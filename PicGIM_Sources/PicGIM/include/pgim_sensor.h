//
// pgim_sensor.h
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

/*!		\file			pgim_sensor.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			It configures and manages the SENSOR module.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_SENSOR_H_
	#define _PGIM_SENSOR_H_
		
	#if ( PGIM_SENSOR == PG_ENABLE )
	
		//---[ Errors ]---
			//---[ Errors Adc Ref]---
			#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
				#define	PG_SENSOR_ADC_REF_ERROR_OK					1			//!< No error. Correct value.
				#define	PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH		-1			//!< Reference voltage value too big.
				#define	PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW			-2			//!< Reference voltage value negative or zero.
			#endif
			//---[ End Errors Adc Ref]---
			
			//---[ Errors Ntc ]---
			#if ( PGIM_SENSOR_NTC == PG_ENABLE )
				#define	PG_SENSOR_NTC_ERROR_OK						2			//!< No error. Correct value.
				#define	PG_SENSOR_NTC_ERROR_UNPLUGGED				-11			//!< Unplugged sensor.
				#define	PG_SENSOR_NTC_ERROR_SHORTED					-12			//!< Shorted sensor.
			#endif
			//---[ End Errors Ntc ]---
		//---[ END Errors ]---
		
		//---[ Prototypes ]---
		extern	_pg_float	pg_sensor_adc_ref_measured;							//!< Variable containing the result of the function that measures the ADC-Ref sensor
		extern	_pg_float	pg_sensor_ntc_measured;								//!< Variable containing the result of the function that measures the NTC sensor
		
		/*!
			\brief			This function measures the value of the reference voltage of the AD converter.
			\param			\b volt_stable_ref : a stable voltage reference to measure by ADC MODULE. \n
			\return			A pointer to the value of the reference voltage of the AD converter.\n
							It also sets the following values in the ERROR MODULE(if enabled): \n
							\b PG_OK : if all value are right. \n
							\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH : if the reference voltage value is too big. \n
							\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW : if the reference voltage value is negative or zero. \n
			\note			This function can measure the supply voltage of the micro-controller. \n
							It is useful with battery powered device. \n
							It is able to perform his job because the AD-Module uses ALWAYS the Vdd as superior reference. \n
		*/
		_pg_float *			pg_sensor_adc_ref			( _pg_float volt_stable_ref );

		/*!
			\brief			This function measures the temperature value of an NTC sensor.
			\param			\b ad_channel : channel where is connected the ntc to measure on AD input. \n
							Must be specified in ad_converter style, like as PG_CH_0, PG_CH_1, PG_CH_2... \n
							This module will only execute the calls pg_adc_start() and pg_adc_get(). \n
			\return			A pointer to the value of temperature in Celsius degrees. \n
							It also sets the following values in the ERROR MODULE(if enabled): \n
							\b PG_OK : if all value are right. \n
							\b PG_SENSOR_NTC_ERROR_UNPLUGGED : if the sensor is unplugged. \n
							\b PG_SENSOR_NTC_ERROR_SHORTED : if the sensor is shorted. \n
							
		*/		
		_pg_float *			pg_sensor_ntc				( _pg_Uint8 ad_channel );

		//---[ END Prototypes ]---
	#endif	
#endif /* _PGIM_SENSOR_H_ */

