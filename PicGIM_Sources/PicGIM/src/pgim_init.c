//
// pgim_init.c
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

/*!		\file			pgim_init.c
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

#if PG_PROJECT_STATE == PG_DEBUG
	#warning	PG_HS_PG PG_HS_MSG This file is always compiling.
#endif

void pg_initialize( void ) {

	#if ( PGIM_BOARD == PG_BOARD_A )
		pg_board_a_init();
	#endif
	
	#if	( PG_USE_INTERNAL_OSC == PG_ENABLE )
		pg_internal_osc_init( );
	#endif

//	#if	( PGIM_LCD_PCD8544 == PG_ENABLE )
//		pg_lcd_pcd8544_reset();
//	#endif

	ADCON1 = 0x0f;

	#if	( PGIM_TIMER == PG_ENABLE )
		pg_timer_init( );
	#endif

	#if	( PGIM_INTERRUPTS == PG_ENABLE )
		pg_interrupt_init( );
	#endif

	#if ( PGIM_CAL_DELAY == PG_ENABLE ) && defined( __18CXX )
		pg_delay_NinstusCalc( );
	#endif

	#if	( PGIM_PWM == PG_ENABLE )
		pg_pwm_init( );
	#endif

	#if	( PGIM_AD_CONVERTER == PG_ENABLE )
		pg_adc_init( );
	#endif

	#if	( PGIM_EE == PG_ENABLE )
		pg_ee_init( );
	#endif

	#if	( PGIM_LCD_HD44780 == PG_ENABLE )
		pg_lcd_hd44780_init( );
	#endif

//	#if	( PGIM_LCD_PCD8544 == PG_ENABLE )
//		pg_lcd_pcd8544_init( );
//	#endif
//
//	#if	( PGIM_LCD_9340 == PG_ENABLE )
//		pg_lcd_9340_init( );
//	#endif

	#if	( PGIM_SERIAL == PG_ENABLE )			//To init after lcd-pcd8544 and lcd-char
		pg_serial_init();
	#endif
	
	#if	( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		pg_delay( 1 , PG_MSEC );				// Delay to wait memory becomes ready; no chip-select allowed
	#endif
	
}


