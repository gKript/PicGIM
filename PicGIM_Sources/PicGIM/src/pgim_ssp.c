/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ssp.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2015  gKript.org - We.PIC project - <http://www.gkript.org>

		This program is free software: you can redistribute it and/or modify
		it under the terms of the GNU General Public License as published by
		the Free Software Foundation, either version 3 of the License, or
		(at your option) any later version.

		This program is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
		GNU General Public License for more details.

		You should have received a copy of the GNU General Public License
		along with this program.  If not, see <http://www.gnu.org/licenses/>.

	END LICENSE
 */

 /*!
		\file		pgim_ssp.c
		\version	0.5-0
		\date		2002 - 2017
		\brief		A simple serial protocol
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

//--------------------------------------------------------------------------
// SSP - (S)imple (S)erial (P)rotocol
//--------------------------------------------------------------------------
// TX send: 'K'(1[B]) + #Byte(2[B]) + Data('#Byte'[B]) + Crc(1[B]) + 'X'(1[B])
// RX send: 'k'(1[B])                                                'x'(1[B])
//--------------------------------------------------------------------------
// 'K'		= Header
// 'k'		= Header Reply
// Data		= Data bytes to send
// #Byte	= # of data byte to send
// 'X'		= Footer
// 'x'		= Footer Reply
//--------------------------------------------------------------------------

#include "picgim.h"

#if ( PGIM_SSP == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	_pg_Uint8	pg_ssp_error;

	//---[ Init ]---
	void	pg_ssp_init( void ) {
		pg_ssp_error = PG_SSP_NO_ERROR;
		pg_ssp_empty_serial( );
	}
	
	//---[ Empty ]---
	void	pg_ssp_empty_serial( void ) {
		//--------------------------------------------------------------------------
		while( DataRdyUSART() ) {
			ReadUSART();
		}
	}

	//---[ Send Byte ]---
	void	pg_ssp_send_byte( _pg_Uint8 pg_ssp_sbyte ) {
		//--------------------------------------------------------------------------
		while( BusyUSART() );
		WriteUSART( pg_ssp_sbyte );
	}
	
	//---[ Read Byte ]---
	_pg_Uint8	pg_ssp_read_byte( void ) {
		//--------------------------------------------------------------------------
		//	Returns read byte || ( PG_NOK && set error )
		//--------------------------------------------------------------------------
		#if ( PG_SSP_RX_MODE == PG_NOT_BLOCKING )
			_pg_Uint16	pg_ssp_timeout;
			pg_ssp_timeout = PG_SSP_RXTIMEOUT;
		#endif
		pg_delay( PG_SSP_RXDELAY , PG_MSEC );
		while( 1 ) {
			if( DataRdyUSART() ) {				
				pg_ssp_error = PG_SSP_NO_ERROR;
				return( ReadUSART( ) );
			}
			else {
				#if ( PG_SSP_RX_MODE == PG_BLOCKING )
					continue;
				#endif
				#if ( PG_SSP_RX_MODE == PG_NOT_BLOCKING )
					if( pg_ssp_timeout ) {
						pg_delay( 1 , PG_MSEC );
						pg_ssp_timeout--;
					}
					else {
						pg_ssp_error = PG_SSP_ERROR_RX_TIMEOUT;
						return( PG_NOK );
					}
				#endif
			}
		}
	}

	//---[ Tx Data ]---
	_pg_Uint8	pg_ssp_tx( _pg_Uint8 * pg_ssp_tx_buffer , _pg_Uint16 pg_ssp_tx_length ) {
		//--------------------------------------------------------------------------
		//	pg_ssp_tx_length: Min = 1, Max = 65535 ( = 2^16 - 1)
		//	Returns PG_OK || ( PG_NOK && set error )
		//--------------------------------------------------------------------------
		_pg_Uint8		tindex = 0;
		_pg_Uint16_VAL	tx_length;
		_pg_Uint8		tx_crc;
		
		tx_length.Val = pg_ssp_tx_length;
		
		//---[ Header ]---
		pg_ssp_send_byte( PG_SSP_CONTROL_HEADER );
		if( pg_ssp_read_byte() !=  PG_SSP_CONTROL_HEADER_REPLY ) {
			pg_ssp_error = PG_SSP_ERROR_WRONG_HEADER_REPLY;
			return( PG_NOK );
		}				
		
		//---[ Length ]---
		pg_ssp_send_byte( tx_length.byte.HB );
		pg_ssp_send_byte( tx_length.byte.LB );
		
		//---[ Data ]---
		for( tindex = 0; tindex < pg_ssp_tx_length ; tindex++ ) {
			pg_ssp_send_byte( *( pg_ssp_tx_buffer + tindex ) );
		}
		
		//---[ Crc ]---
		#if( PG_SSP_CRC_ENABLE == PG_ENABLE )
			tx_crc = pg_crc_8( pg_ssp_tx_buffer, pg_ssp_tx_length );
			pg_ssp_send_byte( tx_crc );
			pg_lcd_hd44780_put_char( 0 , tx_crc );
		
			if( pg_ssp_read_byte() !=  PG_SSP_OK_CRC ) {
				pg_ssp_error = PG_SSP_ERROR_CRC;
				return( PG_NOK );
			}
		#endif
		
		//---[ Footer ]---
		pg_ssp_send_byte( PG_SSP_CONTROL_FOOTER );	
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_FOOTER_REPLY ) {
			pg_ssp_error = PG_SSP_ERROR_WRONG_FOOTER_REPLY;
			return( PG_NOK );			
		}
		pg_ssp_error = PG_SSP_NO_ERROR;
		return( PG_OK );
	}
	
	//---[ Rx Data ]---
	_pg_Uint8	pg_ssp_rx( _pg_Uint8 * pg_ssp_rx_buffer ) {
		//--------------------------------------------------------------------------
		//	Returns PG_OK || ( PG_NOK && set error )
		//--------------------------------------------------------------------------
		_pg_Uint8		rindex;
		_pg_Uint16_VAL	rx_length;
		_pg_Uint8		rx_crc;
		
		//---[ Header ]---
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_HEADER ) {
			pg_ssp_error = PG_SSP_ERROR_WRONG_HEADER;
			return( PG_NOK );
		}
		pg_ssp_send_byte( PG_SSP_CONTROL_HEADER_REPLY );

		//---[ Length ]---
		rx_length.byte.HB = pg_ssp_read_byte( );
		rx_length.byte.LB = pg_ssp_read_byte( );		
		
		//---[ Data ]---
		for( rindex = 0; rindex < rx_length.Val ; rindex++ ) {
			*( pg_ssp_rx_buffer + rindex ) = pg_ssp_read_byte();	
		}
		
		//---[ Crc ]---
		#if( PG_SSP_CRC_ENABLE == PG_ENABLE )
			rx_crc = pg_crc_8( pg_ssp_rx_buffer, rx_length.Val );
			if( pg_ssp_read_byte() != rx_crc ) {
				pg_ssp_error = PG_SSP_ERROR_CRC;
				pg_ssp_send_byte( PG_SSP_ERROR_CRC );
				return( PG_NOK );
			}
			pg_ssp_send_byte( PG_SSP_OK_CRC );
		#endif
		
		//---[ Footer ]---
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_FOOTER ) {
			pg_ssp_error = PG_SSP_ERROR_WRONG_FOOTER;
			return( PG_NOK );
		}
		pg_ssp_send_byte( PG_SSP_CONTROL_FOOTER_REPLY );
		pg_ssp_error = PG_SSP_NO_ERROR;
		return( PG_OK );
	}
	
	//---[ Crc_8 ]---
	_pg_Uint8 pg_crc_8( _pg_Uint8 * pg_crc8_data, _pg_Uint16 pg_crc8_length) {
		//--------------------------------------------------------------------------
		_pg_Uint8	crc = 0x00;
		_pg_Uint8	amount;
		_pg_Uint8	data;
		_pg_Uint8	sdx;
		_pg_Uint16	idx;
		
		for( idx = 0 ; idx < pg_crc8_length ; idx++ ) {
			data = *pg_crc8_data;
			for( sdx = 8 ; sdx ; sdx-- ) {
				amount = ( crc ^ data ) & 0x01;
				crc >>= 1;
				if ( amount ) {
					crc ^= 0x8C;
				}
				data >>= 1;
			}
			pg_crc8_data++;
		}
		return( crc );
	}

#endif




