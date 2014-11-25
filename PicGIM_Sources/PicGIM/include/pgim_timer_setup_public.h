//
// pgim_timer_setup_public.h
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

/*!		\file			pgim_timer_setup_public.h		
		\version		0.5-0
		\date			2002 - 2014
		\brief			TIMER module configuration public file.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_TIMER_SETUP_PUBLIC_H_
	#define _PGIM_TIMER_SETUP_PUBLIC_H_

//	#if ( PGIM_TIMER != PG_DISABLE )
	
		//		D E V I C E S   E N A B L I N G
		#define PGIM_TIMER_0					PG_ENABLE_LOOP	//!< Must be: PG_DISABLE || PG_ENABLE_1_SHOT || PG_ENABLE_LOOP
		#define PGIM_TIMER_1					PG_DISABLE	//!< Must be: PG_DISABLE || PG_ENABLE_1_SHOT || PG_ENABLE_LOOP
	
		//		P A R A M E T E R S
		#define PG_TIMER_0_DELAY_TRIM			320				//!< Set the correct value of delay in uSec resulting from test
		#define PG_TIMER_1_DELAY_TRIM			299				//!< Set the correct value of delay in uSec resulting from test

//	#endif
#endif /* _PGIM_TIMER_SETUP_PUBLIC_H_ */
 
 
