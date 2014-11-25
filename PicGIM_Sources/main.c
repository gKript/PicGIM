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

void	led_blink_a( void ) {
	T_B3 = PG_OUT;
	L_B3 ^= 1;
}

void	led_blink_b( void ) {
	T_B2 = PG_OUT;
	L_B2 ^= 1;
	T_B0 = PG_OUT;
	L_B0 = P_B3 & P_B2 & P_B1;
}

void main( void ) {
	pg_initialize();
	pg_lcd_hd44780_write( PG_CONTROLLER_0 , PG_LINE_0 , 0 , "gKript.org  test"  );
	pg_lcd_hd44780_write( PG_CONTROLLER_0 , PG_LINE_1 , 0 , "Timers  & Events"  );
	pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );
	pg_event_set( PG_EVENT_PERIPHERAL , PG_ENABLE );
	pg_timer_set_freq( PG_TIMER_0 , 1 , PG_HZ );
	pg_timer_set_period( PG_TIMER_1 , 50 , PG_MSEC );
	pg_event_attach( PG_EVENT_TMR0 , led_blink_a );
	pg_event_attach( PG_EVENT_TMR1 , led_blink_b );
	pg_event_set( PG_EVENT_TMR0 , PG_ENABLE );
	pg_timer_start( PG_TIMER_0 );
	pg_delay_sec( 5 );
	pg_event_set( PG_EVENT_TMR1 , PG_ENABLE );
	pg_timer_start( PG_TIMER_1 );
	pg_delay_sec( 5 );
	while( 1 ) {
		pg_delay_msec( 1333 );
		T_B1 = PG_OUT;
		L_B1 ^= 1;
	}
}

