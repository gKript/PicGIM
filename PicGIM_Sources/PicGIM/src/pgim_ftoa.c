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
		\brief			Converts 32-bit float to string. It is lightweight.
		\details		
		\author			DarioG(Dario Greggio), Ren and 1and0 from the forum of Microchip(R) (original version)
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

	//---[ Ftoa ]---
	 void	pg_ftoa( _pg_float pg_ftoa_value, char * pg_ftoa_buffer ) {
		//--------------------------------------------------
		if ( pg_ftoa_value < 0 ) { 
			*pg_ftoa_buffer++ = '-'; 
			pg_ftoa_value *= -1; 
		} 
		sprintf( pg_ftoa_buffer, ( const far rom char * ) "%lu.%03u", 
								(long)pg_ftoa_value, 
								(int)( ( pg_ftoa_value - (long)pg_ftoa_value ) * 1000 + 0.5 ) ); 
								//ori: (int)( ( pg_ftoa_value - (long)pg_ftoa_value ) * 1000. + 0.5 ) ); 
	}
	//---[ END Ftoa ]---
#endif


