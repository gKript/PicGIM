/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		picgim.h
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
		\file		picgim.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		This is the file to include in each file you want to compile in your project except the file where is the \b main() function.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_INCLUDES_H_
	#define _PGIM_INCLUDES_H_

    #pragma warning disable 520

//	#if ! defined( __18CXX ) && ! defined( __XC8 )
	#if ! defined( __18CXX )
//		#error	PicGIM can be compiled ONLY under MCHP C18 or XC8 !!!
		#error	PicGIM can be compiled ONLY under MCHP C18 !!!
	#endif

//    #include <xc.h>
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
	#include "pgim_selective_compiling_setup.h"	//load second last
	#include "pgim_selective_compiling.h"		//load last
	
	//-------------------------------------------------------------------------------
	//    I N C L U S I O N S
	//-------------------------------------------------------------------------------


	//---[ Board A ]---
	#if ( PGIM_BOARD != PG_BOARD_USER_DEFINED )
		#if ( PGIM_BOARD == PG_BOARD_A )
			#include "pgim_board_setup_a.h"
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Board A >>> Defined
			#endif
		#endif
		#if ( PGIM_BOARD == PG_BOARD_EXPERIENCE )
			#include "pgim_board_setup_experience.h"
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Experience Board >>> Defined
			#endif
		#endif
	#endif
	//---[ END Board A ]---

	
	//---[ Error ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_ERROR
		#define		PGIM_ERROR		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_ERROR
		#define		PGIM_ERROR		PG_DISABLE
	#endif
	#if ( PGIM_ERROR == PG_ENABLE )
/*
		enum _pgmodules_code_enum {
			PG_ADC,
			PG_BUZZER,
			PG_DELAY,
			//PG_CONSTANTS,
			PG_EE,
			PG_ENCODER,
			PG_EXT_MEM,
			PG_EZFUSE,
			PG_FONT,
			PG_INTERRUTPS,
			PG_LCD_PCD8544,
			PG_LCD_9340,
			PG_LCD_HD44780,
			PG_LCD_5110,
			PG_PWM,
			PG_SERIAL,
			PG_SPI,
			PG_TIMER,
			PG_FTOA,
			PG_SENSOR,
			PG_RTC_DS1302,
			PG_3WIRE,
			PG_GCP,
			PG_SSP,
			PG_GKH32,
			PG_PRS
		};
*/
		#include "pgim_error.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> ERROR module >>> Loaded
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
        #define	_XTAL_FREQ              PG_CLOCK
		#include "pgim_caldelay.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> DELAY module >>> Loaded
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
			#warning	PicGIM >>> BUZZER module >>> Loaded
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

//		#include <portb.h>      //kmod
		#include "pgim_event.h"
//		#include "pgim_interrupt_callbacks.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> IRQ module >>> INTERRUPTS handle module loaded
			#if	( PG_SUGGESTION == PG_ENABLE )
				#warning PicGIM >>> Note >>> Hint >>> See the documentation to know how initialize interrupts you want to manage.
			#endif
		#endif
	#else
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
			#warning	PicGIM >>> Note >>> INTERRUPTS disabled
			#warning    PicGIM >>> Note >>> Hint >>> Keep in mind that PicGim offers a very simple way to use them. See the documentation.
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
			#warning	PicGIM >>> ADC module >>> Loaded
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
		#include <spi.h>	                //kmod 2
