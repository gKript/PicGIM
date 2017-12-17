/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_h32.h
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
		\file		pgim_h32.h
		\version	0.5-0
		\date		2002 - 2017
		\brief		Multiplatform random number generator
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_H32_H_
	#define _PGIM_H32_H_

	#if ( PGIM_H32 == PG_ENABLE )

		#define	 GKGKH32_MASK_AND		0b00001111000011110000111100001111
		#define	 GKGKH32_MASK_XOR		0b00011100011100011100011100011100
		#define	 GKGKH32_MASK_OR		0b00011000110001100011000110001100

		#define	 GKPRS_MASK_AND_A		0b00001111000011110000111100001111
		#define	 GKPRS_MASK_AND_B		0b11111111000000001111111100000000
		#define	 GKPRS_MASK_AND_C		0b01010101010101010101010101010101
		#define	 GKPRS_MASK_AND_D		0b00110011001100110011001100110011
		#define	 GKPRS_MASK_AND_E		0b00011100011100011100011100011100
		#define	 GKPRS_MASK_AND_F		0b00100100100100100100100100100100
		#define	 GKPRS_MASK_XOR_A		0b10100100010000100000100000010000
		#define	 GKPRS_MASK_XOR_B		0b01101101101101101101101101101101
		#define	 GKPRS_MASK_XOR_C		0b11011011110110111101101111011011
		#define	 GKPRS_MASK_XOR_D		0b00011000110001100011000110001100
		#define	 GKPRS_MASK_XOR_E		0b00001000010000100001000010000100
		#define	 GKPRS_MASK_XOR_F		0b11101110111011101110111011101111

		#define GKTWIST_TWIST(T,A,X,S)	T+=(((A&S)^X)|S)					//  T = Twist - A = MASK_AND - X = MASK_XOR - S = SEED  
		
		extern	_pg_Uint32	pg_h32_twisted;
		extern	_pg_Uint32	pg_h32_seed;
		extern	_pg_Uint32	pg_h32_sum; 
		extern	_pg_Uint8   pg_h32_rand; 
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/	
		_pg_Uint32		pg_h32_Hash32						( _pg_Uint8 * pass );
				
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/	
		void			pg_h32_prs_seed					( _pg_Uint32 seed );
				
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/	
		void			pg_h32_prs_twist					( void );
				
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/	
		_pg_Uint8		pg_h32_prs_rand8					( void );

	#endif
#endif
	
	
	