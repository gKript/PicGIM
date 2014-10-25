//
// pgim_font8x8.h
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

/*!		\file			pgim_font8x8.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PG_FONT_8X8_H_
	#define _PG_FONT_8X8_H_
	//
	// standard ascii 5x8 font
	// defines ascii characters 0x20-0x7F (32-127)
	//
	//
	rom const _pg_Uint8 font_8x8[] = {
		0x08, 0x08,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 20  space
		0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00,  // 21  exclamation
		0x6C, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00,  // 22  double quote
		0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00,  // 23  pound
		0x30, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x00,  // 24  dollar
		0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00,  // 25  percent
		0x38, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0x76, 0x00,  // 26  ampersand
		0x60, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,  // 27  single quote
		0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00,  // 28  left paren
		0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,  // 29  right paren
		0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00,  // 2a  star
		0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, 0x00,  // 2b  plus
		0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,  // 2c  comma
		0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,  // 2d  minus
		0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00,  // 2e  period
		0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00,  // 2f  slash
		0x7C, 0xC6, 0xCE, 0xDE, 0xF6, 0xE6, 0x7C, 0x00,  // 30  0
		0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0xFC, 0x00,  // 31  1
		0x78, 0xCC, 0x0C, 0x38, 0x60, 0xCC, 0xFC, 0x00,  // 32  2
		0x78, 0xCC, 0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00,  // 33  3
		0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x1E, 0x00,  // 34  4
		0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00,  // 35  5
		0x38, 0x60, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00,  // 36  6
		0xFC, 0xCC, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00,  // 37  7
		0x78, 0xCC, 0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00,  // 38  8
		0x78, 0xCC, 0xCC, 0x7C, 0x0C, 0x18, 0x70, 0x00,  // 39  9
		0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00,  // 3a  colon
		0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,  // 3b  semicolon
		0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00,  // 3c  less than
		0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00,  // 3d  equals
		0x60, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x60, 0x00,  // 3e  greater than
		0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x00,  // 3f  question
		0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x78, 0x00,  // 40  at
		0x30, 0x78, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0x00,  // 41  A
		0xFC, 0x66, 0x66, 0x7C, 0x66, 0x66, 0xFC, 0x00,  // 42  B
		0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00,  // 43  C
		0xF8, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00,  // 44  D
		0xFE, 0x62, 0x68, 0x78, 0x68, 0x62, 0xFE, 0x00,  // 45  E
		0xFE, 0x62, 0x68, 0x78, 0x68, 0x60, 0xF0, 0x00,  // 46  F
		0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00,  // 47  G
		0xCC, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00,  // 48  H
		0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,  // 49  I
		0x1E, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00,  // 4a  J
		0xE6, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0xE6, 0x00,  // 4b  K
		0xF0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xFE, 0x00,  // 4c  L
		0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00,  // 4d  M
		0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0xC6, 0x00,  // 4e  N
		0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00,  // 4f  O
		0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x00,  // 50  P
		0x78, 0xCC, 0xCC, 0xCC, 0xDC, 0x78, 0x1C, 0x00,  // 51  Q
		0xFC, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0xE6, 0x00,  // 52  R
		0x78, 0xCC, 0xE0, 0x70, 0x1C, 0xCC, 0x78, 0x00,  // 53  S
		0xFC, 0xB4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,  // 54  T
		0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFC, 0x00,  // 55  U
		0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,  // 56  V
		0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00,  // 57  W
		0xC6, 0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0x00,  // 58  X
		0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x30, 0x78, 0x00,  // 59  Y
		0xFE, 0xC6, 0x8C, 0x18, 0x32, 0x66, 0xFE, 0x00,  // 5a  Z
		0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00,  // 5b  left square bracket
		0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00,  // 5c  backslash
		0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00,  // 5d  right square bracket
		0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00,  // 5e  tilde
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,  // 5f  underline
		0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,  // 60  single quote
		0x00, 0x00, 0x78, 0x0C, 0x7C, 0xCC, 0x76, 0x00,  // 61  a
		0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0xDC, 0x00,  // 62  b
		0x00, 0x00, 0x78, 0xCC, 0xC0, 0xCC, 0x78, 0x00,  // 63  c
		0x1C, 0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0x76, 0x00,  // 64  d
		0x00, 0x00, 0x78, 0xCC, 0xFC, 0xC0, 0x78, 0x00,  // 65  e
		0x38, 0x6C, 0x60, 0xF0, 0x60, 0x60, 0xF0, 0x00,  // 66  f
		0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,  // 67  g
		0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0xE6, 0x00,  // 68  h
		0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,  // 69  i
		0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78,  // 6a  j
		0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0xE6, 0x00,  // 6b  k
		0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,  // 6c  l
		0x00, 0x00, 0xCC, 0xFE, 0xFE, 0xD6, 0xC6, 0x00,  // 6d  m
		0x00, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00,  // 6e  n
		0x00, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0x78, 0x00,  // 6f  o
		0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xF0,  // 70  p
		0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x1E,  // 71  q
		0x00, 0x00, 0xDC, 0x76, 0x66, 0x60, 0xF0, 0x00,  // 72  r
		0x00, 0x00, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x00,  // 73  s
		0x10, 0x30, 0x7C, 0x30, 0x30, 0x34, 0x18, 0x00,  // 74  t
		0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00,  // 75  u
		0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,  // 76  v
		0x00, 0x00, 0xC6, 0xD6, 0xFE, 0xFE, 0x6C, 0x00,  // 77  w
		0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00,  // 78  x
		0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,  // 79  y
		0x00, 0x00, 0xFC, 0x98, 0x30, 0x64, 0xFC, 0x00,  // 7a  z
		0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00,  // 7b  left curly bracket
		0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00,  // 7c  or
		0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00,  // 7d  right curly bracket
		0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 7e  tilde
		0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00,  // 7f  pyramid
	};

#endif /* _PG_FONT_8X8_H_ */


