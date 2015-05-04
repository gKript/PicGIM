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

	//		S O F T W A R E   G E N E R A L
	#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_CAL_DELAY						PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	
	//		H A R D W A R E   I N T E R N A L
	#define PGIM_EVENTS							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_AD_CONVERTER					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_TIMER							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_PWM							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SERIAL							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	//		H A R D W A R E   E X T E R N A L
	#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	//		H A R D W A R E   G K R I P T
	#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	
	
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E R R O R   H A N D L E R
	//------------------------------------------------------------------------------
	#if ( PGIM_ERROR == PG_ENABLE )
		#define	PG_ERROR_LED_PRESENT			PG_NO					//!< Must be: PG_YES || PG_NO
		#define	PG_ERROR_LCD_PRESENT			PG_NO					//!< Must be: PG_NO  || PG_HD44780
	#endif

	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   C A L - D E L A Y
	//------------------------------------------------------------------------------
	//Nothing to configure here.

	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   F T O A
	//------------------------------------------------------------------------------
	#if ( PGIM_FTOA == PG_ENABLE )
		#define PG_FTOA_CONVERSION_ACCURATE 	PG_YES					//!< Must be: PG_YES || PG_NO
	#endif
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E V E N T S
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   A D - C O N V E R T E R
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S P I
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E E
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   T I M E R
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   P W M 
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S E R I A L
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//------------------------------------------------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
		#define	PG_LCD_HD44780_COLUMNS			16						//!< Number of columns of the display
		#define	PG_LCD_HD44780_LINES			2						//!< Number of lines of the display
		#define PG_LCD_HD44780_BUSY_FLAG		PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_LINE_0_ADDRESS	0x00					//!< Address (default 0x00) for the line number 1. Must be : PG_MISSING if there is not.
		#define PG_LCD_HD44780_LINE_1_ADDRESS	0X40					//!< Address (default 0x40) for the line number 2. Must be : PG_MISSING if there is not.
		#define PG_LCD_HD44780_LINE_2_ADDRESS	PG_MISSING				//!< Address (default 0x00) for the line number 3. Must be : PG_MISSING if there is not.
		#define PG_LCD_HD44780_LINE_3_ADDRESS	PG_MISSING				//!< Address (default 0x40) for the line number 4. Must be : PG_MISSING if there is not.
		#define PG_LCD_HD44780_SPLASH_ENABLE	PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_SPLASH_TIME		1						//!< Show time of splash in seconds [s] || 0 = do not clear
	#endif

	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   B U Z Z E R
	//------------------------------------------------------------------------------
	#if ( PGIM_BUZZER == PG_ENABLE )
		#define PG_BEEP_LONG					100						/*!	Defines the long duration of the beep	*/
		#define	PG_BEEP_SHORT					40						/*!	Defines the short duration of the beep	*/
		#define	PG_BEEP_HIGH					1						/*!	Defines the high tone of the beep		*/
		#define	PG_BEEP_MID						3						/*!	Defines the mean tone of the beep		*/
		#define	PG_BEEP_LOW						7						/*!	Defines the low tone of the beep		*/
	#endif
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   S E N S O R
	//------------------------------------------------------------------------------
	//Nothing to configure here.
	
	//------------------------------------------------------------------------------
	//		S O F T W A R E   C O N F I G   |   E N C O D E R
	//------------------------------------------------------------------------------
	//Nothing to configure here.

#endif 




