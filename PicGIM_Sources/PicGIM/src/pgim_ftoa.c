/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ftoa.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.6
	Current version :		0.6-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_ftoa.h

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2016  gKript.org - We.PIC project - <http://www.gkript.org>

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
		\file		pgim_ftoa.c
		\version	0.6-0
		\date		2002 - 2016
		\brief		To convert a float to string.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if ( PGIM_FTOA == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HF_FTOA PG_HS_MSG This file is compiling.
	#endif
	
	char	pg_ftoa_internal_buffer[ 32 ];
	
	//---[ Ftoa ]-----------------------------------------------------------------------
	char *	pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint8 pg_ftoa_trunc_decimal_digits ) {
	//----------------------------------------------------------------------------------
		_pg_Uint8	index_int_buf = 0;
		_pg_int8	integer_digits = 1;

		if ( pg_ftoa_value < 0 ) { //gestione segno meno
			pg_ftoa_internal_buffer[ index_int_buf ] = '-';
			index_int_buf++;
			pg_ftoa_value *= -1;
		}
		while ( pg_ftoa_value >= 10 ) {
			pg_ftoa_value = pg_ftoa_value / 10; //sposto la virgola a sx di un posto
			integer_digits++;
		}
		pg_ftoa_trunc_decimal_digits = pg_ftoa_trunc_decimal_digits + integer_digits;
		while ( pg_ftoa_trunc_decimal_digits ) { //da implementare per scegliere numero cifre se dopo la virgola oppure in totale escluso punto e segno meno
			pg_ftoa_internal_buffer[ index_int_buf ] = (_pg_Uint8)pg_ftoa_value + '0'; //stampo la parte intera che ora e' una cifra sola
			pg_ftoa_trunc_decimal_digits--;
			index_int_buf++;
			integer_digits--;
			if ( ( integer_digits == 0 ) && ( pg_ftoa_trunc_decimal_digits > 0 ) ) { //evita di stampare il '.' con nessuna cifra dopo
				pg_ftoa_internal_buffer[ index_int_buf ] = '.';
				index_int_buf++;
			}
			pg_ftoa_value = ( ( pg_ftoa_value - (_pg_Uint8)pg_ftoa_value ) * 10 ); //sposto la virgola a dx di un posto ed elimino la decina
		}
		pg_ftoa_internal_buffer[ index_int_buf ] = '\0';
		return ( pg_ftoa_internal_buffer );
	}
	//---[ END Ftoa ]-------------------------------------------------------------------
	
#endif


