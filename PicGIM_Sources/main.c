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
	float flo;
	char buff[16];
	pg_initialize();
	pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
	pg_adc_set( PG_ADC_MODULE , PG_ON );
	while(1) {
		flo = * pg_sensor_ntc( PG_CH_0 );
		//char *	pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint24 pg_ftoa_trunc_decimal_digits, char * pg_ftoa_buffer );
		pg_ftoa( flo, PG_FTOA_DECIMAL_DIGITS_2, buff );
		//putsUSART(  char *data );
		putrsUSART( buff );
	}
	PG_INFINITE_LOOP;
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

rom _pg_Uint24	array_mask[] = { 0b100000000000000000000000 , 0b010000000000000000000000 , 0b001000000000000000000000 , 0b000100000000000000000000 , 0b000010000000000000000000 , 0b000001000000000000000000 , 0b000000100000000000000000 , 0b000000010000000000000000 , 0b000000001000000000000000 , 0b000000000100000000000000 , 0b000000000010000000000000 , 0b000000000001000000000000 , 0b000000000000100000000000 , 0b000000000000010000000000 , 0b000000000000001000000000 , 0b000000000000000100000000 , 0b000000000000000010000000 , 0b000000000000000001000000 , 0b000000000000000000100000 , 0b000000000000000000010000 , 0b000000000000000000001000 , 0b000000000000000000000100 , 0b000000000000000000000010 , 0b000000000000000000000001 };



void	my_flush_3bytes( void  ) {
	_pg_Uint8	b , l;
	for( l = 0 ; l < ( MY_STRIP_LED_A_METER * MY_STRIP_LENGTH ) ; l++ ) {
		for( b = 0 ; b < 24 ; b++ ) {
			if ( my_rgb.Val & array_mask[b] ) {
//				putsSPI( WS2811_1 );
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
//					Nop();
			}
			else {
//				putsSPI( WS2811_0 );
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_HIGH;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
					MY_STRIP = PG_LOW;
//					Nop();
			}
		}
//		for( b = 0 ; b < 51 ; b++ ) {
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//						Nop();
//		}
	}
}

void	PushButton( void ) {
	T_B3 = PG_OUT;
	L_B3 ^= 1;
}

void main( void ) {
	pg_pin_mode( MY_STRIP_TRIS , PG_OUT );
	pg_pin_mode( T_C3 , PG_OUT );
	pg_pin_mode( T_C5 , PG_OUT );
	pg_pin_mode( T_B3 , PG_OUT );
	pg_initialize();
	pg_spi_open( PG_SPI_0 , PG_SPI_MASTER_FOSC_4 , MODE_00 , SMPEND );
	MYRED = 0xff;
	MYGREEN = 0x00;
	MYBLUE = 0x00;
	PG_LOOP( PG_FOREVER ) {
		my_rgb.Val = 0x555555;
		my_flush_3bytes();
		pg_delay_msec( 30 );
		pg_pin_toggle( L_B3 );
//		my_rgb.Val = 0x00ff00;
//		my_flush_3bytes();
//		pg_delay_msec( 10 );
//		my_rgb.Val = 0x0000ff;
//		my_flush_3bytes();
//		pg_delay_msec( 10 );
	}
}

*/