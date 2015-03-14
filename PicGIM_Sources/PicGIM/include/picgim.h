//
// picgim.h
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

/*!		\file			picgim.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			Includes compiler and enabled modules header file.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
		\warning		This file is to be included in all files .C added by the user. \n <b>It is NOT to be included</b> in the file where is the \b main() function.
 */

#ifndef _PGIM_INCLUDES_H_
	#define _PGIM_INCLUDES_H_

//	#define PG_DOXYGEN

	#ifdef __XC8
		#include <xc.h>
	#endif

	#if ! defined( __18CXX ) && ! defined ( __PIC24F__ ) && ! defined( __XC8 )
		#error	PicGIM can be compiled ONLY under MCHP C18, C30 or XC8 !!!
	#endif

	#if defined( __18CXX )
		#include <io.h>
		#include <pconfig.h>
	#elif defined( __XC8 )
		#include <xc.h>
	#endif

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <math.h>

	#include "pgim_version.h"
	#include "pgim_custom_type.h"
	#include "pgim_defines.h"
	#include "pgim_module_setup.h"
	#include "pgim_hardware_setup_public.h"

	
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S
	//-------------------------------------------------------------------------------


	//---[ Board A ]---
	#if ( PGIM_BOARD != PG_BOARD_USER_DEFINED )
		#if ( PGIM_BOARD == PG_BOARD_A )
			#include "pgim_board_setup_a.h"
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HB_A Defined
			#endif
		#endif
		#if ( PGIM_BOARD == PG_BOARD_EXPERIENCE )
			#include "pgim_board_setup_experience.h"
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HB_EXPERIENCE Defined
			#endif
		#endif
	#endif
	//---[ END Board A ]---

	
