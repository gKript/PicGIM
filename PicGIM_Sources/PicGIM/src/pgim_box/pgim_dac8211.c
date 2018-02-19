//
// pgim_dac8211.c
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

/*!		\file			pgim_dac8211.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

//main.c
//Kappa, 26 Gennaio 2013

//----------------------------------------------------------------------------
//	INCLUDE
//----------------------------------------------------------------------------
#include <p18f4550.h>
#include <delays.h>
#include "main.h"
#include <usart.h>
#include <stdlib.h>

//----------------------------------------------------------------------------
//	PRAGMA
//----------------------------------------------------------------------------
#pragma config MCLRE	=	ON
#pragma config FOSC		=	XT_XT
#pragma config PLLDIV	=	1			//No prescale (4 MHz oscillator input drives PLL directly) 
#pragma config CPUDIV	=	OSC1_PLL2	//Postscaler [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
										//=> 4*12=96, 96/2=48
#pragma config WDT		=	OFF
#pragma config PWRT		=	ON
#pragma config BOR		=	OFF
#pragma config LVP		=	OFF
#pragma config PBADEN   =	OFF

//----------------------------------------------------------------------------
//	Main
//----------------------------------------------------------------------------
void main( void ) {

	unsigned char k = 0;			//contatore
	char parola[ 6 ] = "00000";
	int word = 0;					//dato a 16bit con segno

	// Senza segno:
	//--------------------------------
	// 0-32767		-->	 2.50V - 3.75V
	// 32768-65525	-->	 1.25V - 2.50V

	// Con segno:
	//--------------------------------
	// 0-32767		-->	 2.50V - 3.75V	==> 0 - (+)1.25 con (+)2.50V di offset
	// -32768-0		-->	 1.25V - 2.50V	==> 0 - (-)1.25 con (+)2.50V di offset
	
	//------------------------------------------------------------------------
	//	Hardware config ------------------------------------------------------
	//------------------------------------------------------------------------
	
	//	INGRESSI ANALOGICI
	ADCON1	=	0x0F;				//disabilitati
	
	//	PT8211
	PT8211_CH_TRIS		=	0;
	PT8211_CL_TRIS		=	0;
	PT8211_DT_TRIS		=	0;
	
	//	LED
	LED_TRIS			=	0;

	//	USART
	
	//RCSTA |= 0b10000000;		//configuro seriale hw: pag.237 pdf, bit SPEN a 1
	//TRISC |= 0b11000000;		//configuro seriale hw: pag.237 pdf, pin RX(RC7) e TX(RC6) in ingresso; il modulo settera' TX in out.

	OpenUSART(	USART_TX_INT_OFF  &
				USART_RX_INT_OFF  &
				USART_ASYNCH_MODE &
				USART_EIGHT_BIT   &
				USART_CONT_RX     &
				USART_BRGH_HIGH, 25 );	//9600@4MHz;	Terminale: 9600, 8N1, NO_HW, ANSIW

	//------------------------------------------------------------------------
	//	Code
	//------------------------------------------------------------------------
	Flash_Led();
	Delay10KTCYx( 100 );
	
	putrsUSART( "\n\n\r" );
	putrsUSART( "PIC18F4550 - 48MHz (4MHz x 12)\n\r" );
	putrsUSART( "PT8211 16bit DAC Test\n\r" );
	putrsUSART( "-----------------------------\n\r" );
	putrsUSART( "    0-32767 --> 2.50V - 3.75V\n\r" ); 
	putrsUSART( "32768-65525 --> 1.25V - 2.50V\n\r" );
	putrsUSART( "-----------------------------\n\n\r" );
	
	while( 1 ) {
		putrsUSART( "PT8211: Input dec word > " );	//while ( BusyUSART() ); //aspetto che non stia ancora trasmettendo
		getsUSART( parola, 5 );						//while( !DataRdyUSART() )
		putrsUSART( "\t\tReceived dec word: " );
		putsUSART( parola );						//scrive stringa + null; //while ( BusyUSART() ); //aspetto che non stia ancora trasmettendo
		putrsUSART( "\n\r" );
			
		word = atoi( parola );						//int atoi( const char * s );

		Flash_Led();
		Delay10KTCYx( 100 );
			
		PT8211_DT = 0;							//pin dato basso
		PT8211_CL = 0;							//legge il dato sul fronte di salita
		PT8211_CH = 0;							//0=DX; 1=SX

		Write_Word( DX, word );					//void Write_Word ( char ch, int dataword );
		Delay10KTCYx( 1 );
		Write_Word( SX, word );					//void Write_Word ( char ch, int dataword );
		Delay10KTCYx( 1 );

		PT8211_CL = 0;
		PT8211_DT = 0;
		PT8211_CH = 0;
	}
}

//----------------------------------------------------------------------------
//	Flash_Led
//----------------------------------------------------------------------------
void Flash_Led( void ) {

	LED = 1;
	Delay1KTCYx( 250 );
	LED = 0;
}

//----------------------------------------------------------------------------
//	Write_Word
//----------------------------------------------------------------------------
void Write_Word( unsigned char ch, int campione ) {

	unsigned char j = 0;						//contatore
	char stringa[ 20 ];
	
	PT8211_CH = ch;
	
	for( j = 0; j < 16; j++ ){
		PT8211_DT = ( ( ( campione << j  ) & 0x8000 ) >> 15 );	//grazie Zanna!
		
		PT8211_CL = 1;
		Delay10TCYx( 1 );		//CL_H min 25ns; 1cy=20ns; aspetto 10 cicli
		PT8211_CL = 0;
		Delay10TCYx( 1 );
		
		if( PT8211_CH == DX ) {
			stringa[ j ] = PT8211_DT + '0';
		}
	}
	if( PT8211_CH == DX ) {
		stringa[ 16 ] = '\0';
		putrsUSART( "\t\t\t\t\tLatched  bin word: " );
		putsUSART( stringa );	//itoa( PT8211_DT, stringa ) );	//itoa( int value, char * string );
		putrsUSART( "\n\n\r" );
	}
}
//----------------------------------------------------------------------------
//EOF
//----------------------------------------------------------------------------

// char   byte;           // 8-bit
// int    word;           // 16-bit
// long   dword;          // 32-bit


