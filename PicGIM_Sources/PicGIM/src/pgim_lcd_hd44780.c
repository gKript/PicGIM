/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_lcd_hd44780.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_lcd_hd44780.h

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

 /*!
		\file		pgim_lcd_hd44780.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		Configures and manages character lcd display with HD44780 controller
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#include "picgim.h"

#if	( PGIM_LCD_HD44780 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	void pg_lcd_hd44780_init( void ) {
		//Backlight turn-off and tris
		#if ( PG_LCD_HD44780_BL_0_PRESENT == PG_YES )
			#if ( PG_LCD_HD44780_BL_0_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_0 = PG_LOW;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_0_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_0 = PG_HIGH;	//Active Low
			#endif
			PG_LCD_HD44780_BL_0_TRIS = PG_OUT;
		#endif
		#if ( PG_LCD_HD44780_BL_1_PRESENT == PG_YES )
			#if ( PG_LCD_HD44780_BL_1_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_1 = PG_LOW;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_1_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_1 = PG_HIGH;	//Active Low
			#endif
			PG_LCD_HD44780_BL_1_TRIS = PG_OUT;
		#endif
		#if ( PG_LCD_HD44780_BL_2_PRESENT == PG_YES )
			#if ( PG_LCD_HD44780_BL_2_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_2 = PG_LOW;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_2_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_2 = PG_HIGH;	//Active Low
			#endif
			PG_LCD_HD44780_BL_2_TRIS = PG_OUT;
		#endif
		#if ( PG_LCD_HD44780_BL_3_PRESENT == PG_YES )
			#if ( PG_LCD_HD44780_BL_3_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_3 = PG_LOW;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_3_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_3 = PG_HIGH;	//Active Low
			#endif
			PG_LCD_HD44780_BL_3_TRIS = PG_OUT;
		#endif

		//Lcd control tris
		#if( PG_LCD_HD44780_EN_0_PRESENT == PG_YES )
			PG_LCD_HD44780_EN_0 = PG_DISABLE;
			PG_LCD_HD44780_EN_0_TRIS = PG_OUT;
		#endif
		#if( PG_LCD_HD44780_EN_1_PRESENT == PG_YES )
			PG_LCD_HD44780_EN_1 = PG_DISABLE;
			PG_LCD_HD44780_EN_1_TRIS = PG_OUT;
		#endif
		#if( PG_LCD_HD44780_EN_2_PRESENT == PG_YES )
			PG_LCD_HD44780_EN_2 = PG_DISABLE;
			PG_LCD_HD44780_EN_2_TRIS = PG_OUT;
		#endif
		#if( PG_LCD_HD44780_EN_3_PRESENT == PG_YES )
			PG_LCD_HD44780_EN_3 = PG_DISABLE;
			PG_LCD_HD44780_EN_3_TRIS = PG_OUT;
		#endif
		#if ( PG_LCD_HD44780_RW_PRESENT == PG_YES )
			PG_LCD_HD44780_RW = PG_LOW;
			PG_LCD_HD44780_RW_TRIS = PG_OUT;
		#endif
		PG_LCD_HD44780_RS_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_0_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_1_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_2_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_3_TRIS  = PG_OUT;
		
		//Initialize controllers
		#if ( PG_LCD_HD44780_EN_0_PRESENT == PG_YES )
			pg_lcd_hd44780_init_routine( PG_CONTROLLER_0 );
		#endif
		#if ( PG_LCD_HD44780_EN_1_PRESENT == PG_YES )
			pg_lcd_hd44780_init_routine( PG_CONTROLLER_1 );
		#endif
		#if ( PG_LCD_HD44780_EN_2_PRESENT == PG_YES )
			pg_lcd_hd44780_init_routine( PG_CONTROLLER_2 );
		#endif
		#if ( PG_LCD_HD44780_EN_3_PRESENT == PG_YES )
			pg_lcd_hd44780_init_routine( PG_CONTROLLER_3 );
		#endif
		
		//Backlight turn-on
		#if ( ( PG_LCD_HD44780_BL_0_PRESENT == PG_YES ) && ( PG_LCD_HD44780_BL_0_ENABLE == PG_ENABLE ) )
			#if ( PG_LCD_HD44780_BL_0_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_0 = PG_HIGH;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_0_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_0 = PG_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PG_LCD_HD44780_BL_1_PRESENT == PG_YES ) && ( PG_LCD_HD44780_BL_1_ENABLE == PG_ENABLE ) )
			#if ( PG_LCD_HD44780_BL_1_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_1 = PG_HIGH;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_1_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_1 = PG_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PG_LCD_HD44780_BL_2_PRESENT == PG_YES ) && ( PG_LCD_HD44780_BL_2_ENABLE == PG_ENABLE ) )
			#if ( PG_LCD_HD44780_BL_2_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_2 = PG_HIGH;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_2_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_2 = PG_LOW;	//Active Low
			#endif
		#endif
		#if ( ( PG_LCD_HD44780_BL_3_PRESENT == PG_YES ) && ( PG_LCD_HD44780_BL_3_ENABLE == PG_ENABLE ) )
			#if ( PG_LCD_HD44780_BL_3_ENABLE_LOGIC == PG_POSITIVE )
				PG_LCD_HD44780_BL_3 = PG_HIGH;	//Active High
			#endif
			#if ( PG_LCD_HD44780_BL_3_ENABLE_LOGIC == PG_NEGATIVE )
				PG_LCD_HD44780_BL_3 = PG_LOW;	//Active Low
			#endif
		#endif
		
		//Splash screen FULL
		#if ( ( PG_LCD_HD44780_EN_0_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_FULL_0_EN ) )
			pg_lcd_hd44780_splash_full( PG_CONTROLLER_0 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_1_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_FULL_1_EN ) )
			pg_lcd_hd44780_splash_full( PG_CONTROLLER_1 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_2_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_FULL_2_EN ) )
			pg_lcd_hd44780_splash_full( PG_CONTROLLER_2 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_3_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_FULL_3_EN ) )
			pg_lcd_hd44780_splash_full( PG_CONTROLLER_3 );
		#endif
		
		//Splash screen SLIDE
		#if ( ( PG_LCD_HD44780_EN_0_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_SLIDE_0_EN ) )
			pg_lcd_hd44780_splash_slide( PG_CONTROLLER_0 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_1_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_SLIDE_1_EN ) )
			pg_lcd_hd44780_splash_slide( PG_CONTROLLER_1 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_2_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_SLIDE_2_EN ) )
			pg_lcd_hd44780_splash_slide( PG_CONTROLLER_2 );
		#endif
		#if ( ( PG_LCD_HD44780_EN_3_PRESENT == PG_YES ) && ( PG_LCD_HD44780_SPLASH_SLIDE_3_EN ) )
			pg_lcd_hd44780_splash_slide( PG_CONTROLLER_3 );
		#endif
	}


	void pg_lcd_hd44780_init_routine( _pg_Uint8 ControllerNumber ) {
		pg_delay_msec( 200 );
		PG_LCD_HD44780_RS = PG_COMMAND;
		if( PG_LCD_HD44780_RW_PRESENT )
			PG_LCD_HD44780_RW = PG_WRITE;
		pg_lcd_hd44780_en_select( ControllerNumber , PG_DISABLE );
//		pg_lcd_hd44780_en_select( ControllerNumber , PG_ENABLE );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000011 );
		pg_delay_msec( 50 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000011 );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000011 );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000010 );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000010 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00001000 );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000000 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00001000 );
		pg_delay_msec( 1 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000000 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000001 );
		pg_delay_msec( 20 );
		
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000000 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000110 );
		pg_delay_msec( 1 );

		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00000000 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , PG_COMMAND , 0b00001100 );	//pg_ldc_hd44780_write_nibble( PG_TRUE , 0b00001101 );cursor blink
		pg_delay_msec( 1 );
		
		pg_lcd_hd44780_clear( ControllerNumber );
		pg_delay_msec( 10 );
		pg_lcd_hd44780_goto( ControllerNumber , 0 , 0 );
		pg_delay_msec( 10 );
	}
	
	
	#if ( ( PG_LCD_HD44780_SPLASH_FULL_0_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_1_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_2_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_3_EN == PG_ENABLE ) )
		void	pg_lcd_hd44780_splash_full( _pg_Uint8 ControllerNumber ) {
			_pg_Uint8 c, r;
			for ( r = 0  ; r < PG_LCD_HD44780_LINES ; r++ ) {
				for ( c = 0  ; c < PG_LCD_HD44780_COLUMNS ; c++ ) {
					pg_lcd_hd44780_write_p_char( ControllerNumber , r , c , "%c" , 0xff );
				}
			}
			#if ( PG_LCD_HD44780_SPLASH_FULL_DELAY != 0 )
				pg_delay_sec( PG_LCD_HD44780_SPLASH_FULL_DELAY );
				pg_lcd_hd44780_clear( ControllerNumber );
				pg_lcd_hd44780_goto( ControllerNumber , 0 , 0 );
			#endif
			pg_delay_msec( 500 );
		}		
	#endif

	
	#if ( ( PG_LCD_HD44780_SPLASH_SLIDE_0_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_1_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_2_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_3_EN == PG_ENABLE ) )
		void	pg_lcd_hd44780_splash_slide( _pg_Uint8 ControllerNumber ) {
			_pg_Uint8 c, r;
			for ( r = 0 ; r < PG_LCD_HD44780_LINES ; r++ ) {
				for ( c = 0 ; c < PG_LCD_HD44780_COLUMNS ; c++ ) {
					pg_lcd_hd44780_write_p_char( ControllerNumber , r , c , "%c" , 0xff );
					pg_delay_msec( PG_LCD_HD44780_SPLASH_SLIDE_SPEED );	//100
					if ( c >= 1 )
						pg_lcd_hd44780_write_p_char( ControllerNumber , r , c - 1 , "%c" , 0x20 );
				}
				pg_lcd_hd44780_write_p_char( ControllerNumber , r , c , "%c" , 0x20 );
			}
			pg_lcd_hd44780_clear( ControllerNumber );
			pg_lcd_hd44780_goto( ControllerNumber , 0 , 0 );
			pg_delay_msec( 500 );
		}
	#endif

	
	#if ( PG_LCD_HD44780_BUSY_FLAG == PG_ENABLE )
		_pg_Uint8 pg_lcd_hd44780_read_byte( _pg_Uint8 ControllerNumber ) {
			_pg_Uint8 	Dat;
			
			PG_LCD_HD44780_DATA_0_TRIS  = PG_IN;
			PG_LCD_HD44780_DATA_1_TRIS  = PG_IN;
			PG_LCD_HD44780_DATA_2_TRIS  = PG_IN;
			PG_LCD_HD44780_DATA_3_TRIS  = PG_IN;
			
			pg_lcd_hd44780_en_select( ControllerNumber , PG_ENABLE );
			pg_delay_usec( 5 );
			
			Dat = 0x00;
			if( PG_LCD_HD44780_DATA_3_PORT )	Dat |= 0x80;
			if( PG_LCD_HD44780_DATA_2_PORT )	Dat |= 0x40;
			if( PG_LCD_HD44780_DATA_1_PORT )	Dat |= 0x20;
			if( PG_LCD_HD44780_DATA_0_PORT )	Dat |= 0x10;
			
			pg_lcd_hd44780_en_select( ControllerNumber , PG_DISABLE );
			pg_delay_usec( 5 );
			
			pg_lcd_hd44780_en_select( ControllerNumber , PG_ENABLE );
			pg_delay_usec( 5 );
			
			if( PG_LCD_HD44780_DATA_3_PORT )	Dat |= 0x08;
			if( PG_LCD_HD44780_DATA_2_PORT )	Dat |= 0x04;
			if( PG_LCD_HD44780_DATA_1_PORT )	Dat |= 0x02;
			if( PG_LCD_HD44780_DATA_0_PORT )	Dat |= 0x01;
			
			pg_lcd_hd44780_en_select( ControllerNumber , PG_DISABLE );
			pg_delay_usec( 5  );

			PG_LCD_HD44780_DATA_0_TRIS  = PG_OUT;
			PG_LCD_HD44780_DATA_1_TRIS  = PG_OUT;
			PG_LCD_HD44780_DATA_2_TRIS  = PG_OUT;
			PG_LCD_HD44780_DATA_3_TRIS  = PG_OUT;
			
			return Dat;
		}
	#endif 


	void pg_lcd_hd44780_wait_busy( _pg_Uint8 ControllerNumber ) {
		#if ( PG_LCD_HD44780_BUSY_FLAG == PG_ENABLE )
			_pg_Uint8 Status;
			PG_LCD_HD44780_RS = PG_COMMAND;
			if( PG_LCD_HD44780_RW_PRESENT )
				PG_LCD_HD44780_RW = PG_READ;
			do {
				Status = pg_lcd_hd44780_read_byte( ControllerNumber );
			} while ( Status & 0x80 );
			if( PG_LCD_HD44780_RW_PRESENT )
				PG_LCD_HD44780_RW = PG_WRITE;
		#else
			pg_delay_usec( PG_LCD_HD44780_BUSY_DELAY );
		#endif
	}


	void pg_ldc_hd44780_write_nibble( _pg_Uint8 ControllerNumber , _pg_Uint8 DataType , _pg_Uint8 Dat ) {
		// es.: pg_ldc_hd44780_write_nibble( PG_CONTROLLER_0 , PG_COMMAND , 0x01 );
		
		if( ( ControllerNumber < 0 ) || ( ControllerNumber > 4 ) || ( ControllerNumber == PG_MISSING ) )
			return;	//gestire errore
			
		PG_LCD_HD44780_RS = DataType;
		if( PG_LCD_HD44780_RW_PRESENT )
			PG_LCD_HD44780_RW = PG_WRITE;
		pg_lcd_hd44780_en_select( ControllerNumber , PG_ENABLE );
		pg_delay_msec( 1 );
		
		PG_LCD_HD44780_DATA_0 = PG_LCD_HD44780_DATA_1 = PG_LCD_HD44780_DATA_2 = PG_LCD_HD44780_DATA_3 = PG_CLEAR;
		
		Dat &= 0x0F;	//superfluo?
		if ( Dat & 0x08 )	PG_LCD_HD44780_DATA_3 = 1;
		if ( Dat & 0x04 )	PG_LCD_HD44780_DATA_2 = 1;
		if ( Dat & 0x02 )	PG_LCD_HD44780_DATA_1 = 1;
		if ( Dat & 0x01 )	PG_LCD_HD44780_DATA_0 = 1;
		
		pg_lcd_hd44780_en_select( ControllerNumber , PG_DISABLE );
		pg_delay_msec( 1 );
	}


	void pg_lcd_hd44780_write_byte( _pg_Uint8 ControllerNumber , _pg_Uint8 DataType , _pg_Uint8 Dat ) {
		pg_ldc_hd44780_write_nibble( ControllerNumber , DataType , Dat >> 4 );
		pg_ldc_hd44780_write_nibble( ControllerNumber , DataType , Dat );
	}
	
	
	void pg_lcd_hd44780_en_select( _pg_Uint8 ControllerNumber , _pg_Uint8 EnState ) {
		//	es.: pg_lcd_hd44780_en_select( PG_CONTROLLER_0 , PG_ENABLE );
		#if ( PG_LCD_HD44780_EN_0_PRESENT == PG_YES )
			if	( ControllerNumber == PG_CONTROLLER_0 )
				PG_LCD_HD44780_EN_0 = EnState;
		#endif
		#if ( PG_LCD_HD44780_EN_1_PRESENT == PG_YES )
			if	( ControllerNumber == PG_CONTROLLER_1 )
				PG_LCD_HD44780_EN_1 = EnState;
		#endif
		#if ( PG_LCD_HD44780_EN_2_PRESENT == PG_YES )
			if	( ControllerNumber == PG_CONTROLLER_2 )
				PG_LCD_HD44780_EN_2 = EnState;
		#endif
		#if ( PG_LCD_HD44780_EN_3_PRESENT == PG_YES )
			if	( ControllerNumber == PG_CONTROLLER_3 )
				PG_LCD_HD44780_EN_3 = EnState;
		#endif
	}


	void pg_lcd_hd44780_clear( _pg_Uint8 ControllerNumber ) {
		pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , 0x01 );
		pg_lcd_hd44780_wait_busy( ControllerNumber );
	}


	void pg_lcd_hd44780_goto( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos ) {
		//	es.: pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_0 , 0 )
		
		if ( ( Ln > ( PG_LCD_HD44780_LINES - 1 ) ) || ( Pos > ( PG_LCD_HD44780_COLUMNS - 1 ) ) )
			return;	//gestire errore 
			
		//pg_lcd_hd44780_write_byte( GtControllerNumber , PG_COMMAND , ( Ln == 1 ) ? ( 0xC0 | Pos ) : ( 0x80 | Pos ) );
		
		if( ( ( Ln == PG_LINE_0 ) && ( PG_LCD_HD44780_LINE_0_ADDRESS == PG_MISSING ) ) ||
			( ( Ln == PG_LINE_1 ) && ( PG_LCD_HD44780_LINE_1_ADDRESS == PG_MISSING ) ) ||
			( ( Ln == PG_LINE_2 ) && ( PG_LCD_HD44780_LINE_2_ADDRESS == PG_MISSING ) ) ||
			( ( Ln == PG_LINE_3 ) && ( PG_LCD_HD44780_LINE_3_ADDRESS == PG_MISSING ) ) )
			return;	//gestire errore
		
		if ( Ln == PG_LINE_0 )
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , ( 0x80 | ( PG_LCD_HD44780_LINE_0_ADDRESS + Pos ) ) );
		if ( Ln == PG_LINE_1 )
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , ( 0x80 | ( PG_LCD_HD44780_LINE_1_ADDRESS + Pos ) ) );
		if ( Ln == PG_LINE_2 )
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , ( 0x80 | ( PG_LCD_HD44780_LINE_2_ADDRESS + Pos ) ) );
		if ( Ln == PG_LINE_3 )
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , ( 0x80 | ( PG_LCD_HD44780_LINE_3_ADDRESS + Pos ) ) );
			
		pg_lcd_hd44780_wait_busy( ControllerNumber );

		//		LCD 4x16 ( Model: WH1604A )
		//		
		//			 0  1  2 ... 15
		//	-----------------------
		//	0		00 01 02 ... 0F
		//	1		40 41 42 ... 4F
		//	2		10 11 12 ... 1F
		//	3		50 51 52 ... 5F
	}
	
	
	#if ( PG_LCD_HD44780_CHAR_GENERATOR == PG_INCLUDE )
		void pg_lcd_hd44780_char_generator( _pg_Uint8 ControllerNumber ,char location , char * new_char ) {
			//	Location 0,1,2,...7
			//	pattern[8]={0x06,0x09,0x09,0x06,0x00,0x00,0x00,0x00};
			//	pg_lcd_hd44780_char_generator( 0 , pattern );
			char i;
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , 0x40 + ( location * 8 ) );
			for( i = 0 ; i < 8 ; i++ )
				pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , new_char[i] );
		}
	#endif
	
	
	#if	( PGIM_EE == PG_ENABLE )
		void pg_lcd_hd44780_char_generator_from_EE( _pg_Uint8 ControllerNumber ,char location , _pg_Uint16 ee_addy ) {
			char i;
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , 0x40 + ( location * 8 ) );
			for( i = 0 ; i < 8 ; i++ )
				pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , pg_ee_read( ee_addy + i ) );
		}
	#endif

	
	void pg_lcd_hd44780_put_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Data ) {
		pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , Data );
		pg_lcd_hd44780_wait_busy( ControllerNumber );
	}

	
	#if ( PG_LCD_HD44780_PUT_P_CHAR == PG_INCLUDE )
		void pg_lcd_hd44780_put_p_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Data ) {
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , Data );
			pg_lcd_hd44780_wait_busy( ControllerNumber );
		}
	#endif
	
	
	#if ( PG_LCD_HD44780_PUT_BYTE == PG_INCLUDE )
		void pg_lcd_hd44780_put_byte( _pg_Uint8 ControllerNumber , _pg_Uint8 Val ) {
			pg_lcd_hd44780_put_char( ControllerNumber , Val / 10 + '0' );
			pg_lcd_hd44780_put_char( ControllerNumber , Val % 10 + '0' );
		}
	#endif
	
	
	#if ( PG_LCD_HD44780_PUT_P_BYTE == PG_INCLUDE )
		void pg_lcd_hd44780_put_p_byte( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Val ) {
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			pg_lcd_hd44780_put_char( ControllerNumber , Val / 10 + '0' );
			pg_lcd_hd44780_put_char( ControllerNumber , Val % 10 + '0' );
		}
	#endif
	
	
	void pg_lcd_hd44780_write_string( _pg_Uint8 ControllerNumber , _pg_int8  *Str ) {
		_pg_Uint8 i = 0;
		while ( Str[i] )
			pg_lcd_hd44780_put_char( ControllerNumber , Str[i++] );
	}


	#if ( PG_LCD_HD44780_WRITE_STRING_ROM == PG_INCLUDE )
		//void pg_lcd_hd44780_write_string_rom( _pg_Uint8 ControllerNumber , const rom _pg_int8  *Str ) {
		void pg_lcd_hd44780_write_string_rom( _pg_Uint8 ControllerNumber , const _pg_int8  *Str ) {
			_pg_Uint8 i = 0;
			while ( Str[ i ] )
				pg_lcd_hd44780_put_char( ControllerNumber , Str[ i++ ] );
		}
	#endif
	

	#if ( PG_LCD_HD44780_WRITE_P_STRING == PG_INCLUDE 	)
		void pg_lcd_hd44780_write_p_string( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8  *Str ) {
			_pg_Uint8 i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
				while ( Str[i] )
				pg_lcd_hd44780_put_char( ControllerNumber , Str[i++] );
		}
	#endif
	

	#if ( PG_LCD_HD44780_WRITE_P_STRING_FLASH == PG_INCLUDE )
		void pg_lcd_hd44780_write_p_string_flash( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8  *Str , _pg_Uint8 time , _pg_Uint8 unit ) {
			_pg_Uint8 i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			while ( Str[i] )
				pg_lcd_hd44780_put_char( ControllerNumber , Str[i++] );
			pg_delay( time , unit );
			i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			while ( Str[i++] )
				pg_lcd_hd44780_put_char( ControllerNumber , ' ' );
		}
	#endif

	
	#if ( PG_LCD_HD44780_WRITE_P_STRING_ROM == PG_INCLUDE )
		//void pg_lcd_hd44780_write_p_string_rom( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Str ) {
		void pg_lcd_hd44780_write_p_string_rom( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8  *Str ) {
			_pg_Uint8 i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			while ( Str[ i ] )
				pg_lcd_hd44780_put_char( ControllerNumber , Str[ i++ ] );
		}
	#endif
	
	
	#if ( PG_LCD_HD44780_WRITE_P_STRING_FLASH_ROM == PG_INCLUDE )
		//void pg_lcd_hd44780_write_p_string_flash_rom( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Str , _pg_Uint8 time , _pg_Uint8 unit ) {
		void pg_lcd_hd44780_write_p_string_flash_rom( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8  *Str , _pg_Uint8 time , _pg_Uint8 unit ) {
			_pg_Uint8 i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			while ( Str[ i ] )
				pg_lcd_hd44780_put_char( ControllerNumber , Str[ i++ ] );
			
			pg_delay( time , unit );
			i = 0;
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			while ( Str[ i++ ] )
				pg_lcd_hd44780_put_char( ControllerNumber , ' ' );
		}
	#endif
	
	
	#if ( PG_LCD_HD44780_WRITE_P_INT == PG_INCLUDE )
		//void	pg_lcd_hd44780_write_p_int( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Format , _pg_int16 Val ) {
		void	pg_lcd_hd44780_write_p_int( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8  *Format , _pg_int16 Val ) {
			_pg_int8 Str[ PG_LCD_HD44780_COLUMNS ];
			pg_lcd_hd44780_goto( ControllerNumber ,Ln , Pos );
			sprintf( Str , Format , Val );
			pg_lcd_hd44780_write_string( ControllerNumber , Str );
		}	
	#endif
	
	
	#if ( PGIM_FTOA	== PG_ENABLE )
		void	pg_lcd_hd44780_write_p_float( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint24 Decimal_Digits , float Flt ) {
//			_pg_int8 Str[ PG_LCD_HD44780_COLUMNS ];
			pg_lcd_hd44780_goto( ControllerNumber ,Ln , Pos );
			pg_lcd_hd44780_write_string( ControllerNumber , pg_ftoa( Flt, Decimal_Digits ) );
		}
	#endif

	
	#if ( ( PG_LCD_HD44780_SPLASH_FULL_0_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_1_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_2_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_FULL_3_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_0_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_1_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_2_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_SPLASH_SLIDE_3_EN == PG_ENABLE ) || \
		( PG_LCD_HD44780_WRITE_P_CHAR == PG_ENABLE ) )
		//void	pg_lcd_hd44780_write_p_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Format , _pg_int8 Chr ) {
		void	pg_lcd_hd44780_write_p_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8  *Format , _pg_int8 Chr ) {
			_pg_int8 Str[ PG_LCD_HD44780_COLUMNS ];
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			sprintf( Str , Format , Chr );
			pg_lcd_hd44780_write_string( ControllerNumber , Str );
		}
	#endif

	
	#if ( PG_LCD_HD44780_WRITE == PG_INCLUDE )
		//void	pg_lcd_hd44780_write( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Format , ... ) {
		void	pg_lcd_hd44780_write( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Format , ... ) {
			char    Message[ 2 * PG_LCD_HD44780_COLUMNS ];
			va_list	VAList;
			va_start( VAList , Format );
			vsprintf( Message , Format , VAList );
			va_end( VAList );
			pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
			//pg_lcd_hd44780_write_string( ControllerNumber , Ln , Pos , Message );
			pg_lcd_hd44780_write_string( ControllerNumber , Message );
		}
	#endif
#endif


