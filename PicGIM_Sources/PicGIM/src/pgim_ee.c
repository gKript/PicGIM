/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ee.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_ee.h

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
		\file		pgim_ee.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To read and write in the internal EEprom.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if	( PGIM_EE == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif


	void pg_ee_init( void ) {
		EECON1bits.EEPGD = 0;
		EECON1bits.CFGS = 0;
	}

	#if ( PG_EE_WRITE == PG_INCLUDE )
		_pg_Uint8 pg_ee_write( _pg_Uint8 ee_data , _pg_Uint16 ee_addy ) {
			_pg_Uint8 GIE_state;
			_pg_Uint16 count = 0;
			
			#if ( PG_INTERRUPTS == PG_ENABLE )
				GIE_state = PG_INTERRUPT_GLOBAL_ENABLE;
				if ( PG_INTERRUPT_GLOBAL_ENABLE )
					pg_event_set( PG_EVENT_GLOBAL , PG_DISABLE );
			#endif
			
			EEADR = ee_addy;
			EEDATA = ee_data;
			EECON1bits.WREN = 1;
			EECON2 = 0x55;
			EECON2 = 0xAA;
			EECON1bits.WR = 1;
			while ( EECON1bits.WR );
			
			#if ( PG_INTERRUPTS == PG_ENABLE )
				if ( GIE_state )
					pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );
			#endif
				
			EECON1bits.WREN = 0;
			if ( pg_ee_read( ee_addy ) == ee_data )
				return PG_OK;
			else
				return PG_NOK;
		}
	#endif

	#if ( PG_EE_READ == PG_INCLUDE )
		char pg_ee_read( _pg_Uint16 ee_addy ) {
			_pg_Uint8 ee_data = 0;
			EEADR = ee_addy;
			EECON1bits.RD = 1;
			ee_data = EEDATA;
			return ee_data;
		}
	#endif

	#if ( PG_EE_WRITE_BUFFER == PG_INCLUDE )
		void pg_ee_write_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen ) {
			_pg_Uint8 GIE_state;
			_pg_Uint16 count = 0;
			EECON1bits.WREN = PG_ENABLE;
			for( count = 0 ; count < buflen ; count++ )
				pg_ee_write( *( buffer + count ) , ee_addy + count );
			EECON1bits.WREN = PG_DISABLE;
		}
	#endif
	
	#if ( PG_EE_READ_BUFFER == PG_INCLUDE )
		void pg_ee_read_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen ) {
			_pg_Uint16 count = 0;
			for( count = 0 ; count < buflen ; count++ )
				*( buffer + count ) = pg_ee_read( ee_addy + count );
		}
	#endif
#endif




		
		



	