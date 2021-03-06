/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_serial.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_serial.h

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
		\file		pgim_serial.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		Calculates the parameters needed to obtain the baud rate defined by the user, or automatically searches for the highest.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/



#include "picgim.h"

#if ( PGIM_SERIAL == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	_pg_Uint8	pg_serial_bitconf_cycle_index;			//cycle index 
	_pg_Uint8	pg_serial_baudrate_cycle_index;			//baudrate index
	_pg_Uint8	pg_serial_baudrate_debug_index;			//baudrate debug index
	
	_pg_Uint32	pg_serial_baudrate_value_wanted;		//9600
	_pg_Uint32	pg_serial_baudrate_value_calculated;	//9615
	_pg_float	pg_serial_baudrate_error;				//0.16 [%]
	_pg_Uint16	pg_serial_baudrate_reg;					//[SPBRGH:SPBRG]
	_pg_Uint16	pg_serial_baudrate_reg_size;			//8bit => 0xFF; 16 bit => 0xFFFF;
	_pg_float	pg_serial_baudrate_reg_calculated;		//
	_pg_Uint8	pg_serial_baudrate_divisor;				// 4, 16 o 64; vedi tabella pag.205 4620
	_pg_Uint8 	pg_serial_baudrate_index;				//from ( 0 -> 115200 ) to ( 7 -> 300 );
	_pg_Uint8 	pg_serial_baudrate_speed;				//for OpenUSART: 64 for BRGH = 0; 16 for BRGH = 0;
	
	_pg_Uint8 pg_serial_string_baudrate[16];
	_pg_Uint8 pg_serial_string_error[100];				//to re-define
	
	//extern	rom const _pg_Uint8 font_5x8[];
	
	//---[ Serial Init ]---
	_pg_int8 pg_serial_init( void ) {
		//--------------------------------------------------
		//	Configure tris USART.
		//	Set in INPUT TX and RX: the EUSART control will automatically reconfigure the pin from input to output as needed.
			PG_SERIAL_TX_TRIS = 1;
			PG_SERIAL_RX_TRIS = 1;
		
		//--------------------------------------------------
		//	MANUAL MODE
		#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_MANUAL )
			pg_serial_baudrate_speed = PGIM_SERIAL_BAUDRATE_SPEED;
			pg_serial_baudrate_reg = PGIM_SERIAL_BAUDRATE_REGISTER;
			
		//--------------------------------------------------
		//	SEMI-AUTOMATIC and AUTOMATIC MODE
		#else
			//--------------------------------------------------
			// Configure debug tris PIN	
			#if ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE )
				PGIM_SERIAL_DEBUG_PIN_TRIS = PG_OUT;
				PGIM_SERIAL_DEBUG_PIN = 0;
				pg_delay( 1 , PG_SEC );
			#endif
			
			//--------------------------------------------------
			// Configure debug tris pin Buzzer
			#if ( PGIM_SERIAL_DEBUG_TO_BUZZER == PG_ENABLE )
				PG_BUZZER_PIN_TRIS = PG_OUT;
				PG_BUZZER_PIN = 0;
			#endif
			
			//--------------------------------------------------
			TXSTAbits.SYNC = 0;									//Only asynchronous mode used
			
			//--------------------------------------------------
			//	Looking for the configuration with percentage error (%) lower then user's specification
			for ( pg_serial_baudrate_cycle_index = 0; pg_serial_baudrate_cycle_index < PG_SERIAL_BAUDRATE_VALUE_QUANTITY; pg_serial_baudrate_cycle_index++ ) {
			
				for ( pg_serial_bitconf_cycle_index = 0; pg_serial_bitconf_cycle_index < 4; pg_serial_bitconf_cycle_index++ ) {
					switch ( pg_serial_bitconf_cycle_index ) {
						case 0: {
							BAUDCONbits.BRG16 = 0;				//8bit; /64; Fosc/[64(reg+1)];
							TXSTAbits.BRGH = 0;
							pg_serial_baudrate_reg_size = 0xFF;
							pg_serial_baudrate_divisor = 64;
							break;
						}
						case 1: {
							BAUDCONbits.BRG16 = 0;				//8bit; /16; Fosc/[16(reg+1)];
							TXSTAbits.BRGH = 1;
							pg_serial_baudrate_reg_size = 0xFF;
							pg_serial_baudrate_divisor = 16;
							break;
						}
						case 2: {
							BAUDCONbits.BRG16 = 1;				//16bit; /16; Fosc/[16(reg+1)];
							TXSTAbits.BRGH = 0;
							pg_serial_baudrate_reg_size = 0xFFFF;
							pg_serial_baudrate_divisor = 16;
							break;
						}
						case 3: {
							BAUDCONbits.BRG16 = 1;				//16bit; /4; Fosc/[4(reg+1)];
							TXSTAbits.BRGH = 1;
							pg_serial_baudrate_reg_size = 0xFFFF;
							pg_serial_baudrate_divisor = 4;
							break;
						}
					}
					
					#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_SEMI_AUTOMATIC )
						pg_serial_baudrate_value_wanted = PGIM_SERIAL_BAUDRATE;
					#endif
					
					#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_AUTOMATIC )
						pg_serial_baudrate_value_wanted = pg_serial_baudrate_converter( pg_serial_baudrate_cycle_index );
					#endif
					
					pg_serial_baudrate_reg_calculated = ( ( ( ( PG_CLOCK * 1000000 ) / (_pg_float)pg_serial_baudrate_value_wanted ) / pg_serial_baudrate_divisor ) - 1 );
					
					//	Make sure it is contained in the register
					if ( ( pg_serial_baudrate_reg_calculated > 1 ) && ( pg_serial_baudrate_reg_calculated <= pg_serial_baudrate_reg_size ) ) {
					
						//pg_serial_baudrate_value_calculated = (_pg_Uint32)( ( PG_CLOCK  * 1000000 ) / ( pg_serial_baudrate_divisor * ( pg_serial_baudrate_reg + 1 ) ) );
						pg_serial_baudrate_value_calculated = (_pg_Uint32)( ( PG_CLOCK  * 1000000 ) / ( pg_serial_baudrate_divisor * ( (_pg_Uint32)( pg_serial_baudrate_reg_calculated ) + 1 )  ) );
						pg_serial_baudrate_error = ( ( ( (_pg_float)pg_serial_baudrate_value_calculated - (_pg_float)pg_serial_baudrate_value_wanted ) / (_pg_float)pg_serial_baudrate_value_wanted ) * 100 );
						
						if ( pg_serial_baudrate_error < PGIM_SERIAL_BAUDRATE_ACCURACY ) {
							pg_serial_baudrate_reg = (_pg_Uint16)pg_serial_baudrate_reg_calculated;		//<=== TARGET
							
							pg_serial_debug_ok();
							return PG_OK;
						}
					}
				}
				
				pg_serial_bitconf_cycle_index = 0;
				
				#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_SEMI_AUTOMATIC )	//se e' manuale il for 0-7 deve fare un giro solo perche' il br e' prefissato dall'utente
					pg_serial_debug_fail();
					return PG_SERIAL_ERROR_BAUDRATE_NOT_FOUND;
					//break;										//pg_serial_baudrate_cycle_index = 7; il breack mantiene l'informazione d'uscita perche' non modifica il valore del contatore
				#endif	
			}
			#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_AUTOMATIC )
				pg_serial_debug_fail();
				return PG_SERIAL_ERROR_BAUDRATE_NOT_FOUND;
			#endif
		#endif
        return ( 1 );       //kmod da valutare se applicare a tutti!!!
	}
	//---[ END Init ]---

	
	//---[ Debug Ok ]---
	void pg_serial_debug_ok( void ) {
		//--------------------------------------------------
		//	Debug output to PIN
		#if ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			
			//------------------------------------------------
			//	Debug output to PIN ( Automatic mode )	( OK )
			#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_AUTOMATIC )

				for ( pg_serial_baudrate_debug_index = 0; pg_serial_baudrate_debug_index < ( pg_serial_baudrate_cycle_index + 1 ); pg_serial_baudrate_debug_index++ ) {
					PGIM_SERIAL_DEBUG_PIN = 1;			// OK - AUTOMATIC: The number of flashes indicates the baud rate found ( see table ).
					pg_delay( 500 , PG_MSEC );
					PGIM_SERIAL_DEBUG_PIN = 0;
					pg_delay( 500 , PG_MSEC );
				}
				pg_delay( 1 , PG_SEC );
			#endif
			
			//----------------------------------------------------
			//	Debug output to PIN ( Semi-Automatic mode )	( OK )
			#if ( PGIM_SERIAL_BAUDRATE_MODE == PG_SEMI_AUTOMATIC )

				PGIM_SERIAL_DEBUG_PIN = 1;			// OK - MANUAL: A long flash.
				pg_delay( 3 , PG_SEC );
				PGIM_SERIAL_DEBUG_PIN = 0;
				pg_delay( 1 , PG_SEC );
			#endif
		#endif
		
		//------------------------------------------------
		//	Debug output to BUZZER					( OK )
		#if ( PGIM_SERIAL_DEBUG_TO_BUZZER == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );		// OK - AUTOMATIC and MANUAL: A long beep.
		#endif
		
		//------------------------------------------------
		//	Debug output to LCD-PCD8544				( OK )
		#if ( PGIM_SERIAL_DEBUG_TO_LCD_PCD8544 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			pg_lcd_pcd8544_init( );															//SE NON LA RIFACCIO QUA VENGONO AREE NERE
			pg_lcd_pcd8544_font_select( font_5x8 );
			pg_lcd_pcd8544_backlight( PG_ON );
			pg_lcd_pcd8544_set_pos( 0 , 0 );
			pg_lcd_pcd8544_send_string_rom( ">   PicGIM   <" );
			pg_lcd_pcd8544_set_pos( 0 , 2 );
			pg_lcd_pcd8544_send_string_rom( "USART AutoConf" );
			pg_lcd_pcd8544_set_pos( 0 , 3 );
			pg_lcd_pcd8544_send_string_rom( "Baud :" );
			pg_lcd_pcd8544_set_pos( 40 , 3 );
			pg_lcd_pcd8544_send_string( ltoa( pg_serial_baudrate_value_wanted, pg_serial_string_baudrate ) );
			pg_lcd_pcd8544_set_pos( 0 , 4 );
			pg_lcd_pcd8544_send_string_rom( "Err% :" );
			pg_lcd_pcd8544_set_pos( 40 , 4 );
			sprintf( pg_serial_string_error, "%2.3f", pg_serial_baudrate_error );							//NON STAMPA
			//sprintf( pg_serial_string_error, "%2.3f", pg_serial_baudrate_error );
			pg_lcd_pcd8544_send_string( pg_serial_string_error );
			//pg_lcd_pcd8544_send_string( ltoa( pg_serial_baudrate_error, pg_serial_string_error ) );
			//pg_delay( PGIM_SERIAL_DEBUG_LCD_DELAY , PG_SEC );
			//pg_beep( PG_BEEP_LOW , PG_BEEP_SHORT );
		#endif
		
		//--------------------------------------------------
		//	Debug output to LCD-HD44780				( OK )
		#if ( PGIM_SERIAL_DEBUG_TO_LCD_HD44780 == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			pg_lcd_hd44780_write_p_int( 0 , 0 , 0 , "Baudrate: %d" , pg_serial_baudrate_value_wanted );
		#endif
	}
	//---[ END Debug Ok]---
	
	
	//---[ Debug Fail]---
	void pg_serial_debug_fail( void ) {
		//--------------------------------------------------
		//	Debug output to PIN						( Fail )
		#if ( PGIM_SERIAL_DEBUG_TO_PIN == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			PGIM_SERIAL_DEBUG_PIN = 0;
			pg_delay( 1 , PG_SEC );
			for ( pg_serial_baudrate_debug_index = 0; pg_serial_baudrate_debug_index < 24; pg_serial_baudrate_debug_index++ ) {
				PGIM_SERIAL_DEBUG_PIN = 1;					//FAIL - AUTOMATIC and MANUAL: Many rapid flashes.
				pg_delay( 200 , PG_MSEC );
				PGIM_SERIAL_DEBUG_PIN = 0;
				pg_delay( 200 , PG_MSEC );
			}
		#endif
		
		//--------------------------------------------------
		//	Debug output to BUZZER					( Fail )
		#if ( PGIM_SERIAL_DEBUG_TO_BUZZER == PG_ENABLE ) && ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			pg_beep( PG_BEEP_LOW , PG_BEEP_LONG );			//FAIL - AUTOMATIC and MANUAL: Three short beep.
			pg_delay( 250 , PG_MSEC );
			pg_beep( PG_BEEP_LOW , PG_BEEP_LONG );
			pg_delay( 250 , PG_MSEC );
			pg_beep( PG_BEEP_LOW , PG_BEEP_LONG );				
			//    pg_beep( PG_BEEP_LOW , PG_BEEP_SHORT );
			//    pg_beep( PG_BEEP_MID , PG_BEEP_SHORT );
			//    pg_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
		#endif
	}
	//---[ END Debug Fail]---

	
	//---[ Open ]---
	void pg_serial_open( void ) {
	//--------------------------------------------------
		#if ( PGIM_SERIAL_BAUDRATE_MODE != PG_MANUAL )
			if ( TXSTAbits.BRGH == 0 )
				pg_serial_baudrate_speed = USART_BRGH_LOW;		//64
			else
				pg_serial_baudrate_speed = USART_BRGH_HIGH;		//16
		#endif
		
		OpenUSART ( USART_ASYNCH_MODE			&
					USART_EIGHT_BIT				&
					PGIM_SERIAL_RX_MODE			&
					pg_serial_baudrate_speed,
					pg_serial_baudrate_reg );		//spbrg e' un "unsigned int", quindi scriviamo direttamente il reg che e' _pg_Uint16
		/*
		void OpenUSART( unsigned char config, unsigned int spbrg);
		USART Mode: 		USART_ASYNCH_MODE  	Asynchronous Mode
		Transmission Width:	USART_EIGHT_BIT      8-bit transmit/receive
		Reception mode:     USART_SINGLE_RX      Single reception
							USART_CONT_RX        Continuous reception
		Baud rate:          USART_BRGH_HIGH      High baud rate
							USART_BRGH_LOW       Low baud rate

		spbrg		Asynchronous mode, high speed:	Fosc / (16 * (spbrg + 1))
					Asynchronous mode, low speed:	Fosc / (64 * (spbrg + 1))
					Synchronous mode:				Fosc / (4 * (spbrg + 1))

		OpenUSART ( USART_ASYNCH_MODE &
					USART_EIGHT_BIT   &
					USART_CONT_RX     &
					USART_BRGH_HIGH,
					25                );
		*/
	}
	//---[ END Open ]---
	
	
	//---[ Close ]---
	void pg_serial_close( void ) {
	//--------------------------------------------------
		CloseUSART();
	}
	//---[ END Close ]---
	
	
	//---[ Baud-Rate Converter ]---
	_pg_Uint32	pg_serial_baudrate_converter( _pg_Uint8 pg_serial_baudrate_index ) {
	//--------------------------------------------------
		/*-----------------------		
		Baud-Rate	Index	Size
		-------------------------		Note: For debug pin, pulse in out are "Index + 1"
		115200		  0		3byte
		57600		  1		  "
		38400		  2		  "	
		19200		  3		  "
		9600		  4		  "
		4800		  5		  "
		2400		  6		  "
		1200	 	  7	 	  "
		300			  8		2byte
		-----------------------*/
		switch ( pg_serial_baudrate_index ) {
			case 0:
			{
				return( PG_SERIAL_BAUDRATE_115200 );
			}
			case 1:
			{
				return( PG_SERIAL_BAUDRATE_57600 );
			}
			case 2:
			{
				return( PG_SERIAL_BAUDRATE_38400 );
			}
			case 3:
			{
				return( PG_SERIAL_BAUDRATE_19200 );
			}
			case 4:
			{
				return( PG_SERIAL_BAUDRATE_9600 );
			}
			case 5:
			{
				return( PG_SERIAL_BAUDRATE_4800 );
			}
			case 6:
			{
				return( PG_SERIAL_BAUDRATE_2400 );
			}
			case 7:
			{
				return( PG_SERIAL_BAUDRATE_1200 );
			}
			case 8:
			{
				return( PG_SERIAL_BAUDRATE_300 );
			}
			default: {
			//	return( <WRONG PG_SERIAL_BAUDRATE_VALUE_QUANTITY> );
			//	break;
			}
		}
	}
	//---[ END Baud-Rate Converter ]---	

