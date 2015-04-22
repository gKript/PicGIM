/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_buzzer.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_buzzer.h

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
		\file		pgim_buzzer.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		Functions to drive a buzzer.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public V3 license. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public V3 license. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
*/

#include "picgim.h"

#if ( PGIM_BUZZER == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	void	pg_buzzer_beep( _pg_Uint8 tone , _pg_Uint16 len ) {
		_pg_int16 i;
		PG_BUZZER_PIN_TRIS = PG_OUT;
		if ( tone == PG_BEEP_MID ) len /= 2;
		if ( tone == PG_BEEP_LOW ) len /= 4;
		for( i = 0 ; i < len ; i++ ) {
			PG_BUZZER_PIN = PG_ON;
			pg_delay_msec( tone );
			PG_BUZZER_PIN = PG_OFF;
			pg_delay_msec( tone );
		}
		PG_BUZZER_PIN = PG_OFF;
		PG_BUZZER_PIN_TRIS = PG_IN;
	}
#endif


