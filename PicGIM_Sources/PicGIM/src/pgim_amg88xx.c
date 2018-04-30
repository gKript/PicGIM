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

#include "picgim.h"

#if ( ( PGIM_AMG88XX == PG_ENABLE ) && ( ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_YES ) || ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_YES ) ) )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> AMG88XX >>> This file is compiling.
	#endif
	
	//---[ Init ]---
	_pg_Uint8 pg_amg88xx_init( void ) {
		//--------------------------------------------------
		#if( ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_YES ) && ( PG_AMG88XX_IRQ_DEVICE1 != PG_MISSING ) )
			PG_AMG88XX_IRQ_DEVICE1_TRIS = PG_IN;
		#endif
		#if( ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_YES ) && ( PG_AMG88XX_IRQ_DEVICE2 != PG_MISSING ) )
			PG_AMG88XX_IRQ_DEVICE2_TRIS = PG_IN;
		#endif
		//Set NORMAL mode
		#if ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_mode( PGIM_AMG88XX_ADDRESS_01 , PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_NORMAL ) == PG_NOK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE1_REGISTER_SET_NORMAL_MODE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		#if ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_mode( PGIM_AMG88XX_ADDRESS_02 , PG_AMG88XX_REGISTER_POWER_CONTROL_MODE_NORMAL ) == PG_NOK ) {
						#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE2_REGISTER_SET_NORMAL_MODE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		//Reset to activate normal mode
		#if ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_reset( PGIM_AMG88XX_ADDRESS_01 , PG_AMG88XX_REGISTER_RESET_VALUE_INITIAL ) == PG_NOK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE1_REGISTER_RESET , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		#if ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_reset( PGIM_AMG88XX_ADDRESS_01 , PG_AMG88XX_REGISTER_RESET_VALUE_INITIAL ) == PG_NOK ) {
						#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE2_REGISTER_RESET , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		//Set frame-rate to #10[FPS]
		#if ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_framerate( PGIM_AMG88XX_ADDRESS_01 , PG_AMG88XX_REGISTER_FRAMERATE_10FPS ) == PG_NOK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE1_REGISTER_FRAMERATE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		#if ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_framerate( PGIM_AMG88XX_ADDRESS_02 , PG_AMG88XX_REGISTER_FRAMERATE_10FPS ) == PG_NOK ) {
						#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE2_REGISTER_FRAMERATE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		//Disable IRQ
		#if ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_interrupt_enable( PGIM_AMG88XX_ADDRESS_01 , PG_AMG88XX_REGISTER_INTERRUPT_DISABLE ) == PG_NOK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE1_REGISTER_INTERRUPT_DISABLE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		#if ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_ENABLE )
			if ( pg_amg88xx_interrupt_enable( PGIM_AMG88XX_ADDRESS_02 , PG_AMG88XX_REGISTER_INTERRUPT_DISABLE ) == PG_NOK ) {
						#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_DEVICE2_REGISTER_INTERRUPT_DISABLE , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		#endif
		//Wait to device become ready 
		pg_delay_msec( 100 );
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End Init ]---
	
	
	//---[ Reset ]---
	_pg_Uint8	pg_amg88xx_reset( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue ) {
		//--------------------------------------------------
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_RESET_ADDRESS , RegisterValue , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_GENERAL_REGISTER_RESET , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End Reset ]---

	
	//---[ Mode ]---
	_pg_Uint8	pg_amg88xx_mode( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue ) {
		//--------------------------------------------------
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_POWER_CONTROL_ADDRESS , RegisterValue , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_GENERAL_REGISTER_MODE , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End Mode ]---
	
	
	//---[ FrameRate ]---
	_pg_Uint8	pg_amg88xx_framerate( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue ) {
		//--------------------------------------------------
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_FRAMERATE_ADDRESS , RegisterValue , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_GENERAL_REGISTER_FRAMERATE , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End FrameRate ]---

	
	//---[ Interrupt ]---
	_pg_Uint8	pg_amg88xx_interrupt_mode( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue ) {
		//--------------------------------------------------
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_INTERRUPT_ADDRESS , RegisterValue , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_GENERAL_REGISTER_INTERRUPT_MODE , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	
	_pg_Uint8	pg_amg88xx_interrupt_enable( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterValue ) {
		//--------------------------------------------------
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_INTERRUPT_ADDRESS , RegisterValue , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_GENERAL_REGISTER_INTERRUPT_ENABLE , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End Interrupt ]---
	
	
	//---[ Interrupt Hardware Check ]---
	#if ( ( ( PGIM_AMG88XX_DEVICE_01_ENABLE == PG_YES ) && ( PG_AMG88XX_IRQ_DEVICE1 != PG_MISSING ) ) || ( ( PGIM_AMG88XX_DEVICE_02_ENABLE == PG_YES ) && ( PG_AMG88XX_IRQ_DEVICE2 != PG_MISSING ) ) )
		_pg_Uint8	pg_amg88xx_interrupt_hardware_check( _pg_Uint8 DeviceAddress ) {
			//--------------------------------------------------
			if ( DeviceAddress == PGIM_AMG88XX_ADDRESS_01 )
				if ( PG_AMG88XX_IRQ_DEVICE1 ) {
					return ( PG_YES );
				}
				return ( PG_NO );
			}
			else {
			if ( DeviceAddress == PGIM_AMG88XX_ADDRESS_02 )
				if ( PG_AMG88XX_IRQ_DEVICE2 ) {
					return ( PG_YES );
				}
				return ( PG_NO );
			}
		}
	#endif
	//---[ End Interrupt  Hardware Check ]---
	
	
	//---[ Status Check ]---
	_pg_Uint8	pg_amg88xx_status_check( _pg_Uint8 DeviceAddress , _pg_Uint8 Flag ) {
		//--------------------------------------------------
		_pg_Uint8	status_check;
		if ( pg_i2c_read_register( DeviceAddress , PG_AMG88XX_REGISTER_STATUS_ADDRESS , &status_check , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_STATUS_READ , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		else {
			switch ( Flag ) {
				case PG_AMG88XX_REGISTER_STATUS_GLOBAL : {
					if ( status_check & PG_AMG88XX_REGISTER_STATUS_GLOBAL )
						return ( PG_AMG88XX_REGISTER_STATUS_GLOBAL );
				}
				case PG_AMG88XX_REGISTER_STATUS_THERMISTOR : {
					if ( status_check & PG_AMG88XX_REGISTER_STATUS_THERMISTOR )
						return ( PG_AMG88XX_REGISTER_STATUS_THERMISTOR );
				}
				case PG_AMG88XX_REGISTER_STATUS_TEMPERATURE : {
					if ( status_check & PG_AMG88XX_REGISTER_STATUS_TEMPERATURE )
						return ( PG_AMG88XX_REGISTER_STATUS_TEMPERATURE );
				}
				case PG_AMG88XX_REGISTER_STATUS_INTERRUPT : {
					if ( status_check & PG_AMG88XX_REGISTER_STATUS_INTERRUPT )
						return ( PG_AMG88XX_REGISTER_STATUS_INTERRUPT );
				}
				default : {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
					return ( PG_OK );
				}
			}
		}
	}
	//---[ End Status Check ]---
	
	//---[ Status Clear ]---
	_pg_Uint8	pg_amg88xx_status_clear( _pg_Uint8 DeviceAddress , _pg_Uint8 Flag ) {
		//--------------------------------------------------
		_pg_Uint8	status_clear;
		if ( pg_i2c_read_register( DeviceAddress , PG_AMG88XX_REGISTER_STATUS_ADDRESS , &status_clear , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_STATUS_READ , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		else {
			switch ( Flag ) {
				case PG_AMG88XX_REGISTER_STATUS_GLOBAL : {
					status_clear = PG_AMG88XX_REGISTER_STATUS_GLOBAL;
				}
				case PG_AMG88XX_REGISTER_STATUS_THERMISTOR : {
					status_clear = PG_AMG88XX_REGISTER_STATUS_THERMISTOR;
				}
				case PG_AMG88XX_REGISTER_STATUS_TEMPERATURE : {
					status_clear = PG_AMG88XX_REGISTER_STATUS_TEMPERATURE;
				}
				case PG_AMG88XX_REGISTER_STATUS_INTERRUPT : {
					status_clear = PG_AMG88XX_REGISTER_STATUS_INTERRUPT;
				}
				default : {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_AMG88XX_ERROR_STATUS_WRONG_FLAG , PG_ERROR_OK );
					#endif
					return ( PG_NOK );
				}
			}
		}
		if ( pg_i2c_write_register( DeviceAddress , PG_AMG88XX_REGISTER_STATUS_ADDRESS , &status_clear , 1 ) == PG_NOK ) {
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_AMG88XX , PG_AMG88XX_ERROR_STATUS_WRITE , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ End Status Clear ]---
#endif


