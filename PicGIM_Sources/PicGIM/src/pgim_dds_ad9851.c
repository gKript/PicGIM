/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_dds_ad9851.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_dds_ad9851.h

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

 /*!
		\file		pgim_dds_ad9851.c
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the AD9851 DDS device.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#include "picgim.h"

#if ( PGIM_DDS_AD9851 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
		
	void pg_dds_ad9851_init( void ) {
		//---[ Init ]---------------------------------------------------------
		//tris
		#if ( PG_DDS_AD9851_DATA_MODE == PG_SERIAL )
			PG_DDS_AD9851_SERIAL_DATA_TRIS	= PG_OUT;
		#endif
		#if ( PG_DDS_AD9851_DATA_MODE == PG_PARALLEL )
			PG_DDS_AD9851_DATABUS_TRIS		= PG_OUT;
		#endif
		PG_DDS_AD9851_WORD_CLOCK_TRIS		= PG_OUT;
		PG_DDS_AD9851_FREQ_UPDATE_TRIS		= PG_OUT;
		PG_DDS_AD9851_RESET_TRIS			= PG_OUT;

		//lat
		#if ( PG_DDS_AD9851_DATA_MODE == PG_SERIAL )
			PG_DDS_AD9851_SERIAL_DATA		= PG_LOW;
		#endif
		#if ( PG_DDS_AD9851_DATA_MODE == PG_PARALLEL )
			PG_DDS_AD9851_DATABUS			= PG_LOW;
		#endif
		PG_DDS_AD9851_WORD_CLOCK			= PG_LOW;	//active high on rising edge
		PG_DDS_AD9851_FREQ_UPDATE			= PG_LOW;	//active high on rising edge
		PG_DDS_AD9851_RESET					= PG_LOW;	//active high on rising edge
		
		//reset	(it does NOT overwrite frequency word (undefined at startup)
		pg_dds_ad9851_reset( );
		
		//serial mode (immediately after reset)
		#if ( PG_DDS_AD9851_DATA_MODE == PG_SERIAL )
			// to enable serial mode make:
			// sw || hw pull-up on AD9851 pin#3 "D1=Logic0(*)/SetSerialMode" by 10[Kohm] (needed and readen only at init sequence to enter in serial mode)
			// to enable multiplier make:
			// sw || hw pull-up on AD9851 pin#4 "D0=6xRefClock" by 10[Kohm] (needed and readen only at init sequence; at next word write, it will be sent in serial mode)
			// to disable power-down:
			// sw || hw pull-down on AD9851 pin#2 "D2" (needed and readen only at init sequence; at next word write, it will be sent in serial mode)
			pg_dds_ad9851_word_clock( );	//load in default parallel mode only the first byte 'xxxxx011' to: (1)disable power-down; (2)enable serial mode; (3) enable multiplier;
			pg_dds_ad9851_freq_update( );
		#endif
		
		pg_dds_ad9851_set_freq( 0.0 );		//send a valid frequency word (undefined at startup)
		#if ( PG_DDS_AD9851_INIT_FREQ != 0.0 )
			pg_dds_ad9851_set_freq( PG_DDS_AD9851_INIT_FREQ );
		#endif
	}

	void pg_dds_ad9851_set_freq( float dds_fout ) {
		//---[ Set Frequency ]---------------------------------------------------------
		_pg_Uint8 	c;
		_pg_Uint8 	word[ 5 ];
		float 		dds_clock		= PG_DDS_AD9851_CLOCK_REF;
		float 		dds_res			= 4294967296.0;	//2^32 = 0xFFFFFFFF = 0b11111111111111111111111111111111
		float 		dds_coef		= 0.0;			//multiplication coefficient ( word = dds_coef * dds_out )
		_pg_Uint32 	dds_fword		= 0x00000000;	//#4 byte, only data frequency						
		_pg_Uint32 	dds_fword_temp	= 0x00000000;
		
		//multiplier
		#if ( PG_DDS_AD9851_MULTIPLIER == PG_ENABLE )
			dds_clock = PG_DDS_AD9851_CLOCK_REF * 6;	//i.e.: 180MHz = 30MHz(ext. osc) x 6 (PLL)
		#endif
		
		//frequency word computation
		dds_coef = dds_res / dds_clock;					//dds_coef needs high resolution!
		dds_fword = (_pg_Uint32)dds_fout * dds_coef;	//now, dds_fword contains 32bit frequency data
		
		word[ 0 ] = 0b00000001;							//bit<0>(1=multiplier enabled); bit<1>=0(always); bit<2>(1=powerdown enabled); bit<3-7>(phase)
		dds_fword_temp = dds_fword;
		
		//parallel mode
		#if ( PG_DDS_AD9851_DATA_MODE == PG_PARALLEL )		
			//#4 byte divide "word" vector, masking "dds_fword"
			word[ 4 ] = (_pg_Uint32)(0x000000FF & dds_fword_temp);	//extracting first byte (LSB)	//0b00000000000000000000000011111111
			dds_fword_temp = dds_fword_temp >> 8;
			word[ 3 ] = (_pg_Uint32)(0x000000FF & dds_fword_temp);	//extracting second byte
			dds_fword_temp = dds_fword_temp >> 8;
			word[ 2 ] = (_pg_Uint32)(0x000000FF & dds_fword_temp);	//extracting third byte
			dds_fword_temp = dds_fword_temp >> 8;
			word[ 1 ] = (_pg_Uint32)(0x000000FF & dds_fword_temp);	//extracting fourth (MSB)
			
			//send complete programming word (5 byte = 40bit)
			for( c = 0; c < 5; c++ ) {
				LATD = word[ c ];				
				pg_dds_ad9851_word_clock( );
			}
		#endif
		
		//serial mode
		#if ( PG_DDS_AD9851_DATA_MODE == PG_SERIAL )
			for( c = 0; c < 32; c++ ) {
				PG_DDS_AD9851_SERIAL_DATA = ( dds_fword_temp & 0x00000001 );						//0b00000000000000000000000000000001
				dds_fword_temp = dds_fword_temp >> 1;
				pg_dds_ad9851_word_clock( );
			}
			for( c = 0; c < 8; c++ ) {
				PG_DDS_AD9851_SERIAL_DATA = ( word[ 0 ] & 0b00000001 );
				word[ 0 ] = word[ 0 ] >> 1;
				pg_dds_ad9851_word_clock( );
			}
		#endif
		
		//frequency update
		pg_dds_ad9851_freq_update( );
	}

	void pg_dds_ad9851_sweep_ss( float f_start, float f_stop, float f_step, _pg_Uint16 step_delay ) {
		//---[ Sweep (Start-Stop) ]---------------------------------------------------------
		// f_start		= start frequency [Hz]
		// f_stop		= stop frequency [Hz]
		// f_step		= frequency increase every step [Hz]
		// step_delay	= delay between sweep step (1-65535[ms])
		//----------------------------------------------------------------------------------
		float f = 0.0;

		if( f_start == f_stop ) {
			pg_dds_ad9851_set_freq( f_start );
		}
		else if( f_start < f_stop ) {
			for( f = f_start; f < ( f_stop + f_step ); f = f + f_step ) {
				pg_dds_ad9851_set_freq( f );
				if( step_delay > 0 )
					pg_delay( step_delay , PG_MSEC );
			}
		}
		else {	 // (f_start > f_stop )
			for( f = f_start; f > ( f_stop - f_step ); f = f - f_step ) {
				pg_dds_ad9851_set_freq( f );
				if( step_delay > 0 )
					pg_delay( step_delay , PG_MSEC );
			}
		}
	}

	void pg_dds_ad9851_sweep_cs( float f_center, float f_span, float f_step, _pg_Uint8 direction , _pg_Uint16 step_delay ) {
		//---[ Sweep (Center-Span) ]---------------------------------------------------------
		//f_center		= central frequency [Hz]
		//f_span		= sweep width [Hz]
		//f_step		= sweep step [Hz]
		//step_delay	= delay between sweep step (1-65535[ms])
		//----------------------------------------------------------------------------------
		if( direction == PG_FORWARD ) {
			pg_dds_ad9851_sweep_ss( ( f_center - ( f_span / 2 ) ) , ( f_center + ( f_span / 2 ) ) , f_step , step_delay );
		}
		if( direction == PG_REVERSE ) {
			pg_dds_ad9851_sweep_ss( ( f_center + ( f_span / 2 ) ) , ( f_center - ( f_span / 2 ) ) , f_step , step_delay );
		}
	}
		
	void pg_dds_ad9851_reset( void ) {
	//---[ Reset ]---------------------------------------------------------
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_RESET = PG_HIGH;					//active high on rising edge
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_RESET = PG_LOW;
		pg_delay( 1 , PG_USEC );
	}

	void pg_dds_ad9851_word_clock( void ) {
	//---[ Word Clock ]---------------------------------------------------------	
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_WORD_CLOCK = PG_HIGH;				//active high on rising edge
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_WORD_CLOCK = PG_LOW;
		pg_delay( 1 , PG_USEC );
	}
	
	void pg_dds_ad9851_freq_update( void ) {
	//---[ Frequency Update ]---------------------------------------------------------	
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_FREQ_UPDATE = PG_HIGH;			//active high on rising edge
		pg_delay( 1 , PG_USEC );
		PG_DDS_AD9851_FREQ_UPDATE = PG_LOW;
		pg_delay( 1 , PG_USEC );
	}
	
#endif