//	//---[ Constants ]---
//	#if ( PGIM_CONSTANTS == PG_ENABLE )
//		#include "pgim_constants.h"
//		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PG_HS_PG PG_HM_UNIV_CONST Defined
//		#endif
//	#endif
//	//---[ END Constants ]---


	//---[ Error ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_ERROR
		#define		PGIM_ERROR		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_ERROR
		#define		PGIM_ERROR		PG_DISABLE
	#endif
	#if ( PGIM_ERROR == PG_ENABLE )

		enum _pgmodules_code_enum {
			PG_ADC,
			PG_BUZZER,
			PG_DELAY,
			PG_CONSTANTS,
			PG_EE,
			PG_ENCODER,
			PG_EXT_MEM,
			PG_EZFUSE,
			PG_FONT,
			PG_INTERRUTPS,
			PG_LCD_PCD8544,
			PG_LCD_9340,
			PG_LCD_HD44780,
			PG_PWM,
			PG_SERIAL,
			PG_SPI,
			PG_TIMER,
			PG_FTOA,
			PG_SENSOR
		};

		#include "pgim_error.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_ERROR Loaded
		#endif
	#endif
	//---[ END Error ]---


	//---[ Calibrated Delay ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_CAL_DELAY
		#define		PGIM_CAL_DELAY		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_CAL_DELAY
		#define		PGIM_CAL_DELAY		PG_DISABLE
	#endif
	#if ( PGIM_CAL_DELAY == PG_ENABLE )
		#include "pgim_caldelay.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_DELAY Loaded
		#endif
	#else
		#if defined( __18CXX )
			#include <delays.h>
		#endif
	#endif
	//---[ END Calibrated Delay ]---
	
	
	//---[ Buzzer ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_BUZZER
		#define		PGIM_BUZZER		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_BUZZER
		#define		PGIM_BUZZER		PG_DISABLE
	#endif
	#if ( PGIM_BUZZER == PG_ENABLE )
	
		#include "pgim_buzzer.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_BUZZER Loaded
		#endif
	#endif
	//---[ END Buzzer ]---
	
	
	//---[ Interrupts ]---
	#if defined( PG_DOXYGEN )
	
		#undef		PGIM_EVENTS
		#undef		PG_EVENT_SET_INT0	
		#undef		PG_EVENT_SET_INT1	
		#undef		PG_EVENT_SET_INT2	
		#undef		PG_EVENT_SET_TMR0	
		#undef		PG_EVENT_SET_TMR1	
		#undef		PG_EVENT_SET_TMR2	
		#undef		PG_EVENT_SET_RB0	
		#undef		PG_EVENT_SET_AD		
		#undef		PG_EVENT_SET_USARTRC      
		#undef		PG_EVENT_SET_USARTTX      
		#undef		PG_EVENT_SET_SSP	
		#undef		PG_EVENT_SET_CCP1	
		#undef		PG_EVENT_SET_CCP2	
		#undef		PG_EVENT_SET_OSCF	
		#undef		PG_EVENT_SET_CM		
		#undef		PG_EVENT_SET_EE		
		#undef		PG_EVENT_SET_BCL	

		#define		PGIM_EVENTS			PG_ENABLE
		#define		PG_EVENT_SET_INT0			PG_ENABLE
		#define		PG_EVENT_SET_INT1			PG_ENABLE
		#define		PG_EVENT_SET_INT2			PG_ENABLE
		#define		PG_EVENT_SET_TMR0		PG_ENABLE
		#define		PG_EVENT_SET_TMR1		PG_ENABLE
		#define		PG_EVENT_SET_TMR2		PG_ENABLE
		#define		PG_EVENT_SET_RB0			PG_ENABLE
		#define		PG_EVENT_SET_AD			PG_ENABLE
		#define		PG_EVENT_SET_USARTRC	PG_ENABLE
		#define		PG_EVENT_SET_USARTTX	PG_ENABLE
		#define		PG_EVENT_SET_SSP			PG_ENABLE
		#define		PG_EVENT_SET_CCP1		PG_ENABLE
		#define		PG_EVENT_SET_CCP2		PG_ENABLE
		#define		PG_EVENT_SET_OSCF		PG_ENABLE
		#define		PG_EVENT_SET_CM			PG_ENABLE
		#define		PG_EVENT_SET_EE			PG_ENABLE
		#define		PG_EVENT_SET_BCL			PG_ENABLE
	
	
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_EVENTS
		#define		PGIM_EVENTS		PG_DISABLE
	#endif
	
	//--------------------------------------------------
	#if ( PGIM_EVENTS == PG_ENABLE )
	
		#include "pgim_event.h"
