/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f14k22_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f14k22.h

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
		\file		pgim_18f14k22_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The public configuration file for the 18F4620 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_18F14K22_PUBLIC_H_
	#define _PGIM_18F14K22_PUBLIC_H_

	#ifdef	_GIM_H_
		#ifdef _PGIM_18F14K22_PRIVATE_H_
		
			/** CONFIGURATION **************************************************/
			
			//---[ Fuses ]---
			#if ( PG_USE_INTERNAL_OSC == PG_DISABLE )
				#pragma config FOSC				= ECH  		// Used only with external oscillator
			#endif
			PLLEN = ON
			

			#pragma config RETEN				= OFF
			#pragma config SOSCEL				= HIGH		//SOSCSEL
			#pragma config XINST				= ON
			#pragma config PLLCFG				= ON
			#pragma config PRCKEN				= ON
			#pragma config FCMEN				= OFF
			#pragma config IESO					= OFF
			#pragma config PWRTEN				= ON
			#pragma config BOREN				= OFF
			#pragma config BORV					= 3
			#pragma config BORPWR				= MEDIUM
			#pragma config WDTEN				= OFF
			#pragma config WDTPS				= 4096
			#pragma config RTCOSC				= INTOSCREF
			#pragma config EASHFT				= OFF
			#pragma config ABW					= MM
			#pragma config BW					= 8
			#pragma config WAIT					= ON
			#pragma config CCP2MX				= PORTBE
			#pragma config ECCPMX				= PORTH
			#pragma config MSSPMSK				= MSK5
			#pragma config MCLRE				= ON
			#pragma config STVREN				= OFF
			#pragma config BBSIZ0				= BB1K
			#pragma config CP0					= OFF
			#pragma config CP1					= OFF
			#pragma config CP2					= OFF
			#pragma config CP3					= OFF
			#pragma config CP4					= OFF
			#pragma config CP5					= OFF
			#pragma config CP6					= OFF
			#pragma config CP7					= OFF
			#pragma config CPB					= OFF
			#pragma config CPD					= OFF
			#pragma config WRT0					= OFF
			#pragma config WRT1					= OFF
			#pragma config WRT2					= OFF
			#pragma config WRT3					= OFF
			#pragma config WRT4					= OFF
			#pragma config WRT5					= OFF
			#pragma config WRT6					= OFF
			#pragma config WRT7					= OFF
			#pragma config WRTC					= OFF
			#pragma config WRTB					= OFF
			#pragma config WRTD					= OFF
			#pragma config EBRT0				= OFF
			#pragma config EBRT1				= OFF
			#pragma config EBRT2				= OFF
			#pragma config EBRT3				= OFF
			#pragma config EBRT4				= OFF
			#pragma config EBRT5				= OFF
			#pragma config EBRT6				= OFF
			#pragma config EBRT7				= OFF
			#pragma config EBRTB				= OFF
			//---[ ENDFuses ]---

			/*******************************************************************/

			#if ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Hint >>> All fuses are set as you want.
			#endif
		#else
			#warning	PicGIM >>> Core >>> This file is not for a direct include!
		#endif
	#endif
#endif /* _PGIM_18F14K22_PUBLIC_H_ */


