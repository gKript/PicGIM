/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_pwm.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_pwm.c

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
		\file		pgim_pwm.h
		\version	0.5-0
		\date		2002 - 2015
		\brief			It configures and manages the PWM module, calculating and setting the necessary parameters
		\details		The modules supported are PWM1 and PWM2
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_PWM_H_
	#define _PGIM_PWM_H_
		
	#if ( PGIM_PWM == PG_ENABLE )
	
//        #include <plib/pwm.h>

		//---[ Errors ]---
		#define	PG_PWM_ERROR						-1						//!< Undefined error
		#define PG_PWM_ERROR_ID						-2						//!< PWM ID not enabled or wrong
		#define PG_PWM_ERROR_FREQ_TOO_HIGH			-3						//!< Required frequency is too high!
		#define PG_PWM_ERROR_FREQ_TOO_LOW			-4						//!< Required frequency is too low!
		#define PG_PWM_ERROR_PERIOD_TOO_LONG		-5						//!< Required frequency is too high!
		#define PG_PWM_ERROR_PERIOD_TOO_SHORT		-6						//!< Required frequency is too low!
		#define	PG_PWM_ERROR_DUTYCYCLE_RANGE		-7						//!< Required dutycycle is senseless!
		#define PG_PWM_ERROR_NOT_SET				-8						//!< Frequency and prescler have NOT been calculated; must run \a gp_pwm_set() function before.
		#define	PG_PWM_ERROR_ALREADY_STARTED		-9						//!< PWM module is already started.
		#define	PG_PWM_ERROR_ALREADY_STOPPED		-10						//!< PWM module is already stopped.
		#define	PG_PWM_ERROR_DEAD_TIME_OVER			-11						//!< Dead-time value too big.
		#define	PG_PWM_ERROR_RESTART_FAILED			-12						//!< It was not possible to reset the fault condition. Is fault issue removed? Event must gone away.
		#define	PG_PWM_ERROR_SHUTDOWN_FAILED		-13						//!< It was not possible to set the fault condition. Is fault already present?
		#define PG_PWM_ERROR_RES_MAX_OUT_OF_VALUE	-14						//!< Resolution max calculation return a value aout of range ( max 10[bit] )
		
		#if ( PGIM_PWM_1 == PG_ENABLE )
			#define	PG_PWM_ERROR_NOT_DC_1			-51						//!< Dutycycle of PWM1 has NOT been calculated. Must be distinguished from that of the PWM2.
		#endif
		
		#if ( PGIM_PWM_2 == PG_ENABLE )
			#define	PG_PWM_ERROR_NOT_DC_2			-71						//!< Dutycycle of PWM2 has NOT been calculated. Must be distinguished from that of the PWM1.
		#endif
		//---[ END Errors ]---
		
		
		//---[ Variables ]---
		#define PG_PWM_DUTYCYCLE_MIN				0.000					//!< Min percentage dutycycle value.
		#define PG_PWM_DUTYCYCLE_MAX				100.000					//!< Max percentage dutycycle value.

		#define PG_PWM_PR2_REG_MIN					0						//!< Minimum PR2 register value.
		#define PG_PWM_PR2_REG_MAX					255						//!< Maximum PR2 register value (8bit).
		
		#define PG_PWM_TMR2_PRESCALER_MIN			1						//!< Minimum PR2 register value.
		#define PG_PWM_TMR2_PRESCALER_MAX			16						//!< Maximum PR2 register value (8bit).
		//---[ END Variables ]---
		
		
		//---[ Flags ]---
		#define	PG_PWM_FLAGS						pg_pwm_state.Val
		#define PG_PWM_FLAG_SET_OK					pg_pwm_state.bits.b0	//!<If '0', PWM has not a correct frequency and prescaler; must run \a gp_pwm_set() function before.
		
		#if ( PGIM_PWM_1 == PG_ENABLE )
			#define PG_PWM_FLAG_1_DC_OK				pg_pwm_state.bits.b1	//!<If '1', duty-cycle of PWM1 is set; if '0', duty-cycle of PWM1 has not yet been calculated. Must be distinguished from that of the PWM2.
			#define PG_PWM_FLAG_1_RUNNING			pg_pwm_state.bits.b3	//!<If '1', PWM1 is started; if '0', PWM1 is stopped. Must be distinguished from that of the PWM2.
		#endif
		
		#if ( PGIM_PWM_2 == PG_ENABLE )
			#define PG_PWM_FLAG_2_DC_OK				pg_pwm_state.bits.b2	//!<If '1', duty-cycle of PWM2 is set; if '0', duty-cycle of PWM2 has not yet been calculated. Must be distinguished from that of the PWM1.
			#define PG_PWM_FLAG_2_RUNNING			pg_pwm_state.bits.b4	//!<If '1', PWM2 is started; if '0', PWM2 is stopped. Must be distinguished from that of the PWM1.
		#endif
		//---[ END Flags ]---

		
		//---[ PWM Devices ]---
		#if ( PGIM_PWM_1 == PG_ENABLE )
			#define PG_PWM_1						1						//!< PWM 1 device identifier.
		#endif

		#if ( PGIM_PWM_2 == PG_ENABLE )
			#define PG_PWM_2						2						//!< PWM 2 device identifier.
		#endif
		//---[ END PWM Devices ]---
		
		
		//---[ Global variables (GV) ]---
		#define	PG_GV_PWM_FREQ_MIN				pg_pwm_freq_min;		//!< Minimum achievable frequency [Hz].
		#define	PG_GV_PWM_FREQ_MAX				pg_pwm_freq_max;		//!< Maximum achievable frequency [Hz].

		#define	PG_GV_PWM_PERIOD_MIN			pg_pwm_period_min;		//!< Minimum achievable period [s].
		#define	PG_GV_PWM_PERIOD_MAX			pg_pwm_period_max;		//!< Maximum achievable period [s].

		#define	PG_GV_PWM_1_DUTYCYCLE			pg_pwm_1_dutycycle;		//!< PWM 1 module calculated duty-cycle [s].
		#define	PG_GV_PWM_2_DUTYCYCLE			pg_pwm_2_dutycycle;		//!< PWM 2 module calculated duty-cycle [s].
		
		#define	PG_GV_PWM_DEADTIME_MAX			pg_pwm_deadtime_us_max	//!< Maximum deadtime [us](micro-seconds).
		//---[ END Global variables (GV) ]---

		//---[ Prototypes ]---
		extern _pg_float pg_pwm_freq_min;								//!< Minimum achievable frequency [Hz].
		extern _pg_float pg_pwm_freq_max;								//!< Maximum achievable frequency [Hz].
		extern _pg_float pg_pwm_period_min;								//!< Minimum achievable period [s].
		extern _pg_float pg_pwm_period_max;								//!< Maximum achievable period [s].
		extern _pg_float pg_pwm_1_dutycycle;							//!< PWM 1 module calculated duty-cycle [s].
		extern _pg_float pg_pwm_2_dutycycle;							//!< PWM 2 module calculated duty-cycle [s].
		extern _pg_Uint8 pg_pwm_deadtime_us_max;						//!< Maximum deadtime [us](micro-seconds).
		
		#if ( PG_PWM_DC_RES_MAX == PG_INCLUDE )
			extern _pg_float pg_pwm_dutycycle_resolution_max;			//!< Maximum achievable duty-cycle resolution [bit].
		#endif
		
		/*!
			\brief			This function properly initializes the PWM module. 
			\return			\b PG_DONE : if the initialization has ended. \n
								\b PG_PWM_ERROR_DEAD_TIME_OVER : if the dead-time in enhanced mode has failed. The initialization was not completed.
			\param			Nothing.
			\attention		Internal use only !
			\deprecated	Do not call directly. \n
								Already called in pg_initialize().
		*/
		_pg_int8	pg_pwm_init						( void );		// far getire il valore di ritorno da chi chiama la init!!!

		/*!
			\brief			This function configures the PWM module. \n
							It requires two parameters, a value and a unit of measurement. \n
							PicGIM understands if the value is a frequency or a time, depending on the measure unit. \n
							In this way you can easily set the PMW specifying the frequency or the period. \n
							The frequency can be expressed in \a MHz, \a KHz, \a Hz. \n
							The period can be expressed in \a seconds [s], \a milli-second [ms], \a micro-seconds [us].
			\return			\b PG_OK : if everything was successful. \n
							\b PG_PWM_ERROR_FREQ_TOO_LOW : if the required frequency is too \a low. \n
							\b PG_PWM_ERROR_FREQ_TOO_HIGH : if the required frequency is too \a high. \n
							\b PG_PWM_ERROR_PERIOD_TOO_SHORT : if the required period is too \a short. \n
							\b PG_PWM_ERROR_PERIOD_TOO_LONG : if the required period is too \a long.
			\param			pwm_value 				The required frequency or period value.
			\param			unit_measure			The measure unit of the frequency or period. \n
								Use \b PG_MHZ for \a MHz \n
								Use \b PG_KHZ for \a KHz \n
								Use \b PG_HZ for \a Hz \n
								Use \b PG_SEC for \a seconds [s] \n
								Use \b PG_MSEC for \a milli-seconds [ms] \n
								Use \b PG_USEC for \a micro-seconds [us]								
		*/
		_pg_int8	pg_pwm_set						( _pg_float pwm_value , _pg_Uint8 unit_measure );
		
		/*!
			\brief			This function sets the pwn duty-cycle.

			\return			\b PG_OK : if everything was successful. \n
							\b PG_PWM_ERROR_ID : if the \a pwm_id parameter is wrong.
			\param			pwm_id					The identification number of the pwm channel. \n
								Use \b PG_PWM_1 to select \a PWM 1 \n
								Use \b PG_PWM_1 to select \a PWM 2
			\param			pwm_dutycycle_percent	The required percentage value of duty-cycle. \n
								Use a decimal value from 0 to 100. \n
								Default duty-cycle is set to 50%.
		*/
		_pg_int8	pg_pwm_dutycycle				( _pg_Uint8 pwm_id , _pg_float pwm_dutycycle_percent );			
		
		/*!
			\brief			This function start the selected pwm device.
			\note			Must be called after setting the frequency or the period of the PWM device, \n
							therefore it is necessary to call the \ref pg_pwm_set function first.
			\return			\b PG_OK : if everything was successful. \n
							\b PG_PWM_ERROR_NOT_SET : if the frequency or the period of the PWM device have not been set. \n
							\b PG_PWM_ERROR_NOT_DC_1 : if the duty-cycle of the PWM 1 device have not been set. \n
							\b PG_PWM_ERROR_NOT_DC_2 : if the duty-cycle of the PWM 2 device have not been set. \n
							\b PG_PWM_ERROR_ALREADY_STARTED : if the pwm device is already started. \n
							\b PG_PWM_ERROR_ID : if the \a pwm_id parameter is wrong.
			\param			pwm_id					The identification number of the pwm channel. \n
								Use \b PG_PWM_1 to select \a PWM 1 \n
								Use \b PG_PWM_2 to select \a PWM 2
		*/
		_pg_int8	pg_pwm_start					( _pg_Uint8 pwm_id );
		
		#if ( PG_PWM_STOP == PG_INCLUDE )
			/*!
				\brief			This function stop the selected pwm device.
				\note			Must be called after setting the frequency or the period of the PWM device, \n
								therefore it is necessary to call the \ref pg_pwm_set function first.
				\return			\b PG_OK : if everything was successful. \n
								\b PG_PWM_ERROR_ALREADY_STOPPED : if the pwm device is already stopped.
				\param			pwm_id					The identification number of the pwm channel. \n
									Use \b PG_PWM_1 to select \a PWM 1 \n
									Use \b PG_PWM_2 to select \a PWM 2
			*/
			_pg_int8	pg_pwm_stop						( _pg_Uint8 pwm_id );
		#endif
		
		#if ( PG_PWM_RESTART == PG_INCLUDE )
			/*!
				\brief			This function restart all \a supported pwm device after a software or hardware shut-down event. \n
								Please, refer to the manual of the micro-controller to check if the shut-down feature is available \n
								for the pwm device which has been chosen.
				\note			In order to work the fault condition has to be removed before the call.
				\return			\b PG_OK : if everything was successful. \n
								\b PG_PWM_ERROR_RESTART_FAILED : if the necessary conditions are not met: \n
									\arg Pwm mode must be \a ENHANCED
									\arg Pwm configuration must NOT be \a SINGLE_OUT
				\param			Nothing.
			*/
			_pg_int8	pg_pwm_restart					( void );
		#endif
		
		#if ( PG_PWM_SHUTDOWN == PG_INCLUDE )
			/*!
				\brief			This function shut-down all \a supported pwm device in the case of fault condition. \n
								Please, refer to the manual of the micro-controller to check if the shut-down feature is available \n
								for the pwm device which has been chosen. \n
								Only available in the Enhanced mode. \n
								A shutdown event can be caused by a low level on the fault input hardware pin (FLT0), \n
								or it can be forced by means of this function.
				\return			\b PG_OK : if everything was successful. \n
								\b PG_PWM_ERROR_SHUTDOWN_FAILED : if the necessary conditions are not met: \n
									\arg Pwm mode must be \a ENHANCED
									\arg Pwm configuration must NOT be \a SINGLE_OUT
				\param			Nothing.
			*/
			_pg_int8	pg_pwm_shutdown					( void );
		#endif
		
		#if ( PG_PWM_DC_RES_MAX == PG_INCLUDE )
			/*!
				\brief			This function returns the value of the maximum resolution obtained in accordance \n
								with the parameters and the values set in the configuration.
				\return			\b pg_pwm_dutycycle_resolution_max : the resolution value expressed in bits [bit]. \n
								Maximum resolution value is 10[bit]. \n
								\b PG_PWM_ERROR_RES_MAX_OUT_OF_VALUE : if the calculation returned an incorrect value.
				\param			Nothing.
			*/
			_pg_float	pg_pwm_dc_res_max				( void );
		#endif
		//---[ ENDPrototypes ]---

	#endif	
