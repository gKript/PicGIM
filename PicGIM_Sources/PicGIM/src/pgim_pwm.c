/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_pwm.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_pwm.h

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
		\file		pgim_pwm.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		It configures and manages the PWM module, calculating and setting the necessary parameters
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#include "picgim.h"

#if ( PGIM_PWM == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	/*
	28-pin devices have 2 STANDARD CCP	modules,
	40/44-pin devices have one STANDARD CCP module and one ENHANCED-CCP module.
	*/
	
	//_pg_float	pg_pwm_tosc;									// Time in [us] = 1 / (fclock [MHz])
	
	_pg_float	pg_pwm_freq;									// [Hz]
	_pg_float	pg_pwm_freq_min;								// [Hz]
	_pg_float	pg_pwm_freq_max;								// [Hz]

	_pg_float	pg_pwm_period;									// [s]
	_pg_float	pg_pwm_period_min;								// [s]
	_pg_float	pg_pwm_period_max;								// [s]
	_pg_float	pg_pwm_period_max_no_prescaler;					// [s]
	_pg_Uint8	pg_pwm_pr2_reg_value;							// 8bit
	_pg_Uint8	pg_pwm_tmr2_prescaler;							// 1,4,16
	
	#if ( PG_PWM_DC_RES_MAX == PG_INCLUDE )
		_pg_float	pg_pwm_dutycycle_resolution_max;			// [bit]; Max 10 bit
	#endif
	
	_pg_Uint8_BITS	pg_pwm_state;								// PWM running flag; If PWM1 is running: Bit1=1; If PWM2 is stopped: Bit2=0;
	
	#if ( PGIM_PWM_1 == PG_ENABLE )
		_pg_float	pg_pwm_1_dutycycle_100;						// Percent value of pwm 1;
		_pg_float	pg_pwm_1_dutycycle;							// [s]
		_pg_Uint16	pg_pwm_1_dutycycle_reg;						// CCPRXL:CCPXCON<5:4> 10bit
	#endif

	#if ( PGIM_PWM_2 == PG_ENABLE )
		_pg_float	pg_pwm_2_dutycycle_100;						// Percent value of pwm 2;
		_pg_float	pg_pwm_2_dutycycle; 						// [s]
		_pg_Uint16	pg_pwm_2_dutycycle_reg;						// CCPRXL:CCPXCON<5:4> 10bit
	#endif

