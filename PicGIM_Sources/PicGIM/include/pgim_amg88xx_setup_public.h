//
// pgim_amg88xx_setup_public.h
//
// PicGim  -  Generic Information Manager for Pic 18 / 24 family uControllers 
// Version 0.6-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002 - 2018 
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

/*!		\file			pgim_amg88xx_setup_public.h
		\version		0.6-0
		\date			2002 - 2018
		\brief			Infrared Array Sensor - Grid-EYE
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_AMG88XX_SETUP_PUBLIC_H_
	#define _PGIM_AMG88XX_SETUP_PUBLIC_H_

	#if ( PGIM_AMG88XX == PG_ENABLE )
	
		//-------------------------------------------------------------------------------------------------------------
		//		D E V I C E      A D D R E S S
		//-------------------------------------------------------------------------------------------------------------
		// Warning!		These addresses are assigned by the device manufacturer and should not be changed,
		//				but they remain available if needed.
		//-------------------------------------------------------------------------------------------------------------
		#define	PGIM_AMG88XX_ADDRESS_01							0x68		//!< Must be: 1101000 ( 0x68 ) || 1101001 ( 0x69 )
		#define	PGIM_AMG88XX_ADDRESS_02							0x69		//!< Must be: 1101000 ( 0x68 ) || 1101001 ( 0x69 )
		
	#endif
#endif /* _PGIM_AMG88XX_SETUP_PUBLIC_H_ */