#endif

		//--------------------------------------------------
		//PG_SERIAL_BAUDRATE_SPEED_LOW  64	---> Set BRGH = 0
		//PG_SERIAL_BAUDRATE_SPEED_HIGH 16	---> Set BRGH = 1
		//pg_serial_baudrate_calc = ( PG_CLOCK / ( pg_serial_baudrate_divisor * ( pg_serial_baudrate_reg + 1 ) ) );
		//pg_serial_baudrate_max_high_speed = ( PG_CLOCK / ( PG_SERIAL_BAUDRATE_SPEED_HIGH ) ); 	//pg_serial_baudrate_reg = [SPBRGH:SPBRG] = 0
		//pg_serial_baudrate_max_low_speed = ( PG_CLOCK / ( PG_SERIAL_BAUDRATE_SPEED_LOW ) ); 	//pg_serial_baudrate_reg = [SPBRGH:SPBRG] = 0
		//--------------------------------------------------
		//PG_SERIAL_BAUDRATE_SPEED_LOW  64	---> Set BRGH = 0
		//PG_SERIAL_BAUDRATE_SPEED_HIGH 16	---> Set BRGH = 1
		//pg_serial_baudrate_calc = ( PG_CLOCK / ( pg_serial_baudrate_divisor * ( pg_serial_baudrate_reg + 1 ) ) );
		//pg_serial_baudrate_min_high_speed = ( PG_CLOCK / PG_SERIAL_BAUDRATE_SPEED_HIGH / 65536 ); //pg_serial_baudrate_reg = [SPBRGH:SPBRG] = 65535 ( +1 = 65536 )
		//pg_serial_baudrate_min_low_speed = ( PG_CLOCK / PG_SERIAL_BAUDRATE_SPEED_LOW / 65536 ); //pg_serial_baudrate_reg = [SPBRGH:SPBRG] = 65535 ( +1 = 65536 )
		//--------------------------------------------------
		//Those are for 24F, but can help
		//MAX baud rate (BRGH=0) possible is FCY/64 (for [SPBRGH:SPBRG]=0)
		//MIN baud rate (BRGH=0) possible is FCY/(64 * 65536)
		//--------------------------------------------------
		//MAX baud rate (BRGH=1) possible is FCY/16 (for [SPBRGH:SPBRG]=0)
		//MIN baud rate (BRGH=1) possible is FCY/(16 * 65536)		
		//--------------------------------------------------

	
