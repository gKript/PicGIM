/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_module_setup.h
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
		\file		pgim_module_setup.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Management modules: inclusions, dependencies and conflicts
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing.
  		\todo		<b>In the next Milestone</b> \n \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #20 &ensp; - &ensp; Reduction and optimization of the use of Ram and Program. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #21 &ensp; - &ensp; Integrated watchdog manager. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #27 &ensp; - &ensp; Sermon - Programmable Serial Monitor. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #24 &ensp; - &ensp; AN914 - Dynamic Memory Allocation. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #19 &ensp; - &ensp; Reset manager. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #31 &ensp; - &ensp; XC8 integration. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #22 &ensp; - &ensp; SMBus implementation. \n
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #26 &ensp; - &ensp; Simple encryption algorithm. \n

*/
#ifndef _PGIM_MODULE_SETUP_H_
	#define	_PGIM_MODULE_SETUP_H_

	//------------------------------------------------------------------------------
	//      F O R   D E B U G   O N L Y
	//------------------------------------------------------------------------------

	#define PGIM_ALL_MODULES_DISABLED   PG_DISABLE				// PG_ENABLE   PG_DISABLE
	
	//------------------------------------------------------------------------------
	//      I N C L U S I O N   O F   P U B L I C   F I L E S
	//------------------------------------------------------------------------------

	#include "pgim_project_setup_public.h"

	#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PROJECT_INFO_SHOW == PG_ENABLE )
		#warning	-
		#warning	-
		#warning	PicGIM >>> Project: [ PG_PROJECT_NAME  V PG_PROJECT_VERSION_MAJOR . PG_PROJECT_VERSION_MINOR ] by [ PG_PROJECT_ORGANIZATION ]  -  Author: [ PG_PROJECT_AUTHOR ]
		#warning	-
		#warning	-
	#endif

	#include "pgim_ezfuse.h"
	#define PGIM_BOARD			PG_BOARD_USER_DEFINED		// Only for Milestone 0.5
	#include "pgim_module_setup_public.h"

    #include "pgim_font_setup_public.h"
	#include "pgim_event_setup_public.h"
	#include "pgim_timer_setup_public.h"
	#include "pgim_pwm_setup_public.h"
	#include "pgim_serial_setup_public.h"
	#include "pgim_external_memory_setup_public.h"
	#include "pgim_sensor_setup_public.h"
	#include "pgim_gcp_setup_public.h"
	#include "pgim_ssp_setup_public.h"
	#include "pgim_prs_setup_public.h"
	//
    #include "pgim_hardware_setup.h"

	//------------------------------------------------------------------------------	
	//		D E P E N D E N C Y    M A N A G E M E N T
	//------------------------------------------------------------------------------	

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   D E B U G
	//------------------------------------------------------------------------------
	#if ( PGIM_ERROR == PG_ENABLE )
		#if ( PG_PROJECT_STATE != PG_DEBUG )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must set the PROJECT STATE to DEBUG in pgim_project_setup_public.h as required by other modules or DISABLE the module that need DEBUG STATE
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   D E L A Y
	//------------------------------------------------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_LCD_PCD8544 == PG_ENABLE ) || \
		( PGIM_LCD_9340 == PG_ENABLE ) || ( PGIM_BUZZER == PG_ENABLE ) || \
		( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) || \
		( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) ) ) || \
		( PGIM_EXTERNAL_MEMORY == PG_ENABLE ) || ( ( PGIM_ERROR == PG_ENABLE ) && ( PG_ERROR_LED_PRESENT == PG_YES ) ) || \
		( PGIM_TIMER == PG_ENABLE ) || \
		( PGIM_ENCODER == PG_ENABLE )

		#if ( PGIM_CAL_DELAY == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the DELAY module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   A D   C O N V E R T E R
	//------------------------------------------------------------------------------
	#if ( PGIM_SENSOR == PG_ENABLE )

		#if ( PGIM_AD_CONVERTER == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the AD CONVERTER module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   S P I
	//------------------------------------------------------------------------------
	#if ( ( PGIM_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_EXTERNAL_MEMORY == PG_ENABLE ) )
		#if	( PGIM_SPI == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the SPI module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   I 2 C
	//------------------------------------------------------------------------------
	// #if (  == PG_ENABLE )
		// #if	( PGIM_I2C == PG_DISABLE )
			// #warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the I2C module required by other modules
			// #ifndef		PG_EXIT_ON_ERROR
				// #define		PG_EXIT_ON_ERROR
			// #endif
		// #endif
	// #endif

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   L C D - P C D 8 5 4 4
	//------------------------------------------------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) )

		#if ( PGIM_LCD_PCD8544 == PG_DISABLE ) && defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the LCD-PCD8544 module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   L C D - H D 4 4 7 8 0
	//------------------------------------------------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) ) \
		&& defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
		
		#if ( PGIM_LCD_HD44780 == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the LCD-HD44780 module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   B U Z Z E R
	//------------------------------------------------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_BUZZER == PG_ENABLE ) )
		 
		#if ( PGIM_BUZZER == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the BUZZER module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   3 W I R E
	//------------------------------------------------------------------------------
	#if ( PGIM_RTC_DS1302 == PG_ENABLE )
		 
		#if ( PGIM_3WIRE == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the 3WIRE module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   R T C - D S 1 3 0 2
	//------------------------------------------------------------------------------
	#if ( PGIM_RTC_DS1302 == PG_ENABLE )
		 
		#if ( PGIM_3WIRE == PG_DISABLE )
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable the 3WIRE module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//	D e p e n d e n c y   o n   F O N T S
	//------------------------------------------------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) )

		#if ( PGIM_SERIAL == PG_ENABLE ) && defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#if ( PGIM_FONT == PG_DISABLE )
				#warning	PicGIM >>> ERROR !!! >>> Core >>> You must enable FONT module as required by SERIAL debug
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#endif
			#if ( PGIM_FONT_5X8 == PG_NOT_INCLUDE )
				#warning	PicGIM >>> ERROR !!! >>> Core >>> You must include 5X8 font as required by SERIAL debug
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#endif
		#endif
	#endif
	
	//------------------------------------------------------------------------------
	//		C O N F L I C T   M A N A G E M E N T
	//------------------------------------------------------------------------------
	#if ( PGIM_BOARD == PG_BOARD_A )
		#if ( PG_PIN_NUMBER != 28 )
			#warning	PicGIM >>> ERROR !!! >>> Board A  >>> You are using an MCU NOT COMPATIBLE with Board A.
			#warning	PicGIM >>> ERROR !!! >>> Continue >>> Board A can only support MCU DIL with 28 Pin.
			#ifndef	PG_EXIT_ON_ERROR
				#define	PG_EXIT_ON_ERROR
			#endif
         #endif
    #endif

	#if ( ( PGIM_SPI == PG_ENABLE ) && ( PGIM_I2C == PG_ENABLE ) )
		#error	PicGIM >>> ERROR !!! >>> MSSP HW module >>> Hardware conflict.
		#error	PicGIM >>> ERROR !!! >>> Continue       >>> Currently it is not possible to use both modules at the same time.
		#ifndef	PG_EXIT_ON_ERROR
			#define	PG_EXIT_ON_ERROR
		#endif
    #endif
	
#endif /* _PGIM_MODULE_SETUP_H_ */
 
 
 