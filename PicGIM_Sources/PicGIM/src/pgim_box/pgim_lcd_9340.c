//
// pgim_pg_lcd_9340.c
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

/*!		\file			pgim_pg_lcd_9340.c
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

#if ( PGIM_LCD_9340 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif

	void pg_lcd_9340_init( void ) {
		PG_LCD_9340_CS_TRIS			= PG_OUT;
		PG_LCD_9340_RST_TRIS		= PG_OUT;
		PG_LCD_9340_RS_TRIS			= PG_OUT;
		PG_SPI_SDI_TRIS				= PG_IN;
		PG_SPI_SDO_TRIS				= PG_OUT;
		PG_SPI_SCK_TRIS				= PG_OUT;
//		PG_SPI_SS_TRIS				= PG_IN;
		PG_LCD_9340_BACKLIGHT_TRIS	= PG_OUT;
		pg_spi_open( PG_SPI_0 , PG_SPI_MASTER_FOSC_16 , MODE_00 , SMPEND );
		pg_delay_msec( 20 );
		PG_LCD_9340_CS	= 0;
		PG_LCD_9340_RST	= 0;
		pg_delay_msec( 20 );
		PG_LCD_9340_RST	= 1;
		pg_lcd_9340_WR_command_8( 0xCB );
		pg_lcd_9340_WR_data_8( 0x39 );
		pg_lcd_9340_WR_data_8( 0x2C );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x34 );
		pg_lcd_9340_WR_data_8( 0x02 );
		pg_lcd_9340_WR_command_8( 0xCF );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0XC1 );
		pg_lcd_9340_WR_data_8( 0X30 );
		pg_lcd_9340_WR_command_8( 0xE8 );
		pg_lcd_9340_WR_data_8( 0x85 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x78 );
		pg_lcd_9340_WR_command_8( 0xEA );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_command_8( 0xED );
		pg_lcd_9340_WR_data_8( 0x64 );
		pg_lcd_9340_WR_data_8( 0x03 );
		pg_lcd_9340_WR_data_8( 0X12 );
		pg_lcd_9340_WR_data_8( 0X81 );
		pg_lcd_9340_WR_command_8( 0xF7 );
		pg_lcd_9340_WR_data_8( 0x20 );
		pg_lcd_9340_WR_command_8( 0xC0 );               //Power control
		pg_lcd_9340_WR_data_8( 0x23 );                  //VRH[5:0]
		pg_lcd_9340_WR_command_8( 0xC1 );               //Power control
		pg_lcd_9340_WR_data_8( 0x10 );                  //SAP[2:0];BT[3:0]
		pg_lcd_9340_WR_command_8( 0xC5 );               //VCM control
		pg_lcd_9340_WR_data_8( 0x3e );                  //
		pg_lcd_9340_WR_data_8( 0x28 );
		pg_lcd_9340_WR_command_8( 0xC7 );               //VCM control2
		pg_lcd_9340_WR_data_8( 0x86 );                  //--
		//---------------------------------------------------------
		pg_lcd_9340_WR_command_8( 0x36 );               //Memory Access Control ORIGINALE!
		//pg_lcd_9340_WR_Command_8( 0x37 );             //Memory Access Control
		pg_lcd_9340_WR_data_8( 0x48 );                  //valore originale              DAL BASSO VERSO L'ALTO
		//pg_lcd_9340_WR_Data_8( 0xC8 );                //valore di altro sorgente      DALL'ALTO VERSO IL BASSO
		//---------------------------------------------------------
		pg_lcd_9340_WR_command_8( 0x3A );
		pg_lcd_9340_WR_data_8( 0x55 );                  //16bit Format
		pg_lcd_9340_WR_command_8( 0xB1 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x18 );
		pg_lcd_9340_WR_command_8( 0xB6 );               //Display Function Control
		pg_lcd_9340_WR_data_8( 0x08 );
		pg_lcd_9340_WR_data_8( 0x82 );
		pg_lcd_9340_WR_data_8( 0x27 );
		pg_lcd_9340_WR_command_8( 0xF2 );               //3Gamma Function Disable
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_command_8( 0x26 );               //Gamma curve selected
		pg_lcd_9340_WR_data_8( 0x01 );
		pg_lcd_9340_WR_command_8( 0xE0 );               //Set Gamma
		pg_lcd_9340_WR_data_8( 0x0F );
		pg_lcd_9340_WR_data_8( 0x31 );
		pg_lcd_9340_WR_data_8( 0x2B );
		pg_lcd_9340_WR_data_8( 0x0C );
		pg_lcd_9340_WR_data_8( 0x0E );
		pg_lcd_9340_WR_data_8( 0x08 );
		pg_lcd_9340_WR_data_8( 0x4E );
		pg_lcd_9340_WR_data_8( 0xF1 );
		pg_lcd_9340_WR_data_8( 0x37 );
		pg_lcd_9340_WR_data_8( 0x07 );
		pg_lcd_9340_WR_data_8( 0x10 );
		pg_lcd_9340_WR_data_8( 0x03 );
		pg_lcd_9340_WR_data_8( 0x0E );
		pg_lcd_9340_WR_data_8( 0x09 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_command_8( 0XE1 );               //Set Gamma
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x0E );
		pg_lcd_9340_WR_data_8( 0x14 );
		pg_lcd_9340_WR_data_8( 0x03 );
		pg_lcd_9340_WR_data_8( 0x11 );
		pg_lcd_9340_WR_data_8( 0x07 );
		pg_lcd_9340_WR_data_8( 0x31 );
		pg_lcd_9340_WR_data_8( 0xC1 );
		pg_lcd_9340_WR_data_8( 0x48 );
		pg_lcd_9340_WR_data_8( 0x08 );
		pg_lcd_9340_WR_data_8( 0x0F );
		pg_lcd_9340_WR_data_8( 0x0C );
		pg_lcd_9340_WR_data_8( 0x31 );
		pg_lcd_9340_WR_data_8( 0x36 );
		pg_lcd_9340_WR_data_8( 0x0F );
		pg_lcd_9340_WR_command_8( 0x11 );               //Exit Sleep
		pg_delay_msec( 120 );
		pg_lcd_9340_WR_command_8( 0x29 );               //Display on
		pg_lcd_9340_WR_command_8( 0x2c );
		PG_LCD_9340_CS	= 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_command_8( unsigned char cmd ) {
		//
		PG_LCD_9340_RS = 0;
		PG_LCD_9340_CS = 0;
		putcSPI( cmd );
		PG_LCD_9340_CS = 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_command_16( unsigned char cmd_1 , unsigned char cmd_0 ) {
		//
		PG_LCD_9340_RS = 0;
		PG_LCD_9340_CS = 0;
		putcSPI( cmd_1 );
		PG_LCD_9340_CS = 1;
		//
		pg_delay_usec( 10 );
		//
		PG_LCD_9340_CS = 0;
		putcSPI( cmd_0 );
		PG_LCD_9340_CS = 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_command_16INT( unsigned int icmd ) {
		//
		PG_LCD_9340_RS = 0;
		PG_LCD_9340_CS = 0;
		pg_lcd_9340_WR_command_8( icmd >> 8 );
		pg_lcd_9340_WR_command_8( icmd );
		PG_LCD_9340_CS = 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_data_8( unsigned char data ) {
		//
		PG_LCD_9340_RS = 1;
		PG_LCD_9340_CS = 0;
		putcSPI( data );
		PG_LCD_9340_CS = 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_data_16( unsigned char data1 , unsigned char data0 ) {
		//
		PG_LCD_9340_RS = 1;
		PG_LCD_9340_CS = 0;
		putcSPI( data1 );
		PG_LCD_9340_CS = 1;
		//
		pg_delay_usec( 10 );
		//
		PG_LCD_9340_CS = 0;
		putcSPI( data0 );
		PG_LCD_9340_CS = 1;
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_WR_data_16INT( unsigned int idato ) {
		//
		pg_lcd_9340_WR_data_8( idato >> 8 );
		pg_lcd_9340_WR_data_8( idato );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_reset( void ) {
		//
		PG_LCD_9340_RST = 1;
		pg_delay_msec( 1 );
		PG_LCD_9340_RST = 0;
		pg_delay_msec( 10 );
		PG_LCD_9340_RST = 1;
		pg_delay_msec( 120 );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_sleep( void ) {
		//
		pg_lcd_9340_WR_command_8( 0x28 );                       //Display off
		pg_delay_msec( 20 );
		pg_lcd_9340_WR_command_8( 0x10 );                       //Enter Sleep mode
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_exitsleep( void ) {
		//
		pg_lcd_9340_WR_command_8( 0x11 );                               //Exit Sleep
		pg_delay_msec( 120 );
		pg_lcd_9340_WR_command_8( 0x29 );                               //Display on
		pg_lcd_9340_WR_command_8( 0x2c );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_disp_single_color( unsigned char DH , unsigned char DL ) {
		//
		unsigned int i , j;
		pg_lcd_9340_set_pos( 0 , 0 );
		for ( i = 0; i < 320; i++ ) {
			for ( j = 0; j < 240; j++ ) {
				pg_lcd_9340_WR_command_16( DH , DL );
			}
		}
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_prova_imm( void ) {
		//
		int i , j;
		pg_lcd_9340_address_set( 0 , 239 , 0 , 319 );

		//pg_lcd_9340_WR_Command_8( 0x2C ); WR MEM
		//pg_lcd_9340_WR_Command_8( 0x3C ); WR MEM CONTINUE

		for( i = 0; i < 320; i++ ) {
			for( j = 0; j < 240; j++ ) {
				//pg_lcd_9340_WR_Data_8( color );
				//pg_lcd_9340_WR_Data_16INT( color );
			}
		}
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_test_single_color( int color ) {
		//
		int i , j;
		pg_lcd_9340_address_set( 0 , 239 , 0 , 319 );
		for( i = 0; i < 320; i++ ) {
			for( j = 0; j < 240; j++ ) {
				//pg_lcd_9340_WR_Data_8( color );
				pg_lcd_9340_WR_data_16INT( color );
			}
		}
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_test_single_gradient( int color ) {    //da rivedere
		//
		int i , j;
		pg_lcd_9340_address_set( 0 , 239 , 0 , 319 );       //??
		for( i = 0; i < 320; i++ ) {
			for( j = 0; j < 240; j++ ) {
				//pg_lcd_9340_WR_Data_8( color );
				pg_lcd_9340_WR_data_16INT( color );
			}
			color = color + 32;
		}
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_address_set( unsigned int x1 , unsigned int x2 , unsigned int y1 , unsigned int y2 ) {
		//
		pg_lcd_9340_WR_command_8( 0x2a );
		pg_lcd_9340_WR_data_16INT( x1 );
		pg_lcd_9340_WR_data_16INT( x2 );
		pg_lcd_9340_WR_command_8( 0x2b );
		pg_lcd_9340_WR_data_16INT( y1 );
		pg_lcd_9340_WR_data_16INT( y2 );
		pg_lcd_9340_WR_command_8( 0x2c );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_set_pos( unsigned int x , unsigned int y ) {                    //VERIFICARE!
		//
		pg_lcd_9340_WR_command_8( 0x2a );
		pg_lcd_9340_WR_data_16( x >> 8 , x );
		pg_lcd_9340_WR_command_8( 0x2b );
		pg_lcd_9340_WR_data_16( y >> 8 , y );
		pg_lcd_9340_WR_command_8( 0x2c );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_set_pos_2( unsigned int x0 , unsigned int y0 , unsigned int x1 , unsigned int y1 ) {              //VERIFICARE!
		//
		pg_lcd_9340_WR_command_8( 0x2A );
		pg_lcd_9340_WR_data_8( x0 >> 8 );
		pg_lcd_9340_WR_data_8( x0 );
		pg_lcd_9340_WR_data_8( x1 >> 8 );
		pg_lcd_9340_WR_data_8( x1 );

		pg_lcd_9340_WR_command_8( 0x2B );
		pg_lcd_9340_WR_data_8( y0 >> 8 );
		pg_lcd_9340_WR_data_8( y0 );
		pg_lcd_9340_WR_data_8( y1 >> 8 );
		pg_lcd_9340_WR_data_8( y1 );
		pg_lcd_9340_WR_command_8( 0x2c );
	}

	//----------------------------------------------------------------------------


	void  pg_lcd_9340_ram_adress_set( void ) {
		//
		pg_lcd_9340_WR_command_8( 0x2A );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0xaf );

		pg_lcd_9340_WR_command_8( 0x2B );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0x00 );
		pg_lcd_9340_WR_data_8( 0xdb );
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_test_picture( unsigned char *map ) {
		//
		int i , j;
		pg_lcd_9340_ram_adress_set( );
		for( i = 0; i < 76; i++ ) {
			for( j = 0; j < 96; j++ ) {
				pg_lcd_9340_WR_data_16( map[ 192 * i + j * 2 ] , map[ 192 * i + j * 2 + 1 ] );
			}
		}
	}

	//----------------------------------------------------------------------------


	void pg_lcd_9340_show_image( const unsigned char *image ) {
		//
		int i , j , k;
		unsigned char picH , picL;
		pg_lcd_9340_disp_single_color( 0xff , 0xff );
		for( k = 0; k < 8; k++ ) {
			for( j = 0; j < 6; j++ ) {
				pg_lcd_9340_set_pos_2( 40 * j , 40 * k , 40 * j + 39 , 40 * k + 39 );
				for( i = 0; i < 1600; i++ ) {
					picH = *( image + i * 2 + 1 );
					picL = *( image + i * 2 );
					pg_lcd_9340_WR_data_16( picH , picL );
				}
			}
		}
	}
#endif


