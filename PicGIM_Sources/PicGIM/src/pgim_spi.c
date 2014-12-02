//
// pgim_spi.c
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

/*!		\file			pgim_spi.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
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


