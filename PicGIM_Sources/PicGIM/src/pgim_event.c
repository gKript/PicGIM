/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_interrupt.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_interrupt.h

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
		\file		pgim_interrupt.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the interrupt.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public V3 license. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public V3 license. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/


#include "picgim.h"

#if	( PGIM_EVENTS == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	volatile char pg_event_name;

	pg_int0_cb_pointer		pg_int0_callback;
	pg_int1_cb_pointer		pg_int1_callback;
	pg_int2_cb_pointer		pg_int2_callback;
	pg_tmr0_cb_pointer		pg_tmr0_callback;
	pg_tmr1_cb_pointer		pg_tmr1_callback;
	pg_tmr2_cb_pointer		pg_tmr2_callback;
	pg_rb0_cb_pointer		pg_rb0_callback;
	pg_ad_cb_pointer		pg_ad_callback;
	pg_usartrc_cb_pointer	pg_usartrc_callback;
	pg_usarttx_cb_pointer	pg_usarttx_callback;
	pg_ssp_cb_pointer		pg_ssp_callback;
	pg_ccp1_cb_pointer		pg_ccp1_callback;
	pg_ccp2_cb_pointer		pg_ccp2_callback;
	pg_oscf_cb_pointer		pg_oscf_callback;
	pg_cm_cb_pointer		pg_cm_callback;
	pg_ee_cb_pointer		pg_ee_callback;
	pg_bcl_cb_pointer		pg_bcl_callback;

	pg_event_user_handler	pg_user_handler_callback;


	void	pg_event_init( void ) {
		RCONbits.IPEN = 0;
		pg_user_handler_callback = NULL;
		pg_event_name = PG_EVENT_CLEAR;
	}


	void	pg_event_clear_bit( char int_event ) {
		switch( int_event ) {
		#if	( PG_EVENT_SET_INT0 == PG_ENABLE )
			case PG_EVENT_INT0:
			{
				if ( PG_INTERRUPT_INT0_FLAG )
					PG_INTERRUPT_INT0_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT1 == PG_ENABLE )
			case PG_EVENT_INT1:
			{
				if ( PG_INTERRUPT_INT1_FLAG )
					PG_INTERRUPT_INT1_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT2 == PG_ENABLE )
			case PG_EVENT_INT2:
			{
				if ( PG_INTERRUPT_INT2_FLAG )
					PG_INTERRUPT_INT2_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR0 == PG_ENABLE )
			case PG_EVENT_TMR0:
			{
				if ( PG_INTERRUPT_TMR0_FLAG )
					PG_INTERRUPT_TMR0_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR1 == PG_ENABLE )
			case PG_EVENT_TMR1:
			{
				if ( PG_INTERRUPT_TMR1_FLAG )
					PG_INTERRUPT_TMR1_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR2 == PG_ENABLE )
			case PG_EVENT_TMR2:
			{
				if ( PG_INTERRUPT_TMR2_FLAG )
					PG_INTERRUPT_TMR2_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_RB0 == PG_ENABLE )
			case PG_EVENT_RB0:
			{
				if ( PG_INTERRUPT_RB0_FLAG )
					PG_INTERRUPT_RB0_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_AD == PG_ENABLE )
			case PG_EVENT_AD:
			{
				if ( PG_INTERRUPT_AD_FLAG )
					PG_INTERRUPT_AD_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTRC == PG_ENABLE )
			case PG_EVENT_USARTRC:
			{
				if ( PG_INTERRUPT_USARTRC_FLAG )
					PG_INTERRUPT_USARTRC_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTTX == PG_ENABLE )
			case PG_EVENT_USARTTX:
			{
				if ( PG_INTERRUPT_USARTTX_FLAG )
					PG_INTERRUPT_USARTTX_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_SSP == PG_ENABLE )
			case PG_EVENT_SSP:
			{
				if ( PG_INTERRUPT_SSP_FLAG )
					PG_INTERRUPT_SSP_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP1 == PG_ENABLE )
			case PG_EVENT_CCP1:
			{
				if ( PG_INTERRUPT_CCP1_FLAG )
					PG_INTERRUPT_CCP1_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP2 == PG_ENABLE )
			case PG_EVENT_CCP2:
			{
				if ( PG_INTERRUPT_CCP2_FLAG )
					PG_INTERRUPT_CCP2_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_OSCF == PG_ENABLE )
			case PG_EVENT_OSCF:
			{
				if ( PG_INTERRUPT_OSCF_FLAG )
					PG_INTERRUPT_OSCF_FLAG = PG_CLEAR;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CM == PG_ENABLE )
			case PG_EVENT_CM:
			{
				if ( PG_INTERRUPT_CM_FLAG )
					PG_INTERRUPT_CM_FLAG = PG_CLEAR;
				break;
			}
		#endif
			#if ! defined( PGIM_P18F97J60 )
				#if ( PG_EVENT_SET_EE == PG_ENABLE )
						case PG_EVENT_EE:
					{
						if ( PG_INTERRUPT_EE_FLAG )
							PG_INTERRUPT_EE_FLAG = PG_CLEAR;
						break;
					}
				#endif
			#endif
		#if ( PG_EVENT_SET_BCL == PG_ENABLE )
				case PG_EVENT_BCL:
			{
				if ( PG_INTERRUPT_BCL_FLAG )
					PG_INTERRUPT_BCL_FLAG = PG_CLEAR;
				break;
			}
		#endif
		}
		pg_event_name = PG_EVENT_CLEAR;
	}


	void	pg_event_set( char int_event , char int_state ) {
		pg_event_clear_bit( int_event );
		switch( int_event ) {
			case PG_EVENT_ANY: {
				INTCONbits.GIE = int_state;
				INTCONbits.GIEH = int_state;
				INTCONbits.GIEL = int_state;
				INTCONbits.PEIE = int_state;
				break;
			}
			case PG_EVENT_GLOBAL: {
				INTCONbits.GIE = int_state;
				INTCONbits.GIEH = int_state;
				INTCONbits.GIEL = int_state;
				break;
			}
			case PG_EVENT_PERIPHERAL: {
				INTCONbits.PEIE = int_state;
				break;
			}
		#if ( PG_EVENT_SET_INT0 == PG_ENABLE )
			case PG_EVENT_INT0: {
				PG_INTERRUPT_INT0_ENABLE = int_state;
//				INTCON2bits.RBPU = 0;				// Pull ups on Portb are enable
//				INTCON2bits.INTEDG0 = 0;			// Activates on raising edge
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT1 == PG_ENABLE )
			case PG_EVENT_INT1: {
//				EnablePullups();
				DisablePullups();
//				INTCON2bits.RBPU = 1;				// Pull ups on Portb are enable
//		INTCON2bits.INTEDG0 = 0;			// Activates on raising edge
				PG_INTERRUPT_INT1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT2 == PG_ENABLE )
			case PG_EVENT_INT2:	{
				PG_INTERRUPT_INT2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR0 == PG_ENABLE )
			case PG_EVENT_TMR0:	{
				PG_INTERRUPT_TMR0_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR1 == PG_ENABLE )
			case PG_EVENT_TMR1:	{
				PG_INTERRUPT_TMR1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR2 == PG_ENABLE )
			case PG_EVENT_TMR2:	{
				PG_INTERRUPT_TMR2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_RB0 == PG_ENABLE )
			case PG_EVENT_RB0:	{
				PG_INTERRUPT_RB0_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_AD == PG_ENABLE )
			case PG_EVENT_AD: {
				PG_INTERRUPT_AD_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTRC == PG_ENABLE )
			case PG_EVENT_USARTRC: {
				PG_INTERRUPT_USARTRC_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTTX == PG_ENABLE )
			case PG_EVENT_USARTTX: {
				PG_INTERRUPT_USARTTX_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_SSP == PG_ENABLE )
			case PG_EVENT_SSP: {
				PG_INTERRUPT_SSP_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP1 == PG_ENABLE )
			case PG_EVENT_CCP1: {
				PG_INTERRUPT_CCP1_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP2 == PG_ENABLE )
			case PG_EVENT_CCP2: {
				PG_INTERRUPT_CCP2_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_OSCF == PG_ENABLE )
			case PG_EVENT_OSCF: {
				PG_INTERRUPT_OSCF_ENABLE = int_state;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CM == PG_ENABLE )
			case PG_EVENT_CM: {
				PG_INTERRUPT_CM_ENABLE = int_state;
				break;
			}
		#endif
		#if ! defined( PGIM_P18F97J60 )
			#if ( PG_EVENT_SET_EE == PG_ENABLE )
				case PG_EVENT_EE: {
					PG_INTERRUPT_EE_ENABLE = int_state;
					break;
				}
			#endif
		#endif
		#if ( PG_EVENT_SET_BCL == PG_ENABLE )
			case PG_EVENT_BCL: {
				PG_INTERRUPT_BCL_ENABLE = int_state;
				break;
			}
		#endif
		}
	}


	char	pg_interrupt_get( void ) {
		#if ( PG_EVENT_SET_INT0 == PG_ENABLE )
			if ( ( PG_EVENT_SET_INT0 == PG_ENABLE ) && ( PG_INTERRUPT_INT0_FLAG ) )
				return PG_EVENT_INT0;
		#endif
		#if ( PG_EVENT_SET_INT1 == PG_ENABLE )
			if ( ( PG_EVENT_SET_INT1 == PG_ENABLE ) && ( PG_INTERRUPT_INT1_FLAG ) )
				return PG_EVENT_INT1;
		#endif
		#if ( PG_EVENT_SET_INT2 == PG_ENABLE )
			if ( ( PG_EVENT_SET_INT2 == PG_ENABLE ) && ( PG_INTERRUPT_INT2_FLAG ) )
				return PG_EVENT_INT2;
		#endif
		#if ( PG_EVENT_SET_TMR0 == PG_ENABLE )
			if ( ( PG_EVENT_SET_TMR0 == PG_ENABLE ) && ( PG_INTERRUPT_TMR0_FLAG ) )
				return PG_EVENT_TMR0;
		#endif
		#if ( PG_EVENT_SET_TMR1 == PG_ENABLE )
			if ( ( PG_EVENT_SET_TMR1 == PG_ENABLE ) && ( PG_INTERRUPT_TMR1_FLAG ) )
				return PG_EVENT_TMR1;
		#endif
		#if ( PG_EVENT_SET_TMR2 == PG_ENABLE )
			if ( ( PG_EVENT_SET_TMR2 == PG_ENABLE ) && ( PG_INTERRUPT_TMR2_FLAG ) )
				return PG_EVENT_TMR2;
		#endif
		#if ( PG_EVENT_SET_RB0 == PG_ENABLE )
			if ( ( PG_EVENT_SET_RB0 == PG_ENABLE ) && ( PG_INTERRUPT_RB0_FLAG ) )
				return PG_EVENT_RB0;
		#endif
		#if ( PG_EVENT_SET_AD == PG_ENABLE )
			if ( ( PG_EVENT_SET_AD == PG_ENABLE ) && ( PG_INTERRUPT_AD_FLAG ) )
				return PG_EVENT_AD;
		#endif
		#if ( PG_EVENT_SET_USARTRC == PG_ENABLE )
			if ( ( PG_EVENT_SET_USARTRC == PG_ENABLE ) && ( PG_INTERRUPT_AD_FLAG ) )
				return PG_EVENT_USARTRC;
		#endif
		#if ( PG_EVENT_SET_USARTTX == PG_ENABLE )
			if ( ( PG_EVENT_SET_USARTTX == PG_ENABLE ) && ( PG_INTERRUPT_USARTTX_FLAG ) )
				return PG_EVENT_USARTTX;
		#endif
		#if ( PG_EVENT_SET_SSP == PG_ENABLE )
			if ( ( PG_EVENT_SET_SSP == PG_ENABLE ) && ( PG_INTERRUPT_SSP_FLAG ) )
				return PG_EVENT_SSP;
		#endif
		#if ( PG_EVENT_SET_CCP1 == PG_ENABLE )
			if ( ( PG_EVENT_SET_CCP1 == PG_ENABLE ) && ( PG_INTERRUPT_CCP1_FLAG ) )
				return PG_EVENT_CCP1;
		#endif
		#if ( PG_EVENT_SET_CCP2 == PG_ENABLE )
			if ( ( PG_EVENT_SET_CCP2 == PG_ENABLE ) && ( PG_INTERRUPT_CCP2_FLAG ) )
				return PG_EVENT_CCP2;
		#endif
		#if ( PG_EVENT_SET_OSCF == PG_ENABLE )
			if ( ( PG_EVENT_SET_OSCF == PG_ENABLE ) && ( PG_INTERRUPT_OSCF_FLAG ) )
				return PG_EVENT_OSCF;
		#endif
		#if ( PG_EVENT_SET_CM == PG_ENABLE )
			if ( ( PG_EVENT_SET_CM == PG_ENABLE ) && ( PG_INTERRUPT_CM_FLAG ) )
				return PG_EVENT_CM;
		#endif
		#if !defined( PGIM_P18F97J60 )
			#if ( PG_EVENT_SET_EE == PG_ENABLE )
				if ( ( PG_EVENT_SET_EE == PG_ENABLE ) && ( PG_INTERRUPT_EE_FLAG ) )
					return PG_EVENT_EE;
			#endif
		#endif
		#if ( PG_EVENT_SET_BCL == PG_ENABLE )
			if ( ( PG_EVENT_SET_BCL == PG_ENABLE ) && ( PG_INTERRUPT_BCL_FLAG ) )
				return PG_EVENT_BCL;
		#endif
		return PG_EVENT_CLEAR;
	}


	#if ( PG_EVENT_AUTO_HANDLER == PG_ENABLE )


	char	pg_event_auto_handler( void ) {
		pg_event_name = pg_interrupt_get( );
		if ( pg_event_name != PG_EVENT_CLEAR ) {
			switch( pg_event_name ) {
				#if	( PG_EVENT_SET_INT0 == PG_ENABLE )
					case PG_EVENT_INT0: {
						pg_int0_callback();
						PG_INTERRUPT_INT0_FLAG = PG_CLEAR;
						break;
					}
				#endif
				#if	( PG_EVENT_SET_INT1 == PG_ENABLE )
					case PG_EVENT_INT1: {
						pg_int1_callback();
						PG_INTERRUPT_INT1_FLAG = PG_CLEAR;
						break;
					}
				#endif
				#if	( PG_EVENT_SET_INT2 == PG_ENABLE )
					case PG_EVENT_INT2: {
						pg_int2_callback();
						PG_INTERRUPT_INT2_FLAG = PG_CLEAR;
						break;
					}
				#endif
				#if	( PG_EVENT_SET_TMR0 == PG_ENABLE ) && ( PGIM_TIMER_0 != PG_DISABLE ) && ( PGIM_TIMER == PG_ENABLE )
					case PG_EVENT_TMR0: {
						if ( PGIM_TIMER_0 == PG_ENABLE_1_SHOT )
							T0CONbits.TMR0ON = 0;
						TMR0L = pg_timer_0_tmr_reg_set_save.byte.LB;		//!< Restore Timer Set value
						TMR0H = pg_timer_0_tmr_reg_set_save.byte.HB;		//!< Restore Timer Set value
						pg_tmr0_callback();
						break;
					}
				#endif
				#if	( PG_EVENT_SET_TMR1 == PG_ENABLE ) && ( PGIM_TIMER_1 != PG_DISABLE ) && ( PGIM_TIMER == PG_ENABLE )
					case PG_EVENT_TMR1: {
						if ( PGIM_TIMER_1 == PG_ENABLE_1_SHOT )
							T1CONbits.TMR1ON = 0;
						TMR1L = pg_timer_1_tmr_reg_set_save.byte.LB;
						TMR1H = pg_timer_1_tmr_reg_set_save.byte.HB;
						pg_tmr1_callback();
						break;
					}
				#endif
				#if	( PG_EVENT_SET_TMR2 == PG_ENABLE ) && ( PGIM_TIMER_2 != PG_DISABLE ) && ( PGIM_TIMER == PG_ENABLE )
					case PG_EVENT_TMR2: {
						if ( PGIM_TIMER_2 == PG_ENABLE_1_SHOT )
							T1CONbits.TMR2ON = 0;
						TMR2L = pg_timer_2_tmr_reg_set_save.byte.LB;
						TMR2H = pg_timer_2_tmr_reg_set_save.byte.HB;
						pg_tmr2_callback();
						break;
					}
				#endif
				#if	( PG_EVENT_SET_RB0 == PG_ENABLE )
					case PG_EVENT_RB0: {
						INTCON2bits.RBPU = 0;
						INTCON2bits.RBIP = 1;
						pg_rb0_callback();
						break;
					}
				#endif
				#if	( PG_EVENT_SET_AD == PG_ENABLE )
					case PG_EVENT_AD: {
						pg_ad_callback( );
						break;
					}
				#endif
				#if ( PG_EVENT_SET_USARTRC == PG_ENABLE )
					case PG_EVENT_USARTRC: {
						pg_usartrc_callback( );
						break;
					}
				#endif
				#if ( PG_EVENT_SET_USARTTX == PG_ENABLE )
					case PG_EVENT_USARTTX: {
						pg_usarttx_callback( );
						break;
					}
				#endif
				#if ( PG_EVENT_SET_SSP == PG_ENABLE )
					case PG_EVENT_SSP: {
						pg_ssp_callback();
						break;
					}
				#endif
				#if ( PG_EVENT_SET_CCP1 == PG_ENABLE )
					case PG_EVENT_CCP1: {
						pg_ccp1_callback();
						break;
					}
				#endif
				#if ( PG_EVENT_SET_CCP2 == PG_ENABLE )
					case PG_EVENT_CCP2: {
						pg_ccp2_callback();
						break;
					}
				#endif
				#if ( PG_EVENT_SET_OSCF == PG_ENABLE )
					case PG_EVENT_OSCF: {
						pg_oscf_callback();
						break;
					}
				#endif
				#if ( PG_EVENT_SET_CM == PG_ENABLE )
					case PG_EVENT_CM: {
						pg_cm_callback();
						break;
					}
				#endif
				#if ! defined( PGIM_P18F97J60 )
					#if ( PG_EVENT_SET_EE == PG_ENABLE )
							case PG_EVENT_EE: {
							pg_ee_callback();
							break;
						}
					#endif
				#endif
				#if ( PG_EVENT_SET_BCL == PG_ENABLE )
						case PG_EVENT_BCL: {
						pg_bcl_callback();
						break;
					}
				#endif
			}
		}
		return pg_event_name;
	}


	void	pg_event_attach( int event , void (*pg_event_callback)(void) ) {
		switch( event ) {
		#if	( PG_EVENT_SET_INT0 == PG_ENABLE )
			case PG_EVENT_INT0 : {
				pg_int0_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT1 == PG_ENABLE )
			case PG_EVENT_INT1 : {
				pg_int1_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_INT2 == PG_ENABLE )
			case PG_EVENT_INT2 : {
				pg_int2_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR0 == PG_ENABLE )
			case PG_EVENT_TMR0 : {
				pg_tmr0_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR1 == PG_ENABLE )
			case PG_EVENT_TMR1 : {
				pg_tmr1_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_TMR2 == PG_ENABLE )
			case PG_EVENT_TMR2 : {
				pg_tmr2_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_RB0 == PG_ENABLE )
			case PG_EVENT_RB0 : {
				pg_rb0_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_AD == PG_ENABLE )
			case PG_EVENT_AD : {
				pg_ad_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTRC == PG_ENABLE )
			case PG_EVENT_USARTRC : {
				pg_usartrc_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_USARTTX == PG_ENABLE )
			case PG_EVENT_USARTTX : {
				pg_usarttx_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_SSP == PG_ENABLE )
			case PG_EVENT_SSP : {
				pg_ssp_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP1 == PG_ENABLE )
			case PG_EVENT_CCP1 : {
				pg_ccp1_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CCP2 == PG_ENABLE )
			case PG_EVENT_CCP2 : {
				pg_ccp2_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_OSCF == PG_ENABLE )
			case PG_EVENT_OSCF : {
				pg_oscf_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_CM == PG_ENABLE )
			case PG_EVENT_CM : {
				pg_cm_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_EE == PG_ENABLE )
			case PG_EVENT_EE : {
				pg_ee_callback = pg_event_callback;
				break;
			}
		#endif
		#if ( PG_EVENT_SET_BCL == PG_ENABLE )
			case PG_EVENT_BCL : {
				pg_bcl_callback = pg_event_callback;
				break;
			}
		#endif
		}
	}


	void	pg_event_user_handler_attach( void (*pg_uh_callback)(void) ) {
		pg_user_handler_callback = pg_uh_callback;
	}

	#endif
#endif


