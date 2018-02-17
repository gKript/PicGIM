 //
// pgim_lcd_5110.h
//
// picGim  -  Generic Information Manager for Pic 18 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002, 2003 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of Gim library.

	picGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	picGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

/*!	\file		pgim_lcd_5110.h
	\version	1.0-0
	\brief		Copyright (C) 2001, 2013<BR>
				Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)<BR>
				Released under the terms of the GNU General Public License v2<BR>
				[ http://gkript.org/gk_gpl_v2.php ]
*/ 		

#ifndef		__PGIM_LCD5110_H__
	#define		__PGIM_LCD5110_H__
	
	#if ( PGIM_LCD_5110 == PG_ENABLE )

		void	pg_lcd_5110_init			    	( void );
		void	pg_lcd_5110_send			    	( _pg_Uint8 dc , _pg_Uint8 chr );
		void	pg_lcd_5110_clear			    	( _pg_Uint8 wb );			//white = 0; black = 1

		void	pg_lcd_5110_backlight		    	( _pg_int8 flag );
		void	pg_lcd_5110_set_pos			    	( _pg_Uint8 x , _pg_Uint8 y );
		
		#if ( PGIM_FONT == PG_ENABLE )
    		void	pg_lcd_5110_send_char	    	( _pg_Uint8 character );
		    void    pg_lcd_5110_font_select     	( rom const _pg_Uint8 * font );
    		void	pg_lcd_5110_send_string_rom		( rom _pg_int8* string );
    		void	pg_lcd_5110_send_string			( _pg_int8 * string );
		#endif
		
	#endif
#endif


