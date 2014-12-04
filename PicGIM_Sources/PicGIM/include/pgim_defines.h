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

	#define	PG_LOOP( a )			while( a )		/*!	A Loop with argument	*/
	#define	PG_INFINITE_LOOP		while( 1 )		/*!	A forever loop	*/
	#define	PG_HALT					while( 1 )		/*!	A forever loop	*/

	#define	PG_FOREVER				1				/*!	An argument for \ref PG_LOOP()	*/
	
	#define	PG_OK					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOK					0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_DONE					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOT_DONE				0				/*!	An alternative way to say "logic value 0"	*/
	
	#define	PG_YES					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NO					0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_ON					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_OFF					0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_IN					1				/*!	To program a PIN in INPUT	*/
	#define	PG_OUT					0				/*!	To program a PIN in OUTPUT	*/

	#define	PG_8BIT_IN				0xFF			/*!	To program an entire PORT in INPUT	*/
	#define	PG_8BIT_OUT				0x00			/*!	To program an entire PORT in OUTPUT	*/

	#define	PG_LOW					0				/*!	An alternative way to say "logic value 0"	*/
	#define	PG_HIGH					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_TRISTATE				2				/*!	Tristate when available	*/
	
	#define	PG_SET					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_CLEAR				0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_START				1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_STOP					0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_ENABLE				1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_DISABLE				0				/*!	An alternative way to say "logic value 0"	*/

	#define PG_ENABLE_1_S			2				/*!	To program the TIMER to do just only one count 	*/
	#define PG_ENABLE_LOOP			3				/*!	To program the TIMER to do a continuos counting	*/

	#define	PG_INCLUDE				1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_NOT_INCLUDE			0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_MASTER				1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_SLAVE				2				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_BUSY					1				/*!	An alternative way to say "logic value 1"	*/
	#define	PG_READY				0				/*!	An alternative way to say "logic value 0"	*/

	#define PG_TRUE					1				/*!	An alternative way to say "logic value 1"	*/
	#define PG_FALSE				0				/*!	An alternative way to say "logic value 0"	*/

	#define PG_READ					1				/*!	An alternative way to say "logic value 1"	*/
	#define PG_WRITE				0				/*!	An alternative way to say "logic value 0"	*/

	#define	PG_SEC					1				/*!	A time unit : Second	*/
	#define	PG_MSEC					2				/*!	A time unit : Millisecond	*/
	#define	PG_USEC					3				/*!	A time unit : Microsecond	*/

	#define	PG_HZ					4				/*!	A frequency unit : Hertz	*/
	#define	PG_KHZ					5				/*!	A frequency unit : Kilohertz	*/
	#define	PG_MHZ					6				/*!	A frequency unit : Megahertz	*/

	#define PG_RELEASE				0				/*!	The state of a project : Debug	*/
	#define PG_DEBUG				1				/*!	The state of a project : release	*/
	
	#define PG_NONE					0				/*!	An alternative way to say "logic value 0"	*/
	#define PG_STANDARD				1				/*!	A module state : Standard	*/
	#define PG_ENHANCED				2				/*!	A module state : Enhanced	*/
	
	#define PG_MANUAL				0				/*!	A Serial module mode : Manual	*/
	#define PG_SEMI_AUTOMATIC		1				/*!	A Serial module mode : SemiAutomatic	*/
	#define PG_AUTOMATIC			2				/*!	A Serial module mode : Automatic	*/

	#define	PG_DEBUG_LCD_CHAR		1				/*! To use the LCD CHAR as debug output */
