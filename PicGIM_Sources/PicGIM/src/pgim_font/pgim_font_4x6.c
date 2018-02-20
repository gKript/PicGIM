//
// pgim_font4x6.h
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

/*!		\file			pgim_font4x6.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( ( PGIM_FONT == PG_ENABLE ) && ( PGIM_FONT_4X6 == PG_INCLUDE ) )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	rom const _pg_Uint8 font_4x6[] = {
		0x04, 0x06,
		0x00, 0x00, 0x00, 0x00,                  // Code for _pg_int8  
		0x00, 0x00, 0x17, 0x00,                  // Code for _pg_int8 !
		0x00, 0x03, 0x00, 0x03,                  // Code for _pg_int8 "
		0x00, 0x1F, 0x0A, 0x1F,                  // Code for _pg_int8 #
		0x00, 0x14, 0x3F, 0x0A,                  // Code for _pg_int8 $
		0x00, 0x09, 0x04, 0x12,                  // Code for _pg_int8 %
		0x00, 0x1A, 0x15, 0x1E,                  // Code for _pg_int8 &
		0x00, 0x03, 0x01, 0x00,                  // Code for _pg_int8 '
		0x00, 0x0E, 0x11, 0x00,                  // Code for _pg_int8 (
		0x00, 0x11, 0x0E, 0x00,                  // Code for _pg_int8 )
		0x00, 0x15, 0x0E, 0x15,                  // Code for _pg_int8 *
		0x00, 0x04, 0x0E, 0x04,                  // Code for _pg_int8 +
		0x00, 0x30, 0x10, 0x00,                  // Code for _pg_int8 ,
		0x00, 0x04, 0x04, 0x04,                  // Code for _pg_int8 -
		0x00, 0x00, 0x10, 0x00,                  // Code for _pg_int8 .
		0x00, 0x18, 0x04, 0x03,                  // Code for _pg_int8 /
		0x00, 0x1E, 0x11, 0x0F,                  // Code for _pg_int8 0
		0x00, 0x12, 0x1F, 0x10,                  // Code for _pg_int8 1
		0x00, 0x19, 0x15, 0x12,                  // Code for _pg_int8 2
		0x00, 0x11, 0x15, 0x0A,                  // Code for _pg_int8 3
		0x00, 0x06, 0x04, 0x1F,                  // Code for _pg_int8 4
		0x00, 0x17, 0x15, 0x09,                  // Code for _pg_int8 5
		0x00, 0x0E, 0x15, 0x08,                  // Code for _pg_int8 6
		0x00, 0x01, 0x1D, 0x07,                  // Code for _pg_int8 7
		0x00, 0x0A, 0x15, 0x0A,                  // Code for _pg_int8 8
		0x00, 0x02, 0x15, 0x0E,                  // Code for _pg_int8 9
		0x00, 0x00, 0x14, 0x00,                  // Code for _pg_int8 :
		0x00, 0x30, 0x14, 0x00,                  // Code for _pg_int8 ;
		0x00, 0x04, 0x0A, 0x11,                  // Code for _pg_int8 <
		0x00, 0x14, 0x14, 0x14,                  // Code for _pg_int8 =
		0x00, 0x11, 0x0A, 0x04,                  // Code for _pg_int8 >
		0x00, 0x01, 0x15, 0x02,                  // Code for _pg_int8 ?
		0x00, 0x1F, 0x11, 0x17,                  // Code for _pg_int8 @
		0x00, 0x1E, 0x05, 0x1E,                  // Code for _pg_int8 A
		0x00, 0x1F, 0x15, 0x0A,                  // Code for _pg_int8 B
		0x00, 0x0E, 0x11, 0x11,                  // Code for _pg_int8 C
		0x00, 0x1F, 0x11, 0x0E,                  // Code for _pg_int8 D
		0x00, 0x1F, 0x15, 0x11,                  // Code for _pg_int8 E
		0x00, 0x1F, 0x05, 0x01,                  // Code for _pg_int8 F
		0x00, 0x0E, 0x11, 0x1D,                  // Code for _pg_int8 G
		0x00, 0x1F, 0x04, 0x1F,                  // Code for _pg_int8 H
		0x00, 0x11, 0x1F, 0x11,                  // Code for _pg_int8 I
		0x00, 0x08, 0x10, 0x0F,                  // Code for _pg_int8 J
		0x00, 0x1F, 0x04, 0x1B,                  // Code for _pg_int8 K
		0x00, 0x1F, 0x10, 0x10,                  // Code for _pg_int8 L
		0x00, 0x1F, 0x06, 0x1F,                  // Code for _pg_int8 M
		0x00, 0x1F, 0x02, 0x1F,                  // Code for _pg_int8 N
		0x00, 0x0E, 0x11, 0x0E,                  // Code for _pg_int8 O
		0x00, 0x1F, 0x05, 0x02,                  // Code for _pg_int8 P
		0x00, 0x0E, 0x19, 0x1E,                  // Code for _pg_int8 Q
		0x00, 0x1F, 0x05, 0x1A,                  // Code for _pg_int8 R
		0x00, 0x16, 0x15, 0x0D,                  // Code for _pg_int8 S
		0x00, 0x01, 0x1F, 0x01,                  // Code for _pg_int8 T
		0x00, 0x1F, 0x10, 0x1F,                  // Code for _pg_int8 U
		0x00, 0x0F, 0x10, 0x0F,                  // Code for _pg_int8 V
		0x00, 0x1F, 0x0C, 0x1F,                  // Code for _pg_int8 W
		0x00, 0x1B, 0x04, 0x1B,                  // Code for _pg_int8 X
		0x00, 0x03, 0x1C, 0x03,                  // Code for _pg_int8 Y
		0x00, 0x19, 0x15, 0x13,                  // Code for _pg_int8 Z
		0x00, 0x1F, 0x11, 0x00,                  // Code for _pg_int8 [
		0x00, 0x03, 0x04, 0x18,                  // Code for _pg_int8 BackSlash
		0x00, 0x11, 0x1F, 0x00,                  // Code for _pg_int8 ]
		0x00, 0x02, 0x01, 0x02,                  // Code for _pg_int8 ^
		0x20, 0x20, 0x20, 0x20,                  // Code for _pg_int8 _
		0x00, 0x01, 0x03, 0x00,                  // Code for _pg_int8 `
		0x00, 0x18, 0x14, 0x1C,                  // Code for _pg_int8 a
		0x00, 0x1F, 0x14, 0x08,                  // Code for _pg_int8 b
		0x00, 0x08, 0x14, 0x14,                  // Code for _pg_int8 c
		0x00, 0x08, 0x14, 0x1F,                  // Code for _pg_int8 d
		0x00, 0x0C, 0x1C, 0x14,                  // Code for _pg_int8 e
		0x00, 0x04, 0x1E, 0x05,                  // Code for _pg_int8 f
		0x00, 0x2C, 0x24, 0x3C,                  // Code for _pg_int8 g
		0x00, 0x1F, 0x04, 0x18,                  // Code for _pg_int8 h
		0x00, 0x00, 0x1D, 0x00,                  // Code for _pg_int8 i
		0x00, 0x20, 0x3D, 0x00,                  // Code for _pg_int8 j
		0x00, 0x1F, 0x08, 0x14,                  // Code for _pg_int8 k
		0x00, 0x00, 0x1F, 0x00,                  // Code for _pg_int8 l
		0x00, 0x1C, 0x0C, 0x1C,                  // Code for _pg_int8 m
		0x00, 0x1C, 0x04, 0x18,                  // Code for _pg_int8 n
		0x00, 0x08, 0x14, 0x08,                  // Code for _pg_int8 o
		0x00, 0x3C, 0x14, 0x08,                  // Code for _pg_int8 p
		0x00, 0x08, 0x14, 0x3C,                  // Code for _pg_int8 q
		0x00, 0x1C, 0x04, 0x00,                  // Code for _pg_int8 r
		0x00, 0x10, 0x1C, 0x04,                  // Code for _pg_int8 s
		0x00, 0x04, 0x1E, 0x14,                  // Code for _pg_int8 t
		0x00, 0x1C, 0x10, 0x1C,                  // Code for _pg_int8 u
		0x00, 0x0C, 0x10, 0x0C,                  // Code for _pg_int8 v
		0x00, 0x1C, 0x18, 0x1C,                  // Code for _pg_int8 w
		0x00, 0x14, 0x08, 0x14,                  // Code for _pg_int8 x
		0x00, 0x2C, 0x10, 0x0C,                  // Code for _pg_int8 y
		0x00, 0x04, 0x1C, 0x10,                  // Code for _pg_int8 z
		0x00, 0x04, 0x1F, 0x11,                  // Code for _pg_int8 {
		0x00, 0x00, 0x1F, 0x00,                  // Code for _pg_int8 |
		0x00, 0x11, 0x1F, 0x04,                  // Code for _pg_int8 }
		0x02, 0x01, 0x02, 0x01                   // Code for _pg_int8 ~
	};
#endif


