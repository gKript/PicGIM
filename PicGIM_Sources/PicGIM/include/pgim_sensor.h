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
		#if ( PGIM_SENSOR_ADC_REF == PG_ENABLE )
			//---[ Error ADC-Ref ]---
			#define	PG_SENSOR_ADC_REF_ERROR_OK						1			//!< No error. Correct value.
			//#define	PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH		-1			//!< Reference voltage value too big.
			//#define	PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW			-2			//!< Reference voltage value negative or zero.
			//---[ End Errors ADC-Ref ]---
				
			//---[ Prototypes ADC-Ref ]---
			extern _pg_float	pg_sensor_adc_ref_volt_measured;							//!< ADC module measured voltage reference
			
			/*!
				\brief			This function measures the value of the reference voltage of the AD converter.
				
				\param			None. \n
				
				\return			A float value of the reference voltage of the AD converter.\n
								It also sets the following values in the ERROR MODULE(if enabled): \n
								\b PG_OK : if all value are right. \n
								
				\note			This function can measure the supply voltage of the micro-controller. \n
								It is useful with battery powered device. \n
								It is able to perform his job because the AD-Module uses ALWAYS the Vdd as superior reference. \n
			*/
			_pg_float			pg_sensor_adc_ref			( void );
			//---[ End Prototypes ADC-Ref ]---
		#endif

		#if ( PGIM_SENSOR_NTC == PG_ENABLE )
			//---[ Errors Ntc ]---
			#define	PG_SENSOR_NTC_ERROR_OK						2			//!< No error. Correct value.
			#define	PG_SENSOR_NTC_ERROR_UNPLUGGED				-11			//!< Unplugged sensor.
			#define	PG_SENSOR_NTC_ERROR_SHORTED					-12			//!< Shorted sensor.
			//---[ End Errors Ntc ]---
			
			//---[ Prototypes Ntc ]---
			extern	_pg_float	pg_sensor_ntc_tempc_measured;				//!< Celsius degree read by sensor
			
			/*!
				\brief			This function measures the temperature value of an NTC sensor.
				
				\param			ad_channel : channel where is connected the ntc to measure on AD input. \n
								Must be specified in ad_converter style, like as PG_CH_0, PG_CH_1, PG_CH_2... \n
								This module will only execute the calls pg_adc_start() and pg_adc_get(). \n
								
				\return			A foat value of temperature in Celsius degrees. \n
								It also sets the following values in the ERROR MODULE(if enabled): \n
								\b PG_OK : if all value are right. \n
								\b PG_SENSOR_NTC_ERROR_UNPLUGGED : if the sensor is unplugged. \n
								\b PG_SENSOR_NTC_ERROR_SHORTED : if the sensor is shorted. \n
								
			*/		
			_pg_float			pg_sensor_ntc				( _pg_Uint8 ad_channel );
			//---[ END Prototypes Ntc ]---
		#endif
	#endif	
#endif /* _PGIM_SENSOR_H_ */

