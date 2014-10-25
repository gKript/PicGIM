//
// pgim_pwm_setup_public.h
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

/*!		\file			pgim_pwm_setup_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			PWM module configuration public file
		\details		The modules supported are PWM1 and PWM2
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_PWM_SETUP_PUBLIC_H_
	#define _PGIM_PWM_SETUP_PUBLIC_H_

//	#if ( PGIM_PWM == PG_ENABLE )
	
		//		C H A N N E L S   E N A B L I N G
		#define PGIM_PWM_1							PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		#define PGIM_PWM_2							PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE

		
		//		E N H A N C E D   M O D E
		#define PG_PWM_1_ENHANCED					PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
		#define PG_PWM_2_ENHANCED					PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE

		
		//		E N H A N C E D   M O D E   C O N F I G U R A T I O N
		#define PG_PWM_1_OUT_CONF					HALF_OUT		//!< Must be: SINGLE_OUT || HALF_OUT || FULL_OUT_FWD || FULL_OUT_REV
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
		
//	#endif
#endif /* _PGIM_PWM_SETUP_PUBLIC_H_ */