//	#define PG_DEBUG_LCD_PCD8544	2
	
	#define PG_COMMAND				0				/*! The byte is a Command */
	#define PG_DATA					1				/*! The byte is a Data */
	
	#define PG_MISSING				-1				/*!	An error state : Missing */
	
	#define PG_CONTROLLER_0			0				/*!	This is the controller 0 */
	#define PG_CONTROLLER_1			1				/*!	This is the controller 1 */
	#define PG_CONTROLLER_2			2				/*!	This is the controller 2 */
	#define PG_CONTROLLER_3			3				/*!	This is the controller 3 */
	
	#define	PG_LINE_0				0				/*!	This is the line 0 */
	#define	PG_LINE_1				1				/*!	This is the line 1 */
	#define	PG_LINE_2				2				/*!	This is the line 2 */
	#define	PG_LINE_3				3				/*!	This is the line 3 */

	#define	PG_HD44780				1				/*!	The name of the controller HD44780 */

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
	#define	PG_CONSTANTS_BOLTZMANN					( 1.3806488 * pow( 10 , -23 ) )		//!< Boltzmann's constant. Unit of measure: [J/K]
	#define	PG_CONSTANTS_PLANK_JS					( 6.62606957 * pow( 10 , -34 ) )					//!< Planck's constant. Unit of measure: [J*s]
	#define	PG_CONSTANTS_PLANK_EV					( 4.13562852 * pow( 10 , -15 ) )	//!< Planck's constant. Unit of measure: [eV*s]
	#define	PG_CONSTANTS_ELEMENTARY_CHARGE			( 1.602176565 * pow( 10 , -19 ) 	//!< Elementary charge. Unit of measure: [C]
	#define	PG_CONSTANTS_GRAVITY_ACCELERATION		9.80665								//!< Gravitational acceleration. Unit of measure: [m/(s^2)]


	////////////////////////////////////////////////////////////////////////////////
	//
	//		C H E M I S T R Y   C O N S T A N T S
	//
	////////////////////////////////////////////////////////////////////////////////

	#define	PG_CONSTANTS_AVOGADRO					( 6.02214129 * pow( 10 , 23 ) )		//!< Avogadro's number



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

	\section	planmicrochoose		Choose the proper Microcontroller

		\htmlonly <hr> \endhtmlonly
		\endcode
		
		Here is a table that summarizes chromatically the attention to be placed in the choice of the microcontroller. \n

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

 			Here is the table:

			\image	html	picgim-structure-table.png

			\n 

			And here's the chart: \n 

			\image	html	no-module.png

			\n\n

		\subsection		planmicrodetaildelay		The Delay module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The DELAY module has no dependencies, but has only an additional feature that is compiled only if the EVENTS module is enabled and occupies approximately 15 bytes of Program Memory and 0 bytes of Static RAM. \n \n

 			Here is the table:

			\image	html	delay-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			And here's the chart: \n

			\image	html	delay-module.png

			\n\n

		\subsection		planmicrodetailevent		The Events module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The EVENTS module has no dependencies. \n
			The event module is composed by the structure for its proper operation and the contribution of each individual event. \n
 			The table will then be divided into two sections: the structure and a single event. \n \n

 			Here is the table:

			\image	html	events-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			And here's the chart for the EVENTS structure: \n

			\image	html	event-module.png

			\n

			And here's the chart for each Event: \n

			\image	html	each-event.png

			\n\n

		\subsection		planmicrodetaillcdhd		The LCD HD44780 module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The LCD module HD44780 has as a dependency the DELAY module. \n
			The LCD HD44780 module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n

			\note	The table below shows on a red background the module dependencies.
 
 			Here is the table:

			\image	html	lcd-hd44780-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			Here's the chart for the LCD HD44780 with ERRORS disabled: \n

			\image	html	lcd-hd44780.png

			\n

			Here's the chart for the LCD HD44780 with ERRORS enabled: \n

			\image	html	lcd-hd44780-error.png

			\n\n


		\subsection		planmicrodetailadconv		The AD Converter module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The AD Converter module has no dependencies. \n
			The AD Converter module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n \n

 			Here is the table:

			\image	html	adconv-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			Here's the chart for the AD Converter with ERRORS disabled: \n

			\image	html	ad-converter.png

			\n

			Here's the chart for the AD Converter with ERRORS enabled: \n

			\image	html	ad-converter-error.png

			\n\n

		\subsection		planmicrodetailspi		The SPI module

			\htmlonly <hr> \endhtmlonly
			\endcode

			The SPI Converter module has no dependencies. \n
			The SPI module supports the module ERRORS. \n
			The table and graphs show the data in every possible configuration. \n \n

 			Here is the table:

			\image	html	spi-table.png

			\note	The resources needed by each module were calculated compiling PicGIM with only this module enabled, including any dependencies, and subtracting the amount of Program memory and Static RAM of the PicGIM structure.

			\n

			Here's the chart for the SPI with ERRORS disabled: \n

			\image	html	spi-module.png

			\n

			Here's the chart for the SPI with ERRORS enabled: \n

			\image	html	spi-module-error.png

			\n\n

