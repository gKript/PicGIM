/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_hardware_setup_public.h
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
		\file		pgim_hardware_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Hardware details configuration public file.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_HARDWARE_SETUP_PUBLIC_H_
	#define	_PGIM_HARDWARE_SETUP_PUBLIC_H_

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   L E D - E R R O R
	//------------------------------------------------------------------------------
	#if ( ( PGIM_ERROR == PG_ENABLE ) && ( PG_ERROR_LED_PRESENT == PG_YES ) )
		#define	PG_ERROR_LED						L_B0
		#define	PG_ERROR_LED_TRIS					T_B0
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
	//------------------------------------------------------------------------------
	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
		#define PG_LCD_HD44780_RS					L_D4
		#define PG_LCD_HD44780_RW_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_RW					L_D5				//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_0_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_EN_0					L_D6				//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_1_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_EN_1					L_B0				//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_2_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_EN_2					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_3_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_EN_3					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_DATA_0				L_D0				//!< Must be: <pin-lat-name>
		#define PG_LCD_HD44780_DATA_1				L_D1				//!< Must be: <pin-lat-name>
		#define PG_LCD_HD44780_DATA_2				L_D2				//!< Must be: <pin-lat-name>
		#define PG_LCD_HD44780_DATA_3				L_D3				//!< Must be: <pin-lat-name>
		#define PG_LCD_HD44780_BL_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
		#define PG_LCD_HD44780_BL					L_D7				//!< Must be: <pin-lat-name> || PG_MISSING if not used.

		#define PG_LCD_HD44780_RS_TRIS				T_D4				//!< Must be: <pin-tris-name>
		#define PG_LCD_HD44780_RW_TRIS				T_D5				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_0_TRIS			T_D6				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_1_TRIS			T_B0				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_2_TRIS			PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_EN_3_TRIS			PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_LCD_HD44780_DATA_0_TRIS			T_D0				//!< Must be: <pin-tris-name>
		#define PG_LCD_HD44780_DATA_1_TRIS			T_D1				//!< Must be: <pin-tris-name>
		#define PG_LCD_HD44780_DATA_2_TRIS			T_D2				//!< Must be: <pin-tris-name>
		#define PG_LCD_HD44780_DATA_3_TRIS			T_D3				//!< Must be: <pin-tris-name>
		#define PG_LCD_HD44780_BL_TRIS				T_D7				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		
		#define PG_LCD_HD44780_DATA_0_PORT			P_D0				//!< Must be: <pin-port-name>
		#define PG_LCD_HD44780_DATA_1_PORT			P_D1				//!< Must be: <pin-port-name>
		#define PG_LCD_HD44780_DATA_2_PORT			P_D2				//!< Must be: <pin-port-name>
		#define PG_LCD_HD44780_DATA_3_PORT			P_D3				//!< Must be: <pin-port-name>
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   B U Z Z E R
	//------------------------------------------------------------------------------
	#if ( PGIM_BUZZER == PG_ENABLE )
		#define	PG_BUZZER_PIN						L_C2
		#define	PG_BUZZER_PIN_TRIS					T_C2
	#endif
	
	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   E N C O D E R
	//------------------------------------------------------------------------------
	#if ( PGIM_ENCODER == PG_ENABLE )
		#define	PG_ENCODER_STEP						P_B0
		#define	PG_ENCODER_DIR						P_B5
		#define	PG_ENCODER_SW						P_B6

		#define	PG_ENCODER_STEP_TRIS				T_B0
		#define	PG_ENCODER_DIR_TRIS					T_B5
		#define	PG_ENCODER_SW_TRIS					T_B6
	#endif

	//------------------------------------------------------------------------------
	//		H A R D W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
	//------------------------------------------------------------------------------
	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		#define	PG_EXTERNAL_MEMORY_CS				L_C3
		#define	PG_EXTERNAL_MEMORY_CS_TRIS			T_C3
	#endif

#endif /* _PGIM_HARDWARE_SETUP_PUBLIC_H_ */


