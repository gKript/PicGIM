/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_timer.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_3wire.h

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2015  gKript.org - We.PIC project - <http://www.gkript.org>

		This program is free software: you can redistribute it and/or modify
		it under the terms of the GNU General Public License as published by
		the Free Software Foundation, either version 3 of the License, or
		(at your option) any later version.

		This program is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
		GNU General Public License for more details.

		You should have received a copy of the GNU General Public License
		along with this program.  If not, see <http://www.gnu.org/licenses/>.

	END LICENSE
 */

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
		//---[ Init ]---------------------------------------------------------
		PG_3WIRE_IO 			= PG_LOW;
		PG_3WIRE_CK 			= PG_LOW;
		PG_3WIRE_IO_TRIS		= PG_IN; //Set IN as default
		PG_3WIRE_CK_TRIS		= PG_OUT; //Always OUT
	}
	
	
	void	pg_3wire_wr_byte( _pg_Uint8 wr_byte ) {
		//---[ Write BYTE ]---------------------------------------------------
		_pg_Uint8	cycle;
		for( cycle = 0; cycle < 8; cycle++ ) {
			PG_3WIRE_IO = PG_LOW;
			PG_3WIRE_IO_TRIS = PG_OUT; //Set again data tris out every cycle, because before the clock falling edge data tris must be set as IN
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
			PG_3WIRE_CK = PG_HIGH; //Data is written here with clock rising edge
			pg_delay( 1, PG_USEC );
			PG_3WIRE_IO_TRIS = PG_IN; //Set data tris IN, because for a reading command, the data is immediately ready on the falling edge of last cycle (bit7)
			PG_3WIRE_CK = PG_LOW; //On the last bit (bit7), first data bit is pushed out now, ready for reading
		}
	}
	

	_pg_Uint8	pg_3wire_rd_byte( void ) {
		//---[ Read BYTE ]----------------------------------------------------
		_pg_Uint8	rd_byte;
		_pg_Uint8	cycle;
		rd_byte = 0x00;
		//The first bit of data to be received is already present
		//and is available from the falling edge of the last clock pulse of the command just sent
		PG_3WIRE_IO_TRIS = PG_IN; // It should already be set IN by write function or by default...
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
		return( rd_byte );
	}
	
#endif


