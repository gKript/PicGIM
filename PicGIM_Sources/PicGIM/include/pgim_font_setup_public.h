//
// pgim_font_setup_public.h
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

/*!	\file		pgim_font_setup_public.h
	\version	0.5-0
	\brief		Copyright (C) 2001, 2013<BR>
				Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)<BR>
				Released under the terms of the GNU General Public License v2<BR>
				[ http://gkript.org/gk_gpl_v2.php ]
*/ 		

#ifndef	__PGIM_FONT_SETUP_PUBLIC_H__
	#define	__PGIM_FONT_SETUP_PUBLIC_H__
	
//	#if ( ( PGIM_LCD_5110 == PG_ENABLE ) || ( PGIM_LCD9340 == PG_ENABLE ) )
	#if ( PGIM_FONT == PG_ENABLE )

	//------------------------------------------------------------------------------
	//		S T A N D A R D   F O N T
	//------------------------------------------------------------------------------
			#define		PGIM_FONT_3X4				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_3X5				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_4X6				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_5X5				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_5X6				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_5X7				PG_INCLUDE			//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_5X7_D				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_5X8				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_6X8				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_8X8				PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE

	//------------------------------------------------------------------------------
	//		S G U   S P E C I A L   F O N T
	//------------------------------------------------------------------------------
			#define		PGIM_FONT_SGU_3X8			PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_SGU_6X16			PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_SGU_6X16_UP		PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			#define		PGIM_FONT_SGU_6X16_DW		PG_NOT_INCLUDE		//!< Must be: PG_INCLUDE || PG_NOT_INCLUDE
			
	#endif
#endif	/*  __PGIM_FONT_SETUP_PUBLIC_H__  */


