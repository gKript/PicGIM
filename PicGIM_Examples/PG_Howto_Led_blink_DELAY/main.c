/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		main.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.5-0
	Deprecated version :	This file is not part of PicGIM library but it is only an Howto.

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

/*
	This howto is part of the kit PicGIM 0.5 library.

	In this example we analyze how to configure PicGIM and how to write the right code to blink a LED once per second.
	In this example we will use a PIC18F4620 with a 40MHz oscillator.
	As always, the first thing to do is to configure the file "pgim_project_setup_public.h" to customize the project.
	In this example we filled out the necessary fields in this way:

			//	P R O J E C T   D E T A I L S
			#define PG_PROJECT_NAME						Led_blink_DELAY			//!< The name of your Project
			#define PG_PROJECT_ORGANIZATION				gKript Howto			//!< The name of your Organization
			#define PG_PROJECT_AUTHOR					asyntote				//!< Your name or, if you like, your nickname
			#define PG_PROJECT_VERSION					0.1						//!< The version of your project
			#define PG_PROJECT_STATE					PG_DEBUG				//!< Must be: PG_DEBUG  ||  PG_RELEASE
			#define PG_PROJECT_DATE						04/05/2015				//!< Date of the project

			//	H A R D W A R E   C O N F I G   M A I N   S Y S T E M
			#define PG_CLOCK							40.000					//!< The CORE FREQUENCY of the CPU in your project. Unit of measure is expressed in [MHz]. Accuracy: X.XXX. \note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, you need to consider the value of the \b oscillator/crystal and eventually of the \b PLL.						\attention		4MHz is the minimum clock frequency managed by \b PicGIM. \n If you set a lower frequency 4MHz functions of delay will definitely inaccurate.
			#define PG_USER_SUPPLY_VOLT					5.00					//!< The power supply VOLTAGE of the MCU in your project. Unit of measure is expressed in [V]. Accuracy: X.XX
			#define PG_USER_SUPPLY_BATTERY				PG_NO					//!< Must be: PG_YES  ||  PG_NO
			#define PG_USE_INTERNAL_OSC					PG_DISABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE

			//	P I C G I M   B E H A V I O U R
			#define PG_VERBOSE							PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
			#define PG_SUGGESTION						PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
			#define PG_PROJECT_INFO_SHOW				PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE

	Before compile PicGIM we still have to set some configuration files.
	The "pgim_module_setup_public.h" file defines which modules are included and compiled.
	This example requires the presence only of the DELAY module.
	So here are the necessary settings:

			//		S O F T W A R E   G E N E R A L
			#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_CAL_DELAY						PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   I N T E R N A L
			#define PGIM_EVENTS							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_AD_CONVERTER					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_TIMER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_PWM							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SERIAL							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   E X T E R N A L
			#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   G K R I P T
			#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	Once you enabled the DELAY module we configure the HARDWARE.
	The DELAY module is software and is part of the SOFTWARE GENERAL category.
	This means that I do not have to assign any pins to the devices.
	The DELAY module not needs to be configured. Is crucial to indicate correctly the oscillator frequency.

	Now PicGIM is properly configured for the project to be developed.

	These are the warnings that PicGIM returns during compilation.
	If all goes well they will be like these :

			Warning [2105] PicGIM:  Core >  Version "0.5-0"  : Milestone "0.5"  : State "rel"
			Warning [2105] PicGIM:  Message >  ~~~  Check periodically on www.gkript.org if you are using the latest PicGIM released!
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Project: [ Led_blink_DELAY   V 0.1  ] by [ gKript Howto  ]  -  Author: [ asyntote  ]
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Core >  Set 18F4620 as current mcu
			Warning [2105] PicGIM:  Core >  Using EXTERNAL oscillator ( 40.000  [MHz] )
			Warning [2105] PicGIM:  Core >  ~~~  All fuses are set as you want.
			Warning [2105] PicGIM:  Core >  ~~~  TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
			Warning [2105] PicGIM:  Core >  Set MCU POWER SUPPLY to 5.00  [V]
			Warning [2105] PicGIM:  Core >  Make sure that the 5.00  voltage is enough for the clock frequency chosen.
			Warning [2105] PicGIM:  DELAY module >  Loaded
			Warning [2105] PicGIM:  Note >  INTERRUPTS disabled
			Warning [2105] PicGIM:  Note >  ~~~  Keep in mind that PicGim offers a very simple way to use them. See the documentation.

*/

/*
	RELATED TO THIS EXAMPLE :

	DELAY module	: http://howto.gkript.org/picgim/0.5/a00008.html
	PINS name		: http://howto.gkript.org/picgim/0.5/a00014.html#langpins
	DEFINES			: http://howto.gkript.org/picgim/0.5/a00014.html#langpinmpcdefine
	MACRO			: http://howto.gkript.org/picgim/0.5/a00014.html#langpinmacro
*/


//	Only in the file main.c it is always necessary to include the header file picgim_main.h.
#include "picgim_main.h"

//	A PIN definition ( LATBbits.LATB3 = L_B3 ) for a LED 
#define MY_LED          L_B4

//	A TRIS definition for the PIN ( TRISBbits.TRISB3 = T_B3 )
#define MY_LED_TRIS     T_B4


void main( void ) {
	//	It is compulsory to initialize PicGIM with this function.
	pg_initialize();

	//	This macro sets a TRIS as required by the user. It is not compulsory to use these macros.
    pg_pin_mode( MY_LED_TRIS , PG_OUT );

	//	This MACRO sets the logic state 0 to the PIN indicated by the user.
	pg_pin_clear( MY_LED );

	//	We enter into an infinite loop.
	PG_LOOP( PG_FOREVER ) {

		// This macro takes care to invert the status of a PIN.
		pg_pin_toggle( MY_LED );

		//	The DELAY function to wait 500mS
		pg_delay( 500 , PG_MSEC );
	}
}

//	At this point you can compile the project and verify that the LED will blink 2 times per second.


