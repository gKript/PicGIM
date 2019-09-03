//

#ifndef _PGIM_ENDIAN_H_
	#define _PGIM_ENDIAN_H_

	#if ( PGIM_ENDIAN == PG_ENABLE )
			
		_pg_Uint8 	pg_endian_byte				( _pg_Uint8  pg_byte );
		_pg_Uint16 	pg_endian_word				( _pg_Uint16 pg_word );
		_pg_Uint24 	pg_endian_24				( _pg_Uint24 pg_shortlong );
		_pg_Uint32 	pg_endian_double_word		( _pg_Uint32 pg_double_word );
		
	#endif
#endif


