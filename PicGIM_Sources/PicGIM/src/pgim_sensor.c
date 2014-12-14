//
// pgim_sensor.c
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

/*!		\file			pgim_sensor.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			It configures and manages the SENSOR module
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_SENSOR == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	//il modulo adc deve gia' essere configurato

	//---[ Sensor Adc Ref ]---
	#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
		_pg_float	pg_sensor_volt_adc_ref( _pg_float volt_stable_ref ) {
			//--------------------------------------------------------------------
			//Connect the analog input selected in pgim_sensor_setup_public.h to a stable voltage reference "volt_ref".
			//Such as for example 2.5V by a TL431 powered between VDD and GND.
			//volt_ad_ref = ( ( volt_stable_ref * PG_ADC_RES_STEPS ) / pg_adc_get( ) );
			//i.e.: 5 = ( ( 2.5 * 1024 ) / 512 )	
			//If volt_ad_ref used by AD MODULE is Vdd, it returns the power supply voltage value.
			
			// Parameter "volt_stable_ref" value check
			if( volt_stable_ref > PG_USER_SUPPLY ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH , PG_ERROR_CRITICAL );
				#endif
				return PG_NOK;
			}
			if( ( volt_stable_ref < 0 ) || ( volt_stable_ref = 0 ) ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW , PG_ERROR_CRITICAL );
				#endif
				return PG_NOK;
			}

			pg_adc_start( PGIM_SENSOR_ADC_REF_CH );
			
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_ADC_REF_ERROR_OK , PG_ERROR_OK );
			#endif
			
			return( ( volt_stable_ref * PG_ADC_RES_STEPS ) / pg_adc_get( ) );	
		}
	#endif
	//---[ END Sensor Adc Ref ]---

	//---[ Sensor Ntc ]---
	#if ( PGIM_SENSOR_NTC == PG_ENABLE )
		
		_pg_float	pg_sensor_ntc( _pg_Uint8 ad_channel ) {
			//--------------------------------------------------------------------
			//Working in Celsius. If in Fahrenheit, must convert! (next release con modulo pg_conversion)
			//Fahrenheit -> Celsius 	°C = (°F - 32) / 1,8
			//Celsius -> Fahrenheit 	°F = °C × 1,8 + 32
		
			_pg_float	Ntc_Res, Ntc_Volt;
			_pg_Uint32	Ad_Measure_Accumulator = 0;
			_pg_Uint8	Ad_Measure_Avg_Index;

			//Acquisition and calculating average
			for ( Ad_Measure_Avg_Index = 0; Ad_Measure_Avg_Index < PGIM_SENSOR_NTC_AD_AVERAGE; Ad_Measure_Avg_Index++ ) {
				pg_adc_start( ad_Channel );	//Chiamare ogni volta prima di pg_adc_get( )
				
				//Acquired value control for condition sensor check
				if( pg_adc_get( ) >= ( PG_ADC_RES_STEPS - PGIM_SENSOR_NTC_AD_ROW_GUARD_MAX ) ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_UNPLUGGED , PG_ERROR_CRITICAL );
						//stampare su std_err "Sensore sul canale ad_channel scollegato" (come identifico il sensore?)
					#endif
					return PG_NOK;
				}
				if( ( pg_adc_get( ) <= PGIM_SENSOR_NTC_AD_ROW_GUARD_MIN) ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_SHORTED , PG_ERROR_CRITICAL );
						//stampare su std_err "Sensore sul canale ad_channel in corto" (come identifico il sensore?)
					#endif
					return PG_NOK;
				}
				
				Ad_Measure_Accumulator += pg_adc_get( );
			}
			Ad_Measure_Accumulator /= PGIM_SENSOR_NTC_AD_AVERAGE;
			
			//Calculation of ntc voltage
			Ntc_Volt = ( PG_USER_SUPPLY * Ad_Measure_Accumulator / ADC_RESOLUTION );
			
			//Calculating ntc resistance value
			Ntc_Res = ( ( Ntc_Volt * PGIM_SENSOR_NTC_PULLUP_RESISTOR ) / ( PG_USER_SUPPLY - Ntc_Volt ) );
			
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_SENSOR , PG_SENSOR_NTC_ERROR_OK , PG_ERROR_OK );
			#endif
			
			#if ( PGIM_SENSOR_NTC_CALCULATION_METHOD == PG_SENSOR_METHOD_BETA )
				//Returns with BETA
				// 1/T = (1/T0) + (1/B)*ln(R/R0)  =>  T = 1 / ( (1/T0) + ( (1/B)*ln(R/R0) ) )	//ln = logaritmo NATURALE (log() in C)!
				//return( (_pg_int16)( ( 1.0 / ( ( 1.0 / NTC_T_ZERO ) + ( ( 1.0 / Ntc_Beta ) * log( Ntc_Res / NTC_R_ZERO ) ) ) ) - NTC_KELVIN_CONST ) );
				return( ( ( 1.0 / ( ( 1.0 / PGIM_SENSOR_NTC_TEMP_REF + PG_CONSTANTS_KELVIN_CONST ) + ( ( 1.0 / PGIM_SENSOR_NTC_BETA ) * log( Ntc_Res / PGIM_SENSOR_NTC_RES_REF ) ) ) ) - PG_CONSTANTS_KELVIN_CONST ) );	// Returns in degrees Celsius
			#endif
			
			#if ( PGIM_SENSOR_NTC_CALCULATION_METHOD == PG_SENSOR_METHOD_COEF )
				//Returns with coefficients A, B, C
				//(_pg_int16)( ( 1.0 / ( a + ( b * ( log R ) ) + ( c * log ( R ) * log ( R ) * log ( R ) ) ) ) - 273.15 )
				return ( ( 1.0 / ( PGIM_SENSOR_NTC_COEF_A + ( PGIM_SENSOR_NTC_COEF_B * ( log ( Ntc_Res ) ) ) + ( PGIM_SENSOR_NTC_COEF_C * log ( Ntc_Res ) * log ( Ntc_Res ) * log ( Ntc_Res ) ) ) ) - PG_CONSTANTS_KELVIN_CONST );	// Returns in degrees Celsius
			#endif
		}
	#endif
	//---[ END Sensor Ntc ]---		
	
	
#endif

/*
_pg_int16	Read_Ntc_Temperature( _pg_Uint8 ADChannel , _pg_int16 Ntc_Beta ) {								//AD_CHANNEL_PANEL, AD_CHANNEL_TANK, AD_CHANNEL_AMB   //PG_CH_0 = Panel; PG_CH_1 = Tank; PG_CH_2 = Ambient
	//--------------------------------------------------------------------
	_pg_float	Ntc_Res, Ntc_Volt;
	//_pg_Uint16	Adc_Get_Sample[ ADC_GET_AVERAGE ];
	_pg_Uint32	Adc_Get_Accumulator = 0;
	_pg_Uint8	Avg_Index;

	//Acquisisco ADC_GET_AVERAGE campioni, sommandoli tra di loro e poi dividendo per il loro numero ADC_GET_AVERAGE
	for ( Avg_Index = 0; Avg_Index < ADC_GET_AVERAGE; Avg_Index++ ) {
		pg_adc_start( ADChannel );	//Chiamare ogni volta prima di pg_adc_get( )
		Adc_Get_Accumulator += pg_adc_get( );
	}
	Adc_Get_Accumulator /= ADC_GET_AVERAGE;
	
	//Ntc_Volt = ( PWR_SUPPLY_VDD * pg_adc_get( ) / ADC_RESOLUTION );
	Ntc_Volt = ( PWR_SUPPLY_VDD * Adc_Get_Accumulator / ADC_RESOLUTION );
	Ntc_Res = ( ( Ntc_Volt * PULLUP_NTC_R1 ) / ( PWR_SUPPLY_VDD - Ntc_Volt ) );
	
	//Return with BETA
	// 1/T = (1/T0) + (1/B)*ln(R/R0)  =>  T = 1 / ( (1/T0) + ( (1/B)*ln(R/R0) ) )	//logaritmo NATURALE !
	return( (_pg_int16)( ( 1.0 / ( ( 1.0 / NTC_T_ZERO ) + ( ( 1.0 / Ntc_Beta ) * log( Ntc_Res / NTC_R_ZERO ) ) ) ) - NTC_KELVIN_CONST ) );
	
	//Return with a,b,c (formula verificata, ma a,b,c sono ancora fisse sotto define)
	//(_pg_int16)( ( 1.0 / ( a + ( b * ( log R ) ) + ( c * log ( R ) * log ( R ) * log ( R ) ) ) ) - 273.15 )
	//return (_pg_int16)( ( 1.0 / ( NTC_A + ( NTC_B * ( log ( Ntc_Res ) ) ) + ( NTC_C * log ( Ntc_Res ) * log ( Ntc_Res ) * log ( Ntc_Res ) ) ) ) - NTC_KELVIN_CONST );
} 
*/