/*		//Asynchronous mode
		//--------------------------------------------------
		BRG16:
			1 = 16-bit Baud Rate Generator : SPBRGH and SPBRG			pg_serial_baudrate_reg -> _pg_Uint16
			0 = 8-bit  Baud Rate Generator : SPBRG only					pg_serial_baudrate_reg -> _pg_Uint8
		//--------------------------------------------------
		BRGH:
			1 = High speed		Fosc / ( 16 * (spbrg + 1 ) )			pg_serial_baudrate_divisor = 16;
			0 = Low speed		Fosc / ( 64 * (spbrg + 1 ) )			pg_serial_baudrate_divisor = 64;
		//--------------------------------------------------
		Desired Baud Rate = FOSC / ( 64 * ( [SPBRGH:SPBRG] + 1 ) )
		
		SPBRGH:SPBRG = ( ( FOSC / Desired Baud Rate ) / 64 ) - 1
					 = ( ( 16000000 / 9600 ) / 64 ) - 1
					 = [ 25.042 ] = 25
					 
		Calculated Baud Rate = 16000000 / ( 64 ( 25 + 1 ) ) = 9615
	 
		Error	= ( Calculated Baud Rate - Desired Baud Rate ) / Desired Baud Rate
				= ( 9615 - 9600 ) / 9600 = 0.16%
		//--------------------------------------------------
		//Look for max baudrate with lower % error
		//There are 4 cases
		BRGH = 0; BRG16 = 0;
		BRGH = 0; BRG16 = 1;
		BRGH = 1; BRG16 = 0;
		BRGH = 1; BRG16 = 1;
*/	


	//---[ Baud-Rate Reg Calculator ]---
