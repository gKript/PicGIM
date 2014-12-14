//
// main.c
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

/*!		\file			main.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/


#include "picgim_main.h"

void main( void ) {
	pg_initialize();
	PG_LOOP( PG_FOREVER ) {;}
}

/*
#define	MY_STRIP			L_D0
#define MY_STRIP_TRIS		T_D0

#define	MY_STRIP_LED_A_METER		16
#define MY_STRIP_LENGTH				5

#define	MYRED				my_rgb.byte.MB
#define	MYGREEN				my_rgb.byte.LB
#define	MYBLUE				my_rgb.byte.HB

#define WS2811_0			0b10000000
#define WS2811_1			0b11110000

_pg_Uint24_VAL	my_rgb;

void	my_flush_3bytes( void  ) {
	_pg_Uint8	b , l;
	_pg_Uint24	mask;
	for( l = 0 ; l < ( MY_STRIP_LED_A_METER * MY_STRIP_LENGTH ) ; l++ ) {
		mask = 0x800000;
		for( b = 0 ; b < 24 ; b++ ) {
			if ( my_rgb.Val & mask ) {
				putsSPI( WS2811_1 );
//					MY_STRIP = PG_HIGH;
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					MY_STRIP = PG_LOW;
//					Nop();
//					Nop();
//					Nop();
////					Nop();
			}
			else {
				putsSPI( WS2811_0 );
//					MY_STRIP = PG_HIGH;
//					Nop();
//					Nop();
//					MY_STRIP = PG_LOW;
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
//					Nop();
////					Nop();
			}
			mask >>= 1;
		}
		for( b = 0 ; b < 51 ; b++ ) {
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
						Nop();
		}
	}
}

void	PushButton( void ) {
	T_B3 = PG_OUT;
	L_B3 ^= 1;
}

void main( void ) {
	pg_pin_mode( MY_STRIP_TRIS , PG_OUT );
	pg_initialize();
	pg_spi_open( PG_SPI_0 , PG_SPI_MASTER_FOSC_64 , MODE_00 , SMPEND );
	MYRED = 0xff;
	MYGREEN = 0x00;
	MYBLUE = 0x00;
	PG_LOOP( PG_FOREVER ) {
		my_rgb.Val = 0xff0000;
		my_flush_3bytes();
		pg_delay_sec( 1 );
		my_rgb.Val = 0x00ff00;
		my_flush_3bytes();
		pg_delay_sec( 1 );
		my_rgb.Val = 0x0000ff;
		my_flush_3bytes();
		pg_delay_sec( 1 );
	}
}

*/