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


#include "picgim_main.h"

void main( void ) {
	pg_initialize();
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , 0 , 0 , "//--> 00" );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , 1 , 0 , "//--> 01" );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_1 , 0 , 0 , "//--> 10" );
	pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_1 , 1 , 0 , "//--> 11" );
	pg_buzzer_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
	PG_HALT;
}


