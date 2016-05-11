/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_adc.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_adc.h

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
		\file		pgim_adc.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		It configures and manages the ADC module, calculating and setting the necessary parameters.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if ( PGIM_AD_CONVERTER == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

//	_pg_int16	pg_adc_user_scale_min;
//	_pg_int16	pg_adc_user_scale_max;

	void pg_adc_init( void ) {
		pg_adc_set( PG_FOSC_PARAM , PG_FOSC_16 );
		pg_adc_set( PG_TAD_PARAM , PG_TAD_16 );
		pg_adc_set( PG_JUSTIFICATION_PARAM , PG_JUSTIFIED_RIGHT );
//		pg_adc_user_scale_min = 0;
//		pg_adc_user_scale_max = pow( 2 , PG_ADC_RES_BITS ) - 1 ;
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
//			case PG_USER_SCALE_MIN:
//			{
//				pg_adc_user_scale_min = value ;
//				#if PG_ERROR_IS_ENABLE
//					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
//				#endif
//				break;
//			}
//			case PG_USER_SCALE_MAX:
//			{
//				pg_adc_user_scale_max = value ;
//				#if PG_ERROR_IS_ENABLE
//					pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
//				#endif
//				break;
//			}
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

	#if ( PG_ADC_START_AVG___SC == PG_ENABLE )
		_pg_Uint16 pg_adc_start_avg( _pg_Uint8 channel , _pg_Uint8 average ) {		// if ( PIE1bits.ADIE == PG_DISABLE ) ???
			_pg_Uint8 cont;
			_pg_Uint32 accumulator = 0;
			_pg_Uint16 res;
			if ( PIE1bits.ADIE == PG_DISABLE ) {
				if ( average >= PG_MAX_AVERAGE ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_ADC , PG_ADC_ERROR_NO_AVERAGE , PG_ERROR_CRITICAL );
					#endif
				}
				else {
					for( cont = 0 ; cont < average ; cont++ ) {
						accumulator += pg_adc_start( channel );
					}
					res = ( accumulator / average );
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_ADC , PG_OK , PG_ERROR_OK );
					#endif
				}
				return res;
			}
			else {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_ADC , PG_ADC_ERROR_NO_AVERAGE , PG_ERROR_CRITICAL );
				#endif
				return pg_adc_start( channel );
			}
		}
	#endif
	
	_pg_Uint16	pg_adc_get( void ) {
		_pg_Uint16_VAL	value_get;
		value_get.byte.HB = ADRESH;
		value_get.byte.LB = ADRESL;
		return value_get.Val;
	}

	#if ( PG_ADC_GET_USER_SCALE___SC == PG_ENABLE )
		_pg_int16	pg_adc_get_user_scale( _pg_int16 Min , _pg_int16 Max ) {
			return (_pg_int16)( ( ( (float)( Max - Min ) / ( PG_ADC_RES_STEPS - 1 ) ) * pg_adc_get() ) + Min );
		}
	#endif
	
	#if ( PG_ADC_GET_PERC___SC == PG_ENABLE )
		_pg_Uint8	pg_adc_get_perc( void ) {
			return (_pg_Uint8)( ( 100.0 / ( PG_ADC_RES_STEPS - 1 ) * pg_adc_get() ) );
		}
	#endif
	
	#if ( PG_ADC_GET_PERC_F___SC == PG_ENABLE )
		float	pg_adc_get_perc_f( void ) {
			return (float)( ( 100.0 / ( PG_ADC_RES_STEPS - 1 ) ) * pg_adc_get() );
		}
	#endif
	
#endif

		
