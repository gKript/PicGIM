//
// 
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

/*!		\file			main.c
		\version		0.6-0
		\date			2002 - 2018
		\brief			AD9851 DDS programming DEMO
		\details		A demonstration of frequency and sweep programming
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim_main.h"

//------------------------------------------------------------------------
//	SSP - (S)imple (S)erial (P)rotocol DEMO
//------------------------------------------------------------------------
//	Send buffers over serial port and display them to lcd
//------------------------------------------------------------------------
//	Enable and configure:
//		PGIM_SSP
//		PGIM_SERIAL
//		PGIM_CAL_DELAY
//		PGIM_LCD_HD44780	(needed only for debug)
//------------------------------------------------------------------------


//------------------------------------------------------------------------
//	TX - Main
//------------------------------------------------------------------------
void main( void ) {
	_pg_Uint8	txbuff_1[ ] = "PicGIM ";
	_pg_Uint8	txbuff_2[ ] = "is ";
	_pg_Uint8	txbuff_3[ ] = "nice!";
	
	pg_initialize( );
	pg_serial_open( );
	
	if( pg_ssp_tx( txbuff_1 , sizeof( txbuff_1 ) ) != PG_OK ) {
		pg_lcd_hd44780_put_char( 0 , 'F' );
		PG_HALT;
	}
	else {
		pg_lcd_hd44780_put_char( 0 , 'G' );
	}
	if( pg_ssp_tx( txbuff_2 , sizeof( txbuff_2 ) ) != PG_OK ) {
		pg_lcd_hd44780_put_char( 0 , 'F' );
		PG_HALT;
	}
	else {
		pg_lcd_hd44780_put_char( 0 , 'G' );
	}
	if( pg_ssp_tx( txbuff_3 , sizeof( txbuff_3 ) ) != PG_OK ) {
		pg_lcd_hd44780_put_char( 0 , 'F' );
		PG_HALT;
	}
	else {
		pg_lcd_hd44780_put_char( 0 , 'G' );
	}
	PG_HALT;
}

/*
//------------------------------------------------------------------------
//	RX - Main
//------------------------------------------------------------------------
void main( void ) {
	_pg_Uint8	rxbuff[ 16 ];
	_pg_Uint8	index;
	
	pg_initialize( );
	pg_serial_open( );
	
	if( pg_ssp_rx( rxbuff ) == PG_OK ) {
		pg_lcd_hd44780_write( 0 , 0 , 0 , "%s", rxbuff );
	}
	PG_HALT;
}
*/

