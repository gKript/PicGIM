//
// pgim_buzzer.c
//
// picGim  -  Generic Information Manager for Pic 18 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002, 2011 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of picGim library.

	picGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	picGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, PG_WRITE to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

#include "../include/pgim_includes.h"
#include "../include/pgim_sblcd_master.h"


#ifdef	PGIM_SBLCD_MASTER

	#include "../include/pgim_caldelay.h"
	
	void pg_generic_Str2Ram( static _pg_int8 *dest , static _pg_int8 rom *src ) {
		while ((*dest++ = *src++) != '\0') ;
	}

	
	void	pg_sblcd_mv1_Init( void ) {
		TRIS_M_SBLCD_ERROR	= PG_IN;
		TRIS_M_SBLCD_BUSY		= PG_IN;
		TRIS_M_SBLCD_CLK		= PG_OUT;
		TRIS_M_SBLCD_DATA		= PG_OUT;
		TRIS_M_SBLCD_EN			= PG_OUT;
		M_SBLCD_EN				= 0;
		M_SBLCD_DATA			= 0;
		M_SBLCD_CLK				= 0;
		pg_sblcd_mv1_SendCommand(	SBLCD_COMM_RESET );
		pg_sblcd_v1_WaitBusyUp();
		pg_delay_Sec( 1 );
		pg_sblcd_mv1_SendCommand(	SBLCD_COMM_TESTERROR );
		pg_delay_Sec( 1 );
		pg_sblcd_mv1_SendCommand(	SBLCD_COMM_RESERROR );
	}

	
	void pg_sblcd_mv1_ClkPulse() {
		M_SBLCD_CLK = 1;
		Delay100TCYx(25);
		M_SBLCD_CLK = 0;
	}

	
	void pg_sblcd_mv1_WaitBusyDown() {
		while ( M_SBLCD_BUSY );
//			Nop();
	}

	
	void pg_sblcd_mv1_WaitBusyUp() {
		while ( ! M_SBLCD_BUSY );
//			Nop();
	}


	void pg_sblcd_mv1_Delay( void ) {
//		Delay10KTCYx(15);
		pg_delay_mSec( 1 );
	}


	_pg_int8	pg_sblcd_mv1_Puts( rom _pg_int8 * to_lcd ) {
		_pg_int8 strbuffer[50];
		_pg_int16 i;	
		strcpypgm2ram( strbuffer, to_lcd );
		for( i = 0 ; i < strlen( strbuffer ) ; i++ )
			pg_sblcd_mv1_SendData( strbuffer[i] );
		return 1;
	}

	_pg_int8	pg_sblcd_mv1_ClrRow( _pg_Uint8 row ) {
		_pg_int8 i;
		if ( row != SBLCD_COMM_CLR_CURR )
			pg_sblcd_mv1_SendCommand(	row );
		for( i = 0 ; i < 40 ; i++ )
			pg_sblcd_mv1_SendData( ' ' );
		return 1;
	}



	_pg_int8	pg_sblcd_mv1_PutsRam( _pg_int8 * to_lcd ) {
		_pg_int16 i;
		for( i = 0 ; i < strlen( to_lcd ) ; i++ )
			pg_sblcd_mv1_SendData( to_lcd[i] );
		return 1;
	}

	_pg_int8 pg_sblcd_mv1_SendData( _pg_Uint8 to_send ) {
		_pg_Uint8 tmp;
		_pg_int16 loop;
		tmp = to_send; 
		pg_sblcd_v1_WaitBusyDown();
		M_SBLCD_EN   = 1;
		M_SBLCD_DATA = 1;	//	1  = data
		sblcd_clk_pulse();
		sblcd_delay();
		for ( loop = 0 ; loop < 8 ; loop++ ) {
			tmp = to_send;
			tmp >>= loop;
			tmp &= 0b00000001;
			if ( tmp )
				M_SBLCD_DATA = 1;
			else
				M_SBLCD_DATA = 0;
			sblcd_delay();
			sblcd_clk_pulse();
		}
		M_SBLCD_DATA = 0;
		M_SBLCD_EN   = 0;
		sblcd_delay();
	}


	void pg_sblcd_mv1_SendCommand( _pg_Uint8 to_send ) {
		_pg_Uint8 tmp;
		_pg_int16 loop;
		tmp = to_send;
		pg_sblcd_v1_WaitBusyDown();
		M_SBLCD_EN   = 1;
		M_SBLCD_DATA = 0;	//	0  = command
		sblcd_clk_pulse();
		sblcd_delay();
		for ( loop = 0 ; loop < 8 ; loop++ ) {
			tmp = to_send;
			tmp >>= loop;
			tmp &= 0b00000001;
			if ( tmp )
				M_SBLCD_DATA = 1;
			else
				M_SBLCD_DATA = 0;
			sblcd_delay();
			sblcd_clk_pulse();
		}
		M_SBLCD_DATA = 0;
		M_SBLCD_EN   = 0;
		sblcd_delay();
	}

	_pg_Uint8 pg_sblcd_mv1_GetCommand( void ) {
		_pg_Uint8 tmp = 0; 
		_pg_int16 loop;
		pg_sblcd_v1_WaitBusyDown();
		TRIS_M_SBLCD_CLK = 1;
		TRIS_M_SBLCD_DATA = 1;
		M_SBLCD_EN   = 1;
		for ( loop = 0 ; loop < 8 ; loop++ ) {
			while( M_SBLCD_CLK != 1 ) ;
			if ( M_SBLCD_DATA == 1 )
				tmp += 1;
			tmp <<= 1;
			while( M_SBLCD_CLK != 0 ) ;
		}
		M_SBLCD_DATA = 0;
		M_SBLCD_EN   = 0;
		TRIS_M_SBLCD_CLK = 0;
		TRIS_M_SBLCD_DATA = 0;
		sblcd_delay();
		return tmp;
	}



	void pg_sblcd_mv1_ResetError( void ) {
		pg_sblcd_mv1_SendCommand( SBLCD_COMM_RESERROR );
	}

	
#endif