//	#if ( ( PGIM_PWM_1 == PG_ENABLE ) && ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) ) || \
		( ( PGIM_PWM_2 == PG_ENABLE ) && ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) )
	#if ( ( ( PGIM_PWM_1 == PG_ENABLE ) && ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) ) || ( ( PGIM_PWM_2 == PG_ENABLE ) && ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) ) )		//kmod
		_pg_Uint8	pg_pwm_deadtime_cyclemachine;				// # cycle-machine to be assigned to dead-time
		_pg_Uint8	pg_pwm_deadtime_us_max;						// Maximum time in micro-sedonds [us] available for the dead time 
	#endif
		
		
	//---[ Pwm Init ]---
	_pg_int8	pg_pwm_init( void ) {
	
		T2CONbits.TMR2ON = 0;									// Stop common timer
		PG_PWM_FLAGS = 0x00;									// Clear all flag bit
		
		//--------------------------------------------------
		//	Calculation: PWM Period = [(PR2) + 1] * 4 * TOSC * (TMR2 Prescale Value)
		//	Calculation: PWM Duty Cycle = (CCPRXL:CCPXCON<5:4>) * TOSC * (TMR2 Prescale Value)
		pg_pwm_period_min = ( ( ( PG_PWM_PR2_REG_MIN + 1 ) * PG_PWM_FOSC_DIVIDER * PG_PWM_TMR2_PRESCALER_MIN ) / ( PG_CLOCK * 1000000 ) );	//[s]
		pg_pwm_period_max = ( ( ( PG_PWM_PR2_REG_MAX + 1 ) * PG_PWM_FOSC_DIVIDER * PG_PWM_TMR2_PRESCALER_MAX ) / ( PG_CLOCK * 1000000 ) );	//[s]
		pg_pwm_freq_min = ( 1 / pg_pwm_period_max );
		pg_pwm_freq_max = ( 1 / pg_pwm_period_min );
		pg_pwm_period_max_no_prescaler = ( ( ( PG_PWM_PR2_REG_MAX + 1 ) * PG_PWM_FOSC_DIVIDER * PG_PWM_TMR2_PRESCALER_MIN ) / ( PG_CLOCK * 1000000 ) );	//sec

		//--------------------------------------------------
		//	Calculation: Tosc = ( 1 / PG_CLOCK )[us]
		//	pg_pwm_tosc = ( 1 / PG_CLOCK );												// PG_CLOCK is in [MHz], than T is in [us]
			
		//--------------------------------------------------
		//	ENHANCED-MODE:
//		#if ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) ) || \
//			( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) )		
//			#if ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF == HALF_OUT ) ) || \
//				( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF == HALF_OUT ) )
				
		#if ( ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) ) || ( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) ) )
			#if ( ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF == HALF_OUT ) ) || ( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF == HALF_OUT ) ) )
				//--------------------------------------------------
				//	DEAD-TIME:			( Only available in Enhanced mode && Half-Bridge )
				pg_pwm_deadtime_cyclemachine = (_pg_Uint8)( PG_PWM_DEAD_TIME / ( ( 1 / PG_CLOCK ) * PG_TCYCLEPERI ) );
				pg_pwm_deadtime_us_max = ( ( 1 / PG_CLOCK ) * PG_TCYCLEPERI * 0x7F );	// [us] (Resolution is one cycle-machine: ( ( 1 / PG_CLOCK ) * PG_TCYCLEPERI ) ); Non necessaria alle funzioni
				
				if ( pg_pwm_deadtime_cyclemachine > 0x7F ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_DEAD_TIME_OVER , PG_ERROR_ERROR );
					#endif
					return PG_NOK;
				}
				else {
					PWM1CON = PWM1CON + pg_pwm_deadtime_cyclemachine;	//pg_pwm_deadtime_cyclemachine & 0x7F
				}
			#endif
			
			//--------------------------------------------------
			//	AUTO-SHUTDOWN		( Only available in the Enhanced mode )
			#if ( PG_PWM_AUTO_SHUTDOWN == PG_DISABLE )
				ECCP1ASbits.ECCPASE = 0;								// Clear fault flag; 1 = shutdown state; 0 = pwm is operating
				
				ECCP1ASbits.ECCPAS2 = 0;								// Auto-Shtdown DISABLED. No fault source
				ECCP1ASbits.ECCPAS1 = 0;
				ECCP1ASbits.ECCPAS0 = 0;
			#endif
			
			#if ( PG_PWM_AUTO_SHUTDOWN == PG_ENABLE )
				ECCP1ASbits.ECCPASE = 0;								// Clear fault flag; 1 = shutdown state; 0 = pwm is operating
				
				//	MODE
				#if ( PG_PWM_AUTO_SHUTDOWN_MODE == PG_AUTOMATIC )		
					PWM1CONbits.PRSEN = 1;								// ECCP1ASbits.ECCPASE will be resetted automatically and PWM will restart on event goes away
				#endif
				#if ( PG_PWM_AUTO_SHUTDOWN_MODE == PG_MANUAL )
					PWM1CONbits.PRSEN = 0;								// ECCP1ASbits.ECCPASE must be resetted manually by pg_pwm_restart() to restart PWM, but after event is gone away
				#endif
				
				//	OUTPUT STATE ON FAIL
				//	AC
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_AC == PG_LOW )
					ECCP1ASbits.PSSAC1 = 0;
					ECCP1ASbits.PSSAC0 = 0;
				#endif
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_AC == PG_HIGH )
					ECCP1ASbits.PSSAC1 = 0;
					ECCP1ASbits.PSSAC0 = 1;
				#endif
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_AC == PG_TRISTATE )
					ECCP1ASbits.PSSAC1 = 1;
					ECCP1ASbits.PSSAC0 = 0;
				#endif
				
				//	BD
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_BD == PG_LOW )
					ECCP1ASbits.PSSBD1 = 0;
					ECCP1ASbits.PSSBD0 = 0;
				#endif
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_BD == PG_HIGH )
					ECCP1ASbits.PSSBD1 = 0;
					ECCP1ASbits.PSSBD0 = 1;
				#endif
				#if ( PG_PWM_AUTO_SHUTDOWN_STATE_BD == PG_TRISTATE )
					ECCP1ASbits.PSSBD1 = 1;
					ECCP1ASbits.PSSBD0 = 0;
				#endif
				
				//	Enabling...
				ECCP1ASbits.ECCPAS2 = 1;								// Auto-Shutdown ENABLED. Only FLT0 pin is e fault source
				ECCP1ASbits.ECCPAS1 = 0;
				ECCP1ASbits.ECCPAS0 = 0;
			#endif
		#endif
		
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_PWM , PG_DONE , PG_ERROR_OK );
		#endif
		return PG_OK;
		
		//TRIS reg will be set by C18 cal functions
	}
	//---[ END Pwm Init ]---	


	//---[ Pwm Set Frequency or Period ]---								// Pwm frequency is common for all channel
	_pg_int8	pg_pwm_set( _pg_float pwm_value , _pg_Uint8 unit_measure ) {
		
		T2CONbits.TMR2ON = 0;											// Stop PWM signal.
			
		//--------------------------------------------------
		//If pwm_value is a FREQUENCY:
		if ( ( unit_measure == PG_MHZ ) || ( unit_measure == PG_KHZ ) || ( unit_measure == PG_HZ ) ) {
			
			if ( unit_measure == PG_MHZ )
				pwm_value *= 1000;
			if ( ( unit_measure == PG_MHZ ) || ( unit_measure == PG_KHZ ) )
				pwm_value *= 1000;									// Now we have freq in [Hz]!

			// Lower frequency limit check
			if ( pwm_value <= pg_pwm_freq_min ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_FREQ_TOO_LOW , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			// Upper frequency limit check
			if ( pwm_value > pg_pwm_freq_max ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_FREQ_TOO_HIGH , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_pwm_freq = pwm_value;								// [Hz]
			pg_pwm_period = ( 1 / pg_pwm_freq );					//[s]	<<<===	TARGET!!!
		}
		
		//--------------------------------------------------
		//If pwm_value is a TIME:
		if ( ( unit_measure == PG_USEC ) || ( unit_measure == PG_MSEC ) || ( unit_measure == PG_SEC ) ) {
		
			if ( unit_measure == PG_USEC )
				pwm_value /= 1000;
			if ( ( unit_measure == PG_USEC ) || ( unit_measure == PG_MSEC ) )
				pwm_value /= 1000;										//Now we have time in [s]!

			// Lower period limit check
			if ( pwm_value <= pg_pwm_period_min ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_PERIOD_TOO_SHORT , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			// Upper period limit check
			if ( pwm_value > pg_pwm_period_max ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_PERIOD_TOO_LONG , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
			pg_pwm_period = pwm_value;									//[s]	<<<===	TARGET!!!
		}
		
		//--------------------------------------------------
		//	PRESCALER:
		//	Searching for the right value
		if ( pg_pwm_period <= pg_pwm_period_max_no_prescaler ) {
			pg_pwm_tmr2_prescaler = 1;
			T2CONbits.T2CKPS1 = 0;										//Set prescaler to 1
			T2CONbits.T2CKPS0 = 0;										//Timer2 Clock Prescale Select bits: "00" = Prescaler is 1
		} 	
		else if ( pg_pwm_period < ( pg_pwm_period_max_no_prescaler * 4 ) ) {
			pg_pwm_tmr2_prescaler = 4;
			T2CONbits.T2CKPS1 = 0;										//Set prescaler to 4
			T2CONbits.T2CKPS0 = 1;										//Timer2 Clock Prescale Select bits: "01" = Prescaler is 4
		} 	
		else {
			pg_pwm_tmr2_prescaler = 16;
			T2CONbits.T2CKPS1 = 1;										//Set prescaler to 16
			T2CONbits.T2CKPS0 = 0;										//Timer2 Clock Prescale Select bits: "1x" = Prescaler is 16
		}
		
		//--------------------------------------------------
		//	FREQENCY ( PERIOD ):
		//	Computation for the right PR2 register value (It will set frequency)
		//	Calculation: PWM Period = [(PR2) + 1] * 4 * TOSC * (TMR2 Prescale Value)
		pg_pwm_pr2_reg_value = (_pg_Uint8)( ( pg_pwm_period / ( PG_PWM_FOSC_DIVIDER * ( 1 / ( PG_CLOCK * 1000000 ) ) * pg_pwm_tmr2_prescaler ) ) - 1 );
		
		PR2 = pg_pwm_pr2_reg_value;										//		<<<===	TARGET!!!
		PG_PWM_FLAG_SET_OK = 1;											// Set has configured pwm freq correctly
		
		//--------------------------------------------------
		#if ( PGIM_PWM_1 == PG_ENABLE )
			
			//	ENHANCED mode configuration
			#if ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT )
				SetOu   tputPWM1( PG_PWM_1_OUT_CONF, PG_PWM_1_OUT_MODE );
			#endif
			
			//	DUTYCYCLE re-calculating for new frequency
			if ( PG_PWM_FLAG_1_DC_OK == 1 )
				pg_pwm_dutycycle( PG_PWM_1 , pg_pwm_1_dutycycle_100 ); 
		#endif
			
		//--------------------------------------------------
		#if ( PGIM_PWM_2 == PG_ENABLE )

			//	ENHANCED mode configuration
			#if ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_2_OUT_CONF != SINGLE_OUT )
				SetOutputPWM2( PG_PWM_2_OUT_CONF, PG_PWM_2_OUT_MODE );
			#endif
			
			//	DUTYCYCLE re-calculating for new frequency			
			if ( PG_PWM_FLAG_2_DC_OK == 1 ) 
				pg_pwm_dutycycle( PG_PWM_2 , pg_pwm_2_dutycycle_100 );
		#endif

		//--------------------------------------------------		
		T2CONbits.TMR2ON = 1;											// Start PWM signal.
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
		#endif
		return PG_OK;
	}
	//---[ END Pwm Set Frequency or Period ]---


	//---[ Pwm Dutycycle ]---
	_pg_int8	pg_pwm_dutycycle( _pg_Uint8 pwm_id , _pg_float pwm_dutycycle_percent ) {	//Called after pg_pwm_set, because need (TMR2 Prescale Value) and time period
			
		if ( ( pwm_dutycycle_percent < PG_PWM_DUTYCYCLE_MIN ) || ( pwm_dutycycle_percent > PG_PWM_DUTYCYCLE_MAX ) ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_DUTYCYCLE_RANGE , PG_ERROR_ERROR );
			#endif
			return PG_NOK;
		}
		
		switch( pwm_id ) {
			//--------------------------------------------------
			#if ( PGIM_PWM_1 == PG_ENABLE )
				pg_pwm_1_dutycycle_100 = pwm_dutycycle_percent;
				case PG_PWM_1:
				{
					//	Calculation: PWM Duty Cycle = (CCPRXL:CCPXCON<5:4>) * TOSC * (TMR2 Prescale Value)
					//  Calculation: (CCPRXL:CCPXCON<5:4>) = PWM Duty Cycle / TOSC / (TMR2 Prescale Value)
					pg_pwm_1_dutycycle = ( ( pg_pwm_period * pwm_dutycycle_percent ) / 100 );
					pg_pwm_1_dutycycle_reg = (_pg_Uint16)( ( pg_pwm_1_dutycycle * PG_CLOCK * 1000000 ) / pg_pwm_tmr2_prescaler );
					
					SetDCPWM1( pg_pwm_1_dutycycle_reg );
					PG_PWM_FLAG_1_DC_OK = 1;
					
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
					#endif
					return PG_OK;
				}
			#endif
			
			//--------------------------------------------------
			#if ( PGIM_PWM_2 == PG_ENABLE )
				pg_pwm_2_dutycycle_100 = pwm_dutycycle_percent;
				case PG_PWM_2:
				{
					//	Calculation: PWM Duty Cycle = (CCPRXL:CCPXCON<5:4>) * TOSC * (TMR2 Prescale Value)
					//  Calculation: (CCPRXL:CCPXCON<5:4>) = PWM Duty Cycle / TOSC / (TMR2 Prescale Value)
					pg_pwm_2_dutycycle = ( ( pg_pwm_period * pwm_dutycycle_percent ) / 100 );
					pg_pwm_2_dutycycle_reg = (_pg_Uint16)( ( pg_pwm_2_dutycycle * PG_CLOCK * 1000000 ) / pg_pwm_tmr2_prescaler );
						
					SetDCPWM2( pg_pwm_2_dutycycle_reg );
					PG_PWM_FLAG_2_DC_OK = 1;
					
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
					#endif
					return PG_OK;
				}
			#endif
			
			//--------------------------------------------------
			default: {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ID , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
		}
	}
	//---[ END Pwm Dutycycle ]---


	//---[ Pwm Start ]---
	_pg_int8	pg_pwm_start( _pg_Uint8 pwm_id ) {
		
		if ( PG_PWM_FLAG_SET_OK == 0 ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_NOT_SET , PG_ERROR_FATAL );
			#endif
			return PG_NOK;
		}
		
		switch( pwm_id ) {
			//--------------------------------------------------
			#if ( PGIM_PWM_1 == PG_ENABLE )
				case PG_PWM_1:
				{
					if ( PG_PWM_FLAG_1_DC_OK == 0 )	{					// If dutycycle has NOT been calculated...
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_NOT_DC_1 , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}	
					if ( ! PG_PWM_FLAG_1_RUNNING ) {					// If PWM1 is NOT running...
						OpenPWM1( pg_pwm_pr2_reg_value );
						PG_PWM_FLAG_1_RUNNING = 1;
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
						#endif
						return PG_OK;
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ALREADY_STARTED , PG_ERROR_ERROR );
						#endif
						return PG_NOK;
					}
				}
			#endif
			
			//--------------------------------------------------
			#if ( PGIM_PWM_2 == PG_ENABLE )
				case PG_PWM_2:
				{
					if ( PG_PWM_FLAG_2_DC_OK == 0 )	{					// If dutycycle has NOT been calculated...
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_NOT_DC_2 , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}
					if ( ! PG_PWM_FLAG_2_RUNNING ) {					// If PWM2 is NOT running...
						OpenPWM2( pg_pwm_pr2_reg_value );
						PG_PWM_FLAG_2_RUNNING = 1;
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
						#endif
						return PG_OK;
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ALREADY_STARTED , PG_ERROR_ERROR );
						#endif
						return PG_NOK;
					}
				}
			#endif
			
			//--------------------------------------------------
			default: {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ID , PG_ERROR_ERROR );
				#endif
				return PG_NOK;
			}
		}
	}
	//---[ END Pwm Start ]---


	//---[ Pwm Stop ]---
	#if ( PG_PWM_STOP == PG_INCLUDE )
		_pg_int8	pg_pwm_stop( _pg_Uint8 pwm_id ) {
		
			switch( pwm_id ) {
				//--------------------------------------------------
				#if ( PGIM_PWM_1 == PG_ENABLE )
					case PG_PWM_1:
					{
						if ( PG_PWM_FLAG_1_RUNNING ) {						// If PWM1 is running...
							ClosePWM1( );
							PG_PWM_FLAG_1_RUNNING = 0;
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
							#endif
							return PG_OK;
						}
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ALREADY_STOPPED , PG_ERROR_ERROR );
							#endif
							return PG_NOK;
						}	
					}
				#endif
				
				//--------------------------------------------------
				#if ( PGIM_PWM_2 == PG_ENABLE )
					case PG_PWM_2:
					{
						if ( PG_PWM_FLAG_2_RUNNING ) {						// If PWM2 is running...
							ClosePWM2( );
							PG_PWM_FLAG_2_RUNNING = 0;
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
							#endif
							return PG_OK;
						} 
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ALREADY_STOPPED , PG_ERROR_ERROR );
							#endif
							return PG_NOK;
						}
					}
				#endif
				
				//--------------------------------------------------
				default: {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_ID , PG_ERROR_ERROR );
					#endif
					return PG_NOK;
				}
			}
		}
	#endif
	//---[ END Pwm Stop ]---


	//---[ Pwm Shutdown ]---
	#if ( PG_PWM_SHUTDOWN == PG_INCLUDE )
		_pg_int8	pg_pwm_shutdown( void ) {								// Stop output in fault condition in enhanced mode
		
			#if ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) ) || \
				( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) )
				//--------------------------------------------------
				//	SHUTDOWN:					( Only available in the Enhanced mode and in Half-Bridge )
				if ( ECCP1ASbits.ECCPASE = 0 ) {
					ECCP1ASbits.ECCPASE = 1;
					if ( ECCP1ASbits.ECCPASE = 1 ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
						#endif
						return PG_OK;
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_SHUTDOWN_FAILED , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}
				}
			#endif
		}
	#endif
	//---[ END Pwm Shutdown ]---	

	//---[ Pwm Restart ]---
	#if ( PG_PWM_RESTART == PG_INCLUDE )
		_pg_int8	pg_pwm_restart( void ) {
		
			#if ( ( PG_PWM_1_ENHANCED == PG_ENABLE ) && ( PG_PWM_1_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) ) || \
				( ( PG_PWM_2_ENHANCED == PG_ENABLE ) && ( PG_PWM_2_MODE == PG_ENHANCED ) && ( PG_PWM_1_OUT_CONF != SINGLE_OUT ) )
				//--------------------------------------------------
				//	RESTART AFTER SHUTDOWN:			( Only available in the Enhanced mode and in Half-Bridge )
				if ( ECCP1ASbits.ECCPASE = 1 ) {
					ECCP1ASbits.ECCPASE = 0;
					if ( ECCP1ASbits.ECCPASE = 0 ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_OK , PG_ERROR_OK );
						#endif
						return PG_OK;
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_RESTART_FAILED , PG_ERROR_ERROR );
						#endif
						return PG_NOK;
					}
				}
			#endif
		}
	#endif
	//---[ END Pwm Restart ]---	
	
	
	//---[ Pwm Resolution Max]---
	#if ( PG_PWM_DC_RES_MAX == PG_INCLUDE )
		_pg_float	pg_pwm_dc_res_max( void ) {
	
			#if ( ( PGIM_PWM_1 == PG_ENABLE ) || ( PGIM_PWM_2 == PG_ENABLE ) ) && ( PGIM_PWM_DC_RESOLUTION_MAX_CALC == PG_ENABLE )
				pg_pwm_dutycycle_resolution_max = ( ( log10 ( ( PG_CLOCK * 1000000 ) / pg_pwm_freq ) ) / log10 ( 2.00 ) );
				if ( ( pg_pwm_dutycycle_resolution_max > 1.00 ) && ( pg_pwm_dutycycle_resolution_max <= 10.00 ) ) {
					return pg_pwm_dutycycle_resolution_max;
				}
				else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_PWM , PG_PWM_ERROR_RES_MAX_OUT_OF_VALUE , PG_ERROR_ERROR );
					#endif
					return PG_NOK;
				}
			#endif
		}
	#endif
	//---[ END Pwm Resolution Max ]---
	
