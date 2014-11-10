//
// pgim_18f2320_public.h
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

/*!		\file			pgim_18f2320_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_18F2320_PUBLIC_H_
	#define _PGIM_18F2320_PUBLIC_H_

	#ifdef	_GIM_H_
		#ifdef _PGIM_18F2320_PRIVATE_H_
		
			/** CONFIGURATION **************************************************/
			
			//---[ Fuses ]---
			#if	( PG_USE_INTERNAL_OSC == PG_DISABLE )
				#pragma	config OSC		= HSPLL  				// Used only with external oscillator
			#endif
			
			#pragma config FSCM			= OFF
			#pragma config IESO			= OFF
			#pragma config PWRT			= OFF
			#pragma config BOR			= ON
			#pragma config BORV			= 20
			#pragma config WDT			= OFF
			#pragma config WDTPS		= 32768
			#pragma config MCLRE		= ON
			#pragma config PBAD			= DIG
			#pragma config CCP2MX		= C1
			#pragma config STVR			= ON
			#pragma config LVP			= OFF
			#pragma config DEBUG		= OFF
			#pragma config CP0			= OFF
			#pragma config CP1			= OFF
			#pragma config CP2			= OFF
			#pragma config CP3			= OFF
			#pragma config CPB			= OFF
			#pragma config WRT0			= OFF
			#pragma config WRT1			= OFF
			#pragma config WRT2			= OFF
			#pragma config WRT3			= OFF
			#pragma config WRTB			= OFF
			#pragma config WRTC			= OFF
			#pragma config WRTD			= OFF
			#pragma config EBTR0		= OFF
			#pragma config EBTR1		= OFF
			#pragma config EBTR2		= OFF
			#pragma config EBTR3		= OFF
			#pragma config EBTRB		= OFF
			//---[ ENDFuses ]---
			
			/*******************************************************************/

			#if ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE PG_HS_SUGG All fuses are set as you want.
			#endif
		#else
			#warning	PG_HS_PG PG_HS_CORE This file is not for a direct include!
		#endif
	#endif
#endif /* _PGIM_18F2320_PUBLIC_H_ */
