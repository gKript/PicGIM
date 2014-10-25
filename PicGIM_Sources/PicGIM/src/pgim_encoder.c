//
// pgim_encoder.c
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

/*!		\file			pgim_encoder.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_ENCODER == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	#ifdef	PG_ENCODER_ABP
		_pg_int8	encoder_cw( void ) {
			_pg_int16 t;
			_pg_int16 vel;
			_pg_int8 res = 1;
			vel = 0;
			while( !PG_ENCODER_A  || !PG_ENCODER_B );
			for ( t = 0 ; t < ITERATION ; t++ ) {
				if ( ! PG_ENCODER_A ) {
					Delay1KTCYx( DELAY_AR );
					while( !PG_ENCODER_A  || !PG_ENCODER_B );
					vel++;
				}
			}
			if ( vel > ENC_DELAY_1 )
				res = 1;
			if ( vel > ENC_DELAY_2 )
				res = 2;
			if ( vel > ENC_DELAY_3 )
				res = 3;
			if ( vel > ENC_DELAY_4 )
				return 4;
			return res;
		}


		_pg_int8	encoder_ccw( void ) {
			_pg_int16 t;
			_pg_int16 vel;
			_pg_int8 res = 1;
			vel = 0;
			while( !PG_ENCODER_A  || !PG_ENCODER_B );
			for ( t = 0 ; t < ITERATION ; t++ ) {
				if ( ! PG_ENCODER_B ) {
					Delay1KTCYx( DELAY_AR );
					while( !PG_ENCODER_A  || !PG_ENCODER_B );
					vel++;
				}
			}
			while( !PG_ENCODER_A  || !PG_ENCODER_B );
			if ( vel > ENC_DELAY_1 )
				res = 1;
			if ( vel > ENC_DELAY_2 )
				res = 2;
			if ( vel > ENC_DELAY_3 )
				res = 3;
			if ( vel > ENC_DELAY_4 )
				return 4;
			return res;
		}
	#endif	

	#ifdef	PG_ENCODER_GKPD
		_pg_int8 pg_encoder_direction = ENC_UNK;

		
		void enc_start_end_pulse_block( ) {
			while( ! ENCODER_PULSE );
			Delay1KTCYx( DELAY_AR );
			while( ENCODER_PULSE );
		}

		
		_pg_Uint8 enc_start_end_pulse_non_block( ) {
			if ( ENCODER_PULSE ) {
				Delay1KTCYx( DELAY_AR );
				while( ENCODER_PULSE );
				return 1;
			}
			return 0;
		}

		
		_pg_Uint8	encoder_pulse( void ) {
			_pg_Uint16 t = 0 , vel = 0;
			_pg_Uint8 res = 0;
			while ( ! ENCODER_PULSE ) ;
			Delay1KTCYx( DELAY_AR );
			pg_encoder_direction = PG_ENCODER_DIR;
			#ifdef	PG_ENCODER_INTENSITY
				for ( t = 0 ; t < ITERATION ; t++ ) {
					if ( enc_start_end_pulse_non_block( ) )
						vel++;
				}
				if ( vel == 0 )
					res = 0;
				if ( vel <= ENC_DELAY_2 )
					res = 1;
				if ( vel > ENC_DELAY_2 )
					res = 2;
				if ( vel > ENC_DELAY_3 )
					res = 3;
				if ( vel > ENC_DELAY_4 )
					if ( vel > ENC_DELAY_4 )
						res = 4;
				return res;
			#elif	PG_ENCODER_NO_INTENSITY
				return 0;
			#endif
		}
	#endif
#endif


