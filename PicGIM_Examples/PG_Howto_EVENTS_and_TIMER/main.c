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

	In this example we analyze how to configure PicGIM and how to write the right code using the TIMER interrupt
	to control the blinking of a LED.
	In this example we will use a PIC18F4620 with a 40MHz oscillator.
	As always, the first thing to do is to configure the file "pgim_project_setup_public.h" to customize the project.
	In this example we filled out the necessary fields in this way:

			//	P R O J E C T   D E T A I L S
			#define PG_PROJECT_NAME						EVENTS_and_TIMER		//!< The name of your Project
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
	This example requires the presence of the TIMER and EVENTS module.
	To operate the TIMER module needs the DELAY module.
	If you do not enable the DELAY module you will get a dependency error in compilation.
	So here are the necessary settings:

			//		S O F T W A R E   G E N E R A L
			#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_CAL_DELAY						PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   I N T E R N A L
			#define PGIM_EVENTS							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_AD_CONVERTER					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_TIMER							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_PWM							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SERIAL							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   E X T E R N A L
			#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   G K R I P T
			#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	Once you enabled the required modules we configure the HARDWARE.
	TIMER and EVENTS are internal devices and are part of the category HARDWARE INTERNAL.
	This means that I do not have to assign any pins to the devices.
	
	TIMER and EVENTS module needs to be configured, because thay have special features
	which change the parameters and operation.
	We will use only the TIMER 0 of TIMER module.
	These settings are made by editing the file "pgim_timer_setup_public.h".
	Here are the settings required:

			//		T I M E R   E N A B L I N G
			#define PGIM_TIMER_0					PG_ENABLE		//!< Must be: PG_DISABLE || PG_ENABLE_1_SHOT || PG_ENABLE_LOOP
			#define PGIM_TIMER_1					PG_DISABLE		//!< Must be: PG_DISABLE || PG_ENABLE_1_SHOT || PG_ENABLE_LOOP

			//		P A R A M E T E R S
			#define PG_TIMER_0_DELAY_TRIM			320				//!< Set the correct value of delay in uSec resulting from test
			#define PG_TIMER_1_DELAY_TRIM			299				//!< Set the correct value of delay in uSec resulting from test

	We will get only the interrupt from the TIMER 0.
	These settings are made by editing the file "pgim_event_setup_public.h".
	Here are the settings required:

			//	-------- Auto Interrupts Handler -----------------------------------------------------------
			#define PG_EVENT_AUTO_HANDLER		PG_ENABLE			// PG_ENABLE	PG_DISABLE

			//	-------- External Interrupts ----------------------------------------------------------------
			#define PG_EVENT_SET_INT0			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_INT1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_INT2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_RB0			PG_DISABLE			// PG_ENABLE	PG_DISABLE

			//	-------- Internal Interrupts ----------------------------------------------------------------
			#define PG_EVENT_SET_TMR0			PG_ENABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_TMR1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_TMR2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_AD				PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_USARTRC        PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_USARTTX        PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_SSP			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_CCP1			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_CCP2			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_OSCF			PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_CM				PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_EE				PG_DISABLE			// PG_ENABLE	PG_DISABLE
			#define PG_EVENT_SET_BCL			PG_DISABLE			// PG_ENABLE	PG_DISABLE


	Now PicGIM is properly configured for the project to be developed.

	These are the warnings that PicGIM returns during compilation.
	If all goes well they will be like these :

			Warning [2105] PicGIM:  Core >  Version "0.5-0"  : Milestone "0.5"  : State "rel"
			Warning [2105] PicGIM:  Message >  ~~~  Check periodically on www.gkript.org if you are using the latest PicGIM released!
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Project: [ TIMER_to_EVENTS   V 0.1  ] by [ gKript Howto  ]  -  Author: [ asyntote  ]
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Core >  Set 18F4620 as current mcu
			Warning [2105] PicGIM:  Core >  Using EXTERNAL oscillator ( 20.000  [MHz] )
			Warning [2105] PicGIM:  Core >  ~~~  All fuses are set as you want.
			Warning [2105] PicGIM:  Core >  ~~~  TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
			Warning [2105] PicGIM:  Core >  Set MCU POWER SUPPLY to 5.00  [V]
			Warning [2105] PicGIM:  Core >  Make sure that the 5.00  voltage is enough for the clock frequency chosen.
			Warning [2105] PicGIM:  DELAY module >  Loaded
			Warning [2105] PicGIM:  IRQ module >  INTERRUPTS handle module loaded
			Warning [2105] PicGIM:  Note >  ~~~  See the documentation to know how initialize interrupts you want to manage.
			Warning [2105] PicGIM:  TIMER 0 module >  ~~~  Max time available is 4.000  * 65535.000  * 256  / 20.000  [us]
			Warning [2105] PicGIM:  TIMER 0 module >  Loaded
*/

/*
	RELATED TO THIS EXAMPLE :

	DELAY module	: http://howto.gkript.org/picgim/0.5/a00008.html
	EVENTS module	: http://howto.gkript.org/picgim/0.5/a00042.html
	TIMER module	: http://howto.gkript.org/picgim/0.5/a00060.html
	PINS name		: http://howto.gkript.org/picgim/0.5/a00014.html#langpins
	DEFINES			: http://howto.gkript.org/picgim/0.5/a00014.html#langpinmpcdefine
	MACRO			: http://howto.gkript.org/picgim/0.5/a00014.html#langpinmacro
*/


//	Only in the file main.c it is always necessary to include the header file picgim_main.h.
#include "picgim_main.h"

//	A PIN definition ( LATBbits.LATB3 = L_B3 ) for a LED 
#define MY_LED          L_B3

//	A TRIS definition for the PIN ( TRISBbits.TRISB3 = T_B3 )
#define MY_LED_TRIS     T_B3


//	This is the function that I want to be invoked at each EVENT TIMER.
void    led_blink( void ) {
	
	// This macro takes care to invert the status of a PIN. 
    pg_pin_toggle( MY_LED );        
}

void main( void ) {
	//	It is compulsory to initialize PicGIM with this function.
	pg_initialize();

	//	This macro sets a TRIS as required by the user. It is not compulsory to use these macros.
    pg_pin_mode( MY_LED_TRIS , PG_OUT );

	//	It enables global interruption.
    pg_event_set( PG_EVENT_GLOBAL , PG_ENABLE );

	//	It enables the interrupts from the internal peripherals.
    pg_event_set( PG_EVENT_PERIPHERAL , PG_ENABLE );

	//	It connects the "led_blink" event TIMER 0.
    pg_event_attach( PG_EVENT_TMR0 , led_blink );

	//	Enabling the event from TIMER 0.
    pg_event_set( PG_EVENT_TMR0 , PG_ENABLE );

	//	You set the frequency of the timer 0 to 2 Hz.
	//	Each 2Hz we will get an interrupt.
    pg_timer_set_freq( PG_TIMER_0 , 2 , PG_HZ );

	//	Starting the TIMER 0.
	//	After this line will begin the interrupts.
    pg_timer_start( PG_TIMER_0 );

	//	We enter into an infinite loop.
	PG_HALT;
}

//	At this point you can compile the project and verify that the LED will blink 2 times per second.


