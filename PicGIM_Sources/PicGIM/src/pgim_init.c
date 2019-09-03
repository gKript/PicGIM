/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_init.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		picgim.h

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
		\file		pgim_init.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To properily initiate the PicGIM library.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if PG_PROJECT_STATE == PG_DEBUG
	#warning	PicGIM >>> Message >>> This file is always compiled.
#endif

void pg_initialize( void ) {
	
	#if ( PG_POWER_GOOD_DELAY > 0 )
		#warning	PicGIM >>> Message >>> Power good delay set to PG_POWER_GOOD_DELAY [ms].
		pg_delay_msec( PG_POWER_GOOD_DELAY );
	#endif
	
	#if ( PGIM_BOARD == PG_BOARD_A )
		pg_board_a_init();
	#endif
	
	#if	( PG_USE_INTERNAL_OSC == PG_ENABLE )
		pg_internal_osc_init( );
	#endif

	ADCON1 = 0x0f;

	#if	( PGIM_TIMER == PG_ENABLE )
		pg_timer_init( );
	#endif

	#if	( PGIM_EVENTS == PG_ENABLE )
		pg_event_init( );
	#endif

	#if ( PGIM_CAL_DELAY == PG_ENABLE ) && defined( __18CXX )
		pg_delay_NinstusCalc( );
	#endif

	#if ( PGIM_I2C == PG_ENABLE )
		pg_i2c_init( );
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

	#if	( PGIM_ENCODER == PG_ENABLE )
		pg_encoder_init( );
	#endif

	#if	( PGIM_LCD_HD44780 == PG_ENABLE )
		pg_lcd_hd44780_init( );
	#endif

	#if	( PGIM_LCD_PCD8544 == PG_ENABLE )
		pg_lcd_pcd8544_init( );
        #endif

//	#if	( PGIM_LCD_9340 == PG_ENABLE )
//		pg_lcd_9340_init( );
//	#endif

	#if	( PGIM_SERIAL == PG_ENABLE )			//To init after lcd-pcd8544 and lcd-char
		pg_serial_init();
	#endif
	
	#if	( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		pg_delay( 10 , PG_MSEC );				// Delay to wait memory becomes ready; no chip-select allowed
		pg_external_memory_init( );
	#endif
	
	#if ( PGIM_3WIRE == PG_ENABLE )
		pg_3wire_init( );
	#endif

	#if ( PGIM_RTC_DS1302 == PG_ENABLE )
		pg_rtc_ds1302_init( );
	#endif
	
	#if ( PGIM_AMG88XX == PG_ENABLE )
		pg_amg88xx_init( );
	#endif
	
	#if ( PGIM_DDS_AD9851 == PG_ENABLE )
		pg_dds_ad9851_init( );
	#endif

	#if ( PGIM_SSP == PG_ENABLE )
		pg_ssp_init( );
	#endif

	#if ( PGIM_FLASH_LVP == PG_ENABLE )
		pg_flash_lvp_init( );
	#endif
}


