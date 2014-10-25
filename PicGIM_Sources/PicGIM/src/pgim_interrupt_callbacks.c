//
// pgim_interrupt_callbacks.c
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

/*!		\file			pgim_interrupt_callbacks.c
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

	/////////////////////////////////////////////////////////////////////////////////////////
	//  C A L L B A C K S   T O   A U T O M A T I C   H A N D L E   I T E R R U P T S   -   
	//
	//      P U T   Y O U R   C O D E   I N S I D E
	/////////////////////////////////////////////////////////////////////////////////////////

	#if ( PG_INTERRUPT_AUTO_HANDLER == PG_DISABLE )


	char	pg_interrupt_user_event_handler( void ) {
//------  U S E R   E V E N T   H A N D L E R    -    P U T   Y O U R   C O D E   H E R E --------





//-----------------------------------------------------------------------------------------
	}
	#endif

	/////////////////////////////////////////////////////////////////////////////////////////
	//  C A L L B A C K S   T O   A U T O M A T I C   H A N D L E   I T E R R U P T S   -   
	//
	//      P U T   Y O U R   C O D E   I N S I D E   T H E M
	/////////////////////////////////////////////////////////////////////////////////////////


	#if	PG_INTERRUPT_INT0 == PG_ENABLE
		void	pg_interrupts_event_int0( void ) {
//------  I N T 0    -    P U T   Y O U R   C O D E   H E R E -----------------------------------


			L_B2 ^= 1;


//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_INT1 == PG_ENABLE
		void	pg_interrupts_event_int1( void ) {
//------  I N T 1    -    P U T   Y O U R   C O D E   H E R E -----------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_INT2 == PG_ENABLE
		void	pg_interrupts_event_int2( void ) {
//------  I N T 2    -    P U T   Y O U R   C O D E   H E R E -----------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_RB0 == PG_ENABLE
		void	pg_interrupts_event_rb0( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_TMR0 == PG_ENABLE
		void	pg_interrupts_event_tmr0( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------


			L_B1 ^= 1;


//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_TMR1 == PG_ENABLE
		void	pg_interrupts_event_tmr1( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------


			L_B3 ^= 1;


//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_TMR2 == PG_ENABLE
		void	pg_interrupts_event_tmr2( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_RB0 == PG_ENABLE
		void	pg_interrupts_event_rb0( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_AD == PG_ENABLE
		void	pg_interrupts_event_ad( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------


//			L_B3 ^= 1;


//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_USARTRC == PG_ENABLE
		void	pg_interrupts_event_usartrc( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_USARTTX == PG_ENABLE
		void	pg_interrupts_event_usarttx( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_SSP == PG_ENABLE
		void	pg_interrupts_event_ssp( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_CCP1 == PG_ENABLE
		void	pg_interrupts_event_ccp1( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_CCP2 == PG_ENABLE
		void	pg_interrupts_event_ccp2( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_CCP2 == PG_ENABLE
		void	pg_interrupts_event_ccp2( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_OSCF == PG_ENABLE
		void	pg_interrupts_event_oscf( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_CM == PG_ENABLE
		void	pg_interrupts_event_cm( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_EE == PG_ENABLE
		void	pg_interrupts_event_ee( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_BCL == PG_ENABLE
		void	pg_interrupts_event_bcl( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	#if	PG_INTERRUPT_HLVD == PG_ENABLE
		void	pg_interrupts_event_hlvd( void ) {
//------  R B 0    -    P U T   Y O U R   C O D E   H E R E -------------------------------------





//------------------------------------------------------------------------------------------
		}
	#endif
	
	
#endif
