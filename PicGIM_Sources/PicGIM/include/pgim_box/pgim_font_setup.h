//
// pgim_font_setup.h
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

/*!		\file			pgim_font_setup.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_FONT_SETUP_H_
	#define _PGIM_FONT_SETUP_H_
	
	#if ( PGIM_LCD_PCD8544 == PG_ENABLE ) || ( PGIM_LCD_9340 == PG_ENABLE )

		#include "pgim_font_setup_public.h"

		#if ( PGIM_FONTS == PG_ENABLE ) && defined ( _GIM_H_ )

			#if	( PGIM_FONT_3X4 == PG_INCLUDE )
				#include "pgim_font_3x4.h"
				extern	rom const _pg_Uint8 font_3x4[];
			#endif
			#if	( PGIM_FONT_3X5 == PG_INCLUDE )
				#include "pgim_font_3x5.h"
				extern	rom const _pg_Uint8 font_3x5[];
			#endif
			#if	( PGIM_FONT_4X6 == PG_INCLUDE )
				#include "pgim_font_4x6.h"
				extern	rom const _pg_Uint8 font_4x6[];
			#endif
			#if	( PGIM_FONT_5X5 == PG_INCLUDE )
				#include "pgim_font_5x5.h"
				extern	rom const _pg_Uint8 font_5x5[];
			#endif
			#if	( PGIM_FONT_5X6 == PG_INCLUDE )
				#include "pgim_font_5x6.h"
				extern	rom const _pg_Uint8 font_5x6[];
			#endif
			#if	( PGIM_FONT_5X7 == PG_INCLUDE )
				#include "pgim_font_5x7.h"
				extern	rom const _pg_Uint8 font_5x7[];
			#endif
			#if	( PGIM_FONT_5X7_D == PG_INCLUDE )
				#include "pgim_font_5x7_matrix_6x8_v.h"
				extern	rom const _pg_Uint8 font_5x7_matrix_6x8_v[];
			#endif
			#if	( PGIM_FONT_5X8 == PG_INCLUDE )
				#include "pgim_font_5x8.h"
				extern	rom const _pg_Uint8 font_5x8[];
			#endif
			#if	( PGIM_FONT_6X8 == PG_INCLUDE )
				#include "pgim_font_6x8.h"
				extern	rom const _pg_Uint8 font_6x8[];
			#endif
			#if	( PGIM_FONT_8X8 == PG_INCLUDE )
				#include "pgim_font_8x8.h"
				extern	rom const _pg_Uint8 font_8x8[];
			#endif
			#if	( PGIM_FONT_SGU_3X8 == PG_INCLUDE )
				#include "pgim_font_sgu_3x8.h"
				extern	rom const _pg_Uint8 font_sgu_3x8[];
			#endif
			#if	( PGIM_FONT_SGU_6X16 == PG_INCLUDE )
				#include "pgim_font_sgu_6x16.h"
				extern	rom const _pg_Uint8 font_sgu_6x16[];
			#endif
			#if	( PGIM_FONT_SGU_6X16_UP == PG_INCLUDE )
				#include "pgim_font_sgu_6x16_8up.h"
				extern	rom const _pg_Uint8 font_sgu_6x16_8up[];
			#endif
			#if	( PGIM_FONT_SGU_6X16_DW == PG_INCLUDE )
				#include "pgim_font_sgu_6x16_8dw.h"
				extern	rom const _pg_Uint8 font_sgu_6x16_8dw[];
			#endif
    					
        #endif

		struct sbl_glcd_font {
			_pg_Uint8 cur_x;
			_pg_Uint8 cur_y;
			_pg_Uint8 width;
			_pg_Uint8 height;
			_pg_Uint8 v_spacing;
			_pg_Uint8 h_spacing;
			_pg_Uint8 justify_x;
			_pg_Uint8 justify_y;
			rom const _pg_Uint8 *font;
		};

	#endif
	
#endif /* _PGIM_FONT_SETUP_H_ */


