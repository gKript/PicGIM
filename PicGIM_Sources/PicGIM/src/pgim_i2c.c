//
// pgim_i2c.c
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

/*!		\file			pgim_i2.c
		\version		0.6-0
		\date			2002 - 2018
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_I2C == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> External memory module >>> This file is compiling.
	#endif

	//---[ Init ]---
	void pg_i2c_init( void ) {
		//--------------------------------------------------
		PG_I2C_SCL_TRIS					= PG_IN;
		PG_I2C_SDA_TRIS					= PG_IN;
	}
	//---[ End Init ]---
	

	//---[ Write ]---
	_pg_Uint8 pg_i2c_write_register( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterAddress , _pg_Uint8 * WriteData , _pg_Uint8 Quantity ) {
		//--------------------------------------------------
		// MASTER:	| Start | [A7-A1]=Address + [A0]=0(Write)] |     | [A7-A1]=Reg-Address |     |[D7-D0]=WriteData |     | ... | [D7-D0]=WriteData |     | Stop |
		// SLAVE :	|       |                                  | Ack |                     | Ack |                  | Ack | ... |                   | Ack |
		//--------------------------------------------------
		// WriteI2C returns 0 if the write was successful
		//--------------------------------------------------
		_pg_Uint8	idx;
		
		IdleI2C();                        					//Waiting for free bus
		StartI2C();                        					//Send START signal
		IdleI2C();                         					//Waiting for end operation
		if ( WriteI2C( ( DeviceAddress << 1 ) & 0xfe ) ) {  	//Send MSB-7-Bit device-address and LSB-1-Bit set to '0' for write command; 
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_DEVICE_ADDRESS_WR , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		IdleI2C();                         					//Waiting for end operation
		if ( WriteI2C( RegisterAddress ) ) { 	 				//Send register address; 
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_REGISTER_ADDRESS , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		for ( idx = 0; idx < Quantity; idx++ ) {
			IdleI2C();                         				//Waiting for end operation
			if ( WriteI2C( *( WriteData + idx ) ) ) {			//Send "quantity" byte; 
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_DATA , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		}
		IdleI2C();                         					//Waiting for end operation
		StopI2C();                        					//Send STOP signal
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ Write End ]---
	
	
	//---[ Read ]---
	_pg_Uint8 pg_i2c_read_register( _pg_Uint8 DeviceAddress , _pg_Uint8 RegisterAddress , _pg_Uint8 * ReadData , _pg_Uint8 Quantity ) {
		//--------------------------------------------------
		// MASTER:	| Start | [A7-A1]=Dev-Address + [A0]=0(Write)] |     | [A7-A1]=Reg-Address |     | Re-Start | [A7-A1]=Dev-Address + [A0]=1(Read)] |                       | Nack | Stop |
		// SLAVE :	|       |                                      | Ack |                     | Ack |          |                                     | Ack |[D7-D0]=ReadData |
		//--------------------------------------------------
		// WriteI2C returns 0 if the write was successful
		//--------------------------------------------------
		_pg_Uint8	idx;
		
		IdleI2C();                        					//Waiting for free bus
		StartI2C();                       					//Send START signal
		IdleI2C();                         					//Waiting for end operation
		if ( WriteI2C( ( DeviceAddress << 1 ) & 0xfe ) ) {	//Send MSB-7-Bit device-address and LSB-1-Bit set to '0' for write command; 
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_DEVICE_ADDRESS_WR , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		IdleI2C();                         					//Waiting for end operation
		if ( WriteI2C( RegisterAddress ) ) { 	 				//Send register address; 
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_REGISTER_ADDRESS , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		IdleI2C();                         					//Waiting for end operation
		RestartI2C( );									//Send ReStart signal
		if ( WriteI2C( ( DeviceAddress << 1 ) | 0x01 ) ) { 	//Send MSB-7-Bit device-address and LSB-1-Bit set to '0' for write command;
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_WRITE_DEVICE_ADDRESS_RD , PG_ERROR_ERROR );
			#endif
			return ( PG_NOK );
		}
		for ( idx = 0; idx < Quantity; idx++ ) {
			if ( DataRdyI2C() ) {							//1 if there is data in the SSP buffer
				*( ReadData + idx ) = ReadI2C( );   	 		//Read byte from device
				if ( Quantity - idx++ ) {
					AckI2C();								//Send ACK signal to device	
				}
			}
		}
		NotAckI2C();                      					//Send NACK signal
		StopI2C();                         					//Send STOP signal
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
		#endif
		return ( PG_OK );
	}
	//---[ Read End ]---
	
	
	//---[ Open ]---
	_pg_Uint8 pg_i2c_open( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed ) {
		//--------------------------------------------------
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					if ( ! SSPCON1bits.SSPEN ) {
						OpenI2C( Mode, Speed );	//OpenI2C( unsigned char Mode, unsigned char slew );
						if ( ! SSPCON1bits.SSPEN ) {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
							#endif
							return ( PG_NOK );
						}
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
							#endif
							return ( PG_OK );
						}
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_ALREADY , PG_ERROR_WARNING );
						#endif
						return ( PG_NOK );
					}
				}
			#else
				case PG_I2C_0:  {
					if ( ! SSP1CON1bits.SSPEN ) {
						OpenI2C1( Mode, Speed );
						if ( ! SSP1CON1bits.SSPEN ) {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
							#endif
							return ( PG_NOK );
						}
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
							#endif
							return ( PG_OK );
						}
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_ALREADY , PG_ERROR_WARNING );
						#endif
						return ( PG_NOK );
					}
				}
				case PG_I2C_1: {
					if ( ! SSP2CON1bits.SSPEN ) {
						OpenI2C2( Mode, Speed );
						if ( ! SSP2CON1bits.SSPEN ) {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
							#endif
							return ( PG_NOK );
						}
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
							#endif
							return ( PG_OK );
						}
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_ALREADY , PG_ERROR_WARNING );
						#endif
						return ( PG_NOK );
					}
				}
			#endif
			default: {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		}
	}
	//---[ End Open ]---


	//---[ Re-Open ]---
	_pg_Uint8 pg_i2c_reopen( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed ) {
		pg_i2c_close( Port_Number );
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					OpenI2C( Mode, Speed );	//OpenI2C( unsigned char Mode, unsigned char slew );
					if ( ! SSPCON1bits.SSPEN ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
						#endif
						return ( PG_NOK );
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
						return ( PG_OK );
					}
				}
			#else
				case PG_I2C_0: {
					OpenI2C1( Mode, Speed );
					if ( ! SSP1CON1bits.SSPEN ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
						#endif
						return ( PG_NOK );
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
						return ( PG_OK );
					}
				}
				case PG_I2C_1: {
					OpenI2C2( Mode, Speed );
					if ( ! SSP2CON1bits.SSPEN ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_OPEN_FAILED , PG_ERROR_OK );
						#endif
						return ( PG_NOK );
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
						return ( PG_OK );
					}
				}
			#endif
			default: {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		}
	}
	//---[ End Re-Open ]---


	//---[ Close ]---
	_pg_Uint8	pg_i2c_close( _pg_Uint8 Port_Number ) {
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					if ( SSPCON1bits.SSPEN ) {
						CloseI2C( );
						if ( SSPCON1bits.SSPEN ) {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_FAILED , PG_ERROR_OK );
							#endif
							return ( PG_NOK );
						}
						else {
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
							#endif
							return ( PG_OK );
						}
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_ALREADY , PG_ERROR_WARNING );
						#endif
						return ( PG_NOK );
					}
				}
			#else	
			case PG_I2C_0: {
				if ( SSP1CON1bits.SSPEN ) {
					CloseI2C( );
					if ( SSP1CON1bits.SSPEN ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_FAILED , PG_ERROR_OK );
						#endif
						return ( PG_NOK );
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
						return ( PG_OK );
					}
				}
				else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_ALREADY , PG_ERROR_WARNING );
					#endif
					return ( PG_NOK );
				}
			}
			case PG_I2C_1: {
				if ( SSP2CON1bits.SSPEN ) {
					CloseI2C1( );
					if ( SSP2CON1bits.SSPEN ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_FAILED , PG_ERROR_OK );
						#endif
						return ( PG_NOK );
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
						return ( PG_OK );
					}
				}
				else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_CLOSE_ALREADY , PG_ERROR_WARNING );
					#endif
					return PG_I2C_ALREADY_CLOSE;
				}
			}
			#endif
			default: {
				#if PG_ERROR_IS_ENABLE
				    pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
				return ( PG_NOK );
			}
		}
	}
	//---[ End Close ]---
#endif	


