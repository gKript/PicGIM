//
// pgim_encoder.h
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

/*!		\file			pgim_encoder.h
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

#ifndef _PGIM_ENCODER_H_
	#define _PGIM_ENCODER_H_
	
	#if defined( __18CXX )
		#include <delays.h>
	#endif

	#if ( PGIM_ENCODER == PG_ENABLE )

		#define PG_ENCODER_GKPD

		#define	DELAY_AR				5
		#define	DELAY_OUT				40
		#define	ITERATION				7000

		#define	ENC_UNK					-1
		#define	ENC_CW					0
		#define	ENC_CCW					1

		#define	ENCODER_SW				( ! PG_ENCODER_SW )
		#define	ENCODER					( ENCODER_STEP  || ENCODER_DIR || ENCODER_SW )

		#define	ENC_DELAY_1				1
		#define	ENC_DELAY_2				3
		#define	ENC_DELAY_3				5
		#define	ENC_DELAY_4				7


		extern	_pg_int8				pg_encoder_direction;


		void		pg_encoder_start_end_pulse_block		( void );
		_pg_Uint8	pg_encoder_start_end_pulse_non_block	( void );
		_pg_int8	pg_encoder_pulse						( void );

	#endif	
#endif /* _PGIM_ENCODER_H_ */

/*
	\page	HWG_encoder		Encoder



	\attention	Here a link to the file : \ref pgim_encoder.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/
