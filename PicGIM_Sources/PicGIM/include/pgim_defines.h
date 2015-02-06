//
// pgim_defines.h
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

/*!		\file			pgim_defines.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_DEFINES_H_
	#define _PGIM_DEFINES_H_

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      P I C G I M
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	PG_LOOP( a )					while( a )		/*!	A conditional Loop */
	#define	PG_INFINITE_LOOP				while( 1 )		/*!	A forever loop	*/
	#define	PG_HALT							while( 1 )		/*!	A forever loop	*/
	#define pg_loop							while( 1 )		/*!	A forever loop	*/

	#define	PG_FOREVER						1				/*!	An argument for \ref PG_LOOP()	*/
	
	#define	PG_OK							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOK							0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_DONE							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOT_DONE						0				/*!	An alternative way to say "logic value 0"	*/
	
	#define	PG_YES							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NO							0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_ON							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_OFF							0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_IN							1				/*!	To program a PIN in INPUT	*/
	#define	PG_OUT							0				/*!	To program a PIN in OUTPUT	*/

	#define	PG_8BIT_IN						0xFF			/*!	To program an entire PORT in INPUT	*/
	#define	PG_8BIT_OUT						0x00			/*!	To program an entire PORT in OUTPUT	*/

	#define	PG_LOW							0				/*!	An alternative way to say "logic value 0"	*/
	#define	PG_HIGH							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_TRISTATE						2				/*!	Tristate when available	*/
	
	#define	PG_SET							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_CLEAR						0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_START						1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_STOP							0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_ENABLE						1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_DISABLE						0				/*!	An alternative way to say "logic value 0"	*/

//	#define PG_ENABLE_1_S					2				/*!	To program the TIMER to do just only one count 	*/
//	#define PG_ENABLE_LOOP					3				/*!	To program the TIMER to do a continuos counting	*/

	#define	PG_INCLUDE						1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOT_INCLUDE					0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_MASTER						1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_SLAVE						2				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_BUSY							1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_READY						0				/*!	An alternative way to say "logic value 0"	*/

	#define PG_TRUE							1				/*!	An alternative way to say "logic value 1"	*/
	#define PG_FALSE						0				/*!	An alternative way to say "logic value 0"	*/

	#define PG_READ							1				/*!	An alternative way to say "logic value 1"	*/
	#define PG_WRITE						0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_SEC							1				/*!	A time unit : Second	*/
	#define	PG_MSEC							2				/*!	A time unit : Millisecond	*/
	#define	PG_USEC							3				/*!	A time unit : Microsecond	*/

	#define	PG_HZ							4				/*!	A frequency unit : Hertz	*/
	#define	PG_KHZ							5				/*!	A frequency unit : Kilohertz	*/
	#define	PG_MHZ							6				/*!	A frequency unit : Megahertz	*/

	#define PG_RELEASE						0				/*!	The state of a project : Debug	*/
	#define PG_DEBUG						1				/*!	The state of a project : release	*/
	
	#define PG_NONE							0				/*!	An alternative way to say "logic value 0"	*/
	#define PG_STANDARD						1				/*!	A module state : Standard	*/
	#define PG_ENHANCED						2				/*!	A module state : Enhanced	*/
	
	#define PG_MANUAL						0				/*!	A Serial module mode : Manual	*/
	#define PG_SEMI_AUTOMATIC				1				/*!	A Serial module mode : SemiAutomatic	*/
	#define PG_AUTOMATIC					2				/*!	A Serial module mode : Automatic	*/

	#define	PG_DEBUG_LCD_CHAR				1				/*! To use the LCD CHAR as debug output */
