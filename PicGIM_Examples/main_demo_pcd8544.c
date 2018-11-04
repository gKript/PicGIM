//
// 
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
		\version		0.6-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

//PCD8544 demo ( Nokia 5110 - Lcd display controller)

#include "picgim_main.h"

void main( void ) {
	pg_initialize();
	pg_lcd_pcd8544_init();

	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_sec( 2 );
	pg_lcd_pcd8544_font_select( font_5x7 );
	pg_lcd_pcd8544_set_pos( 5 , 1 );
	pg_lcd_pcd8544_send_string_rom( " Controller" );
	pg_lcd_pcd8544_set_pos( 5 , 2 );
	pg_lcd_pcd8544_send_string_rom( "  PCD8544" );
	pg_lcd_pcd8544_set_pos( 5 , 3 );
	pg_lcd_pcd8544_send_string_rom( "84 x 48 pixel" );
	
	PG_HALT;
}