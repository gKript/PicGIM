//
// pgim_adc.c
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

/*!		\file			pgim_adc.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			It configures and manages the ADC module, calculating and setting the necessary parameters.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_AD_CONVERTER == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	_pg_int16	pg_adc_user_scale_min;
	_pg_int16	pg_adc_user_scale_max;


	void pg_adc_init( void ) {
		pg_adc_set( PG_FOSC_PARAM , PG_FOSC_16 );
		pg_adc_set( PG_TAD_PARAM , PG_TAD_16 );
		pg_adc_set( PG_JUSTIFICATION_PARAM , PG_JUSTIFIED_RIGHT );
		pg_adc_user_scale_min = 0;
		pg_adc_user_scale_max = pow( 2 , PG_ADC_RES_BITS ) - 1 ;
	}

	
	void pg_adc_set( _pg_Uint8 parameter , _pg_Uint8 value ) {
		switch( parameter ) {
			case PG_ANALOG_CHANNELS_PARAM:
			{
				ADCON1 |= PG_ANALOG_CHANNELS_MASK;
				ADCON1 &= ( PG_ANALOG_CHANNELS_MASK & (_pg_Uint8)( 16 - ( value ) ) );
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_FOSC_PARAM:
			{
				ADCON2 |= PG_FOSC_MASK;
				ADCON2 &= value;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_TAD_PARAM:
			{
				ADCON2 |= PG_TAD_MASK;
				ADCON2 &= value;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_JUSTIFICATION_PARAM:
			{
				ADCON2bits.ADFM = value ;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_ADC_MODULE:
			{
				ADCON0bits.ADON = value ;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_USER_SCALE_MIN:
			{
				pg_adc_user_scale_min = value ;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			case PG_USER_SCALE_MAX:
			{
				pg_adc_user_scale_max = value ;
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
				#endif
				break;
			}
			default : {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_ADC_ERROR , PG_ERROR_WARNING );
				#endif
			}
		}
	}


	_pg_Uint16 pg_adc_start( _pg_Uint8 channel ) {
		ADCON0 |= PG_CH_MASK;
		ADCON0 &= channel;
		ADCON0bits.GO = 1;
		if ( PIE1bits.ADIE == PG_DISABLE ) {
			while( ADCON0bits.GO );
		}
		return pg_adc_get();
	}


	_pg_Uint16 pg_adc_start_avg( _pg_Uint8 channel , _pg_Uint8 average ) {		// if ( PIE1bits.ADIE == PG_DISABLE ) ???
		_pg_Uint8 cont;
		_pg_Uint32 accumulator;
		_pg_int16 res;
		if ( average >= PG_MAX_AVERAGE ) {
			res = -1;
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_ADC , PG_ADC_ERROR_TOO_AVERAGE , PG_ERROR_CRITICAL );
			#endif
		}
		else {
			for( cont = 0 ; cont < average ; cont++ ) {
				accumulator += (_pg_Uint32)pg_adc_start( channel );
			}
			res = (_pg_Uint16)( accumulator / average );
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
			#endif
		}
		return res;
	}


	_pg_Uint16	pg_adc_get( void ) {
		_pg_Uint16_VAL	value_get;
		value_get.byte.HB = ADRESH;
		value_get.byte.LB = ADRESL;
		return value_get.Val;
	}


//	_pg_int16	pg_adc_get_user_scale( void ) {
//		long a , b , c , d;
//		a = pg_adc_user_scale_max - pg_adc_user_scale_min;
//		b = pg_adc_get() * a;
//		c = b / ( pow( 2 , PG_ADC_RES_BITS ) - 1 );
//		d = c + pg_adc_user_scale_min;
//		return d;
//	}


	_pg_int16	pg_adc_get_user_scale( void ) {
		return ( ( ( ( pg_adc_user_scale_max - pg_adc_user_scale_min ) / PG_ADC_RES_STEPS ) * pg_adc_get() ) + pg_adc_user_scale_min );
	}


//	_pg_Uint8	pg_adc_get_perc( void ) {
//		return ( ( 512 * 100 ) / ( pow( 2 , PG_ADC_RES_BITS ) - 1 ) );
//	}


	_pg_Uint8	pg_adc_get_perc( void ) {
		return ( ( 100 / PG_ADC_RES_STEPS ) * pg_adc_get() );
	}


	float	pg_adc_get_perc_f( void ) {
		return ( ( 100.0 / PG_ADC_RES_STEPS ) * pg_adc_get() );
	}


//	_pg_Uint16 pg_adc_acq_with_average( _pg_Uint8 channel , _pg_Uint8 average ) {
//		_pg_Uint8 cont;
//		_pg_Uint16_VAL	value_get;
//		_pg_Uint32 somma;
//		_pg_int16 res;
//		if ( average >= PG_MAX_AVERAGE ) {
//			res = -1;
//			#if PG_ERROR_IS_ENABLE
//				pg_error_set( PG_ERROR_ADC , PG_ADC_ERROR_TOO_AVERAGE , PG_ERROR_CRITICAL );
//			#endif
//		}
//		else {
//			for( cont = 0 ; cont < average ; cont++ ) {
//				ADCON0 |= PG_CH_MASK;
//				ADCON0 &= channel;
//				ADCON0bits.GO = 1;
//				while( ADCON0bits.GO ) ;
//				value_get.byte.HB = ADRESH;
//				value_get.byte.LB = ADRESL;
//				somma += (_pg_Uint32)value_get.Val & 0x00ff ;
//			}
//			res = (_pg_Uint32)(somma / average);
//			#if PG_ERROR_IS_ENABLE
//				pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
//			#endif
//		}
//		return res;
//	}
	
#endif


