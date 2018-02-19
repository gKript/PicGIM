/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_hardware_setup.h
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
		\file		pgim_hardware_setup.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The private file for the hardware definitions.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_HARDWARE_SETUP_H_
	#define	_PGIM_HARDWARE_SETUP_H_

	#if	defined( __18CXX )
		//-------------------------------------------------
		#if ( PG_USER_SUPPLY_VOLT == 0.00 )
		
			#warning	PicGIM >>> ERROR !!! >>> Core >>> We think this is the first time you have compiled your project with PicGim. First of all you have to set the correct power supply value in pgim_hardware_setup_public.h
			#ifndef		PG_EXIT_ON_ERROR
				#define		PG_EXIT_ON_ERROR
			#endif
		#endif
		
		//-------------------------------------------------
		#if ( PG_CLOCK == 0.000 )
		
			#warning	PicGIM >>> ERROR !!! >>> Core >>> We think this is the first time you have compiled your project with PicGim. First of all you have to set the correct oscillator MHz value in pgim_hardware_setup_public.h
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
	
		#warning	PicGIM >>> ERROR !!! >>> Core >>> The MCU power supply ( PG_USER_SUPPLY_VOLT [mV] ) is greater than its maximum specification ( PG_MCU_SUPPLY_VOLT_MAX [mV] ).
		#ifndef		PG_EXIT_ON_ERROR
			#define		PG_EXIT_ON_ERROR
		#endif
	#else
		#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
			//-------------------------------------------------
			#if ( PG_USER_SUPPLY_VOLT < PG_MCU_SUPPLY_VOLT_MIN )
			
				#warning PicGIM >>> Core >>> The requested MCU power supply ( PG_USER_SUPPLY_VOLT [mV] ) is lower than the correct specification ( PG_MCU_SUPPLY_VOLT_MIN [mV] ).
			#else
				#warning PicGIM >>> Core >>> Set MCU POWER SUPPLY to PG_USER_SUPPLY_VOLT [mV]
				#warning PicGIM >>> Core >>> Make sure that the PG_USER_SUPPLY_VOLT [mV] voltage is enough for the clock frequency chosen.
			#endif
		#endif
	#endif
#endif


