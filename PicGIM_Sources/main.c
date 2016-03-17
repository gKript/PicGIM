/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		main.c
	Project :		<Insert here the name of your project>
	Author :		<Insert here your nick>

	START LICENSE	GPL V3.0

		<one line to give the program's name and a brief idea of what it does.>
 
	    Copyright (C) <year>  <name of author>

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

//	This test code works on a 16x2 HD44780 lcd display.

#include "picgim_main.h"

void main( void ) {
	
	pg_initialize( );
	
	//---[ Programming clock/calendar: ]--------------------------------------------------------------------
	// 1.) Remove the comment of the three functions below;
	// 2.) Fill with the correct data and program the device;
	// 3.) Comment again and program again, so the updated information
	//     of the running clock will not be overwritten at the next reset.
	//------------------------------------------------------------------------------------------------------
//	pg_rtc_ds1302_wr_date( 31 , 12 , 15 );					// Programming function #1, to setup date
//	pg_rtc_ds1302_wr_time( 23 , 59 , 50 );					// Programming function #2, to setup clock
//	pg_rtc_ds1302_wr_weekday( PG_RTC_DS1302_WEEKDAY_SUN );	// Programming function #3, to setup week day
	
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_0 , 0 , "Date=  /  /  " );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_1 , 0 , "Time=  :  :  " );
		
	pg_loop {
		pg_rtc_ds1302_rd_date( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  5 , "%02d" , (int)ds1302_day );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  8 , "%02d" , (int)ds1302_month );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 , 11 , "%02d" , (int)ds1302_year );
		
		pg_rtc_ds1302_rd_time( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 ,  5 , "%02d" , (int)ds1302_hour );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 ,  8 , "%02d" , (int)ds1302_min );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 , 11 , "%02d" , (int)ds1302_sec );
		
		pg_rtc_ds1302_rd_weekday( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  14 , "%d" , (int)ds1302_weekday );
		
		pg_delay( 1 , PG_SEC );
	}
	PG_HALT;
}


