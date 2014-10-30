 //
// pgim_ftoa.c
//
// PicGim  -  Generic Information Manager for Pic 18 / 24 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002 - 2014 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of PicGim library.

	PicGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	PicGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

/*!		\file			pgim_ftoa.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			Converts a float to string.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_SERIAL == PG_ENABLE ) || ( PGIM_SPI == PG_ENABLE ) )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	char		pg_ftoa_internal_buffer[ 32 ];
	
	//---[ Ftoa ]---	// Float numer with maximum 8 digit
	char *pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint24 pg_ftoa_trunc_decimal_digits, char * pg_ftoa_buffer ) {
		//--------------------------------------------------
		
		_pg_Uint32	pg_ftoa_part_integer = 0;
		_pg_Uint32	pg_ftoa_part_decimal = 0;
		_pg_Uint32	pg_ftoa_truncated = 0;
		_pg_Uint32	pg_ftoa_mask = 0;
		char		pg_ftoa_eight_buffer[ 32 ];
		_pg_Uint8	pg_ftoa_eight_buffer_lenght = 0;

		// Truncation number, leaving the required decimal digits
		pg_ftoa_truncated = (_pg_Uint32)( pg_ftoa_value * pg_ftoa_trunc_decimal_digits );

		// Check of the maximum manageable 8 digit value for high accuracy
		// ( Exact correspondence between the number and character )
		ultoa ( pg_ftoa_truncated, pg_ftoa_eight_buffer );
		pg_ftoa_eight_buffer_lenght = strlen ( pg_ftoa_eight_buffer );

		if (  pg_ftoa_eight_buffer_lenght > PG_FTOA_MAX_DIGITS ) {
			if ( PG_FTOA_CONVERSION_ACCURATE == PG_YES ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_FTOA , PG_FTOA_ERROR_OVER_8_ACCURACY , PG_ERROR_WARNING );		//Set a WARNING for accuracy loss
				#endif
			}
			if ( PG_FTOA_CONVERSION_ACCURATE == PG_NO ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_FTOA , PG_FTOA_ERROR_OVER_8_ACCURACY_NO , PG_ERROR_CRITICAL );		//Set a CRITICAL for accuracy loss
				#endif
			}
		}		
		// Find the integer part of the float number
		pg_ftoa_part_integer = (_pg_Uint32)pg_ftoa_value;
		
		// Create the mask to extract the decimal part
		pg_ftoa_mask = ( pg_ftoa_part_integer * pg_ftoa_trunc_decimal_digits );
		
		// Extract the decimal part
		pg_ftoa_part_decimal = ( pg_ftoa_truncated - pg_ftoa_mask );
		
		if ( pg_ftoa_value < 0 ) { 
			*pg_ftoa_buffer++ = '-'; 
			pg_ftoa_value *= -1; 
		}
		
		if ( pg_ftoa_buffer == NULL ) {
			// Build the string in internal buffer
			sprintf( pg_ftoa_internal_buffer, ( const far rom char * ) "%lu.%lu", pg_ftoa_part_integer, pg_ftoa_part_decimal ); 
			return ( &pg_ftoa_internal_buffer );
		}
		else {
			// Build the string in user's buffer
			sprintf( pg_ftoa_buffer, ( const far rom char * ) "%lu.%lu", pg_ftoa_part_integer, pg_ftoa_part_decimal );
			return ( NULL );
		}
	}
	//---[ END Ftoa ]---
	
#endif