/*	_pg_float pg_serial_baudrate_reg_calculator( _pg_Uint32 pg_serial_baudrate_value_wanted, _pg_Uint8 pg_serial_baudrate_divisor ) {
		//--------------------------------------------------
		//pg_serial_baudrate_reg = ( ( ( PG_CLOCK / pg_serial_baudrate_wanted ) / pg_serial_baudrate_divisor ) - 1 );
		return ( ( ( PG_CLOCK / pg_serial_baudrate_value_wanted ) / pg_serial_baudrate_divisor ) - 1 );
	}
	//---[ END Baud-Rate Calculator ]---
*/	
	
	//---[ Baud-Rate Value Calculator ]---
/*	_pg_Uint32 pg_serial_baudrate_value_calculator( _pg_Uint32 pg_serial_baudrate_reg, _pg_Uint8 pg_serial_baudrate_divisor ) {
		//--------------------------------------------------
		//pg_serial_baudrate_calc = ( PG_CLOCK / ( pg_serial_baudrate_divisor * ( pg_serial_baudrate_reg + 1 ) ) );
		return (_pg_Uint32)( PG_CLOCK / ( pg_serial_baudrate_divisor * ( pg_serial_baudrate_reg + 1 ) ) );
	}
	//---[ END Baud-Rate Value Calculator ]---
*/

	//---[ Baud-Rate Error Calculator ]---
/*	_pg_float pg_serial_baudrate_error_calculator( _pg_Uint32 pg_serial_baudrate_value_calculated, _pg_Uint32 pg_serial_baudrate_value_wanted ) {
		//--------------------------------------------------
		//
		return ( ( (_pg_float)pg_serial_baudrate_value_calculated - (_pg_float)pg_serial_baudrate_value_wanted ) / (_pg_float)pg_serial_baudrate_value_wanted );
	}
	//---[ END Baud-Rate Error Calculator ]---
*/

	