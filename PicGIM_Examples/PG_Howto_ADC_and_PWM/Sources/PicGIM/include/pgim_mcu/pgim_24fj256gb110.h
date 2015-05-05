//
// pgim_24fj256gb110.h
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

/*!		\file			pgim_24fj256gb110.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_24FJ256GB110_PRIVATE_H_
	#define _PGIM_24FJ256GB110_PRIVATE_H_

	//---[ Internal Oscillator ]---
	#if ( PG_USE_INTERNAL_OSC == PG_ENABLE )
		#ifdef _GIM_H_
			#pragma	config //todo							//!< Internal oscillator, port function on RA6, EC (External Clock) used by USB
		#endif
		#undef	PG_CLOCK
		#define	PG_CLOCK 32.000 //todo						//!< Re-define new oscillator frequency
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using INTERNAL oscillator requested by user ( PG_CLOCK [MHz] )
		#endif
	#else
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using EXTERNAL oscillator configured by user ( PG_CLOCK [MHz] )
		#endif
	#endif
	//---[ END Internal Oscillator ]---
	
	
	//---[ Public ]---
	#include ".\pgim_mcu\pgim_24fj256gb110_public.h"
	//---[ END Public ]---

	
	//---[ Extended Instructions Set ]--- NOT SUPPORTED
	#if defined( __EXTENDED18__ )
		#error	PG_HS_PG This MCU don't support the Extended Instructions Set feature
	#endif
	//---[ END Extended Instructions Set ]---
	
	
	//---[ Hardware Resources ]---
	#define		PG_TCYCLEPERI				2					//!<	The number of cycles required for an instruction for the family PIC18
	#define		PG_MAX_OSC_FREQ				32.000				//!<	The maximum working frequency
	
	#define		PG_MAX_RAM					16384				//!<	The maximum amount of RAM
	#define		PG_MAX_EEPROM				0					//!<	If ( PG_MAX_EEPROM == 0 ) there is no EEPROM memory. The 24FJ256GB110 does NOT have eeprom.
	
	#define		PG_MCU_SUPPLY_VOLT_MAX		3.60				//!<	The maximum power supply voltage with regulator enabled
	#define		PG_MCU_SUPPLY_VOLT_MIN		2.20				//!<	The minimum power supply voltage with regulator enabled
	
	#define		PG_ADC_RES_BITS				10					//!<	ADC resolution bits
	#define		PG_ADC_RES_STEPS			1024				//!<	ADC resolution steps.
	
	#define		PG_PWM_1_MODE				PG_NONE				//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED - ( NOT YET SUPPORTED BY PICGIM )
	#define		PG_PWM_2_MODE				PG_NONE				//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED - ( NOT YET SUPPORTED BY PICGIM )
	#define		PG_PWM_FOSC_DIVIDER			2.000				//!<	Internal clock divider to drive timer
	//---[ END Hardware Resources ]---

#endif /* _PGIM_24FJ256GB110_PRIVATE_H_ */


