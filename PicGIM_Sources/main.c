/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		main.c
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
 
#include "picgim_main.h"

void main( void ) {
	//--------------------------------------------------------------------------
	_pg_Uint8 password[ 32 ];
	_pg_Uint8 arg[] = "corrado";
	_pg_Uint8 c;
	
	pg_initialize();
	pg_lcd_hd44780_clear( 0 );

	pg_prs_seed( pg_h32_hash32( arg ) );
	printf( "chsum  %08X\n" , pg_h32_sum );
	puts( "Pseudo seq:" );
	for ( c = 0 ; c < 10 ; c++ ) {
		printf ( " %3u " , pg_prs_rand8() );
	}
	puts( "" );
	PG_HALT;
}


