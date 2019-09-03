//
#include "picgim.h"

#if ( PGIM_FLASH == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	//--------------------------------------------------------------------------
	// Read from program memory are performed one byte at a time.
	// Programming and erasing are performed by block, i.e. 32 word or 64 bytes.
	// See device manual for block size and define them in .h.
	// Istruction must be aligned (odd and even) to word, no matters for data.
	//--------------------------------------------------------------------------
	
	//---[ Set Table Pointer Flash ]---
	void pg_flash_set_table_pointer( _pg_Uint32 pg_ptr_address ) {
		//--------------------------------------------------------------------------
		_pg_Uint32_VAL	address;
		
		address.Val = pg_ptr_address;
		
		TBLPTRU	= address.byte.UB;			// Set Table Pointer Address, UPPER Byte
		TBLPTRH	= address.byte.HB;			// Set Table Pointer Address, HIGHER Byte
		TBLPTRL	= address.byte.LB;			// Set Table Pointer Address, LOWER Byte
	}
	
	//---[ Execute Flash ]---
	void pg_flash_execute( void ) {
		//--------------------------------------------------------------------------
		_pg_Uint8	flag_irq;
		
		flag_irq = 0;
		
		EECON1bits.EEPGD = 1;				// Point to flash program memory
		EECON1bits.CFGS = 0;       			// Access flash program memory
		EECON1bits.WREN = 1;				// Enable write to memory
		if( INTCONbits.GIE ) {				// Disable IRQ, if enabled
			INTCONbits.GIE = 0;
			flag_irq = 0x01;
		}
		EECON2 = 0x55;						// Required sequence
		EECON2 = 0xAA;						// Required sequence
		EECON1bits.WR = 1;					// Start erase (CPU stall) (Required sequence end)
		if( flag_irq ) {					// Restore IRQ, if enabled
			INTCONbits.GIE = 1;
			flag_irq = 0x00;
		}
	}
	
	//---[ Read Flash ]---
	void pg_flash_read( _pg_Uint32 pg_address_start , _pg_Uint32 pg_byte_number , _pg_Uint8 * pg_buffer_read ) {
		//--------------------------------------------------------------------------
		_pg_Uint32	n;
		
		pg_flash_set_table_pointer( pg_address_start );
		for( n = 0 ; n < pg_byte_number ; n++ ) {
			_asm TBLRDPOSTINC _endasm
			*( pg_buffer_read + n ) = TABLAT;
		}
	}

	//---[ Erase Flash ]---
	void pg_flash_erase( _pg_Uint32 pg_address_start , _pg_Uint16 pg_erase_block_number ) {
		//--------------------------------------------------------------------------
		_pg_Uint16	n;
		
		for( n = 0 ; n < pg_erase_block_number ; n++ ) {
			pg_flash_set_table_pointer( pg_address_start + ( PG_FLASH_SIZE_ERASE_BLOCK * n ) );
			EECON1bits.FREE = 1;			// Enable block Erase operation
			pg_flash_execute( );
		}
	}

	//---[ Write Block Flash ]---
	void pg_flash_write_block( _pg_Uint32 pg_address_start , _pg_Uint16 pg_write_block_number , _pg_Uint8 * pg_buffer_write ) {
		//--------------------------------------------------------------------------
		_pg_Uint16	n;
		_pg_Uint8	holding_reg;
		
		for( n = 0 ; n < pg_write_block_number ; n++ ) {
			pg_flash_set_table_pointer( pg_address_start + ( PG_FLASH_SIZE_WRITE_BLOCK * n ) );
			holding_reg = PG_FLASH_SIZE_WRITE_BLOCK;
			while( holding_reg-- ) {		// Fill holding registers
				TABLAT = *( pg_buffer_write++ );
				_asm TBLWTPOSTINC _endasm
			}
			_asm TBLRDPOSTDEC _endasm		// tblptr - 1 to return in the right block
			pg_flash_execute( );
			//############################################################################################
			//############################################################################################
			//pg_buffer_write -= PG_FLASH_SIZE_WRITE_BLOCK;			//2rm only for debug!!!!!!!!!!!!!!!!!!
			//############################################################################################
			//############################################################################################
		}
	}

	//---[ Write Word Flash ]---
	void pg_flash_write_word( _pg_Uint32 pg_address_word , _pg_Uint16 pg_data ) {
		//--------------------------------------------------------------------------
		_pg_Uint16_VAL	data;
		
		data.Val = pg_data;
		
		pg_flash_set_table_pointer( pg_address_word );
		TABLAT = data.byte.LB;
		_asm TBLWTPOSTINC _endasm			// Store low byte
		TABLAT = data.byte.HB;
		_asm TBLWT _endasm					// Store high byte
		pg_flash_execute( );
	}

	//todo:	write ID loc https://microchipdeveloper.com/faq:35

#endif
 
 
