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

#ifndef _PGIM_HARDWARE_SETUP_H_
	#define	_PGIM_HARDWARE_SETUP_H_

	#if	defined( __18CXX )
		//-------------------------------------------------
		#if ( PG_USER_SUPPLY_VOLT == 0.00 )
		
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE We think this is the first time you have compiled your project with PicGim. First of all you have to set the correct power supply value in pgim_hardware_setup_public.h
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
		
		//-------------------------------------------------
		#if ( PG_CLOCK == 0.000 )
		
			#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE We think this is the first time you have compiled your project with PicGim. First of all you have to set the correct oscillator MHz value in pgim_hardware_setup_public.h
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
	#endif
#endif /* _PGIM_HARDWARE_SETUP_H_ */


//-------------------------------------------------------------------------------
//    P O W E R   S U P P L Y
//-------------------------------------------------------------------------------

#if defined( __18CXX )
	//-------------------------------------------------
	#if ( PG_USER_SUPPLY_VOLT > PG_MCU_SUPPLY_VOLT_MAX )
	
		#warning	PG_HS_PG PG_HS_ERR PG_HS_CORE The MCU power supply ( PG_USER_SUPPLY_VOLT [V] ) is greater than its maximum specification ( PG_MCU_SUPPLY_VOLT_MAX [V] ).
		#ifndef		PG_EXIT_ON_ERROR
			#define		PG_EXIT_ON_ERROR
		#endif
	#else
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			//-------------------------------------------------
			#if ( PG_USER_SUPPLY_VOLT < PG_MCU_SUPPLY_VOLT_MIN )
			
				#warning PG_HS_PG PG_HS_CORE The requested MCU power supply ( PG_USER_SUPPLY_VOLT [V] ) is lower than the correct specification ( PG_MCU_SUPPLY_VOLT_MIN [V] ).
			#else
				#warning PG_HS_PG PG_HS_CORE Set MCU POWER SUPPLY to PG_USER_SUPPLY_VOLT [V]
				#warning PG_HS_PG PG_HS_CORE Make sure that the PG_USER_SUPPLY_VOLT voltage is enough for the clock frequency chosen.
			#endif
		#endif
	#endif
#endif


