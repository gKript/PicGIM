/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_spi.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_spi.h

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2015  gKript.org - We.PIC project - <http://www.gkript.org>

		This program is free software: you can redistribute it and/or modify
		it under the terms of the GNU General Public License as published by
		the Free Software Foundation, either version 3 of the License, or
		(at your option) any later version.

		This program is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
		GNU General Public License for more details.

		You should have received a copy of the GNU General Public License
		along with this program.  If not, see <http://www.gnu.org/licenses/>.

	END LICENSE
 */

 /*!
		\file		pgim_spi.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		A more confortable way to configure the SPI device.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#include "picgim.h"

#if ( PGIM_SPI == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif


	void	pg_spi_open( _pg_Uint8 portnumber , _pg_Uint8 sync_mode , _pg_Uint8 bus_mode , _pg_Uint8 smp_phase ) {
		switch( portnumber ) {
			#ifndef	PGIM_P18F97J60
			case PG_SPI_0:
			{
				if ( ! SSPCON1bits.SSPEN ) {
                                    OpenSPI( sync_mode , bus_mode , smp_phase );
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
                                    #endif
				} else {
                                    Nop();
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_SPI_ALREADY_OPEN , PG_ERROR_WARNING );
                                    #endif
                                }
			}
			#else	
			case PG_SPI_0:
			{
				if ( ! SSP1CON1bits.SSPEN ) {
					OpenSPI( sync_mode , bus_mode , smp_phase );
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
                                    #endif
				} else {
                                    Nop();
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_SPI_ALREADY_OPEN , PG_ERROR_WARNING );
                                    #endif
                                }
			}
			case PG_SPI_1:
			{
				if ( ! SSP2CON1bits.SSPEN ) {
					OpenSPI1( sync_mode , bus_mode , smp_phase );
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
                                    #endif
				} else {
                                    Nop();
                                    #if PG_ERROR_IS_ENABLE
                                        pg_error_set( PG_ERROR_SPI , PG_SPI_ALREADY_OPEN , PG_ERROR_WARNING );
                                    #endif
                                }
			}
//                        case PG_SPI_2 : {
//                                if ( ! SSP3CON1bits.SSPEN ){
//                                        OpenSPI2(sync_mode, bus_mode, smp_phase);
//                                    #if PG_ERROR_IS_ENABLE
//                                        pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
//                                    #endif
//				} else {
//                                    Nop();
//                                    #if PG_ERROR_IS_ENABLE
//                                        pg_error_set( PG_ERROR_SPI , PG_SPI_ALREADY_OPEN , PG_ERROR_WARNING );
//                                    #endif
//                                }
//                        }

			#endif
			default: {
                            Nop();
                            #if PG_ERROR_IS_ENABLE
                                pg_error_set( PG_ERROR_SPI , PG_SPI_ERROR , PG_ERROR_ERROR );
                            #endif
			}
		}
	}


	void	pg_spi_reopen( _pg_Uint8 portnumber , _pg_Uint8 sync_mode , _pg_Uint8 bus_mode , _pg_Uint8 smp_phase ) {
                pg_spi_close( portnumber );
		switch( portnumber ) {
			case PG_SPI_0:
			{
                            OpenSPI( sync_mode , bus_mode , smp_phase );
                            #if PG_ERROR_IS_ENABLE
                                pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
                            #endif
			}
			#ifdef	PGIM_P18F97J60
			case PG_SPI_1:
			{
                            OpenSPI1( sync_mode , bus_mode , smp_phase );
                            #if PG_ERROR_IS_ENABLE
                                pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
                            #endif
			}
			#endif
			default:
			{
                            Nop();
                            #if PG_ERROR_IS_ENABLE
                                pg_error_set( PG_ERROR_SPI , PG_SPI_ERROR , PG_ERROR_ERROR );
                            #endif
			}
		}
	}


	void	pg_spi_close( _pg_Uint8 portnumber ) {
		switch( portnumber ) {
			#ifndef	PGIM_P18F97J60
			case PG_SPI_0: {
				if ( SSPCON1bits.SSPEN ) {
					CloseSPI( );
					#if PG_ERROR_IS_ENABLE
					    pg_error_set( PG_ERROR_SPI , PG_OK , PG_ERROR_OK );
					#endif
				} else {
					Nop();
					#if PG_ERROR_IS_ENABLE
					    pg_error_set( PG_ERROR_SPI , PG_SPI_ALREADY_CLOSE , PG_ERROR_WARNING );
					#endif
				}
			}
			#else	
			case PG_SPI_0: {
				if ( SSP1CON1bits.SSPEN ) {
					CloseSPI( );
					return PG_OK;
				} else
					return PG_SPI_ALREADY_CLOSE;
			}
			case PG_SPI_1: {
				if ( SSP2CON1bits.SSPEN ) {
					CloseSPI1( );
					return PG_OK;
				} else
					return PG_SPI_ALREADY_CLOSE;
			}
			#endif
			default: {
				Nop();
				#if PG_ERROR_IS_ENABLE
				    pg_error_set( PG_ERROR_SPI , PG_SPI_ERROR , PG_ERROR_ERROR );
				#endif
			}
		}
	}
#endif	


