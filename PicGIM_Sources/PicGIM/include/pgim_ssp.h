/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ssp.h
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
		\file		pgim_ssp.h
		\version	0.5-0
		\date		2002 - 2017
		\brief		Simple Serial Protocol
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

//SSP -	Simple Serial Protocol


#ifndef _PGIM_SSP_H_
	#define _PGIM_SSP_H_

	#if ( PGIM_SSP == PG_ENABLE )		
		#define		PG_SSP_CONTROL_HEADER				'K'			//!< Start byte
		#define		PG_SSP_CONTROL_HEADER_REPLY			'k'			//!< Start byte reply 
		#define		PG_SSP_CONTROL_FOOTER				'X'			//!< End byte
		#define		PG_SSP_CONTROL_FOOTER_REPLY			'x'			//!< End byte reply
			
		enum pg_ssp_error {
			PG_SSP_NO_ERROR = 48,
			PG_SSP_ERROR_WRONG_HEADER,
			PG_SSP_ERROR_WRONG_FOOTER,
			PG_SSP_ERROR_WRONG_HEADER_REPLY,
			PG_SSP_ERROR_WRONG_FOOTER_REPLY,
			PG_SSP_ERROR_RX_TIMEOUT,
			PG_SSP_ERROR_CRC,
			PG_SSP_OK_CRC
		};

		extern	_pg_Uint8	pg_ssp_error;				//Reports errors (global)
		
		_pg_Uint8 	pg_crc_8							( _pg_Uint8 * pg_crc8_data, _pg_Uint16 pg_crc8_length);
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/			
		void		pg_ssp_init							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		
		void		pg_ssp_empty_serial					( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		
		void		pg_ssp_send_byte					( _pg_Uint8 pg_ssp_sbyte );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/	
		_pg_Uint8	pg_ssp_read_byte					( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_ssp_tx							( _pg_Uint8 * pg_ssp_tx_buffer , _pg_Uint16 pg_ssp_tx_length );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_ssp_rx							( _pg_Uint8 * pg_ssp_rx_buffer );

	#endif
#endif


