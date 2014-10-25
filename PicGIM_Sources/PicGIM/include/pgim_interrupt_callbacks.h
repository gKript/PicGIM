//
// pgim_interrupt_callbacks.h
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

/*!		\file			pgim_interrupt_callbacks.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#if	( PGIM_INTERRUPTS == PG_ENABLE )

	#ifndef _PGIM_INTERRUPTS_CALLBACKS_H_
		#define	_PGIM_INTERRUPTS_CALLBACKS_H_
		
		#include "pgim_defines.h"
		
		#if ( PG_INTERRUPT_AUTO_HANDLER == PG_DISABLE )
			/*!
				\brief	This is the call for the User Interrupt Handler. \n The code for this function must be placed by the user in the relative function in pgim_interrupt_callbacks.c  
				\attention	Please note that in any case \b PicGIM will put my_isr() function in the interrupt vector. \n So upon receipt of an interrupt will be call my_isr() which will call the pgim_interrupt_event() that deals of calling the correct handler and to clean the bit of the event. \n If you want to completely manage the interrupts in autonomy is necessary to disable completely the module. Please see the \b caller \b graph for this function.
				\see \ref interruptconfenm
			*/
			char	pg_interrupt_user_event_handler( void );
		#endif

		#if ( PG_INTERRUPT_INT0 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_INT0 . 
			*/
			void pg_interrupts_event_int0( void );
		#endif
		#if ( PG_INTERRUPT_INT1 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_INT1 . 
			*/
			void pg_interrupts_event_int1( void );
		#endif
		#if ( PG_INTERRUPT_INT2 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_INT2 . 
			*/
			void pg_interrupts_event_int2( void );
		#endif
		#if ( PG_INTERRUPT_TMR0 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_TMR0 . 
			*/
			void pg_interrupts_event_tmr0( void );
		#endif
		#if ( PG_INTERRUPT_TMR1 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_TMR1 . 
			*/
			void pg_interrupts_event_tmr1( void );
		#endif		
		#if ( PG_INTERRUPT_TMR2 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_TMR2 . 
			*/
			void pg_interrupts_event_tmr2( void );
		#endif		
		#if ( PG_INTERRUPT_RB0 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_RB0 . 
			*/
			void pg_interrupts_event_rbo( void );
		#endif
		#if ( PG_INTERRUPT_AD == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_AD . 
			*/
			void pg_interrupts_event_ad( void );
		#endif
		#if ( PG_INTERRUPT_USARTRC == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_USARTRC . 
			*/
			void pg_interrupts_event_usartrc( void );
		#endif
		#if ( PG_INTERRUPT_USARTTX == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_USARTTX . 
			*/
			void pg_interrupts_event_usarttx( void );
		#endif
		#if ( PG_INTERRUPT_SSP == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_SSP . 
			*/
			void pg_interrupts_event_ssp( void );
		#endif
		#if ( PG_INTERRUPT_CCP1 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_CCP1 . 
			*/
			void pg_interrupts_event_ccp1( void );
		#endif
		#if ( PG_INTERRUPT_CCP2 == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_CCP2 . 
			*/
			void pg_interrupts_event_ccp2( void );
		#endif
		#if ( PG_INTERRUPT_OSCF == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_OSCF . 
			*/
			void pg_interrupts_event_oscf( void );
		#endif
		#if ( PG_INTERRUPT_CM == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_CM . 
			*/
			void pg_interrupts_event_cm( void );
		#endif
		#if ( PG_INTERRUPT_EE == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_EE . 
			*/
			void pg_interrupts_event_ee( void );
		#endif
		#if ( PG_INTERRUPT_BCL == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_BCL . 
			*/
			void pg_interrupts_event_bcl( void );
		#endif
		#if ( PG_INTERRUPT_HLVD == PG_ENABLE )
			/*!	
				\brief	This is the callback for the event \ref PG_INTERRUPT_HLVD . 
			*/
			void pg_interrupts_event_hlvd( void );
		#endif
		
	#endif /* _PGIM_INTERRUPTS_CALLBACKS_H_ */
#endif


