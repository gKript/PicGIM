/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ftoa.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_ftoa.h

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
		\file		pgim_ftoa.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To convert a float to string.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
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
	
	//---[ Ftoa ]---
	char *	pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint24 pg_ftoa_trunc_decimal_digits ) {
		//--------------------------------------------------
		//pg_float_value must be a maximum of 7 digits, excluding the sign and the decimal point.
		//i.e.: 1.234567 -1.234567 123.4567 123456.7
		//if pg_float_value = 12.34567890, the real acquired value is 12.34567 (7 digits)
		_pg_Uint32	pg_ftoa_part_integer = 0;
		_pg_Uint32	pg_ftoa_part_decimal = 0;
		_pg_Uint32	pg_ftoa_truncated = 0;
		_pg_Uint32	pg_ftoa_mask = 0;
		char		pg_ftoa_eight_buffer[ 32 ];
		_pg_Uint8	pg_ftoa_eight_buffer_lenght = 0;
		_pg_Uint8	pg_ftoa_value_sign = 0;			//Store sign (1=negative) and pointer offset for sprintf
		_pg_float 	pg_ftoa_multiplier;				//pow(float,float)=x^y want float
		
		//Manage sign
		if ( pg_ftoa_value < 0 ) { 
			pg_ftoa_internal_buffer[ 0 ] = '-'; 
			pg_ftoa_value_sign = 1;					//1 = negative value;
			pg_ftoa_value *= -1;
		}
		
		//Implement format management "E00" (-1237890123.4567 to -1237890e+009)
		
		//Truncation number, leaving the required decimal digits
		pg_ftoa_multiplier = pow( 10.0 , (float)pg_ftoa_trunc_decimal_digits );
		pg_ftoa_truncated = (_pg_Uint32)( pg_ftoa_value * pg_ftoa_multiplier );

		//Checking for digits number: for high accuracy, the maximum manageable number of digits is 8.
		//In this case, number and character corresponding.
		ultoa ( pg_ftoa_truncated, pg_ftoa_eight_buffer );
		pg_ftoa_eight_buffer_lenght = strlen ( pg_ftoa_eight_buffer );

		//Find integer part of float number
		pg_ftoa_part_integer = (_pg_Uint32)pg_ftoa_value;
		
		//Create mask to extract decimal part
		pg_ftoa_mask = ( pg_ftoa_part_integer * pg_ftoa_multiplier );
		
		//Extract decimal part
		pg_ftoa_part_decimal = ( pg_ftoa_truncated - pg_ftoa_mask );
		
		//Create string
		sprintf( pg_ftoa_internal_buffer + pg_ftoa_value_sign , ( const far rom char * ) "%lu.%lu", pg_ftoa_part_integer, pg_ftoa_part_decimal );

		#if PG_ERROR_IS_ENABLE
			if (  pg_ftoa_eight_buffer_lenght > PG_FTOA_MAX_DIGITS ) {
				//Set a WARNING for accuracy loss
				if ( PG_FTOA_CONVERSION_ACCURATE == PG_NO ) {
						pg_error_set( PG_ERROR_FTOA , PG_FTOA_ERROR_OVER_8_ACCURACY , PG_ERROR_WARNING );
				}
				//Set a CRITICAL for accuracy loss
				if ( PG_FTOA_CONVERSION_ACCURATE == PG_YES ) {
						pg_error_set( PG_ERROR_FTOA , PG_FTOA_ERROR_OVER_8_ACCURACY_NO , PG_ERROR_CRITICAL );
				}
			}
			else {
				//No error
				pg_error_set( PG_ERROR_FTOA , PG_FTOA_ERROR_OK , PG_ERROR_OK );
			}
		#endif
		return ( pg_ftoa_internal_buffer );
	}
	//---[ END Ftoa ]---
#endif


