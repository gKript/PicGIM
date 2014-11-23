//
// pgim_ee.c
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

/*!		\file			pgim_ee.c
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

#if	( PGIM_EE == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif


	void pg_ee_init( void ) {
		EECON1bits.EEPGD = 0;
		EECON1bits.CFGS = 0;
	}


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


	char pg_ee_read( _pg_Uint16 ee_addy ) {
		_pg_Uint8 ee_data = 0;
		EEADR = ee_addy;
		EECON1bits.RD = 1;
		ee_data = EEDATA;
		return ee_data;
	}


	void pg_ee_write_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen ) {
		_pg_Uint8 GIE_state;
		_pg_Uint16 count = 0;
		EECON1bits.WREN = PG_ENABLE;
		for( count = 0 ; count < buflen ; count++ )
			pg_ee_write( *( buffer + count ) , ee_addy + count );
		EECON1bits.WREN = PG_DISABLE;
	}


	void pg_ee_read_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen ) {
		_pg_Uint16 count = 0;
		for( count = 0 ; count < buflen ; count++ )
			*( buffer + count ) = pg_ee_read( ee_addy + count );
	}
#endif