//	#define PG_DEBUG_LCD_PCD8544			2
	
	#define PG_COMMAND						0				/*! The byte is a Command */
	#define PG_DATA							1				/*! The byte is a Data */
	
	#define PG_MISSING						-1				/*!	An error state : Missing */
	
	#define PG_CONTROLLER_0					0				/*!	This is the controller 0 */
	#define PG_CONTROLLER_1					1				/*!	This is the controller 1 */
	#define PG_CONTROLLER_2					2				/*!	This is the controller 2 */
	#define PG_CONTROLLER_3					3				/*!	This is the controller 3 */
	
	#define	PG_LINE_0						0				/*!	This is the line 0 */
	#define	PG_LINE_1						1				/*!	This is the line 1 */
	#define	PG_LINE_2						2				/*!	This is the line 2 */
	#define	PG_LINE_3						3				/*!	This is the line 3 */

	#define	PG_HD44780						1				/*!	The name of the controller HD44780 */
	
	#define	PG_SENSOR_METHOD_BETA			1				/*!	Beta calculation method for ntc sensors */
	#define	PG_SENSOR_METHOD_COEF			2				/*!	Coefficients calculation method for ntc sensors */
	
	#define	PG_DEGREES_CELSIUS				1				/*! Indicates the use of Celsius scale */		//(generic define, not dedicated to the sensor module)
	#define	PG_DEGREES_FAHRENHEIT			2				/*! Indicates the use of Fahrenheit scale */	//(generic define, not dedicated to the sensor module)
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      B O A R D   D E F I N E S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	PG_BOARD_USER_DEFINED	0				/*!	PicGIM will run on a user define board */
	#define	PG_BOARD_A				1				/*!	PicGIM will run on a BOARD A */
	#define	PG_BOARD_EXPERIENCE		2				/*!	PicGIM will run on a BOARD EXPERIENCE */

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      H E A D E R   M E S S A G E S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//		HM = HEADER-MODULE;	HS = HEADER-SYSTEM; HB = HEADER-BOARD; HF = HEADER-FUNCTION;
	
	#define PG_HS_PG			PicGIM:
	
	#define PG_HS_CORE			Core >
	#define PG_HS_MSG			Message >
	#define PG_HS_NOTE			Note >
	#define PG_HS_SUGG			~~~
	#define PG_HS_ERR			!!! ERROR !!! :
	#define PG_HS_CONTINUE		continue >
	
	#define PG_HM_LCD_HD44780	LCD HD44780 module >
	#define PG_HM_LCD_PCD8544	LCD PCD8544 module >	
	#define PG_HM_LCD_9340		LCD 9340 module >
	#define PG_HM_IRQ			IRQ module >
	#define PG_HM_EXT_MEM		EXTERNAL MEMORY module >
	#define PG_HM_DELAY			DELAY module >
	#define PG_HM_SERVO			SERVO module >
	#define PG_HM_ERROR			ERROR module >
	#define PG_HM_FONT			FONT module >
	#define PG_HM_ADC			ADC module >
	#define PG_HM_SPI			SPI module >
	#define PG_HM_SERIAL		SERIAL module >
	#define PG_HM_EE			EE module >
	#define PG_HM_TIMER			TIMER module >
	#define PG_HM_TIMER0		TIMER 0 module >
	#define PG_HM_TIMER1		TIMER 1 module >
	#define PG_HM_SPI			SPI module >
	#define PG_HM_PWM			PWM module >				
	#define PG_HM_PWM1			PWM 1 module >	
	#define PG_HM_PWM2			PWM 2 module >		
	#define PG_HM_BUZZER		BUZZER module >	
	#define PG_HM_ENCODER		ENCODER module >	
	#define PG_HM_UNIV_CONST	UNIVERSAL CONSTANTS >
	#define PG_HM_SENSOR		SENSOR module >
	
	#define PG_HF_FTOA			FtoA function >
	
	#define PG_HB_A				Board A >
	#define PG_HB_EXPERIENCE	Experience Board >


	#include <math.h>

	////////////////////////////////////////////////////////////////////////////////
	//
	//		M A T H E M A T I C A L   C O N S T A N T S
	//
	////////////////////////////////////////////////////////////////////////////////

	#define	PG_CONSTANTS_PI							3.1415926535897						//!< Pi-Greek
	#define	PG_CONSTANTS_EULER						2.7182818284590						//!< Euler's number. Base of the natural logarithm


	////////////////////////////////////////////////////////////////////////////////
	//
	//		P H Y S I C A L   C O N S T A N T S
	//
	////////////////////////////////////////////////////////////////////////////////

	#define	PG_CONSTANTS_LIGHT_VELOCITY				299792458							//!< Speed of light. Unit of measure: [m/s]
	#define	PG_CONSTANTS_BOLTZMANN					( 1.3806488E-23 )					//!< Boltzmann's constant. Unit of measure: [J/K]
	#define	PG_CONSTANTS_PLANK_JS					( 6.62606957E-34 )					//!< Planck's constant. Unit of measure: [J*s]
	#define	PG_CONSTANTS_PLANK_EV					( 4.13562852E-15 )					//!< Planck's constant. Unit of measure: [eV*s]
	#define	PG_CONSTANTS_ELEMENTARY_CHARGE			( 1.602176565E-19 ) 				//!< Elementary charge. Unit of measure: [C]
	#define	PG_CONSTANTS_GRAVITY_ACCELERATION		9.80665								//!< Gravitational acceleration. Unit of measure: [m/(s^2)]
	#define	PG_CONSTANTS_KELVIN_CONST				273.15								//!< Absolute value of the absolute zero temperature (0�K) in degrees Celsius

	////////////////////////////////////////////////////////////////////////////////
	//
	//		C H E M I S T R Y   C O N S T A N T S
	//
	////////////////////////////////////////////////////////////////////////////////

	#define	PG_CONSTANTS_AVOGADRO					( 6.02214129E+23 )					//!< Avogadro's number



	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      P I N   M A C R O   -   A r d u i n o   l i k e
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	// PORT (P_) to read, LAT (L_) to write, TRIS (T_) to set the mode.

