//
// pgim_caldelay.c
//
// PicGim  -  Generic Information Manager for Pic 18 / 24 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002 - 2014 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of PicGim library.

	PicGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	PicGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

/*!		\file			pgim_caldelay.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
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


		void pg_delay_sec( _pg_Uint8 sec ) {
			while ( sec-- ) {
				Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
				Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
				Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
				Delay10KTCYx( ( ( pg_ninstus * 20 ) + PG_NINSTUS_OFFSET ) );
				Delay10KTCYx( ( pg_ninstus * 20 ) );
			}
		}


		void pg_delay_msec( _pg_Uint16 msec ) {
			while ( msec-- ) {
				Delay10TCYx( pg_ninstus * 20 );
				Delay10TCYx( pg_ninstus * 20 );
				Delay10TCYx( pg_ninstus * 20 );
				Delay10TCYx( pg_ninstus * 20 );
				Delay10TCYx( pg_ninstus * 20 );
			}
		}


		void pg_delay_usec( _pg_Uint16 tusec )  {
			tusec /= 10;
			while( tusec-- ) {
				Delay10TCYx( pg_ninstus );
			}
		}


		void	pg_delay( _pg_Uint16 req_delay , _pg_Uint8 unit ) {
			if ( unit == PG_SEC )
				pg_delay_sec( req_delay );
			if ( unit == PG_MSEC )
				pg_delay_msec( req_delay );
			if ( unit == PG_USEC )
				pg_delay_usec( req_delay );
		}

		
		#if	( PGIM_EVENTS == PG_ENABLE )
			void pg_delay_high_priority( _pg_Uint16 req_delay , _pg_Uint8 unit ) {
				_pg_Uint8 GIE_state , PIE_state;
				GIE_state = PG_INTERRUPT_GLOBAL_ENABLE;
				PIE_state = PG_INTERRUPT_PERIPHERAL_ENABLE;
				if ( GIE_state )
					pg_event_set( PG_EVENT_GLOBAL , PG_DISABLE );
				if ( PIE_state )
					pg_event_set( PG_EVENT_PERIPHERAL , PG_DISABLE );
				if ( unit == PG_SEC )
					pg_delay_sec( req_delay );
				if ( unit == PG_MSEC )
					pg_delay_msec( req_delay );
				if ( unit == PG_USEC )
					pg_delay_usec( req_delay );
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