//		#include "pgim_interrupt_callbacks.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_IRQ INTERRUPTS handle module loaded
			#if	( PG_SUGGESTION == PG_ENABLE )
				#warning PG_HS_PG PG_HS_NOTE PG_HS_SUGG See the documentation to know how initialize interrupts you want to manage.
			#endif
		#endif
	#else
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
			#warning	PG_HS_PG PG_HS_NOTE INTERRUPTS disabled
			#warning    PG_HS_PG PG_HS_NOTE PG_HS_SUGG Keep in mind that PicGim offers a very simple way to use them. See the documentation.
		#endif
	#endif
	//---[ END Interrupts ]---
	
	
	//---[ AD-Converter ]---
	#if defined( PG_DOXYGEN )
	
		#undef		PGIM_AD_CONVERTER
		#define		PGIM_AD_CONVERTER		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_AD_CONVERTER
		#define		PGIM_AD_CONVERTER		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_AD_CONVERTER == PG_ENABLE )
		#include "pgim_adc.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_ADC Loaded
		#endif
	#endif
	//---[ END AD-Converter ]---
	
	
	//---[ Spi ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_SPI
		#define		PGIM_SPI		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_SPI
		#define		PGIM_SPI		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_SPI == PG_ENABLE )
		#include <spi.h>
		#include "pgim_spi.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_SPI Loaded
		#endif
	#endif
	//---[ END Spi ]---
	
	
	//---[ EE ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_EE
		#define		PGIM_EE		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_EE
		#define		PGIM_EE		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_EE == PG_ENABLE )
		#include "pgim_ee.h"
		#if defined( __18F97J60 )
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You have requested the EE module but this MCU [ 18F97J60 ] have not the EEPROM on board. Please disable the module EE in "pgim_module_setup_public.h"
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#else
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HM_EE Loaded
			#endif
		#endif
	#endif
	//---[ END EE ]---
	
	
	//---[ Timer ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_TIMER
		#define		PGIM_TIMER		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_TIMER
		#define		PGIM_TIMER		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_TIMER == PG_ENABLE )
		#include <timers.h>
		#include "pgim_timer.h"
		#if ( PGIM_TIMER_0 != PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HM_TIMER0 Loaded
			#endif
		#endif
		#if ( PGIM_TIMER_1 != PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HM_TIMER1 Loaded
			#endif
		#endif
		#if ( PGIM_EVENTS == PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
				#warning	PG_HS_PG PG_HM_TIMER PG_HS_SUGG Enabled without interrupt. Keep in mind PicGIM is able to handle interrupts very easily.
			#endif
		#endif
	#endif
	//---[ END Timer ]---
	
	
	//---[ Pwm ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_PWM
		#define		PGIM_PWM		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_PWM
		#define		PGIM_PWM		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_PWM == PG_ENABLE )
		#include <pwm.h>
		#include "pgim_pwm.h"
		#if defined( __24FJ256GB110 )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE You have requested the PWM module but it is NOT YET SUPPORTED with this MCU. \
								Please disable this module in "pgim_module_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#endif
		#endif
		//--------------------------------------------------
		#if defined( PG_DOXYGEN )
			#undef		PGIM_PWM_1
			#define		PGIM_PWM_1		PG_ENABLE
		#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
			#undef		PGIM_PWM_1
			#define		PGIM_PWM_1		PG_DISABLE
		#endif
		//--------------------------------------------------
		#if ( PGIM_PWM_1 == PG_ENABLE )
		
			#if defined( _GIM_H_ ) && ( PG_PWM_1_MODE == PG_NONE )
				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#else
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
					#warning	PG_HS_PG PG_HM_PWM1 Loaded
				#endif
				#if defined( _GIM_H_ ) && ( PG_PWM_1_MODE != PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_ENABLE )
					#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE Sorry, ENHANCED mode NOT SUPPORTED.	Please disable it in "pgim_pwm_setup_public.h"
					#ifndef		PG_EXIT_ON_ERROR
						#define		PG_EXIT_ON_ERROR
					#endif
				#endif
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_ENABLE )
					#if ( PG_PWM_1_OUT_CONF != SINGLE_OUT )
						#warning	PG_HS_PG PG_HM_PWM1 ENHANCED mode enabled
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PG_HS_PG PG_HM_PWM1 AUTO-SHUTDOWN feature enabled
						#endif
					#else
						#warning	PG_HS_PG PG_HM_PWM1 ENHANCED mode is disabled in SINGLE mode
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PG_HS_PG PG_HM_PWM1 AUTO-SHUTDOWN feature is disabled in SINGLE mode
						#endif
					#endif
				#endif
				#if defined( _GIM_H_ )&& ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE ) && \
					( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_DISABLE )
					
					#warning	PG_HS_PG PG_HM_PWM1 PG_HS_SUGG Keep in mind that this module supports the ENHANCED mode
				#endif
			#endif
		#endif
		//--------------------------------------------------
		#if defined( PG_DOXYGEN )
			#undef		PGIM_PWM_2
			#define		PGIM_PWM_2		PG_ENABLE
		#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
			#undef		PGIM_PWM_2
			#define		PGIM_PWM_2		PG_DISABLE
		#endif
		//--------------------------------------------------
		#if ( PGIM_PWM_2 == PG_ENABLE )
		
			#if defined( _GIM_H_ ) && ( PG_PWM_2_MODE == PG_NONE )
				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#else
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
					#warning	PG_HS_PG PG_HM_PWM2 Loaded
				#endif
				#if defined( _GIM_H_ ) && ( PG_PWM_2_MODE != PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_ENABLE )
					#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE Sorry, ENHANCED mode NOT SUPPORTED. Please disable it in "pgim_pwm_setup_public.h"
					#ifndef		PG_EXIT_ON_ERROR
						#define		PG_EXIT_ON_ERROR
					#endif
				#endif
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_ENABLE )
					#if ( PG_PWM_2_OUT_CONF != SINGLE_OUT )
						#warning	PG_HS_PG PG_HM_PWM2 ENHANCED mode enabled
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PG_HS_PG PG_HM_PWM2 SHUTDOWN feature enabled
						#endif
					#else
						#warning	PG_HS_PG PG_HM_PWM2 ENHANCED mode is disabled in SINGLE mode
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PG_HS_PG PG_HM_PWM2 SHUTDOWN feature is disabled in SINGLE mode
						#endif
					#endif
				#endif
				#if defined( _GIM_H_ )&& ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE ) && \
					( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_DISABLE )
					#warning	PG_HS_PG PG_HM_PWM2 PG_HS_SUGG Keep in mind that this module supports the ENHANCED mode
				#endif
			#endif
		#endif
		#if	defined( _GIM_H_ ) && \
			( ( ( PGIM_PWM_1 == PG_ENABLE ) && ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) \
			&& ( PG_PWM_1_OUT_CONF == HALF_OUT ) ) || ( ( PGIM_PWM_2 == PG_ENABLE ) && ( PG_PWM_2_ENHANCED == PG_ENABLE ) \
			&& ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF == HALF_OUT ) ) )
			
			#if ( PG_PWM_DEAD_TIME > ( ( 1 / PG_CLOCK ) * PG_TCYCLEPERI * 0x7F ) )
				#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE Dead-time is too long. Please decrease the value in "pgim_pwm_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#else
				#warning	PG_HS_PG PG_HM_PWM Set DEAD-TIME
			#endif
		#endif
		#if	defined( _GIM_H_ ) && ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_PWM_DC_RESOLUTION_MAX_CALC == PG_ENABLE ) && \
			( ( PGIM_PWM_1 == PG_ENABLE ) || ( PGIM_PWM_2 == PG_ENABLE ) )
			#warning	PG_HS_PG PG_HM_PWM Enabled duty-cycle resolution max calculation [bit]
		#endif	
	#endif
	//---[ END Pwm ]---
	
	
	//---[ Lcd HD44780 ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_LCD_HD44780
		#define		PGIM_LCD_HD44780		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_LCD_HD44780
		#define		PGIM_LCD_HD44780		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
		#if ( PG_LCD_HD44780_EN_0_PRESENT  ==  PG_DISABLE )
			#undef	PG_LCD_HD44780_EN_0
			#define	PG_LCD_HD44780_EN_0		L_A1
			#undef	PG_LCD_HD44780_EN_0_TRIS
			#define	PG_LCD_HD44780_EN_0_TRIS	T_A1
		#endif
		#if ( PG_LCD_HD44780_EN_1_PRESENT  ==  PG_DISABLE )
			#undef	PG_LCD_HD44780_EN_1
			#define	PG_LCD_HD44780_EN_1		L_A1
			#undef	PG_LCD_HD44780_EN_1_TRIS
			#define	PG_LCD_HD44780_EN_1_TRIS	T_A1
		#endif
		#if ( PG_LCD_HD44780_EN_2_PRESENT  ==  PG_DISABLE )
			#undef	PG_LCD_HD44780_EN_2
			#define	PG_LCD_HD44780_EN_2		L_A1
			#undef	PG_LCD_HD44780_EN_2_TRIS
			#define	PG_LCD_HD44780_EN_2_TRIS	T_A1
		#endif
		#if ( PG_LCD_HD44780_EN_3_PRESENT  ==  PG_DISABLE )
			#undef	PG_LCD_HD44780_EN_3
			#define	PG_LCD_HD44780_EN_3		L_A1
			#undef	PG_LCD_HD44780_EN_3_TRIS
			#define	PG_LCD_HD44780_EN_3_TRIS	T_A1
		#endif
		#include "pgim_lcd_hd44780.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_LCD_HD44780 Loaded
		#endif
	#endif
	//---[ END Lcd HD44780 ]---
	
	
	//---[ Lcd PCD8544 ]---
