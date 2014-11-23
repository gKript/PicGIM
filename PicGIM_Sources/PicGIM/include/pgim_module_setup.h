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
	#include "pgim_board_setup_public.h"
	#include "pgim_module_setup_public.h"

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

//	#include "pgim_font_setup_public.h"
	#include "pgim_event_setup_public.h"
	#include "pgim_timer_setup_public.h"
	#include "pgim_pwm_setup_public.h"
	#include "pgim_serial_setup_public.h"
	#include "pgim_external_memory_setup_public.h"

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

/*!	
	\page 		WPC_module			Modules

		\tableofcontents

		\image html moduli.jpg
			
		\section Whatm		What are modules

 			\htmlonly
				<b>PicGIM</b> is a <i>"modular library from scratch"</i> and it is divided into <b>modules</b>. <br>
				Each module handles a specific hardware device or particular software routines as Delay. <br>
				<b>PicGIM</b> manages the internal peripherals of the microcontroller and also to external devices such as the LCD display. <br><br>
				The modules have been divided in two main categories:
				<ul>
						<li><b> \endhtmlonly \ref SWPAGE \htmlonly </b></li>
						<li><b> \endhtmlonly \ref HWPAGE \htmlonly </b></li>
				</ul>
				<b>SOFTWARE</b> modules are divided into the following two classes:
				<ul>
						<li><b> \endhtmlonly \ref SW_cmp \htmlonly </b></li>
						<li><b> \endhtmlonly \ref SW_gen \htmlonly </b></li>
				</ul>
				<b>HARDWARE</b> modules are divided into the following three classes:
				<ul>
						<li><b> \endhtmlonly \ref HW_int \htmlonly </b></li>
						<li><b> \endhtmlonly \ref HW_ext \htmlonly </b></li>
						<li><b> \endhtmlonly \ref HW_gkr \htmlonly </b></li>
				</ul>

			\endhtmlonly


		\section MDetail		Modules details

			\htmlonly

				The <b>COMPULSORY</b> modules can not be disabled and are as follows :
				<ul>
						<li> \endhtmlonly \ref SWC_version \htmlonly </li>
						<li> \endhtmlonly \ref SWC_EzFuse \htmlonly </li>
				</ul>

 				The <b>GENERAL</b> modules are software utilities, as delay, and are as follows:<br>
				<ul>
						<li> \endhtmlonly \ref SWG_delay \htmlonly </li>
						<li> \endhtmlonly \ref SWG_error \htmlonly </li>
				</ul>
				The <b>HARDWARE::INTERNAL</b> modules refer to the internal devices of the MCU and are as follows:<br>
				<ul>
						<li> \endhtmlonly \ref HWI_intosc \htmlonly </li>
						<li> \endhtmlonly \ref HWI_interrupt \htmlonly </li>
						<li> \endhtmlonly \ref HWI_adc \htmlonly </li>
						<li> \endhtmlonly \ref HWI_timer \htmlonly </li>
						<li> \endhtmlonly \ref HWI_serial \htmlonly </li>
						<li> \endhtmlonly \ref HWI_spi \htmlonly </li>
						<li> \endhtmlonly \ref HWI_ee \htmlonly </li>
						<li> \endhtmlonly \ref HWI_pwm \htmlonly </li>
 				</ul>
				The <b>HARDWARE::EXTERNAL</b> modules refer to generic hardware normally used, for example LCD display, and are as follows:<br>
				<ul>
						<li> \endhtmlonly \ref HWE_ext_mem \htmlonly </li>
						<li> \endhtmlonly \ref HWE_buzzer \htmlonly </li>
						<li> \endhtmlonly \ref HWE_lcd_HD44780 \htmlonly </li>
 				</ul>
				The <b>HARDWARE::GKRIPT</b> modules refer to hardware specifically created by <b>gKript.org</b>, like graphics controller and encoder management, and are as follows:<br>
				<ul>
					<li> \endhtmlonly \ref HWG_encoder \htmlonly </li>
				</ul>
			\endhtmlonly

		\section	Howm			How to use them?
			<p>
				Use the \b PicGIM modules is easy. \n
				These are the #define that enable / disable modules.
				\code
					//		S O F T W A R E   G E N E R A L
					#define PGIM_ERROR							PG_DISABLE
					#define PGIM_CAL_DELAY						PG_DISABLE
					#define PGIM_CONSTANTS						PG_DISABLE
					
					//		H A R D W A R E   I N T E R N A L
					#define PGIM_EVENTS						PG_DISABLE
					#define PGIM_AD_CONVERTER					PG_DISABLE
					#define PGIM_SPI							PG_DISABLE
					#define PGIM_EE								PG_DISABLE
					#define PGIM_TIMER							PG_DISABLE
					#define PGIM_PWM							PG_DISABLE
					#define PGIM_SERIAL							PG_DISABLE

					//		H A R D W A R E   E X T E R N A L
					#define PGIM_LCD_HD44780					PG_DISABLE
					#define PGIM_BUZZER							PG_DISABLE
					#define PGIM_EXTERNAL_MEMORY				PG_DISABLE

					//		H A R D W A R E   G K R I P T
					#define PGIM_ENCODER						PG_DISABLE
				\endcode
				\n
				
				
			</p>

		\section	hhwset	Hardware settings
			<p>
				Each module has a dedicated hardware setting to work properly. \n
				Here there are the sections that refer for the individual hardware settings. \n
			</p>
					\subpage	SWPAGE	
					\n
					\subpage	HWPAGE
					\n
			<p>
				The changes to adapt PicGIM to your hardware are to be done in this file: \n \n
				&nbsp;&nbsp;&nbsp;  pgim_module_setup.h \n
				&nbsp;&nbsp;&nbsp;  pgim_hardware_setup.h \n
				\n \n \n \n
			</p>

	\page	SWPAGE		SOFTWARE Modules

			-	\subpage	SW_cmp
			-	\subpage	SW_gen

	\page	HWPAGE		HARDWARE Modules

			-	\subpage	HW_int
			-	\subpage	HW_ext
			-	\subpage	HW_gkr


	\page	SW_cmp		SOFTWARE::COMPULSORY Modules

			-	\subpage	SWC_version
			-	\subpage	SWC_EzFuse

	\page	SW_gen		SOFTWARE::GENERAL Modules

			-	\subpage	SWG_delay
			-	\subpage	SWG_error
			-	\subpage	SWG_constants
			-	\subpage	SWG_float

	\page	HW_int		HARDWARE::INTERNAL Modules

			-	\subpage	HWI_intosc
			-	\subpage	HWI_interrupt
			-	\subpage	HWI_adc
			-	\subpage	HWI_timer
			-	\subpage	HWI_serial
			-	\subpage	HWI_spi
			-	\subpage	HWI_ee
			-   \subpage    HWI_pwm

	\page	HW_ext		HARDWARE::EXTERNAL Modules

			-	\subpage	HWE_ext_mem
			-	\subpage	HWE_buzzer
			-	\subpage	HWE_lcd_HD44780



	\page	HW_gkr		HARDWARE::GKRIPT Modules

			-	\subpage	HWG_encoder


 */


 