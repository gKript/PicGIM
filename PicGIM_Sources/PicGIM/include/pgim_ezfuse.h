//
// pgim_ezfuse.h
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

/*!		\file			pgim_ezfuse.h
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

#ifndef _PGIM_EZFUSE_H_
	#define _PGIM_EZFUSE_H_
	
	//-----------------------------------------------------
	#if defined( __18CXX ) 
		
		#if defined( __18F2550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F2550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2550.h"
			#define		PGIM_P18F2550
		
		#elif defined( __18F2320 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F2320 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2320.h"
			#define		PGIM_P18F2320
		
		#elif defined( __18F4620 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F4620 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4620.h"
			#define		PGIM_P18F4620
		
		#elif defined( __18F4550 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F4550 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4550.h"
			#define		PGIM_P18F4550
		
		#elif defined( __18F4553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F4553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4553.h"
			#define		PGIM_P18F4553
		
		#elif defined( __18F2553 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F2553 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f2553.h"
			#define		PGIM_P18F2553
			
		#elif defined( __18F97J60 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F97J60 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f97J60.h"
			#define		PGIM_P18F97J60
			
		#elif defined( __18F4520 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 18F4520 as current mcu
			#endif
			#include ".\pgim_mcu\pgim_18f4520.h"
			#define		PGIM_P18F4520
			
		#else
			#error	PG_HS_PG PG_HS_CORE !!!!!! MCU NOT SUPPORTED BY PICGIM. SORRY !!!!!!
		#endif
	#endif
	
	//-----------------------------------------------------
	#if defined( __24CXX ) 
		#if defined( __24FJ256GB110 )
			#if	defined ( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Set 24FJ256GB110 as current cpu
			#endif

			#define		PGIM_P24FJ256GB110
		#else
			//	#error	PG_HS_PG PG_HS_CORE !!!!!! MCU NOT SUPPORTED BY PICGIM. SORRY !!!!!!
		#endif
	#endif

	//-----------------------------------------------------
	#if defined( __24CXX ) 
		#include <p24cxxx.h>
	#endif

#endif /* _PGIM_EZFUSE_H_ */

/*!	
	\page	SWC_EzFuse			Easy FUSE settingss

		\section		Whatez		What is it?
			\htmlonly
					<b>EzFuse</b> is an easy way to configure the fuse and the basic parameters to start a project in a very short time.<br><em>This module is not disabled.</em><br>
			\endhtmlonly
			If you still do not know the modules of \a PicGIM then read this section specifies : \ref module

                \section		HOWez		How to select the microcontroller
					\htmlonly
							From the menu bar click <b>"Configure"</b>. Then click <b>"select device..."</b>.
							<br><br>
							<IMG src="cpuselect.jpg" align="center" border="0" >
							<br><br>
							This will open the following dialog box.
							<br><br>
							<IMG src="cpuselected.jpg" align="center" border="0" >
							<br><br>
							From the drop down menu you can choose the desired MCU.
							<br><br>
							<IMG src="cpuselecting.jpg" align="center" border="0" >
							<br><br>
							<b>PicGIM</b> does not support all MCU listed but only a few. The list of supported MCU is constantly updated.
							<b>PicGIM</b> is an open source project so you can add yourself a specific MCU.

					\endhtmlonly
		
					Here you can refer to the specifications for the \a MCU supported by \a PicGIM : \subpage cpu


	\page 		cpu		Supported MCU by PicGIM
	
		\htmlonly

			These are the MCU currently supported by PicGIM. As already mentioned, the list is constantly updated. <br><br>
			Check on http://www.gkript.org PicGIM that is always the latest version. <br>
			As mentioned above, you can create your own support for one another MCU or request support PicGIM developers. <br>
			
		\endhtmlonly
		
			\subpage		MCU_PIC18F97J60
			\subpage		MCU_PIC18F4620
			\subpage		MCU_PIC18F4553
			\subpage		MCU_PIC18F4550
			\subpage		MCU_PIC18F4520
			\subpage		MCU_PIC18F2553
			\subpage		MCU_PIC18F2550
			\subpage		MCU_PIC18F2320

					
	\attention	Here a link to the file : \ref pgim_ezfuse.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
 */


 