#endif






/*
---------------------------------------------------------------------------------------
28 PIN		Mod.PWM2	pin CCP2	(RB3||RC1)
			Mod.PWM1	pin CCP1	(RC2)
---------------------------------------------------------------------------------------			
40 PIN		Mod.PWM2	pin CCP2	(RB3||RC1)	come sul 28 pin
			Mod.PWM1	pin P1A		(RC2)		come sul 28 pin se usata singola uscita
						pin P1B		(RD5)
						pin P1C		(RD6)
						pin P1D		(RD7)
---------------------------------------------------------------------------------------
*/

/*
void SetOutputPWM1 (  unsigned char outputconfig, unsigned char outputmode );

outputconfig

	  SINGLE_OUT        single output

	  FULL_OUT_FWD      full-bridge output forward

	  HALF_OUT          half-bridge output

	  FULL_OUT_REV      full-bridge output reverse

outputmode

	  PWM_MODE_1          P1A and P1C active-high,
						  P1B and P1D active-high

	  PWM_MODE_2          P1A and P1C active-high,
						  P1B and P1D active-low

	  PWM_MODE_3          P1A and P1C active-low,
						  P1B and P1D active-high

	  PWM_MODE_4          P1A and P1C active-low,
						  P1B and P1D active-low
						  
						  
SetOutputPWM1( SINGLE_OUT, PWM_MODE_1 );

 */
 
 /*
	CCPR1L = pg_pwm_1_dutycycle_reg >> 2;	//Msb Byte <9:2> of 10bit
	CCP1CONbits.DC1B1 = 0;					//Bit <1> of 10bit
	CCP1CONbits.DC1B0 = 0;					//Bit <0> of 10bit
	if ( pg_pwm_1_dutycycle_reg & 0x0200 )	//Check bit 1
		CCP1CONbits.DC1B1 = 1;
	if ( pg_pwm_1_dutycycle_reg & 0x0100 )	//Check bit 0
		CCP1CONbits.DC1B0 = 1;
*/













