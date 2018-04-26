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
	
	
	//---[ Open ]---
	void pg_i2c_open( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed ) {
		//--------------------------------------------------
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					if ( ! SSPCON1bits.SSPEN ) {
						OpenI2C( Mode, Speed );	//OpenI2C( unsigned char Mode, unsigned char slew );
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
					}
					else {
						Nop();
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR_ALREADY_OPEN , PG_ERROR_WARNING );
						#endif
					}
				}
			#else
				case PG_I2C_0:  {
					if ( ! SSP1CON1bits.SSPEN ) {
						OpenI2C1( Mode, Speed );
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
					}
					else {
						Nop();
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ALREADY_OPEN , PG_ERROR_WARNING );
						#endif
					}
				}
				case PG_I2C_1: {
					if ( ! SSP2CON1bits.SSPEN ) {
						OpenI2C2( Mode, Speed );
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
					}
					else {
						Nop();
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ALREADY_OPEN , PG_ERROR_WARNING );
						#endif
					}
				}
			#endif
			default: {
				Nop();
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
			}
		}
	}
	//---[ End Open ]---


	//---[ Re-Open ]---
	void pg_i2c_reopen( _pg_Uint8 Port_Number , _pg_Uint8 Mode , _pg_Uint8 Speed ) {
		pg_i2c_close( Port_Number );
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					OpenI2C( Mode, Speed );	//OpenI2C( unsigned char Mode, unsigned char slew );
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
				}
			#else
				case PG_I2C_0: {
					OpenI2C1( Mode, Speed );
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
				}
				case PG_I2C_1: {
					OpenI2C2( Mode, Speed );
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
				}
			#endif
			default: {
				Nop();
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
			}
		}
	}
	//---[ End Re-Open ]---


	//---[ Close ]---
	void	pg_i2c_close( _pg_Uint8 Port_Number ) {
		switch( Port_Number ) {
			#ifndef	PGIM_P18F97J60
				case PG_I2C_0: {
					if ( SSPCON1bits.SSPEN ) {
						CloseI2C( );
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
						#endif
					}
					else {
						Nop();
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_I2C , PG_I2C_ALREADY_CLOSE , PG_ERROR_WARNING );
						#endif
					}
				}
			#else	
			case PG_I2C_0: {
				if ( SSP1CON1bits.SSPEN ) {
					CloseI2C( );
					Nop();
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
				}
				else {
					Nop();
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_I2C_ALREADY_CLOSE , PG_ERROR_WARNING );
					#endif
				}
			}
			case PG_I2C_1: {
				if ( SSP2CON1bits.SSPEN ) {
					CloseI2C1( );
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_OK , PG_ERROR_OK );
					#endif
				}
				else {
					return PG_I2C_ALREADY_CLOSE;
					Nop();
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_I2C , PG_I2C_ALREADY_CLOSE , PG_ERROR_WARNING );
					#endif
				}
			}
			#endif
			default: {
				Nop();
				#if PG_ERROR_IS_ENABLE
				    pg_error_set( PG_ERROR_I2C , PG_I2C_ERROR , PG_ERROR_ERROR );
				#endif
			}
		}
	}
	//---[ End Close ]---
#endif	


