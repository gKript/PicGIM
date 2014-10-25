//
// picgim_main.h
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

/*!		\file			picgim_main.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
		\warning		This file is to be included only in the file where is the \b main() function.

*/

#ifndef _GIM_H_
	#define	_GIM_H_

	#include "picgim.h"
	
	/*!
		\brief		To correct initialize the PicGIM library
	*/
	void pg_initialize( void );

	#if	( PGIM_INTERRUPTS == PG_ENABLE )
		#pragma code my_isr = 0x08

		void my_isr( void ) {
			_asm
			GOTO pgim_interrupt_event
			_endasm
		}
		
		#pragma code
		#pragma interrupt pgim_interrupt_event

		void pgim_interrupt_event( void ) {
		#if PG_INTERRUPT_AUTO_HANDLER == PG_ENABLE
			pg_interrupt_auto_event_handler();
		#else
			pg_interrupt_user_event_handler();
		#endif
			pg_interrupt_clear_bit(pg_event_name);
		}
	#endif

#endif 

