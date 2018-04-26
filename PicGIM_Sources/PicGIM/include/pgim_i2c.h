//
// pgim_i2c.h
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

/*!		\file			pgim_i2c.h
		\version		0.6-0
		\date			2002 - 2018
		\brief			Inter Integrated Circuit support
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_I2C_H_
	#define _PGIM_I2C_H_

	#if ( PGIM_I2C == PG_ENABLE )
	
		//---[ Error ]---
		#define	PG_I2C_ERROR_ALREADY_OPEN		10					//!< The return value indicates that the I2C port is already open.
		#define	PG_I2C_ERROR_ALREADY_CLOSE		11					//!< The return value indicates that the I2C port is already closed.
		#define	PG_I2C_ERROR					-1					//!< The return value indicates a general ERROR.
		//---[ End Error ]---

		//---[ Port ]---
		#define	PG_I2C_0						0					//!< Port I2C 0 selection
//		#define	PG_I2C_1						1					//!< Port I2C 1 selection
		//---[ End Port ]---
		
		//---[ Mode ]---
		#define	PG_I2C_MODE_MASTER				MASTER				//!< Operating mode as master.
//		#define	PG_I2C_MODE_SLAVE_7				SLAVE_7				//!< Operating mode as slave with #7bit device addressing.
//		#define	PG_I2C_MODE_SLAVE_10			SLAVE_10			//!< Operating mode as slave with #10bit device addressing.
		//---[ End Mode ]---
		
		//---[ Speed ]---
		#define	PG_I2C_SPEED_100K				SLEW_OFF			//!< Slew rate disabled for 100 kHz mode.
		#define	PG_I2C_SPEED_400K				SLEW_ON				//!< Slew rate enabled for 400 kHz mode.
		//---[ End Speed ]---
		
		//---[ Prototype ]---
		void	pg_i2c_open						( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed );
		void	pg_i2c_reopen					( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed );
		void	pg_i2c_close					( _pg_Uint8 Port_Number );
		//---[ End Prototype ]---
	#endif
#endif /* _PGIM_I2C_H_ */
	

	