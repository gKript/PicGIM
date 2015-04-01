//
// pgim_module_setup_public.h
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

/*!		\file		pgim_module_setup_public.h
		\version	0.5-0
		\date		2002 - 2014
		\brief		Allows to enable or disable individual modules.
		\details	
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	Released under the terms of the GNU General Public License v2<BR>
				[ http://gkript.org/gk_gpl_v2.php ]
		\todo           In the next milestone \b PicGIM will support many other hardware module. Please check frequently our site www.gkript.org for news about PicGIM.
*/

#ifndef _PGIM_MODULE_SETUP_PUBLIC_H_
	#define	_PGIM_MODULE_SETUP_PUBLIC_H_

	//		S O F T W A R E   G E N E R A L
	#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_CAL_DELAY						PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	
	//		H A R D W A R E   I N T E R N A L
	#define PGIM_EVENTS							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_AD_CONVERTER					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_TIMER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_PWM							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_SERIAL							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	//		H A R D W A R E   E X T E R N A L
	#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
	#define PGIM_BUZZER							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
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
	/*	#if ( PGIM_ENCODER == PG_ENABLE )
			#define	PG_ENCODER_
			#define	PG_ENCODER_
		#endif
	*/
#endif 



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//	New in the next Milestone
//
//	#define	PGIM_FONTS							PG_ENABLE				// PG_ENABLE   PG_DISABLE	#define PGIM_LCD_PCD8544					PG_ENABLE				// PG_ENABLE   PG_DISABLE
//	#define PGIM_LCD_9340						PG_ENABLE				// PG_ENABLE   PG_DISABLE
//
//	//------------------------------------------------------------------------------
//	//		S O F T W A R E   C O N F I G   |   L C D - P C D 8 5 4 4
//	//------------------------------------------------------------------------------
//	//Please, configure in "pgim_hardware_setup_public.h" file too.
//	#if ( PGIM_LCD_PCD8544 == PG_ENABLE )
//		#define PG_LCD_PCD8544_SPI_PORT			PG_SPI_0				//!<	Must be : PG_SPI_0 || PG_SPI_1 || PG_SPI_2
//		#define PG_LCD_PCD8544_SPI_SYNC_MODE	PG_SPI_MASTER_FOSC_64	//!<	Must be : PG_SPI_MASTER_FOSC_4 || PG_SPI_MASTER_FOSC_16 || PG_SPI_MASTER_FOSC_64 || PG_SPI_MASTER_FOSC_TMR2
//		#define PG_LCD_PCD8544_SPI_BUS_MODE		MODE_00					//!<	Must be : MODE_00 || MODE_01 || MODE_10 || MODE_11
//		#define PG_LCD_PCD8544_SPI_SMP_PHASE	SMPEND            		//!<	Must be : SMPEND || SMPEND
//	#endif
//
//	//------------------------------------------------------------------------------
//	//		S O F T W A R E   C O N F I G   |   L C D - 9 3 4 0
//	//------------------------------------------------------------------------------
//	//Please, configure in "pgim_hardware_setup_public.h" file too.
//	#if ( PGIM_LCD_9340 == PG_ENABLE )
//		//#define PG_LCD_9340_
//		//#define PG_LCD_9340_
//	#endif
//	
//	//------------------------------------------------------------------------------
//	//		S O F T W A R E   C O N F I G   |   E X T E R N A L   M E M O R Y
//	//------------------------------------------------------------------------------
//	//Please, configure in "pgim_hardware_setup_public.h" file too.
//	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
//			#define	PG_EXTERNAL_MEMORY_
//			#define	PG_EXTERNAL_MEMORY_
//	#endif



