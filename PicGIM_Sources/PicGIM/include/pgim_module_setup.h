//
// pgim_module_setup.h
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

/*!		\file			pgim_module_setup.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			Management modules: inclusions, dependencies and conflicts
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\todo			<b>In the next Milestone</b> \n \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #38 &ensp; - &ensp; Reduction and optimization of the use of Ram and Program. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #14 &ensp; - &ensp; Integrated watchdog manager. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #22 &ensp; - &ensp; Sermon - Programmable Serial Monitor. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #43 &ensp; - &ensp; AN914 - Dynamic Memory Allocation. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #13 &ensp; - &ensp; Reset manager. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #8  &ensp; - &ensp; Develop ILI9340 LCD module. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #48 &ensp; - &ensp; Develop 5110 LCD module. \n
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \b #55 &ensp; - &ensp; Simple encryption algorithm. \n
*/

#ifndef _PGIM_MODULE_SETUP_H_
	#define	_PGIM_MODULE_SETUP_H_

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      F O R   D E B U G   O N L Y
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define PGIM_ALL_MODULES_DISABLED   PG_DISABLE				// PG_ENABLE   PG_DISABLE
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      I N C L U S I O N   O F   P U B L I C   F I L E S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#include "pgim_project_setup_public.h"

	#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PROJECT_INFO_SHOW == PG_ENABLE )
		#warning	-
		#warning	-
		#warning	PG_HS_PG Project: [ PG_PROJECT_NAME  V PG_PROJECT_VERSION ] by [ PG_PROJECT_ORGANIZATION ]  -  Author: [ PG_PROJECT_AUTHOR ]
		#warning	-
		#warning	-
	#endif

	#include "pgim_ezfuse.h"
//	#include "pgim_board_setup_public.h"
	#define PGIM_BOARD			PG_BAORD_USER_DEFINED
	#include "pgim_module_setup_public.h"

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

//	#include "pgim_font_setup_public.h"
	#include "pgim_event_setup_public.h"
	#include "pgim_timer_setup_public.h"
	#include "pgim_pwm_setup_public.h"
	#include "pgim_serial_setup_public.h"
//	#include "pgim_external_memory_setup_public.h"

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

    #include "pgim_hardware_setup.h"

	//////////////////////////////////////////////////////////////////////////////////////////////////////	
	//	D e p e n d e n c y    m a n a g e m e n t
	//////////////////////////////////////////////////////////////////////////////////////////////////////	


	//	D e p e n d e n c y   o n   D E B U G
	//  -------------------------------------
	#if ( PGIM_ERROR == PG_ENABLE )
		#if ( PG_PROJECT_STATE != PG_DEBUG )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must set the PROJECT STATE to DEBUG in pgim_project_setup_public.h as required by other modules or DISABLE the module that need DEBUG STATE
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif



	//	D e p e n d e n c y   o n   D E L A Y
	//  -------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_LCD_PCD8544 == PG_ENABLE ) || \
		( PGIM_LCD_9340 == PG_ENABLE ) || ( PGIM_BUZZER == PG_ENABLE ) || \
		( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) || \
		( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) ) ) || \
		( PGIM_EXTERNAL_MEMORY == PG_ENABLE ) || ( ( PGIM_ERROR == PG_ENABLE ) && ( PGIM_ERROR_LED_PRESENT == PG_YES ) ) || \
		( PGIM_TIMER == PG_ENABLE )

		#if ( PGIM_CAL_DELAY == PG_DISABLE )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable the DELAY module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//	D e p e n d e n c y   o n   S P I
	//  ---------------------------------
	//	|| ( PGIM_TIMER == PG_ENABLE )
	//	( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) &&

	#if ( ( PGIM_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_EXTERNAL_MEMORY == PG_ENABLE ) )
		
		#if	( PGIM_SPI == PG_DISABLE )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable the SPI module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//	D e p e n d e n c y   o n   L C D - P C D 8 5 4 4
	//  -------------------------------------------------
//	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) )
//
//		#if ( PGIM_LCD_PCD8544 == PG_DISABLE ) && defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable the LCD-PCD8544 module required by other modules
//			#ifndef		PG_EXIT_ON_ERROR
//				#define		PG_EXIT_ON_ERROR
//			#endif
//		#endif
//	#endif
	
	//	D e p e n d e n c y   o n   L C D - H D 4 4 7 8 0
	//  -------------------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) ) \
		&& defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
		
		#if ( PGIM_LCD_HD44780 == PG_DISABLE )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable the LCD-HD44780 module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif

	//	D e p e n d e n c y   o n   B U Z Z E R
	//  ---------------------------------------
	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_BUZZER == PG_ENABLE ) )
		 
		#if ( PGIM_BUZZER == PG_DISABLE )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable the BUZZER module required by other modules
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
	
	//	D e p e n d e n c y   o n   F O N T S
	//  -------------------------------------
//	#if ( ( PGIM_SERIAL == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) && ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) )
//
//		#if ( PGIM_SERIAL == PG_ENABLE ) && defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#if ( PGIM_FONTS == PG_DISABLE )
//				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must enable FONTS as required by SERIAL debug
//				#ifndef		PG_EXIT_ON_ERROR
//					#define		PG_EXIT_ON_ERROR
//				#endif
//			#endif
//			#if ( PGIM_FONT_5X8 == PG_NOT_INCLUDE )
//				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You must include 5X8 font as required by SERIAL debug
//				#ifndef		PG_EXIT_ON_ERROR
//					#define		PG_EXIT_ON_ERROR
//				#endif
//			#endif
//		#endif
//	#endif
	

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	C o n f l i c t   m a n a g e m e n t
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_BOARD == PG_BOARD_A )
		#if ( PG_PIN_NUMBER != 28 )
			#warning	PG_HS_PG PG_HS_ERR PG_HB_A You are using an MCU NOT COMPATIBLE with Board A.
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CONTINUE Board A can only support MCU DIL with 28 Pin.
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
	#endif

#endif /* _PGIM_MODULE_SETUP_H_ */
 