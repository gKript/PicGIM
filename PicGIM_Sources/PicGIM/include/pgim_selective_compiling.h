/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_selective_compiling.h
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

/*!		\file		pgim_selective_compiling.h
		\version	0.6-0
		\date		2002 - 2016
		\brief		
		\details	
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/

#ifndef _PGIM_SELECTIVE_COMPILING_H_
	#define _PGIM_SELECTIVE_COMPILING_H_

	#if defined( PG_DOXYGEN )
		//==============================================================================
		//		LCD_HD44780  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_LCD_HD44780 == PG_ENABLE )
			#undef	PG_LCD_HD44780_CHAR_GENERATOR
			#define	PG_LCD_HD44780_CHAR_GENERATOR					PG_INCLUDE
			#undef	PG_LCD_HD44780_PUT_P_CHAR
			#define	PG_LCD_HD44780_PUT_P_CHAR						PG_INCLUDE
			#undef	PG_LCD_HD44780_PUT_BYTE
			#define	PG_LCD_HD44780_PUT_BYTE							PG_INCLUDE
			#undef	PG_LCD_HD44780_PUT_P_BYTE
			#define	PG_LCD_HD44780_PUT_P_BYTE						PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_STRING_ROM
			#define	PG_LCD_HD44780_WRITE_STRING_ROM					PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING
			#define	PG_LCD_HD44780_WRITE_P_STRING					PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_FLASH
			#define	PG_LCD_HD44780_WRITE_P_STRING_FLASH				PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_ROM
			#define	PG_LCD_HD44780_WRITE_P_STRING_ROM				PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_FLASH_ROM
			#define	PG_LCD_HD44780_WRITE_P_STRING_FLASH_ROM			PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_INT
			#define	PG_LCD_HD44780_WRITE_P_INT						PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_CHAR
			#define	PG_LCD_HD44780_WRITE_P_CHAR						PG_INCLUDE
			#undef	PG_LCD_HD44780_WRITE
			#define	PG_LCD_HD44780_WRITE							PG_INCLUDE
		#endif
		//==============================================================================
		//		RTC_DS1302  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_RTC_DS1302 == PG_ENABLE )
			#undef	PG_RTC_DS1302_USE_MIN
			#define	PG_RTC_DS1302_USE_MIN							PG_INCLUDE
			#undef	PG_RTC_DS1302_USE_HOUR
			#define	PG_RTC_DS1302_USE_HOUR							PG_INCLUDE
			#undef	PG_RTC_DS1302_USE_DAY
			#define	PG_RTC_DS1302_USE_DAY							PG_INCLUDE
			#undef	PG_RTC_DS1302_USE_MONTH
			#define	PG_RTC_DS1302_USE_MONTH							PG_INCLUDE
			#undef	PG_RTC_DS1302_USE_YEAR
			#define	PG_RTC_DS1302_USE_YEAR							PG_INCLUDE
			#undef	PG_RTC_DS1302_USE_WEEKDAY
			#define	PG_RTC_DS1302_USE_WEEKDAY						PG_INCLUDE
			#undef	PG_RTC_DS1302_WR_TIME_ALL
			#define	PG_RTC_DS1302_WR_TIME_ALL						PG_INCLUDE
			#undef	PG_RTC_DS1302_RD_TIME_ALL
			#define	PG_RTC_DS1302_RD_TIME_ALL						PG_INCLUDE
			#undef	PG_RTC_DS1302_WR_DATE_ALL
			#define	PG_RTC_DS1302_WR_DATE_ALL						PG_INCLUDE
			#undef	PG_RTC_DS1302_RD_DATE_ALL
			#define	PG_RTC_DS1302_RD_DATE_ALL						PG_INCLUDE
		#endif
		//==============================================================================
		//		AD_CONVERTER  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_AD_CONVERTER == PG_ENABLE )
			#undef	PG_ADC_GET_USER_SCALE
			#define	PG_ADC_GET_USER_SCALE							PG_INCLUDE
			#undef	PG_ADC_START_AVG
			#define	PG_ADC_START_AVG								PG_INCLUDE
			#undef	PG_ADC_GET_PERC
			#define	PG_ADC_GET_PERC									PG_INCLUDE
			#undef	PG_ADC_GET_PERC_F
			#define	PG_ADC_GET_PERC_F								PG_INCLUDE
		#endif
		//==============================================================================
		//		CALDELAY  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_CAL_DELAY == PG_ENABLE )
			#undef	PG_DELAY_SEC
			#define	PG_DELAY_SEC									PG_INCLUDE
			#undef	PG_DELAY_MSEC
			#define	PG_DELAY_MSEC									PG_INCLUDE
			#undef	PG_DELAY_USEC
			#define	PG_DELAY_USEC									PG_INCLUDE
			#undef	PG_DELAY
			#define	PG_DELAY										PG_INCLUDE
			#undef	PG_DELAY_HIGH_PRIORITY
			#define	PG_DELAY_HIGH_PRIORITY							PG_INCLUDE
		#endif
		//==============================================================================
		//		EE  -  S e l e c t i v e   c o m p i l i n g
		//==============================================================================
		#if ( PGIM_EE == PG_ENABLE )
			#undef	PG_EE_WRITE										
			#define	PG_EE_WRITE										PG_INCLUDE
			#undef	PG_EE_READ										
			#define	PG_EE_READ										PG_INCLUDE
			#undef	PG_EE_WRITE_BUFFER								
			#define	PG_EE_WRITE_BUFFER								PG_INCLUDE
			#undef	PG_EE_READ_BUFFER								
			#define	PG_EE_READ_BUFFER								PG_INCLUDE
		#endif
		
	#elif ( ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG ) )
		//==============================================================================
		//		LCD_HD44780  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_LCD_HD44780 == PG_ENABLE )
			#undef	PG_LCD_HD44780_CHAR_GENERATOR
			#define	PG_LCD_HD44780_CHAR_GENERATOR					PG_EXCLUDE
			#undef	PG_LCD_HD44780_PUT_P_CHAR
			#define	PG_LCD_HD44780_PUT_P_CHAR						PG_EXCLUDE
			#undef	PG_LCD_HD44780_PUT_BYTE
			#define	PG_LCD_HD44780_PUT_BYTE							PG_EXCLUDE
			#undef	PG_LCD_HD44780_PUT_P_BYTE
			#define	PG_LCD_HD44780_PUT_P_BYTE						PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_STRING_ROM
			#define	PG_LCD_HD44780_WRITE_STRING_ROM					PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING
			#define	PG_LCD_HD44780_WRITE_P_STRING					PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_FLASH
			#define	PG_LCD_HD44780_WRITE_P_STRING_FLASH				PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_ROM
			#define	PG_LCD_HD44780_WRITE_P_STRING_ROM				PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_STRING_FLASH_ROM
			#define	PG_LCD_HD44780_WRITE_P_STRING_FLASH_ROM			PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_INT
			#define	PG_LCD_HD44780_WRITE_P_INT						PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE_P_CHAR
			#define	PG_LCD_HD44780_WRITE_P_CHAR						PG_EXCLUDE
			#undef	PG_LCD_HD44780_WRITE
			#define	PG_LCD_HD44780_WRITE							PG_EXCLUDE
		#endif
		//==============================================================================
		//		RTC_DS1302  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_RTC_DS1302 == PG_ENABLE )
			#undef	PG_RTC_DS1302_USE_MIN
			#define	PG_RTC_DS1302_USE_MIN							PG_EXCLUDE
			#undef	PG_RTC_DS1302_USE_HOUR
			#define	PG_RTC_DS1302_USE_HOUR							PG_EXCLUDE
			#undef	PG_RTC_DS1302_USE_DAY
			#define	PG_RTC_DS1302_USE_DAY							PG_EXCLUDE
			#undef	PG_RTC_DS1302_USE_MONTH
			#define	PG_RTC_DS1302_USE_MONTH							PG_EXCLUDE
			#undef	PG_RTC_DS1302_USE_YEAR
			#define	PG_RTC_DS1302_USE_YEAR							PG_EXCLUDE
			#undef	PG_RTC_DS1302_USE_WEEKDAY
			#define	PG_RTC_DS1302_USE_WEEKDAY						PG_EXCLUDE
			#undef	PG_RTC_DS1302_WR_TIME_ALL
			#define	PG_RTC_DS1302_WR_TIME_ALL						PG_EXCLUDE
			#undef	PG_RTC_DS1302_RD_TIME_ALL
			#define	PG_RTC_DS1302_RD_TIME_ALL						PG_EXCLUDE
			#undef	PG_RTC_DS1302_WR_DATE_ALL
			#define	PG_RTC_DS1302_WR_DATE_ALL						PG_EXCLUDE
			#undef	PG_RTC_DS1302_RD_DATE_ALL
			#define	PG_RTC_DS1302_RD_DATE_ALL						PG_EXCLUDE
		#endif
		//==============================================================================
		//		AD_CONVERTER  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_AD_CONVERTER == PG_ENABLE )
			#undef	PG_ADC_GET_USER_SCALE
			#define	PG_ADC_GET_USER_SCALE							PG_EXCLUDE
			#undef	PG_ADC_START_AVG
			#define	PG_ADC_START_AVG								PG_EXCLUDE
			#undef	PG_ADC_GET_PERC
			#define	PG_ADC_GET_PERC									PG_EXCLUDE
			#undef	PG_ADC_GET_PERC_F
			#define	PG_ADC_GET_PERC_F								PG_EXCLUDE
		#endif
		//==============================================================================
		//		CALDELAY  -  R e d e f i n i t i o n s
		//==============================================================================
		#if ( PGIM_CAL_DELAY == PG_ENABLE )
			#undef	PG_DELAY_SEC
			#define	PG_DELAY_SEC									PG_EXCLUDE
			#undef	PG_DELAY_MSEC
			#define	PG_DELAY_MSEC									PG_EXCLUDE
			#undef	PG_DELAY_USEC
			#define	PG_DELAY_USEC									PG_EXCLUDE
			#undef	PG_DELAY
			#define	PG_DELAY										PG_EXCLUDE
			#undef	PG_DELAY_HIGH_PRIORITY
			#define	PG_DELAY_HIGH_PRIORITY							PG_EXCLUDE
		#endif
		//==============================================================================
		//		EE  -  S e l e c t i v e   c o m p i l i n g
		//==============================================================================
		#if ( PGIM_EE == PG_ENABLE )
			#undef	PG_EE_WRITE										
			#define	PG_EE_WRITE										PG_EXCLUDE
			#undef	PG_EE_READ										
			#define	PG_EE_READ										PG_EXCLUDE
			#undef	PG_EE_WRITE_BUFFER								
			#define	PG_EE_WRITE_BUFFER								PG_EXCLUDE
			#undef	PG_EE_READ_BUFFER								
			#define	PG_EE_READ_BUFFER								PG_EXCLUDE
		#endif
	#endif
#endif /* _PGIM_SELECTIVE_COMPILING_H_ */


