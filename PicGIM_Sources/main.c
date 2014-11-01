//
// main.c
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

/*!		\file			main.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/


#include "picgim_main.h"

void main( void ) {

	char buf[ 32 ];
	pg_initialize();
	pg_serial_open();
	
	putrsUSART( "Using user's buffer   : " );
	pg_ftoa( 1234.5678, PG_FTOA_DECIMAL_DIGITS_2, buf );
	putsUSART( buf );
	putrsUSART( "\n" );
	
	putrsUSART( "Using internal buffer : " );
	putsUSART( pg_ftoa( 1234.5678, PG_FTOA_DECIMAL_DIGITS_2, NULL ) );
	putrsUSART( "\n" );
	putrsUSART( "---------------------\n" );
	pg_serial_close();
	
	T_D0 = PG_OUT;
	
	pg_interrupt_enable_set( PG_INTERRUPT_EVENTS , PG_ENABLE );
	pg_interrupt_enable_set( PG_INTERRUPT_EVENT_TMR0 , PG_ENABLE );
	
	pg_timer_set_freq( PG_TIMER_0 , 1 , PG_KHZ );
	pg_timer_start( PG_TIMER_0 );
	
	PG_INFINITE_LOOP;
}

