//
// pgim_lcd_hd44780.c
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

/*!		\file			pgim_lcd_hd44780.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			Configures and manages character lcd display with HD44780 controller
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if	( PGIM_LCD_HD44780 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif
	
	
	void pg_lcd_hd44780_init( void ) {		
		if( PG_LCD_HD44780_EN_0_PRESENT )		pg_lcd_hd44780_init_routine( PG_CONTROLLER_0 );
		if( PG_LCD_HD44780_EN_1_PRESENT )		pg_lcd_hd44780_init_routine( PG_CONTROLLER_1 );
		if( PG_LCD_HD44780_EN_2_PRESENT )		pg_lcd_hd44780_init_routine( PG_CONTROLLER_2 );
		if( PG_LCD_HD44780_EN_3_PRESENT )		pg_lcd_hd44780_init_routine( PG_CONTROLLER_3 );
	}



	//	Location 0,1,2,...7
	//	pattern[8]={0x06,0x09,0x09,0x06,0x00,0x00,0x00,0x00};
	//	pg_lcd_hd44780_char_generator( 0 , pattern );
	void pg_lcd_hd44780_char_generator( _pg_Uint8 ControllerNumber ,char location , char * new_char ) {
		char i;
		pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , 0x40 + ( location * 8 ) );
		for( i = 0 ; i < 8 ; i++ )
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , new_char[i] );
	}

	#if	( PGIM_EE == PG_ENABLE )

		void pg_lcd_hd44780_char_generator_from_EE( _pg_Uint8 ControllerNumber ,char location , _pg_Uint16 ee_addy ) {
			char i;
			pg_lcd_hd44780_write_byte( ControllerNumber , PG_COMMAND , 0x40 + ( location * 8 ) );
			for( i = 0 ; i < 8 ; i++ )
				pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , pg_ee_read( ee_addy + i ) );
		}

	#endif

	void pg_lcd_hd44780_init_routine( _pg_Uint8 ControllerNumber ) {
		_pg_Uint8 c, r;
		
		if( PG_LCD_HD44780_EN_0_PRESENT ) 	PG_LCD_HD44780_EN_0_TRIS = PG_OUT;
		if( PG_LCD_HD44780_EN_1_PRESENT ) 	PG_LCD_HD44780_EN_1_TRIS = PG_OUT;
		if( PG_LCD_HD44780_EN_2_PRESENT ) 	PG_LCD_HD44780_EN_2_TRIS = PG_OUT;
		if( PG_LCD_HD44780_EN_3_PRESENT ) 	PG_LCD_HD44780_EN_3_TRIS = PG_OUT;

		PG_LCD_HD44780_RW_TRIS  = PG_OUT;
		PG_LCD_HD44780_RS_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_0_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_1_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_2_TRIS  = PG_OUT;
		PG_LCD_HD44780_DATA_3_TRIS  = PG_OUT;

		pg_delay_msec( 200 );
		PG_LCD_HD44780_RS = PG_COMMAND;
		PG_LCD_HD44780_RW = PG_WRITE;
		pg_lcd_hd44780_en_select( ControllerNumber , PG_DISABLE );
		pg_lcd_hd44780_en_select( ControllerNumber , PG_ENABLE );		//superfluo? ci pensera' la write-nibble
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
		
		if( PG_LCD_HD44780_BL_PRESENT ) {
			PG_LCD_HD44780_BL_TRIS = PG_OUT;
			PG_LCD_HD44780_BL = PG_ENABLE;
		}
		#if ( PG_LCD_HD44780_SPLASH_ENABLE == PG_ENABLE )
			for ( r = 0  ; r < PG_LCD_HD44780_LINES ; r++ ) {
				for ( c = 0  ; c < PG_LCD_HD44780_COLUMNS ; c++ ) {
					pg_lcd_hd44780_write_p_char( ControllerNumber , r , c , "%c" , 0xff );
				}
			}
			#if ( PG_LCD_HD44780_SPLASH_TIME != 0 )
				pg_delay_sec( PG_LCD_HD44780_SPLASH_TIME );
				pg_lcd_hd44780_clear( ControllerNumber );
				pg_lcd_hd44780_goto( ControllerNumber , 0 , 0 );
			#endif
		#endif
		}



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
			PG_LCD_HD44780_RW = PG_READ;
			do {
				Status = pg_lcd_hd44780_read_byte( ControllerNumber );
			} while ( Status & 0x80 );
			PG_LCD_HD44780_RW = PG_WRITE;
		#else
			pg_delay_usec( 1 );
		#endif
	}



	void pg_ldc_hd44780_write_nibble( _pg_Uint8 ControllerNumber , _pg_Uint8 DataType , _pg_Uint8 Dat ) {
		// es.: pg_ldc_hd44780_write_nibble( PG_CONTROLLER_0 , PG_COMMAND , 0x01 );
		
		if( ( ControllerNumber < 0 ) || ( ControllerNumber > 4 ) || ( ControllerNumber == PG_MISSING ) )
			return;	//gestire errore
			
		PG_LCD_HD44780_RS = DataType;
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
		if	( ( ControllerNumber == PG_CONTROLLER_0 ) && ( PG_LCD_HD44780_EN_0_PRESENT ) )
			PG_LCD_HD44780_EN_0 = EnState;
		if	( ( ControllerNumber == PG_CONTROLLER_1 ) && ( PG_LCD_HD44780_EN_1_PRESENT ) )
			PG_LCD_HD44780_EN_1 = EnState;
		if	( ( ControllerNumber == PG_CONTROLLER_2 ) && ( PG_LCD_HD44780_EN_2_PRESENT ) )
			PG_LCD_HD44780_EN_2 = EnState;
		if	( ( ControllerNumber == PG_CONTROLLER_3 ) && ( PG_LCD_HD44780_EN_3_PRESENT ) )
			PG_LCD_HD44780_EN_3 = EnState;
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

/*
LCD 4x16 (tipo WH1604A)

			 0  1 --- 15
			------------
	0		00 01 --- 0F
	1		40 41 --- 4F
	2		10 11 --- 1F
	3		50 51 --- 5F

*/

	}


	void pg_lcd_hd44780_put_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Data ) {
		pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , Data );
		pg_lcd_hd44780_wait_busy( ControllerNumber );
	}

	
	void pg_lcd_hd44780_put_p_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Data ) {
		pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
		pg_lcd_hd44780_write_byte( ControllerNumber , PG_DATA , Data );
		pg_lcd_hd44780_wait_busy( ControllerNumber );
	}

	
	void pg_lcd_hd44780_put_byte( _pg_Uint8 ControllerNumber , _pg_Uint8 Val ) {
		pg_lcd_hd44780_put_char( ControllerNumber , Val / 10 + '0' );
		pg_lcd_hd44780_put_char( ControllerNumber , Val % 10 + '0' );
	}

	
	void pg_lcd_hd44780_put_p_byte( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Val ) {
		pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
		pg_lcd_hd44780_put_char( ControllerNumber , Val / 10 + '0' );
		pg_lcd_hd44780_put_char( ControllerNumber , Val % 10 + '0' );
	}

	
	void pg_lcd_hd44780_write_string( _pg_Uint8 ControllerNumber , _pg_int8  *Str ) {
		_pg_Uint8 i = 0;
		while ( Str[i] )
			pg_lcd_hd44780_put_char( ControllerNumber , Str[i++] );
	}


	void pg_lcd_hd44780_write_string_rom( _pg_Uint8 ControllerNumber , const rom _pg_int8  *Str ) {
		_pg_Uint8 i = 0;
		while ( Str[ i ] )
			pg_lcd_hd44780_put_char( ControllerNumber , Str[ i++ ] );
	}


	void pg_lcd_hd44780_write_p_string( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8  *Str ) {
		_pg_Uint8 i = 0;
		pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
		while ( Str[i] )
			pg_lcd_hd44780_put_char( ControllerNumber , Str[i++] );
	}


	void pg_lcd_hd44780_write_p_string_rom( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Str ) {
		_pg_Uint8 i = 0;
		pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
		while ( Str[ i ] )
			pg_lcd_hd44780_put_char( ControllerNumber , Str[ i++ ] );
	}


	void	pg_lcd_hd44780_write_p_int( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *format , _pg_int16 val ) {
		_pg_int8 str[ PG_LCD_HD44780_COLUMNS ];
		pg_lcd_hd44780_goto( ControllerNumber ,Ln , Pos );
		sprintf( str , format , val );
		pg_lcd_hd44780_write_string( ControllerNumber , str );
	}


	void	pg_lcd_hd44780_write_p_float( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *format , float flt ) {
		_pg_int8 str[ PG_LCD_HD44780_COLUMNS ];
		pg_lcd_hd44780_goto( ControllerNumber ,Ln , Pos );
		sprintf( str , format , flt );
		pg_lcd_hd44780_write_string( ControllerNumber , str );
	}


	void	pg_lcd_hd44780_write_p_char( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *format , _pg_int8 chr ) {
		_pg_int8 str[ PG_LCD_HD44780_COLUMNS ];
		pg_lcd_hd44780_goto( ControllerNumber , Ln , Pos );
		sprintf( str , format , chr );
		pg_lcd_hd44780_write_string( ControllerNumber , str );
	}


	void	pg_lcd_hd44780_write( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * format , ... ) {
		char    message[2 * PG_LCD_HD44780_COLUMNS];
		va_list	VAList;
		va_start( VAList , format );
		vsprintf( message , format , VAList );
		va_end( VAList );
		pg_lcd_hd44780_write_p_string( ControllerNumber , Ln , Pos , message );
	}
#endif

