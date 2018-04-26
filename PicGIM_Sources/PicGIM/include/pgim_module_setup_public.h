/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_module_setup_public.h
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
		\file		pgim_module_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Allows to enable or disable individual modules.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_MODULE_SETUP_PUBLIC_H_
	#define	_PGIM_MODULE_SETUP_PUBLIC_H_

	//================================================================================================================
	//		S O F T W A R E   G E N E R A L
	//================================================================================================================
	#define PGIM_ERROR								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_CAL_DELAY							PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_FTOA								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_GCP								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_SSP								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_GKH32								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_PRS								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_FONT								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	
	//================================================================================================================
	//		S O F T W A R E   D E V I C E
	//================================================================================================================
	#define PGIM_3WIRE								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	
	//================================================================================================================
	//		H A R D W A R E   I N T E R N A L
	//================================================================================================================
	#define PGIM_EVENTS								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_AD_CONVERTER						PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SPI								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_I2C								PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_EE									PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_TIMER								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_PWM								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SERIAL								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	
	//================================================================================================================
	//		H A R D W A R E   E X T E R N A L
	//================================================================================================================
	#define PGIM_LCD_HD44780						PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_LCD_PCD8544						PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_BUZZER								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SENSOR								PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_RTC_DS1302							PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	#define	PGIM_EXTERNAL_MEMORY					PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	
	//================================================================================================================
	//		H A R D W A R E   G K R I P T
	//================================================================================================================
	#define PGIM_ENCODER							PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
	
	
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E R R O R   H A N D L E R
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIM_ERROR == PG_ENABLE )
		#define	PG_ERROR_LED_PRESENT				PG_NO				//!< Must be: PG_YES || PG_NO
		#define	PG_ERROR_LCD_PRESENT				PG_NO				//!< Must be: PG_NO  || PG_HD44780
	#endif

	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   C A L - D E L A Y
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.

	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   F T O A
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIM_FTOA == PG_ENABLE )
		#define	PG_FTOA_PRINT_SIGN_PLUS				PG_NO				//!< Must be: PG_YES || PG_NO
		#define	PG_FTOA_PRINT_SIGN_MINUS			PG_YES				//!< Must be: PG_YES || PG_NO
	#endif
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   G C P
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S S P
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
		
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   G K H 3 2	
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   P R S
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   F O N T
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   3 W I R E
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIM_3WIRE == PG_ENABLE )
		#define PG_3WIRE_DIRECTION_INPUT			PG_LSB_FIRST		//!< Must be: PG_MSB_FIRST || PG_LSB_FIRST
		#define PG_3WIRE_DIRECTION_OUTPUT			PG_LSB_FIRST		//!< Must be: PG_MSB_FIRST || PG_LSB_FIRST
	#endif

	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E V E N T S
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   A D - C O N V E R T E R
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S P I
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E E
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   T I M E R
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   P W M 
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S E R I A L
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
		#define	PG_LCD_HD44780_COLUMNS				16					//!< Number of columns of the display
		#define	PG_LCD_HD44780_LINES				2					//!< Number of lines of the display
		#define	PG_LCD_HD44780_BUSY_FLAG			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_BUSY_DELAY			1					//!< Waiting time for display processing in micro-seconds [us]
		#define	PG_LCD_HD44780_LINE_0_ADDRESS		0x00				//!< Address (default 0x00) for the line number 1. Must be : PG_MISSING if there is not.
		#define	PG_LCD_HD44780_LINE_1_ADDRESS		0X40				//!< Address (default 0x40) for the line number 2. Must be : PG_MISSING if there is not.
		#define	PG_LCD_HD44780_LINE_2_ADDRESS		PG_MISSING			//!< Address (default 0x00) for the line number 3. Must be : PG_MISSING if there is not.
		#define	PG_LCD_HD44780_LINE_3_ADDRESS		PG_MISSING			//!< Address (default 0x40) for the line number 4. Must be : PG_MISSING if there is not.
		#define	PG_LCD_HD44780_BL_0_ENABLE			PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_BL_1_ENABLE			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_BL_2_ENABLE			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_BL_3_ENABLE			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_BL_0_ENABLE_LOGIC	PG_POSITIVE			//!< Must be: PG_POSITIVE || PG_NEGATIVE
		#define	PG_LCD_HD44780_BL_1_ENABLE_LOGIC	PG_POSITIVE			//!< Must be: PG_POSITIVE || PG_NEGATIVE
		#define	PG_LCD_HD44780_BL_2_ENABLE_LOGIC	PG_POSITIVE			//!< Must be: PG_POSITIVE || PG_NEGATIVE
		#define	PG_LCD_HD44780_BL_3_ENABLE_LOGIC	PG_POSITIVE			//!< Must be: PG_POSITIVE || PG_NEGATIVE
		#define	PG_LCD_HD44780_SPLASH_FULL_0_EN		PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_FULL_1_EN		PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_FULL_2_EN		PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_FULL_3_EN		PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_FULL_DELAY	1					//!< Show time of splash in seconds [s] || 0 = do not clear
		#define	PG_LCD_HD44780_SPLASH_SLIDE_0_EN	PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_SLIDE_1_EN	PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_SLIDE_2_EN	PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_SLIDE_3_EN	PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_LCD_HD44780_SPLASH_SLIDE_SPEED	1					//!< Slowdown time of slider in milli-seconds [ms]
	#endif

	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |	L C D  - P C D 8 5 4 4 
	//----------------------------------------------------------------------------------------------------------------
	
		#define	PG_PCD8544_DATA			    		1
		#define	PG_PCD8544_COMMAND			    	0
		
		#define	PG_PCD8544_CONFIGURATION			0x08
		#define	PG_PCD8544_FUNCTION					0x20
		#define	PG_PCD8544_ADDRESS_Y				0x40
		#define	PG_PCD8544_ADDRESS_X				0x80
		#define	PG_PCD8544_EXT_TEMP_CONTROL			0x04
		#define	PG_PCD8544_EXT_BIAS_CONTROL			0x10
		#define	PG_PCD8544_EXT_SET_VOP		    	0x80
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   B U Z Z E R
	//----------------------------------------------------------------------------------------------------------------
	#if ( PGIM_BUZZER == PG_ENABLE )
		#define PG_BEEP_LONG						100					//!< Defines the long duration of the beep
		#define	PG_BEEP_SHORT						40					//!< Defines the short duration of the beep
		#define	PG_BEEP_HIGH						1					//!< Defines the high tone of the beep
		#define	PG_BEEP_MID							3					//!< Defines the mean tone of the beep
		#define	PG_BEEP_LOW							7					//!< Defines the low tone of the beep
	#endif
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S E N S O R
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   R T C _ D S 1 3 0 2
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.

	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//----------------------------------------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E N C O D E R
	//----------------------------------------------------------------------------------------------------------------
	//Nothing to configure here.

#endif 




