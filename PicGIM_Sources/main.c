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
	
	pg_pin_mode( T_B4 , PG_IN );
	
	//---[ Programming clock/calendar: ]--------------------------------------------------------------------
	//	Make a push-button and a pull-up on PORTB4 pin.
	//	At reset time, PORTB4 is probed. If low, rtc will be programmed.
	//------------------------------------------------------------------------------------------------------
	if( !P_B4 ) {
		pg_rtc_ds1302_wr_date_all( 31 , 12 , 15 );
		pg_rtc_ds1302_wr_time_all( 23 , 59 , 50 );
		pg_rtc_ds1302_wr_weekday( PG_RTC_DS1302_WEEKDAY_SUN );
	}
	
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_0 , 0 , "Date=  /  /  " );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_1 , 0 , "Time=  :  :  " );
		
	pg_loop {
		pg_rtc_ds1302_rd_date_all( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  5 , "%02d" , (_pg_int16)ds1302_day );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  8 , "%02d" , (_pg_int16)ds1302_month );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 , 11 , "%02d" , (_pg_int16)ds1302_year );
		
		pg_rtc_ds1302_rd_time_all( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 ,  5 , "%02d" , (_pg_int16)ds1302_hour );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 ,  8 , "%02d" , (_pg_int16)ds1302_min );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_1 , 11 , "%02d" , (_pg_int16)ds1302_sec );
		
		pg_rtc_ds1302_rd_weekday( );
		pg_lcd_hd44780_write_p_int( PG_CONTROLLER_0 , PG_LINE_0 ,  14 , "%d" , (_pg_int16)ds1302_weekday );
		
		pg_delay( 1 , PG_SEC );
	}
	PG_HALT;
}


