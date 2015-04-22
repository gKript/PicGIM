/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_int_osc.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_int_osc.h

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
		\file		pgim_int_osc.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the internal oscillator.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public V3 license. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public V3 license. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/


#include "picgim.h"

#if	( PG_USE_INTERNAL_OSC == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif


	void	pg_internal_osc_init( void ) {

		//---[ 18F2320 ]---
		#ifdef	PGIM_P18F2320
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F2320 ]---
		
		
		//---[ 18F2550 ]---
		#ifdef	PGIM_P18F2550
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F2550 ]---
		
		
		//---[ 18F2553 ]---
		#ifdef	PGIM_P18F2553
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F2553 ]---
		
		
		//---[ 18F4520 ]---
		#ifdef	PGIM_P18F4520
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F4520 ]---
		
		
		//---[ 18F4550 ]---
		#ifdef	PGIM_P18F4550
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F4550 ]---
		
		
		//---[ 18F4553 ]---
		#ifdef	PGIM_P18F4553
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F4553 ]---
		
		
		//---[ 18F4620 ]---
		#ifdef	PGIM_P18F4620
			//OSCTUNEbits.PLLEN	=	1;							//!< Enable PLL with internal oscillator ( 8MHz x 4 = 32 MHz )
			OSCCONbits.IRCF2	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF1	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.IRCF0	=	1;							//!< IRCF<2-0> set frequency
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			//OSCCONbits.SCS0		=	x;
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F4620 ]---
		
		
		//---[ 18F97J60 ]---
		#ifdef	PGIM_P18F97J60
			OSCCONbits.SCS1		=	1;							//!< Select internal oscillator
			OSCCONbits.SCS0		=	1;							//!< Select internal oscillator
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 18F97J60 ]---
		
		
		//---[ 24FJ256GB110 ]---
		#ifdef	PGIM_P24FJ256GB110
			// todo
			#define	PG_INTERNAL_OSC_CONFIGURED
		#endif
		//---[ END 24FJ256GB110 ]---
		
		
		//---[ Fail ]---
		#ifndef	PG_INTERNAL_OSC_CONFIGURED
			#error	PG_HS_PG PG_HS_CORE Failed configuring INTERNAL oscillator
		#endif
		//---[ END Fail ]---
	}
#endif


