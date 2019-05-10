/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_error.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_error.c

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
		\file		pgim_error.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To know which error we have done.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_ERROR_H_
	#define _PGIM_ERROR_H_

	#define PG_ERROR_IS_ENABLE      ( PGIM_ERROR == PG_ENABLE )

	#if ( PGIM_ERROR == PG_ENABLE )

		enum _pg_error_state_enum {
                    PG_ERROR_OK = 100,
                    PG_ERROR_WARNING,									//!< msg
                    PG_ERROR_CRITICAL,									//!< non compromette  funz ma avvisa potenzial lo compromette, valori di ritorno potenz non correti
                    PG_ERROR_ERROR,										//!< fallito qualche config
                    PG_ERROR_FATAL										//!< blocco totale dell'esecuzione del prg in loop infinito panic con led lamp
		};

		enum _pg_error_modules_enum {
                    PG_ERROR_SPI = 10,
					PG_ERROR_I2C,
					PG_ERROR_ADC,
					PG_ERROR_TIMER,
					PG_ERROR_PWM,
					PG_ERROR_FTOA,
					PG_ERROR_SENSOR,
					PG_ERROR_RTC_DS1302,
					PG_ERROR_GCP,
					PG_ERROR_AMG88XX,
					PG_ERROR_SSP
                };

		extern _pg_Uint32_VAL			pg_error_state;					//!<	The ERROR registry

		#define	PG_ERROR_MODULE			pg_error_state.byte.LB			//!<	The MODULE coded by the _pgmodules_code_enum enumerator
		#define	PG_ERROR_CODE			pg_error_state.byte.HB			//!<	The error code returned by the caller function
		#define	PG_ERROR_SEVERITY		pg_error_state.byte.MB			//!<	May be one of this :  OK, WARNING, CRITICAL, ERROR or FATAL

		/*!
		 *  \brief This Function initialize the error handler module.
		 */
		void	pg_error_init( void );

		/*!
		 *  \brief This Function convert the severity in string.
		 */
		const char *	pg_error_severity_str( _pg_Uint8 severity );

		#if ( PG_ERROR_LED_PRESENT == PG_YES )
			/*!
			 *  \brief This Function sets led blink timing (for internal use).
			 */
			 void	pg_error_led_sequence ( void );

			/*!
			 *  \brief This Function stop the flow of the program in an infinite loop. If a LED is present and correctly set ( pgim_hardware_setup_public.h ) it will blink quickly several times and pause.
			 */
			void	pg_error_led( void );
		#endif

		void			pg_error_set( _pg_Uint8 module , _pg_Uint8 code , _pg_Uint8 severity );
		char *	pg_error_code_to_module( _pg_Uint8 module );
		
	#endif
#endif /* _PGIM_EE_H_ */

/*!
	\page	SWG_error	Error manager

		\tableofcontents

		\image	html	error.png

		The \b ERROR \b HANDLING \b MODULE takes care, in case of error, to set correctly three variables useful for the user to understand in detail what the error means. \n
		The three variables are the following : \n
			\arg \ref PG_ERROR_MODULE	: The caller MODULE described by the \ref _pgmodules_code_enum enumerator. \n
			\arg \ref PG_ERROR_CODE		: The error code returned by the caller function. \n
			\arg \ref PG_ERROR_SEVERITY	: One of those indicated by the following enumerator: :  \ref _pg_error_state_enum

		The severity Critical produces a blink (about 800mS) on LED assigned to debugging before resuming normal execution. \n
		The severity Error produces three flashes (about 800mS each one) on the LED assigned to debugging before resuming normal execution. \n
		The severity Fatal move into an infinite loop (about 800mS each one) on the LED assigned to the debugging and if it also enabled the LCD display the module and error code will be written. \n

		\warning		A FATAL error will produce an infinite loop only if you have set the LED to report errors. \n If enabled, all interrupts are disabled.

		\endcode
			\n \n \n

		\section	qsderrorconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be included in the project. \n 
					In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref fewtimerconfenm  \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref dwjp2cnbperroren  \n
					\n \n \n
				\arg \b pgim_hardware_setup_public.h : where are collected configuration details for the indicator LED. \n
						In this file there are these configurations  : \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref dwjp2cnbperrorset \n
						 \n \n &nbsp;&nbsp;&nbsp;&nbsp;

			\warning	This module requires the \b DEBUG mode it activated. \n
						\code
							#define PG_PROJECT_STATE					PG_DEBUG
						\endcode
						This setting is in this file : \ref pgim_project_setup_public.h

			\n \n

			\attention	For software reference, please read the documentation about \b pgim_error.h . \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>

  			\n \n 

			\subsection	fewtimerconfenm		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_ERROR							PG_ENABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Timer module enabled.
					\arg \b PG_DISABLE : Timer module disabled.
					\endcode

				\subsubsection	errormodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_ERROR \n

			\subsection	dwjp2cnbperroren	Indicator LED enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PG_ERROR_LED_PRESENT			PG_YES
				\endcode
					These defines enable or disable the indicator LED. \n
					They must be: \n
					\arg \b PG_ENABLE			: Indicator LED is present and enabled.
					\arg \b PG_DISABLE			: Indicator LED is NOT present.

				\subsubsection	errorchenreflen		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PG_ERROR_LED_PRESENT \n

			\subsection	dwjp2cnbperrorset	Indicator LED setting
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PG_ERROR_LED						L_B0
					#define	PG_ERROR_LED_TRIS					T_B0
				\endcode
					These defines enable or disable the indicator LED. \n
					They may be: \n
					\arg For \ref PG_ERROR_LED		: A LAT bit correctly defined in relation to the MCU used. \n
					e.g. : L_B0
					\arg For \ref PG_ERROR_LED_TRIS : The TRIS bits used for \ref PG_ERROR_LED . \n
					e.g. : T_B0

				\subsubsection	errorchensetref		References
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_ERROR_LED_PRESENT \n


		\section	fdwerrorcsdwfun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\htmlonly <br> \endhtmlonly

			\subsection	errorprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_error_init() : This is the initialization function of the Timer handler module.

				\htmlonly <br><br> \endhtmlonly

			\subsection	timerpubfunc	Public functions
				\endcode

				\arg \b pg_timer_set() : Allows to configure the timer selected by timer_id parameter and calculates the limit values.
				\arg \b pg_timer_start() : Allows to start the timer selected by timer_id parameter.
				\arg \b pg_timer_stop() : Allows to stop the timer selected by timer_id parameter.
				\arg \b pg_timer_reg_current_value() : Converts the value of the timer contained in the two 8-bit registers (TMRxH and TMRxL) in a 16-bit value.

				\endcode

			\htmlonly <br><br> \endhtmlonly
			
*/