//	#define	pinMode( a , b )		T_ ## a = PG_ ## b
//	#define	pinSet( a )				L_ ## a = PG_SET
//	#define	pinClear( a )			L_ ## a = PG_CLEAR
//	#define	digitalWrite( a , b )	L_ ## a = b
//	#define	digitalRead( a )		P_ ## a
//	#define	pinToggle( a )			L_ ## a ^= 1

	/*!
	 * \brief			This macro is useful to set a specific bit as INPUT or OUTPUT.
	 * \param	pin		The pin to set [ E.g. T_B1 ]
	 * \param	mode	The logical expression that gives the value to be set.
	 * \return			Nothing.
	 */
	#define	pg_pin_mode( pin , mode )			pin = mode

	/*!
	 * \brief	This macro is useful to set a specific bit to logic level ONE.
	 * \param	pin		The pin to set [ E.g. L_B1 ]
	 * \return			Nothing.
	 */
	#define	pg_pin_set( pin )					pin = PG_SET

	/*!
	 * \brief	This macro is useful to set a specific bit to logic level ZERO.
	 * \param	pin		The pin to set [ E.g. L_B1 ]
	 * \return			Nothing.
	 */
	#define	pg_pin_clear( pin )					pin = PG_CLEAR

	/*!
	 * \brief	This macro is useful to set a specific bit to a specific value.
	 * \param	pin		The pin to set [ E.g. L_B1 ]
	 * \param	value	The logical expression that gives the value to be set.
	 * \return			Nothing.
	 */
	#define	pg_pin_write( pin , value )		pin = value

	/*!
	 * \brief	This macro is useful to read the logical level of a specific bit.
	 * \param	pin		The pin to set [ E.g. L_B1 ]
	 * \return			The value of the requested pin.
	 */
	#define	pg_pin_read( pin )				pin

	/*!
	 * \brief	With this function you can reverse the logic value present. \n If the value is 1 after the call will be 0, and vice versa.
	 * \param	pin		The pin to toggle [ E.g. L_B1 ]
	 * \return			Nothing.
	 */
	#define	pg_pin_toggle( pin )				( pin ^= 1 )


	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      P O R T S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	P_A1				PORTAbits.RA1
	#define	P_A1				PORTAbits.RA1
	#define	P_A2				PORTAbits.RA2
	#define	P_A3				PORTAbits.RA3
	#define	P_A4				PORTAbits.RA4
	#define	P_A5				PORTAbits.RA5
	#define	P_A6				PORTAbits.RA6
	#define	P_A7				PORTAbits.RA7

	#define	P_B0				PORTBbits.RB0
	#define	P_B1				PORTBbits.RB1
	#define	P_B2				PORTBbits.RB2
	#define	P_B3				PORTBbits.RB3
	#define	P_B4				PORTBbits.RB4
	#define	P_B5				PORTBbits.RB5
	#define	P_B6				PORTBbits.RB6
	#define	P_B7				PORTBbits.RB7

	#define	P_C0				PORTCbits.RC0
	#define	P_C1				PORTCbits.RC1
	#define	P_C2				PORTCbits.RC2
	#define	P_C3				PORTCbits.RC3
	#define	P_C4				PORTCbits.RC4
	#define	P_C5				PORTCbits.RC5
	#define	P_C6				PORTCbits.RC6
	#define	P_C7				PORTCbits.RC7

	#define	P_D0				PORTDbits.RD0
	#define	P_D1				PORTDbits.RD1
	#define	P_D2				PORTDbits.RD2
	#define	P_D3				PORTDbits.RD3
	#define	P_D4				PORTDbits.RD4
	#define	P_D5				PORTDbits.RD5
	#define	P_D6				PORTDbits.RD6
	#define	P_D7				PORTDbits.RD7

	#define	P_E0				PORTEbits.RE0
	#define	P_E1				PORTEbits.RE1
	#define	P_E2				PORTEbits.RE2
	#define	P_E3				PORTEbits.RE3
	#define	P_E4				PORTEbits.RE4
	#define	P_E5				PORTEbits.RE5
	#define	P_E6				PORTEbits.RE6
	#define	P_E7				PORTEbits.RE7

	#define	P_F0				PORTFbits.RF0
	#define	P_F1				PORTFbits.RF1
	#define	P_F2				PORTFbits.RF2
	#define	P_F3				PORTFbits.RF3
	#define	P_F4				PORTFbits.RF4
	#define	P_F5				PORTFbits.RF5
	#define	P_F6				PORTFbits.RF6
	#define	P_F7				PORTFbits.RF7

	#define	P_G0				PORTGbits.RG0
	#define	P_G1				PORTGbits.RG1
	#define	P_G2				PORTGbits.RG2
	#define	P_G3				PORTGbits.RG3
	#define	P_G4				PORTGbits.RG4
	#define	P_G5				PORTGbits.RG5
	#define	P_G6				PORTGbits.RG6
	#define	P_G7				PORTGbits.RG7

	#define	P_H0				PORTHbits.RH0
	#define	P_H1				PORTHbits.RH1
	#define	P_H2				PORTHbits.RH2
	#define	P_H3				PORTHbits.RH3
	#define	P_H4				PORTHbits.RH4
	#define	P_H5				PORTHbits.RH5
	#define	P_H6				PORTHbits.RH6
	#define	P_H7				PORTHbits.RH7



	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      L A T
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	L_A1				LATAbits.LATA1	
	#define	L_A1				LATAbits.LATA1	
	#define	L_A2				LATAbits.LATA2	
	#define	L_A3				LATAbits.LATA3
	#define	L_A4				LATAbits.LATA4	
	#define	L_A5				LATAbits.LATA5	
	#define	L_A6				LATAbits.LATA6	
	#define	L_A7				LATAbits.LATA7	

	#define	L_B0				LATBbits.LATB0	
	#define	L_B1				LATBbits.LATB1	
	#define	L_B2				LATBbits.LATB2	
	#define	L_B3				LATBbits.LATB3
	#define	L_B4				LATBbits.LATB4	
	#define	L_B5				LATBbits.LATB5	
	#define	L_B6				LATBbits.LATB6	
	#define	L_B7				LATBbits.LATB7	

	#define	L_C0				LATCbits.LATC0	
	#define	L_C1				LATCbits.LATC1	
	#define	L_C2				LATCbits.LATC2	
	#define	L_C3				LATCbits.LATC3
	#define	L_C4				LATCbits.LATC4	
	#define	L_C5				LATCbits.LATC5	
	#define	L_C6				LATCbits.LATC6	
	#define	L_C7				LATCbits.LATC7	

	#define	L_D0				LATDbits.LATD0	
	#define	L_D1				LATDbits.LATD1	
	#define	L_D2				LATDbits.LATD2	
	#define	L_D3				LATDbits.LATD3
	#define	L_D4				LATDbits.LATD4	
	#define	L_D5				LATDbits.LATD5	
	#define	L_D6				LATDbits.LATD6	
	#define	L_D7				LATDbits.LATD7	

	#define	L_E0				LATEbits.LATE0	
	#define	L_E1				LATEbits.LATE1	
	#define	L_E2				LATEbits.LATE2	
	#define	L_E3				LATEbits.LATE3
	#define	L_E4				LATEbits.LATE4	
	#define	L_E5				LATEbits.LATE5	
	#define	L_E6				LATEbits.LATE6	
	#define	L_E7				LATEbits.LATE7	

	#define	L_F0				LATFbits.LATF0	
	#define	L_F1				LATFbits.LATF1	
	#define	L_F2				LATFbits.LATF2	
	#define	L_F3				LATFbits.LATF3
	#define	L_F4				LATFbits.LATF4	
	#define	L_F5				LATFbits.LATF5	
	#define	L_F6				LATFbits.LATF6	
	#define	L_F7				LATFbits.LATF7	

	#define	L_G0				LATGbits.LATG0	
	#define	L_G1				LATGbits.LATG1	
	#define	L_G2				LATGbits.LATG2	
	#define	L_G3				LATGbits.LATG3
	#define	L_G4				LATGbits.LATG4	
	#define	L_G5				LATGbits.LATG5	
	#define	L_G6				LATGbits.LATG6	
	#define	L_G7				LATGbits.LATG7	

	#define	L_H0				LATHbits.LATH0	
	#define	L_H1				LATHbits.LATH1	
	#define	L_H2				LATHbits.LATH2	
	#define	L_H3				LATHbits.LATH3
	#define	L_H4				LATHbits.LATH4	
	#define	L_H5				LATHbits.LATH5	
	#define	L_H6				LATHbits.LATH6	
	#define	L_H7				LATHbits.LATH7	



	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      T R I S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	T_A1				TRISAbits.TRISA1	
	#define	T_A1				TRISAbits.TRISA1	
	#define	T_A2				TRISAbits.TRISA2	
	#define	T_A3				TRISAbits.TRISA3
	#define	T_A4				TRISAbits.TRISA4	
	#define	T_A5				TRISAbits.TRISA5	
	#define	T_A6				TRISAbits.TRISA6	
	#define	T_A7				TRISAbits.TRISA7	

	#define	T_B0				TRISBbits.TRISB0	
	#define	T_B1				TRISBbits.TRISB1	
	#define	T_B2				TRISBbits.TRISB2	
	#define	T_B3				TRISBbits.TRISB3
	#define	T_B4				TRISBbits.TRISB4	
	#define	T_B5				TRISBbits.TRISB5	
	#define	T_B6				TRISBbits.TRISB6	
	#define	T_B7				TRISBbits.TRISB7	

	#define	T_C0				TRISCbits.TRISC0	
	#define	T_C1				TRISCbits.TRISC1	
	#define	T_C2				TRISCbits.TRISC2	
	#define	T_C3				TRISCbits.TRISC3
	#define	T_C4				TRISCbits.TRISC4	
	#define	T_C5				TRISCbits.TRISC5	
	#define	T_C6				TRISCbits.TRISC6	
	#define	T_C7				TRISCbits.TRISC7	

	#define	T_D0				TRISDbits.TRISD0	
	#define	T_D1				TRISDbits.TRISD1	
	#define	T_D2				TRISDbits.TRISD2	
	#define	T_D3				TRISDbits.TRISD3
	#define	T_D4				TRISDbits.TRISD4	
	#define	T_D5				TRISDbits.TRISD5	
	#define	T_D6				TRISDbits.TRISD6	
	#define	T_D7				TRISDbits.TRISD7	

	#define	T_E0				TRISEbits.TRISE0	
	#define	T_E1				TRISEbits.TRISE1	
	#define	T_E2				TRISEbits.TRISE2	
	#define	T_E3				TRISEbits.TRISE3
	#define	T_E4				TRISEbits.TRISE4	
	#define	T_E5				TRISEbits.TRISE5	
	#define	T_E6				TRISEbits.TRISE6	
	#define	T_E7				TRISEbits.TRISE7	

	#define	T_F0				TRISFbits.TRISF0	
	#define	T_F1				TRISFbits.TRISF1	
	#define	T_F2				TRISFbits.TRISF2	
	#define	T_F3				TRISFbits.TRISF3
	#define	T_F4				TRISFbits.TRISF4	
	#define	T_F5				TRISFbits.TRISF5	
	#define	T_F6				TRISFbits.TRISF6	
	#define	T_F7				TRISFbits.TRISF7	

	#define	T_G0				TRISGbits.TRISG0	
	#define	T_G1				TRISGbits.TRISG1	
	#define	T_G2				TRISGbits.TRISG2	
	#define	T_G3				TRISGbits.TRISG3
	#define	T_G4				TRISGbits.TRISG4	
	#define	T_G5				TRISGbits.TRISG5	
	#define	T_G6				TRISGbits.TRISG6	
	#define	T_G7				TRISGbits.TRISG7	

	#define	T_H0				TRISHbits.TRISH0	
	#define	T_H1				TRISHbits.TRISH1	
	#define	T_H2				TRISHbits.TRISH2	
	#define	T_H3				TRISHbits.TRISH3
	#define	T_H4				TRISHbits.TRISH4	
	#define	T_H5				TRISHbits.TRISH5	
	#define	T_H6				TRISHbits.TRISH6	
	#define	T_H7				TRISHbits.TRISH7

