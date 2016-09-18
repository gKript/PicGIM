/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_timer.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_timer.h

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
		\file		pgim_timer.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the Timer device.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/



#include "picgim.h"

#if ( PGIM_TIMER == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	#if ( PGIM_TIMER_0 != PG_DISABLE )
		_pg_float		pg_timer_0_period;
		_pg_float		pg_timer_0_count_min;
		_pg_float		pg_timer_0_count_max;
		_pg_float		pg_timer_0_nanosec;
		_pg_float		pg_timer_0_nanosec_min;
		_pg_float		pg_timer_0_nanosec_max;

		_pg_Uint16		pg_timer_0_prescaler;
		_pg_Uint8		pg_timer_0_prescaler_mask;
		_pg_Uint16		pg_timer_0_timer_counter;
		_pg_Uint16_VAL	pg_timer_0_tmr_reg_set_value;
		_pg_Uint16_VAL	pg_timer_0_tmr_reg_current_value;
		_pg_float		pg_timer_0_period_with_prescaler;

		_pg_Uint16_VAL	pg_timer_0_tmr_reg_set_save;
	#endif

	#if ( PGIM_TIMER_1 != PG_DISABLE )
		_pg_float		pg_timer_1_period;
		_pg_float		pg_timer_1_count_min;
		_pg_float		pg_timer_1_count_max;
		_pg_float		pg_timer_1_nanosec;
		_pg_float		pg_timer_1_nanosec_min;
		_pg_float		pg_timer_1_nanosec_max;

		_pg_Uint16		pg_timer_1_prescaler;
		_pg_Uint8		pg_timer_1_prescaler_mask;
		_pg_Uint16		pg_timer_1_timer_counter;
		_pg_Uint16_VAL	pg_timer_1_tmr_reg_set_value;
		_pg_Uint16_VAL	pg_timer_1_tmr_reg_current_value;
		_pg_float		pg_timer_1_period_with_prescaler;

		_pg_Uint16_VAL	pg_timer_1_tmr_reg_set_save;
	#endif


	//---[ Timer Set Period]---
	_pg_Uint8	pg_timer_set_period( _pg_Uint8 timer_id , _pg_float timer_time , _pg_Uint8 unit_measure ) {	// PG_SEC || PG_MSEC
		//--------------------------------------------------
		if ( unit_measure == PG_SEC )
			timer_time *= 1000;
		if ( ( unit_measure == PG_MSEC ) || ( unit_measure == PG_SEC ) )
			timer_time *= 1000;								// Then found micro-seconds.
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIM_TIMER_0 != PG_DISABLE )
			case PG_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 0 ) {				// If timer is NOT running
					pg_timer_0_nanosec = ( timer_time - ( PG_TIMER_0_DELAY_TRIM / pg_ninstus ) ) * 100;	    // Take back value always by micro-seconds
					// User input by micro-seconds [us], but all calculations are by tens of nano-seconds [ns].
					// Lower limit check
					if( pg_timer_0_nanosec < pg_timer_0_nanosec_min ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_TIMER , PG_TIMER_ERROR_TIME_TOO_SHORT , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}

					// Upper limit check
					if( pg_timer_0_nanosec > pg_timer_0_nanosec_max ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_TIMER , PG_TIMER_ERROR_TIME_TOO_LONG , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}

					// Search for right prescaler value
					if( pg_timer_0_nanosec <= pg_timer_0_count_max ) {
						pg_timer_0_prescaler = 1;	        // No prescaler
						pg_timer_0_prescaler_mask = T0_PS_1_1;
					} else {
						pg_timer_0_prescaler = 2;
						pg_timer_0_prescaler_mask = T0_PS_1_2;
					}
					if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 2.000 ) ) {
						pg_timer_0_prescaler = 4;
						pg_timer_0_prescaler_mask = T0_PS_1_4;
					} else if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 4.000 ) ) {
						pg_timer_0_prescaler = 8;
						pg_timer_0_prescaler_mask = T0_PS_1_8;
					} else if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 8.000 ) ) {
						pg_timer_0_prescaler = 16;
						pg_timer_0_prescaler_mask = T0_PS_1_16;
					} else if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 16.000 ) ) {
						pg_timer_0_prescaler = 32;
						pg_timer_0_prescaler_mask = T0_PS_1_32;
					} else if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 32.000 ) ) {
						pg_timer_0_prescaler = 64;
						pg_timer_0_prescaler_mask = T0_PS_1_64;
					} else if ( pg_timer_0_nanosec < ( pg_timer_0_count_max * 64.000 ) ) {
						pg_timer_0_prescaler = 128;
						pg_timer_0_prescaler_mask = T0_PS_1_128;
					} else {
						pg_timer_0_prescaler = 256;
						pg_timer_0_prescaler_mask = T0_PS_1_256;
					}

					// Computation for the right timer register value
					pg_timer_0_period_with_prescaler = ( pg_timer_0_period * pg_timer_0_prescaler );
					pg_timer_0_timer_counter = (_pg_Uint16)( pg_timer_0_nanosec  / pg_timer_0_period_with_prescaler );
					pg_timer_0_tmr_reg_set_value.Val = 65535 - pg_timer_0_timer_counter;

					TMR0H = pg_timer_0_tmr_reg_set_value.byte.HB;   // TMR0H MUST be loaded before TMR0L !!!
					TMR0L = pg_timer_0_tmr_reg_set_value.byte.LB;

					// Setting the parameters of the timer
					T0CON = ( 0x7F & T0_16BIT & T0_SOURCE_INT & T0_EDGE_FALL & pg_timer_0_prescaler_mask );  // Configure timer, but don't start it yet
					pg_timer_0_tmr_reg_set_save.byte.LB  = TMR0L;
					pg_timer_0_tmr_reg_set_save.byte.HB  = TMR0H;

					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_TIMER , PG_OK , PG_ERROR_OK );
					#endif
					return PG_OK;
				} else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_TIMER , PG_TIMER_IS_RUNNING , PG_ERROR_WARNING );
					#endif
					return PG_NOK;
				}
			}
			#endif
			//--------------------------------------------------
			#if ( PGIM_TIMER_1 != PG_DISABLE )
			case PG_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 0 ) {				// If timer is NOT running
					pg_timer_1_nanosec = ( timer_time - ( PG_TIMER_1_DELAY_TRIM / pg_ninstus ) ) * 100;	    // Take back value always by micro-seconds
					// User input by micro-seconds [us], but all calculations are by tens of nano-seconds [ns].
					// Lower limit check
					if( pg_timer_1_nanosec < pg_timer_1_nanosec_min ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_TIMER , PG_TIMER_ERROR_TIME_TOO_SHORT , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}

					// Upper limit check
					if( pg_timer_1_nanosec > pg_timer_1_nanosec_max ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_TIMER , PG_TIMER_ERROR_TIME_TOO_LONG , PG_ERROR_FATAL );
						#endif
						return PG_NOK;
					}

					// Search for right prescaler value
					if( pg_timer_1_nanosec <= pg_timer_1_count_max ) {
						pg_timer_1_prescaler = 1;	        // No prescaler
						pg_timer_1_prescaler_mask = T0_PS_1_1;
					} else {
						pg_timer_1_prescaler = 2;
						pg_timer_1_prescaler_mask = T0_PS_1_2;
					}
					if ( pg_timer_1_nanosec < ( pg_timer_1_count_max * 2.000 ) ) {
						pg_timer_1_prescaler = 4;
						pg_timer_1_prescaler_mask = T0_PS_1_4;
					} else if ( pg_timer_1_nanosec < ( pg_timer_1_count_max * 4.000 ) ) {
						pg_timer_1_prescaler = 8;
						pg_timer_1_prescaler_mask = T0_PS_1_8;
					}

					// Computation for the right timer register value
					pg_timer_1_period_with_prescaler = ( pg_timer_1_period * pg_timer_1_prescaler );
					pg_timer_1_timer_counter = (_pg_Uint16)( pg_timer_1_nanosec  / pg_timer_1_period_with_prescaler );
					pg_timer_1_tmr_reg_set_value.Val = 65535 - pg_timer_1_timer_counter;

					TMR1H = pg_timer_1_tmr_reg_set_value.byte.HB;   // TMR1H MUST be loaded before TMR1L !!!
					TMR1L = pg_timer_1_tmr_reg_set_value.byte.LB;

					// Setting the parameters of the timer
					T1CON = ( 0x7F & T1_16BIT_RW & T1_SOURCE_INT & T1_OSC1EN_OFF & T1_SYNC_EXT_OFF & pg_timer_1_prescaler_mask );  // Configure timer, but don't start it yet
					pg_timer_1_tmr_reg_set_save.byte.LB  = TMR1L;
					pg_timer_1_tmr_reg_set_save.byte.HB  = TMR1H;

					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_TIMER , PG_OK , PG_ERROR_OK );
					#endif
					return PG_OK;
				} 
				else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_TIMER , PG_TIMER_IS_RUNNING , PG_ERROR_WARNING );
					#endif
					return PG_TIMER_IS_RUNNING;
				}
			}
			#endif
			default:
			{
				return PG_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Set Period]---

	//---[ Timer Set Frequency]---
	_pg_Uint8	pg_timer_set_freq( _pg_Uint8 timer_id , _pg_float timer_freq , _pg_Uint8 unit_measure ) {	// PG_HZ || PG_KHZ
		//--------------------------------------------------
		_pg_float	pg_timer_freq_to_period;
		
		if ( unit_measure == PG_HZ )
			timer_freq /= 1000;								// Then found kilo-hertz.
		pg_timer_freq_to_period = 1.0 / timer_freq;			// Then found milli-seconds.
		pg_timer_set_period( timer_id , pg_timer_freq_to_period , PG_MSEC );
		
		// If timer_id = 0, force TIMER_0 in loop mode. Remember to restore!!!
		;
		// If timer_id = 1, force TIMER_1 in loop mode. Remember to restore!!!
		;
	}
	//---[ END Timer Set Frequency]---


	//---[ Timer Start  ]---
	_pg_Uint8	pg_timer_start( _pg_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIM_TIMER_0 != PG_DISABLE )
			case PG_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 0 ) {				// If timer is NOT running
					T0CONbits.TMR0ON = 1;
					return PG_OK;
				} else
					return PG_TIMER_ALREADY_STARTED;
			}
			#endif
			//--------------------------------------------------
			#if ( PGIM_TIMER_1 != PG_DISABLE )
			case PG_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 0 ) {				// If timer is NOT running
					T1CONbits.TMR1ON = 1;
					return PG_OK;
				} else
					return PG_TIMER_ALREADY_STARTED;
			}
			#endif
			default:
			{
				return PG_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Start ]---

	//---[ Timer Stop  ]---
	_pg_Uint8	pg_timer_stop( _pg_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIM_TIMER_0 != PG_DISABLE )
			case PG_TIMER_0:
			{
				if ( T0CONbits.TMR0ON == 1 ) {
					T0CONbits.TMR0ON = 0;
					TMR0L = pg_timer_0_tmr_reg_set_save.byte.LB;		// Restore Timer Set value
					TMR0H = pg_timer_0_tmr_reg_set_save.byte.HB;		// Restore Timer Set value
					return PG_OK;
				} else
					return PG_TIMER_ALREADY_STOPPED;
			}
			#endif
			//--------------------------------------------------
			#if ( PGIM_TIMER_1 != PG_DISABLE )
			case PG_TIMER_1:
			{
				if ( T1CONbits.TMR1ON == 1 ) {
					T1CONbits.TMR1ON = 0;
					TMR0L = pg_timer_1_tmr_reg_set_save.byte.LB;		// Restore Timer Set value
					TMR0H = pg_timer_1_tmr_reg_set_save.byte.HB;		// Restore Timer Set value
					return PG_OK;
				} else
					return PG_TIMER_ALREADY_STOPPED;
			}
			#endif
			default:
			{
				return PG_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Stop ]---

	//---[ Timer Value ]---
	_pg_Uint16	pg_timer_reg_current_value( _pg_Uint8 timer_id ) {
		//--------------------------------------------------
		switch( timer_id ) {
			//--------------------------------------------------
			#if ( PGIM_TIMER_0 != PG_DISABLE )
			case PG_TIMER_0:
			{
				pg_timer_0_tmr_reg_current_value.byte.HB = TMR0H;
				pg_timer_0_tmr_reg_current_value.byte.LB = TMR0L;
				return( pg_timer_0_tmr_reg_current_value.Val );
			}
			#endif
			//--------------------------------------------------
			#if ( PGIM_TIMER_1 != PG_DISABLE )
			case PG_TIMER_1:
			{
				pg_timer_1_tmr_reg_current_value.byte.HB = TMR1H;
				pg_timer_1_tmr_reg_current_value.byte.LB = TMR1L;
				return( pg_timer_1_tmr_reg_current_value.Val );
			}
			#endif
			default:
			{
				return PG_TIMER_ERROR_ID;
			}
		}
	}
	//---[ END Timer Value ]---

	//---[ Timer Init ]---
	void	pg_timer_init( void ) {
		//--------------------------------------------------
		#if ( PGIM_TIMER_0 != PG_DISABLE )
			pg_timer_0_period		= ( ( 100.000 * PG_TIMER_FOSC_DIVIDER ) / PG_CLOCK );		// One step timer, without prescaler, by tens of nano-second [10 ns];
			pg_timer_0_count_max	= ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER ) / PG_CLOCK ) * PG_TIMER_0_TMR_REG_MAX );	// Max time with full tmr register, without prescaler, by tens of nano-second [10 ns];
			pg_timer_0_nanosec_min	= ( ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER / PG_CLOCK ) * PG_TIMER_0_TMR_REG_MIN ) * PG_TIMER_0_PRESCALER_MIN ) + PG_TIMER_0_OFFSET_GUARD );
			pg_timer_0_nanosec_max	= ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER / PG_CLOCK ) * PG_TIMER_0_TMR_REG_MAX ) * PG_TIMER_0_PRESCALER_MAX );	// Max time with full tmr register, with max prescaler, by tens of nano-second [10 ns];

			T0CON = 0b00001000;										// Stops Timer; 16-bit; Internal clock fron oscillator; No prescaler.
		#endif
		/*
				T0CON:
				-----------------------
				TIMER0 CONTROL REGISTER

				TMR0ON T08BIT T0CS T0SE PSA T0PS2 T0PS1 T0PS0
				bit 7 									bit 0
				---------------------------------------------
				bit 7 TMR0ON: Timer0 On/Off Control bit
								1 = Enables Timer0
								0 = Stops Timer0
				bit 6 T08BIT: Timer0 8-bit/16-bit Control bit
								1 = Timer0 is configured as an 8-bit timer/counter
								0 = Timer0 is configured as a 16-bit timer/counter
				bit 5 T0CS: Timer0 Clock Source Select bit
								1 = Transition on T0CKI pin
								0 = Internal instruction cycle clock (CLKO)
				bit 4 T0SE: Timer0 Source Edge Select bit
								1 = Increment on high-to-low transition on T0CKI pin
								0 = Increment on low-to-high transition on T0CKI pin
				bit 3 PSA: Timer0 Prescaler Assignment bit
								1 = TImer0 prescaler is NOT assigned. Timer0 clock input bypasses prescaler.
								0 = Timer0 prescaler is assigned. Timer0 clock input comes from prescaler output.
				bit 2-0 T0PS2:T0PS0: Timer0 Prescaler Select bits
								111 = 1:256 Prescale value
								110 = 1:128 Prescale value
								101 = 1:64 Prescale value
								100 = 1:32 Prescale value
								011 = 1:16 Prescale value
								010 = 1:8 Prescale value
								001 = 1:4 Prescale value
								000 = 1:2 Prescale value
		 */
		//--------------------------------------------------
		#if ( PGIM_TIMER_1 != PG_DISABLE )
			pg_timer_1_period		= ( ( 100.000 * PG_TIMER_FOSC_DIVIDER ) / PG_CLOCK );		// One step timer, without prescaler, by tens of nano-second [10 ns];
			pg_timer_1_count_max	= ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER ) / PG_CLOCK ) * PG_TIMER_1_TMR_REG_MAX );	// Max time with full tmr register, without prescaler, by tens of nano-second [10 ns];
			pg_timer_1_nanosec_min	= ( ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER / PG_CLOCK ) * PG_TIMER_1_TMR_REG_MIN ) * PG_TIMER_1_PRESCALER_MIN ) + PG_TIMER_1_OFFSET_GUARD );
			pg_timer_1_nanosec_max	= ( ( ( 100.000 * PG_TIMER_FOSC_DIVIDER / PG_CLOCK ) * PG_TIMER_1_TMR_REG_MAX ) * PG_TIMER_1_PRESCALER_MAX );	// Max time with full tmr register, with max prescaler, by tens of nano-second [10 ns];

			T1CON = 0b10000100;										// 16-bit; No prescaler; No sync; Internal clock fron oscillator; Stops Timer;
		#endif
		/*
				T1CON:
				-----------------------
				TIMER1 CONTROL REGISTER

				RD16 T1RUN T1CKPS1 T1CKPS0 T1OSCEN T1SYNC TMR1CS TMR1ON
				bit 7 											  bit 0
				-------------------------------------------------------
				bit 7 RD16: 16-bit Read/Write Mode Enable bit
								1 = Enables register read/write of TImer1 in one 16-bit operation
								0 = Enables register read/write of Timer1 in two 8-bit operations
				bit 6 T1RUN: Timer1 System Clock Status bit
								1 = Device clock is derived from Timer1 oscillator
								0 = Device clock is derived from another source
				bit 5-4 T1CKPS1:T1CKPS0: Timer1 Input Clock Prescale Select bits
								11 = 1:8 Prescale value
								10 = 1:4 Prescale value
								01 = 1:2 Prescale value
								00 = 1:1 Prescale value
				bit 3 T1OSCEN: Timer1 Oscillator Enable bit
								1 = Timer1 oscillator is enabled
								0 = Timer1 oscillator is shut off
								The oscillator inverter and feedback resistor are turned off to eliminate power drain.
				bit 2 T1SYNC: Timer1 External Clock Input Synchronization Select bit
								When TMR1CS = 1:
								1 = Do not synchronize external clock input
								0 = Synchronize external clock input
								When TMR1CS = 0:
								This bit is ignored. Timer1 uses the internal clock when TMR1CS = 0.
				bit 1 TMR1CS: Timer1 Clock Source Select bit
								1 = External clock from pin RC0/T1OSO/T13CKI (on the rising edge)
								0 = Internal clock (FOSC/4)
				bit 0 TMR1ON: Timer1 On bit
								1 = Enables Timer1
								0 = Stops Timer1				
		*/
	}
	//---[ END Timer Init ]---
#endif