*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!
	\page	PG_language		The language of PicGIM

		\tableofcontents
	
		\n
		\image html Language.png
		\n \n 
			
		\b PicGIM also introduces changes to the classic references of the \b Microchip \b environment. \n
		These changes affect different components such as the \b types \b of \b variables and the \b PIN \b names. \n
		These changes were made with the purpose to simplify the code writing. \n \n

		\note	The types of variables and pin names proposed by PicGIM do not override standards introduced by the C18 compiler.
	
		
		\section	langtype	Variable Type name reference

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
				The variable types have been reorganized to size and signed and unsigned.
				\htmlonly
				<br>
				<table class="cl_table" width="60%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="left" >Real size</th>
							<th width="25%" align="left" >PicGIM type</th>
							<th width="25%" align="left" >STD type</th>
							<th width="40%" align="left" >Description</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td >1 byte</td><td ><b>\endhtmlonly \ref _pg_int8 \htmlonly</b></td><td>char</td><td>Signed integer 8 bit size</td>
						</tr>
						<tr>
							<td >1 byte</td><td ><b>\endhtmlonly \ref _pg_Uint8 \htmlonly</b></td><td>unsigned char</td><td>Unsigned integer 8 bit size</td>
						</tr>
						<tr>
							<td >2 byte</td><td ><b>\endhtmlonly \ref _pg_int16 \htmlonly</b></td><td>int</td><td>Signed integer 16 bit size</td>
						</tr>
						<tr>
							<td >2 byte</td><td ><b>\endhtmlonly \ref _pg_Uint16 \htmlonly</b></td><td>unsigned int</td><td>Unsigned integer 16 bit size</td>
						</tr>
						<tr>
							<td >3 byte</td><td ><b>\endhtmlonly \ref _pg_int24 \htmlonly</b></td><td>short long</td><td>Signed integer 24 bit size</td>
						</tr>
						<tr>
							<td >3 byte</td><td ><b>\endhtmlonly \ref _pg_Uint24 \htmlonly</b></td><td>unsigned short long</td><td>Unsigned integer 24 bit size</td>
						</tr>
						<tr>
							<td >4 byte</td><td ><b>\endhtmlonly \ref _pg_int32 \htmlonly</b></td><td>long</td><td>Signed integer 32 bit size</td>
						</tr>
						<tr>
							<td >4 byte</td><td ><b>\endhtmlonly \ref _pg_Uint32 \htmlonly</b></td><td>unsigned long</td><td>Unsigned integer 32 bit size</td>
						</tr>
					</tbody>
				</table>
				
				<table class="cl_table" width="60%" border="0" >
					<tbody>
						<tr>
							<td width="10%" align="left" >4 byte</td><td width="25%" align="left" ><b>\endhtmlonly \ref _pg_buffer \htmlonly</b></td><td width="25%" align="left" >char *</td><td width="40%" align="left" >A pointer to a signed integer 8 bit size</td>
						</tr>
						<tr>
							<td width="10%" align="left" >4 byte</td><td ><b>\endhtmlonly \ref _pg_Ubuffer \htmlonly</b></td><td>unsigned char *</td><td>A pointer to a unsigned integer 8 bit size</td>
						</tr>
					</tbody>
				</table>
				
				<table class="cl_table" width="60%" border="0" >
					<tbody>
						<tr>
							<td width="10%" align="left" >4 byte</td><td width="25%" align="left" ><b>\endhtmlonly \ref _pg_bool \htmlonly</b></td><td width="25%" align="left" >BOOL</td><td width="40%" align="left" >A boolean flag</td>
						</tr>
					</tbody>
				</table>
				<br> 
				\endhtmlonly
				
				A practical code example.
				\code
					...
					void main( void ) {
						_pg_int8	small_counter , reg_a = 0;
						_pg_Uint32	big_counter;
						_pg_Uint16	values[32];
						_pg_bool	test = false;
					...
				\endcode
			</p>
			\n 

		\section	langpins	Pins name reference

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
				In addition PicGIM reorganizes the names of pins to different contexts ( TRIS, PORT, LAT ). \n
				Here is a reference table for each port. \n \n

			\attention	The amount, the arrangement and the names of available pins is related to the model of microcontroller used.

			\n

 			\subsection	langporta	Port A

				\htmlonly
 				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>A0</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA0</td><td width="15%" align="center" ><b>T_A0</b></td>
							<td width="15%" align="center" >PORTAbits.RA0</td><td width="15%" align="center" ><b>P_A0</b></td>
							<td width="15%" align="center" >LATAbits.LATA0</td><td width="15%" align="center" ><b>L_A0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A1</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA1</td><td width="15%" align="center" ><b>T_A1</b></td>
							<td width="15%" align="center" >PORTAbits.RA1</td><td width="15%" align="center" ><b>P_A1</b></td>
							<td width="15%" align="center" >LATAbits.LATA1</td><td width="15%" align="center" ><b>L_A1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A2</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA2</td><td width="15%" align="center" ><b>T_A2</b></td>
							<td width="15%" align="center" >PORTAbits.RA2</td><td width="15%" align="center" ><b>P_A2</b></td>
							<td width="15%" align="center" >LATAbits.LATA2</td><td width="15%" align="center" ><b>L_A2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A3</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA3</td><td width="15%" align="center" ><b>T_A3</b></td>
							<td width="15%" align="center" >PORTAbits.RA3</td><td width="15%" align="center" ><b>P_A3</b></td>
							<td width="15%" align="center" >LATAbits.LATA3</td><td width="15%" align="center" ><b>L_A3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A4</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA4</td><td width="15%" align="center" ><b>T_A4</b></td>
							<td width="15%" align="center" >PORTAbits.RA4</td><td width="15%" align="center" ><b>P_A4</b></td>
							<td width="15%" align="center" >LATAbits.LATA4</td><td width="15%" align="center" ><b>L_A4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A5</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA5</td><td width="15%" align="center" ><b>T_A5</b></td>
							<td width="15%" align="center" >PORTAbits.RA5</td><td width="15%" align="center" ><b>P_A5</b></td>
							<td width="15%" align="center" >LATAbits.LATA5</td><td width="15%" align="center" ><b>L_A5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A6</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA6</td><td width="15%" align="center" ><b>T_A6</b></td>
							<td width="15%" align="center" >PORTAbits.RA6</td><td width="15%" align="center" ><b>P_A6</b></td>
							<td width="15%" align="center" >LATAbits.LATA6</td><td width="15%" align="center" ><b>L_A6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A7</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA7</td><td width="15%" align="center" ><b>T_A7</b></td>
							<td width="15%" align="center" >PORTAbits.RA7</td><td width="15%" align="center" ><b>P_A7</b></td>
							<td width="15%" align="center" >LATAbits.LATA7</td><td width="15%" align="center" ><b>L_A7</b></td>
						</tr>
					</tbody>
				</table>
				<BR>
				\endhtmlonly


			\subsection langportb	Port B
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>B0</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB0</td><td width="15%" align="center" ><b>T_B0</b></td>
							<td width="15%" align="center" >PORTBbits.RB0</td><td width="15%" align="center" ><b>P_B0</b></td>
							<td width="15%" align="center" >LATBbits.LATB0</td><td width="15%" align="center" ><b>L_B0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B1</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB1</td><td width="15%" align="center" ><b>T_B1</b></td>
							<td width="15%" align="center" >PORTBbits.RB1</td><td width="15%" align="center" ><b>P_B1</b></td>
							<td width="15%" align="center" >LATBbits.LATB1</td><td width="15%" align="center" ><b>L_B1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B2</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB2</td><td width="15%" align="center" ><b>T_B2</b></td>
							<td width="15%" align="center" >PORTBbits.RB2</td><td width="15%" align="center" ><b>P_B2</b></td>
							<td width="15%" align="center" >LATBbits.LATB2</td><td width="15%" align="center" ><b>L_B2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B3</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB3</td><td width="15%" align="center" ><b>T_B3</b></td>
							<td width="15%" align="center" >PORTBbits.RB3</td><td width="15%" align="center" ><b>P_B3</b></td>
							<td width="15%" align="center" >LATBbits.LATB3</td><td width="15%" align="center" ><b>L_B3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B4</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB4</td><td width="15%" align="center" ><b>T_B4</b></td>
							<td width="15%" align="center" >PORTBbits.RB4</td><td width="15%" align="center" ><b>P_B4</b></td>
							<td width="15%" align="center" >LATBbits.LATB4</td><td width="15%" align="center" ><b>L_B4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B5</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB5</td><td width="15%" align="center" ><b>T_B5</b></td>
							<td width="15%" align="center" >PORTBbits.RB5</td><td width="15%" align="center" ><b>P_B5</b></td>
							<td width="15%" align="center" >LATBbits.LATB5</td><td width="15%" align="center" ><b>L_B5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B6</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB6</td><td width="15%" align="center" ><b>T_B6</b></td>
							<td width="15%" align="center" >PORTBbits.RB6</td><td width="15%" align="center" ><b>P_B6</b></td>
							<td width="15%" align="center" >LATBbits.LATB6</td><td width="15%" align="center" ><b>L_B6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>B7</b></td>
							<td width="15%" align="center" >TRISBbits.TRISB7</td><td width="15%" align="center" ><b>T_B7</b></td>
							<td width="15%" align="center" >PORTBbits.RB7</td><td width="15%" align="center" ><b>P_B7</b></td>
							<td width="15%" align="center" >LATBbits.LATB7</td><td width="15%" align="center" ><b>L_B7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly

 			\subsection langportc	Port C
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>C0</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC0</td><td width="15%" align="center" ><b>T_C0</b></td>
							<td width="15%" align="center" >PORTCbits.RC0</td><td width="15%" align="center" ><b>P_C0</b></td>
							<td width="15%" align="center" >LATCbits.LATC0</td><td width="15%" align="center" ><b>L_C0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C1</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC1</td><td width="15%" align="center" ><b>T_C1</b></td>
							<td width="15%" align="center" >PORTCbits.RC1</td><td width="15%" align="center" ><b>P_C1</b></td>
							<td width="15%" align="center" >LATCbits.LATC1</td><td width="15%" align="center" ><b>L_C1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C2</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC2</td><td width="15%" align="center" ><b>T_C2</b></td>
							<td width="15%" align="center" >PORTCbits.RC2</td><td width="15%" align="center" ><b>P_C2</b></td>
							<td width="15%" align="center" >LATCbits.LATC2</td><td width="15%" align="center" ><b>L_C2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C3</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC3</td><td width="15%" align="center" ><b>T_C3</b></td>
							<td width="15%" align="center" >PORTCbits.RC3</td><td width="15%" align="center" ><b>P_C3</b></td>
							<td width="15%" align="center" >LATCbits.LATC3</td><td width="15%" align="center" ><b>L_C3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C4</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC4</td><td width="15%" align="center" ><b>T_C4</b></td>
							<td width="15%" align="center" >PORTCbits.RC4</td><td width="15%" align="center" ><b>P_C4</b></td>
							<td width="15%" align="center" >LATCbits.LATC4</td><td width="15%" align="center" ><b>L_C4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C5</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC5</td><td width="15%" align="center" ><b>T_C5</b></td>
							<td width="15%" align="center" >PORTCbits.RC5</td><td width="15%" align="center" ><b>P_C5</b></td>
							<td width="15%" align="center" >LATCbits.LATC5</td><td width="15%" align="center" ><b>L_C5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C6</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC6</td><td width="15%" align="center" ><b>T_C6</b></td>
							<td width="15%" align="center" >PORTCbits.RC6</td><td width="15%" align="center" ><b>P_C6</b></td>
							<td width="15%" align="center" >LATCbits.LATC6</td><td width="15%" align="center" ><b>L_C6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>C7</b></td>
							<td width="15%" align="center" >TRISCbits.TRISC7</td><td width="15%" align="center" ><b>T_C7</b></td>
							<td width="15%" align="center" >PORTCbits.RC7</td><td width="15%" align="center" ><b>P_C7</b></td>
							<td width="15%" align="center" >LATCbits.LATC7</td><td width="15%" align="center" ><b>L_C7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
			\subsection langportd	Port D
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>D0</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD0</td><td width="15%" align="center" ><b>T_D0</b></td>
							<td width="15%" align="center" >PORTDbits.RD0</td><td width="15%" align="center" ><b>P_D0</b></td>
							<td width="15%" align="center" >LATDbits.LATD0</td><td width="15%" align="center" ><b>L_D0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D1</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD1</td><td width="15%" align="center" ><b>T_D1</b></td>
							<td width="15%" align="center" >PORTDbits.RD1</td><td width="15%" align="center" ><b>P_D1</b></td>
							<td width="15%" align="center" >LATDbits.LATD1</td><td width="15%" align="center" ><b>L_D1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D2</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD2</td><td width="15%" align="center" ><b>T_D2</b></td>
							<td width="15%" align="center" >PORTDbits.RD2</td><td width="15%" align="center" ><b>P_D2</b></td>
							<td width="15%" align="center" >LATDbits.LATD2</td><td width="15%" align="center" ><b>L_D2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D3</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD3</td><td width="15%" align="center" ><b>T_D3</b></td>
							<td width="15%" align="center" >PORTDbits.RD3</td><td width="15%" align="center" ><b>P_D3</b></td>
							<td width="15%" align="center" >LATDbits.LATD3</td><td width="15%" align="center" ><b>L_D3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D4</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD4</td><td width="15%" align="center" ><b>T_D4</b></td>
							<td width="15%" align="center" >PORTDbits.RD4</td><td width="15%" align="center" ><b>P_D4</b></td>
							<td width="15%" align="center" >LATDbits.LATD4</td><td width="15%" align="center" ><b>L_D4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D5</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD5</td><td width="15%" align="center" ><b>T_D5</b></td>
							<td width="15%" align="center" >PORTDbits.RD5</td><td width="15%" align="center" ><b>P_D5</b></td>
							<td width="15%" align="center" >LATDbits.LATD5</td><td width="15%" align="center" ><b>L_D5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D6</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD6</td><td width="15%" align="center" ><b>T_D6</b></td>
							<td width="15%" align="center" >PORTDbits.RD6</td><td width="15%" align="center" ><b>P_D6</b></td>
							<td width="15%" align="center" >LATDbits.LATD6</td><td width="15%" align="center" ><b>L_D6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>D7</b></td>
							<td width="15%" align="center" >TRISDbits.TRISD7</td><td width="15%" align="center" ><b>T_D7</b></td>
							<td width="15%" align="center" >PORTDbits.RD7</td><td width="15%" align="center" ><b>P_D7</b></td>
							<td width="15%" align="center" >LATDbits.LATD7</td><td width="15%" align="center" ><b>L_D7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
			\subsection langporte	Port E
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>E0</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE0</td><td width="15%" align="center" ><b>T_E0</b></td>
							<td width="15%" align="center" >PORTEbits.RE0</td><td width="15%" align="center" ><b>P_E0</b></td>
							<td width="15%" align="center" >LATEbits.LATE0</td><td width="15%" align="center" ><b>L_E0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E1</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE1</td><td width="15%" align="center" ><b>T_E1</b></td>
							<td width="15%" align="center" >PORTEbits.RE1</td><td width="15%" align="center" ><b>P_E1</b></td>
							<td width="15%" align="center" >LATEbits.LATE1</td><td width="15%" align="center" ><b>L_E1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E2</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE2</td><td width="15%" align="center" ><b>T_E2</b></td>
							<td width="15%" align="center" >PORTEbits.RE2</td><td width="15%" align="center" ><b>P_E2</b></td>
							<td width="15%" align="center" >LATEbits.LATE2</td><td width="15%" align="center" ><b>L_E2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E3</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE3</td><td width="15%" align="center" ><b>T_E3</b></td>
							<td width="15%" align="center" >PORTEbits.RE3</td><td width="15%" align="center" ><b>P_E3</b></td>
							<td width="15%" align="center" >LATEbits.LATE3</td><td width="15%" align="center" ><b>L_E3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E4</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE4</td><td width="15%" align="center" ><b>T_E4</b></td>
							<td width="15%" align="center" >PORTEbits.RE4</td><td width="15%" align="center" ><b>P_E4</b></td>
							<td width="15%" align="center" >LATEbits.LATE4</td><td width="15%" align="center" ><b>L_E4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E5</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE5</td><td width="15%" align="center" ><b>T_E5</b></td>
							<td width="15%" align="center" >PORTEbits.RE5</td><td width="15%" align="center" ><b>P_E5</b></td>
							<td width="15%" align="center" >LATEbits.LATE5</td><td width="15%" align="center" ><b>L_E5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E6</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE6</td><td width="15%" align="center" ><b>T_E6</b></td>
							<td width="15%" align="center" >PORTEbits.RE6</td><td width="15%" align="center" ><b>P_E6</b></td>
							<td width="15%" align="center" >LATEbits.LATE6</td><td width="15%" align="center" ><b>L_E6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>E7</b></td>
							<td width="15%" align="center" >TRISEbits.TRISE7</td><td width="15%" align="center" ><b>T_E7</b></td>
							<td width="15%" align="center" >PORTEbits.RE7</td><td width="15%" align="center" ><b>P_E7</b></td>
							<td width="15%" align="center" >LATEbits.LATE7</td><td width="15%" align="center" ><b>L_E7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
			\subsection langportf	Port F
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>F0</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF0</td><td width="15%" align="center" ><b>T_F0</b></td>
							<td width="15%" align="center" >PORTFbits.RF0</td><td width="15%" align="center" ><b>P_F0</b></td>
							<td width="15%" align="center" >LATFbits.LATF0</td><td width="15%" align="center" ><b>L_F0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F1</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF1</td><td width="15%" align="center" ><b>T_F1</b></td>
							<td width="15%" align="center" >PORTFbits.RF1</td><td width="15%" align="center" ><b>P_F1</b></td>
							<td width="15%" align="center" >LATFbits.LATF1</td><td width="15%" align="center" ><b>L_F1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F2</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF2</td><td width="15%" align="center" ><b>T_F2</b></td>
							<td width="15%" align="center" >PORTFbits.RF2</td><td width="15%" align="center" ><b>P_F2</b></td>
							<td width="15%" align="center" >LATFbits.LATF2</td><td width="15%" align="center" ><b>L_F2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F3</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF3</td><td width="15%" align="center" ><b>T_F3</b></td>
							<td width="15%" align="center" >PORTFbits.RF3</td><td width="15%" align="center" ><b>P_F3</b></td>
							<td width="15%" align="center" >LATFbits.LATF3</td><td width="15%" align="center" ><b>L_F3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F4</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF4</td><td width="15%" align="center" ><b>T_F4</b></td>
							<td width="15%" align="center" >PORTFbits.RF4</td><td width="15%" align="center" ><b>P_F4</b></td>
							<td width="15%" align="center" >LATFbits.LATF4</td><td width="15%" align="center" ><b>L_F4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F5</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF5</td><td width="15%" align="center" ><b>T_F5</b></td>
							<td width="15%" align="center" >PORTFbits.RF5</td><td width="15%" align="center" ><b>P_F5</b></td>
							<td width="15%" align="center" >LATFbits.LATF5</td><td width="15%" align="center" ><b>L_F5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F6</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF6</td><td width="15%" align="center" ><b>T_F6</b></td>
							<td width="15%" align="center" >PORTFbits.RF6</td><td width="15%" align="center" ><b>P_F6</b></td>
							<td width="15%" align="center" >LATFbits.LATF6</td><td width="15%" align="center" ><b>L_F6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>F7</b></td>
							<td width="15%" align="center" >TRISFbits.TRISF7</td><td width="15%" align="center" ><b>T_F7</b></td>
							<td width="15%" align="center" >PORTFbits.RF7</td><td width="15%" align="center" ><b>P_F7</b></td>
							<td width="15%" align="center" >LATFbits.LATF7</td><td width="15%" align="center" ><b>L_F7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
			\subsection langportg	Port G
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>G0</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG0</td><td width="15%" align="center" ><b>T_G0</b></td>
							<td width="15%" align="center" >PORTGbits.RG0</td><td width="15%" align="center" ><b>P_G0</b></td>
							<td width="15%" align="center" >LATGbits.LATG0</td><td width="15%" align="center" ><b>L_G0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G1</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG1</td><td width="15%" align="center" ><b>T_G1</b></td>
							<td width="15%" align="center" >PORTGbits.RG1</td><td width="15%" align="center" ><b>P_G1</b></td>
							<td width="15%" align="center" >LATGbits.LATG1</td><td width="15%" align="center" ><b>L_G1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G2</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG2</td><td width="15%" align="center" ><b>T_G2</b></td>
							<td width="15%" align="center" >PORTGbits.RG2</td><td width="15%" align="center" ><b>P_G2</b></td>
							<td width="15%" align="center" >LATGbits.LATG2</td><td width="15%" align="center" ><b>L_G2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G3</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG3</td><td width="15%" align="center" ><b>T_G3</b></td>
							<td width="15%" align="center" >PORTGbits.RG3</td><td width="15%" align="center" ><b>P_G3</b></td>
							<td width="15%" align="center" >LATGbits.LATG3</td><td width="15%" align="center" ><b>L_G3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G4</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG4</td><td width="15%" align="center" ><b>T_G4</b></td>
							<td width="15%" align="center" >PORTGbits.RG4</td><td width="15%" align="center" ><b>P_G4</b></td>
							<td width="15%" align="center" >LATGbits.LATG4</td><td width="15%" align="center" ><b>L_G4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G5</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG5</td><td width="15%" align="center" ><b>T_G5</b></td>
							<td width="15%" align="center" >PORTGbits.RG5</td><td width="15%" align="center" ><b>P_G5</b></td>
							<td width="15%" align="center" >LATGbits.LATG5</td><td width="15%" align="center" ><b>L_G5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G6</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG6</td><td width="15%" align="center" ><b>T_G6</b></td>
							<td width="15%" align="center" >PORTGbits.RG6</td><td width="15%" align="center" ><b>P_G6</b></td>
							<td width="15%" align="center" >LATGbits.LATG6</td><td width="15%" align="center" ><b>L_G6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>G7</b></td>
							<td width="15%" align="center" >TRISGbits.TRISG7</td><td width="15%" align="center" ><b>T_G7</b></td>
							<td width="15%" align="center" >PORTGbits.RG7</td><td width="15%" align="center" ><b>P_G7</b></td>
							<td width="15%" align="center" >LATGbits.LATG7</td><td width="15%" align="center" ><b>L_G7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
			\subsection langporth	Port H
				\htmlonly
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name ( for READ )</th>
							<th width="30%" align="center" >LAT name ( for WRITE )</th>
						</tr>
					</thead>
				</table>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" ><b>&nbsp;</b></th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
							<th width="15%" align="center" >STD</th><th width="15%" align="center" >PicGIM</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td width="10%" align="center" ><b>H0</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH0</td><td width="15%" align="center" ><b>T_H0</b></td>
							<td width="15%" align="center" >PORTHbits.RH0</td><td width="15%" align="center" ><b>P_H0</b></td>
							<td width="15%" align="center" >LATHbits.LATH0</td><td width="15%" align="center" ><b>L_H0</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H1</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH1</td><td width="15%" align="center" ><b>T_H1</b></td>
							<td width="15%" align="center" >PORTHbits.RH1</td><td width="15%" align="center" ><b>P_H1</b></td>
							<td width="15%" align="center" >LATHbits.LATH1</td><td width="15%" align="center" ><b>L_H1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H2</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH2</td><td width="15%" align="center" ><b>T_H2</b></td>
							<td width="15%" align="center" >PORTHbits.RH2</td><td width="15%" align="center" ><b>P_H2</b></td>
							<td width="15%" align="center" >LATHbits.LATH2</td><td width="15%" align="center" ><b>L_H2</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H3</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH3</td><td width="15%" align="center" ><b>T_H3</b></td>
							<td width="15%" align="center" >PORTHbits.RH3</td><td width="15%" align="center" ><b>P_H3</b></td>
							<td width="15%" align="center" >LATHbits.LATH3</td><td width="15%" align="center" ><b>L_H3</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H4</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH4</td><td width="15%" align="center" ><b>T_H4</b></td>
							<td width="15%" align="center" >PORTHbits.RH4</td><td width="15%" align="center" ><b>P_H4</b></td>
							<td width="15%" align="center" >LATHbits.LATH4</td><td width="15%" align="center" ><b>L_H4</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H5</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH5</td><td width="15%" align="center" ><b>T_H5</b></td>
							<td width="15%" align="center" >PORTHbits.RH5</td><td width="15%" align="center" ><b>P_H5</b></td>
							<td width="15%" align="center" >LATHbits.LATH5</td><td width="15%" align="center" ><b>L_H5</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H6</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH6</td><td width="15%" align="center" ><b>T_H6</b></td>
							<td width="15%" align="center" >PORTHbits.RH6</td><td width="15%" align="center" ><b>P_H6</b></td>
							<td width="15%" align="center" >LATHbits.LATH6</td><td width="15%" align="center" ><b>L_H6</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>H7</b></td>
							<td width="15%" align="center" >TRISHbits.TRISH7</td><td width="15%" align="center" ><b>T_H7</b></td>
							<td width="15%" align="center" >PORTHbits.RH7</td><td width="15%" align="center" ><b>P_H7</b></td>
							<td width="15%" align="center" >LATHbits.LATH7</td><td width="15%" align="center" ><b>L_H7</b></td>
						</tr>
					</tbody>
				</table>
				\endhtmlonly
		</p>
			\htmlonly <br><br> \endhtmlonly

	\section	langpinmacro	The MACRO for handling PINS
			\htmlonly <hr> \endhtmlonly
			This is a list of macros defined for handling PINs. \n

			\htmlonly <br><br> \endhtmlonly
			\endcode

			\arg \b pg_pin_mode() : This macro is useful to set a specific bit as INPUT or OUTPUT.
			\arg \b pg_pin_set() : This macro is useful to set a specific bit to logic level ONE.
			\arg \b pg_pin_clear() : This macro is useful to set a specific bit to logic level ZERO.
			\arg \b pg_pin_write() : This macro is useful to set a specific bit to a specific value.
			\arg \b pg_pin_read() : This macro is useful to read the logical level of a specific bit.
			\arg \b pg_pin_toggle() : With this function you can reverse the logic value present. If the value is 1 after the call will be 0, and vice versa.
			\htmlonly <br><br> \endhtmlonly

		\subsection	langpinmacroexample		A code example
 		\htmlonly
			Here is a simple example of how to use the pin macro in your code. <br>
		\endhtmlonly

		\code
			...
			pg_pin_mode( T_D0 , PG_OUT );
			pg_pin_mode( T_D1 , PG_IN );
			pg_pin_mode( T_D2 , PG_IN );
			pg_pin_mode( T_D3 , PG_IN );
			pg_pin_mode( T_D4 , PG_OUT );

			pg_pin_clear( L_D0 );
			pg_pin_set( L_D0 );
			pg_pin_write( L_D0 , pg_pin_read( P_D1 ) & pg_pin_read( P_D2 ) & pg_pin_read( P_D3 ) );

			PG_LOOP( PG_FOREVER ) {
				pg_pin_toggle( L_D4 );
			}
 
 		\endcode

		\htmlonly <br><br> \endhtmlonly


*/



