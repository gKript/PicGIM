//
// pgim_interrupt_setup_public.h
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

/*!		\file			pgim_interrupt_setup_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_INTERRUPTS_SETUP_PUBLIC_H_
	#define	_PGIM_INTERRUPTS_SETUP_PUBLIC_H_

//	-------- Auto Interrupts Handler -----------------------------------------------------------
	
	#define PG_INTERRUPT_AUTO_HANDLER   PG_ENABLE			// PG_ENABLE	PG_DISABLE

//	-------- External Interrupts ----------------------------------------------------------------

	#define PG_INTERRUPT_INT0			PG_ENABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_INT1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_INT2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_RB0			PG_DISABLE			// PG_ENABLE	PG_DISABLE

//	-------- Internal Interrupts ----------------------------------------------------------------
	
	#define PG_INTERRUPT_TMR0			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_TMR1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_TMR2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_AD				PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_USARTRC        PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_USARTTX        PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_SSP			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_CCP1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_CCP2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_OSCF			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_CM				PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_EE				PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_BCL			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	#define PG_INTERRUPT_HLVD			PG_DISABLE			// PG_ENABLE	PG_DISABLE
	
#endif /* _PGIM_INTERRUPTS_SETUP_PUBLIC_H_ */


