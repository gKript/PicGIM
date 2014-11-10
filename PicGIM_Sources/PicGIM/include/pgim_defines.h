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

	#define	PG_LOOP( a )			while( a )
	#define	PG_INFINITE_LOOP		while( 1 )
	#define	PG_HALT					while( 1 )

	#define	PG_FOREVER				1
	
	#define	PG_OK					1
	#define	PG_NOK					0

	#define	PG_DONE					1
	#define	PG_NOT_DONE				0
	
	#define	PG_YES					1
	#define	PG_NO					0

	#define	PG_ON					1
	#define	PG_OFF					0

	#define	PG_IN					1
	#define	PG_OUT					0

	#define	PG_8BIT_IN				0xFF
	#define	PG_8BIT_OUT				0x00

	#define	PG_LOW					0
	#define	PG_HIGH					1
	#define	PG_TRISTATE				2
	
	#define	PG_SET					1
	#define	PG_CLEAR				0

	#define	PG_START				1
	#define	PG_STOP					0

	#define	PG_ENABLE				1
	#define	PG_DISABLE				0

	#define PG_ENABLE_1_S			2
	#define PG_ENABLE_LOO			3

	#define	PG_INCLUDE				1
	#define	PG_NOT_INCLUD			0

	#define	PG_MASTER				1
	#define	PG_SLAVE				2

	#define	PG_BUSY					1
	#define	PG_READY				0

	#define PG_TRUE					1
	#define PG_FALSE				0

	#define PG_READ					1
	#define PG_WRITE				0

	#define	PG_SEC					1
	#define	PG_MSEC					2
	#define	PG_USEC					3

	#define	PG_HZ					4
	#define	PG_KHZ					5
	#define	PG_MHZ					6

	#define PG_RELEASE				0
	#define PG_DEBUG				1
	
	#define PG_NONE					0
	#define PG_STANDARD				1
	#define PG_ENHANCED				2
	
	#define PG_MANUAL				0
	#define PG_SEMI_AUTOMATIC		1
	#define PG_AUTOMATIC			2

	#define	PG_DEBUG_LCD_CHAR		1
//	#define PG_DEBUG_LCD_PCD8544	2
	
	#define PG_COMMAND				0
	#define PG_DATA					1
	
	#define PG_MISSING				-1
	
	#define PG_CONTROLLER_0			0
	#define PG_CONTROLLER_1			1
	#define PG_CONTROLLER_2			2
	#define PG_CONTROLLER_3			3
	
	#define	PG_LINE_0				0
	#define	PG_LINE_1				1
	#define	PG_LINE_2				2
	#define	PG_LINE_3				3

	#define	PG_HD44780				1

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//      B O A R D   D E F I N E S
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	#define	PG_BOARD_USER_DEFINED	0
	#define	PG_BOARD_A				1
	#define	PG_BOARD_EXPERIENCE		2

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

	\page	PG_language		The language of PicGIM

		\tableofcontents
	
		\n
		\image html language.png
		\n \n 
			
		\b PicGIM also introduces changes to the classic references of the \b Microchip \b environment. \n
		These changes affect different components such as the \b types \b of \b variables and the \b PIN \b names. \n
		These changes were made with the purpose to simplify the code writing. \n \n
	
		
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
							<th width="25%" align="left" >PicGIM type</th>
							<th width="25%" align="left" >STD type</th>
							<th width="50%" align="left" >Description</th>
						</tr>
					</thead>
					<tbody>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_int8 \htmlonly</b></td><td>char</td><td>Signed integer 8 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_Uint8 \htmlonly</b></td><td>unsigned char</td><td>Unsigned integer 8 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_int16 \htmlonly</b></td><td>int</td><td>Signed integer 16 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_Uint16 \htmlonly</b></td><td>unsigned int</td><td>Unsigned integer 16 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_int24 \htmlonly</b></td><td>short long</td><td>Signed integer 24 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_Uint24 \htmlonly</b></td><td>unsigned short long</td><td>Unsigned integer 24 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_int32 \htmlonly</b></td><td>long</td><td>Signed integer 32 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_Uint32 \htmlonly</b></td><td>unsigned long</td><td>Unsigned integer 32 bit size</td>
						</tr>
						<tr>
							<td >&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_buffer \htmlonly</b></td><td>char *</td><td>A pointer to a signed integer 8 bit size</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_Ubuffer \htmlonly</b></td><td>unsigned char *</td><td>A pointer to a unsigned integer 8 bit size</td>
						</tr>
						<tr>
							<td >&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td>
						</tr>
						<tr>
							<td ><b>\endhtmlonly \ref _pg_bool \htmlonly</b></td><td>BOOL</td><td>A boolean flag</td>
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
				They were also reorganized the names of the pins to the context ( TRIS, PORT, LAT ). \n
				Here is a reference table for each port. \n
				\htmlonly
				<br>
				<table class="cl_table" width="100%" border="0" >
					<thead>
						<tr>
							<th width="10%" align="center" >PIN</th>
							<th width="30%" align="center" >TRIS name</th>
							<th width="30%" align="center" >PORT name</th>
							<th width="30%" align="center" >LAT name</th>
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
							<td width="10%" align="center" ><b>A1</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA1</td><td width="15%" align="center" ><b>T_A1</b></td>
							<td width="15%" align="center" >PORTAbits.RA1</td><td width="15%" align="center" ><b>P_A1</b></td>
							<td width="15%" align="center" >LATAbits.LATA1</td><td width="15%" align="center" ><b>L_A1</b></td>
						</tr>
						<tr>
							<td width="10%" align="center" ><b>A1</b></td>
							<td width="15%" align="center" >TRISAbits.TRISA1</td><td width="15%" align="center" ><b>T_A1</b></td>
							<td width="15%" align="center" >PORTAbits.RA1</td><td width="15%" align="center" ><b>P_A1</b></td>
							<td width="15%" align="center" >LATAbits.LATA1</td><td width="15%" align="center" ><b>L_A1</b></td>
						</tr>
					</tbody>
				</table>
				
				\endhtmlonly
		</p>
*/



