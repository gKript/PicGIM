//
// pgim_rtc_ds1302.h
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

/*!		\file			pgim_rtc_ds1302.h
		\version		0.6-0
		\date			2002 - 2016
		\brief			Support for DS1302 - Real-Time Clock/Calendar Trickle Charge Timekeeping
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

//Doc. Ref.: DALLAS Semiconductor, DS1302 Trickle-Charge Timekeeping Chip

#ifndef _PGIM_RTC_DS1302_H_
	#define _PGIM_RTC_DS1302_H_
	
	#if	( PGIM_RTC_DS1302 == PG_ENABLE )
	
	//---[ Defines ]---
	#define	PG_RTC_DS1302_CS_DELAY	pg_delay( 10, PG_USEC );
	
	#define	PG_RTC_DS1302_CMD_WR_SEC			0x80		//!< Command to set second
	#define	PG_RTC_DS1302_CMD_WR_MIN			0x82		//!< Command to set minute
	#define	PG_RTC_DS1302_CMD_WR_HOUR			0x84		//!< Command to set hour
	#define	PG_RTC_DS1302_CMD_WR_DAY			0x86		//!< Command to set day
	#define	PG_RTC_DS1302_CMD_WR_MONTH			0x88		//!< Command to set month
	#define	PG_RTC_DS1302_CMD_WR_WEEKDAY		0x8A		//!< Command to set week day number
	#define	PG_RTC_DS1302_CMD_WR_YEAR			0x8C		//!< Command to set year
	#define	PG_RTC_DS1302_CMD_WR_WRPROTECT		0x8E		//!< Command to set or remove device write protection
	#define	PG_RTC_DS1302_CMD_WR_CHARGE			0x90		//!< Command to set trickle-charge configuration
	
	#define	PG_RTC_DS1302_CMD_RD_SEC			0x81		//!< Command to get second
	#define	PG_RTC_DS1302_CMD_RD_MIN			0x83		//!< Command to get minute
	#define	PG_RTC_DS1302_CMD_RD_HOUR			0x85		//!< Command to get hour
	#define	PG_RTC_DS1302_CMD_RD_DAY			0x87		//!< Command to get day
	#define	PG_RTC_DS1302_CMD_RD_MONTH			0x89		//!< Command to get month
	#define	PG_RTC_DS1302_CMD_RD_WEEKDAY		0x8B		//!< Command to get week day number
	#define	PG_RTC_DS1302_CMD_RD_YEAR			0x8D		//!< Command to get year
	#define	PG_RTC_DS1302_CMD_RD_WRPROTECT		0x8F		//!< Command to get device write protection status
	#define	PG_RTC_DS1302_CMD_RD_CHARGE			0x91		//!< Command to get trickle-charge configuration
	
	enum	_pg_rtc_ds1302_weekday_ita_enum {
				PG_RTC_DS1302_WEEKDAY_LUN = 1,
				PG_RTC_DS1302_WEEKDAY_MAR,
				PG_RTC_DS1302_WEEKDAY_MER,
				PG_RTC_DS1302_WEEKDAY_GIO,
				PG_RTC_DS1302_WEEKDAY_VEN,
				PG_RTC_DS1302_WEEKDAY_SAB,
				PG_RTC_DS1302_WEEKDAY_DOM
	};

	enum	_pg_rtc_ds1302_weekday_eng_enum {
				PG_RTC_DS1302_WEEKDAY_MON = 1,
				PG_RTC_DS1302_WEEKDAY_TUE,
				PG_RTC_DS1302_WEEKDAY_WED,
				PG_RTC_DS1302_WEEKDAY_THU,
				PG_RTC_DS1302_WEEKDAY_FRI,
				PG_RTC_DS1302_WEEKDAY_SAT,
				PG_RTC_DS1302_WEEKDAY_SUN
	};
	//---[ End Defines ]---
	
	//---[ Prototypes ]---	
	extern	_pg_Uint8 	ds1302_sec;					//!<	0-59			( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_min;					//!<	0-59			( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_hour;				//!<	1-12/0-23		( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_day;					//!<	1-31			( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_month;				//!<	1-12			( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_weekday;				//!<	1-7				( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_year;				//!<	00-99			( Decimal value accepted range )
	extern	_pg_Uint8 	ds1302_halt_clock;			//!<	Halt clock flag ( 1 = stopped; 0 = running )
	
	void		pg_rtc_ds1302_init					( void );
	
	void		pg_rtc_ds1302_wr_enable				( void );
	void		pg_rtc_ds1302_wr_disable			( void );
	
	void		pg_rtc_ds1302_wr_time				( _pg_Uint8 ds1302_set_hour, _pg_Uint8 ds1302_set_min, _pg_Uint8 ds1302_set_sec );			
	void		pg_rtc_ds1302_wr_date				( _pg_Uint8 ds1302_set_day, _pg_Uint8 ds1302_set_month, _pg_Uint8 ds1302_set_year );
	void		pg_rtc_ds1302_wr_weekday			( _pg_Uint8 ds1302_set_weekday );
	
	void		pg_rtc_ds1302_rd_time				( void );
	void		pg_rtc_ds1302_rd_date				( void );
	void		pg_rtc_ds1302_rd_weekday			( void );
	
	void		pg_rtc_ds1302_start_clock			( void );
	void		pg_rtc_ds1302_stop_clock			( void );
	//---[ End Prototypes ]---	
	
	#endif
	
#endif	/* _PGIM_RTC_DS1302_H_ */


