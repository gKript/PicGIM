//
// pgim_lcd_5110.c
//
// picGim  -  Generic Information Manager for Pic 18 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002, 2011 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of picGim library.

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

#include "picgim.h"

#if ( PGIM_LCD_5110 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif

	#if ( PGIM_FONT == PG_ENABLE )
	    struct pg_font_config fxy;
	#endif

	void pg_lcd_5110_init( void ) {
		PG_LCD_5110_CE_TRIS		= PG_OUT;
		PG_LCD_5110_RST_TRIS	= PG_OUT;
		PG_LCD_5110_DC_TRIS		= PG_OUT;
		PG_SPI_SDI_TRIS		= PG_IN;
		PG_SPI_SDO_TRIS		= PG_OUT;
		PG_SPI_SCK_TRIS		= PG_OUT;
		PG_SPI_SS_TRIS		= PG_IN;
		PG_LCD_5110_LED_TRIS			= PG_OUT;
		pg_spi_open( PG_SPI_1, PG_SPI_MASTER_FOSC_16, MODE_00, SMPEND );
		pg_delay_msec( 20 );
	    PG_LCD_5110_CE	= 0;
	    PG_LCD_5110_RST	= 0;
	    pg_delay_msec( 20 );
	    PG_LCD_5110_RST	= 1;
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_FUNCTION + 0x01 );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_EXT_SET_VOP + 0x40 );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_EXT_TEMP_CONTROL + 0x02 );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_EXT_BIAS_CONTROL + 0x03 );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_FUNCTION + 0x00 );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_CONFIGURATION + 0x04 );
		pg_lcd_5110_clear( 1 );
		pg_lcd_5110_backlight( PG_ON );
		pg_delay_msec( 125 );
		pg_lcd_5110_backlight( PG_OFF );
		pg_lcd_5110_clear( 0 );
		pg_delay_msec( 250 );
	}
	
    #if PGIM_FONT == PG_ENABLE
    	void pg_lcd_5110_font_select( rom const _pg_Uint8 * font ) {
    		fxy.width	= font[0];
    		fxy.height	= font[1];
    		fxy.font	= font;
    	}	
    #endif	

	void pg_lcd_5110_send( _pg_Uint8 dc , _pg_Uint8 chr ) {
		if ( dc == PG_5110_DATA ) 
			PG_LCD_5110_DC = 1;
		else if ( dc == PG_5110_COMMAND ) 
			PG_LCD_5110_DC = 0;
	    putcSPI( chr );
	}


	void pg_lcd_5110_clear( _pg_Uint8 wb ) {
	    _pg_Uint16 n;
	    _pg_Uint8 bg;
	    if( wb )		
	        bg = 0xFF;
	    else
	        bg = 0x00;
		pg_lcd_5110_set_pos( 0 , 0 );
	    for( n = 0 ; n < 504 ; n++ ) {
	        pg_lcd_5110_send( PG_5110_DATA , bg );
		}
	}

	#if PGIM_FONT == PG_ENABLE
    	void pg_lcd_5110_send_char( _pg_Uint8 character ) {
    	    _pg_Uint8 column = 0;
    		character = character - 0x20; 						// 0x20 is the first element of the array
    		for( column = 0 ; column < fxy.width ; column++ ) {			// Pass through each column
    	        pg_lcd_5110_send( PG_5110_DATA , fxy.font[ ( _pg_int16 ) character * fxy.width + column + 2 ] );
    	    }
    		pg_lcd_5110_send( PG_5110_DATA , 0x00 ); 							// Send a colon (1 byte) as space
    	}

	
    	void pg_lcd_5110_send_string_rom( rom _pg_int8 *string ) {
    	    while( * string ) {
    	        pg_lcd_5110_send_char( *string );
    	        string++;
    	    }
    	}
    
    
    	void pg_lcd_5110_send_string( _pg_int8 * string ) {
    	    while( * string ) {
    	        pg_lcd_5110_send_char( * string );
    	        string++;
    	    }
    	}
    	
    	void pg_lcd_5110_write_pint( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  *format , _pg_int16 val ) {
    		_pg_int8 str[ 16 ];
    		pg_lcd_5110_set_pos( x , y );		
    		sprintf( str , format , val );
    		pg_lcd_5110_send_string( str );
    	}
    	
    	
    	void pg_lcd_5110_write_pfloat( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  *format , float flt ) {
    		_pg_int8 str[ 16 ];
    		pg_lcd_5110_set_pos( x , y );
    		sprintf( str , format , flt );
    		pg_lcd_5110_send_string( str );
    	}
    	
    
    	void pg_lcd_5110_write_pchar( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  *format , _pg_int8 chr ) {
    		_pg_int8 str[ 16 ];
    		pg_lcd_5110_set_pos( x , y );
    		sprintf( str , format , chr );
    		pg_lcd_5110_send_string( str );
    	}
    	

    #endif    	
	
	void pg_lcd_5110_backlight( _pg_int8 flag ) {
		if ( ! flag )
			PG_LCD_5110_LED = PG_ON;
		else
			PG_LCD_5110_LED = PG_OFF;
	}
	

	void pg_lcd_5110_set_pos( _pg_Uint8 x , _pg_Uint8 y ) {
		pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_ADDRESS_X + x );
	    pg_lcd_5110_send( PG_5110_COMMAND , PG_5110_ADDRESS_Y + y );
	}
	


#endif


