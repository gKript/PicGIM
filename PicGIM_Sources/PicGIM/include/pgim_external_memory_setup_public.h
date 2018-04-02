//
// pgim_external_memory_setup_public.h
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

/*!		\file			pgim_external_memory_setup_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_EXTERNAL_MEMORY_SETUP_PUBLIC_H_
	#define _PGIM_EXTERNAL_MEMORY_SETUP_PUBLIC_H_

	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		//-------------------------------------------------------------------------------------------------------------
		//		D E V I C E   T E C N O L O G Y
		//-------------------------------------------------------------------------------------------------------------
		#define PGIM_EXTERNAL_MEMORY_TECNOLOGY					PG_TECNOLOGY_SPI	// PG_TECNOLOGY_SPI	PG_TECNOLOGY_I2C

		//-------------------------------------------------------------------------------------------------------------
		//		D E V I C E   T Y P E
		//-------------------------------------------------------------------------------------------------------------
		#define PGIM_EXTERNAL_MEMORY_TYPE						PG_MX25L			// PG_MX25L 
		
		//-------------------------------------------------------------------------------------------------------------
		//		D E V I C E   P A R A M E T E R S
		//-------------------------------------------------------------------------------------------------------------
		#define PGIM_EXTERNAL_MEMORY_CHIP_SIZE					67108864			// [ bit ]
		#define PGIM_EXTERNAL_MEMORY_BLOCK_SIZE					65536				// [ byte ]
		#define PGIM_EXTERNAL_MEMORY_SECTOR_SIZE				4096				// [ byte ]
		#define PGIM_EXTERNAL_MEMORY_PAGE_SIZE					256					// [ byte ]

	#endif
#endif /* _PGIM_EXTERNAL_MEMORY_SETUP_PUBLIC_H_ */

