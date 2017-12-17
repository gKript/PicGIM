/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		main.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

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
 
#include "picgim_main.h"

void main( void ) {
	//--------------------------------------------------------------------------
	_pg_Uint8 password[ 32 ];
	_pg_Uint8 arg[] = "corrado";
	_pg_Uint8 c;
	
	pg_initialize();
	//pg_serial_open( );
	pg_lcd_hd44780_clear( 0 );

	pg_h32_prs_seed( pg_h32_Hash32( arg ) );
	printf( "chsum  %08X\n" , pg_h32_sum );
	puts( "Pseudo seq:" );
	for ( c = 0 ; c < 10 ; c++ ) {
		printf ( " %3u " , pg_h32_prs_rand8() );
	}
	puts( "" );
	//pg_lcd_hd44780_write_string( 0 , rbuffer );	
	
	//pg_serial_close();
	PG_HALT;
}







//#################################################################################
//#################################################################################
//#################################################################################
//SSP -	Simple Serial Protocol
//main_RX.c
//#################################################################################
//#################################################################################
//#################################################################################
/* 
void main( void ) { //RX
	//--------------------------------------------------------------------------
	_pg_Uint8 rbuffer[ 8 ];
	
	pg_initialize( );
	pg_serial_open( );
	pg_lcd_hd44780_clear( 0 );

	pg_ssp_init();

	PG_LOOP( PG_FOREVER ) {
		//pg_lcd_hd44780_clear( 0 );
		pg_lcd_hd44780_goto( 0 , 0 , 0 );
		pg_delay( 4 , PG_SEC );
		if( pg_ssp_rx( rbuffer ) == PG_OK ) {
			pg_lcd_hd44780_put_char( 0 , '!' );
			pg_lcd_hd44780_put_char( 0 , '!' );
			pg_lcd_hd44780_put_char( 0 , '!' );
			pg_lcd_hd44780_write_string( 0 , rbuffer );	
		}
	}
	//pg_serial_close();
	PG_HALT;
}
 */














//pg_lcd_hd44780_put_char( 0 , 'T' );
//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read( ) );

/* 

void blink_led_error( void ) {
	pg_pin_set( LED_ERROR );
	pg_delay( 500 , PG_MSEC );
	pg_pin_clear( LED_ERROR );
}

void blink_led_ok( void ) {
	pg_pin_set( LED_OK );
	pg_delay( 500 , PG_MSEC );
	pg_pin_clear( LED_OK );
}
	pg_pin_clear( LED_OK );
	pg_pin_clear( LED_ERROR );
	pg_pin_mode( LED_OK_TRIS , PG_OUT );
	pg_pin_mode( LED_ERROR_TRIS , PG_OUT );
	pg_pin_mode( PUSH_TRIS , PG_IN );

		
	pg_pin_clear( LED_OK );
	pg_pin_clear( LED_ERROR );
	pg_pin_mode( LED_OK_TRIS , PG_OUT );
	pg_pin_mode( LED_ERROR_TRIS , PG_OUT );
	
	#define PUSH			P_B1
	#define LED_OK			L_B2
	#define LED_ERROR		L_B3

	#define PUSH_TRIS		T_B1
	#define LED_OK_TRIS		T_B2
	#define LED_ERROR_TRIS	T_B3
*/
/*
			switch ( responce ) {
			case PG_OK :
				pg_lcd_hd44780_clear( 0 );
				pg_lcd_hd44780_write_string( 0 , rbuffer );
			break;
			default :
				blink_led_error();
			break;
		}
	*/



//		if( !PUSH ) {				//debounce
//			pg_delay_msec( 100 );	//debounce
//			if( !PUSH ) {			//debounce















