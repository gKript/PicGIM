//
// pgim_board_setup_a.c
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

/*!		\file			pgim_board_setup_a.c
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

#if ( PGIM_BOARD == PG_BOARD_A )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	void	pg_board_a_init( void ) {
		PG_PUSHB_0_TRIS = PG_IN;
		PG_PUSHB_1_TRIS = PG_IN;
		PG_LED_0_TRIS	= PG_OUT;
		PG_LED_1_TRIS	= PG_OUT;

		PG_LED_0 = PG_OFF;
		PG_LED_0 = PG_OFF;
	}

#endif

