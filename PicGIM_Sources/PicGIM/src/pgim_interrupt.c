//
// pgim_interrupt.c
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

/*!		\file			pgim_interrupt.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if	( PGIM_INTERRUPTS == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	volatile char pg_event_name;

	pg_int0_cb_pointer	pg_int0_callback;
	pg_int1_cb_pointer	pg_int1_callback;
	pg_int2_cb_pointer	pg_int2_callback;
	pg_tmr0_cb_pointer	pg_tmr0_callback;
	pg_tmr1_cb_pointer	pg_tmr1_callback;
	pg_tmr2_cb_pointer	pg_tmr2_callback;


	void	pg_interrupt_init( void ) {
		#if defined( __18CXX )
		RCONbits.IPEN = 0;
		pg_event_name = PG_INTERRUPT_EVENT_CLEAR;
		#endif
	}


	void	pg_interrupt_clear_bit( char int_event ) {
		switch( int_event ) {
			case PG_INTERRUPT_EVENT_INT0:
			{
				if ( PG_INTERRUPT_INT0_FLAG )
					PG_INTERRUPT_INT0_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_INT1:
			{
				if ( PG_INTERRUPT_INT1_FLAG )
					PG_INTERRUPT_INT1_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_INT2:
			{
				if ( PG_INTERRUPT_INT2_FLAG )
					PG_INTERRUPT_INT2_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR0:
			{
				if ( PG_INTERRUPT_TMR0_FLAG )
					PG_INTERRUPT_TMR0_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR1:
			{
				if ( PG_INTERRUPT_TMR1_FLAG )
					PG_INTERRUPT_TMR1_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR2:
			{
				if ( PG_INTERRUPT_TMR2_FLAG )
					PG_INTERRUPT_TMR2_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_RB0:
			{
				if ( PG_INTERRUPT_RB0_FLAG )
					PG_INTERRUPT_RB0_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_AD:
			{
				if ( PG_INTERRUPT_AD_FLAG )
					PG_INTERRUPT_AD_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_USARTRC:
			{
				if ( PG_INTERRUPT_USARTRC_FLAG )
					PG_INTERRUPT_USARTRC_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_USARTTX:
			{
				if ( PG_INTERRUPT_USARTTX_FLAG )
					PG_INTERRUPT_USARTTX_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_SSP:
			{
				if ( PG_INTERRUPT_SSP_FLAG )
					PG_INTERRUPT_SSP_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_CCP1:
			{
				if ( PG_INTERRUPT_CCP1_FLAG )
					PG_INTERRUPT_CCP1_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_CCP2:
			{
				if ( PG_INTERRUPT_CCP2_FLAG )
					PG_INTERRUPT_CCP2_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_OSCF:
			{
				if ( PG_INTERRUPT_OSCF_FLAG )
					PG_INTERRUPT_OSCF_FLAG = PG_CLEAR;
				break;
			}
			case PG_INTERRUPT_EVENT_CM:
			{
				if ( PG_INTERRUPT_CM_FLAG )
					PG_INTERRUPT_CM_FLAG = PG_CLEAR;
				break;
			}
			#if ! defined( PGIM_P18F97J60 )
				case PG_INTERRUPT_EVENT_EE:
				{
					if ( PG_INTERRUPT_EE_FLAG )
						PG_INTERRUPT_EE_FLAG = PG_CLEAR;
					break;
				}
			#endif
			case PG_INTERRUPT_EVENT_BCL:
			{
				if ( PG_INTERRUPT_BCL_FLAG )
					PG_INTERRUPT_BCL_FLAG = PG_CLEAR;
				break;
			}
		}
		pg_event_name = PG_INTERRUPT_EVENT_CLEAR;
	}


	void	pg_interrupt_enable_set( char int_event , char int_state ) {
		switch( int_event ) {
			case PG_INTERRUPT_EVENTS:
			{
				INTCONbits.GIE = int_state;
				INTCONbits.PEIE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_GLOBAL:
			{
				INTCONbits.GIE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_PERIPHERAL:
			{
				INTCONbits.PEIE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_INT0:
			{
				if ( PG_INTERRUPT_INT0 == PG_ENABLE ) {
					PG_INTERRUPT_INT0_ENABLE = int_state;
					if ( int_state == PG_ENABLE ) {
						T_B0 = PG_IN;
						ADCON1 = 0x0F;
					}
				}
				break;
			}
			case PG_INTERRUPT_EVENT_INT1:
			{
				if ( PG_INTERRUPT_INT1 == PG_ENABLE )
					PG_INTERRUPT_INT0_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_INT2:
			{
				if ( PG_INTERRUPT_INT1 == PG_ENABLE )
					PG_INTERRUPT_INT0_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR0:
			{
				if ( PG_INTERRUPT_TMR0 == PG_ENABLE )
					PG_INTERRUPT_TMR0_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR1:
			{
				if ( PG_INTERRUPT_TMR1 == PG_ENABLE )
					PG_INTERRUPT_TMR1_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_TMR2:
			{
				if ( PG_INTERRUPT_TMR2 == PG_ENABLE )
					PG_INTERRUPT_TMR2_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_RB0:
			{
				if ( PG_INTERRUPT_RB0 == PG_ENABLE )
					PG_INTERRUPT_RB0_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_AD:
			{
				if ( PG_INTERRUPT_AD == PG_ENABLE )
					PG_INTERRUPT_AD_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_USARTRC:
			{
				if ( PG_INTERRUPT_USARTRC == PG_ENABLE )
					PG_INTERRUPT_USARTRC_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_USARTTX:
			{
				if ( PG_INTERRUPT_USARTTX == PG_ENABLE )
					PG_INTERRUPT_USARTTX_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_SSP:
			{
				if ( PG_INTERRUPT_SSP == PG_ENABLE )
					PG_INTERRUPT_SSP_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_CCP1:
			{
				if ( PG_INTERRUPT_CCP1 == PG_ENABLE )
					PG_INTERRUPT_CCP1_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_CCP2:
			{
				if ( PG_INTERRUPT_CCP2 == PG_ENABLE )
					PG_INTERRUPT_CCP2_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_OSCF:
			{
				if ( PG_INTERRUPT_OSCF == PG_ENABLE )
					PG_INTERRUPT_OSCF_ENABLE = int_state;
				break;
			}
			case PG_INTERRUPT_EVENT_CM:
			{
				if ( PG_INTERRUPT_CM == PG_ENABLE )
					PG_INTERRUPT_CM_ENABLE = int_state;
				break;
			}
			#if ! defined( PGIM_P18F97J60 )
				case PG_INTERRUPT_EVENT_EE:
				{
					if ( PG_INTERRUPT_EE == PG_ENABLE )
						PG_INTERRUPT_EE_ENABLE = int_state;
					break;
				}
			#endif
			case PG_INTERRUPT_EVENT_BCL:
			{
				if ( PG_INTERRUPT_BCL == PG_ENABLE )
					PG_INTERRUPT_BCL_ENABLE = int_state;
				break;
			}
		}
		pg_interrupt_clear_bit( int_event );
	}


	char	pg_interrupt_get( void ) {
		if ( ( PG_INTERRUPT_INT0 == PG_ENABLE ) && ( PG_INTERRUPT_INT0_FLAG ) )
			return PG_INTERRUPT_EVENT_INT0;
		if ( ( PG_INTERRUPT_INT1 == PG_ENABLE ) && ( PG_INTERRUPT_INT1_FLAG ) )
			return PG_INTERRUPT_EVENT_INT1;
		if ( ( PG_INTERRUPT_INT2 == PG_ENABLE ) && ( PG_INTERRUPT_INT2_FLAG ) )
			return PG_INTERRUPT_EVENT_INT2;
		if ( ( PG_INTERRUPT_TMR0 == PG_ENABLE ) && ( PG_INTERRUPT_TMR0_FLAG ) )
			return PG_INTERRUPT_EVENT_TMR0;
		if ( ( PG_INTERRUPT_TMR1 == PG_ENABLE ) && ( PG_INTERRUPT_TMR1_FLAG ) )
			return PG_INTERRUPT_EVENT_TMR1;
		if ( ( PG_INTERRUPT_TMR2 == PG_ENABLE ) && ( PG_INTERRUPT_TMR2_FLAG ) )
			return PG_INTERRUPT_EVENT_TMR2;
		if ( ( PG_INTERRUPT_RB0 == PG_ENABLE ) && ( PG_INTERRUPT_RB0_FLAG ) )
			return PG_INTERRUPT_EVENT_RB0;
		if ( ( PG_INTERRUPT_AD == PG_ENABLE ) && ( PG_INTERRUPT_AD_FLAG ) )
			return PG_INTERRUPT_EVENT_AD;
		if ( ( PG_INTERRUPT_USARTRC == PG_ENABLE ) && ( PG_INTERRUPT_AD_FLAG ) )
			return PG_INTERRUPT_EVENT_USARTRC;
		if ( ( PG_INTERRUPT_USARTTX == PG_ENABLE ) && ( PG_INTERRUPT_USARTTX_FLAG ) )
			return PG_INTERRUPT_EVENT_USARTTX;
		if ( ( PG_INTERRUPT_SSP == PG_ENABLE ) && ( PG_INTERRUPT_SSP_FLAG ) )
			return PG_INTERRUPT_EVENT_SSP;
		if ( ( PG_INTERRUPT_CCP1 == PG_ENABLE ) && ( PG_INTERRUPT_CCP1_FLAG ) )
			return PG_INTERRUPT_EVENT_CCP1;
		if ( ( PG_INTERRUPT_CCP2 == PG_ENABLE ) && ( PG_INTERRUPT_CCP2_FLAG ) )
			return PG_INTERRUPT_EVENT_CCP2;
		if ( ( PG_INTERRUPT_OSCF == PG_ENABLE ) && ( PG_INTERRUPT_OSCF_FLAG ) )
			return PG_INTERRUPT_EVENT_OSCF;
		if ( ( PG_INTERRUPT_CM == PG_ENABLE ) && ( PG_INTERRUPT_CM_FLAG ) )
			return PG_INTERRUPT_EVENT_CM;
		#if !defined( PGIM_P18F97J60 )
			if ( ( PG_INTERRUPT_EE == PG_ENABLE ) && ( PG_INTERRUPT_EE_FLAG ) )
				return PG_INTERRUPT_EVENT_EE;
		#endif
		if ( ( PG_INTERRUPT_BCL == PG_ENABLE ) && ( PG_INTERRUPT_BCL_FLAG ) )
			return PG_INTERRUPT_EVENT_BCL;
		return PG_INTERRUPT_EVENT_CLEAR;
	}


	#if ( PG_INTERRUPT_AUTO_HANDLER == PG_ENABLE )


	char	pg_interrupt_auto_event_handler( void ) {
		pg_event_name = pg_interrupt_get( );
		if ( pg_event_name != PG_INTERRUPT_EVENT_CLEAR ) {
			switch( pg_event_name ) {
					#if	( PG_INTERRUPT_INT0 == PG_ENABLE )
				case PG_INTERRUPT_EVENT_INT0:
				{
					//pg_interrupts_event_int0( );
					pg_int0_callback();
					PG_INTERRUPT_INT0_FLAG = PG_CLEAR;
					break;
				}
					#endif
					#if	( PG_INTERRUPT_INT1 == PG_ENABLE )
				case PG_INTERRUPT_EVENT_INT1:
				{
//					INTCON2bits.RBPU = 0;
//					INTCON2bits.RBIP = 1;
//					pg_interrupts_event_int1( );
					pg_int1_callback();
					PG_INTERRUPT_INT1_FLAG = PG_CLEAR;
					break;
				}
					#endif
					#if	( PG_INTERRUPT_INT2 == PG_ENABLE )
				case PG_INTERRUPT_EVENT_INT2:
				{
//					INTCON2bits.RBPU = 0;
//					INTCON2bits.RBIP = 1;
//					pg_interrupts_event_int2( );
					pg_int2_callback();
					PG_INTERRUPT_INT2_FLAG = PG_CLEAR;
					break;
				}
					#endif
					#if	( PG_INTERRUPT_TMR0 == PG_ENABLE ) && ( PGIM_TIMER_0 != PG_DISABLE ) && ( PGIM_TIMER == PG_ENABLE )
				case PG_INTERRUPT_EVENT_TMR0:
				{
					//							if ( PG_INTERRUPT_TMR0_FLAG ) {
					if ( PGIM_TIMER_0 == PG_ENABLE_1_SHOT )
						T0CONbits.TMR0ON = 0;
					TMR0L = pg_timer_0_tmr_reg_set_save.byte.LB;		//!< Restore Timer Set value
					TMR0H = pg_timer_0_tmr_reg_set_save.byte.HB;		//!< Restore Timer Set value
//					pg_interrupts_event_tmr0( );
					pg_tmr0_callback();
					//							}
					break;
				}
					#endif
					#if	( PG_INTERRUPT_TMR1 == PG_ENABLE ) && ( PGIM_TIMER_1 != PG_DISABLE ) && ( PGIM_TIMER == PG_ENABLE )
				case PG_INTERRUPT_EVENT_TMR1:
				{
					//							if ( PG_INTERRUPT_TMR1_FLAG == PG_ENABLE ) {
					if ( PGIM_TIMER_1 == PG_ENABLE_1_SHOT )
						T1CONbits.TMR1ON = 0;
					TMR1L = pg_timer_1_tmr_reg_set_save.byte.LB;
					TMR1H = pg_timer_1_tmr_reg_set_save.byte.HB;
//					pg_interrupts_event_tmr1( );
					pg_tmr1_callback();
					//							}
					break;
				}
					#endif
					#if	( PG_INTERRUPT_TMR2 == PG_ENABLE )
				case PG_INTERRUPT_EVENT_TMR2:
				{
					if ( PG_INTERRUPT_TMR2_FLAG ) {
						pg_interrupts_event_tmr2( );
						PG_INTERRUPT_TMR2_FLAG = PG_CLEAR;
					}
					break;
				}
					#endif
					#if	( PG_INTERRUPT_RB0 == PG_ENABLE )
				case PG_INTERRUPT_EVENT_RB0:
				{
					INTCON2bits.RBPU = 0;
					INTCON2bits.RBIP = 1;
					if ( PG_INTERRUPT_RB0_FLAG ) {
						pg_interrupts_event_rb0( );
						PG_INTERRUPT_RB0_FLAG = PG_CLEAR;
					}
					break;
				}
					#endif
					#if	( PG_INTERRUPT_AD == PG_ENABLE )
				case PG_INTERRUPT_EVENT_AD:
				{
					if ( PG_INTERRUPT_AD_FLAG ) {
						pg_interrupts_event_ad( );
						PG_INTERRUPT_AD_FLAG = PG_CLEAR;
					}
					break;
				}
					#endif
				case PG_INTERRUPT_EVENT_USARTRC:
				{
					if ( PG_INTERRUPT_USARTRC_FLAG ) {

						PG_INTERRUPT_USARTRC_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_USARTTX:
				{
					if ( PG_INTERRUPT_USARTTX_FLAG ) {

						PG_INTERRUPT_USARTTX_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_SSP:
				{
					if ( PG_INTERRUPT_SSP_FLAG ) {

						PG_INTERRUPT_SSP_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_CCP1:
				{
					if ( PG_INTERRUPT_CCP1_FLAG ) {
			//			pg_interrupts_event_ccp1( );
						PG_INTERRUPT_CCP1_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_CCP2:
				{
					if ( PG_INTERRUPT_CCP2_FLAG ) {

						PG_INTERRUPT_CCP2_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_OSCF:
				{
					if ( PG_INTERRUPT_OSCF_FLAG ) {

						PG_INTERRUPT_OSCF_FLAG = PG_CLEAR;
					}
					break;
				}
				case PG_INTERRUPT_EVENT_CM:
				{
					if ( PG_INTERRUPT_CM_FLAG ) {
					
						PG_INTERRUPT_CM_FLAG = PG_CLEAR;
					}
					break;
				}
					#if ! defined( PGIM_P18F97J60 )
				case PG_INTERRUPT_EVENT_EE:
				{
					if ( PG_INTERRUPT_EE_FLAG ) {

						PG_INTERRUPT_EE_FLAG = PG_CLEAR;
					}
					break;
				}
					#endif
				case PG_INTERRUPT_EVENT_BCL:
				{
					if ( PG_INTERRUPT_BCL_FLAG ) {

						PG_INTERRUPT_BCL_FLAG = PG_CLEAR;
					}
					break;
				}
			}
		}
		return pg_event_name;
	}


	void	pg_event_attach( int event , void (*pg_event_callback)(void) ) {
		switch( event ) {
			case PG_EVENT_INT0 : {
				pg_int0_callback = pg_event_callback;
				break;
			}
			case PG_EVENT_INT1 : {
				pg_int1_callback = pg_event_callback;
				break;
			}
			case PG_EVENT_INT2 : {
				pg_int2_callback = pg_event_callback;
				break;
			}
			case PG_EVENT_TMR0 : {
				pg_tmr0_callback = pg_event_callback;
				break;
			}
			case PG_EVENT_TMR1 : {
				pg_tmr1_callback = pg_event_callback;
				break;
			}
			case PG_EVENT_TMR2 : {
				pg_tmr2_callback = pg_event_callback;
				break;
			}
		}
	}

	#endif
#endif


