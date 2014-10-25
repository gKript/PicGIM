//
// pgim_font_sgu_3x8.h
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

/*!		\file			pgim_font_sgu_3x8.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PG_FONT_SGU_3x8_H_
	#define _PG_FONT_SGU_3x8_H_
	//
	//
	//	<Note>
	//
	//
	rom const _pg_Uint8 font_sgu_3x8[] = {
        0x00, 0x00, 0x00,		// Code for _pg_int8  			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 !			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 "			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 #			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 $			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 %			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 &			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 '			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 (			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 )			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 *			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 +			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 ,			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 -			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 .			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 /			NOT IMPLEMENTED
        0x7F, 0xC3, 0x7F,		// Code for _pg_int8 0
        0x43, 0xC0, 0x40,		// Code for _pg_int8 1
        0x43, 0xC3, 0x40,		// Code for _pg_int8 2
        0x43, 0xC3, 0x43,		// Code for _pg_int8 3
        0x4F, 0xC3, 0x43,		// Code for _pg_int8 4
        0x4F, 0xCF, 0x43,		// Code for _pg_int8 5
        0x4F, 0xCF, 0x4F,		// Code for _pg_int8 6
        0x7F, 0xCF, 0x4F,		// Code for _pg_int8 7
        0x7F, 0xFF, 0x4F,		// Code for _pg_int8 8
        0x7F, 0xFF, 0x7F,		// Code for _pg_int8 9
        0x00, 0x00, 0x00,		// Code for _pg_int8 :			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 ;			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 <			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 =			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 >			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 ?			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 @			NOT IMPLEMENTED
        0x33, 0x33, 0xFF,		// Code for _pg_int8 A			--> ALIAS LOWER CASE
        0xC3, 0xCF, 0xFF,		// Code for _pg_int8 B			--> ALIAS LOWER CASE
        0xFF, 0x03, 0xFF,		// Code for _pg_int8 C			--> ALIAS LOWER CASE
        0xF3, 0xFF, 0xF3,		// Code for _pg_int8 D			--> ALIAS LOWER CASE
        0xFF, 0x30, 0xF3,		// Code for _pg_int8 E			--> ALIAS LOWER CASE
        0x03, 0x03, 0xFF,		// Code for _pg_int8 F			--> ALIAS LOWER CASE
        0xFF, 0xC0, 0xCF,		// Code for _pg_int8 G			--> ALIAS LOWER CASE
        0xF3, 0x33, 0xFF,		// Code for _pg_int8 H			--> ALIAS LOWER CASE
        0xC3, 0xF3, 0xC3,		// Code for _pg_int8 I			--> ALIAS LOWER CASE
        0xCF, 0xC3, 0xCF,		// Code for _pg_int8 J			--> ALIAS LOWER CASE
        0xCF, 0xFF, 0xFF,		// Code for _pg_int8 K			--> ALIAS LOWER CASE
        0xCC, 0xFF, 0x33,		// Code for _pg_int8 L			--> ALIAS LOWER CASE
        0xCF, 0xF0, 0xCF,		// Code for _pg_int8 M			--> ALIAS LOWER CASE
        0xF0, 0x3F, 0xFC,		// Code for _pg_int8 N			--> ALIAS LOWER CASE
        0xCF, 0x3C, 0xF3,		// Code for _pg_int8 O			--> ALIAS LOWER CASE
        0xFF, 0x00, 0xC3,		// Code for _pg_int8 P			--> ALIAS LOWER CASE
        0xCC, 0x3F, 0xCC,		// Code for _pg_int8 Q			--> ALIAS LOWER CASE
        0xF3, 0xC3, 0xF3,		// Code for _pg_int8 R			--> ALIAS LOWER CASE
        0xFF, 0x0C, 0x3F,		// Code for _pg_int8 S			--> ALIAS LOWER CASE
        0xF3, 0x30, 0xF3,		// Code for _pg_int8 T			--> ALIAS LOWER CASE
        0x03, 0x03, 0xFF,		// Code for _pg_int8 U			--> ALIAS LOWER CASE
        0xC3, 0xFF, 0xFF,		// Code for _pg_int8 V			--> ALIAS LOWER CASE
        0xCF, 0x3C, 0xFF,		// Code for _pg_int8 W			--> ALIAS LOWER CASE
        0xFF, 0x30, 0xFF,		// Code for _pg_int8 X			--> ALIAS LOWER CASE
        0xFF, 0xC3, 0x0F,		// Code for _pg_int8 Y			--> ALIAS LOWER CASE
        0xF3, 0x3F, 0xC3,		// Code for _pg_int8 Z			--> ALIAS LOWER CASE
        0x00, 0x00, 0x00,		// Code for _pg_int8 [			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 BackSlash	NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 ]			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 ^			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 _			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 `			NOT IMPLEMENTED
        0x33, 0x33, 0xFF,		// Code for _pg_int8 a			--> ALIAS UPPER CASE
        0xC3, 0xCF, 0xFF,		// Code for _pg_int8 b			--> ALIAS UPPER CASE
        0xFF, 0x03, 0xFF,		// Code for _pg_int8 c			--> ALIAS UPPER CASE
        0xF3, 0xFF, 0xF3,		// Code for _pg_int8 d			--> ALIAS UPPER CASE
        0xFF, 0x30, 0xF3,		// Code for _pg_int8 e			--> ALIAS UPPER CASE
        0x03, 0x03, 0xFF,		// Code for _pg_int8 f			--> ALIAS UPPER CASE
        0xFF, 0xC0, 0xCF,		// Code for _pg_int8 g			--> ALIAS UPPER CASE
        0xF3, 0x33, 0xFF,		// Code for _pg_int8 h			--> ALIAS UPPER CASE
        0xC3, 0xF3, 0xC3,		// Code for _pg_int8 i			--> ALIAS UPPER CASE
        0xCF, 0xC3, 0xCF,		// Code for _pg_int8 j			--> ALIAS UPPER CASE
        0xCF, 0xFF, 0xFF,		// Code for _pg_int8 k			--> ALIAS UPPER CASE
        0xCC, 0xFF, 0x33,		// Code for _pg_int8 l			--> ALIAS UPPER CASE
        0xCF, 0xF0, 0xCF,		// Code for _pg_int8 m			--> ALIAS UPPER CASE
        0xF0, 0x3F, 0xFC,		// Code for _pg_int8 n			--> ALIAS UPPER CASE
        0xCF, 0x3C, 0xF3,		// Code for _pg_int8 o			--> ALIAS UPPER CASE
        0xFF, 0x00, 0xC3,		// Code for _pg_int8 p			--> ALIAS UPPER CASE
        0xCC, 0x3F, 0xCC,		// Code for _pg_int8 q			--> ALIAS UPPER CASE
        0xF3, 0xC3, 0xF3,		// Code for _pg_int8 r			--> ALIAS UPPER CASE
        0xFF, 0x0C, 0x3F,		// Code for _pg_int8 s			--> ALIAS UPPER CASE
        0xF3, 0x30, 0xF3,		// Code for _pg_int8 t			--> ALIAS UPPER CASE
        0x03, 0x03, 0xFF,		// Code for _pg_int8 u			--> ALIAS UPPER CASE
        0xC3, 0xFF, 0xFF,		// Code for _pg_int8 v			--> ALIAS UPPER CASE
        0xCF, 0x3C, 0xFF,		// Code for _pg_int8 w			--> ALIAS UPPER CASE
        0xFF, 0x30, 0xFF,		// Code for _pg_int8 x			--> ALIAS UPPER CASE
        0xFF, 0xC3, 0x0F,		// Code for _pg_int8 y			--> ALIAS UPPER CASE
        0xF3, 0x3F, 0xC3,		// Code for _pg_int8 z			--> ALIAS UPPER CASE
        0x00, 0x00, 0x00,		// Code for _pg_int8 {			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 |			NOT IMPLEMENTED
        0x00, 0x00, 0x00,		// Code for _pg_int8 }			NOT IMPLEMENTED
        0x00, 0x00, 0x00 		// Code for _pg_int8 ~			NOT IMPLEMENTED
        };

#endif	/* _PG_FONT_SGU_3x8_H_ */


