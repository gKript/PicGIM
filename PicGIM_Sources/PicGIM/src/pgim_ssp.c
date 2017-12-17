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
		\brief		
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

//--------------------------------------------------------------------------
//k, 23-10-2017
//--------------------------------------------------------------------------
//gkssp simple serial protocol
//--------------------------------------------------------------------------
//transports variable lenght data, min. 1 - max. 256 byte at time
//simple integrity error check (!100%, di primo livello, non sicura)
//It works on rollover of 8bit usigned char data to avoid int use.
//--------------------------------------------------------------------------
// TX send: 'K'(1B) + Lenght(1B) + PayLoad(#B) + IC(1B) + 'X'(1B)
// RX send: 'k'(1B)                                       'x'(1B) 
//--------------------------------------------------------------------------
//'K' = Header
//PayLoad = carico utile
//Length = lunghezza payload (contiene la lunghezza reale - 1, Max:255 [256-1]) (Min:0 [1-1])
//IC = simple 8bit xor Integrity Check (option)
//'X' = Footer
//'k' = Header Reply
//'x' = Footer Reply
//------------------------------------------------------------------------
//	UART
//------------------------------------------------------------------------
//while(BusyUSART());				//Ret "1" if busy.
//if( DataRdyUSART() )				//Ret "1" if data is present.
//getsUSART ( rbuffer, length );	//PAYLOAD ricevuto	//void getsUSART ( char * buffer, unsigned char length ); There is no time out when pg_ssp_waiting for characters to arrive.	
//putsUSART( Temp_Panel_Str );		//WriteUSART(  char data ); This function writes a string of data to the USART including the null character.
//putrsUSART( Temp_Panel_Str );		//WriteUSART(  char data ); This function writes a rom string of data to the USART including the null charac.
//WriteUSART( 'P' );				//WriteUSART(  char data ); This function writes a byte to the USART transmit buffer.
//------------------------------------------------------------------------

//todo:
//togliere +1 dal for
//test 256° byte
//init nel .h
//gestire timeout

#include "picgim.h"

