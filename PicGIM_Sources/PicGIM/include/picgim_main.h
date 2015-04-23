/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		picgim_main.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

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
		\file		picgim_main.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		This is the file to include in the \b MAIN file. The file where is the \b main() function.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _GIM_H_
	#define	_GIM_H_

	#include "picgim.h"
	
	/*!
		\brief		To correct initialize the PicGIM library
	*/
	void pg_initialize( void );

	#if	( PGIM_EVENTS == PG_ENABLE )
		#pragma code my_isr = 0x08

		void my_isr( void ) {
			_asm
				GOTO pg_event_occurred
			_endasm
		}
		
		#pragma code
		#pragma interrupt pg_event_occurred

		void pg_event_occurred( void ) {
			#if PG_EVENT_AUTO_HANDLER == PG_ENABLE
				pg_event_auto_handler();
			#else
				if ( pg_user_handler_callback != NULL )
					pg_user_handler_callback();
			#endif
				pg_event_clear_bit( pg_event_name );
		}

	#endif

#endif 

