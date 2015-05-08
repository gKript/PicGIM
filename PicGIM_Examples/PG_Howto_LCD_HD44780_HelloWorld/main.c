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
	with the purpose of writing a text on a HD44780 controller 16x2 lcd display, using the busy flag bit.
	The aim is to write "Hello world!" on the first line, starting from the third column.
	We choose to use, for example, a PIC18F4620 with a 20MHz oscillator.
	As always, the first thing to do is to configure the file "pgim_project_setup_public.h" to customize the project.
	In this example we filled out the necessary fields in this way:

			//	P R O J E C T   D E T A I L S
			#define PG_PROJECT_NAME						LCD_HD44780_HelloWorld	//!< The name of your Project
			#define PG_PROJECT_ORGANIZATION				gKript Howto			//!< The name of your Organization
			#define PG_PROJECT_AUTHOR					skymatrix/asyntote		//!< Your name or, if you like, your nickname
			#define PG_PROJECT_VERSION					0.1						//!< The version of your project
			#define PG_PROJECT_STATE					PG_DEBUG				//!< Must be: PG_DEBUG  ||  PG_RELEASE
			#define PG_PROJECT_DATE						07/05/2015				//!< Date of the project

			//	H A R D W A R E   C O N F I G   M A I N   S Y S T E M
			#define PG_CLOCK							20.000					//!< The CORE FREQUENCY of the CPU in your project. Unit of measure is expressed in [MHz]. Accuracy: X.XXX. \note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, you need to consider the value of the \b oscillator/crystal and eventually of the \b PLL.						\attention		4MHz is the minimum clock frequency managed by \b PicGIM. \n If you set a lower frequency 4MHz functions of delay will definitely inaccurate.
			#define PG_USER_SUPPLY_VOLT					5.00					//!< The power supply VOLTAGE of the MCU in your project. Unit of measure is expressed in [V]. Accuracy: X.XX
			#define PG_USER_SUPPLY_BATTERY				PG_NO					//!< Must be: PG_YES  ||  PG_NO
			#define PG_USE_INTERNAL_OSC					PG_DISABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE

			//	P I C G I M   B E H A V I O U R
			#define PG_VERBOSE							PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
			#define PG_SUGGESTION						PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE
			#define PG_PROJECT_INFO_SHOW				PG_ENABLE				//!< Must be: PG_ENABLE  ||  PG_DISABLE

	Before compile PicGIM we still have to set some configuration files.
	The "pgim_module_setup_public.h" file defines which modules are included and compiled.
	This example code requires the presence of the LCD_HD44780 module.
	The LCD module is dependent on the DELAY module, then this one must also be enabled.
	If you do not enable it, PicGIM will return a compilation error.
	
	The DELAY module is software and is part of the SOFTWARE GENERAL category.
	This means that I do not have to assign any pins to the devices.
	The DELAY module not needs to be configured, it is crucial to indicate correctly
	the oscillator frequency, so that it can correctly calculate timings.
	
	Here, there are the necessary settings:

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
			#define PGIM_LCD_HD44780					PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   G K R I P T
			#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	Always in the same "pgim_module_setup_public.h" file, if required,
	we must modify the related software configuration.	
	In a 2x16 lcd display there is only one on-board controller.
	Controllers not used must be declared unused, by PG_MISSING define.
	We need to read busy flag bit, from lcd.
	The first line is at address 0x00.
	We want a spash screen for a time of two seconds.
	Here, there are the necessary settings:
	
			#define	PG_LCD_HD44780_COLUMNS			16						//!< Number of columns of the display
			#define	PG_LCD_HD44780_LINES			2						//!< Number of lines of the display
			#define PG_LCD_HD44780_BUSY_FLAG		PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PG_LCD_HD44780_LINE_0_ADDRESS	0x00					//!< Address (default 0x00) for the line number 1. Must be : PG_MISSING if there is not.
			#define PG_LCD_HD44780_LINE_1_ADDRESS	PG_MISSING				//!< Address (default 0x40) for the line number 2. Must be : PG_MISSING if there is not.
			#define PG_LCD_HD44780_LINE_2_ADDRESS	PG_MISSING				//!< Address (default 0x00) for the line number 3. Must be : PG_MISSING if there is not.
			#define PG_LCD_HD44780_LINE_3_ADDRESS	PG_MISSING				//!< Address (default 0x40) for the line number 4. Must be : PG_MISSING if there is not.
			#define PG_LCD_HD44780_SPLASH_ENABLE	PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PG_LCD_HD44780_SPLASH_TIME		2						//!< Show time of splash in seconds [s] || 0 = do not clear


	Now that the modules are enabled and software side configured, we must configure the HARDWARE.
	LCD_HD44780 is an external devices and is part of the category HARDWARE EXTERNAL;
	this means that Pic pins are to be assigned to display, in order to be able to control its functions.
	These settings are made by editing the dedicated section in the file "pgim_hardware_setup_public.h".
	Our display has a single controller, then only one enable pin.
	It is provided of a led backlight (BL), so a pin is dedicated to drive it.
	We will use it in the configuration with four bits of data.
	We assign the following pin as in the following table:
	
			Lcd RS pin -> Pic LATD, bit 4
			Lcd RW pin -> Pic LATD, bit 5
			Lcd EN pin -> Pic LATD, bit 6
			
			Lcd D0 pin -> Pic LATD, bit 0
			Lcd D1 pin -> Pic LATD, bit 1
			Lcd D2 pin -> Pic LATD, bit 2
			Lcd D3 pin -> Pic LATD, bit 3
			
			Lcd BL pin -> Pic LATD, bit 7
	
	We must also specify, when required, if some pins are being used or not.
	If not, we have to indicate them are missing by PG_MISSING define
	(referring to the relative physical pin define) and by PG_NO (referring
	to the related "_PRESENT" define).
	After the latch bits, in the same way, we assign the right tris bits
	and also the right port bits (because we have to read the busy flag bit ).
	It is of fundamental importance that the number of the port pins
	is the same for all three values!
	Here, there are the required settings:

			#define PG_LCD_HD44780_RS					L_D4				//!< Must be: <pin-lat-name>
			#define PG_LCD_HD44780_RW_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_RW					L_D5				//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_0_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_EN_0					L_D6				//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_1_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_EN_1					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_2_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_EN_2					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_3_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_EN_3					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_0				L_D0				//!< Must be: <pin-lat-name>
			#define PG_LCD_HD44780_DATA_1				L_D1				//!< Must be: <pin-lat-name>
			#define PG_LCD_HD44780_DATA_2				L_D2				//!< Must be: <pin-lat-name>
			#define PG_LCD_HD44780_DATA_3				L_D3				//!< Must be: <pin-lat-name>
			#define PG_LCD_HD44780_BL_PRESENT			PG_YES				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_BL					L_D7				//!< Must be: <pin-lat-name> || PG_MISSING if not used.

			#define PG_LCD_HD44780_RS_TRIS				T_D4				//!< Must be: <pin-tris-name>
			#define PG_LCD_HD44780_RW_TRIS				T_D5				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_0_TRIS			T_D6				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_1_TRIS			PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_2_TRIS			PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_EN_3_TRIS			PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_0_TRIS			T_D0				//!< Must be: <pin-tris-name>
			#define PG_LCD_HD44780_DATA_1_TRIS			T_D1				//!< Must be: <pin-tris-name>
			#define PG_LCD_HD44780_DATA_2_TRIS			T_D2				//!< Must be: <pin-tris-name>
			#define PG_LCD_HD44780_DATA_3_TRIS			T_D3				//!< Must be: <pin-tris-name>
			#define PG_LCD_HD44780_BL_TRIS				T_D7				//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			
			#define PG_LCD_HD44780_DATA_0_PORT			P_D0				//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_1_PORT			P_D1				//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_2_PORT			P_D2				//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_3_PORT			P_D3				//!< Must be: <pin-port-name> || PG_MISSING if not used.

	It is also possible not to use the busy flag. Of course it will lose speed, but we save a pin
	because the RW must remain fixed at low level (the display will only be written and never read).
	Now, here we have the only defines that need to be changed in the configuration just created to not use the busy flag bit:
	
			Lcd RW pin -> not used (permanently connect it to low level)
			#define PG_LCD_HD44780_BUSY_FLAG			PG_DISABLE			//!< Must be: PG_ENABLE || PG_DISABLE
			#define PG_LCD_HD44780_RW_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_RW					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_RW_TRIS				PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_0_PORT			PG_MISSING			//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_1_PORT			PG_MISSING			//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_2_PORT			PG_MISSING			//!< Must be: <pin-port-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_DATA_3_PORT			PG_MISSING			//!< Must be: <pin-port-name> || PG_MISSING if not used.
	
	If the backlight is not present, files must be configured in this way:
	
			#define PG_LCD_HD44780_BL_PRESENT			PG_NO				//!< Must be: PG_YES || PG_NO
			#define PG_LCD_HD44780_BL					PG_MISSING			//!< Must be: <pin-lat-name> || PG_MISSING if not used.
			#define PG_LCD_HD44780_BL_TRIS				PG_MISSING			//!< Must be: <pin-tris-name> || PG_MISSING if not used.

	Now PicGIM is properly configured for the project to be developed.

	These are the warnings that PicGIM returns during compilation.
	If all goes well they will be like these :

			Warning [2105] PicGIM:  Core >  Version "0.5-0"  : Milestone "0.5"  : State "rel" 
			Warning [2105] PicGIM:  Message >  ~~~  Check periodically on www.gkript.org if you are using the latest PicGIM released!
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Project: [ LCD_HD44780_HelloWorld   V 0.1  ] by [ gKript Howto  ]  -  Author: [ skymatrix/asyntote  ]
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Core >  Set 18F4620 as current mcu
			Warning [2105] PicGIM:  Core >  Using EXTERNAL oscillator ( 20.000  [MHz] )
			Warning [2105] PicGIM:  Core >  ~~~  All fuses are set as you want.
			Warning [2105] PicGIM:  Core >  ~~~  TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
			Warning [2105] PicGIM:  Core >  Set MCU POWER SUPPLY to 5.00  [V]
			Warning [2105] PicGIM:  Core >  Make sure that the 5.00  voltage is enough for the clock frequency chosen.
			Warning [2105] PicGIM:  DELAY module >  Loaded
			Warning [2105] PicGIM:  Note >  INTERRUPTS disabled
			Warning [2105] PicGIM:  Note >  ~~~  Keep in mind that PicGim offers a very simple way to use them. See the documentation.
			Warning [2105] PicGIM:  LCD HD44780 module >  Loaded
*/

/*
	RELATED TO THIS EXAMPLE :
	
	HD44780 module :		http://howto.gkript.org/picgim/0.5/a00050.html
	DELAY module :			http://howto.gkript.org/picgim/0.5/a00008.html
	PIN name reference :	http://howto.gkript.org/picgim/0.5/a00014.html#langpins
*/


//	Only in the file main.c it is always necessary to include the header file picgim_main.h.
#include "picgim_main.h"

#define	LCD_CONTROLLER		0		//The controller number. The first and only is '0'.
#define	LCD_LINE			0		//The line number. The first is '0'.
#define	LCD_COLUMN			2		//The column number. In this instance is the third.

void main( void ) {
	//	It is compulsory to initialize PicGIM with this function.
	pg_initialize();
	
	//	Write text string to lcd on controller '0', on the first line from the third column.
	pg_lcd_hd44780_write_p_string_rom( LCD_CONTROLLER , LCD_LINE , LCD_COLUMN , "Hello world!" ); 
	
	//	We enter into an infinite loop.
	PG_HALT;
}

/*	At this point you can compile the project and verify that the display
	power on backlight, shows the slpash screen and then
	correctly print the string on the first line from the third column.
*/


 