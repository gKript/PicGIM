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

	In this example we analyze how to configure PicGIM and how to write the right code using a 0-5 volt analog input
	to control the duty cycle of a PWM output that modulates the brightness of a LED.
	In this example we will use a PIC18F4620 with a 40MHz oscillator.
	As always, the first thing to do is to configure the file "pgim_project_setup_public.h" to customize the project.
	In this example we filled out the necessary fields in this way:

			//	P R O J E C T   D E T A I L S
			#define PG_PROJECT_NAME						ADC_to_PWM				//!< The name of your Project
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
	This example requires the presence of the ADC and PWM module.
	So here are the necessary settings:

			//		S O F T W A R E   G E N E R A L
			#define PGIM_ERROR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_CAL_DELAY						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_FTOA							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   I N T E R N A L
			#define PGIM_EVENTS							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_AD_CONVERTER					PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SPI							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_EE								PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_TIMER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_PWM							PG_ENABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SERIAL							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   E X T E R N A L
			#define PGIM_LCD_HD44780					PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_BUZZER							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_SENSOR							PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

			//		H A R D W A R E   G K R I P T
			#define PGIM_ENCODER						PG_DISABLE				//!< Must be: PG_ENABLE || PG_DISABLE

	Once you enabled the required modules we configure the HARDWARE.
	ADC and PWM are internal devices and are part of the category HARDWARE INTERNAL.
	This means that I do not have to assign any pins to the devices.
	ADC module does not require any setting.
	PWM module needs to be configured, because it has special features
	which change the parameters and operation.
	We will use only the first channel of PWM module.
	These settings are made by editing the file "pgim_pwm_setup_public.h".
	Here are the settings required:

			//		P W M   C H A N N E L S   E N A B L I N G
			#define PGIM_PWM_1							PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
			#define PGIM_PWM_2							PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE

			//		E N H A N C E D   M O D E
			#define PG_PWM_1_ENHANCED					PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE
			#define PG_PWM_2_ENHANCED					PG_DISABLE		//!< Must be: PG_ENABLE || PG_DISABLE

			//		E N H A N C E D   M O D E   C O N F I G U R A T I O N
			#define PG_PWM_1_OUT_CONF					SINGLE_OUT		//!< Must be: SINGLE_OUT || HALF_OUT || FULL_OUT_FWD || FULL_OUT_REV
			#define PG_PWM_1_OUT_MODE					PWM_MODE_1		//!< Must be: PWM_MODE_1 || PWM_MODE_2 || PWM_MODE_3 || PWM_MODE_4

			#define PG_PWM_2_OUT_CONF					SINGLE_OUT		//!< Must be: SINGLE_OUT || HALF_OUT || FULL_OUT_FWD || FULL_OUT_REV
			#define PG_PWM_2_OUT_MODE					PWM_MODE_1		//!< Must be: PWM_MODE_1 || PWM_MODE_2 || PWM_MODE_3 || PWM_MODE_4

			#define PG_PWM_DEAD_TIME					12.000			//!< A value in micro-seconds [us]. Used only in HalfBridge mode!

			#define PG_PWM_AUTO_SHUTDOWN				PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE
			#define PG_PWM_AUTO_SHUTDOWN_MODE			PG_AUTOMATIC	//!< Must be: PG_MANUAL || PG_AUTOMATIC
			#define PG_PWM_AUTO_SHUTDOWN_STATE_AC		PG_TRISTATE		//!< Must be: PG_TRISTATE || PG_HIGH || PG_LOW
			#define PG_PWM_AUTO_SHUTDOWN_STATE_BD		PG_TRISTATE		//!< Must be: PG_TRISTATE || PG_HIGH || PG_LOW


			//		D U T Y - C Y C L E   R E S O L U T I O N   M A X   C A L C U L A T I O N
			#define PGIM_PWM_DC_RESOLUTION_MAX_CALC		PG_ENABLE		//!< Must be: PG_ENABLE || PG_DISABLE

	Now PicGIM is properly configured for the project to be developed.

	These are the warnings that PicGIM returns during compilation.
	If all goes well they will be like these :

			Warning [2105] PicGIM:  Core >  Version "0.5-0"  : Milestone "0.5"  : State "rel"
			Warning [2105] PicGIM:  Message >  ~~~  Check periodically on www.gkript.org if you are using the latest PicGIM released!
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Project: [ ADC_to_PWM   V 0.1  ] by [ gKript Howto  ]  -  Author: [ asyntote  ]
			Warning [2105] -
			Warning [2105] -
			Warning [2105] PicGIM:  Core >  Set 18F4620 as current mcu
			Warning [2105] PicGIM:  Core >  Using EXTERNAL oscillator ( 40.000  [MHz] )
			Warning [2105] PicGIM:  Core >  ~~~  All fuses are set as you want.
			Warning [2105] PicGIM:  Core >  ~~~  TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
			Warning [2105] PicGIM:  Core >  Set MCU POWER SUPPLY to 5.00  [V]
			Warning [2105] PicGIM:  Core >  Make sure that the 5.00  voltage is enough for the clock frequency chosen.
			Warning [2105] PicGIM:  Note >  INTERRUPTS disabled
			Warning [2105] PicGIM:  Note >  ~~~  Keep in mind that PicGim offers a very simple way to use them. See the documentation.
			Warning [2105] PicGIM:  ADC module >  Loaded
			Warning [2105] PicGIM:  PWM 1 module >  Loaded
			Warning [2105] PicGIM:  PWM 1 module >  ~~~  Keep in mind that this module supports the ENHANCED mode
			Warning [2105] PicGIM:  PWM module >  Enabled duty-cycle resolution max calculation [bit]

*/

/*
	RELATED TO THIS EXAMPLE :

	ADC module	: http://howto.gkript.org/picgim/0.5/a00004.html
	PWM module	: http://howto.gkript.org/picgim/0.5/a00052.html
*/


//	Only in the file main.c it is always necessary to include the header file picgim_main.h.
#include "picgim_main.h"

void main( void ) {

	//	It is compulsory to initialize PicGIM with this function.
	pg_initialize();

	//	I enable only one channel (AN0) as analog input.
	pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_1_CHANNEL );
	//	I turn on the ADC module.
	pg_adc_set( PG_ADC_MODULE , PG_ON );
	//	I perform the first analog conversion.
	pg_adc_start( PG_CH_0 );
	
	//	I enable the PWM setting the maximum frequency calculated by PicGIM based on the frequency of the oscillator used in the project.
	pg_pwm_set( 15 , PG_KHZ );
	//	I set the Duty Cycle of PWM passing the percentage of the analog signal converted.
	pg_pwm_dutycycle( PG_PWM_1 , pg_adc_get_perc() );
	//	I starting the PWM device
	pg_pwm_start( PG_PWM_1 );
	
	//	We enter into an infinite loop that will run our program.
	PG_LOOP ( PG_FOREVER ) {
		//	I perform an analog conversion.
		pg_adc_start( PG_CH_0 );
		//	I set the Duty Cycle of PWM passing the percentage of the analog signal converted.
		//  For example with a supply voltage of 5V an analog conversion of 2.5V match to 50%.
		pg_pwm_dutycycle( PG_PWM_1 , pg_adc_get_perc() );
	}
}

//	At this point you can compile the project and verify that the brightness of the LED changes depending on the input voltage.


