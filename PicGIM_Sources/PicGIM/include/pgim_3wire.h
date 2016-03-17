//
// pgim_3wire.h
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

/*!		\file			pgim_3wire.h
		\version		0.6-0
		\date			2002 - 2016
		\brief			Simple 3-wire serial protocol
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_3WIRE_H_
	#define _PGIM_3WIRE_
	
	#if	( PGIM_3WIRE == PG_ENABLE )
	
		//---[ Prototypes ]---	
		void		pg_3wire_init				( void );
		void		pg_3wire_wr_byte			( _pg_Uint8 wr_byte );
		_pg_Uint8	pg_3wire_rd_byte			( void );
		//---[ End Prototypes ]---	
	
	#endif
	
#endif /* _PGIM_3WIRE_H_ */