#endif /* _PGIM_DEFINES_H_ */

/*!
	\page	PG_consideraproj		Planning a new project with PicGIM
		\tableofcontents
	
		\n
		\image html planning.png
		\n 
			
		To plan a new project with PicGIM you need to consider in detail what modules will need to enable. \n
		And with even more attention to which microcontroller to use. \n
		Keep in mind that PicGIM, in the next milestone will be even more careful in the use of the Program Memory and RAM and even more configurable. \n

		\htmlonly <br><br> \endhtmlonly

	\section	planmicrouseht		How to use this data

 		\htmlonly <hr> \endhtmlonly
		\endcode

		In this page there are a large amount of data that we consider useful. \n
		The less experienced may find it difficult to interpret them in the correct way. \n
		What we would like is to give some advice for the correct reading. \n \n
		Configurations vary on three basic parameters : \n
		<i>
		&nbsp;&nbsp;&nbsp;&nbsp;The type of Set Instruction chosen. \n
		&nbsp;&nbsp;&nbsp;&nbsp;The type of optimization used. \n
		&nbsp;&nbsp;&nbsp;&nbsp;Enabling or not the Error module for debugging. \n \n
		</i>
		Regarding the Set Instruction is necessary to keep in mind that NOT all microcontrollers support them. \n \n
		For the collection of all these data are heading choices three levels of optimization. \n
		<i>
		&nbsp;&nbsp;&nbsp;&nbsp;The first level is NOT optimized. \n
		&nbsp;&nbsp;&nbsp;&nbsp;The second level is the maximum that allows the C18 in the free version. In this version the C18 NOT allow Procedural Abstraction. \n
		&nbsp;&nbsp;&nbsp;&nbsp;The third level is the commercial version of the C18 which includes the Procedural Abstraction. \n \n
		</i>
		During the development of a project the debugging is very important. \n
		PicGIM provides the Error module to have, immediately run time, the feedback if the parameters passed to the other modules are correct or not. \n
		If you choose a microcontroller with a narrow program memory may NOT be able to enable it. \n \n
		To do the calculations PicGIM has been virtually separated into two elements. \n
		Its structure and each individual module. \n \n
 		So, to get an accurate measure of the resources taken up by PicGIM you need to collect the data of the MODULES that interest and summing them. \n
		To the sum of MODULES will add the space taken up by the STRUCTURE of PicGIM always in the same configuration chosen previously. \n

  		\htmlonly <br> \endhtmlonly

	\section	planmicrochoose		Choose the proper Microcontroller

 		\htmlonly <hr> \endhtmlonly
		\endcode
		
		Here is a table that summarizes chromatically the attention to be placed in the choice of the microcontroller to use in a PicGIM project. \n

		\endcode

		\n

		\image	html	tabella-mcu-colori.png
 	
		\n

		\attention		In this table are ONLY microcontrollers currently supported by PicGIM. \n The microcontrollers supported are constantly increasing, and in case of a specific request, please write to info@gkript.org.

		<p>
			As you can see the 18F2320 is colored orange which means critical. \n
			This does NOT mean that there are no applications that PicGIM can do on this MCU. \n
			Simply will need a good project planning for configuring PicGIM always keeping in mind the amount of Program Memory required for main algorithm. \n
 			In the next section are shown, in detail, the amount of Program Memory and Static RAM necessary for the inclusion of each module.
		</p> 

		\attention	The next milestone (1.0) PicGIM can work generically with all MCU 18F. \n
					The module EasyFuse today is compulsory but from next milestone it can be disabled as the others.

  		\htmlonly <br> \endhtmlonly

	\section	planmicrodetails		Program Memory and Static RAM in detail

		\htmlonly <hr> \endhtmlonly
		\endcode

		The calculations were performed in conditions of "FROZEN CODE". \n
		The calculation methods were as follows : \n \n

		\warning	If is used MplabX you must keep in mind that is not supported directly the Extended Instruction Set modality in compilation. \n It will be necessary to set this mode manually by following the guide HERE. 

		\n
 
		\htmlonly

				<table class="cl_table" width="50%" border="0" >
					<thead>
						<tr align="center">
							<th width="30%">Instruction set</th>
							<th width="40%">Optimization</th>
							<th width="30%">Error module</th>
						</tr>
					</thead>
					<tbody>
						<tr align="center"> <td>Traditional</td><td>NO optimization [-O]</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Traditional</td><td>STD optimization [-Opa]</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Traditional</td><td>FULL optimization</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>NO optimization [-O]</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>STD optimization [-Opa]</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>FULL optimization</td><td>DISABLE</td> </tr>
						<tr align="center"> <td>Traditional</td><td>NO optimization [-O]</td><td>ENABLE</td> </tr>
						<tr align="center"> <td>Traditional</td><td>STD optimization [-Opa]</td><td>ENABLE</td> </tr>
						<tr align="center"> <td>Traditional</td><td>FULL optimization</td><td>ENABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>NO optimization [-O]</td><td>ENABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>STD optimization [-Opa]</td><td>ENABLE</td> </tr>
						<tr align="center"> <td>Extended</td><td>FULL optimization</td><td>ENABLE</td> </tr>
					</tbody>
				</table>
			\endhtmlonly
 	\htmlonly <br><br> \endhtmlonly

		\subsection		planmicrodetailscore	The PicGIM core structure

			\htmlonly <hr> \endhtmlonly
			\endcode

			The amount of resources required by the internal structure of PicGIM is calculated by disabling all its features. \n \n

			\subsubsection	planmicrodetailscoretable		Table
			\endcode

			\image	html	picgim-structure-table.png

			\n 

			\subsubsection	planmicrodetailscorechart		Chart
			\endcode

			\image	html	no-module.png

			\n\n

		\subsection		planmicrodetaildelay		The Delay module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The DELAY module has no dependencies, but has only an additional feature that is compiled only if the EVENTS module is enabled and occupies approximately 15 bytes of Program Memory and 0 bytes of Static RAM. \n \n

			\subsubsection	planmicrodetailsdelaytable		Table
			\endcode

			\image	html	delay-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n
			\subsubsection	planmicrodetailsdelaychart		Chart
			\endcode

			\image	html	delay-module.png

			\n\n

		\subsection		planmicrodetailevent		The Events module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The EVENTS module has no dependencies. \n
			The event module is composed by the structure for its proper operation and the contribution of each individual event. \n
 			The table will then be divided into two sections: the structure and a single event. \n \n

			\subsubsection	planmicrodetailseventtable		Table
			\endcode

			\image	html	events-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			\subsubsection	planmicrodetailseventchart		Charts
			\endcode

			\image	html	event-module.png

			\n

			Chart for each Event: \n

			\image	html	each-event.png

			\n\n

		\subsection		planmicrodetaillcdhd		The LCD HD44780 module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The LCD module HD44780 has as a dependency the DELAY module. \n
			The LCD HD44780 module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n

			\note	The table below shows on a red background the module dependencies.

			\subsubsection	planmicrodetailslcdhd44780table		Table
			\endcode

			\image	html	lcd-hd44780-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			\subsubsection	planmicrodetailslcdhd44780chart		Charts
			\endcode

			\image	html	lcd-hd44780.png

			\n

			Chart for the LCD HD44780 with ERRORS enabled: \n

			\image	html	lcd-hd44780-error.png

			\n\n


		\subsection		planmicrodetailadconv		The AD Converter module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The AD Converter module has no dependencies. \n
			The AD Converter module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n \n

			\subsubsection	planmicrodetailsadctable		Table
			\endcode

			\image	html	adconv-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			\subsubsection	planmicrodetailsadcchart		Charts
			\endcode

			\image	html	ad-converter.png

			\n

			Chart for the AD Converter with ERRORS enabled: \n

			\image	html	ad-converter-error.png

			\n\n

		\subsection		planmicrodetailspi		The SPI module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The SPI Converter module has no dependencies. \n
			The SPI module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n \n

			\subsubsection	planmicrodetailsspitable		Table
			\endcode

			\image	html	spi-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			\subsubsection	planmicrodetailsspichart		Charts
			\endcode

			\image	html	spi-module.png

			\n

			Chart for the SPI with ERRORS enabled: \n

			\image	html	spi-module-error.png

			\n\n

*/



