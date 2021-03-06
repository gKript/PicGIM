//
// pgim_external_memory.h
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

/*!		\file			pgim_external_memory.h
		\version		0.6-0
		\date			2002 - 2018
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_EXTERNAL_MEMORY_SETUP_H_
	#define _PGIM_EXTERNAL_MEMORY_SETUP_H_

	#if ( PGIM_EXTERNAL_MEMORY == PG_ENABLE )
		#define	PG_MX25L6406										1
		
		#define	PG_TECNOLOGY_SPI									1
		#define	PG_TECNOLOGY_I2C									2

		//---[ Error ]---
		#define PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_BLOCK		1
		#define PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_SECTOR		2
		#define PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_PAGE			3
		//#define PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_BYTE		4
		#define PG_EXTERNAL_MEMORY_ERROR_WRONG_ADDRESS_UNDEFINED	99
		//---[ End Error ]---
		
		#if ( PGIM_EXTERNAL_MEMORY_TYPE == PG_MX25L6406 )
		
			//---[ Device Parameter ]---
			#define PGIM_EXTERNAL_MEMORY_CHIP_SIZE					8388608				// [ Byte ]; 67108864[ bit ]
			#define PGIM_EXTERNAL_MEMORY_BLOCK_SIZE					65536				// [ Byte ]
			#define PGIM_EXTERNAL_MEMORY_SECTOR_SIZE				4096				// [ Byte ]
			#define PGIM_EXTERNAL_MEMORY_PAGE_SIZE					256					// [ Byte ]	//!< Currently. this value can not change.
			//---[ End Device Parameter ]---

			//---[ Command ]---
			#define	PG_EXTERNAL_MEMORY_COMMAND_WRITE_PAGE	 		0x02
			#define	PG_EXTERNAL_MEMORY_COMMAND_READ_DATA			0x03
			#define	PG_EXTERNAL_MEMORY_COMMAND_READ_STATUS_REG		0x05
			#define	PG_EXTERNAL_MEMORY_COMMAND_WRITE_ENABLE 		0x06
			#define	PG_EXTERNAL_MEMORY_COMMAND_WRITE_DISABLE 		0x04
			#define	PG_EXTERNAL_MEMORY_COMMAND_ERASE_SECTOR 		0x20
			#define PG_EXTERNAL_MEMORY_COMMAND_ERASE_BLOCK			0x52
			#define	PG_EXTERNAL_MEMORY_COMMAND_ERASE_CHIP	 		0x60
			//---[ End Command ]---
			
		#endif
		
		//---[ Address Target ]---
		#define	PG_EXTERNAL_MEMORY_SET_ADDRESS_BLOCK				1
		#define	PG_EXTERNAL_MEMORY_SET_ADDRESS_SECTOR				2
		#define	PG_EXTERNAL_MEMORY_SET_ADDRESS_PAGE					3
		#define	PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE					4
		//---[ End Address Target ]---
		
		//---[ System Block Protection ]---
		// Block #0 reserved for system operation
		#define PGIM_EXTERNAL_MEMORY_FIRST_FREE_BLOCK				0x01	//e.i.: '0x03' = ( Block locked until #2 included, or rather #0, #1 and #2; First available block #3 )
		//---[ End System Block Protection ]---
		
		//---[ Prototype ]---
		extern _pg_Uint8 Adr_H;
		extern _pg_Uint8 Adr_M;
		extern _pg_Uint8 Adr_L;
		
		_pg_Uint8		pg_external_memory_set_address				( _pg_Uint8 Target , _pg_Uint8 New_Address );
		_pg_Uint8		pg_external_memory_set_address_full			( _pg_Uint8 N_Block , _pg_Uint8 N_Sector , _pg_Uint8 N_Page , _pg_Uint8 N_Byte );
		_pg_Uint8		pg_external_memory_erase_chip				( void );											//Need no address.
		_pg_Uint8		pg_external_memory_erase_block				( void ); 											//Need address of: block.
		_pg_Uint8		pg_external_memory_erase_sector				( void );											//Need address of: block, sector.
		_pg_Uint8		pg_external_memory_erase_page				( void );
		_pg_Uint8		pg_external_memory_read_page				( _pg_Uint8 * Buff_Pag_To_Read );					//Need address of: block, sector, page.
		_pg_Uint8		pg_external_memory_write_page				( _pg_Uint8 * Buff_Pag_To_Write );	//AUTOERASE_NO	//Need address of: block, sector, page.
		_pg_Uint8		pg_external_memory_read_byte				( void );											//Need address of: block, sector, page, byte.
		_pg_Uint8		pg_external_memory_write_byte				( _pg_Uint8 Byte_To_Write ); 		//AUTOERASE_NO	//Need address of: block, sector, page, byte.	
		//_pg_Uint8		pg_external_memory_write_byte_auto			( _pg_Uint8 Byte_To_Write ); 						//Need address of: block, sector, page, byte; mem must cleared; auto-increment full address
		_pg_Uint8		pg_external_memory_overwrite_byte			( _pg_Uint8 Byte_To_Write ); 		//AUTOERASE_YES	//Need address of: block, sector, page, byte. 	
		//_pg_Uint8		pg_external_memory_read_string				(  );
		//_pg_Uint8		pg_external_memory_write_string				(  );
		//_pg_Uint8		pg_external_memory_read_buffer				(  );
		//_pg_Uint8		pg_external_memory_write_buffer				(  );
		_pg_Uint8		pg_external_memory_busy						( _pg_Uint8 Blocking ); 							// Blocking = PG_BLOCKING || PG_NOT_BLOCKING
		//_pg_Uint8		pg_external_memory_get_address				( _pg_Uint8 Target );
		//_pg_Uint24	pg_external_memory_get_full_address			( void );
		//---[ End Prototype ]---
	#endif
#endif /* _PGIM_EXTERNAL_MEMORY_H_ */

/*
	\page 		HWE_ext_mem			Serial memory
	\attention	Here a link to the file : \ref pgim_external_memory.h \n This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/



