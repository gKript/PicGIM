/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_sensor.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_sensor.h

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
		\file		pgim_sensor.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		It configures and manages the SENSOR module
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/



#include "picgim.h"

#if ( PGIM_SENSOR == PG_ENABLE )

	//Working only in Celsius degees. If required Fahrenheit, must convert by pg_conversion module in next release.
	//AD_CONVERTER module must be already configured.
	
	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
		_pg_float	pg_sensor_adc_ref_volt_measured;
	#endif
	
	#if ( PGIM_SENSOR_NTC == PG_ENABLE )
		_pg_float	pg_sensor_ntc_tempc_measured;
	#endif

	//---[ Sensor Adc Ref ]---
	#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
		_pg_float	pg_sensor_adc_ref( void ) {
			//--------------------------------------------------------------------
			//Connect the analog input selected in pgim_sensor_setup_public.h to a stable voltage reference "volt_ref".
			//Such as for example 2.5V by a TL431 powered between VDD and GND.
			//volt_ad_ref = ( ( PGIM_SENSOR_ADC_REF_VOLT * PG_ADC_RES_STEPS ) / pg_adc_get( ) );
			//i.e.: 5 = ( ( 2.5 * 1024 ) / 512 )	
			//If volt_ad_ref used by AD MODULE is Vdd, it returns the power supply voltage value.
			pg_adc_start( PGIM_SENSOR_ADC_REF_CH );

			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_ADC_REF_ERROR_OK , PG_ERROR_OK );
			#endif

			pg_sensor_adc_ref_volt_measured = ( ( PGIM_SENSOR_ADC_REF_VOLT * PG_ADC_RES_STEPS ) / pg_adc_get( ) );
			return( pg_sensor_adc_ref_volt_measured );	
		}
	#endif
	//---[ END Sensor Adc Ref ]---

	//---[ Sensor Ntc ]---
	#if ( PGIM_SENSOR_NTC == PG_ENABLE )
		_pg_float	pg_sensor_ntc( _pg_Uint8 ad_channel ) {
			//--------------------------------------------------------------------
			_pg_float	Ntc_Res, Ntc_Volt, Supply_Volt;
			_pg_Uint32	Ad_Measure_Accumulator = 0;
			_pg_Uint8	Ad_Measure_Avg_Index;
			
			//Power supply voltage selection
			#if ( ( PGIM_SENSOR_ADC_REF == ENABLE ) && ( PGIM_SENSOR_NTC_USE_ADCREF == PG_YES ) )
				Supply_Volt = pg_sensor_adc_ref();
			#else
				Supply_Volt = PG_USER_SUPPLY_VOLT;
			#endif
				
			Ad_Measure_Accumulator = pg_adc_start_avg( ad_channel , PGIM_SENSOR_NTC_AD_AVERAGE );
			
			#if PG_ERROR_IS_ENABLE
				if( pg_adc_get( ) >= ( PG_ADC_RES_STEPS - PGIM_SENSOR_NTC_AD_ROW_GUARD_MAX ) ) {
						pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_UNPLUGGED , PG_ERROR_CRITICAL );
						//Show error "Sensor on the #ad_channel disconnected!" (Identify the sensor)
				}
				if( ( pg_adc_get( ) <= PGIM_SENSOR_NTC_AD_ROW_GUARD_MIN) ) {
						pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_SHORTED , PG_ERROR_CRITICAL );
						//Show error "Sensor on the #ad_channel in short-circuit!" (Identify the sensor)
				}
			#endif

			//Calculation of ntc voltage
			Ntc_Volt = ( Supply_Volt * Ad_Measure_Accumulator / PG_ADC_RES_STEPS );
			
			//Calculation of ntc resistance value
			Ntc_Res = ( ( Ntc_Volt * PGIM_SENSOR_NTC_HIGH_RESISTOR ) / ( Supply_Volt - Ntc_Volt ) );
			
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_OK , PG_ERROR_OK );
			#endif
			
			#if ( PGIM_SENSOR_NTC_CALCULATION_METHOD == PG_SENSOR_METHOD_BETA )
				//Using BETA
				// 1/T = (1/T0) + (1/B)*ln(R/R0)  =>  T = 1 / ( (1/T0) + ( (1/B)*ln(R/R0) ) )	//ln = logaritmo NATURALE (log() in C)!
				//return( (_pg_int16)( ( 1.0 / ( ( 1.0 / NTC_T_ZERO ) + ( ( 1.0 / Ntc_Beta ) * log( Ntc_Res / NTC_R_ZERO ) ) ) ) - NTC_KELVIN_CONST ) ); 
				// Result of the calculation in Celsius degrees
				pg_sensor_ntc_tempc_measured = ( ( 1.0 / ( ( 1.0 / ( PGIM_SENSOR_NTC_TEMP_REF + PG_CONSTANTS_KELVIN_CONST ) ) + ( ( 1.0 / PGIM_SENSOR_NTC_BETA ) * log ( Ntc_Res / PGIM_SENSOR_NTC_RES_REF ) ) ) ) - PG_CONSTANTS_KELVIN_CONST );
			#endif
			#if ( PGIM_SENSOR_NTC_CALCULATION_METHOD == PG_SENSOR_METHOD_COEF )
				//Using "A", "B", "C" coefficients
				//(_pg_int16)( ( 1.0 / ( a + ( b * ( log R ) ) + ( c * log ( R ) * log ( R ) * log ( R ) ) ) ) - 273.15 )
				// Result of the calculation in Celsius degrees 
				pg_sensor_ntc_tempc_measured = ( ( 1.0 / ( PGIM_SENSOR_NTC_COEF_A + ( PGIM_SENSOR_NTC_COEF_B * ( log ( Ntc_Res ) ) ) + ( PGIM_SENSOR_NTC_COEF_C * log ( Ntc_Res ) * log ( Ntc_Res ) * log ( Ntc_Res ) ) ) ) + PG_CONSTANTS_KELVIN_CONST );
			#endif
			return( pg_sensor_ntc_tempc_measured );	// Returns in Celsius degrees 
		}
	#endif
	//---[ END Sensor Ntc ]---		
#endif


