//

#ifndef _PGIM_FLASH_H_
	#define _PGIM_FLASH_H_

	#if ( PGIM_FLASH == PG_ENABLE )
			
		// sono nel .h del processore
		// extern volatile near unsigned char       	TABLAT;
		// extern volatile near unsigned short long 	TBLPTR;
		// extern volatile near unsigned char       	TBLPTRL;
		// extern volatile near unsigned char       	TBLPTRH;
		// extern volatile near unsigned char       	TBLPTRU;
	
		void	pg_flash_execute					( void );
		void	pg_flash_set_table_pointer			( _pg_Uint32 pg_ptr_address );
		void	pg_flash_read						( _pg_Uint32 pg_address_start, _pg_Uint32 pg_byte_number, _pg_Uint8 *pg_buffer_read );
		void	pg_flash_erase						( _pg_Uint32 pg_address_start, _pg_Uint16 pg_erase_block_number );
		void	pg_flash_write_word					( _pg_Uint32 pg_address_word, _pg_Uint16 pg_data );
		void	pg_flash_write_block				( _pg_Uint32 pg_address_start, _pg_Uint16 pg_write_block_number, _pg_Uint8 * pg_buffer_write );
		
	#endif
#endif


