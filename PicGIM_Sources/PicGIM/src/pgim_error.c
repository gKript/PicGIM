/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_error.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_error.h

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
		\file		pgim_error.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To know which error we have done.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


#include "picgim.h"


#if ( PGIM_ERROR == PG_ENABLE )

	#warning	PicGIM >>> Message >>> This file is compiling

	_pg_Uint32_VAL	pg_error_state;

	const char *	pg_error_severity_str( _pg_Uint8 severity ) {   //kmod added const
		switch( severity ) {
			case PG_ERROR_WARNING : {
				return "Warning";
			}
			case PG_ERROR_CRITICAL : {
				return "Critical";
			}
			case PG_ERROR_ERROR : {
				return "Error";
			}
			case PG_ERROR_FATAL : {
				return "Fatal";
			}
		}
        return "Undefined";     //kmod added
	}


	void		pg_error_set( _pg_Uint8 module , _pg_Uint8 code , _pg_Uint8 severity ) {
            PG_ERROR_CODE       = code;
            PG_ERROR_MODULE     = module;
            PG_ERROR_SEVERITY   = severity;
            #if ( ( PG_ERROR_LED_PRESENT == PG_YES ) || ( ( PGIM_LCD_HD44780 == PG_ENABLE ) && ( PG_ERROR_LCD_PRESENT == PG_HD44780 ) ) )
                if ( PG_ERROR_SEVERITY == PG_ERROR_FATAL )
					pg_error_led();
            #endif
        }


	char *	pg_error_code_to_module( _pg_Uint8 module ) {
		char res[16];
		switch( module ) {
			case PG_ERROR_SPI : {
				strcpy( res , "SPI" );
				break;
			}
			case PG_ERROR_ADC : {
				strcpy( res , "ADC" );
				break;
			}
			case PG_ERROR_TIMER : {
				strcpy( res , "TIMER" );
				break;
			}
			case PG_ERROR_PWM : {
				strcpy( res , "PWM" );
				break;
			}
			case PG_ERROR_FTOA : {
				strcpy( res , "FTOA" );
				break;
			}
			case PG_ERROR_SENSOR : {
				strcpy( res , "SENSOR" );
				break;
			}
			case PG_ERROR_RTC_DS1302 : {
				strcpy( res , "RTC_DS1302" );
				break;
			}
		}
		return res;
	}

	#if ( PG_ERROR_LED_PRESENT == PG_YES )

		void	pg_error_led_sequence ( void ) {
			PG_ERROR_LED = PG_OFF;
			pg_delay_sec( 1 );
			PG_ERROR_LED = PG_ON;
			pg_delay_msec( 50 );
			PG_ERROR_LED = PG_OFF;
			pg_delay_msec( 100 );
			PG_ERROR_LED = PG_ON;
			pg_delay_msec( 50 );
			PG_ERROR_LED = PG_OFF;
			pg_delay_msec( 100 );
			PG_ERROR_LED = PG_ON;
			pg_delay_msec( 50 );
			PG_ERROR_LED = PG_OFF;
			pg_delay_msec( 100 );
			PG_ERROR_LED = PG_ON;
			pg_delay_msec( 50 );
			PG_ERROR_LED = PG_OFF;
			pg_delay_msec( 100 );
			PG_ERROR_LED = PG_ON;
			pg_delay_msec( 200 );
			PG_ERROR_LED = PG_OFF;
			pg_delay_msec( 200 );
		}


		void	pg_error_led ( void ) {
			_pg_Uint8 GIE_state , PIE_state , TRIS_state;
			TRIS_state = PG_ERROR_LED_TRIS;
			PG_ERROR_LED_TRIS = PG_OUT;
			#if	( PGIM_EVENTS == PG_ENABLE )
				GIE_state = PG_INTERRUPT_GLOBAL_ENABLE;
				PIE_state = PG_INTERRUPT_PERIPHERAL_ENABLE;
				pg_event_set( PG_EVENT_ANY , PG_DISABLE );
			#endif
			switch ( PG_ERROR_SEVERITY ) {
				case PG_ERROR_CRITICAL : {
					pg_error_led_sequence();
					break;
				}
				case PG_ERROR_ERROR : {
					pg_error_led_sequence();
					pg_error_led_sequence();
					pg_error_led_sequence();
					break;
				}
				case PG_ERROR_FATAL : {
					#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) && ( PG_ERROR_LCD_PRESENT == PG_HD44780 ) )	/* HD44780 LCD */
						pg_lcd_hd44780_clear( PG_CONTROLLER_0 );
						pg_lcd_hd44780_write( PG_CONTROLLER_0 , 0 , 0 , "Error on %s" , pg_error_code_to_module( PG_ERROR_MODULE ) );
						pg_lcd_hd44780_write( PG_CONTROLLER_0 , 1 , 0 , "Code : %d" , (unsigned int)PG_ERROR_CODE );
					#endif
					PG_INFINITE_LOOP {
						pg_error_led_sequence();
					}
					break;
				}
			}
			PG_ERROR_LED_TRIS = TRIS_state;
			#if ( PGIM_EVENTS == PG_ENABLE )
				if ( GIE_state )
					pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );
				if ( PIE_state )
					pg_event_set( PG_EVENT_PERIPHERAL , PG_ENABLE );
			#endif
		}
	#endif
#endif


