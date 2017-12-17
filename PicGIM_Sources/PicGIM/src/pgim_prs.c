/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_prs.c
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

 /*!
		\file		pgim_prs.c
		\version	0.5-0
		\date		2002 - 2017
		\brief		Pseudo Random Sequencer
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#include "picgim.h"

#if ( PGIM_PRS == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	_pg_Uint32	pg_prs_twisted	= 0;
	_pg_Uint32	pg_prs_seeded	= PG_H32_SEED;		//default value
	_pg_Uint8   pg_prs_rand		= 0; 

	void pg_prs_seed( _pg_Uint32 seed ) {
		if ( seed != 0 )
			pg_prs_seeded = ( ( ( seed ^ GKGKH32_MASK_XOR ) & GKGKH32_MASK_AND ) | GKGKH32_MASK_OR );
	}

	void pg_prs_twist( void ) {
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_A , GKPRS_MASK_XOR_A , pg_prs_seeded );
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_B , GKPRS_MASK_XOR_B , pg_prs_seeded );
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_C , GKPRS_MASK_XOR_C , pg_prs_seeded );
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_D , GKPRS_MASK_XOR_D , pg_prs_seeded );
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_E , GKPRS_MASK_XOR_E , pg_prs_seeded );
		GKTWIST_TWIST( pg_prs_twisted , GKPRS_MASK_AND_F , GKPRS_MASK_XOR_F , pg_prs_seeded );
	}

	_pg_Uint8 pg_prs_rand8( void ) {
		_pg_Uint8 * t;
		pg_prs_twist();
		t = (_pg_Uint8 *)&pg_prs_twisted;
		pg_prs_rand = t[ 0 ] + t[ 1 ] + t[ 2 ] + t[ 3 ];
//		printf( "Rand %02X - pg_prs_twisted %08X - T : %02X - %02X - %02X - %02X\n" , pg_prs_rand , pg_prs_twisted , t[3] , t[2] , t[1] , t[0] );
		return pg_prs_rand;
	}

#endif

//Pseudo Random Sequencer

/*
//Test main.c
void main( void ) {
	//--------------------------------------------------------------------------
	_pg_Uint8 password[ 32 ];
	_pg_Uint8 arg[] = "corrado";
	_pg_Uint8 c;
	
	pg_initialize();
	//pg_serial_open( );
	pg_lcd_hd44780_clear( 0 );

	pg_prs_seed( pg_h32_hash32( arg ) );
	printf( "chsum  %08X\n" , pg_h32_sum );
	puts( "Pseudo seq:" );
	for ( c = 0 ; c < 10 ; c++ ) {
		printf ( " %3u " , pg_prs_rand8() );
	}
	puts( "" );
	//pg_lcd_hd44780_write_string( 0 , rbuffer );	
	
	//pg_serial_close();
	PG_HALT;
} */


