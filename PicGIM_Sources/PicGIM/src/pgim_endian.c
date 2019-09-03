//
#include "picgim.h"

#if ( PGIM_ENDIAN == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	//---[ Endian 8 - Byte ]---
	_pg_Uint8 pg_endian_byte( _pg_Uint8 pg_byte ) {
		//--------------------------------------------------------------------------
		return( ( ( pg_byte << 4 ) & 0xF0 ) | ( ( pg_byte >> 4 ) & 0x0F ) );
	}

	//---[ Endian 16 - Word ]---
	_pg_Uint16 pg_endian_word( _pg_Uint16 pg_word ) {
		//--------------------------------------------------------------------------
		return( ( ( pg_word << 8 ) & 0xFF00 ) | ( ( pg_word >> 8 ) & 0x00FF ) );
	}
	
	//---[ Endian 24 - ShortLong ]---
	_pg_Uint24 pg_endian_24( _pg_Uint24 pg_shortlong ) {
		//--------------------------------------------------------------------------
		return( ( ( pg_shortlong << 16 ) & 0xFF0000 ) | ( ( pg_shortlong >> 16 ) & 0x0000FF ));
	}

	//---[ Endian 32 - Double Word ]---
	_pg_Uint32 pg_endian_double_word( _pg_Uint32 pg_double_word ) {
		//--------------------------------------------------------------------------
		return( ( ( pg_double_word << 24 ) & 0xFF000000 ) | ( ( pg_double_word >> 24 ) & 0x000000FF ) |
				( ( pg_double_word <<  8 ) & 0x00FF0000 ) | ( ( pg_double_word >>  8 ) & 0x0000FF00 ) );
	}

#endif
 
 
