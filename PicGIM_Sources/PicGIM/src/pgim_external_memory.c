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

	//----------------------------------------------------------------------------
	//	WARNING!	Block '0' is reserved by the system for internal operations.
	//				However, it is possible to have access to all the complete
	//				memory, but some features will no longer be available.
	//				See define PGIM_EXTERNAL_MEMORY_ADDRESSING_PROTECTED in
	//				"pgim_external_memory_setup_public.h" file.
	//----------------------------------------------------------------------------
	// All operations are performed at the current address;
	// it is initialized as follows:
	// Block	= 0x01		( as PGIM_EXTERNAL_MEMORY_FIRST_FREE_BLOCK define in
	//						  pgim_external_memory.h file, but it must be modified
	//						  only if one knows what one is doing )
	// Sector	= 0x00
	// Page		= 0x00
	// Byte		= 0x00
	// It is possible to modify it using the dedicated functions.
	//----------------------------------------------------------------------------
	// Before any write operation, memory must be erased;
	// those functions are tagged with AUTOERASE_NO.
	// Some functions do not need, because erase is internally executed;
	// yhose functions are tagged with AUTOERASE-YES.
	//----------------------------------------------------------------------------
	//
	// =============================
	// Memory Map - MX25L4005:
	// =============================
	//    8      16   16     256
	//    BLK    SEC  PAG    Byte
	//    8bit   4bit 4bit   8bit
	// -----------------------------	
	// 0000.0000|0000|0000|0000.0000
	// -----------------------------
	//     8    * 16 * 16 *   256   * 8[bit] = 4.194.304	= 4[Mb]		//ok
	// -----------------------------
	// #1[BLK] = #16[SEC]
	// #1[SEC] = #16[PAG]
	// #1[PAG] = #256[Byte]
	//
	//----------------------------------------------------------------------------
	//
	// =============================
	// Memory Map - MX25L6406:
	// =============================
	//    128    16   16     256
	//    BLK    SEC  PAG    Byte
	//    8bit   4bit 4bit   8bit
	// -----------------------------	
	// 0000.0000|0000|0000|0000.0000
	// -----------------------------
	//    128   * 16 * 16 *   256   * 8[bit] = 67.108.864 = 64[Mb]	//ok
	// -----------------------------
	// #1[BLK] = #16[SEC]
	// #1[SEC] = #16[PAG]
	// #1[PAG] = #256[Byte]
	//
	//----------------------------------------------------------------------------
	//	Adr_H = Block  Address;
	//	Adr_M = Sector + Page Address;
	//	Adr_L = Byte  Address;
	//----------------------------------------------------------------------------
	//	H  M  L
	//	00 00 00
	//	BB SP bb
	//----------------------------------------------------------------------------
	//	WEL (bit 1 in Status Register):	Write Enable Latch... to set before erase/write
	//	WIP (bit 0 in Status Register):	Write in Progress...  to check after erase/write
	//----------------------------------------------------------------------------

	#if ( PGIM_EXTERNAL_MEMORY_TECNOLOGY == PG_TECNOLOGY_SPI )
		//---[ Global Declaration ]---
		_pg_Uint8 Adr_H;
		_pg_Uint8 Adr_M;
		_pg_Uint8 Adr_L;
		_pg_Uint8 pg_external_memory_page_buffer[ PGIM_EXTERNAL_MEMORY_PAGE_SIZE ];	//internal use
		//---[ End Global Declaration ]---
		
		
		//---[ Init ]---
		void pg_external_memory_init( void ) {
			//--------------------------------------------------
			PG_EXTERNAL_MEMORY_CS_TRIS		= PG_OUT;
			PG_SPI_SCK_TRIS					= PG_OUT;
			PG_SPI_SDO_TRIS					= PG_OUT;
			PG_SPI_SDI_TRIS					= PG_IN;
			//PG_SPI_SS_TRIS				= PG_IN;
			
			Adr_H = PGIM_EXTERNAL_MEMORY_FIRST_FREE_BLOCK;	//First available block for user's operations
			Adr_M = 0x00;									//Sector + Page
			Adr_L = 0x00;									//Byte
		}
		//---[ End Init ]---
		
				
		//---[ Set Address ]---
		_pg_Uint8 pg_external_memory_set_address( _pg_Uint8 Target , _pg_Uint8 New_Address ) {
			//--------------------------------------------------
			//     BLK     SC   PG     BYTE
			// |0000.0000|0000|0000|0000.0000|
			//--------------------------------------------------
			switch( Target ) {
				case PG_EXTERNAL_MEMORY_SET_ADDRESS_BLOCK : {
					// The first block #0 is system reserved for:
					// pg_external_memory_erase_page() and
					// pg_external_memory_overwrite_byte()
					#if ( PGIM_EXTERNAL_MEMORY_ADDRESSING_PROTECTED == PG_YES )
						if( New_Address < PGIM_EXTERNAL_MEMORY_FIRST_FREE_BLOCK ) {
							//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_BLOCK
							return( PG_NOK );
						}
					#endif
					Adr_H = New_Address;
					return( PG_OK );
				}
				case PG_EXTERNAL_MEMORY_SET_ADDRESS_SECTOR : {
					if ( New_Address > 0x0F ) {
						//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_SECTOR
						return ( PG_NOK );
					}
					Adr_M = ( ( New_Address << 4 ) + ( Adr_M & 0x0F ) );	//Adr_M = sssspppp ( s = sector; p = page )
					return( PG_OK );
				}
				case PG_EXTERNAL_MEMORY_SET_ADDRESS_PAGE : {
					if( New_Address > 0x0F ) {
						//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_PAGE
						return ( PG_NOK );
					}
					Adr_M = ( ( Adr_M & 0xF0 ) + New_Address );	//Adr_M = sssspppp
					return( PG_OK );
				}
				case PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE : {
					Adr_L = New_Address;
					return ( PG_OK );
				}
			}
			//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_UNDEFINED
			return( PG_NOK );
		}
		//---[ End Set Address ]---
		
		
		//---[ Set Address Full ]---
			_pg_Uint8 pg_external_memory_set_address_full( _pg_Uint8 N_Block , _pg_Uint8 N_Sector , _pg_Uint8 N_Page , _pg_Uint8 N_Byte ) {
			//--------------------------------------------------
			//     BLK     SC   PG     BYTE
			// |0000.0000|0000|0000|0000.0000|
			//--------------------------------------------------
			if( N_Block > PGIM_EXTERNAL_MEMORY_FIRST_FREE_BLOCK ) {
				//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_BLOCK
				return( PG_NOK );
			}
			if( N_Sector > 0x0F ) {
				//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_SECTOR
				return( PG_NOK );
			}
			if( N_Page > 0x0F ) {
				//todo: set error PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_PAGE
				return( PG_NOK );
			}
			Adr_H = N_Block;
			Adr_M = ( ( N_Sector << 4 ) + N_Page );	//Adr_M = sssspppp ( s = sector; p = page )
			Adr_L = N_Byte;
			//todo: set error
			return( PG_OK );
		}
		//---[ End Set Address Full ]---
		
		
		//---[ Write Page ]---
		_pg_Uint8 pg_external_memory_write_page( _pg_Uint8 * Buff_Pag_To_Write ) {
			//--------------------------------------------------
			//	AUTOERASE_NO
			//--------------------------------------------------
			//	Before write, page must be erased by:
			//	pg_external_memory_erase_page, or
			//	pg_external_memory_erase_sector, or
			//	pg_external_memory_erase_chip !
			//--------------------------------------------------
			_pg_Uint16 iwp0;	//do while _pg_Uint8...

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
				putcSPI( *( Buff_Pag_To_Write + (_pg_Uint8)iwp0 ) );
			}
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_external_memory_busy( PG_BLOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Write Page ]---


		//---[ Read Page ]---
		_pg_Uint8 pg_external_memory_read_page( _pg_Uint8 * Buff_Pag_To_Read ){
			//--------------------------------------------------
			_pg_Uint16 irp0;

			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( 0x00 );
			for( irp0 = 0; irp0 < PGIM_EXTERNAL_MEMORY_PAGE_SIZE; irp0++ ) {
				*( Buff_Pag_To_Read + (_pg_Uint8)irp0 ) = ReadSPI();
			}
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Read Page ]---
		
		
		//---[ Erase Page ]---
		#if ( PGIM_EXTERNAL_MEMORY_ADDRESSING_PROTECTED == PG_YES )
			_pg_Uint8 pg_external_memory_erase_page( void ) {
				//--------------------------------------------------
				//	pg_external_memory_page_buffer is shared,
				//	then it must be released free before return
				//--------------------------------------------------
				_pg_Uint8 idx_page;
				
				_pg_Uint8 save_Adr_H;
				_pg_Uint8 save_Adr_M;
				
				save_Adr_H = Adr_H;						//save original address
				save_Adr_M = Adr_M;
				
				Adr_H = 0x00;							//set to block #0 ( system reserved );
				Adr_M = 0x00;							//set to sector #0, page #0
				pg_external_memory_erase_sector( );	
				
				for( idx_page = 0; idx_page < 16; idx_page++ ) {		//copy sector: all #16 page of a actual sector to system sector #0
					Adr_H = save_Adr_H;					//Restore original address
					Adr_M = save_Adr_M;
					Adr_M &= 0xF0;						//reset page address
					Adr_M += idx_page;					//select idx_page page
					pg_external_memory_read_page( pg_external_memory_page_buffer );
					Adr_H = 0x00;						//go to temp system block
					Adr_M = 0x00;						//reset sector and page address
					Adr_M += idx_page;					//select idx_page page (only nibble on the right)
					pg_external_memory_write_page( pg_external_memory_page_buffer );		
				}
				
				Adr_H = save_Adr_H;						//restore original address
				Adr_M = save_Adr_M;
				pg_external_memory_erase_sector( );		//erase original sector
					
				for( idx_page = 0; idx_page < 16; idx_page++ ) {		//restore #15 (16-1) page original excluded
					Adr_H = 0x00;						//go to temp system block
					Adr_M = 0x00;						//reset sector and page address
					Adr_M += idx_page;					//select idx_page page (only nibble on the right)
					if( ( Adr_M & 0x0F ) != ( save_Adr_M & 0x0F ) ) {
						pg_external_memory_read_page( pg_external_memory_page_buffer );
						Adr_H = save_Adr_H;				//Restore original address
						Adr_M = save_Adr_M;
						Adr_M &= 0xF0;					//reset page address
						Adr_M += idx_page;				//select next page
						pg_external_memory_write_page( pg_external_memory_page_buffer );		
					}
				}
				Adr_H = save_Adr_H;						//Restore original address before return
				Adr_M = save_Adr_M;
				return( PG_DONE );
			}
		#endif
		//---[ END Erase Page ]---		
		
		
		//---[ Erase Sector ]---
 		_pg_Uint8 pg_external_memory_erase_sector( void ) {
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
			
			pg_external_memory_busy( PG_BLOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Erase Sector ]---

		
		//---[ Erase Block ]---
		_pg_Uint8 pg_external_memory_erase_block( void ) {
			//--------------------------------------------------
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_delay( 1 , PG_MSEC );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_BLOCK );
			putcSPI( Adr_H );
			putcSPI( 0x00 );
			putcSPI( 0x00 );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			pg_external_memory_busy( PG_BLOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Erase Block ]---


		//---[ Erase Chip  ]---
		_pg_Uint8 pg_external_memory_erase_chip( void ) {
			//--------------------------------------------------
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;	
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_delay( 1 , PG_MSEC );
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;	
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_ERASE_CHIP );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			pg_external_memory_busy( PG_BLOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Erase Chip  ]---

		
		//---[ Write Page ]---
		_pg_Uint8 pg_external_memory_write_byte( _pg_Uint8 Byte_To_Write ) {
			//--------------------------------------------------
			//	AUTOERASE_NO
			//--------------------------------------------------
			//	Before write, memory must be erased by:
			//	pg_external_memory_erase_page, or
			//	pg_external_memory_erase_sector, or
			//	pg_external_memory_erase_chip !
			//--------------------------------------------------
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
            PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_WRITE_PAGE );
			putcSPI( Adr_H );
			putcSPI( Adr_M );
			putcSPI( Adr_L );
			putcSPI( Byte_To_Write );
			PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			pg_external_memory_busy( PG_BLOCKING );
			pg_spi_close( PG_SPI_0 );
			return( PG_DONE );
		}
		//---[ END Write Page ]---


		//---[ Write Byte ]---	
		#if ( PGIM_EXTERNAL_MEMORY_ADDRESSING_PROTECTED == PG_YES )
			_pg_Uint8 pg_external_memory_overwrite_byte( _pg_Uint8 Byte_To_Write ) {
				//--------------------------------------------------
				//	AUTOERASE_YES
				//--------------------------------------------------
				//	pg_external_memory_page_buffer is shared,
				//	then it must be released free before return
				//--------------------------------------------------
				_pg_Uint8 idx_page;
				
				_pg_Uint8 save_Adr_H;
				_pg_Uint8 save_Adr_M;
				
				save_Adr_H = Adr_H;						//save original address
				save_Adr_M = Adr_M;
				
				pg_external_memory_read_page( pg_external_memory_page_buffer );
				pg_external_memory_page_buffer[ Adr_L ] = Byte_To_Write;
				//free pg_external_memory_page_buffer saving it in system reserved "00 01 xx" (BB SP bb)
				Adr_H = 0x00;							//set to block #0 ( system reserved );
				Adr_M = 0x10;							//set to sector #0, page #1
				pg_external_memory_erase_sector();
				pg_external_memory_write_page( pg_external_memory_page_buffer );
				Adr_H = save_Adr_H;						//set original address
				Adr_M = save_Adr_M;
				pg_external_memory_erase_page( );		//"pg_external_memory_page_buffer" wil be destroied!
				Adr_H = 0x00;							//set to block #0 ( system reserved );
				Adr_M = 0x10;							//set to sector #0, page #1
				pg_external_memory_read_page( pg_external_memory_page_buffer );
				Adr_H = save_Adr_H;						//set original address
				Adr_M = save_Adr_M;
				pg_external_memory_write_page( pg_external_memory_page_buffer );
				// Adr_H = save_Adr_H;					//Restore original address before return
				// Adr_M = save_Adr_M;

				#if ( PGIM_EXTERNAL_MEMORY_WRITE_BYTE_VERIFY == PG_ENABLE )
					if( Byte_To_Write == pg_external_memory_read_byte( ) ) {
					//todo: set error 
					return( PG_OK );
					}
					else {
						//todo: set error 
						return( PG_NOK );
					}
				#endif
				return( PG_DONE );
			#endif
		}
		//---[ END Write Byte ]---
		
		
		//---[ Read Byte ]---
		_pg_Uint8 pg_external_memory_read_byte( void ) {
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
			//todo: set error 
			return( Byte_To_Read );
		}
		//---[ END Read Byte ]---

		
		//---[ Wait Busy Check ]---
		_pg_Uint8 pg_external_memory_busy( _pg_Uint8 Blocking ) {
			//--------------------------------------------------
			// Blocking		---> Blocking = PG_LOCKING			( Wait until no more busy, and return status PG_BUSY || PG_READY )
			// NON Blocking ---> Blocking = PG_NOT_LOCKING		( No wait and returns busy status PG_BUSY || PG_READY )
			// Device can be busy only on Program/Erase/Write access
			//--------------------------------------------------
			_pg_Uint8 Wip_Temp;
			
			pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			PG_EXTERNAL_MEMORY_CS = PG_LOW;
			putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_STATUS_REG );
			
			do {
				Wip_Temp = ReadSPI();
				Wip_Temp &= 0b00000001;				// Waiting and checking for WIP bit of Status-Register: 1 = busy, 0 = idle
				if ( Blocking == PG_NOT_BLOCKING ) {
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





















		// _pg_Uint8 pg_external_memory_overwrite_byte( _pg_Uint8 Byte_To_Write ) {
			// //--------------------------------------------------
			// pg_external_memory_read_page( pg_external_memory_page_buffer );
			// pg_external_memory_page_buffer[ Adr_L ] = Byte_To_Write;
			// //--------------------------------------------------
			// // Before write a page, must erase sector => save sector, no page...
			// //--------------------------------------------------
			// pg_external_memory_erase_sector( );
			// pg_external_memory_write_page( pg_external_memory_page_buffer );

			// if ( ( Verify_W == PG_VERIFY ) && ( Byte_To_Write == pg_external_memory_read_byte( ) ) ) {
				// //todo: set error 
				// return( PG_OK );
			// }
			// else {
				// //todo: set error 
				// return( PG_NOK );	//correggere se no verify
			// }
		// }
		// //---[ END Write Byte ]---
		
		
		// //---[ Read Byte ]---
		// _pg_Uint8 pg_external_memory_read_byte( void ) {
			// //--------------------------------------------------
			// _pg_Uint8 Byte_To_Read;

			// pg_spi_open( PG_SPI_0, PG_SPI_MASTER_FOSC_64, MODE_00, SMPEND );
			
			// PG_EXTERNAL_MEMORY_CS = PG_LOW;
			// putcSPI( PG_EXTERNAL_MEMORY_COMMAND_READ_DATA );
			// putcSPI( Adr_H );
			// putcSPI( Adr_M );
			// putcSPI( Adr_L );
			// Byte_To_Read = ReadSPI();
			// PG_EXTERNAL_MEMORY_CS = PG_HIGH;
			
			// pg_spi_close( PG_SPI_0 );
			// //todo: set error 
			// return( Byte_To_Read );
		// }
		// //---[ END Read Byte ]---
		
		
		