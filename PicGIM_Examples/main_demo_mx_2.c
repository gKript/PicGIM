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
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

//External memory demo
//-------------------------------------------------------------------------------
// This demonstrative example fills the buffer buffer_fill with a value read
// from the eeprom of the pic, writes it to mx memory, reads it from mx memory,
// modifies it and rewrites it. Finally it rewrites the incremented value in the
// eeprom and starts the cycle again. The buffer resulting from each operation
// is printed on the PCD8544 display.
//-------------------------------------------------------------------------------
// Following modules must be enabled in "pgim_module_setup_public.h" file
// PGIM_CAL_DELAY
// PGIM_SPI
// PGIM_FONT
// PGIM_LCD_PCD8544
// PGIM_EXTERNAL_MEMORY
// and hardware must be configured in "pgim_hardware_setup_public.h" file.
//-------------------------------------------------------------------------------

#include "picgim_main.h"

#define	RIT		50
//_pg_Uint8	buffer_fill[ 256 ];
_pg_Uint8	buffer_mx[ 256 ];

void main( void ) {

	_pg_Uint8 idx;
	_pg_Uint8 loop;
	_pg_Uint8 xpos = 0;
	_pg_Uint8 pos_byte = 0;
	
	pg_initialize();

	T_B4 = PG_IN;
	T_B5 = PG_IN;
	
	//------------------------------------------------------------------------
	//splash-screen and set lcd
	//------------------------------------------------------------------------
	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_msec( RIT );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_msec( RIT );
			pg_lcd_pcd8544_font_select( pg_font_5x7_std );
			pg_lcd_pcd8544_set_pos( xpos , 5 );
			pg_lcd_pcd8544_send_string_rom( ">" );
			xpos = xpos + 6;
	//------------------------------------------------------------------------
	//set address
	//------------------------------------------------------------------------
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_BLOCK , 1 );     //Block #1 is the free first one
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_SECTOR , 0 );
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_PAGE , 0 );
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 0 );
	//------------------------------------------------------------------------
	//erase user page before write it
	//------------------------------------------------------------------------
	pg_external_memory_erase_page();
			pg_lcd_pcd8544_set_pos( xpos , 5 );
			pg_lcd_pcd8544_send_string_rom( "e" );
			xpos =xpos + 6;
			pg_delay_msec( RIT );
	//------------------------------------------------------------------------
	//loop
	//------------------------------------------------------------------------
	for ( loop = 0; loop < 256; loop++ ) {			
		//------------------------------------------------------------------------
		//set increased address byte 
		//------------------------------------------------------------------------
		pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , pos_byte++ );
		//------------------------------------------------------------------------
		//write byte
		//------------------------------------------------------------------------
		pg_external_memory_write_byte( pos_byte );
				pg_lcd_pcd8544_set_pos( xpos , 5 );
				pg_lcd_pcd8544_send_string_rom( "w" );
				xpos =xpos + 6;
				pg_delay_msec( RIT );
		//------------------------------------------------------------------------
		//read page
		//------------------------------------------------------------------------
		pg_external_memory_read_page( buffer_mx );
				pg_lcd_pcd8544_set_pos( xpos , 5 );
				pg_lcd_pcd8544_send_string_rom( "r" );
				xpos =xpos + 6;
				pg_delay_msec( RIT );
		//------------------------------------------------------------------------
		//print user page saved in buffer_mx
		//------------------------------------------------------------------------
		idx = 0;	//Just enough only 8bit _pg_Uint8 idx;
		pg_lcd_pcd8544_set_pos( 0 , 0 );
		do {
			pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
			idx++;
		} while ( idx != 0 );
				pg_lcd_pcd8544_set_pos( xpos , 5 );
				pg_lcd_pcd8544_send_string_rom( "p" );
				xpos =xpos + 6;
				pg_delay_msec( RIT );
		//------------------------------------------------------------------------
		// clear lcd
		//------------------------------------------------------------------------
				// pg_lcd_pcd8544_set_pos( xpos , 5 );
				// xpos =xpos + 6;
				// pg_lcd_pcd8544_send_string_rom( "c" );
				// pg_delay_msec( RIT );
				// pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
				xpos = 0;
				pg_lcd_pcd8544_set_pos( xpos , 5 );
				pg_lcd_pcd8544_send_string_rom( "          " );
				pg_delay_msec( RIT );
				xpos = 0;
				pg_lcd_pcd8544_set_pos( xpos , 5 );
				xpos = xpos + 6;
				pg_lcd_pcd8544_send_string_rom( ">" );
				pg_delay_msec( RIT );
				
		if ( ! P_B4 ) {
			break;
		}
		if ( loop == 255 ) {
			//------------------------------------------------------------------------
			//erase user page before new loop
			//------------------------------------------------------------------------
			pg_external_memory_erase_page();
					pg_lcd_pcd8544_set_pos( xpos , 5 );
					pg_lcd_pcd8544_send_string_rom( "e" );
					xpos =xpos + 6;
					pg_delay_msec( RIT );
		}
	}
	//------------------------------------------------------------------------
	//End
	//------------------------------------------------------------------------
	
	PG_HALT;
}
	
