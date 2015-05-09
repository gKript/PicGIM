/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_custom_type.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

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
		\file		pgim_custom_type.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Types redefinition sorted by size.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _GIM_CUSTOM_TYPE_H_
	#define _GIM_CUSTOM_TYPE_H_

	#include <stddef.h>
	#include <GenericTypeDefs.h>

        typedef BOOL    _pg_bool;

	#if !defined( PUBLIC )
		#define PUBLIC
	#endif
	
	#if !defined( PROTECTED )
		#define PROTECTED
	#endif
	
	#if !defined( PRIVATE )
		#define PRIVATE		static
	#endif

	#define	_pg_Font							rom const _pg_Uint8
	
	typedef char								_pg_int8;
	typedef unsigned char						_pg_Uint8;
	typedef int									_pg_int16;
	typedef unsigned int						_pg_Uint16;
	typedef float								_pg_float;
	
        #if defined( __18CXX )
                typedef short long				_pg_int24;
                typedef unsigned short long		_pg_Uint24;
        #endif

	typedef long								_pg_int32;
	typedef unsigned long						_pg_Uint32;
	typedef long long							_pg_int64;
	typedef unsigned long long					_pg_Uint64;
	
	typedef	char *								_pg_buffer;
	typedef	unsigned char *						_pg_Ubuffer;


//	typedef union _BYTE_VAL {
//		BYTE Val;
//		struct {
//			unsigned char b0:1;
//			...
//			unsigned char b7:1;
//		} bits;
//	} BYTE_VAL, BYTE_BITS;

	typedef BYTE_VAL						_pg_Uint8_VAL;
	typedef BYTE_BITS						_pg_Uint8_BITS;


//	typedef union _WORD_VAL {
//		WORD Val;
//		BYTE v[2];
//		struct {
//			BYTE LB;
//			BYTE HB;
//		} byte;
//		struct {
//			unsigned char b0:1;
//			...
//			unsigned char b15:1;
//		} bits;
//	} WORD_VAL, WORD_BITS;

	typedef WORD_VAL						_pg_Uint16_VAL;
	typedef WORD_BITS						_pg_Uint16_BITS;

//	typedef union _DWORD_VAL {
//		DWORD Val;
//		WORD w[2];
//		BYTE v[4];
//		struct {
//			WORD LW;
//			WORD HW;
//		} word;
//		struct {
//			BYTE LB;
//			BYTE HB;
//			BYTE UB;
//			BYTE MB;
//		} byte;
//		struct {
//			WORD_VAL low;
//			WORD_VAL high;
//		} wordUnion;
//		struct {
//			unsigned char b0:1;
//			...
//			unsigned char b31:1;
//		} bits;
//	} DWORD_VAL;

	typedef DWORD_VAL						_pg_Uint32_VAL;
	typedef DWORD_VAL						_pg_Uint32_BITS;


//	typedef union _QWORD_VAL {
//		QWORD Val;
//		DWORD d[2];
//		WORD w[4];
//		BYTE v[8];
//		struct {
//			DWORD LD;
//			DWORD HD;
//		} dword;
//		struct {
//			WORD LW;
//			WORD HW;
//			WORD UW;
//			WORD MW;
//		} word;
//		struct {
//			unsigned char b0:1;
//			...
//			unsigned char b63:1;
//		} bits;
//	} QWORD_VAL;

	typedef QWORD_VAL						_pg_Uint64_VAL;
	typedef QWORD_VAL						_pg_Uint64_BITS;
	
	typedef union _pg_Uint24_UNION{
	#if defined( __18CXX )
		_pg_Uint24		Val;
	#endif
		_pg_Uint8			v[ 3 ];
		struct {
			_pg_Uint8		LB;
			_pg_Uint8		MB;
			_pg_Uint8		HB;
		} byte;
		struct {
			_pg_Uint8		b0:1;
			_pg_Uint8		b1:1;
			_pg_Uint8		b2:1;
			_pg_Uint8		b3:1;
			_pg_Uint8		b4:1;
			_pg_Uint8		b5:1;
			_pg_Uint8		b6:1;
			_pg_Uint8		b7:1;
			_pg_Uint8		b8:1;
			_pg_Uint8		b9:1;
			_pg_Uint8		b10:1;
			_pg_Uint8		b11:1;
			_pg_Uint8		b12:1;
			_pg_Uint8		b13:1;
			_pg_Uint8		b14:1;
			_pg_Uint8		b15:1;
			_pg_Uint8		b16:1;
			_pg_Uint8		b17:1;
			_pg_Uint8		b18:1;
			_pg_Uint8		b19:1;
			_pg_Uint8		b20:1;
			_pg_Uint8		b21:1;
			_pg_Uint8		b22:1;
			_pg_Uint8		b23:1;
		} bits;
	} _pg_Uint24_VAL, _pg_Uint24_BITS;

#endif /* _GIM_CUSTOM_TYPE_H_ */

