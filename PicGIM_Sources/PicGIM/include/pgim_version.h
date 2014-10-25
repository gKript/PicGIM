//
// pgim_version.h
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

/*!		\file			pgim_version.h
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

#ifndef _PGIM_VERSION_H_
	#define _PGIM_VERSION_H_

	#include "pgim_defines.h"
	#include "pgim_project_setup_public.h"

	#define PG_VERSION_STATE				"dev"       //!< \b "rel" for release or \b "dev" for devel

	#define	PG_MAJOR						0			//!<	The major version of PicGIM
	#define	PG_MINOR						4			//!<	The minor version of PicGIM
	#define PG_SUBMINOR						1			//!<	The subminor version of PicGIM

	#define PG_VERSION						"0.4-1" 	//!<	The string for the current version of Gim	*/
	#define	PG_MILESTONE					"0.5"		//!<	The relative Milestone

//		#if ( PG_VERSION_UTILS == PG_ENABLE )
//			#include "pgim_custom_type.h"
//			#define PG_VERCHECK     0 ## 4 ## 1
//			_pg_Uint8   pgim_check_version	( _pg_Uint8 maj , _pg_Uint8 min , _pg_Uint8 sub );
//		#endif

	#if defined( _GIM_H_ ) && ( PG_VERBOSE == PG_ENABLE )
		#warning	PG_HS_PG PG_HS_CORE Version PG_VERSION : Milestone PG_MILESTONE : State PG_VERSION_STATE
		#if ( PG_SUGGESTION == PG_ENABLE )
			#warning	PG_HS_PG PG_HS_MSG PG_HS_SUGG Check periodically on WWW.GKRIPT.ORG if you are using the latest PicGIM!
		#endif
	#endif
	
#endif /* _PGIM_VERSION_H_ */

/*!	\page	SWC_version			The PicGIM version

		This module contains the definitions for the version of \b PicGIM. \n
		If you want to change the verbosity level you need to change \ref PG_VERBOSE in the \ref pgim_project_setup_public.h \n \n
	 
 	


	\attention	Here a link to the file : \ref pgim_version.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


