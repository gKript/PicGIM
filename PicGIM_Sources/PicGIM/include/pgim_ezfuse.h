/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ezfuse.h
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
		\file		pgim_ezfuse.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily set the fuses to start a project.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_EZFUSE_H_
	#define _PGIM_EZFUSE_H_
	
	//-----------------------------------------------------
	#if defined( __18CXX ) 
		
		#if defined( __18F2550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2550.h"
			#define		PGIM_P18F2550
		
		#elif defined( __18F2320 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2320 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2320.h"
			#define		PGIM_P18F2320
		
		#elif defined( __18F4620 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4620 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4620.h"
			#define		PGIM_P18F4620
		
		#elif defined( __18F4550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4550.h"
			#define		PGIM_P18F4550
		
		#elif defined( __18F4553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4553.h"
			#define		PGIM_P18F4553
		
		#elif defined( __18F2553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2553.h"
			#define		PGIM_P18F2553
			
		#elif defined( __18F97J60 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F97J60 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f97J60.h"
			#define		PGIM_P18F97J60
			
		#elif defined( __18F4520 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4520 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4520.h"
			#define		PGIM_P18F4520
			
		#else
			#error	PicGIM >>> Core >>> !!!!!! MCU NOT SUPPORTED BY PICGIM. SORRY !!!!!!
		#endif
	#endif
	
	//-----------------------------------------------------	//kmod add section for xc8
	#if defined( __XC8 ) 
		
		#if defined( _18F2550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2550.h"
			#define		PGIM_P18F2550
		
		#elif defined( _18F2320 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2320 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2320.h"
			#define		PGIM_P18F2320
		
		#elif defined( _18F4620 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4620 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4620.h"
			#define		PGIM_P18F4620
		
		#elif defined( _18F4550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4550.h"
			#define		PGIM_P18F4550
		
		#elif defined( _18F4553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4553.h"
			#define		PGIM_P18F4553
		
		#elif defined( _18F2553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F2553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2553.h"
			#define		PGIM_P18F2553
			
		#elif defined( _18F97J60 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F97J60 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f97J60.h"
			#define		PGIM_P18F97J60
			
		#elif defined( _18F4520 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 18F4520 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4520.h"
			#define		PGIM_P18F4520
			
		#else
			#error	PicGIM >>> Core >>> !!!!!! MCU NOT SUPPORTED BY PICGIM. SORRY !!!!!!
		#endif
	#endif
	
	//-----------------------------------------------------
	#if defined( __24CXX ) 
		#if defined( __24FJ256GB110 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PicGIM >>> Core >>> Set 24FJ256GB110 as current cpu
			#endif

			#define		PGIM_P24FJ256GB110
		#else
			//	#error	PicGIM >>> Core >>> !!!!!! MCU NOT SUPPORTED BY PICGIM. SORRY !!!!!!
		#endif
	#endif

	//-----------------------------------------------------
	#if defined( __24CXX ) 
		#include <p24cxxx.h>
	#endif

#endif /* _PGIM_EZFUSE_H_ */

/*!	
	\page	SWC_EzFuse			Easy FUSE settingss
		\tableofcontents

		\n
		\image html easyfuse.png
		\n

		\endcode

		<b>EzFuse</b> is an easy way to configure the fuse and the basic parameters to start a project in a very short time. \n
		If you still do not know the modules of \a PicGIM then read this section specifies : \ref WPC_module

		\attention	This is  the only one COMPULSORY module so you can not disable it. \n
					But it will be possible to do it from the first release of the next MileStone 1.0 .

	\section		HOWezmp8		MPLAB 8 : How to select the microcontroller

		\htmlonly <hr> \endhtmlonly
		\endcode

		From the menu bar click <b>"Configure"</b>. Then click <b>"select device..."</b>. \n \n
		\image	html	cpuselect.jpg
		\n \n

		This will open the following dialog box. \n \n
		\image	html	cpuselected.jpg
		\n \n

		From the drop down menu you can choose the desired MCU. \n \n
		\image	html	cpuselecting.jpg
		\n \n

		<b>PicGIM</b> does not support all MCU listed but only a few. The list of supported MCU is constantly updated. \n
		<b>PicGIM</b> is an open source project so you can add yourself a specific MCU. \n \n

		Here you can refer to the specifications for the \a MCU supported by \a PicGIM : \subpage cpu

	\section		HOWezmpx		MPLAB X : How to select the microcontroller

		\htmlonly <hr> \endhtmlonly
		\endcode

		From the Dashboard, click the icon highlighted in yellow in the figure below. \n \n
		\image	html	mplabx-dasboard.png
		\n \n

		This will open the following dialog box. \n \n
		\image	html	mplabx-project-properities.png
		\n \n

		From the drop down menu you can choose the desired MCU. \n \n
		\n \n

		<b>PicGIM</b> does not support all MCU listed but only a few. The list of supported MCU is constantly updated. \n
		<b>PicGIM</b> is an open source project so you can add yourself a specific MCU. \n \n

		Here you can refer to the specifications for the \a MCU supported by \a PicGIM : \subpage cpu


	\section	SCM_cpu		Supported MCU by PicGIM

		\htmlonly <hr> \endhtmlonly
		\endcode

		These are the MCU currently supported by PicGIM. As already mentioned, the list is constantly updated. \n \n
		Check on http://www.gkript.org PicGIM that is always the latest version. \n
		As mentioned above, you can create your own support for one another MCU or request support PicGIM developers. \n \n

		\attention	Here a link to the file : \ref pgim_ezfuse.h \n
					This is not a file defined as public and therefore would not be edited. \n
					We suggest that you edit this file only if necessary and only if you know what you are doing.
			
			\subpage	MCU_PIC18F97J60	\n
			\subpage	MCU_PIC18F4620	\n
			\subpage	MCU_PIC18F4553	\n
			\subpage	MCU_PIC18F4550	\n
			\subpage	MCU_PIC18F4520	\n
			\subpage	MCU_PIC18F2553	\n
			\subpage	MCU_PIC18F2550	\n
			\subpage	MCU_PIC18F2320	\n \n \n

 */


 