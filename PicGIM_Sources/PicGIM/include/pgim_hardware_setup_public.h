//
// pgim_hardware_setup_public.h
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

/*!		\file			pgim_hardware_setup_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_HARDWARE_SETUP_PUBLIC_H_
	#define	_PGIM_HARDWARE_SETUP_PUBLIC_H_

////////////////////////////////////////////////////////////////////////////////
//
//		H A R D W A R E   C O N F I G   |   L E D - E R R O R
//
////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_ERROR == PG_ENABLE ) && ( PGIM_ERROR_LED_PRESENT == PG_YES )
		#define	PG_ERROR_LED						L_B3
		#define	PG_ERROR_LED_TRIS					T_B3
	#endif

////////////////////////////////////////////////////////////////////////////////
//
//		H A R D W A R E   C O N F I G   |   L C D - H D 4 4 7 8 0
//
////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
		#define PG_LCD_HD44780_RW					L_D5
		#define PG_LCD_HD44780_RS					L_D4
		#define PG_LCD_HD44780_EN_0_PRESENT			PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_EN_0					L_D6
		#define PG_LCD_HD44780_EN_1_PRESENT			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_EN_1				
		#define PG_LCD_HD44780_EN_2_PRESENT			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_EN_2				
		#define PG_LCD_HD44780_EN_3_PRESENT			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_EN_3				
		#define PG_LCD_HD44780_DATA_0				L_D0
		#define PG_LCD_HD44780_DATA_1				L_D1
		#define PG_LCD_HD44780_DATA_2				L_D2
		#define PG_LCD_HD44780_DATA_3				L_D3
		#define PG_LCD_HD44780_BL_PRESENT			PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_LCD_HD44780_BL					L_D7

		#define PG_LCD_HD44780_RW_TRIS				T_D5
		#define PG_LCD_HD44780_RS_TRIS				T_D4
		#define PG_LCD_HD44780_EN_0_TRIS			T_D6
		#define PG_LCD_HD44780_EN_1_TRIS			
		#define PG_LCD_HD44780_EN_2_TRIS			
		#define PG_LCD_HD44780_EN_3_TRIS			
		#define PG_LCD_HD44780_DATA_0_TRIS			T_D0
		#define PG_LCD_HD44780_DATA_1_TRIS			T_D1
		#define PG_LCD_HD44780_DATA_2_TRIS			T_D2
		#define PG_LCD_HD44780_DATA_3_TRIS			T_D3
		#define PG_LCD_HD44780_BL_TRIS				T_D7
		
		#define PG_LCD_HD44780_DATA_0_PORT			P_D0
		#define PG_LCD_HD44780_DATA_1_PORT			P_D1
		#define PG_LCD_HD44780_DATA_2_PORT			P_D2
		#define PG_LCD_HD44780_DATA_3_PORT			P_D3
	#endif

	
//	////////////////////////////////////////////////////////////////////////////////
//	//
//	//		H A R D W A R E   C O N F I G   |   L C D - P C D 8 5 4 4
//	//
//	////////////////////////////////////////////////////////////////////////////////
//
//	#if ( PGIM_LCD_PCD8544 == PG_ENABLE )
//		#define	PG_LCD_PCD8544_VIDEO_MEMORY			PG_NO			// PG_YES	PG_NO
//
//		#define PG_LCD_PCD8544_PWR					L_C0
//		#define PG_LCD_PCD8544_RST					L_B1			// !Reset
//		#define PG_LCD_PCD8544_CE 					L_B2			// !ChipEnable
//		#define PG_LCD_PCD8544_DC					L_B3			// Data / Command ( 1 = Data; 0 = Command )
//		#define	PG_LCD_PCD8544_BACKLIGHT			L_C1
//
//		#define PG_LCD_PCD8544_PWR_TRIS				T_C0
//		#define PG_LCD_PCD8544_RST_TRIS				T_B1
//		#define PG_LCD_PCD8544_CE_TRIS				T_B2
//		#define PG_LCD_PCD8544_DC_TRIS				T_B3
//		#define	PG_LCD_PCD8544_BACKLIGHT_TRIS		T_C1
//	#endif
//
//
//	////////////////////////////////////////////////////////////////////////////////
//	//
//	//		H A R D W A R E   C O N F I G   |   L C D - 9 3 4 0
//	//
//	////////////////////////////////////////////////////////////////////////////////
//
//	#if ( PGIM_LCD_9340 == PG_ENABLE )
//		#define	PG_LCD_9340_VIDEO_MEMORY			PG_DISABLE		// PG_ENABLE	PG_DISABLE
//
//		#define PG_LCD_9340_PWR						L_C4
//		#define PG_LCD_9340_CS						L_C2			// !ChipSelect
//		#define PG_LCD_9340_RST						L_C1			// !Reset
//		#define PG_LCD_9340_RS						L_C0			// RegisterSelect ( 1 = Data; 0 = Command )
//		#define	PG_LCD_9340_BACKLIGHT				L_B2
//
//		#define PG_LCD_9340_PWR_TRIS				T_C4
//		#define PG_LCD_9340_CS_TRIS					T_C2
//		#define PG_LCD_9340_RST_TRIS				T_C1
//		#define PG_LCD_9340_RS_TRIS					T_C0
//		#define	PG_LCD_9340_BACKLIGHT_TRIS			T_B2
//	#endif
//

	////////////////////////////////////////////////////////////////////////////////
	//
	//		H A R D W A R E   C O N F I G   |   B U Z Z E R
	//
	////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_BUZZER == PG_ENABLE )
		#define	PG_BUZZER_PIN						L_C2
		#define	PG_BUZZER_PIN_TRIS					T_C2
	#endif
	

	////////////////////////////////////////////////////////////////////////////////
	//
	//		H A R D W A R E   C O N F I G   |   E N C O D E R
	//
	////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_ENCODER == PG_ENABLE )

		#define	PG_ENCODER_STEP						L_B5
		#define	PG_ENCODER_DIR						L_B4
		#define	PG_ENCODER_SW						L_B6

		#define	PG_ENCODER_STEP_TRIS				T_B5
		#define	PG_ENCODER_DIR_TRIS					T_B4
		#define	PG_ENCODER_SW_TRIS					T_B6

	#endif


	////////////////////////////////////////////////////////////////////////////////
	//
	//		H A R D W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
	//
	////////////////////////////////////////////////////////////////////////////////

	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		#define	PG_EXTERNAL_MEMORY_CS				L_C3
		#define	PG_EXTERNAL_MEMORY_CS_TRIS			T_C3
	#endif


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif /* _PGIM_HARDWARE_SETUP_PUBLIC_H_ */


