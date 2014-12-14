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

		/*!
			\brief			This function measures the value of the reference voltage of the AD converter.
			\param			\b volt_stable_ref : a stable voltage reference to measure by ADC MODULE. \n
			\return			The value of the reference voltage of the AD converter.\n
							It also sets the following values in the ERROR MODULE(if enabled): \n
							\b PG_OK : if all value are right. \n
							\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_HIGH : if the reference voltage value is too big. \n
							\b PG_SENSOR_ADC_REF_ERROR_REF_TOO_LOW : if the reference voltage value is negative or zero. \n
			\note			This function can measure the supply voltage of the micro-controller. \n
							It is useful with battery powered device. \n
							It is able to perform his job because the AD-Module uses ALWAYS the Vdd as superior reference. \n
		*/
		_pg_float	pg_sensor_volt_adc_ref( _pg_float volt_stable_ref );

		/*!
			\brief			This function measures the temperature value of NTC sensor.
			\param			\b ad_channel : channel where is connected the ntc to measure on AD input. \n
			\return			The value of temperature in Celsius degrees or Fahrenheit degrees\n
							It also sets the following values in the ERROR MODULE(if enabled): \n
							\b PG_OK : if all value are right. \n
							\b PG_SENSOR_NTC_ERROR_UNPLUGGED : if the sensor is unplugged. \n
							\b PG_SENSOR_NTC_ERROR_SHORTED : if the sensor is shorted. \n
		*/		
		_pg_float	pg_sensor_ntc( _pg_Uint8 ad_channel );

		//---[ END Prototypes ]---

	#endif	
#endif /* _PGIM_SENSOR_H_ */

/*!

	\page	HWE_sensor	Sensor

		\tableofcontents

		\image html	sensor.png

		This module is able to handle a multitude of sensors or similar equipment. \n
		It is set so as to be expanded, so as to include new devices. \n \n

		\section	confsens	Module configuration

			\htmlonly <hr> \endhtmlonly
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules inclusion in the project. \n  \n
				\arg \b pgim_sensor_setup_public.h : the management file for the sensor module configuration. \n \n
			</p>
			\n \n \n 

			\subsection	confsensadref	Volt AD Ref (Vdd)
			
				\htmlonly <hr> \endhtmlonly

			\subsection	confsensntc		Ntc
				Esempio: \n
				\image html	ntc.png
				\n
				\htmlonly <hr> \endhtmlonly

		\htmlonly <br><br> \endhtmlonly

*/

