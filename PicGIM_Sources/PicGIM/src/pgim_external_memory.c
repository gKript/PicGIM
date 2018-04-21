//
// pgim_external_memory.c
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

/*!		\file			pgim_external_memory.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HM_EXT_MEM This file is compiling.
	#endif

/*
> Serial Peripheral Interface compatible -- Mode 0 and Mode 3
> 67,108,864 x 1 bit structure or 33,554,432 x 2 bits (Dual Output mode) structure
> 2048 Equal Sectors with 4K byte each
- Any Sector can be erased individually
> 128 Equal Blocks with 64K byte each
- Any Block can be erased individually
> Program Capability
- Byte base
- Page base (256 bytes)
> Latch-up protected to 100mA
*/
//----------------------------------------------------------------------------
/* Addressing MX25L4005:
   -----------------------------
   8         16        4096
   BLK       SEC       ADDR
   8bit      4bit      12bit
   -----------------------------	
   0000.0000|0000|0000.0000.0000
   -----------------------------
   8   *      16   *   4096       * 8 bit = 4.194.304	= 4[Mb]		//ok
   -----------------------------
   #1BLK =  #16SEC =  #16PAG 	(#1PAG=256[byte])
*/
//----------------------------------------------------------------------------
/* Addressing MX25L6406:
   -----------------------------
   128       16        4096
   BLK       SEC       ADDR
   8bit      4bit      12bit
   -----------------------------	
   0000.0000|0000|0000.0000.0000
   -----------------------------
   8   *      16   *   4096       * 8 bit = 67.108.864 = 64[Mb]	//ok
   -----------------------------
   #1BLK =  #16SEC =  #16PAG 	(#1PAG=256[byte])   
*/	
//----------------------------------------------------------------------------
//	Adr_H = Block  Address;
//	Adr_M = Sector Address;
//	Adr_L = Range  Address;
//----------------------------------------------------------------------------

	#if ( PGIM_EXTERNAL_MEMORY_TECNOLOGY == PG_TECNOLOGY_SPI )
		_pg_Uint8 pg_external_memory_page_buffer[ PGIM_EXTERNAL_MEMORY_PAGE_SIZE ];	//internal use
		
		//---[ Init ]---
		void pg_external_memory_init( void ) {
			//--------------------------------------------------
			PG_EXTERNAL_MEMORY_CS_TRIS		= PG_OUT;
			PG_SPI_SCK_TRIS					= PG_OUT;
			PG_SPI_SDO_TRIS					= PG_OUT;
			PG_SPI_SDI_TRIS					= PG_IN;
			//PG_SPI_SS_TRIS				= PG_IN;
		}
		//---[ End Init ]---
		
		
		//---[ Write Page ]---
		_pg_Uint8 pg_external_memory_write_page( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 * bWrite_Page_Data ){
			//--------------------------------------------------
			_pg_Uint16 iwp0;

			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
            PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_PAGE );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( 0x00 );
			
			for( iwp0 = 0; iwp0 < PGIM_EXTERNAL_MEMORY_PAGE_SIZE; iwp0++ ) {
				putcSPI( *( bWrite_Page_Data + (_pg_Uint8)iwp0 ) );
			}
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_external_memory_busy( PG_LOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Write Page ]---


		//---[ Read Page ]---
		_pg_Uint8 pg_external_memory_read_page( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 * bRead_Page_Data ){
			//--------------------------------------------------
			_pg_Uint16 irp0;

			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( 0x00 );
			for( irp0 = 0; irp0 < PGIM_EXTERNAL_MEMORY_PAGE_SIZE; irp0++ ) {
				*( bRead_Page_Data + (_pg_Uint8)irp0 ) = ReadSPI();
			}
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Read Page ]---
		
		
		//---[ Erase Sector ]---
 		_pg_Uint8 pg_external_memory_erase_sector( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M ) {
			//--------------------------------------------------
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_SECTOR );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( 0x00 );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_external_memory_busy( PG_LOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Erase Sector ]---


		//---[ Erase Chip  ]---
		// _pg_Uint8 pg_external_memory_erase_chip( void ) {
			// //--------------------------------------------------
			
			// if ( pg_external_memory_busy( PG_YES ) == PG_BUSY ) 
				// return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
				
			// pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			// PG_EXTERNAL_MEMORY_CS = PG_LOW;	
			// putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			// PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			// //Verificare!	
			// pg_delay( 1 , PG_USEC );
			
			// PG_EXTERNAL_MEMORY_CS = PG_LOW;	
			// putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_CHIP );
			// PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			// pg_spi_close( PG_SPI_0 );
			// return( PG_DONE );
		//}
		//---[ END Erase Chip  ]---

		


		//---[ Erase Block ]---
		// _pg_Uint8 pg_external_memory_erase_block( _pg_Uint8 Adr_H ) {
			// //--------------------------------------------------
			
			// if ( pg_external_memory_busy( PG_YES ) == PG_BUSY ) 
				// return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			// pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			// PG_EXTERNAL_MEMORY_CS = PG_LOW;
			// putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			// PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			// //Verificare!
			// pg_delay( 1 , PG_USEC );
			
			// PG_EXTERNAL_MEMORY_CS = PG_LOW;
			// putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_BLOCK );
			// putcSPI( Adr_H );
			// putcSPI( 0x00 );
			// putcSPI( 0x00 );
			// PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			// pg_spi_close( PG_SPI_0 );
			// return( PG_DONE );
		// }
		//---[ END Erase Block ]---

		
		
		
		//---[ Write Byte ]---	
		_pg_Uint8 pg_external_memory_write_byte( _pg_Uint8 Adr_H , _pg_Uint8 Adr_M , _pg_Uint8 Adr_L , _pg_Uint8 Byte_To_Write , _pg_Uint8 Verify ) {	//PG_VERIFY || PG_NOT_VERIFY
			//--------------------------------------------------
			pg_external_memory_read_page( Adr_H , Adr_M , pg_external_memory_page_buffer );
			pg_external_memory_page_buffer[ Adr_L ] = Byte_To_Write;
			pg_external_memory_erase_sector( Adr_H , Adr_M );	//NON va bene cancellare tutto il settore e non solo la pagina... solo per test!!!
			pg_external_memory_write_page( Adr_H , Adr_M , pg_external_memory_page_buffer );

			if ( ( Verify == PG_VERIFY ) && ( Byte_To_Write == pg_external_memory_read_byte( Adr_H, Adr_M, Adr_L ) ) )
				return( PG_OK );
			else
				return( PG_NOK );	//correggere se no verify
		}
		//---[ END Write Byte ]---
		
		
		//---[ Read Byte ]---
		_pg_Uint8 pg_external_memory_read_byte( _pg_Uint8 Adr_H , _pg_Uint8 Adr_M , _pg_Uint8 Adr_L ) {
			//--------------------------------------------------
			_pg_Uint8 Byte_To_Read;

			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
			Byte_To_Read = ReadSPI();
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_spi_close( PG_SPI_0 );
			return( Byte_To_Read );
		}
		//---[ END Read Byte ]---

		
		//---[ Wait Busy Check ]---
		_pg_Uint8 pg_external_memory_busy( _pg_Uint8 blocking_flag ) {
			//--------------------------------------------------
			// Blocking		---> blocking_flag = PG_LOCKING			( Wait until no more busy, and return status PG_BUSY || PG_READY )
			// NON Blocking ---> blocking_flag = PG_NOT_LOCKING		( No wait and returns busy status PG_BUSY || PG_READY )
			// Device can be busy only on Program/Erase/Write access
			//--------------------------------------------------
			_pg_Uint8 Wip_Temp;
			
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_STATUS_REG );
			
			do {
				Wip_Temp = ReadSPI();
				Wip_Temp &= 0b00000001;				// Waiting and checking for WIP bit of Status-Register: 1 = busy, 0 = idle
				if ( blocking_flag == PG_NOT_LOCKING ) {
					PG_EXTERNAL_MEMORY_CS = PG_HIGH;
					if( Wip_Temp == 1 )
						return( PG_BUSY );			// If busy
					else
						return( PG_READY );
				}
			} while( Wip_Temp );
			
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			pg_spi_close( PG_SPI_0 );
			return( PG_READY );
		}
		//---[ END Wait Busy Check ]---
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
/*
		_pg_Uint8 pg_external_memory_address_high;
		_pg_Uint8 pg_external_memory_address_mid;
		_pg_Uint8 pg_external_memory_address_low;
		
		//---[ Select Page ]---
		_pg_Uint8 pg_external_memory_select_page( _pg_Uint32_ n_page_to_select ){
			//--------------------------------------------------
			//
			
			


		}
		//---[ END Select Page ]---


*/
	#endif	/* PG_TECNOLOGY_SPI */
	
	
	#if ( PGIM_EXTERNAL_MEMORY_TECNOLOGY == PG_TECNOLOGY_I2C )
	
/*		//---[  ]---
		void pg_ ( void ) {
			//--------------------------------------------------
			
			// Asy's code here...

		}
		//---[ END   ]---
*/

	#endif	/* PG_TECNOLOGY_I2C */
#endif	