//	#if defined( PG_DOXYGEN )
//		#undef		PGIM_LCD_PCD8544
//		#define		PGIM_LCD_PCD8544		PG_ENABLE
//	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
//		#undef		PGIM_LCD_PCD8544
//		#define		PGIM_LCD_PCD8544		PG_DISABLE
//	#endif
//	//--------------------------------------------------
//	#if ( PGIM_LCD_PCD8544 == PG_ENABLE )
//		#include "pgim_font_setup.h"
//		#include "pgim_lcd_pcd8544.h"
//		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PG_HS_PG PG_HM_LCD_PCD8544 Loaded
//			#if ( PGIM_FONTS == PG_ENABLE )
//				#warning	PG_HS_PG PG_HM_LCD_PCD8544 Fonts enabled and loaded
//			#endif
//		#endif
//	#endif
	//---[ END Lcd PCD8544 ]---
	
	
	//---[ Lcd 9340 ]---
//	#if defined( PG_DOXYGEN )
//		#undef		PGIM_LCD_9340
//		#define		PGIM_LCD_9340		PG_ENABLE
//	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
//		#undef		PGIM_LCD_9340
//		#define		PGIM_LCD_9340		PG_DISABLE
//	#endif
//	//--------------------------------------------------
//	#if ( PGIM_LCD_9340 == PG_ENABLE )
//		#include "pgim_font_setup.h"
//		#include "pgim_lcd_9340.h"
//		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PG_HS_PG PG_HM_LCD_9340 Loaded
//			#if ( PGIM_FONTS == PG_ENABLE )
//				#warning	PG_HS_PG PG_HM_LCD_9340 Fonts enabled and loaded
//			#endif
//		#endif
//	#endif
	//---[ END Lcd 9340 ]---
	
	
	//---[ Encoder ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_ENCODER
		#define		PGIM_ENCODER		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_ENCODER
		#define		PGIM_ENCODER		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_ENCODER == PG_ENABLE )
		#include "pgim_encoder.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_ENCODER Loaded
		#endif
	#endif
	//---[ END Encoder ]---
	
	
	//---[ Serial ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_SERIAL
		#define		PGIM_SERIAL		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_SERIAL
		#define		PGIM_SERIAL		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_SERIAL == PG_ENABLE )
		#include <usart.h>
		#include "pgim_serial.h"

		//		B A U D R A T E   D E B U G   O U T P U T   T O   P I N
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_DEBUG_TO_PIN				PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PGIM_SERIAL_DEBUG_PIN					L_B3				//!< Output pin for debugging
		#define PGIM_SERIAL_DEBUG_PIN_TRIS				T_B3				//!< Debugging output pin tris

		//		B A U D R A T E   D E B U G   O U T P U T   T O   B U Z Z E R
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_DEBUG_TO_BUZZER				PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE

		//		B A U D R A T E   D E B U G   O U T P U T   T O   L C D
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		//#define PGIM_SERIAL_DEBUG_TO_LCD_PCD8544		PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE. It is not yet supported.
		#define PGIM_SERIAL_DEBUG_TO_LCD_HD44780		PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE

		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_SERIAL Loaded
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_AUTOMATIC ) )
				#warning	PG_HS_PG PG_HM_SERIAL Activated AUTOMATIC mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_SEMI_AUTOMATIC ) )
				#warning	PG_HS_PG PG_HM_SERIAL Activated SEMI-AUTOMATIC mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_MANUAL ) )
				#warning	PG_HS_PG PG_HM_SERIAL Activated MANUAL mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) )
				#warning	PG_HS_PG PG_HM_SERIAL Trying to calculate parameter...
			#endif			
			#if ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PG_HS_PG PG_HM_SERIAL Activated debug output to PIN
			#endif
			#if ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PG_HS_PG PG_HM_SERIAL Activated debug output to LCD-PCD8544
			#endif
			#if ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PG_HS_PG PG_HM_SERIAL Activated debug output to LCD-HD44780
			#endif
		#endif
	#endif
	//---[ END Serial ]---
	
	
	//---[ External Memory ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_EXTERNAL_MEMORY
		#define		PGIM_EXTERNAL_MEMORY		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_EXTERNAL_MEMORY
		#define		PGIM_EXTERNAL_MEMORY		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		#include "pgim_external_memory.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_EXT_MEM Loaded
		#endif
	#endif
	//---[ END External Memory ]---

	
