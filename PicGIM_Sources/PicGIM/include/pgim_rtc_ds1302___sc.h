/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_rtc_ds1302___sc.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_rtc_da1302.c
							pgim_rtc_da1302.h

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

/*!		\file		pgim_rtc_ds1302___sc.h
		\version	0.6-0
		\date		2002 - 2016
		\brief		Support for DS1302 - Real-Time Clock/Calendar Trickle Charge Timekeeping
		\details	
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/

#ifndef _PGIM_RTC_DS1302___SC_H_
	#define _PGIM_RTC_DS1302___SC_H_

	#if ( PGIM_RTC_DS1302 == PG_ENABLE )
	
		//		F U N C T I O N S   T H A T   C A N   B E   D I S A B L E D   I F   N O T   U S E D ( manual )

		#define	PG_RTC_DS1302_USE_MIN___SC					PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_USE_HOUR___SC					PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_USE_DAY___SC					PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_USE_MONTH___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_USE_YEAR___SC					PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_USE_WEEKDAY___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE

		//		F U N C T I O N S   T H A T   C A N   B E   D I S A B L E D   I F   N O T   U S E D ( semi-automatic )
		#define	PG_RTC_DS1302_WR_TIME_ALL___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_RD_TIME_ALL___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_WR_DATE_ALL___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		#define	PG_RTC_DS1302_RD_DATE_ALL___SC				PG_ENABLE	//!< Must be: PG_ENABLE || PG_DISABLE
		
		//	Functions disabled automatically if not required
		//	---------------------------------------------------------
		//	Nothing to configure here.

		//	Compulsory functions ( must be compiled )
		//	---------------------------------------------------------
		//	pg_rtc_ds1302_init
		//	pg_rtc_ds1302_wr_access
		//	pg_rtc_ds1302_start
		//	pg_rtc_ds1302_stop
		//	pg_rtc_ds1302_wr_time_sec
		//	pg_rtc_ds1302_rd_time_sec
	
	#endif
#endif /* _PGIM_RTC_DS1302___SC_H_ */

