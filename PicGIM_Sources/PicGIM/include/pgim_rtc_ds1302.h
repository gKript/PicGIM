/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_rtc_da1302.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_rtc_da1302.c
							pgim_rtc_da1302___sc.h
							
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

/*!		\file		pgim_rtc_ds1302.h
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

//Doc. Ref.: DALLAS Semiconductor, DS1302 Trickle-Charge Timekeeping Chip

#ifndef _PGIM_RTC_DS1302_H_
	#define _PGIM_RTC_DS1302_H_
	
	#if	( PGIM_RTC_DS1302 == PG_ENABLE )
		
		//---[ Delays ]---
		#define	PG_RTC_DS1302_CS_DELAY	pg_delay( 10, PG_USEC );
		//---[ END Delays ]---
		
		//---[ Write Command Addresses ]---
		#define	PG_RTC_DS1302_CMD_WR_SEC				0x80		//!< Command to set second
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_MIN			0x82		//!< Command to set minute
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_HOUR			0x84		//!< Command to set hour
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_DAY			0x86		//!< Command to set day
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_MONTH			0x88		//!< Command to set month
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_WEEKDAY		0x8A		//!< Command to set week day number
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_WR_YEAR			0x8C		//!< Command to set year
		#endif
		#define	PG_RTC_DS1302_CMD_WR_WRPROTECT			0x8E		//!< Command to set or remove device write protection
//		#define	PG_RTC_DS1302_CMD_WR_CHARGE				0x90		//!< Command to set trickle-charge configuration (Not yet implemented)
		//---[ END Write Command Addresses ]---
		
		//---[ Read Command Addresses ]---
		#define	PG_RTC_DS1302_CMD_RD_SEC				0x81		//!< Command to get second
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_MIN			0x83		//!< Command to get minute
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_HOUR			0x85		//!< Command to get hour
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_DAY			0x87		//!< Command to get day
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_MONTH			0x89		//!< Command to get month
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_WEEKDAY		0x8B		//!< Command to get week day number
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_CMD_RD_YEAR			0x8D		//!< Command to get year
		#endif
		#define	PG_RTC_DS1302_CMD_RD_WRPROTECT			0x8F		//!< Command to get device write protection status
//		#define	PG_RTC_DS1302_CMD_RD_CHARGE				0x91		//!< Command to get trickle-charge configuration (Not yet implemented)
		//---[ END Read Command Addresses ]---
		
		//---[ Error ]---
		#define	PG_RTC_DS1302_ERROR_VALUE_SEC			201			//!< Wrong seconds value
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_MIN		202			//!< Wrong seconds value
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_HOUR		203			//!< Wrong seconds value
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_DAY		204			//!< Wrong seconds value
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_MONTH		205			//!< Wrong seconds value
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_YEAR		206			//!< Wrong seconds value
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			#define	PG_RTC_DS1302_ERROR_VALUE_WEEKDAY	207			//!< Wrong seconds value
		#endif
		//---[ END Error ]---
		
		//---[ Days of the week ]---
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
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
		#endif
		//---[ END Days of the week ]---
		
		extern	_pg_Uint8 	ds1302_sec;						//!<	0-59	( Decimal value accepted range )
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_min;					//!<	0-59	( Decimal value accepted range )
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_hour;				//!<	0-23	( Decimal value accepted range )
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_day;					//!<	1-31	( Decimal value accepted range )
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_month;				//!<	1-12	( Decimal value accepted range )
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_weekday;				//!<	1-7		( Decimal value accepted range )
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			extern	_pg_Uint8 	ds1302_year;				//!<	00-99	( Decimal value accepted range )
		#endif
		extern	_pg_Uint8 	ds1302_halt_clock;				//!<	Return or set clock flag status ( 1 = stopped; 0 = running )
		
		void		pg_rtc_ds1302_init( void );
		void		pg_rtc_ds1302_wr_access( _pg_Uint8 ds1302_wr_access );
		void		pg_rtc_ds1302_start( void );
		void		pg_rtc_ds1302_stop( void );
		
		_pg_Uint8	pg_rtc_ds1302_wr_time_sec( _pg_Uint8 ds1302_set_sec );
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_time_min( _pg_Uint8 ds1302_set_min );
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_time_hour( _pg_Uint8 ds1302_set_hour );	
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_date_day( _pg_Uint8 ds1302_set_day );
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_date_month( _pg_Uint8 ds1302_set_month );
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_date_year( _pg_Uint8 ds1302_set_year );
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			_pg_Uint8	pg_rtc_ds1302_wr_weekday( _pg_Uint8 ds1302_set_weekday );
		#endif
		
		#if( PG_RTC_DS1302_WR_TIME_ALL___SC == PG_ENABLE )
			#if( ( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE ) )
				void	pg_rtc_ds1302_wr_time_all( _pg_Uint8 ds1302_set_hour_all, _pg_Uint8 ds1302_set_min_all, _pg_Uint8 ds1302_set_sec_all );
			#endif
		#endif		
		#if( PG_RTC_DS1302_WR_DATE_ALL___SC == PG_ENABLE )
			#if( ( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_MONTH___SC  == PG_ENABLE ) && ( PG_RTC_DS1302_USE_YEAR___SC  == PG_ENABLE ) )
				void	pg_rtc_ds1302_wr_date_all( _pg_Uint8 ds1302_set_day_all, _pg_Uint8 ds1302_set_month_all, _pg_Uint8 ds1302_set_year_all );
			#endif
		#endif
		
		void	pg_rtc_ds1302_rd_time_sec( void );
		#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_time_min( void );
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_time_hour( void );
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_date_day( void );
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_date_month( void );
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_date_year( void );
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
			void	pg_rtc_ds1302_rd_weekday( void );
		#endif
		
		#if( PG_RTC_DS1302_RD_TIME_ALL___SC == PG_ENABLE )
			#if( ( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE ) )		
				void	pg_rtc_ds1302_rd_time_all( void );
			#endif
		#endif
		#if( PG_RTC_DS1302_RD_DATE_ALL___SC == PG_ENABLE )
			#if( ( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE ) )
				void	pg_rtc_ds1302_rd_date_all( void );
			#endif
		#endif
		
	#endif
#endif	/* _PGIM_RTC_DS1302_H_ */