//		#include <plib/spi.h>               //kmod
		#include "pgim_spi.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> SPI module >>> Loaded
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
			#warning	PicGIM >>> ERROR !!! >>> Core >>> You have requested the EE module but this MCU [ 18F97J60 ] have not the EEPROM on board. Please disable the module EE in "pgim_module_setup_public.h"
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#else
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> EE module >>> Loaded
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
//		#include <plib/timers.h>         //kmod
		#include "pgim_timer.h"
		#if ( PGIM_TIMER_0 != PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> TIMER 0 module >>> Loaded
			#endif
		#endif
		#if ( PGIM_TIMER_1 != PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> TIMER 1 module >>> Loaded
			#endif
		#endif
		#if ( PGIM_EVENTS == PG_DISABLE )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
				#warning	PicGIM >>> TIMER module >>> Hint >>> Enabled without interrupt. Keep in mind PicGIM is able to handle interrupts very easily.
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
//		#include <pwm.h>        //kmod
		#include "pgim_pwm.h"
		#if defined( __24FJ256GB110 )
			#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> ERROR !!! >>> Core >>> You have requested the PWM module but it is NOT YET SUPPORTED with this MCU. \
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
				#warning	PicGIM >>> ERROR !!! >>> Core >>> Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#else
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
					#warning	PicGIM >>> PWM 1 module >>> Loaded
				#endif
				#if defined( _GIM_H_ ) && ( PG_PWM_1_MODE != PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_ENABLE )
					#warning	PicGIM >>> ERROR !!! >>> Core >>> Sorry, ENHANCED mode NOT SUPPORTED.	Please disable it in "pgim_pwm_setup_public.h"
					#ifndef		PG_EXIT_ON_ERROR
						#define		PG_EXIT_ON_ERROR
					#endif
				#endif
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_ENABLE )
					#if ( PG_PWM_1_OUT_CONF != SINGLE_OUT )
						#warning	PicGIM >>> PWM 1 module >>> ENHANCED mode enabled
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PicGIM >>> PWM 1 module >>> AUTO-SHUTDOWN feature enabled
						#endif
					#else
						#warning	PicGIM >>> PWM 1 module >>> ENHANCED mode is disabled in SINGLE mode
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PicGIM >>> PWM 1 module >>> AUTO-SHUTDOWN feature is disabled in SINGLE mode
						#endif
					#endif
				#endif
				#if defined( _GIM_H_ )&& ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE ) && \
					( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_ENHANCED == PG_DISABLE )
					
					#warning	PicGIM >>> PWM 1 module >>> Hint >>> Keep in mind that this module supports the ENHANCED mode
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
				#warning	PicGIM >>> ERROR !!! >>> Core >>> Sorry, module NOT PRESENT in this MCU. Please disable it in "pgim_pwm_setup_public.h"
				#ifndef		PG_EXIT_ON_ERROR
					#define		PG_EXIT_ON_ERROR
				#endif
			#else
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
					#warning	PicGIM >>> PWM 2 module >>> Loaded
				#endif
				#if defined( _GIM_H_ ) && ( PG_PWM_2_MODE != PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_ENABLE )
					#warning	PicGIM >>> ERROR !!! >>> Core >>> Sorry, ENHANCED mode NOT SUPPORTED. Please disable it in "pgim_pwm_setup_public.h"
					#ifndef		PG_EXIT_ON_ERROR
						#define		PG_EXIT_ON_ERROR
					#endif
				#endif
				#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_ENABLE )
					#if ( PG_PWM_2_OUT_CONF != SINGLE_OUT )
						#warning	PicGIM >>> PWM 2 module >>> ENHANCED mode enabled
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PicGIM >>> PWM 2 module >>> SHUTDOWN feature enabled
						#endif
					#else
						#warning	PicGIM >>> PWM 2 module >>> ENHANCED mode is disabled in SINGLE mode
						#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
							#warning	PicGIM >>> PWM 2 module >>> SHUTDOWN feature is disabled in SINGLE mode
						#endif
					#endif
				#endif
				#if defined( _GIM_H_ )&& ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE ) && \
					( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_ENHANCED == PG_DISABLE )
					#warning	PicGIM >>> PWM 2 module >>> Hint >>> Keep in mind that this module supports the ENHANCED mode
				#endif
			#endif
		#endif
//		#if	defined( _GIM_H_ ) && \
//			( ( ( PGIM_PWM_1 == PG_ENABLE ) && ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) \
//			&& ( PG_PWM_1_OUT_CONF == HALF_OUT ) ) || ( ( PGIM_PWM_2 == PG_ENABLE ) && ( PG_PWM_2_ENHANCED == PG_ENABLE ) \
//			&& ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF == HALF_OUT ) ) )

		#if	defined( _GIM_H_ )
			#if ( ( PGIM_PWM_1 == PG_ENABLE ) && ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF == HALF_OUT ) ) || \
				( ( PGIM_PWM_2 == PG_ENABLE ) && ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF == HALF_OUT ) )			