#endif /* _PGIM_PWM_H_ */

/*!	
		\page 		HWI_pwm			PWM

			\tableofcontents
	
			\image html	pwm.png

			This module can drive pwm device in \b NORMAL or \b ENHANCED mode. \n
			In enhanced mode, four \b Configurations and four \b Mode are supported. \n
			Is available the use of the \b Shut-Down in automatic and manual mode. \n
			In \b HALF-Bridge mode, the \b Dead-Time is set with the desired duration. \n
			
			\n \n

		\section	confpwm	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be included in the project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref confenm  \n
					\n \n \n
				\arg \b pgim_pwm_setup_public.h : where are collected all the features of the module. \n
						Here are specified the possible values for the various parameters
						and when they have to be set depending on the chosen mode of operation of the module. \n In this file there are these configurations  : \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref dwjp2cnbpchen \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenm \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc_s2 \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc_s3 \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc_s4 \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc_s5 \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref CLCDenmc_s6 \n
						\n \n \n &nbsp;&nbsp;&nbsp;&nbsp;
				
			\attention	For software reference, please read the documentation about \b pgim_pwm.h. \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>
			\n \n \n 

			\subsection	pwmconfenm	Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_PWM							PG_ENABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : pwm module enabled.
					\arg \b PG_DISABLE : pwm module disabled.
					\endcode 
					
				\subsubsection	pwmmodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_PWM \n
							
			\subsection	dwjp2cnbpchen	Channels enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_PWM_1							PG_ENABLE
					#define PGIM_PWM_2							PG_DISABLE
				\endcode
					These defines enable or disable independently pwm channels. \n
					They must be: \n 
					\arg \b PG_ENABLE : pwm channel enabled.
					\arg \b PG_DISABLE : pwm channel disabled.

				\subsubsection	pwmchenref		References
					\li \e File : pgim_pwm_setup_public.h \n
					\li \e Reference : \ref PGIM_PWM_1 \n
					\li \e Reference : \ref PGIM_PWM_2 \n

			\subsection	CLCDenm		Enhanced mode
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_PWM_1_ENHANCED					PG_ENABLE
					#define PG_PWM_2_ENHANCED					PG_DISABLE
				\endcode
				\htmlonly
					These defines enable or disable separately the enhanced mode of pwm channels.<br>
					They must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : enhanced mode enabled.
					\arg \b PG_DISABLE : enhanced mode disabled.
					
				\subsubsection	pwmenhenref		References
					\li \e File : pgim_pwm_setup_public.h \n
					\li \e Reference : \ref PG_PWM_1_ENHANCED \n
					\li \e Reference : \ref PG_PWM_2_ENHANCED \n

			\subsection	CLCDenmc	Enhanced mode configuration
				\htmlonly <hr> \endhtmlonly
				
				\subsubsection CLCDenmc_s1	Output configuration

				\code
					#define PG_PWM_1_OUT_CONF					SINGLE_OUT
					#define PG_PWM_2_OUT_CONF					SINGLE_OUT
				\endcode

				\htmlonly
					These defines select the output type of <i>PWM 1</i> or <i>PWM 2</i> channel. <br>
					They must be: <br>
				\endhtmlonly
				\endcode
					\arg \b SINGLE_OUT : single output.
					\arg \b HALF_OUT : HALF-Bridge output.
					\arg \b FULL_OUT_FWD : FULL-Bridge output forward.
					\arg \b FULL_OUT_REV : FULL-Bridge output reverse.
 
					\subsubsection	pwmenhconfref		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_1_OUT_CONF \n
						\li \e Reference : \ref PG_PWM_2_OUT_CONF \n

				\subsubsection CLCDenmc_s2		Output mode
					\code
						#define PG_PWM_1_OUT_MODE					PWM_MODE_1
						#define PG_PWM_2_OUT_MODE					PWM_MODE_1
					\endcode		
					These defines select the output mode of <i>PWM 1</i> or <i>PWM 2</i> channel. \n
					They must be: \n
					\arg \b PWM_MODE_1 : P1A and P1C \a active-HIGH, P1B and P1D \a active-HIGH.
					\arg \b PWM_MODE_2 : P1A and P1C \a active-HIGH, P1B and P1D \a active-LOW.
					\arg \b PWM_MODE_3 : P1A and P1C \a active-LOW, P1B and P1D \a active-HIGH.
					\arg \b PWM_MODE_4 : P1A and P1C \a active-LOW, P1B and P1D \a active-LOW.
						
					\subsubsection	pwmoutmoderef		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_1_OUT_MODE \n
						\li \e Reference : \ref PG_PWM_2_OUT_MODE \n

				\subsubsection CLCDenmc_s3	Dead time
					\code
						#define PG_PWM_DEAD_TIME					12.000
					\endcode
					This define sets the <b>DEAD-TIME</b> in the <i>HALF-Bridge</i> mode. \n
					The value is expressed in micro-seconds [us]. \n

					\warning	It is used only in \b HALF-Bridge mode!
					
					\subsubsection	pwmdeadtimeref		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_DEAD_TIME \n
					
				\subsubsection CLCDenmc_s4	 Auto-Shutdown
					\code
						#define PG_PWM_AUTO_SHUTDOWN				PG_ENABLE
					\endcode
					In Enhanced mode is also available the <b>hardware Shut-Down</b> function. \n
					Please, refer to the manual of the micro-controller chosen for its implementation. \n
					PicGIM also implements the <b>software Shut-Down</b> function ;&nbsp
					in this way, the shut-down may also be invoked in other circumstances. \n
			
					This define enables SHUT-DOWN feature.<br>
					It must be:<br>
					\endhtmlonly
						\arg \b PG_ENABLE : shut-dowm enabled.
						\arg \b PG_DISABLE : shut-dowm disabled.
						
					\subsubsection	pwmautoshutref		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_AUTO_SHUTDOWN \n

				\subsubsection CLCDenmc_s5	Auto-Shutdown mode
					\code
						#define PG_PWM_AUTO_SHUTDOWN_MODE			PG_AUTOMATIC
					\endcode
					This define sets the mode in which shut-down must operate. \n
					It must be: \n
						\arg \b PG_MANUAL : Ended fault condition, the output of the PWM signal must be re-enabled calling \ref pg_pwm_restart() function.
						\arg \b PG_AUTOMATIC : Ended fault condition, the output of the PWM signal is automatically re-enabled.
						
					\subsubsection	pwmshutmoderef		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_AUTO_SHUTDOWN_MODE \n
					
				\subsubsection CLCDenmc_s6	Auto-Shutdown state
					\code
						#define PG_PWM_AUTO_SHUTDOWN_STATE_AC		PG_TRISTATE
						#define PG_PWM_AUTO_SHUTDOWN_STATE_BD		PG_TRISTATE
					\endcode
					In the case of fault condition, these defines choose the output level of <b>AC</b> and <b>BD</b> pwm signals.<br>
					Please, refer to the manual of the micro-controller chosen for its implementation.<br>
					They must be:<br>
						\arg \b PG_TRISTATE : output is in tri-state.
						\arg \b PG_HIGH : output is at high level.
						\arg \b PG_LOW : output is at low level.
			
					\subsubsection	pwmautoshutref		References
						\li \e File : pgim_pwm_setup_public.h \n
						\li \e Reference : \ref PG_PWM_AUTO_SHUTDOWN_STATE_AC \n
						\li \e Reference : \ref PG_PWM_AUTO_SHUTDOWN_STATE_BD \n
						
		\section	pwmcsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n
			
				\subsection	pwmprivfunc	Private functions
					\note With \b "private" we mean a function that should not be used by the user in its code. \n In the documents are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

					\arg \b pg_pwm_init()
					
					
				\subsection	pwmpubfunc	Public functions
					\arg \b pg_pwm_set() : to set frequency or period.
					\arg \b pg_pwm_dutycycle() : to set the Duty-Cycle.
					\arg \b pg_pwm_start() : to activate the signal output.
					\arg \b pg_pwm_stop() : to stop the signal output.
					\arg \b pg_pwm_restart() : to restart after \a Shut-Down condition.

					\note While the module is running, you can use pg_pwm_set() and pg_pwm_dutycycle() to change the values \b on \b the \b fly.

		\section	pwmexampleuse	A code example
			\htmlonly <hr> \endhtmlonly
			\endhtmlonly
			
			Here is a simple example of how to use the module in your code. 
			\warning	In order to compile this example, the module must be enabled and properly configured.
			\note 		This example use the Delay module also.
			
			\code
				...
				
				pg_pwm_set( pg_pwm_freq_min , PG_HZ );
				pg_pwm_dutycycle( PG_PWM_1 , 25 );
				pg_pwm_start( PG_PWM_1 );
				pg_delay_sec( 1 );
				pg_pwm_dutycycle( PG_PWM_1 , 25 );
				pg_delay_sec( 1 );
				pg_pwm_dutycycle( PG_PWM_1 , 50 );
				pg_delay_sec( 1 );
				pg_pwm_dutycycle( PG_PWM_1 , 75 );

				...
			\endcode

			\htmlonly <br><br> \endhtmlonly

*/