/*
//External memory demo

// This demonstrative example fills the buffer buffer_fill with a value read
// from the eeprom of the pic, writes it to mx memory, reads it from mx memory,
// modifies it and rewrites it. Finally it rewrites the incremented value in the
// eeprom and starts the cycle again. The buffer resulting from each operation
// is printed on the PCD8544 display.

#include "picgim_main.h"

_pg_Uint8	buffer_fill[ 256 ];
_pg_Uint8	buffer_mx[ 256 ];
_pg_Uint8	ee_val;

void main( void ) {

	_pg_Uint8 idx;
	_pg_Uint8 xpos = 0;
	_pg_Uint8 res;
	
	pg_initialize();

	//------------------------------------------------------------------------
	//splash-screen and set lcd
	//------------------------------------------------------------------------
	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	//load previous value from ee and fill buffer_fill
	//------------------------------------------------------------------------
	ee_val = pg_ee_read( 0x0010 );
	
//	idx = 0;	//Just enough only 8bit _pg_Uint8 idx;
//	do {
//		buffer_fill[ idx ] = idx;	//0x18;
//		idx++;
//	} while ( idx != 0 );

	memset( buffer_fill , ee_val , sizeof(_pg_Uint8) * 256 );	//Check space occupied by memeset regard do-while
	res = pg_ee_write( ++ee_val , 0x0010 );

	pg_lcd_pcd8544_font_select( pg_font_5x7_std );
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( ">" );
	
	//------------------------------------------------------------------------
	//read user page @ address = 01.0.0.00 and save it in buffer_mx
	//------------------------------------------------------------------------
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_BLOCK , 1 );     //Block #1 is the free first one
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_SECTOR , 0 );
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_PAGE , 0 );

	pg_external_memory_read_page( buffer_mx );

	//------------------------------------------------------------------------
	//print user page saved in buffer_mx
	//------------------------------------------------------------------------
	idx = 0;	//Just enough only 8bit _pg_Uint8 idx;
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	do {
		pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
		idx++;
	} while ( idx != 0 );
	
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "r" );
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	//erase user page before write it
	//------------------------------------------------------------------------
	pg_external_memory_erase_page();

	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "e" );
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	//fill user page with buffer_fill
	//------------------------------------------------------------------------
	pg_external_memory_write_page( buffer_fill );
	
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "f" );
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	///verify, then read again user page from mx and save it in buffer_mx
	//------------------------------------------------------------------------
	pg_external_memory_read_page( buffer_mx );
	
	//------------------------------------------------------------------------
	//print again user page saved in buffer_mx
	//------------------------------------------------------------------------
	idx = 0;			//_pg_Uint8 idx;
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	do {
		pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
		idx++;
	} while ( idx != 0 );
	
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "r" );
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	//mod buffer_mx
	//------------------------------------------------------------------------
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 42 );
	pg_external_memory_overwrite_byte( 0x00 );
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 44 );
	pg_external_memory_overwrite_byte( 0x00 );
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 46 );
	pg_external_memory_overwrite_byte( 0x00 );

	//------------------------------------------------------------------------
	//read again user page from mx and save it in buffer_mx
	//------------------------------------------------------------------------
	pg_external_memory_read_page( buffer_mx );

	//------------------------------------------------------------------------
	//print again user page saved in buffer_mx
	//------------------------------------------------------------------------
	idx = 0;			//_pg_Uint8 idx;
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	do {
		pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
		idx++;
	} while ( idx != 0 );
	
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "m" );
	pg_delay_sec( 1 );
	
	//------------------------------------------------------------------------
	//Loop
	//------------------------------------------------------------------------
	pg_lcd_pcd8544_set_pos( xpos , 5 );
	xpos =xpos + 6;
	pg_lcd_pcd8544_send_string_rom( "..." );
	pg_delay_sec( 1 );
	
	Reset();
	
	//------------------------------------------------------------------------
	//End
	//------------------------------------------------------------------------
	
	PG_HALT;
}
	

*/



