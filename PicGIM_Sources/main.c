//
// 
//
// PicGim  -  Generic Information Manager for Pic 18 / 24 family uControllers 
// Version 0.6-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002 - 2018
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

/*!		\file			main.c
		\version		0.6-0
		\date			2002 - 2019
		\brief			Bootloader
		\details		...
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim_main.h"

#define	PG_ADDRESS_BOOTLOADER_RESET		0x0100
#define	PG_ADDRESS_IRQ_LOW				0x0008
#define	PG_ADDRESS_IRQ_HIGH				0x0018
#define	PG_ADDRESS_PROGRAM_RESET		0x1000
#define	PG_ADDRESS_IRQ_LOW_REMAP		0x0408
#define	PG_ADDRESS_IRQ_HIGH_REMAP		0x0418


//------------------------------------------------------------------------
//	Bootloader
//------------------------------------------------------------------------
#pragma code BL_START = PG_ADDRESS_BOOTLOADER_RESET
void main( void ) {
	//------------------------------------------------------------------------
	pg_initialize( );

	T_B0 = PG_OUT;
	T_B5 = PG_IN;
	
	L_B0 = PG_OFF;
	
	if( !P_B5 ) {
		//------------------------------------------------------------------------
		//	Boot-Mode
		//------------------------------------------------------------------------
		// ( Start )
		// Read Device-ID (optional)(readonly)
		// Perform Bulk Erase
		// Program Memory
		// Program ID-Location
		// Program Data EE
		// Verify  Program
		// Verify  ID-Location
		// Verify  Data
		// Program Configuration Bits
		// Verify  Configuration Bits
		// ( Done )
		//------------------------------------------------------------------------
		
		pg_flash_lvp_bulk_erase( PG_FLASH_LVP_BULK_ERASE_CHIP );
		
		while( 1 ) {
			pg_delay_msec( 100 );
			pg_pin_toggle( L_B0 );

		}
	}
	_asm GOTO PG_ADDRESS_PROGRAM_RESET _endasm
	PG_HALT;
}
#pragma code 

//------------------------------------------------------------------------
//	Main application
//------------------------------------------------------------------------
#pragma code PRG_RESET = PG_ADDRESS_PROGRAM_RESET
void pg_main( void ) {
	//------------------------------------------------------------------------
	//	NO Boot-Mode
	//------------------------------------------------------------------------
	while( 1 ) {
		pg_delay_msec( 500 );
		pg_pin_toggle( L_B0 );		
	}        
	PG_HALT;
}
#pragma code 

//------------------------------------------------------------------------
//	IRQ LOW
//------------------------------------------------------------------------
#pragma code IRQ_LOW = PG_ADDRESS_IRQ_LOW
void pg_irq_low( void ) {
	_asm GOTO PG_ADDRESS_IRQ_LOW_REMAP _endasm
}
#pragma code 

//------------------------------------------------------------------------
//	IRQ HIGH
//------------------------------------------------------------------------
#pragma code IRQ_HIGH = PG_ADDRESS_IRQ_HIGH
void pg_irq_high( void ) {
	_asm GOTO PG_ADDRESS_IRQ_HIGH_REMAP _endasm
}
#pragma code 

//------------------------------------------------------------------------
//	IRQ LOW Re-Map
//------------------------------------------------------------------------
#pragma code IRQ_LOW_REMAP = PG_ADDRESS_IRQ_LOW_REMAP
void pg_irq_low_remap( void ) {
	;//irq low code here
}
#pragma code 

//------------------------------------------------------------------------
//	IRQ HIGH Re-Map
//------------------------------------------------------------------------
#pragma code IRQ_HIGH_REMAP = PG_ADDRESS_IRQ_HIGH_REMAP
void pg_irq_high_remap( void ) {
	;//irq high code here
}
#pragma code 





 // tipo dato:	(00)dato, (04)exted.addy...
// se dato:	indirizzo
			// #dati
			// dati
			// < risposta con chksum dei dati

// se exted.addy:	upper addy
				// < risposta con chksum dell'indirizzo
				
// tipo (01) protocollato















// void main( void ) {
	
	// _pg_Uint32 a;
	// _pg_Uint8 n;
	// _pg_Uint8 buffer[ 64 ];
	// _pg_Uint8 rbuffer[ 8 ];
	

	// _pg_Uint16 		obj16;
	// _pg_Uint32 		obj32;
	
	// //_pg_Uint8 buffer[ ] = "Hallo Zanna! Un saluto dalla program memory!!!!!!!!!!!!!!!!!!!!!";
	
	// pg_initialize( );
	// //pg_serial_open( );

	// T_B0 = PG_OUT;
	// T_B5 = PG_IN;
	
	// L_B0 = PG_OFF;
	
	// //INTCONbits.GIE = 0;
	
	// for( n = 0 ; n < 64 ; n++ ) {
		// buffer[ n ] = n;
	// }
	
	// n 		= 64;
	// obj32	= 0x12345678;	

	
	// if( P_B5 == 1 ) {
		// //pg_flash_erase( 0x0140, 0x02cf );
		// //void pg_flash_write_block( _pg_Uint32 pg_wb_address_start, _pg_Uint8 pg_block_number, _pg_Uint8 * pg_buffer_write ) {
		// //void pg_flash_read( _pg_Uint32 pg_address_start, _pg_Uint16 pg_byte_number, _pg_Uint8 * pg_buffer_read ) {
		
		// //pg_flash_write_block( 0x0c00, 5, buffer );
		// // pg_flash_erase( 0x0c80, 1 );
		// // pg_flash_read( 0x0cc0, 8, rbuffer );
		// // pg_flash_write_block( 0x0d80, 1, rbuffer );
		// // pg_flash_write_word( 0x2000 , 0x1234 );
		// // pg_flash_write_word( 0x2002 , pg_endian_word( 0x1234 ) );
		
		// // obj16	= ( (_pg_Uint16)( ( obj32 >> 16 ) & 0x0000FFFF ) );
		// // pg_flash_write_word( 0x2000 , obj16 );
		// // obj16	= ( (_pg_Uint16)( ( obj32) & 0x0000FFFF ) );
		// // pg_flash_write_word( 0x2002 , obj16 );
		// // obj16	= ( (_pg_Uint16)( ( pg_endian_double_word( obj32 ) >> 16 ) & 0x0000FFFF ) );
		// // pg_flash_write_word( 0x2010 , obj16 );
		// // obj16	= ( (_pg_Uint16)( pg_endian_double_word( obj32 ) & 0x0000FFFF ) );
		// // pg_flash_write_word( 0x2012 , obj16 );

		// //pg_flash_write_word( 0x2014 , 0x5678 );
		// while( 1 ) {
			// pg_delay_msec( 100 );
			// pg_pin_toggle( L_B0 );
			// // if( !P_B5 ) {
				// // pg_flash_write_word( 0x1227 , 0x0eff );
			// // }
		// }
	// }
	// while( 1 ) {
		// pg_delay_msec( 500 );
		// pg_pin_toggle( L_B0 );		
	// }        
	// PG_HALT;
// }
// //#pragma code 