//				#if ( PG_PWM_DEAD_TIME > ( ( 1 / PG_CLOCK ) * PG_TCYCLEPERI * 0x7F ) )
				#if ( PG_PWM_DEAD_TIME > ( PG_TCYCLEPERI * 0x7F / ( PG_CLOCK / 1000000 ) ) )
					#warning	PicGIM >>> ERROR !!! >>> Core >>> Dead-time is too long. Please decrease the value in "pgim_pwm_setup_public.h"
					#ifndef		PG_EXIT_ON_ERROR
						#define		PG_EXIT_ON_ERROR
					#endif
				#else
					#warning	PicGIM >>> PWM module >>> Set DEAD-TIME
				#endif
			#endif
		#endif
		#if	defined( _GIM_H_ ) && ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_PWM_DC_RESOLUTION_MAX_CALC == PG_ENABLE ) && \
			( ( PGIM_PWM_1 == PG_ENABLE ) || ( PGIM_PWM_2 == PG_ENABLE ) )
			#warning	PicGIM >>> PWM module >>> Enabled duty-cycle resolution max calculation [bit]
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
		#include "pgim_lcd_hd44780.h"
		#if ( ( PG_LCD_HD44780_BUSY_FLAG == PG_ENABLE ) && ( PG_LCD_HD44780_RW_PRESENT == PG_NO ) )
			#error	PicGIM >>> LCD HD44780 module >>> Can not read busy flag, because writing pin is not used!
		#endif
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> LCD HD44780 module >>> Loaded
		#endif
	#endif
	//---[ END Lcd HD44780 ]---
	

	//---[ Lcd 5110 ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_LCD_5110
		#define		PGIM_LCD_5110		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_LCD_5110
		#define		PGIM_LCD_5110		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_LCD_5110 == PG_ENABLE )
		#include "pgim_lcd_5110.h"
		
		#if defined( PG_5110_VMEM_AMOUNT ) 
			#undef	PG_5110_VMEM_AMOUNT
		#endif
		
		#define PG_5110_VMEM_AMOUNT		504
		#if PG_MAX_RAM > ( 2.5 * PG_5110_VMEM_AMOUNT )
			#if	PG_LCD_5110_VIDEO_MEMORY == PG_YES
				_pg_Ubuffer vbuff_5110[ PG_5110_VMEM_AMOUNT ];
				#if defined( _GIM_H )
					#if ( PG_VERBOSE == PG_ENABLE )
						#warning	PicGIM: This amount of allocated RAM ( 504 Bytes ) may cause errors during linking. Use the correct file LKR equipped by PicGIM relating to the selected MCU.
					#endif
				#endif
			#else
				#if defined( _GIM_H )
					#if PG_VERBOSE == PG_ENABLE && PG_SUGGESTION == PG_ENABLE
						#warning	PicGIM: This MCU can use the VIDEO BUFFER. Keep on mind.
					#endif
				#endif
			#endif
		#else
			#if defined( _GIM_H )
				#if ( PG_VERBOSE == PG_ENABLE )
					#warning	PicGIM: Not enough RAM ( PG_MAX_RAM Bytes ) to use VIDEO BUFFER
				#endif
			#endif
		#endif
		
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> LCD 5110 module >>> Loaded
		#endif
	#endif
	//---[ END Lcd 5110 ]---
	
	
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
//		//#include "pgim_font_setup.h"
//		#include "pgim_lcd_pcd8544.h"
//		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
//			#warning	PicGIM >>> LCD PCD8544 module >>> Loaded
//			#if ( PGIM_FONT == PG_ENABLE )
//				#warning	PicGIM >>> LCD PCD8544 module >>> Fonts enabled and loaded
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
//			#warning	PicGIM >>> LCD 9340 module >>> Loaded
//			#if ( PGIM_FONT == PG_ENABLE )
//				#warning	PicGIM >>> LCD 9340 module >>> Fonts enabled and loaded
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
			#warning	PicGIM >>> ENCODER module >>> Loaded
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
		#include <usart.h>          //kmod
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
			#warning	PicGIM >>> SERIAL module >>> Loaded
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_AUTOMATIC ) )
				#warning	PicGIM >>> SERIAL module >>> Activated AUTOMATIC mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_SEMI_AUTOMATIC ) )
				#warning	PicGIM >>> SERIAL module >>> Activated SEMI-AUTOMATIC mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE == PG_MANUAL ) )
				#warning	PicGIM >>> SERIAL module >>> Activated MANUAL mode configuration
			#endif
			#if ( ( PG_SUGGESTION == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL ) )
				#warning	PicGIM >>> SERIAL module >>> Trying to calculate parameter...
			#endif			
			#if ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PicGIM >>> SERIAL module >>> Activated debug output to PIN
			#endif
			#if ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PicGIM >>> SERIAL module >>> Activated debug output to LCD-PCD8544
			#endif
			#if ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
				#warning	PicGIM >>> SERIAL module >>> Activated debug output to LCD-HD44780
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
			#warning	PicGIM >>> EXTERNAL MEMORY module >>> Loaded
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
//			#warning	PicGIM >>> SERVO module >>> Loaded
//		#endif
//	#endif
//	//---[ END Servo ]---


	//---[ Ftoa Function]---
	#if ( PGIM_FTOA == PG_ENABLE )
		#include "pgim_ftoa.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> FTOA function >>> Included
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
			#warning	PicGIM >>> SENSOR module >>> Loaded
			#if ( ( PGIM_SENSOR_ADC_REF == PG_DISABLE ) && ( PG_USER_SUPPLY_BATTERY	== PG_YES ) )
				#warning	PicGIM >>> SENSOR module >>> Hint >>> With the battery power supply (voltage non-constant) it is better to use the ADC-Ref module for the measurement of the true supply voltage.
			#endif
			// Parameter "PGIM_SENSOR_ADC_REF_VOLT" value check
			#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
				#if( PGIM_SENSOR_ADC_REF_VOLT > PG_USER_SUPPLY_VOLT )
					#warning	PicGIM >>> SENSOR module >>> Reference voltage value too big!
				#endif
				#if( ( PGIM_SENSOR_ADC_REF_VOLT < 0 ) || ( PGIM_SENSOR_ADC_REF_VOLT == 0 ) )
					#warning	PicGIM >>> SENSOR module >>> Reference voltage value negative or zero!
				#endif
			#endif
			#if ( ( PGIM_SENSOR_NTC_USE_ADCREF == PG_YES ) && ( PGIM_SENSOR_ADC_REF == PG_DISABLE ) )
				#warning	PicGIM >>> SENSOR module >>> ADC-Ref sensor must be enabled to be used with the NTC sensor!
			#endif
			#if ( ( PGIM_SENSOR_NTC_USE_ADCREF == PG_YES ) && ( PGIM_SENSOR_ADC_REF == PG_ENABLE ) )
				#warning 	PicGIM >>> SENSOR module >>> Using ADC-Ref sensor to measure the power supply voltage for the NTC sensor.
			#else
				#warning 	PicGIM >>> SENSOR module >>> Using declared power supply voltage for the NTC sensor.
			#endif
		#endif
	#endif
	//---[ END Sensor ]---

	
	//---[ RTC_DS1302 ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_RTC_DS1302
		#define		PGIM_RTC_DS1302		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_RTC_DS1302
		#define		PGIM_RTC_DS1302		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_RTC_DS1302 == PG_ENABLE )
		#include "pgim_rtc_ds1302.h"
		// E R R O R   C H E C K   B E F O R E   L O A D   M O D U L E
		#if( ( PG_RTC_DS1302_WR_TIME_ALL == PG_INCLUDE ) || ( PG_RTC_DS1302_RD_TIME_ALL == PG_INCLUDE ) )
			#if( ( PG_RTC_DS1302_USE_MIN == PG_EXCLUDE ) || ( PG_RTC_DS1302_USE_HOUR == PG_EXCLUDE ) )
				#error	PicGIM >>> RTC_DS1302 module >>> ERROR !!! >>> Incorrect pgim_selective_compiling_setup.h configuration file. Must be enabled minutes and hours, if you want to use *_ALL functions!
			#endif
		#endif
		#if( ( PG_RTC_DS1302_WR_DATE_ALL == PG_INCLUDE ) || ( PG_RTC_DS1302_RD_DATE_ALL == PG_INCLUDE ) )
			#if( ( PG_RTC_DS1302_USE_DAY == PG_EXCLUDE ) || ( PG_RTC_DS1302_USE_MONTH == PG_EXCLUDE ) || ( PG_RTC_DS1302_USE_YEAR == PG_EXCLUDE ) )
				#error	PicGIM >>> RTC_DS1302 module >>> ERROR !!! >>> Incorrect pgim_selective_compiling_setup.h configuration file. Must be enabled day, month and year, if you want to use *_ALL functions!
			#endif
		#endif
		//If all is OK...
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> RTC_DS1302 module >>> Loaded
		#endif	
	#endif
	//---[ END RTC_DS1302 ]---
	
	
	//---[ 3Wire ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_3WIRE
		#define		PGIM_3WIRE		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_3WIRE
		#define		PGIM_3WIRE		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_3WIRE == PG_ENABLE )
		#include "pgim_3wire.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> 3WIRE module >>> Loaded
		#endif
	#endif
	//---[ END 3Wire ]---
	
	
	//---[ GCP ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_GCP
		#define		PGIM_GCP		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_GCP
		#define		PGIM_GCP		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( ( ( ( PG_GCP_BUFFER_RX_01_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_01_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_02_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_02_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_03_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_03_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_04_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_04_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_05_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_05_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_06_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_06_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_07_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_07_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_08_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_08_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_09_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_09_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_10_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_10_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_11_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_11_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_12_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_12_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_13_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_13_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_14_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_14_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_15_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_15_MODE	== PG_GCP_STRING ) ) || \
			( ( PG_GCP_BUFFER_RX_16_ENABLE == PG_ENABLE	) && ( PG_GCP_BUFFER_RX_16_MODE	== PG_GCP_STRING ) ) ) && ( PG_GCP_STATUS_MOD_ENABLE == PG_DISABLE ) )
	  #warning PicGIM >>> GCP module >>> Strings need STATUS_MOD enabled.
	#endif
	//If all is OK...
	#if ( PGIM_GCP == PG_ENABLE ) 
		#include "pgim_gcp.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> GCP module >>> Loaded
		#endif
	#endif
	//---[ END GCP ]---
	
	
	//---[ SSP ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_SSP
		#define		PGIM_SSP		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_SSP
		#define		PGIM_SSP		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_SSP == PG_ENABLE ) 
		#include "pgim_ssp.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> SSP module >>> Loaded
		#endif
	#endif
	//---[ END SSP ]---
	
	
	//---[ H32 ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_GKH32
		#define		PGIM_GKH32		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_GKH32
		#define		PGIM_GKH32		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_GKH32 == PG_ENABLE ) 
		#include "pgim_gkh32.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> GKH32 module >>> Loaded
		#endif
	#endif
	//---[ END H32 ]---
	
	
	//---[ PRS ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_PRS
		#define		PGIM_PRS		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_PRS
		#define		PGIM_PRS		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_PRS == PG_ENABLE ) 
		#include "pgim_prs.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> PRS module >>> Loaded
		#endif
	#endif
	//---[ END PRS ]---
	

	//---[ FONT ]---
	#if defined( PG_DOXYGEN )
		#undef		PGIM_FONT
		#define		PGIM_FONT		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PGIM_FONT
		#define		PGIM_FONT		PG_DISABLE
	#endif
	//--------------------------------------------------
	#if ( PGIM_FONT == PG_ENABLE )
		#include "pgim_font_setup.h"
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			#warning	PicGIM >>> FONT module >>> Loaded
		#endif
	#endif
	//---[ END FONT ]---


	//------------------------------------------------------------------------------
	//		E R R O R   M A N A G E M A N T
	//------------------------------------------------------------------------------
	
	#if defined( PG_EXIT_ON_ERROR ) 
		#error	PicGIM >>> ERROR !!! >>> Core >>> PicGIM has stopped compiling due to errors in configuration
	#endif 
	
#endif 


