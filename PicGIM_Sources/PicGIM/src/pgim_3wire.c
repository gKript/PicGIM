//
// pgim_3wire.c
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

/*!		\file			pgim_3wire.c
		\version		0.6-0
		\date			2002 - 2016
		\brief			Simple 3-wire serial protocol
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_3WIRE == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif
	
	void	pg_3wire_init( void ) {
		PG_3WIRE_IO 			= PG_LOW;
		PG_3WIRE_CK 			= PG_LOW;
		PG_3WIRE_IO_TRIS		= PG_OUT;
		PG_3WIRE_CK_TRIS		= PG_OUT;
	}
	
	
	void	pg_3wire_wr_byte( _pg_Uint8 wr_byte ) {
		_pg_Uint8	cycle;
		
		for( cycle = 0; cycle < 8; cycle++ ) {
			PG_3WIRE_IO = PG_LOW;
			
			#if ( PG_3WIRE_DIRECTION_OUTPUT == PG_MSB_FIRST )
				if( wr_byte & 0b10000000 )
					PG_3WIRE_IO = PG_HIGH;
				wr_byte = wr_byte << 1;
			#endif			
			#if ( PG_3WIRE_DIRECTION_OUTPUT == PG_LSB_FIRST )
				if( wr_byte & 0b00000001 )
					PG_3WIRE_IO = PG_HIGH;
				wr_byte = wr_byte >> 1;
			#endif
			
			PG_3WIRE_CK = PG_HIGH;
			pg_delay( 1, PG_USEC );
			PG_3WIRE_CK = PG_LOW;
		}
	}
	

	_pg_Uint8	pg_3wire_rd_byte( void ) {
		_pg_Uint8	rd_byte;
		_pg_Uint8	cycle;
		
		rd_byte = 0x00;
		
		//The first bit of data to be received is already present
		//and is available from the falling edge of the last clock pulse of the command just sent
		PG_3WIRE_IO_TRIS = PG_IN;		
		for( cycle = 0; cycle < 8; cycle++ ) {

			pg_delay( 1, PG_USEC );
			#if ( PG_3WIRE_DIRECTION_INPUT == PG_LSB_FIRST )
				rd_byte = rd_byte >> 1;
				if( PG_3WIRE_IO_PORT )
					rd_byte = rd_byte | 0b10000000;
			#endif
			#if ( PG_3WIRE_DIRECTION_INPUT == PG_MSB_FIRST )
				rd_byte = rd_byte << 1;
				if( PGIM_3WIRE_IO_PORT )
					rd_byte = rd_byte | 0b00000001;
			#endif
			
			PG_3WIRE_CK = PG_HIGH;
			pg_delay( 1, PG_USEC );
			PG_3WIRE_CK = PG_LOW;
		}
		PG_3WIRE_IO_TRIS = PG_OUT;
		return( rd_byte );
	}
	
#endif


