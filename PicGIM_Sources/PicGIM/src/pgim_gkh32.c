/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_gkh32.c
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
		\file		pgim_gkh32.c
		\version	0.5-0
		\date		2002 - 2017
		\brief		GKHash32
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#include "picgim.h"

#if ( PGIM_GKH32 == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	_pg_Uint32	pg_gkh32_sum	= 0; 

	_pg_Uint32 pg_gkh32_hash32( _pg_Uint8 * pass ) {
		_pg_Uint32	tmp	= 0;
		_pg_Uint8	len	= 0;
		_pg_Uint8	c;
		
		pg_gkh32_sum = 0;
		while ( pass[ len ] != '\0' ) {
			pg_gkh32_sum += pass[ len ] + ( GKPRS_MASK_XOR_A >> len ) ^ ( GKPRS_MASK_XOR_F << len );
			len++;
		}
		for ( c = 1 ; c <= 32 ; c++ ) {
			tmp += ( pg_gkh32_sum << 1 ) ^ c;
			pg_gkh32_sum ^= tmp;
		}
		return pg_gkh32_sum;
	}

#endif


