/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_pwm_setup_public.h
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
		\file		pgim_pwm_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		PWM module configuration public file.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_PWM_SETUP_PUBLIC_H_
	#define _PGIM_PWM_SETUP_PUBLIC_H_

	#if ( PGIM_PWM == PG_ENABLE )
	
		//		P W M   C H A N N E L S   E N A B L I N G
		#define PGIM_PWM_1							PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		#define PGIM_PWM_2							PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		
		//		E N H A N C E D   M O D E
		#define PG_PWM_1_ENHANCED					PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_PWM_2_ENHANCED					PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		
		//		E N H A N C E D   M O D E   C O N F I G U R A T I O N
		#define PG_PWM_1_OUT_CONF					SINGLE_OUT		//!< Must be: SINGLE_OUT || HALF_OUT || FULL_OUT_FWD || FULL_OUT_REV
		#define PG_PWM_1_OUT_MODE					PWM_MODE_1		//!< Must be: PWM_MODE_1 || PWM_MODE_2 || PWM_MODE_3 || PWM_MODE_4
	
		#define PG_PWM_2_OUT_CONF					SINGLE_OUT		//!< Must be: SINGLE_OUT || HALF_OUT || FULL_OUT_FWD || FULL_OUT_REV
		#define PG_PWM_2_OUT_MODE					PWM_MODE_1		//!< Must be: PWM_MODE_1 || PWM_MODE_2 || PWM_MODE_3 || PWM_MODE_4
		
		#define PG_PWM_DEAD_TIME					12.000			//!< A value in micro-seconds [us]. Used only in HalfBridge mode!
		
		#define PG_PWM_AUTO_SHUTDOWN				PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_PWM_AUTO_SHUTDOWN_MODE			PG_AUTOMATIC	//!< Must be: PG_MANUAL || PG_AUTOMATIC
		#define PG_PWM_AUTO_SHUTDOWN_STATE_AC		PG_TRISTATE		//!< Must be: PG_TRISTATE || PG_HIGH || PG_LOW
		#define PG_PWM_AUTO_SHUTDOWN_STATE_BD		PG_TRISTATE		//!< Must be: PG_TRISTATE || PG_HIGH || PG_LOW
		
		//		D U T Y - C Y C L E   R E S O L U T I O N   M A X   C A L C U L A T I O N
		#define PGIM_PWM_DC_RESOLUTION_MAX_CALC		PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		
	#endif

#endif /* _PGIM_PWM_SETUP_PUBLIC_H_ */