//	//---[ Servo ]---
//	#if defined( PG_DOXYGEN )
//		#undef		PGIM_SERVO
//		#define		PGIM_SERVO			PG_ENABLE
//	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
//		#undef		PGIM_SERVO
//		#define		PGIM_SERVO			PG_DISABLE
//	#endif
//	//--------------------------------------------------
//	#if ( PGIM_SERVO == PG_ENABLE )
//		#include "pgim_servo.h"
//		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PG_HS_PG PG_HM_SERVO Loaded
//		#endif
//	#endif
//	//---[ END Servo ]---


	//---[ Ftoa Function]---
	#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_SERIAL == PG_ENABLE ) || ( PGIM_SPI == PG_ENABLE ) )
		#include "pgim_ftoa.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HF_FTOA Included
		#endif
	#endif
	//---[ END Ftoa Function ]---

	
	//---[ Sensor ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_SENSOR
		#define		PGIM_SENSOR		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_SENSOR
		#define		PGIM_SENSOR		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_SENSOR == PG_ENABLE )
		#include "pgim_sensor.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PG_HS_PG PG_HM_SENSOR Loaded
			#if ( ( PGIM_SENSOR_ADC_REF == PG_DISABLE ) && ( PG_USER_SUPPLY_BATTERY	== PG_YES ) )
				#warning	PG_HS_PG PG_HM_SENSOR PG_HS_SUGG With the battery power supply (voltage non-constant) it is better to use the ADC-Ref module for the measurement of the true supply voltage.
			#endif
			// Parameter "PGIM_SENSOR_ADC_REF_VOLT" value check
			#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
				#if( PGIM_SENSOR_ADC_REF_VOLT > PG_USER_SUPPLY_VOLT )
					#warning	PG_HS_PG PG_HM_SENSOR Reference voltage value too big!
				#endif
				#if( ( PGIM_SENSOR_ADC_REF_VOLT < 0 ) || ( PGIM_SENSOR_ADC_REF_VOLT == 0 ) )
					#warning	PG_HS_PG PG_HM_SENSOR Reference voltage value negative or zero!
				#endif
			#endif
			#if ( ( PGIM_SENSOR_NTC_USE_ADCREF == PG_YES ) && ( PGIM_SENSOR_ADC_REF == PG_DISABLE ) )
				#warning	PG_HS_PG PG_HM_SENSOR ADC-Ref sensor must be enabled to be used with the NTC sensor!
			#endif
			#if ( ( PGIM_SENSOR_NTC_USE_ADCREF == PG_YES ) && ( PGIM_SENSOR_ADC_REF == PG_ENABLE ) )
				#warning 	PG_HS_PG PG_HM_SENSOR Using ADC-Ref sensor to measure the power supply voltage for the NTC sensor.
			#else
				#warning 	PG_HS_PG PG_HM_SENSOR Using declared power supply voltage for the NTC sensor.
			#endif
		#endif
	#endif
	//---[ END Sensor ]---

	
////////////////////////////////////////////////////////////////////////////////////////////////////////
//	E R R O R   M A N A G E M A N T
////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	#if defined( PG_EXIT_ON_ERROR ) 
		#error	PG_HS_PG PG_HS_ERR PG_HS_CORE PicGIM has stopped compiling due to errors in configuration
	#endif 
	
#endif 


