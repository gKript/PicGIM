//
// pgim_adc.h
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

/*!		\file			pgim_adc.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			It configures and manages the ADC module, calculating and setting the necessary parameters.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_ADC_H

#include "pgim_custom_type.h"

	#define _PGIM_ADC_H
	
	#if ( PGIM_AD_CONVERTER == PG_ENABLE )
	
		#define	PG_ADC_ERROR					100					//!<	This error indicates a generic ADC error.
		#define	PG_ADC_ERROR_TOO_AVERAGE		101					//!<	This error indicates that averages required are more than the maximum allowed.
		#define	PG_ADC_ERROR_NO_AVERAGE			102					//!<	This error indicates that averages function return only one acquisition due to ADinterrupt enabled. The average function work only with AD interrupt disabled.

		#define	PG_FOSC_PARAM					1					//!<	The \e parameter FOSC for the pg_adc_set() function. \n With this you can choose the FOSC value.
		#define	PG_TAD_PARAM					2					//!<	The \e parameter TAD for the pg_adc_set() function. \n With this you can choose the TAD value.
		#define	PG_ANALOG_CHANNELS_PARAM		3					//!<	The \e parameter CHANNELS for the pg_adc_set() function. \n With this you can choose the number of AD channels.
		#define	PG_JUSTIFICATION_PARAM			4					//!<	The \e parameter JUSTIFICATION for the pg_adc_set() function. \n With this you can choose if you want the result justified to the right or to the left.
		#define	PG_ADC_MODULE					5					//!<	The \e parameter ADC for the pg_adc_set() function. \n With this you can turn ON or OFF the ADC device.
		#define	PG_USER_SCALE_MIN				6
		#define	PG_USER_SCALE_MAX				7
		
		#define	PG_JUSTIFIED_RIGHT				1   				//!<	To justify the result on the right.
		#define	PG_JUSTIFIED_LEFT				0   				//!<	To justify the result on the left.
	    										
		#define	PG_FOSC_MASK					0b00000111			//!<	The mask to write correctly in the register the FOSC parameter.
		#define	PG_FOSC_2						0b11111000			//!<	A FOSC value.
		#define	PG_FOSC_4						0b11111100			//!<	A FOSC value.
		#define	PG_FOSC_8						0b11111001			//!<	A FOSC value.
		#define	PG_FOSC_16						0b11111101			//!<	A FOSC value.
		#define	PG_FOSC_32						0b11111010			//!<	A FOSC value.
		#define	PG_FOSC_64						0b11111110			//!<	A FOSC value.
		
		#define	PG_TAD_MASK						0b00111000			//!<	The mask to write correctly in the register the TAD parameter.
		#define	PG_TAD_12						0b11101111			//!<	A TAD value.
		#define	PG_TAD_16						0b11110111			//!<	A TAD value.
		#define	PG_TAD_20						0b11111111			//!<	A TAD value.
		
		#define	PG_ANALOG_CHANNELS_MASK			0b00001111			//!<	The mask to write correctly in the register the number of analogue channels to use.
		#define	PG_1_CHANNEL					2					//!<	To use 1 ADC channels.
		#define	PG_2_CHANNELS					3					//!<	To use 2 ADC channels.
		#define	PG_3_CHANNELS					4					//!<	To use 3 ADC channels.
		#define	PG_4_CHANNELS					5					//!<	To use 4 ADC channels.
		#define	PG_5_CHANNELS					6					//!<	To use 5 ADC channels.
		#define	PG_6_CHANNELS					7					//!<	To use 6 ADC channels.
		#define	PG_7_CHANNELS					8					//!<	To use 7 ADC channels.
		#define	PG_8_CHANNELS					9					//!<	To use 8 ADC channels.
		
		#define	PG_CH_MASK						0b00111100			//!<	The mask to write correctly in the register the selected channel to be sampled.
		#define	PG_CH_0							0b11000011			//!<	To select the ADC channel 0.
		#define	PG_CH_1							0b11000111			//!<	To select the ADC channel 1.
		#define	PG_CH_2							0b11001011			//!<	To select the ADC channel 2.
		#define	PG_CH_3							0b11001111			//!<	To select the ADC channel 3.
		#define	PG_CH_4							0b11010011			//!<	To select the ADC channel 4.
		#define	PG_CH_5							0b11010111			//!<	To select the ADC channel 5.
		#define	PG_CH_6							0b11011011			//!<	To select the ADC channel 6.
		#define	PG_CH_7							0b11011111			//!<	To select the ADC channel 7.

		#define	PG_MAX_AVERAGE					50				//!<	Maximum number of readings in a sample.


//		extern _pg_int16	pg_adc_user_scale_min;
//		extern _pg_int16	pg_adc_user_scale_max;

		/*!
		 *	\brief			This is the initialization function of the ADC handler module.
		 *	\warning		Internal use only.
		 *	\deprecated		Do not call directly. Already called in pg_initialize()
		 */
		void		pg_adc_init					( void );
		
		/*!
		 *	\brief		This is the function to set the main parameters of the module. 
			\return		Nothing.
		 	\param		parameter	Is the main parameter you want to set. 	Possible value : \n
								\ref PG_TAD_PARAM :				The \e parameter TAD for the pg_adc_set() function. \n With this you can choose the TAD value. \n
								\ref PG_FOSC_PARAM :			The \e parameter FOSC for the pg_adc_set() function. \n With this you can choose the FOSC value. \n
								\ref PG_ADC_MODULE :			The \e parameter ADC for the pg_adc_set() function. \n With this you can turn ON or OFF the ADC device. \n
								\ref PG_JUSTIFICATION_PARAM :	The \e parameter JUSTIFICATION for the pg_adc_set() function. \n With this you can choose if you want the result justified to the right or to the left. \n 
								\ref PG_ANALOG_CHANNELS_PARAM :	The \e parameter CHANNELS for the pg_adc_set() function. \n With this you can choose the number of AD channels. \n
								\ref PG_USER_SCALE_MIN :		The \e parameter CHANNELS for the pg_adc_set() function. \n With this you can choose the minimum value of the user scal
								\ref PG_USER_SCALE_MAX :		The \e parameter CHANNELS for the pg_adc_set() function. \n With this you can choose the maximum value of the user scal


			\param		value		The value of the relative parameter. \n
									Possible value : Refer to the table below. \n
			\image		html		param_adc_set.png
			\test	This function set the error status if the \ref SWG_error is enabled . \n \n
						\b PG_OK : Everything is ok. \n
						\b PG_ADC_ERROR : It was probably requested a non-existent parameter. \n
		*/
		void		pg_adc_set					( _pg_Uint8 parameter , _pg_Uint8 value );
		
		/*!
			\brief		When this function is called the acquisition is carried out.
			\param		channel		Indicates the channel on which to make the acquisition. Possible value : \n
								\ref PG_CH_0 : To select the ADC channel 0. \n
								\ref PG_CH_1 : To select the ADC channel 1. \n
								\ref PG_CH_2 : To select the ADC channel 2. \n
								\ref PG_CH_3 : To select the ADC channel 3. \n
								\ref PG_CH_4 : To select the ADC channel 4. \n
								\ref PG_CH_5 : To select the ADC channel 5. \n
								\ref PG_CH_6 : To select the ADC channel 6. \n
								\ref PG_CH_7 : To select the ADC channel 7. \n
			\return		The value of the sampling.
			\test		This function does not change the error status.
		*/
		_pg_Uint16	pg_adc_start				( _pg_Uint8 channel );
		
		/*!
			\brief		This function returns the value of the last acquisition made.
			\param 		Nothing.
			\return		The value of the last sampling.
			\test		This function does not change the error status.
		*/
		_pg_Uint16	pg_adc_get					( void );

		/*!
			\brief		This function returns the value of the last acquisition made in a user secified range.
			\param 		Min	The minimum value of the user scale.
		    \param 		Max	The maximum value of the user scale.
			\return		The value of the last samplingin a user secified range.
			\test		This function does not change the error status.
		*/
		_pg_int16	pg_adc_get_user_scale		( _pg_int16 Min , _pg_int16 Max );

		/*!
			\brief		This function acquires with [n] averages.
			\param		channel		Indicates the channel on which to make the acquisition. Possible value : \n
								\ref PG_CH_0 : To select the ADC channel 0. \n
								\ref PG_CH_1 : To select the ADC channel 1. \n
								\ref PG_CH_2 : To select the ADC channel 2. \n
								\ref PG_CH_3 : To select the ADC channel 3. \n
								\ref PG_CH_4 : To select the ADC channel 4. \n
								\ref PG_CH_5 : To select the ADC channel 5. \n
								\ref PG_CH_6 : To select the ADC channel 6. \n
								\ref PG_CH_7 : To select the ADC channel 7. \n
			\param		average		How do acquisition.
			\return		\b The \b value of the sampling averaged or \b -1 if something wrong. \n
			\test	This function set the error status if the \ref SWG_error is enabled . \n \n
						\b PG_OK : Everything is ok. \n
						\b PG_ADC_ERROR_TOO_AVERAGE : This error indicates that averages required are more than the maximum allowed. \n
		*/
		_pg_Uint16	pg_adc_start_avg			( _pg_Uint8 channel , _pg_Uint8 average );
		
		/*!
			\brief		This function returns the value as a percentage ( 0 - 100 ) of the last acquisition made.
			\param 		Nothing.
			\return		The percentage of the last sampling.
			\test		This function does not change the error status.

		*/
		_pg_Uint8	pg_adc_get_perc				( void );
		
		/*!
			\brief		This function returns the float percentage value of the last acquisition made.
			\param 		Nothing.
			\return		The percentage of the last sampling.
			\test		This function does not change the error status.

		*/
		float	pg_adc_get_perc_f				( void );
		

	#endif
