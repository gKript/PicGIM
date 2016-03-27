/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_rtc_da1302.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_rtc_da1302.h
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

/*!		\file		pgim_rtc_ds1302.c
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

#include "picgim.h"

#if ( PGIM_RTC_DS1302 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif
	
	//Doc. Ref.: DALLAS Semiconductor (R), DS1302 Trickle-Charge Timekeeping Chip
	
	_pg_Uint8 ds1302_sec;				//	0-59
	#if( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE )
		_pg_Uint8 ds1302_min;			//	0-59
	#endif
	#if( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE )
		_pg_Uint8 ds1302_hour;			//	0-23
	#endif
	#if( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE )
		_pg_Uint8 ds1302_day;			//	1-31
	#endif
	#if( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE )
		_pg_Uint8 ds1302_month;			//	1-12
	#endif
	#if( PG_RTC_DS1302_USE_WEEKDAY___SC == PG_ENABLE )
		_pg_Uint8 ds1302_weekday;		//	1-7
	#endif
	#if( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE )
		_pg_Uint8 ds1302_year;			//	00-99
	#endif
	_pg_Uint8 ds1302_halt_clock;		//	( 1 = stopped; 0 = running )
	
	
	void	pg_rtc_ds1302_init( void ) {
		PG_RTC_DS1302_CS 		= PG_DISABLE;
		PG_RTC_DS1302_CS_TRIS 	= PG_OUT;

			ds1302_sec			= 0x00;	//Required for start and stop function too
		#if( PG_RTC_DS1302_USE_MIN___SC )
			ds1302_min			= 0x00;
		#endif
		#if( PG_RTC_DS1302_USE_HOUR___SC )
			ds1302_hour			= 0x00;
		#endif
		#if( PG_RTC_DS1302_USE_DAY___SC )
			ds1302_day			= 0x00;
		#endif
		#if( PG_RTC_DS1302_USE_MONTH___SC )
			ds1302_month		= 0x00;
		#endif
		#if( PG_RTC_DS1302_USE_YEAR___SC )
			ds1302_year			= 0x00;
		#endif
		#if( PG_RTC_DS1302_USE_WEEKDAY___SC )
			ds1302_weekday		= 0x00;
		#endif

		ds1302_halt_clock	= 0x00; //Running clock	( At power on, the relative bit is NOT defined! )
		pg_rtc_ds1302_wr_access( PG_DISABLE ); //Protect stored information ( At power on, the relative bit is NOT defined! )
	}

	
	void	pg_rtc_ds1302_wr_access( _pg_Uint8 ds1302_wr_access ) { //PG_ENABLE, PG_DISABLE
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_WRPROTECT ); //Command to write WP ( Write Protect ) Bit7 ( 1 = Protected )
		if( ds1302_wr_access )
			pg_3wire_wr_byte( 0b00000000 ); //Bit7 = 0 to enable writing
		else
			pg_3wire_wr_byte( 0b10000000 ); //Bit7 = 1 to disable writing
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_start( void ) {
		//---[ Start clock ]--------------------------------------------------
		pg_rtc_ds1302_rd_time_sec( );
		ds1302_halt_clock = 0x00;
		pg_rtc_ds1302_wr_time_sec( ds1302_sec );
	}
	
	
	void	pg_rtc_ds1302_stop( void ) {
		//---[ Stop clock ]---------------------------------------------------
		pg_rtc_ds1302_rd_time_sec( );
		ds1302_halt_clock = 0x01;
		pg_rtc_ds1302_wr_time_sec( ds1302_sec );
	}


	_pg_Uint8	pg_rtc_ds1302_wr_time_sec( _pg_Uint8 ds1302_set_sec ) {	//Required for start and stop function too
		//---[ Write SECOND ]-------------------------------------------------
		_pg_Uint8 temp;
		pg_rtc_ds1302_wr_access( PG_ENABLE );
		if( ds1302_set_sec < 60 ) {	//0-59; unsigned, never is < 0.
			temp = 0x00;
			temp = ( ( ( ds1302_set_sec / 10 ) << 4 ) + ( ds1302_set_sec % 10 ) );
			if( ds1302_halt_clock )
				temp = temp | 0b10000000; //Set "Clock Halt Flag" bit7 high to stop clock and go in low power mode!
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_SEC ); //Command to write seconds
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong second value;
				pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_SEC , PG_ERROR_ERROR );
			#endif
			return PG_NOK;
		}
		pg_rtc_ds1302_wr_access( PG_DISABLE );
		return PG_OK;
	}
	
	
	#if( PG_RTC_DS1302_USE_MIN___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_time_min( _pg_Uint8 ds1302_set_min ) {		
			//---[ Write MINUTE ]-------------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ds1302_set_min < 60 ) {	//0-59; unsigned, never is < 0.
				temp = 0x00;
				temp = ( ( ( ds1302_set_min / 10 ) << 4 ) + ( ds1302_set_min % 10 ) );
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_MIN ); //Command to write minutes
				pg_3wire_wr_byte( temp );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong minute value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_MIN , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_HOUR___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_time_hour( _pg_Uint8 ds1302_set_hour ) {	
			//---[ Write HOUR ]---------------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ds1302_set_hour < 24 ) { //0-23; unsigned, never is < 0.
				temp = 0x00;
				temp = ( ( ( ds1302_set_hour / 10 ) << 4 ) + ( ds1302_set_hour % 10 ) );
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_HOUR ); //Command to write hours
				pg_3wire_wr_byte( temp );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong hour value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_HOUR , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_DAY___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_date_day( _pg_Uint8 ds1302_set_day ) {
			//---[ Write DAY (1-31) ]---------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ( ds1302_set_day > 0 ) &&  ( ds1302_set_day < 32 ) ) { //1-31
				temp = 0x00;
				temp = ( ( ( ds1302_set_day / 10 ) << 4 ) + ( ds1302_set_day % 10 ) );
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_DAY ); //Command to write day
				pg_3wire_wr_byte( temp );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong day value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_DAY , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_MONTH___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_date_month( _pg_Uint8 ds1302_set_month ) {
			//---[ Write MONTH ]--------------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ( ds1302_set_month > 0 ) &&  ( ds1302_set_month < 13 ) ) { //1-12
				temp = 0x00;
				temp = ( ( ( ds1302_set_month / 10 ) << 4 ) + ( ds1302_set_month % 10 ) );
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_MONTH ); //Command to write month
				pg_3wire_wr_byte( temp );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong month value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_MONTHS , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_YEAR___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_date_year( _pg_Uint8 ds1302_set_year ) {
			//---[ Write YEAR ]---------------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ( ds1302_set_year > 0 ) &&  ( ds1302_set_year < 100 ) ) { //00-99
				temp = 0x00;
				temp = ( ( ( ds1302_set_year / 10 ) << 4 ) + ( ds1302_set_year % 10 ) );
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_YEAR ); //Command to write year
				pg_3wire_wr_byte( temp );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong year value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_YEARS , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif

	
	#if( PG_RTC_DS1302_USE_WEEKDAY___SC )
		_pg_Uint8	pg_rtc_ds1302_wr_weekday( _pg_Uint8 ds1302_set_weekday ) {
			//---[ Write WEEKDAY (1-7) ]------------------------------------------
			_pg_Uint8 temp;
			pg_rtc_ds1302_wr_access( PG_ENABLE );
			if( ( ds1302_set_weekday > 0 ) &&  ( ds1302_set_weekday < 8 ) ) { //1-7
				PG_RTC_DS1302_CS = PG_ENABLE;
				PG_RTC_DS1302_CS_DELAY
				pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_WEEKDAY ); //Command to write weekday
				pg_3wire_wr_byte( ds1302_set_weekday );
				PG_RTC_DS1302_CS = PG_DISABLE;
				PG_RTC_DS1302_CS_DELAY
			}
			else {
				#if( PG_ERROR_IS_ENABLE == PG_ENABLE )	//Error: wrong day of the week value;
					pg_error_set( PG_ERROR_RTC_DS1302 , PG_RTC_DS1302_ERROR_VALUE_WEEKDAY , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_rtc_ds1302_wr_access( PG_DISABLE );
			return PG_OK;
		}
	#endif
	
	
	#if( PG_RTC_DS1302_WR_TIME_ALL___SC == PG_ENABLE )
		#if( ( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE ) )
			void	pg_rtc_ds1302_wr_time_all( _pg_Uint8 ds1302_set_hour_all, _pg_Uint8 ds1302_set_min_all, _pg_Uint8 ds1302_set_sec_all ) {
				//---[ Write TIME ALL ]-----------------------------------------------
				pg_rtc_ds1302_wr_time_hour( ds1302_set_hour_all );
				pg_rtc_ds1302_wr_time_min( ds1302_set_min_all );
				pg_rtc_ds1302_wr_time_sec( ds1302_set_sec_all );
			}
		#endif
	#endif
	
	
	#if( PG_RTC_DS1302_WR_DATE_ALL___SC == PG_ENABLE )
		#if( ( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_MONTH___SC  == PG_ENABLE ) && ( PG_RTC_DS1302_USE_YEAR___SC  == PG_ENABLE ) )
			void	pg_rtc_ds1302_wr_date_all( _pg_Uint8 ds1302_set_day_all, _pg_Uint8 ds1302_set_month_all, _pg_Uint8 ds1302_set_year_all ) {
				//---[ Write DATE ALL ]-----------------------------------------------
				pg_rtc_ds1302_wr_date_day( ds1302_set_day_all );
				pg_rtc_ds1302_wr_date_month(  ds1302_set_month_all );
				pg_rtc_ds1302_wr_date_year( ds1302_set_year_all );
			}
		#endif
	#endif
	

	void	pg_rtc_ds1302_rd_time_sec( void ) {	//Required for start and stop function too
		//---[ Read SECOND ]--------------------------------------------------
		_pg_Uint8 temp;
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_SEC ); //Command to read "Clock Halt Flag" and seconds
		temp = pg_3wire_rd_byte( );
		ds1302_halt_clock = temp & 0b10000000; //1 = stopped
		temp = temp & 0b01111111; //Clear "Clock Halt Flag" bit to extract right seconds
		ds1302_sec = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}

	
	#if( PG_RTC_DS1302_USE_MIN___SC )
		void	pg_rtc_ds1302_rd_time_min( void ) {
			//---[ Read MINUTE ]--------------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_MIN ); //Command to read minutes
			temp = pg_3wire_rd_byte( );
			temp = temp & 0b01111111; //Clear unused Bit7
			ds1302_min = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_HOUR___SC )
		void	pg_rtc_ds1302_rd_time_hour( void ) {
			//---[ Read HOUR ]----------------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_HOUR ); //Command to read hours
			temp = pg_3wire_rd_byte( );
			temp = temp & 0b00111111; //Clear unused Bit7 and Bit6, h24 NOT supported!
			ds1302_hour = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_DAY___SC )
		void	pg_rtc_ds1302_rd_date_day( void ) {
			//---[ Read DAY (1-31) ]----------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_DAY ); //Command to read day 1-31
			temp = pg_3wire_rd_byte( );
			temp = temp & 0b00111111; //Clear unused Bit7 and Bit6
			ds1302_day = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_MONTH___SC )
		void	pg_rtc_ds1302_rd_date_month( void ) {
			//---[ Read MONTH ]---------------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_MONTH ); //Command to read month
			temp = pg_3wire_rd_byte( );
			temp = temp & 0b00011111; //Clear unused Bit7, Bit6 and Bit5
			ds1302_month = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_YEAR___SC )
		void	pg_rtc_ds1302_rd_date_year( void ) {
			//---[ Read YEAR ]----------------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_YEAR ); //Command to read year
			temp = pg_3wire_rd_byte( );
			ds1302_year = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_USE_WEEKDAY___SC )
		void	pg_rtc_ds1302_rd_weekday( void ) {
			//---[ Read WEEKDAY (1-7) ]-------------------------------------------
			_pg_Uint8 temp;
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_WEEKDAY ); //Command to read weekday 1-7
			temp = pg_3wire_rd_byte( );
			ds1302_weekday = ( temp & 0b00000111 ); //Clear unused Bit7 - Bit3
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
	#endif
	
	
	#if( PG_RTC_DS1302_RD_TIME_ALL___SC == PG_ENABLE )
		#if( ( PG_RTC_DS1302_USE_MIN___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_HOUR___SC == PG_ENABLE ) )
			void	pg_rtc_ds1302_rd_time_all( void ) {
				//---[ Read TIME ALL ]------------------------------------------------
				pg_rtc_ds1302_rd_time_sec( );
				pg_rtc_ds1302_rd_time_min( );
				pg_rtc_ds1302_rd_time_hour( );
			}
		#endif
	#endif
	
	
	#if( PG_RTC_DS1302_RD_DATE_ALL___SC == PG_ENABLE )
		#if( ( PG_RTC_DS1302_USE_DAY___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_MONTH___SC == PG_ENABLE ) && ( PG_RTC_DS1302_USE_YEAR___SC == PG_ENABLE ) )
			void	pg_rtc_ds1302_rd_date_all( void ) {
				//---[ Read DATE ALL ]------------------------------------------------
				pg_rtc_ds1302_rd_date_day( );
				pg_rtc_ds1302_rd_date_month( );
				pg_rtc_ds1302_rd_date_year( );
			}
		#endif
	#endif
	
#endif


