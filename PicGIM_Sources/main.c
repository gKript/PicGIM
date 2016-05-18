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
		
		printf ( "String = \"%s\"\n\n", pg_ftoa( -123.4567, 2 ) ); // 123.456
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.4561, 3 ) ); // 123.456
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.4569, 3 ) ); // 123.456
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.4567, 4 ) ); // 123.4567
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.4561, 4 ) ); // 123.4560
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.4569, 4 ) ); // 123.4568
//		printf ( "String = \"%s\"\n\n", pg_ftoa( -123.4569, 4 ) ); // -123.4568
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 12345.7841, 4 ) ); // 12345.7841 12345.7837
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123456.7841, 3 ) ); // 123456.776
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123456.78, 2 ) ); // 123456.77
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 99999.999, 2 ) ); // 100000.00
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 999999999.9999, 2 ) ); // 1000000000.00
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 4000000000.1234, 2 ) ); // 4000000000.00
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 40000001.1234,10 ) ); //acquisisce float 4000000e+007 e stampa String = "40000000.00"
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 4000000.1234, 10 ) );//acquisisce float 4000000.
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123456.0000, 6 ) ); // 123455.989360
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 3.234567891, 13 ) ); // 3.2345678806304
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 1.012, 2 ) ); // 1.01
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 1.012, 6 ) ); // 1.011999
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 123.999, 5 ) ); // 123.99899
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 12.5678, 5 ) ); // 12.56779
//		printf ( "String = \"%s\"\n\n", pg_ftoa( -0.0056789, 7 ) ); // -0.0056788
//		printf ( "String = \"%s\"\n\n", pg_ftoa( -0.005678, 6 ) ); // -0.005677
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 1.0/3, 10 ) ); // 0.3333333492
//		printf ( "String = \"%s\"\n\n", pg_ftoa( 1.2345, 3 ) ); // 1.234
		PG_HALT;
}



//		4.294.967.295 max
//		4294967295 max


