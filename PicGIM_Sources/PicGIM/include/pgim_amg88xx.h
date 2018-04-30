//
// pgim_amg88xx.h
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

/*!		\file			pgim_amg88xx.h
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

#ifndef _PGIM_AMG88XX_H_
	#define _PGIM_AMG88XX_H_

	#if ( PGIM_AMG88XX == PG_ENABLE )
		
		//---[ Error ]---
		#define	PG_AMG88XX_ERROR_GENERAL_REGISTER_MODE						10		//!< The return value indicates an error on writing mode register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_SET_NORMAL_MODE			11		//!< The return value indicates an error on writing device #1 mode register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_SET_NORMAL_MODE			12		//!< The return value indicates an error on writing device #2 mode register
		#define	PG_AMG88XX_ERROR_GENERAL_REGISTER_RESET						13		//!< The return value indicates an error on writing reset register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_RESET						14		//!< The return value indicates an error on writing device #1 reset register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_RESET						15		//!< The return value indicates an error on writing device #2 reset register
		#define	PG_AMG88XX_ERROR_GENERAL_REGISTER_FRAMERATE					16		//!< The return value indicates an error on writing framerate register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_FRAMERATE					17		//!< The return value indicates an error on writing device #1 framerate register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_FRAMERATE					18		//!< The return value indicates an error on writing device #2 framerate register
		#define	PG_AMG88XX_ERROR_GENERAL_REGISTER_INTERRUPT_MODE			19		//!< The return value indicates an error on writing interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_INTERRUPT_MODE			20		//!< The return value indicates an error on writing device #1 interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_INTERRUPT_MODE			21		//!< The return value indicates an error on writing device #2 interrupt register
		#define	PG_AMG88XX_ERROR_GENERAL_REGISTER_INTERRUPT_ENABLE			22		//!< The return value indicates an error on writing interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_INTERRUPT_ENABLE			23		//!< The return value indicates an error on writing device #1 interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_INTERRUPT_ENABLE			24		//!< The return value indicates an error on writing device #2 interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE1_REGISTER_INTERRUPT_DISABLE			25		//!< The return value indicates an error on writing device #1 interrupt register
		#define	PG_AMG88XX_ERROR_DEVICE2_REGISTER_INTERRUPT_DISABLE			26		//!< The return value indicates an error on writing device #2 interrupt register
		#define	PG_AMG88XX_ERROR_STATUS_WRONG_FLAG							27		//!< The return value indicates an error on flag parameter of status register
		#define	PG_AMG88XX_ERROR_STATUS_READ								28		//!< The return value indicates an error on reading status register
		#define	PG_AMG88XX_ERROR_STATUS_WRITE								29		//!< The return value indicates an error on writing status register
		//---[ End Error ]---
		
		//---[ Register ]---
		// Mode ( Power Control )
		#define	PG_AMG88XX_REGISTER_POWER_CONTROL_ADDRESS					0x00
		#define PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_NORMAL				0x00
		#define PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_SLEEP				0x10
		#define PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_STBY_60				0x20
		#define PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_STBY_10				0x21
		// Reset
		#define	PG_AMG88XX_REGISTER_RESET_ADDRESS							0x01
		#define PG_AMG88XX_REGISTER_RESET_VALUE_FLAG						0x30
		#define PG_AMG88XX_REGISTER_RESET_VALUE_INITIAL						0x3F
		// FrameRate
		#define	PG_AMG88XX_REGISTER_FRAMERATE_ADDRESS						0x02
		#define	PG_AMG88XX_REGISTER_FRAMERATE_1FPS							0x01
		#define	PG_AMG88XX_REGISTER_FRAMERATE_10FPS							0x00
		// Interrupt
		#define	PG_AMG88XX_REGISTER_INTERRUPT_ADDRESS						0x03
		#define	PG_AMG88XX_REGISTER_INTERRUPT_MODE_ABSOLUTE					0x01
		#define	PG_AMG88XX_REGISTER_INTERRUPT_MODE_DIFFERENCE				0x00
		#define	PG_AMG88XX_REGISTER_INTERRUPT_ENABLE						0x01
		#define	PG_AMG88XX_REGISTER_INTERRUPT_DISABLE						0x00	// Hi-Z !!!
		// Status
		#define	PG_AMG88XX_REGISTER_STATUS_ADDRESS							0x04
		#define	PG_AMG88XX_REGISTER_STATUS_ADDRESS_CLEAR					0x05
		#define	PG_AMG88XX_REGISTER_STATUS_GLOBAL							0x0E	//flag & mask ( 0000.1110 )
		#define	PG_AMG88XX_REGISTER_STATUS_THERMISTOR						0x08	//flag & mask ( 0000.1000 )
		#define	PG_AMG88XX_REGISTER_STATUS_TEMPERATURE						0x04	//flag & mask ( 0000.0100 )
		#define	PG_AMG88XX_REGISTER_STATUS_INTERRUPT						0x02	//flag & mask ( 0000.0010 )
		//---[ End Register ]---

		//---[ Prototype ]---
		_pg_Uint8	pg_amg88xx_init							( void );
		_pg_Uint8	pg_amg88xx_reset						( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue );
		_pg_Uint8	pg_amg88xx_mode							( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue );
		_pg_Uint8	pg_amg88xx_framerate					( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue );
		_pg_Uint8	pg_amg88xx_interrupt_mode				( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue );
		_pg_Uint8	pg_amg88xx_interrupt_enable				( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue );
		_pg_Uint8	pg_amg88xx_interrupt_hardware_check		( _pg_Uint8 DeviceAddress );
		_pg_Uint8	pg_amg88xx_status_check					( _pg_Uint8 DeviceAddress , _pg_Uint8 Flag );
		_pg_Uint8	pg_amg88xx_status_clear					( _pg_Uint8 DeviceAddress , _pg_Uint8 Flag );
		//---[ End Prototype ]---
		
	#endif
#endif /* _PGIM_AMG88XX_H_ */


