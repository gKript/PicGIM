//
// pgim_font.h
//
// picGim  -  Generic Information Manager for Pic 18 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002, 2003 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of Gim library.

	picGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	picGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

/*!	\file		pgim_font.h
	\version	1.0-0
	\brief		Copyright (C) 2001, 2013<BR>
				Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)<BR>
				Released under the terms of the GNU General Public License v2<BR>
				[ http://gkript.org/gk_gpl_v2.php ]
*/ 		

#ifndef	__PGIM_FONT_SETUP_H__
	#define	__PGIM_FONT_SETUP_H__
	
	#if ( PGIM_FONT == PG_ENABLE )
		#if	( PGIM_FONT_5X5_STD == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x5_std[];
		#endif
		#if	( PGIM_FONT_5X5_STD_M == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x5_std_m[];
		#endif
		#if	( PGIM_FONT_5X6_STD == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x6_std[];
		#endif
		#if	( PGIM_FONT_5X6_STD_M == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x6_std_m[];
		#endif
		#if	( PGIM_FONT_5X7_STD == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x7_std[];
		#endif
		#if	( PGIM_FONT_5X7_STD_M == PG_INCLUDE )
			extern	rom const _pg_Uint8 pg_font_5x7_std_m[];
		#endif
	#endif
	
	struct pg_font_config {
		_pg_Uint8 width;
		_pg_Uint8 height;
		_pg_Uint8 mask;
//		_pg_Uint8 cur_x;
//		_pg_Uint8 cur_y;
//		_pg_Uint8 v_spacing;
//		_pg_Uint8 h_spacing;
//		_pg_Uint8 justify_x;
//		_pg_Uint8 justify_y;
		rom const _pg_Uint8 *font;
	};
#endif


