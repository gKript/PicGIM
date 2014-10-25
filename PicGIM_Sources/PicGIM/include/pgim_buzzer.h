//
// pgim_buzzer.h
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

/*!		\file			pgim_buzzer.h
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

#ifndef _PGIM_BUZZER_H_
	#define _PGIM_BUZZER_H_

	#if defined( __18CXX )
		#include <delays.h>
	#endif

    #if ( PGIM_BUZZER == PG_ENABLE )
	
		#define PG_BEEP_LONG        100
		#define	PG_BEEP_SHORT       40
		#define	PG_BEEP_PRESS_L     90
		#define	PG_BEEP_PRESS_S     30
		#define	PG_BEEP_HIGH		1
		#define	PG_BEEP_MID         3
		#define	PG_BEEP_LOW         7

		void    pg_beep( _pg_Uint8 tone , _pg_Uint16 len );

	#endif
#endif /* _PGIM_BUZZER_H_ */


/*!
	\page	HWE_buzzer		Buzzer


	\attention	Here a link to the file : \ref pgim_buzzer.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
 */