#endif

/*!

	\page	HWI_adc		Analog to Digital

		\tableofcontents

		\image html adc_img.png

		We have developed the ADC module to manage up to 8 channels of AD irrespective of how many channels each MCU may have available. [An0 - AN7] \n If this our choice can bring some problems do not hesitate to inform us by writing to info@gkript.org  \n
		To maximally simplify the use of the ADC module have been set by default the FOSC and the TAD. \n
		\code
			pg_adc_set( PG_FOSC_PARAM , PG_FOSC_16 );
			pg_adc_set( PG_TAD_PARAM , PG_TAD_16 );
		\endcode
		The user can freely set them later. \n
		\note	This module is associated to an interrupt signal : \ref PG_EVENT_SET_AD \n It is possible to find out how to use it in this section : \ref adcinterrupthowto \n 
		
		\n \n

		\section	adcconf		Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref adcerruptconfen 
					
					&nbsp;\n \n

				\attention	Here a link to the file : \ref pgim_adc.h \n
							This is not a file defined as public and therefore would not be edited. \n
							We suggest that you edit this file only if necessary and only if you know what you are doing. \n
			</p>
			\n \n \n

			\subsection	adcerruptconfen		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_AD_CONVERTER					PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Interrupts module enabled.
					\arg \b PG_DISABLE : Interrupts module disabled.
					\endcode
					
					\subsubsection	adcmodenref		References
						\li \e File : pgim_module_setup_public.h \n
						\li \e Reference : \ref PGIM_AD_CONVERTER \n
				
		\section	adccsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n
			
			\attention	This module can use the \b Error \b Handling \b Module : \ref SWG_error \n
						In the \e TEST section of each function is specified which values ​​are set and in which cases. \n
						Please refer to the specific documentation of the file header: \ref pgim_adc.h 

			\htmlonly <br> \endhtmlonly

			\subsection	adcprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_adc_init() : This is the initialization function of AD handler module.

				\htmlonly <br><br> \endhtmlonly
				
			\subsection	adcpubfunc	Public functions
				\endcode
				
				\arg \b pg_adc_set() : This is the function to set the main parameters of the module. 
				\arg \b pg_adc_start() : When this function is called the acquisition is carried out. 
				\arg \b pg_adc_start_avg() : When this function is called the acquisition is carried out with [n] averages.
				\arg \b pg_adc_get() : This function returns the value of the last acquisition made.
				\arg \b pg_adc_get_perc() : This function returns the value as a percentage ( 0 - 100 ) of the last acquisition made.
				\arg \b pg_adc_get_perc_f()	: This function returns the value as a percentage in float ( 0.0 - 100.0 ) of the last acquisition made.
				
				\endcode
				
			\htmlonly <br><br> \endhtmlonly
			

	\section	adcexampleuse	A code example
		\htmlonly <hr> \endhtmlonly
			
		Here is a simple example of how to use the module in your code. 
		\warning	In order to compile this example, the module must be enabled and properly configured.
		
		\code
			...
			
			pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
			pg_adc_set( PG_ADC_MODULE , PG_ON );
			pg_adc_start( PG_CH_0 );
			result = pg_adc_get();
			
			...
		\endcode

		\htmlonly <br><br> \endhtmlonly
		
	\section	adcinterrupthowto	Using this module with interrupts
		\endhtmlonly
	
		If the interrupt handling is enable is possible, through the interrupt signal \ref PG_EVENT_SET_AD, have an interrupt at every end of conversion. \n 
		If using the \b Automatic \b Interrupts \b Handler pg_event_auto_handler() will call the associated callback: pg_interrupts_event_ad() \n
		So once entered the code inside the callback it will be executed at every end of conversion. \n 
		
		\b References : \n
			Interrups configuration :\ref iterruptconf \n
			Internal interrupts configuration : \ref interdefinesintern \n 
			Callback configuration : \ref interruptcallbackhowto \n 
			

		\htmlonly <br><br> \endhtmlonly
		
*/

