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

//void encoder_pbt( void ) {
//	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_1 , 0 , "PUSHED" );
//	pg_buzzer_beep( PG_BEEP_MID , PG_BEEP_SHORT );
//	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_1 , 0 , "      " );
//}
//
//
//void encoder_act( void ) {
//	if ( pg_encoder_get_direction() ) {
//		pg_buzzer_beep( PG_BEEP_LOW , PG_BEEP_SHORT );
//	}
//	else {
//		pg_buzzer_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
//	}
//}
//
//
//void timer_test( void ) {
//	static _pg_int16 cont = 0 ;
//	pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 , 8 , "%d" , cont++ );
//}
//

void main( void ) {
	pg_initialize();
//
//	pg_pin_mode( T_B3 , PG_OUT );
//	pg_pin_mode( T_B2 , PG_OUT );
//	pg_pin_mode( T_B1 , PG_IN );
//	pg_pin_mode( T_B0 , PG_IN );
//
//	pg_timer_set_period( PG_TIMER_0 , 1 , PG_SEC );
//	pg_timer_start( PG_TIMER_0 );
//
//    pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );
//    pg_event_set( PG_EVENT_PERIPHERAL , PG_ENABLE );
//
//	pg_event_attach( PG_EVENT_TMR0 , timer_test );
//    pg_event_set( PG_EVENT_TMR0 , PG_ENABLE );
//
//	pg_event_attach( PG_EVENT_INT0 , encoder_act );
//    pg_event_set( PG_EVENT_INT0 , PG_ENABLE );
//
//	pg_event_attach( PG_EVENT_INT1 , encoder_pbt );
//    pg_event_set( PG_EVENT_INT1 , PG_ENABLE );
//
	pg_loop;
}



