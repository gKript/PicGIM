//
// pgim_error.c
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

/*!		\file			pgim_error.c
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


#if ( PGIM_ERROR == PG_ENABLE )

	#warning	PG_HS_PG PG_HS_MSG This file is compiling

	_pg_Uint32_VAL	pg_error_state;

	char *	pg_error_severity_str( _pg_Uint8 severity ) {
		switch( severity ) {
			case PG_ERROR_WARNING : {
				return "Warning";
				break;
			}
			case PG_ERROR_CRITICAL : {
				return "Critical";
				break;
			}
			case PG_ERROR_ERROR : {
				return "Error";
				break;
			}
			case PG_ERROR_FATAL : {
				return "Fatal";
				break;
			}
		}
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


	const char *	pg_error_code_to_module( _pg_Uint8 module ) {
		static const char res[16];
		switch( module ) {
			case PG_ERROR_SPI : {
				strcpypgm2ram( res , "SPI" );
				break;
			}
			case PG_ERROR_ADC : {
				strcpypgm2ram( res , "ADC" );
				break;
			}
			case PG_ERROR_TIMER : {
				strcpypgm2ram( res , "TIMER" );
				break;
			}
			case PG_ERROR_SENSOR : {
				strcpypgm2ram( res , "SENSOR" );
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



