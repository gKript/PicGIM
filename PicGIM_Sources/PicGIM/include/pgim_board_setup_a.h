//
// pgim_hardware_setup.h
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

/*!		\file			pgim_hardware_setup.h
		\version		0.5-0
		\date			2002 - 2014
		\brief
		\details
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#ifndef PGIM_BOARD_SETUP_A_H
#define	PGIM_BOARD_SETUP_A_H

	#if ( PGIM_BOARD == PG_BOARD_A )

		#define	PG_PUSHB_0			P_B0
		#define	PG_PUSHB_1			P_B1
		#define	PG_LED_0			L_B2
		#define	PG_LED_1			L_B3

		#define	PG_PUSHB_0_TRIS		T_B0
		#define	PG_PUSHB_1_TRIS		T_B1
		#define	PG_LED_0_TRIS		T_B2
		#define	PG_LED_1_TRIS		T_B3

		void	pg_board_a_init		( void );

	#endif

#endif

/*

		\attention	Here a link to the file : \ref pgim_board_setup.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