/*!

	\page	HWE_sensor	Sensors

		\tableofcontents

		\image html	sensor.png

		The SENSOR module is able to handle a multitude of sensors or similar equipment. \n
		It can be expanded to be able to control new devices. \n \n

		This module depends on the module AD_CONVERTER which must then be configured in function \n
		of the requests of the user (for example: the number of channels to be dedicated to the sensors). \n
		In the bottom of the page there is a code example to use.\n
		This module will only execute the AD_CONVERTER module calls: pg_adc_start() and pg_adc_get(). \n
		The name of the channel to be passed to functions must be in AD_CONVERTER style, \n
		like as \ref PG_CH_0 , \ref PG_CH_1 , \ref PG_CH_2 ... \n \n
			
		\endcode
			\n \n \n
		
		\section	sensor_mod_conf	Module configuration
			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be included in the project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref sensor_moden  \n
					\n \n \n
				\arg \b pgim_sensor_setup_public.h : where are collected all the features of the module. \n
						Here are specified the possible values for the various parameters and when they have to be set depending on the chosen mode of operation of the module. \n \n
						After the enabling of module, each sensor must be enabled: \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref sensor_sensor_en \n \n
						and configured: \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref sensor_sensconf_adcref \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref sensor_sensconf_ntc \n
						\n \n \n &nbsp;&nbsp;&nbsp;&nbsp;

			\attention	For software reference, please read the documentation about \b pgim_sensor.h . \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>
			
  			\n \n \n
			\subsection	sensor_mod_en		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SENSOR							PG_ENABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Sensor module enabled.
					\arg \b PG_DISABLE : Sensor module disabled.
					\endcode

				\subsubsection	s_sensor_mod_en_ref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR \n
			
			\subsection	sensor_sens_en		Sensor enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SENSOR_ADC_REF				PG_ENABLE
					#define PGIM_SENSOR_NTC					PG_DISABLE
				\endcode
					This define enables or disables the sensors.<br>
				\htmlonly
					They must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Sensor enabled.
					\arg \b PG_DISABLE : Sensor disabled.
					\endcode

				\subsubsection	s_sensor_sens_en_ref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_ADC_REF \n
					\li \e Reference : \ref PGIM_SENSOR_NTC \n
				\n \n \n
				
		\section	sensor_adcref_conf		ADC-Ref sensor configuration	
			\htmlonly <hr> \endhtmlonly
			This is not really a sensor. It simply acquires the value of a stable voltage via input of an AD converter. \n
			The acquired value, since it is stable, and then fixed, does not carry directly any information, \n
			but through it, the reference of the AD converter can be measured. \n
			For the module AD_CONVERTER, the Vref reference is the power supply voltage of the microcontroller, or VDD. \n
			It is therefore possible to measure the supply voltage of the pic, very useful in case of battery powered devices. \n \n
			
			\subsection	sensor_adcref_ch		Channel selection
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_ADC_REF_CH					PG_CH_0
				\endcode	
					This define selects the analog input by which to measure the reference voltage. \n
					It must use the same define created for the ADC module.
					See ADC-Module documentation.
				\htmlonly
					<br><br>It must be:
				\endhtmlonly
					\arg \b PG_CH_0 : The first ADC-Module analog input channel.
					\arg \b PG_CH_1 : The second ADC-Module analog input channel.
					\arg \b PG_CH_2 : The third ADC-Module analog input channel.
				
				\htmlonly
					&nbsp;&nbsp;&nbsp;&nbsp;... and so on, for all available channels.<br>
				\endhtmlonly
			
				\subsubsection	s_sensor_adcref_ch		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_ADC_REF_CH \n
					\li \e Reference : \ref PG_CH_0 \n
							
			\subsection	sensor_adcref_volt		Reference voltage.
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_ADC_REF_VOLT				2.49
				\endcode	
					This define sets the reference voltage generated by the sensor ADC-Ref. \n
					It must be measured accurately (for example by a digital multimeter). \n
					The unit of measure by which it must be expressed is Volt [V].
				
				\subsubsection	s_sensor_adcref_volt		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_ADC_REF_VOLT \n

			\subsection	sensor_adcref_sch	Schematic
				\htmlonly <hr> \endhtmlonly
				In this circuit schematic, for example, a 2.5V reference voltage is used. \n
				Of course, nothing prevents from using other values. \n
				It is important that the \b exact \b value of voltage generated is measured and written in the relative configuration file \n
				specified in the initial section of this module documentation. \n \n
				An example of circuit schematic.
				\image html	sensor_voltadref.png

			\subsection	sensor_adcref_func	Public function
				\htmlonly <hr> \endhtmlonly
				\arg \b pg_sensor_adc_ref() : This function measures the value of the reference voltage of the AD converter. \n \n 

			\subsection	sensor_adcref_code		Example code
				\htmlonly <hr> \endhtmlonly
				\code
					void main( void ) {
						float real_pic_vdd;
						pg_initialize();
						pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
						pg_adc_set( PG_ADC_MODULE , PG_ON );
						real_pic_vdd = pg_sensor_adc_ref( );
						PG_INFINITE_LOOP;
					}
				\endcode
				\n \n \n
			
		\section	sensor_ntc_conf			NTC sensor configuration
			\htmlonly <hr> \endhtmlonly
				This sensor allows to measure the temperature via a resistor NTC connected as shown in the schematic. \n
				The values of the circuit components must be declared in the configuration files \ref pgim_sensor_setup_public.h \n \n
				
			\subsection	sensor_ntc_res		Resistance
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_RES_REF				10000.0
				\endcode
				\htmlonly
					This define specifies the nominal value of the NTC resistance at the reference temperature.<br>
					It must be expressed in [ohm].<br>
				\endhtmlonly
				
				\subsubsection	s_sensor_ntc_res		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_RES_REF \n

			\subsection	sensor_ntc_tempref		Temp ref
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_TEMP_REF			25.0
				\endcode
				\htmlonly
					This define specifies the reference temperature for the nominal value of NTC resistance.<br>
					It must be measured in Celsius degrees.<br>
				\endhtmlonly 

				\subsubsection	s_sensor_ntc_tempref		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_TEMP_REF \n

			\subsection	sensor_ntc_beta			BETA constant
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_BETA 				3988
				\endcode
				\htmlonly
					This define specifies the ntc "BETA" constant.<br>
					The value is specified by the device manufacturer.<br>
				\endhtmlonly

				\subsubsection	s_sensor_ntc_beta		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_BETA \n

			\subsection	sensor_ntc_abc		A B C coefficients
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SENSOR_NTC_COEF_A				1.028444E-3
					#define PGIM_SENSOR_NTC_COEF_B				2.392435E-4
					#define PGIM_SENSOR_NTC_COEF_C				1.562216E-7
				\endcode
				\htmlonly
					These define specify the three coefficients that characterize the NTC.<br>
					The value is specified by the device manufacturer.<br>
				\endhtmlonly

				\subsubsection	s_sensor_ntc_abc		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_COEF_A \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_COEF_B \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_COEF_C \n

			\subsection	sensor_ntc_method		Calculation method
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_CALCULATION_METHOD	PG_SENSOR_METHOD_BETA
				\endcode
				\htmlonly
					The temperature of the NTC can be calculated in two ways:
					through the constant BETA (calculation simpler, but less accurate)
					or by the three coefficients "A", "B", "C" (calculation slightly more complicated, but more precise ).<br>
					It must be:<br>
				\endhtmlonly
				\arg \b	PG_SENSOR_METHOD_BETA : Calculations performed using the BETA constant.
				\arg \b PG_SENSOR_METHOD_COEF : Calculations performed using "A", "B", "C" coefficients.
				
				\subsubsection	s_sensor_ntc_method		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_CALCULATION_METHOD \n

			\subsection	sensor_ntc_hires	High resistor
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SENSOR_NTC_HIGH_RESISTOR		10002.0
				\endcode
				\htmlonly
					This define specifies he high side resitor exact value.<br>
					In the reference schematic, it is marked by R1 label.<br>
					It must be expressed in [ohm].<br>
				\endhtmlonly
				
				\subsubsection	s_sensor_ntc_hires		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_HIGH_RESISTOR \n

			\subsection	sensor_ntc_use_adcref		Reference voltage
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_USE_ADCREF			PG_YES
				\endcode
				\htmlonly
					This define allows to choose the reference voltage to utilize with the AD module.<br>
					It can be chosen between the supply voltage declared in the project,<br>
					or to measure it via the sensor ADC-Ref, which must obviously be enabled and configured.<br>
					<br><br>It must be:
				\endhtmlonly
					\arg \b PG_YES : The supply voltage value used is measured by means of the \b ADC-Ref sensor.
					\arg \b PG_NO : The supply voltage value used in the calculations is that declared by the user in pgim_project_setup_public.h.
				
				\subsubsection	s_sensor_ntc_use_adcref		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_USE_ADCREF \n

			\subsection	sensor_ntc_avg		Average
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_AVERAGE			10
				\endcode
				\htmlonly
					This define specifies the averages number of measurement.<br>
					The number of measurements indicated is executed and then the average is calculated.<br>
				\endhtmlonly

				\subsubsection	s_sensor_ntc_avg		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_AD_AVERAGE \n

			\subsection	sensor_ntc_guard_min	Guard raw min
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_RAW_GUARD_MIN	5
				\endcode
				\htmlonly
					This define specifies the guard limit on the minimum acquired raw value.<br>
					It is very useful to detect if the sensor is short-circuited.<br>
					Set a value not too high, so do not compromise the measurement.<br>
				\endhtmlonly
		
				\subsubsection	s_sensor_ntc_guard_min		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_AD_RAW_GUARD_MIN \n

			\subsection	sensor_ntc_guard_max	Guard raw max
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PGIM_SENSOR_NTC_AD_RAW_GUARD_MAX	50
				\endcode
				\htmlonly
					This define specifies the guard limit on the maximum acquired raw value.<br>
					It is very useful to detect if the sensor is an open-circuit.<br>
					Set a value not too low, so do not compromise the measurement.<br>
				\endhtmlonly
				
				\subsubsection	s_sensor_ntc_guard_max		References
					\li \e File : pgim_sensor_setup_public.h \n
					\li \e Reference : \ref PGIM_SENSOR_NTC_AD_RAW_GUARD_MAX \n

			\subsection	sensor_ntc_sch		Schematic	
				\htmlonly <hr> \endhtmlonly
				Typology circuit to be used: \n
				\image html	sensor_ntc.png
		
			\subsection	sensor_ntc_pubfunc	Public function
				\htmlonly <hr> \endhtmlonly
				\arg \b pg_sensor_ntc() : This function measures the temperature value of an NTC sensor. \n \n 
				
			\subsection sensor_ntc_code		Example code
				\htmlonly <hr> \endhtmlonly
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

//								\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH : if the reference voltage value is too big. \n
//								\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW : if the reference voltage value is negative or zero. \n


