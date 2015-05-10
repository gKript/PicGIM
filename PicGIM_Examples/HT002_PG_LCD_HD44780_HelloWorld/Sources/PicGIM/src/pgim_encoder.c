/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_encoder.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_encoder.h

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
		\file		pgim_encoder.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To drive a Gk encoder.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#include "picgim.h"

#if ( PGIM_ENCODER == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	_pg_int8 pg_encoder_button;
	_pg_int8 pg_encoder_direction;
//	_pg_int8 pg_encoder_intensity = 0;


	void pg_encoder_init( void ) {
		PG_ENCODER_STEP_TRIS = PG_IN;
		PG_ENCODER_DIR_TRIS = PG_IN;
		PG_ENCODER_SW_TRIS = PG_IN;
		pg_encoder_button = PG_NO;
		pg_encoder_direction = PG_ENCODER_UNK;
	}


	_pg_int8	pg_encoder_get_direction( void ) {
		pg_encoder_direction = 	PG_ENCODER_DIR;
	}


	void pg_encoder_start_end_pulse_block( ) {
		while( ! PG_ENCODER_STEP );
		pg_delay_msec( DELAY_AR );
		while( PG_ENCODER_STEP );
	}


	_pg_Uint8 pg_encoder_start_end_pulse_non_block( ) {
		if ( PG_ENCODER_STEP ) {
			pg_delay_msec( DELAY_AR );
			while( PG_ENCODER_STEP );
			return PG_ENCODER_EVENT_OCCURRED;
		}
		return PG_NONE;
	}


	/*
	if ( pg_encoder_button == PG_YES )	pulsante premuto
	if ( pg_encoder_intensity > 0 )	encoder girato di "pg_encoder_intensity" step e "pg_encoder_direction" direzione
	ENC_CW;ENC_CCW; [GLOBALI]=> pg_encoder_direction; pg_encoder_intensity;
	*/
	_pg_int8	pg_encoder_pulse( void ) {
//		_pg_Uint16 t = 0 , vel = 0;
//		_pg_int8 res = 0;
		pg_encoder_button = PG_NO;
		pg_encoder_direction = PG_ENCODER_UNK;
		pg_delay_msec( DELAY_AR );
		while ( ! PG_ENCODER_STEP ) {
			if( PG_ENCODER_SW ) {
				pg_encoder_button = PG_YES;
				return PG_ENCODER_PRESSED;
			}
		}
		pg_delay_msec( DELAY_AR );
		pg_encoder_direction = PG_ENCODER_DIR;
//		#if ( PG_ENCODER_INTENSITY == PG_ENABLE )
//			for ( t = 0 ; t < ITERATION ; t++ ) {
//				if ( enc_start_end_pulse_non_block( ) )
//					vel++;
//			}
//			if ( vel <= ENC_DELAY_2 )
//				res = 1;
//			if ( vel > ENC_DELAY_2 )
//				res = 2;
//			if ( vel > ENC_DELAY_3 )
//				res = 3;
//			if ( vel > ENC_DELAY_4 )
//				if ( vel > ENC_DELAY_4 )
//					res = 4;
//			pg_encoder_intensity = res;
//			return( res );
//		#else
//			pg_encoder_intensity = PG_YES;
			return( pg_encoder_direction );
//		#endif
	}
#endif