#if ( PGIM_SSP == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	_pg_Uint8	pg_ssp_length;				//Buffer length

	//---[ Init ]---
	void	pg_ssp_init( void ) {
		//--------------------------------------------------------------------------
		while( DataRdyUSART() )
			ReadUSART();
		}
	
	//---[ Read Byte Usart ]---
	_pg_Uint8	pg_ssp_read_byte( void ) {
		//--------------------------------------------------------------------------
		_pg_Uint16	pg_ssp_waiting;			//Waiting max on rx byte [ms]
		_pg_Uint8	rbyte;
		
		pg_ssp_waiting = PG_SSP_BYTEDELAY;
		while( 1 ) {
			if( DataRdyUSART() ) {
				rbyte = ReadUSART( );				
				#if ( PG_SSP_DEBUG == PG_ENABLE )
					pg_lcd_hd44780_put_char( 0 , rbyte );
				#endif
				return( rbyte );
			}
			else {
				pg_delay( 1 , PG_MSEC );
				pg_ssp_waiting--;
				if( !pg_ssp_waiting ) {
					#if ( PG_SSP_DEBUG == PG_ENABLE )
						pg_lcd_hd44780_put_char( 0 , 't' );
					#endif
					return( PG_SSP_ERROR_RX_TIMEOUT );
				}
			}
		}
	}

	//---[ Send Byte Usart ]---
		void	pg_ssp_send_byte( _pg_Uint8 sbyte ) {
		//--------------------------------------------------------------------------
		while( BusyUSART() );
		WriteUSART( sbyte );
		#if ( PG_SSP_DEBUG == PG_ENABLE )
			pg_lcd_hd44780_put_char( 0 , sbyte );
		#endif
	}
	
	_pg_Uint8	pg_ssp_tx( _pg_Uint8 * tbuffer , _pg_Uint8 pg_ssp_length ) {
		//--------------------------------------------------------------------------
		// tbuffer max length = 256 byte
		//--------------------------------------------------------------------------
		_pg_Uint8	tindex;
	
		if( !pg_ssp_length ) {
			return( PG_SSP_ERROR_WRONG_BUFFER_LENGTH );	//non posso inviare 0 byte! Minimo 1!
		}
		pg_ssp_length--;
		//per una quantita' di 1 byte, invio 0.
		//si contera' da 0 fino a 255 per 256B di dati
		//se passo la quantita' 256, pg_ssp_length fara' rollover a tutti 0 e con -1 andra' a tutti 1
		//in ricezione devo fare +1 per riottenenere la quantita' corretta se richiesta,
		//ma lo lasceremo decrementato per permettere di contare da 0 a 255 per quantita' da 1 a 256.
		
		//---[ Header ]---
		pg_ssp_send_byte( PG_SSP_CONTROL_HEADER );
		if( pg_ssp_read_byte() !=  PG_SSP_CONTROL_HEADER_REPLY ) {				//LENGTH byte ricevuto (senza +1 per usarlo direttamente del for (altrimenti si, per ricostruire la quantita' corretta, vedi tx...))
			return( PG_SSP_ERROR_WRONG_HEADER );
		}				
		
		//---[ Length ]---
		//LENGTH byte inviato senza +1 per usarlo direttamente del for.
		pg_ssp_send_byte( pg_ssp_length );
		
		//---[ PayLoad ]---
		//??? togliere +1
		for( tindex = 0; tindex < (pg_ssp_length+1); tindex++ ) {		// <= per raggiungere 255 senza rollover; byte a byte e non a stringa, perche' putsUSART e' bloccante e senza possibilita' di controllare ogni byte ricevuto in tempo reale
			pg_ssp_send_byte( *( tbuffer + tindex ) );
			#if ( PG_SSP_CRYPT_ENABLE == PG_ENABLE )
				//---[ Crypt ]---
			#endif
			#if ( PG_SSP_CRC_ENABLE == PG_ENABLE )
				//---[ ICheck ]---
			#endif
		}
		
		//---[ Footer ]---
		pg_ssp_send_byte( PG_SSP_CONTROL_FOOTER );	
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_FOOTER_REPLY ) {
			return( PG_SSP_ERROR_WRONG_FOOTER );
		}
		
		return( PG_OK );
	}
	
	//---[ Rx ]---
	_pg_Uint8	pg_ssp_rx( _pg_Uint8 * rbuffer ) { //non bloccante! se qlc va male aspetta un pochino (PG_SSP_BYTEDELAY)...
		//--------------------------------------------------------------------------
		// rbuffer max length = 256 byte
		//--------------------------------------------------------------------------
		_pg_Uint8	rindex;
		
		//---[ Header ]---
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_HEADER ) {
			return( PG_SSP_ERROR_WRONG_HEADER );
		}
		pg_ssp_send_byte( PG_SSP_CONTROL_HEADER_REPLY );

		//---[ Length ]---
		//LENGTH byte ricevuto senza +1 per usarlo direttamente del for.
		pg_ssp_length = pg_ssp_read_byte();
				
		//---[ PayLoad ]---
		//??? togliere +1
		for( rindex = 0; rindex < (pg_ssp_length+1); rindex++ ) {				// <= per raggiungere 255 senza rollover; byte a byte e non a stringa, perche' getsUSART e' bloccante e senza possibilita' di controllare ogni byte ricevuto in tempo reale
			*( rbuffer + rindex ) = pg_ssp_read_byte();	
			#if ( PG_SSP_CRC_ENABLE == PG_ENABLE )
				//---[ ICheck ]---
			#endif
			#if ( PG_SSP_CRYPT_ENABLE == PG_ENABLE )
				//---[ DeCrypt ]---
			#endif
		}
			
		//---[ Footer ]---
		if( pg_ssp_read_byte() != PG_SSP_CONTROL_FOOTER ) {
			return( PG_SSP_ERROR_WRONG_FOOTER );
		}
		pg_ssp_send_byte( PG_SSP_CONTROL_FOOTER_REPLY );
		
		return( PG_OK );
	}

#endif




