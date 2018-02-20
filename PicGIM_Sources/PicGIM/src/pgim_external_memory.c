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

/* Addressing MX25L64:
   -----------------
   128     16   16   256
   BLK     SEC  PAG  Byte
   7bit    4bit 4bit 8bit
   --------------------------
   0000000.0000.0000.00000000
   --------------------------
   6543210 3210 3210 76543210
   
   128 * 16 * 16 * 256 * 8   = 67108864
   BLK   SEC  PAG  Byte  Bit   Bit total
*/	
	

	#if ( PGIM_EXTERNAL_MEMORY_TECNOLOGY == PG_TECNOLOGY_SPI )

		_pg_Uint8 pg_external_memory_page_buffer[ PGIM_EXTERNAL_MEMORY_PAGE_SIZE ];

		
		//---[ Erase Chip  ]---
		_pg_int8 pg_external_memory_erase_chip( void ) {
			//--------------------------------------------------
			
			if ( pg_external_memory_wait_busy_check( PG_NO ) == PG_BUSY ) 
				return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;	
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			
			//Verificare!	
			pg_delay( 1 , PG_USEC );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;	
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_CHIP );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			return( PG_DONE );
		}
		//---[ END Erase Chip  ]---

		
		//---[ Erase Block ]---
		_pg_int8 pg_external_memory_erase_block( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_L ) {
			//--------------------------------------------------
			
			if ( pg_external_memory_wait_busy_check( PG_NO ) == PG_BUSY ) 
				return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			
			//Verificare!
			pg_delay( 1 , PG_USEC );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_BLOCK );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			return( PG_DONE );
		}
		//---[ END Erase Block ]---

		
		//---[ Erase Sector ]---
		_pg_int8 pg_external_memory_erase_sector( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_L ) {
			//--------------------------------------------------
			
			if ( pg_external_memory_wait_busy_check( PG_NO ) == PG_BUSY ) 
				return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			
			//Verificare!
			pg_delay( 1 , PG_USEC );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_SECTOR );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			return( PG_DONE );
		}
		//---[ END Erase Sector ]---
		
		
		//---[ Write Page ]---
		_pg_int8 pg_external_memory_write_page( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_L, _pg_Uint8 * bWrite_Page_Data ){
			//--------------------------------------------------
			
			unsigned int iwp0;
			
			if ( pg_external_memory_wait_busy_check( PG_NO ) == PG_BUSY ) 
				return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;

			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_PAGE );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );						// Set to '0x00' or any value to select page ???
				
			for( iwp0 = 0; iwp0 < PGIM_EXTERNAL_MEMORY_PAGE_SIZE; iwp0++ ) {
				putcSPI( *( bWrite_Page_Data + iwp0 ) );
			}
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			return( PG_DONE );
		}
		//---[ END Write Page ]---


		//---[ Read Page ]---
		_pg_int8 pg_external_memory_read_page( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_L, _pg_Uint8 * bRead_Page_Data ){
			//--------------------------------------------------
			
			unsigned int irp0;

			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
				
			for( irp0 = 0; irp0 < PGIM_EXTERNAL_MEMORY_PAGE_SIZE; irp0++ ) {
				*( bRead_Page_Data + irp0 ) = ReadSPI();
			}
			
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			return( PG_DONE );
		}
		//---[ END Read Page ]---

		
		//---[ Write Byte ]---	
		_pg_int8 pg_external_memory_write_byte( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_Offset, _pg_Uint8 bWrite_Byte_Data, _pg_Uint8 wb_verify ){
			//--------------------------------------------------
			
			if ( pg_external_memory_wait_busy_check( PG_NO ) == PG_BUSY ) 
				return( PG_EXTERNAL_MEMORY_ERROR_DEVICE_BUSY );
			
			pg_external_memory_read_page( Adr_H, Adr_M, 0x00, pg_external_memory_page_buffer );
			pg_external_memory_page_buffer[ Adr_Offset ] = bWrite_Byte_Data;
			pg_external_memory_write_page( Adr_H, Adr_M, 0x00, pg_external_memory_page_buffer );

			if ( ( wb_verify == PG_YES ) && ( bWrite_Byte_Data == pg_external_memory_read_byte( Adr_H, Adr_M, Adr_Offset ) ) )
				return( PG_OK );
			else
				return( PG_NOK );
		}
		//---[ END Write Byte ]---
		
		
		//---[ Read Byte ]---
		_pg_Uint8 pg_external_memory_read_byte( _pg_Uint8 Adr_H, _pg_Uint8 Adr_M, _pg_Uint8 Adr_L ){
			//--------------------------------------------------
			
			_pg_Uint8 bRead_Byte_Data;
			
			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
			
			bRead_Byte_Data = ReadSPI();
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
			
			return( bRead_Byte_Data );
		}
		//---[ END Read Byte ]---

		
		//---[ Wait Busy Check ]---
		_pg_int8 pg_external_memory_wait_busy_check( _pg_Uint8 blocking_flag ) {
			//--------------------------------------------------
			// Blocking		---> blocking_flag = PG_YES
			// NON Blocking ---> blocking_flag = PG_NO		( Returns busy status )
			// Device can be busy only on Program/Read/Write access
			
			_pg_Uint8 Wip_Temp;

			PG_EXTERNAL_MEMORY_CS = PG_ENABLE;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_STATUS_REG );
			
			do {
				Wip_Temp = ReadSPI();
				Wip_Temp &= 0b00000001;				// Waiting and checking for WIP bit of Status-Register: 1 = busy, 0 = idle
				if ( blocking_flag == PG_NO ) {
					PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
					if( Wip_Temp == 1 )
						return( PG_BUSY );			// If busy
					else
						return( PG_READY );
				}
			} while( Wip_Temp );
			
			PG_EXTERNAL_MEMORY_CS = PG_DISABLE;
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