/*!

	\page	HWE_sensor	Sensor

		\tableofcontents

		\image html	sensor.png

		This module is able to handle a multitude of sensors or similar equipment. \n
		It can be expanded to be able to control new devices. \n \n

		This module depends on the module AD_CONVERTER which must then be configured in function \n
		of the requests of the user (for example: the number of channels to be dedicated to the sensors). \n
		In the bottom of the page there is a code example to use.\n
		This module will only execute the AD_CONVERTER module calls: pg_adc_start() and pg_adc_get(). \n
		The name of the channel to be passed to functions must be in AD_CONVERTER style, \n
		like as \ref PG_CH_0 , \ref PG_CH_1 , \ref PG_CH_2 ... \n \n
			
		\section	SENSORmodconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\htmlonly
			In order to use this module, it must be enabled and configured in: \n
			\endhtmlonly
			\arg \b pgim_module_setup_public.h : the main management file for the modules inclusion in the project. \n
			\code
				#define PGIM_SENSOR					PG_ENABLE
			\endcode
			\htmlonly
			This define enables or disables the module.<br><br>
			It must be:<br>
			\endhtmlonly
			\arg \b PG_ENABLE : Sensor module enabled.
			\arg \b PG_DISABLE : Sensor module disabled.
			\n \n \n
			\arg \b pgim_sensor_setup_public.h : the management file for the sensor module configuration. \n
			\code
				#define PGIM_SENSOR_ADC_REF			PG_ENABLE
			\endcode
			\htmlonly
			This define enables or disables the sensor Volt AD Ref.<br><br>
			It must be:<br>
			\endhtmlonly
			\arg \b PG_ENABLE : Sensor enabled.
			\arg \b PG_DISABLE : Sensor disabled.
			\n \n
			In the same way are enabled and disabled all other sensors.
			\n \n \n 

		\section	SENSADREF		ADC Ref   (VDD measurement)
			\htmlonly <hr> \endhtmlonly
			This is not really a sensor. It simply acquires the value of a stable voltage via input of an AD converter. \n
			The acquired value, since it is stable, and then fixed, does not carry directly any information, \n
			but through it, the reference of the AD converter can be measured. \n
			For the module AD_CONVERTER, the Vref reference is the power supply voltage of the microcontroller, or VDD. \n
			It is therefore possible to measure the supply voltage of the pic, very useful in case of battery powered devices. \n \n
			
		\subsection	CSENSADREFch	ADC-Ref Channel
			\htmlonly
				The channel where to measure the reference voltage.<br>
			\endhtmlonly
			\code
				#define	PGIM_SENSOR_ADC_REF_CH				PG_CH_0	
			\endcode
			\htmlonly
			It must be the name of the channel used in the AD_CONVERTER module:<br>
			\endhtmlonly
			\arg \b PG_CH_0 : For the first AD channel
			\arg \b PG_CH_1 : For the second AD channel
			\arg \b PG_CH_2 : and so on...
					
			\subsection	CSENSADREF	ADC-Ref  Schematic
					\htmlonly
						An example of circuit schematic.<br>
					\endhtmlonly
					\image html	sensor_voltadref.png
					\htmlonly
					In this circuit schematic, for example, a 2.5V reference voltage is used. \n
					Of course, nothing prevents from using other values. \n
					It is important that the \b exact \b value of voltage generated is measured and written in the relative configuration file \n
					specified in the initial section of this module documentation. \n \n
					\endhtmlonly
			
			\subsection	CSENSADREFfunc	ADC-Ref Function
				\arg \b pg_sensor_adc_ref() : This function measures the value of the reference voltage of the AD converter. \n \n 
			
			\subsection	CSENSADREFcode1	AD-Ref Example code
				\code
					void main( void ) {
						float real_pic_vdd;
						pg_initialize();
						pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
						pg_adc_set( PG_ADC_MODULE , PG_ON );
						real_pic_vdd = * pg_sensor_adc_ref( 2.5 );
						PG_INFINITE_LOOP;
					}
				\endcode
				\n \n \n
			
		\section	SENSNTC		NTC 
			\htmlonly <hr> \endhtmlonly
			This sensor allows to measure the temperature via a resistor NTC connected as shown in the schematic. \n
			The values of the circuit components must be declared in the configuration files \ref pgim_sensor_setup_public.h \n \n
							
			\subsection	CSENSNTCresref		Ntc - Resistance 
				\htmlonly
					This define specifies the nominal value of the NTC resistance at the reference temperature.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_RES_REF				10000.0
				\endcode
				\htmlonly
					It must be expressed in [ohm].<br>
				\endhtmlonly
				
			\subsection	CSENSNTCtempref		Ntc - Temp ref
				\htmlonly
					This define specifies the reference temperature for the nominal value of NTC resistance.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_TEMP_REF			25.0
				\endcode
				\htmlonly
					It must be measured in Celsius degrees.<br>
				\endhtmlonly 

			\subsection	CSENSNTCbeta	Ntc - BETA constant
				\htmlonly
					This define specifies the ntc "BETA" constant.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_BETA 				3988
				\endcode
				\htmlonly
					The value is specified by the device manufacturer.<br>
				\endhtmlonly

			\subsection	CSENSNTCabc		Ntc - A B C coefficients
				\htmlonly
					These define specify the three coefficients that characterize the NTC.<br>
				\endhtmlonly
				\code
					#define PGIM_SENSOR_NTC_COEF_A				1.028444E-3
					#define PGIM_SENSOR_NTC_COEF_B				2.392435E-4
					#define PGIM_SENSOR_NTC_COEF_C				1.562216E-7
				\endcode
				\htmlonly
					The value is specified by the device manufacturer.<br>
				\endhtmlonly

			\subsection	CSENSNTCmethod		Ntc - Calculation method
				\htmlonly
					The temperature of the NTC can be calculated in two ways:
					through the constant BETA (calculation simpler, but less accurate)
					or by the three coefficients "A", "B", "C" (calculation slightly more complicated, but more precise ).<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_CALCULATION_METHOD	PG_SENSOR_METHOD_BETA
				\endcode
				\htmlonly
					It must be:<br>
				\endhtmlonly
				\arg \b	PG_SENSOR_METHOD_BETA : Calculations performed using the BETA constant.
				\arg \b PG_SENSOR_METHOD_COEF : Calculations performed using "A", "B", "C" coefficients.
				
			\subsection	CSENSNTChighr	Ntc - High resistor
				\htmlonly
					This define specifies he high side resitor exact value.<br>
					In the reference schematic, it is marked by R1 label.<br>
				\endhtmlonly
				\code
					#define PGIM_SENSOR_NTC_HIGH_RESISTOR		10002.0
				\endcode
				\htmlonly
					It must be expressed in [ohm].<br>
				\endhtmlonly
				
			\subsection	CSENSNTCavg		Ntc - average
				\htmlonly
					This define specifies the averages number of measurement.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_AVERAGE			10
				\endcode
				\htmlonly
					The number of measurements indicated is executed and then the average is calculated.<br>
				\endhtmlonly

			\subsection	CSENSNTCguardmin	Ntc - Guard row min
				\htmlonly
					This define specifies the guard limit on the minimum acquired row value.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_ROW_GUARD_MIN	5
				\endcode
				\htmlonly
					It is very useful to detect if the sensor is short-circuited.<br>
					Set a value not too high, so do not compromise the measurement.<br>
				\endhtmlonly
		
			\subsection	CSENSNTCguardmax	Ntc - Guard row max
				\htmlonly
					This define specifies the guard limit on the maximum acquired row value.<br>
				\endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_ROW_GUARD_MAX	50
				\endcode
				\htmlonly
					It is very useful to detect if the sensor is an open-circuit.<br>
					Set a value not too low, so do not compromise the measurement.<br>
				\endhtmlonly
				
			\subsection	CSENSNTCschem		Ntc - Schematic	
				Typology circuit to be used: \n
				\image html	sensor_ntc.png
		
			\subsection	CSENSNTCfunc	Ntc - Function
				\arg \b pg_sensor_ntc() : This function measures the temperature value of an NTC sensor. \n \n 
			\subsection CSENSNTCcode1	Ntc - Example code
				\code
					void main( void ) {
						float temperature;
						pg_initialize();
						pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
						pg_adc_set( PG_ADC_MODULE , PG_ON );
						temperature = * pg_sensor_ntc( PG_CH_0 );
						PG_INFINITE_LOOP;
					}
				\endcode
			
			\n \n \n
			
		\htmlonly <br><br> \endhtmlonly

*/

