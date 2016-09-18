/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f4550_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f4550.h

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
		\file		pgim_18f4550_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The public configuration file for the 18F4550 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_18F4550_PUBLIC_H_
	#define _PGIM_18F4550_PUBLIC_H_
	
	#ifdef	_GIM_H_
		#ifdef _PGIM_18F4550_PRIVATE_H_

			/** CONFIGURATION **************************************************/

			#if ( PG_USE_INTERNAL_OSC == PG_DISABLE )
				#pragma	config FOSC			= ECPLLIO_EC//HSPLL_HS//HS//XT_XT//XTPLL_XT//EC_EC//XT_XT//ECPLLIO_EC  		//Used only with external oscillator
			#endif
						
			#pragma	config PLLDIV			= 10				// Used only with external oscillator
			#pragma	config CPUDIV			= OSC1_PLL2			// Used only with external oscillator
			#pragma	config USBDIV			= 2 				// Used only with external oscillator
			
			#pragma	config FCMEN			= OFF
			#pragma	config IESO				= OFF
			#pragma	config VREGEN			= OFF
			#pragma	config PWRT				= ON
			#pragma	config BOR				= ON
			#pragma	config BORV				= 2
			#pragma	config WDT				= OFF
			#pragma	config WDTPS			= 32768
			#pragma	config MCLRE			= ON
			#pragma	config LPT1OSC			= OFF
			#pragma	config PBADEN			= OFF
			#pragma	config CCP2MX			= ON 				//CCP2MX = OFF -> PWM2 output on RB3; CCP2MX = ON -> PWM2 output on RC1  
			#pragma	config STVREN			= OFF
			#pragma	config LVP				= OFF
			#pragma	config XINST			= OFF
			#pragma	config DEBUG			= OFF
			#pragma	config CP0				= OFF
			#pragma	config CP1				= OFF
			#pragma	config CP2				= OFF
			#pragma	config CP3				= OFF
			#pragma	config CPB				= OFF
			#pragma	config WRT0				= OFF
			#pragma	config WRT1				= OFF
			#pragma	config WRT2				= OFF
			#pragma	config WRT3				= OFF
			#pragma	config WRTB				= OFF
			#pragma	config WRTC				= OFF
			#pragma	config WRTD				= OFF
			#pragma	config EBTR0			= OFF
			#pragma	config EBTR1			= OFF
			#pragma	config EBTR2			= OFF
			#pragma	config EBTR3			= OFF
			#pragma	config EBTRB			= OFF
						
			/*******************************************************************/

			#warning	PicGIM >>> Core >>> Set fuses as you want.

		#else

			#warning	PicGIM >>> Core >>> This file is not for a direct include!
			
		#endif
	#endif
#endif /* _PGIM_18F4550_PUBLIC_H_ */



/*
PLLDIV = 1	No prescale (4 MHz oscillator input drives PLL directly)  
PLLDIV = 2	Divide by 2 (8 MHz oscillator input)  
PLLDIV = 3	Divide by 3 (12 MHz oscillator input)  
PLLDIV = 4	Divide by 4 (16 MHz oscillator input)  
PLLDIV = 5	Divide by 5 (20 MHz oscillator input)  
PLLDIV = 6	Divide by 6 (24 MHz oscillator input)  
PLLDIV = 10	Divide by 10 (40 MHz oscillator input)  
PLLDIV = 12	Divide by 12 (48 MHz oscillator input)  

CPU System Clock Postscaler:
CPUDIV = OSC1_PLL2	[OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]  
CPUDIV = OSC2_PLL3	[OSC1/OSC2 Src: /2][96 MHz PLL Src: /3]  
CPUDIV = OSC3_PLL4	[OSC1/OSC2 Src: /3][96 MHz PLL Src: /4]  
CPUDIV = OSC4_PLL6	[OSC1/OSC2 Src: /4][96 MHz PLL Src: /6]  

USB Clock Selection bit (used in Full Speed USB mode only; UCFG:FSEN = 1):
USBDIV = 1	USB clock source comes directly from the primary oscillator block with no postscale  
USBDIV = 2	USB clock source comes from the 96 MHz PLL divided by 2  

Oscillator Selection bits:
FOSC = XT_XT		XT oscillator, XT used by USB  
FOSC = XTPLL_XT		XT oscillator, PLL enabled, XT used by USB  
FOSC = ECIO_EC		External clock, port function on RA6, EC used by USB  
FOSC = EC_EC		External clock, CLKOUT on RA6, EC used by USB  
FOSC = ECPLLIO_EC	External clock, PLL enabled, port function on RA6, EC used by USB  
FOSC = ECPLL_EC		External clock, PLL enabled, CLKOUT on RA6, EC used by USB  
FOSC = INTOSCIO_EC	Internal oscillator, port function on RA6, EC used by USB  
FOSC = INTOSC_EC	Internal oscillator, CLKOUT on RA6, EC used by USB  
FOSC = INTOSC_XT	Internal oscillator, XT used by USB  
FOSC = INTOSC_HS	Internal oscillator, HS used by USB  
FOSC = HS			HS oscillator, HS used by USB  
FOSC = HSPLL_HS		HS oscillator, PLL enabled, HS used by USB  
*/


