/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ssp_setup_public.h
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
		\file		pgim_ssp_setup_public.h
		\version	0.5-0
		\date		2002 - 2017
		\brief		Simple Serial Protocol
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_SSP_SETUP_PUBLIC_H_
	#define _PGIM_SSP_SETUP_PUBLIC_H_

	#if ( PGIM_SSP == PG_ENABLE )
		//-------------------------------------------------------------------------------------------------------------
		//		R X   M O D E
		//-------------------------------------------------------------------------------------------------------------
		#define PG_SSP_RX_MODE							PG_BLOCKING		//!< Must be: PG_BLOCKING  ||  PG_NOT_BLOCKING

		//-------------------------------------------------------------------------------------------------------------
		//		R X   D E L A Y			( Mandatory minimum reply rx waiting time )
		//-------------------------------------------------------------------------------------------------------------
		#define PG_SSP_RXDELAY							100					//!< Max. 256[ms]; DO NOT SET TOO LOW!

		//-------------------------------------------------------------------------------------------------------------
		//		R X   T I M E O U T		( Used only in NOT BLOCKING RX MODE )
		//-------------------------------------------------------------------------------------------------------------
		#define PG_SSP_RXTIMEOUT						10000				//!< Min. 1[ms] - Max. 60000[ms]

		//-------------------------------------------------------------------------------------------------------------
		//		C R C
		//-------------------------------------------------------------------------------------------------------------
		#define	PG_SSP_CRC_ENABLE						PG_ENABLE			//!< Must be: PG_ENABLE  ||  PG_DISABLE
		
		//-------------------------------------------------------------------------------------------------------------
		//		C R Y P T
		//-----------------------------------------------------------------------------------------------------------
		//#define	PG_SSP_CRYPT_ENABLE					PG_DISABLE			//!< Must be: PG_ENABLE  ||  PG_DISABLE

	#endif
#endif


