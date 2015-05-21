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

	In this example we analyze how to configure PicGIM and how to write the right code
	with the purpose of writing a text to a software terminal running on PC side, through the RS232 serial port.
	Obviously, it must be properly configured with the parameters that we will choose in a little while.
	We will use, for example, a PIC18F4620 with a 40MHz oscillator.
	As always, the first thing to do is to configure the file "pgim_project_setup_public.h" to customize the project.
	In this example we filled out the necessary fields in this way:

			//	P R O J E C T   D E T A I L S
			#define PG_PROJECT_NAME						SERIAL_To_PC			//!< The name of your Project
			#define PG_PROJECT_ORGANIZATION				gKript Howto			//!< The name of your Organization
			#define PG_PROJECT_AUTHOR					skymatrix				//!< Your name or, if you like, your nickname
			#define PG_PROJECT_VERSION					0.1						//!< The version of your project
			#define PG_PROJECT_STATE					PG_DEBUG				//!< Must be: PG_DEBUG  ||  PG_RELEASE
			#define PG_PROJECT_DATE						21/05/2015				//!< Date of the project

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
	This example code requires the presence of the SERIAL module.
	Here, there are the necessary settings:

			//		S O F T W A R E   G E N E R A L
			#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_CAL_DELAY						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   I N T E R N A L
			#define PGIM_EVENTS							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_AD_CONVERTER					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_TIMER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_PWM							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SERIAL							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   E X T E R N A L
			#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   G K R I P T
			#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	Now that the modules are enabled, we must configure the HARDWARE editing "pgim_serial_setup_public.h" file.
	SERIAL module uses the USART internal device, thus, it is part of the category HARDWARE INTERNAL;
	this means that Pic I/O pins are already assigned.
	We will use the semi-automatic configuration, because it is the easiest of those available that allows us
	to choose the speed of transmission.
	We modify only the necessary parameters as the transmission speed of (for example) 2400.
	We will leave unaltered the accuracy at 1.00 value that allows us to obtain a good precision
	and at the same time the security that the calculation algorithm succeeds.
	The continuous reception is fine in our case, so it's already settled.
	
		// 		C O N F I G   M O D E
		#define PGIM_SERIAL_BAUDRATE_MODE				PG_SEMI_AUTOMATIC	//!< Must be: PG_MANUAL || PG_SEMI_AUTOMATIC || PG_AUTOMATIC

		
		//		P A R A M E T E R S
		//( CONFIG ONLY IN MANUAL MODE )
		#define PGIM_SERIAL_BAUDRATE_SPEED				USART_BRGH_LOW		//!< Must be: USART_BRGH_LOW || USART_BRGH_HIGH \n Refer to the datasheet for the micro-controller chosen.
		#define PGIM_SERIAL_BAUDRATE_REGISTER			25					//!< Set the registry value of the baud-rate. \n Refer to the datasheet for the micro-controller chosen.
		
		//( CONFIG ONLY IN SEMI_AUTOMATIC MODE )
		#define PGIM_SERIAL_BAUDRATE					2400				//!< The possible values are: 300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200

		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_BAUDRATE_ACCURACY			1.00				//!< Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration.
		
		
		//		R X   M O D E
		//( CONGIF ALWAYS )
		#define PGIM_SERIAL_RX_MODE						USART_CONT_RX		//!< Must be: USART_SINGLE_RX || USART_CONT_RX		

	Now PicGIM is properly configured for the project to be developed.

	These are the warnings that PicGIM returns during compilation.
	If all goes well they will be like these :

		PicGIM:  Core >  Version "0.5-0"  : Milestone "0.5"  : State "rel" 
		PicGIM:  Message >  ~~~  Check periodically on www.gkript.org if you are using the latest PicGIM released!
		-
		-
		PicGIM:  Project: [ SERIAL_To_PC   V 0.1  ] by [ gKript Howto  ]  -  Author: [ skymatrix  ]
		-
		-
		PicGIM:  Core >  Set 18F4620 as current mcu
		PicGIM:  Core >  Using EXTERNAL oscillator ( 40.000  [MHz] )
		PicGIM:  Core >  ~~~  All fuses are set as you want.
		PicGIM:  Core >  ~~~  TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
		PicGIM:  Core >  Set MCU POWER SUPPLY to 5.00  [V]
		PicGIM:  Core >  Make sure that the 5.00  voltage is enough for the clock frequency chosen.
		PicGIM:  Note >  INTERRUPTS disabled
		PicGIM:  Note >  ~~~  Keep in mind that PicGim offers a very simple way to use them. See the documentation.
		PicGIM:  SERIAL module >  Loaded
		PicGIM:  SERIAL module >  Activated SEMI-AUTOMATIC mode configuration
		PicGIM:  SERIAL module >  Trying to calculate parameter...
*/

/*
	RELATED TO THIS EXAMPLE :
	
	SERIAL module		: http://howto.gkript.org/picgim/0.5/a00056.html
	DEFINES				: http://howto.gkript.org/picgim/0.5/a00014.html#langpinmpcdefine
*/

//	Only in the file main.c it is always necessary to include the header file picgim_main.h.
#include "picgim_main.h"

void main( void ) {
	//	It is compulsory to initialize PicGIM with this function.
	pg_initialize();
	
	//	Open serial port.
	pg_serial_open();
	
	//	We enter into an infinite loop.
	PG_INFINITE_LOOP {
	
		//	Write a string using the usual functions of Microchip library.
		putrsUSART( "Hello world! " );
	}
}

/*	CAUTION: To connect the serial output of the micro-controller to the input
	of the RS-232 port on the PC, you must use a dedicated levels translator
	(for example, MAX232, or MAX3232 if you use a less than 5[V] power supply).

	Now we must open a software terminal in receiving mode on the PC and configure it with the following settings:
	
		Speed [b/s]:    2400
		Data bits:      8
		Parity:         none
		Stop bit:       1
		Flux control:   none

	At this point you can compile the project and verify that the terminal receives correctly the transmitted strings.
*/


 