//
// pgim_font3x4.h
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

/*!		\file			pgim_font3x4.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PG_FONT_3X4_H_
	#define _PG_FONT_3X4_H_
	//
	//
	//	<Note>
	//
	//
	rom const _pg_Uint8 font_3x4[] = {
		0x03, 0x04,
		0x00, 0x00, 0x00,                        // Code for _pg_int8  
		0x0B, 0x00, 0x00,                        // Code for _pg_int8 !
		0x03, 0x00, 0x03,                        // Code for _pg_int8 "
		0x04, 0x00, 0x00,                        // Code for _pg_int8 #
		0x04, 0x0F, 0x02,                        // Code for _pg_int8 $
		0x00, 0x00, 0x00,                        // Code for _pg_int8 %
		0x00, 0x00, 0x00,                        // Code for _pg_int8 &
		0x03, 0x00, 0x00,                        // Code for _pg_int8 '
		0x06, 0x09, 0x00,                        // Code for _pg_int8 (
		0x09, 0x06, 0x00,                        // Code for _pg_int8 )
		0x0A, 0x04, 0x0A,                        // Code for _pg_int8 *
		0x04, 0x0E, 0x04,                        // Code for _pg_int8 +
		0x0C, 0x00, 0x00,                        // Code for _pg_int8 ,
		0x04, 0x04, 0x04,                        // Code for _pg_int8 -
		0x08, 0x00, 0x00,                        // Code for _pg_int8 .
		0x08, 0x04, 0x02,                        // Code for _pg_int8 /
		0x06, 0x09, 0x06,                        // Code for _pg_int8 0
		0x02, 0x0F, 0x00,                        // Code for _pg_int8 1
		0x09, 0x0D, 0x0B,                        // Code for _pg_int8 2
		0x09, 0x0D, 0x0F,                        // Code for _pg_int8 3
		0x03, 0x02, 0x0F,                        // Code for _pg_int8 4
		0x0B, 0x09, 0x0D,                        // Code for _pg_int8 5
		0x0F, 0x0D, 0x0D,                        // Code for _pg_int8 6
		0x01, 0x0D, 0x03,                        // Code for _pg_int8 7
		0x06, 0x0F, 0x06,                        // Code for _pg_int8 8
		0x0B, 0x0B, 0x0F,                        // Code for _pg_int8 9
		0x09, 0x00, 0x00,                        // Code for _pg_int8 :
		0x00, 0x00, 0x00,                        // Code for _pg_int8 ;
		0x04, 0x0A, 0x00,                        // Code for _pg_int8 <
		0x0A, 0x0A, 0x0A,                        // Code for _pg_int8 =
		0x0A, 0x04, 0x00,                        // Code for _pg_int8 >
		0x01, 0x09, 0x03,                        // Code for _pg_int8 ?
		0x00, 0x00, 0x00,                        // Code for _pg_int8 @
		0x0F, 0x05, 0x0F,                        // Code for _pg_int8 A
		0x0F, 0x0F, 0x0C,                        // Code for _pg_int8 B
		0x0F, 0x09, 0x09,                        // Code for _pg_int8 C
		0x0F, 0x09, 0x06,                        // Code for _pg_int8 D
		0x0F, 0x0D, 0x09,                        // Code for _pg_int8 E
		0x0F, 0x05, 0x01,                        // Code for _pg_int8 F
		0x0F, 0x09, 0x0D,                        // Code for _pg_int8 G
		0x0F, 0x04, 0x0F,                        // Code for _pg_int8 H
		0x09, 0x0F, 0x09,                        // Code for _pg_int8 I
		0x05, 0x09, 0x07,                        // Code for _pg_int8 J
		0x0F, 0x06, 0x09,                        // Code for _pg_int8 K
		0x0F, 0x08, 0x08,                        // Code for _pg_int8 L
		0x0F, 0x01, 0x0F,                        // Code for _pg_int8 M
		0x0F, 0x02, 0x0F,                        // Code for _pg_int8 N
		0x0F, 0x09, 0x0F,                        // Code for _pg_int8 O
		0x0F, 0x05, 0x07,                        // Code for _pg_int8 P
		0x0F, 0x0D, 0x0F,                        // Code for _pg_int8 Q
		0x0F, 0x07, 0x0B,                        // Code for _pg_int8 R
		0x0B, 0x09, 0x0D,                        // Code for _pg_int8 S
		0x01, 0x0F, 0x01,                        // Code for _pg_int8 T
		0x0F, 0x08, 0x0F,                        // Code for _pg_int8 U
		0x07, 0x08, 0x07,                        // Code for _pg_int8 V
		0x0F, 0x04, 0x0F,                        // Code for _pg_int8 W
		0x09, 0x06, 0x09,                        // Code for _pg_int8 X
		0x03, 0x0E, 0x03,                        // Code for _pg_int8 Y
		0x09, 0x0D, 0x0B,                        // Code for _pg_int8 Z
		0x0F, 0x09, 0x00,                        // Code for _pg_int8 [
		0x02, 0x04, 0x08,                        // Code for _pg_int8 BackSlash
		0x09, 0x0F, 0x00,                        // Code for _pg_int8 ]
		0x02, 0x01, 0x02,                        // Code for _pg_int8 ^
		0x08, 0x08, 0x08,                        // Code for _pg_int8 _
		0x03, 0x00, 0x00,                        // Code for _pg_int8 `
		0x0D, 0x0D, 0x0F,                        // Code for _pg_int8 a
		0x0F, 0x0C, 0x0C,                        // Code for _pg_int8 b
		0x0E, 0x0A, 0x0A,                        // Code for _pg_int8 c
		0x0C, 0x0C, 0x0F,                        // Code for _pg_int8 d
		0x0F, 0x0B, 0x0B,                        // Code for _pg_int8 e
		0x0F, 0x05, 0x00,                        // Code for _pg_int8 f
		0x0B, 0x0B, 0x0F,                        // Code for _pg_int8 g
		0x0F, 0x04, 0x0C,                        // Code for _pg_int8 h
		0x0D, 0x00, 0x00,                        // Code for _pg_int8 i
		0x08, 0x0D, 0x00,                        // Code for _pg_int8 j
		0x0F, 0x04, 0x0A,                        // Code for _pg_int8 k
		0x09, 0x0F, 0x08,                        // Code for _pg_int8 l
		0x0E, 0x02, 0x0E,                        // Code for _pg_int8 m
		0x0C, 0x02, 0x0E,                        // Code for _pg_int8 n
		0x0E, 0x0A, 0x0E,                        // Code for _pg_int8 o
		0x0E, 0x06, 0x06,                        // Code for _pg_int8 p
		0x06, 0x06, 0x0E,                        // Code for _pg_int8 q
		0x0E, 0x04, 0x02,                        // Code for _pg_int8 r
		0x0A, 0x09, 0x05,                        // Code for _pg_int8 s
		0x0F, 0x0A, 0x00,                        // Code for _pg_int8 t
		0x06, 0x08, 0x0E,                        // Code for _pg_int8 u
		0x06, 0x08, 0x06,                        // Code for _pg_int8 v
		0x0E, 0x0C, 0x0E,                        // Code for _pg_int8 w
		0x0A, 0x04, 0x0A,                        // Code for _pg_int8 x
		0x02, 0x0C, 0x02,                        // Code for _pg_int8 y
		0x0A, 0x0E, 0x0A,                        // Code for _pg_int8 z
		0x04, 0x0F, 0x09,                        // Code for _pg_int8 {
		0x0F, 0x00, 0x00,                        // Code for _pg_int8 |
		0x09, 0x0F, 0x04,                        // Code for _pg_int8 }
		0x00, 0x00, 0x00                         // Code for _pg_int8 ~
	};

#endif /* _PG_FONT_3X4_H_ */


