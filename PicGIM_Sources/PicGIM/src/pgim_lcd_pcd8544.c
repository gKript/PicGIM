//
// pgim_lcd_pcd8544.c
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

/*!		\file			pgim_lcd_pcd8544.c
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

#if ( PGIM_LCD_PCD8544 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	#if ( PGIM_FONT == PG_ENABLE )
		struct pg_font_config fxy;
	#endif

	void pg_lcd_pcd8544_init( void ) {
		PG_LCD_PCD8544_CE_TRIS			= PG_OUT;
		PG_LCD_PCD8544_DC_TRIS			= PG_OUT;
		PG_LCD_PCD8544_BACKLIGHT_TRIS	= PG_OUT;
		PG_LCD_PCD8544_RST_TRIS			= PG_OUT;
		
		// #if	(sotto compilazione selettiva)
			// PG_LCD_PCD8544_VDD_TRIS	= PG_OUT;
		// #endif
		
		//
		PG_SPI_SDI_TRIS					= PG_IN;
		PG_SPI_SDO_TRIS					= PG_OUT;
		PG_SPI_SCK_TRIS					= PG_OUT;
		PG_SPI_SS_TRIS					= PG_IN;
		//
		PG_LCD_PCD8544_CE				= PG_HIGH;
		//
		//pg_spi_open( PG_SPI_1, PG_SPI_MASTER_FOSC_16, MODE_00, SMPEND );
		pg_delay_msec( 15 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_FUNCTION + 0x01 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_EXT_SET_VOP + 0x40 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_EXT_TEMP_CONTROL + 0x02 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_EXT_BIAS_CONTROL + 0x03 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_FUNCTION + 0x00 );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_CONFIGURATION + 0x04 );
		pg_lcd_pcd8544_backlight( PG_OFF );
		pg_delay_msec( 2 );
		pg_lcd_pcd8544_clear( 0 );
		pg_delay_msec( 2 );
	}

	void pg_lcd_pcd8544_reset( void ) {
		//Reset low within 30[ms], or before, Vdd go high.
		PG_LCD_PCD8544_RST_TRIS	= PG_OUT;
		pg_delay_msec( 1 );
		PG_LCD_PCD8544_RST		= PG_LOW;
		pg_delay_msec( 150 );
		PG_LCD_PCD8544_RST		= PG_HIGH;
	}
	
	#if ( PGIM_FONT == PG_ENABLE )
		void pg_lcd_pcd8544_font_select( rom const _pg_Uint8 * font ) {
			fxy.width	= font[ 0 ];
			fxy.height	= font[ 1 ];
			fxy.mask	= font[ 2 ];
			fxy.font	= font;
		}
	#endif	

	void pg_lcd_pcd8544_send( _pg_Uint8 dc , _pg_Uint8 chr ) {
		
//		pg_spi_open( PG_LCD_PCD8544_SPI_PORT , PG_LCD_PCD8544_SPI_SYNC_MODE , PG_LCD_PCD8544_SPI_BUS_MODE , PG_LCD_PCD8544_SPI_SMP_PHASE );
		pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_16, MODE_00, SMPEND );
		
		PG_LCD_PCD8544_CE	= 0;
		if ( dc == PG_PCD8544_DATA )
			PG_LCD_PCD8544_DC = 1;
		else if ( dc == PG_PCD8544_COMMAND )
			PG_LCD_PCD8544_DC = 0;
		putcSPI( chr );
		PG_LCD_PCD8544_CE	= 1;
//		pg_spi_close( PG_LCD_PCD8544_SPI_PORT );
		pg_spi_close( PG_SPI_0 );
	}

	void pg_lcd_pcd8544_clear( _pg_Uint8 wb ) {
		_pg_Uint16 n;
		_pg_Uint8 bg;
		if( wb )
			bg = 0xFF;
		else
			bg = 0x00;
		pg_lcd_pcd8544_set_pos( 0 , 0 );
		for( n = 0 ; n < 504 ; n++ ) {
			pg_lcd_pcd8544_send( PG_PCD8544_DATA , bg );
		}
	}

	#if ( PGIM_FONT == PG_ENABLE )
		#if ( PG_PROJECT_STATE == PG_DEBUG )
			#warning	PG_HS_PG PG_HS_MSG The font functions is compiling too.
		#endif
		// void pg_lcd_pcd8544_send_char( _pg_Uint8 character ) {
			// _pg_Uint8 column = 0;
			// character = character - 0x20; 						// 0x20 is the first element of the array
			// for( column = 0 ; column < fxy.width ; column++ ) {			// Pass through each column
				// pg_lcd_pcd8544_send( PG_PCD8544_DATA , fxy.font[ ( _pg_int16 ) character * fxy.width + column + 2 ] );
			// }
			// pg_lcd_pcd8544_send( PG_PCD8544_DATA , 0x00 ); 							// Send a colon (1 byte) as space
		// }

		// void pg_lcd_pcd8544_send_string_rom( rom _pg_int8 * string ) {
			// while( *string ) {
				// pg_lcd_pcd8544_send_char( *string );
				// string++;
			// }
		// }		
		
		void pg_lcd_pcd8544_send_char( _pg_Uint8 character ) {
			_pg_Uint8 column = 0;
			character = character - 0x20; 											// 0x20 is the first element of the array
			
			if( !fxy.mask ) {
				for( column = 0 ; column < fxy.width  ; column++ ) {				// Pass through each column
					pg_lcd_pcd8544_send( PG_PCD8544_DATA , fxy.font[ (_pg_int16)character * fxy.width + column + 3 ] );
				}
			}
			if( fxy.mask ) {
				for( column = 0 ; column < ( fxy.width + 1 ) ; column++ ) {			// Pass through each column
					if( ( ( 0x01 << column ) & fxy.font[ (_pg_int16)character * ( fxy.width + 1 ) + 3 ] ) ) {
						pg_lcd_pcd8544_send( PG_PCD8544_DATA , fxy.font[ (_pg_int16)character * ( fxy.width + 1 ) + column + 4 ] );
					}
				}
			}
			
			// for( column = 0 ; column < ( fxy.width + 1 ) ; column++ ) {			// Pass through each column
				// if( fxy.mask && ( ( 0x01 << column ) & fxy.font[ (_pg_int16)character * ( fxy.width + 1 ) + 3 ] ) ) {
					// pg_lcd_pcd8544_send( PG_PCD8544_DATA , fxy.font[ (_pg_int16)character * ( fxy.width + 1 ) + column + 4 ] );
				// }
				// if( !fxy.mask ) {
					// pg_lcd_pcd8544_send( PG_PCD8544_DATA , fxy.font[ (_pg_int16)character * fxy.width + column + 3 ] );
				// }
			// }
			
			pg_lcd_pcd8544_send( PG_PCD8544_DATA , 0x00 ); 				// Send a colon (1 byte) as space
		}

		void pg_lcd_pcd8544_send_string_rom( rom _pg_int8 * string ) {
			while( *string ) {
				pg_lcd_pcd8544_send_char( *string );
				string++;
			}
		}

//----------------------------------------------------------------------------
		void pg_lcd_pcd8544_send_string( _pg_int8 * string ) {
			while( *string ) {
				pg_lcd_pcd8544_send_char( *string );
				string++;
			}
		}

		
//----------------------------------------------------------------------------
		void pg_lcd_pcd8544_write_pint( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  * Format , _pg_int16 Val ) {
			_pg_int8 Str[ 16 ];
			pg_lcd_pcd8544_set_pos( x , y );
			sprintf( Str , Format , Val );
			pg_lcd_pcd8544_send_string( Str );
		}

		
//----------------------------------------------------------------------------
		void pg_lcd_pcd8544_write_pfloat( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  *Format , float Flt ) {
			_pg_int8 Str[ 16 ];
			pg_lcd_pcd8544_set_pos( x , y );
			sprintf( Str , Format , Flt );
			pg_lcd_pcd8544_send_string( Str );
		}


		void pg_lcd_pcd8544_write_pchar( _pg_Uint8 x , _pg_Uint8 y , const rom far _pg_int8  * Format , _pg_int8 chr ) {
			_pg_int8 Str[ 16 ];
			pg_lcd_pcd8544_set_pos( x , y );
			sprintf( Str , Format , chr );
			pg_lcd_pcd8544_send_string( Str );
		}


	#endif    	

	void pg_lcd_pcd8544_backlight( _pg_int8 flag ) {
		if ( flag )
			PG_LCD_PCD8544_BACKLIGHT = PG_ON;
		else
			PG_LCD_PCD8544_BACKLIGHT = PG_OFF;
	}

	void pg_lcd_pcd8544_set_pos( _pg_Uint8 x , _pg_Uint8 y ) {
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_ADDRESS_X + x );
		pg_lcd_pcd8544_send( PG_PCD8544_COMMAND , PG_PCD8544_ADDRESS_Y + y );
	}
	
	// #if	(sotto compilazione selettiva)
	//void pg_lcd_pcd8544_power( _pg_Uint8 status ) {
	//PG_LCD_PCD8544_VDD
	// }
	//#endif
	
#endif


//while (!DataRdySPI()); to add???


