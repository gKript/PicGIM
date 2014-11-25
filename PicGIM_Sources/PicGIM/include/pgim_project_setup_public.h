//
// pgim_project_setup_public.h
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

/*!		\file			pgim_project_setup_public.h
		\version		0.5
		\date			2002 - 2014
		\brief			Public file to enter the basic parameters of the project.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_PROJECT_SETUP_PUBLIC_H_
	#define	_PGIM_PROJECT_SETUP_PUBLIC_H_

	//	P R O J E C T   D E T A I L S
	#define PG_PROJECT_NAME												//!< The name of your Project
	#define PG_PROJECT_ORGANIZATION										//!< The name of your Organization
	#define PG_PROJECT_AUTHOR											//!< Your name or, if you like, your nickname
	#define PG_PROJECT_VERSION											//!< The version of your project
	#define PG_PROJECT_STATE					PG_DEBUG				//!< Must be: PG_DEBUG  ||  PG_RELEASE

	//	H A R D W A R E   C O N F I G   M A I N   S Y S T E M
	#define PG_CLOCK							37.250					//!< The CORE FREQUENCY of the CPU in your project. Unit of measure is expressed in [MHz]. Accuracy: X.XXX. \note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, you need to consider the value of the \b oscillator/crystal and eventually of the \b PLL.						\attention		4MHz is the minimum clock frequency managed by \b PicGIM. \n If you set a lower frequency 4MHz functions of delay will definitely inaccurate.
	#define PG_USER_SUPPLY						5.00					//!< The power supply VOLTAGE of the MCU in your project. Unit of measure is expressed in [V]. Accuracy: X.XX
	#define PG_USE_INTERNAL_OSC					PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
	
	//	P I C G I M   B E H A V I O U R
	#define PG_VERBOSE							PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
	#define PG_SUGGESTION						PG_DISABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
	#define PG_PROJECT_INFO_SHOW				PG_DISABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE

#endif 


