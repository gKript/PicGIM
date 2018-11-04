//
// 
//
// PicGim  -  Generic Information Manager for Pic 18 / 24 family uControllers 
// Version 0.6-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002 - 2018
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

/*!		\file			main.c
		\version		0.6-0
		\date			2002 - 2018
		\brief			AD9851 DDS programming DEMO
		\details		A demonstration of frequency and sweep programming
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim_main.h"

 void main( void ) {
	//------------------------------------------------------------------------
	// AD9851 DDS programming DEMO
	//------------------------------------------------------------------------
	// DDS will generate a 100[KHz] signal, waits 3s, then goes into loop in
	// a continuous sweep forward and backwards from 100[KHz] to 200[KHz],
	// in different ways ("start and stop" or "center and span", with step,
	// and step time delay ) every 3s again.
	//------------------------------------------------------------------------
	// Configure "pgim_hardware_setup_public.h".
	// Configure "pgim_module_setup_public.h".
	//------------------------------------------------------------------------
	// Using serial mode programming.
	// Set sw D0, D1, and D2 AD9851's pin data bus to entering in serial mode,
	// otherwise hw mode is suitable (so, please comment these tris/lat lines)
	T_D0 = 0;
	T_D1 = 0;
	T_D2 = 0;
	//
	L_D0 = 1;	//to AD9851 pin#4 "D0" or with 10K pull-up;
	L_D1 = 1;	//to AD9851 pin#3 "D1" or with 10K pull-up;
	L_D2 = 0;	//to AD9851 pin#2 "D2" or to GND;
	//------------------------------------------------------------------------
	
	pg_initialize( );
	
	pg_dds_ad9851_set_freq( 100000 );
	pg_delay( 3 , PG_SEC );
	
	pg_loop {
		pg_dds_ad9851_sweep_ss( 100000 , 200000 , 1000 , 50 );
		pg_delay( 3 , PG_SEC );
		pg_dds_ad9851_sweep_ss( 200000 , 100000 , 1000 , 50 );
		pg_delay( 3 , PG_SEC );
		pg_dds_ad9851_sweep_cs( 150000 , 100000 , 1000 , PG_FORWARD , 50 );
		pg_delay( 3 , PG_SEC );
		pg_dds_ad9851_sweep_cs( 150000 , 100000 , 1000 , PG_REVERSE , 50 );
		pg_delay( 3 , PG_SEC );
	}
	
	PG_HALT;
	
	//------------------------------------------------------------------------
	//End Main
	//------------------------------------------------------------------------
}


