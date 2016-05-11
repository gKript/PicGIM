/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_caldelay.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_caldelay.h

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
		\file		pgim_caldelay.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		Delay functions for PicGIM
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if ( PGIM_CAL_DELAY == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	#if defined( __18CXX )

		_pg_Uint8	pg_ninstus 	= 0;
		_pg_Uint8	pg_uninstus = 0;


		void pg_delay_NinstusCalc( ) {
			pg_ninstus = ( 0.000001 / ( 1.0 / ( ( PG_CLOCK * 1000000 ) / PG_TCYCLEPERI ) ) );
			pg_uninstus = ( 0.000001 / ( 1.0 / ( ( PG_CLOCK * 1000000 ) / PG_TCYCLEPERI ) ) ) / 2;
		}

		#if ( PG_DELAY_SEC___SC == PG_ENABLE )
			void pg_delay_sec( _pg_Uint8 sec ) {
				while ( sec-- ) {
					Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
					Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
					Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
					Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
					Delay10KTCYx( ( pg_ninstus * 20 ) );
				}
			}
		#endif
		
		#if ( PG_DELAY_MSEC___SC == PG_ENABLE )
			void pg_delay_msec( _pg_Uint16 msec ) {
				while ( msec-- ) {
					Delay10TCYx( pg_ninstus * 20 );
					Delay10TCYx( pg_ninstus * 20 );
					Delay10TCYx( pg_ninstus * 20 );
					Delay10TCYx( pg_ninstus * 20 );
					Delay10TCYx( pg_ninstus * 20 );
				}
			}
		#endif

		#if ( PG_DELAY_USEC___SC == PG_ENABLE )
			void pg_delay_usec( _pg_Uint16 tusec )  {
				tusec /= 10;
				while( tusec-- ) {
					Delay10TCYx( pg_ninstus );
				}
			}
		#endif

		#if ( PG_DELAY___SC == PG_ENABLE )
			void	pg_delay( _pg_Uint16 req_delay , _pg_Uint8 unit ) {
				#if ( PG_DELAY_SEC___SC == PG_ENABLE )
					if ( unit == PG_SEC )
						pg_delay_sec( req_delay );
				#endif
				#if ( PG_DELAY_MSEC___SC == PG_ENABLE )
					if ( unit == PG_MSEC )
						pg_delay_msec( req_delay );
				#endif
				#if ( PG_DELAY_USEC___SC == PG_ENABLE )
					if ( unit == PG_USEC )
						pg_delay_usec( req_delay );
				#endif
			}
		#endif
		
		#if	( ( PGIM_EVENTS == PG_ENABLE ) && ( PG_DELAY_HIGH_PRIORITY___SC == PG_ENABLE ) )
			void pg_delay_high_priority( _pg_Uint16 req_delay , _pg_Uint8 unit ) {
				_pg_Uint8 GIE_state , PIE_state;
				GIE_state = PG_INTERRUPT_GLOBAL_ENABLE;
				PIE_state = PG_INTERRUPT_PERIPHERAL_ENABLE;
				if ( GIE_state )
					pg_event_set( PG_EVENT_GLOBAL , PG_DISABLE );
				if ( PIE_state )
					pg_event_set( PG_EVENT_PERIPHERAL , PG_DISABLE );
				#if ( PG_DELAY_SEC___SC == PG_ENABLE )
					if ( unit == PG_SEC )
						pg_delay_sec( req_delay );
				#endif
				#if ( PG_DELAY_MSEC___SC == PG_ENABLE )
					if ( unit == PG_MSEC )
						pg_delay_msec( req_delay );
				#endif
				#if ( PG_DELAY_USEC___SC == PG_ENABLE )
					if ( unit == PG_USEC )
						pg_delay_usec( req_delay );
				#endif
				if ( GIE_state )
					pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );
				if ( PIE_state )
					pg_event_set( PG_EVENT_PERIPHERAL , PG_ENABLE );
			}
		#endif
	#endif

	#if defined( __C30__ )

		#define FOSC					32000000LL						// Clock frequency in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
		#define FCY      				(FOSC/2)						// MCU is running at FCY MIPS

		#define pg_delay_usec(x)		__delay32(((x*FCY)/1000000L))	// delays x us
		#define pg_delay_msec(x)		__delay32(((x*FCY)/1000L))		// delays x ms
		#define pg_delay_sec(x)			__delay32(((x*FCY)))			// delays x ms

		#define __DELAY_H	1

		#include <libpic30.h>

	#endif
#endif


