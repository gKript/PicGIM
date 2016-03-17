//
// pgim_rtc_ds1302.c
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

/*!		\file			pgim_rtc_ds1302.c
		\version		0.6-0
		\date			2002 - 2016
		\brief			Support for DS1302 - Real-Time Clock/Calendar Trickle Charge Timekeeping
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim.h"

#if ( PGIM_RTC_DS1302 == PG_ENABLE )

	#if ( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PG_HS_PG PG_HS_MSG This file is compiling.
	#endif
	
	//Doc. Ref.: DALLAS Semiconductor, DS1302 Trickle-Charge Timekeeping Chip
	
	_pg_Uint8 ds1302_sec;			//!<	0-59			( Decimal value accepted range )
	_pg_Uint8 ds1302_min;			//!<	0-59			( Decimal value accepted range )
	_pg_Uint8 ds1302_hour;			//!<	1-12/0-23		( Decimal value accepted range )
	_pg_Uint8 ds1302_day;			//!<	1-31			( Decimal value accepted range )
	_pg_Uint8 ds1302_month;			//!<	1-12			( Decimal value accepted range )
	_pg_Uint8 ds1302_weekday;		//!<	1-7				( Decimal value accepted range )
	_pg_Uint8 ds1302_year;			//!<	00-99			( Decimal value accepted range )
	_pg_Uint8 ds1302_halt_clock;	//!<	Halt clock flag ( 0 = running )
	
	
	void	pg_rtc_ds1302_init( void ) {
		PG_RTC_DS1302_CS 			= PG_DISABLE;
		PG_RTC_DS1302_CS_TRIS 		= PG_OUT;

		ds1302_sec			= 0x00;
		ds1302_min			= 0x00;
		ds1302_hour			= 0x00;
		ds1302_day			= 0x00;
		ds1302_month		= 0x00;
		ds1302_weekday		= 0x00;
		ds1302_year			= 0x00;
		ds1302_halt_clock	= 0x00; //Running clock
		
		pg_rtc_ds1302_wr_disable( );
	}

	
	void	pg_rtc_ds1302_wr_enable( void ) {
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_WRPROTECT ); //Command to write WP Write Protect Bit7 ( 1 = Protected )
		pg_3wire_wr_byte( 0b00000000 ); //Bit7 = 0 to enable writing
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_wr_disable( void) {
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_WRPROTECT ); //Command to write WP Write Protect Bit7 ( 1 = Protected )
		pg_3wire_wr_byte( 0b10000000 ); //Bit7 = 1 to disable writing
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_wr_time(_pg_Uint8 ds1302_set_hour, _pg_Uint8 ds1302_set_min, _pg_Uint8 ds1302_set_sec ){
		_pg_Uint8 temp;
		
		//---[ Write HOUR ]---------------------------------------------------------------
		pg_rtc_ds1302_wr_enable( );
		
		if( ds1302_set_hour < 24 ) { //0-23; unsigned, never is < 0.
			temp = 0x00;
			temp = ( ( ( ds1302_set_hour / 10 ) << 4 ) + ( ds1302_set_hour % 10 ) );
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_HOUR ); //Command to write hours
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong hours value;
		}
		//---[ Write MINUTE ]------------------------------------------------------------
		if( ds1302_set_min < 60 ) {	//0-59; unsigned, never is < 0.
			temp = 0x00;
			temp = ( ( ( ds1302_set_min / 10 ) << 4 ) + ( ds1302_set_min % 10 ) );
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_MIN ); //Command to write minutes
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong minutes value;
		}
		//---[ Write SECOND ]------------------------------------------------------------
		if( ds1302_set_sec < 60 ) {	//0-59; unsigned, never is < 0.
			temp = 0x00;
			temp = ( ( ( ds1302_set_sec / 10 ) << 4 ) + ( ds1302_set_sec % 10 ) );
			if( ds1302_halt_clock )
				temp = temp | 0b10000000; //Set "Clock Halt Flag" bit7 high to stop clock and go in low power mode!
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_SEC ); //Command to write seconds
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong seconds value;
		}
		pg_rtc_ds1302_wr_disable( );
	}
	
	
	void	pg_rtc_ds1302_rd_time( void ) {
		_pg_Uint8 temp;
		
		//---[ Read HOUR ]---------------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_HOUR ); //Command to read hours
		temp = pg_3wire_rd_byte( );
		temp = temp & 0b00111111; //Clear unused Bit7 and Bit6, h24 NOT supported!
		ds1302_hour = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
		
		//---[ Read MINUTE ]--------------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_MIN ); //Command to read minutes
		temp = pg_3wire_rd_byte( );
		temp = temp & 0b01111111; //Clear unused Bit7
		ds1302_min = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
		
		//---[ Read SECOND ]--------------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_SEC ); //Command to read "Clock Halt Flag" and seconds
		temp = pg_3wire_rd_byte( );
		ds1302_halt_clock = temp & 0b10000000; //1 = stopped
		temp = temp & 0b01111111; //Clear "Clock Halt Flag" bit to extract right seconds
		ds1302_sec = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_wr_date( _pg_Uint8 ds1302_set_day, _pg_Uint8 ds1302_set_month, _pg_Uint8 ds1302_set_year ) {
		_pg_Uint8 temp;
		
		pg_rtc_ds1302_wr_enable( );
		
		//---[ Write DAY (1-31) ]---------------------------------------------------------
		if( ( ds1302_set_day > 0 ) &&  ( ds1302_set_day < 32 ) ) { //1-31
			temp = 0x00;
			temp = ( ( ( ds1302_set_day / 10 ) << 4 ) + ( ds1302_set_day % 10 ) );
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_DAY ); //Command to write day
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong day value;
		}
		//---[ Write MONTH ]--------------------------------------------------------------
		if( ( ds1302_set_month > 0 ) &&  ( ds1302_set_month < 13 ) ) { //1-12
			temp = 0x00;
			temp = ( ( ( ds1302_set_month / 10 ) << 4 ) + ( ds1302_set_month % 10 ) );
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_MONTH ); //Command to write month
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong month value;
		}
		//---[ Write YEAR ]---------------------------------------------------------------
		if( ( ds1302_set_year > 0 ) &&  ( ds1302_set_year < 100 ) ) { //00-99
			temp = 0x00;
			temp = ( ( ( ds1302_set_year / 10 ) << 4 ) + ( ds1302_set_year % 10 ) );
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_YEAR ); //Command to write year
			pg_3wire_wr_byte( temp );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong year value;
		}
		pg_rtc_ds1302_wr_disable( );
	}
	
		
	void	pg_rtc_ds1302_rd_date( void ) {
		_pg_Uint8 temp;
		
		//---[ Read DAY (1-31) ]----------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_DAY ); //Command to read day 1-31
		temp = pg_3wire_rd_byte( );
		temp = temp & 0b00111111; //Clear unused Bit7 and Bit6
		ds1302_day = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY

		//---[ Read MONTH ]---------------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_MONTH ); //Command to read month
		temp = pg_3wire_rd_byte( );
		temp = temp & 0b00011111; //Clear unused Bit7, Bit6 and Bit5
		ds1302_month = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY

		//---[ Read YEAR ]----------------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_YEAR ); //Command to read year
		temp = pg_3wire_rd_byte( );
		ds1302_year = ( ( temp >> 4 ) * 10 ) + ( temp & 0b00001111 );
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_wr_weekday( _pg_Uint8 ds1302_set_weekday ) {
		_pg_Uint8 temp;
		
		pg_rtc_ds1302_wr_enable( );
		
		//---[ Write WEEKDAY (1-7) ]------------------------------------------------------
		if( ( ds1302_set_weekday > 0 ) &&  ( ds1302_set_weekday < 8 ) ) { //1-7
			PG_RTC_DS1302_CS = PG_ENABLE;
			PG_RTC_DS1302_CS_DELAY
			pg_3wire_wr_byte( PG_RTC_DS1302_CMD_WR_WEEKDAY ); //Command to write weekday
			pg_3wire_wr_byte( ds1302_set_weekday );
			PG_RTC_DS1302_CS = PG_DISABLE;
			PG_RTC_DS1302_CS_DELAY
		}
		else {
			//Error: wrong day value;
		}
		pg_rtc_ds1302_wr_disable( );
	}

	
	void	pg_rtc_ds1302_rd_weekday( void ) {
		_pg_Uint8 temp;
		
		//---[ Read WEEKDAY (1-7) ]-------------------------------------------------------
		PG_RTC_DS1302_CS = PG_ENABLE;
		PG_RTC_DS1302_CS_DELAY
		pg_3wire_wr_byte( PG_RTC_DS1302_CMD_RD_WEEKDAY ); //Command to read weekday 1-7
		temp = pg_3wire_rd_byte( );
		ds1302_weekday = ( temp & 0b00000111 ); //Clear unused Bit7 - Bit3
		PG_RTC_DS1302_CS = PG_DISABLE;
		PG_RTC_DS1302_CS_DELAY
	}
	
	
	void	pg_rtc_ds1302_start_clock	( void ) {
		//---[ Start clock ]--------------------------------------------------------------
		pg_rtc_ds1302_rd_time( );
		ds1302_halt_clock = 0x00;
		pg_rtc_ds1302_wr_time( ds1302_hour, ds1302_min, ds1302_sec );
	}
	
	
	void	pg_rtc_ds1302_stop_clock	( void ) {
		//---[ Stop clock ]---------------------------------------------------------------
		pg_rtc_ds1302_rd_time( );
		ds1302_halt_clock = 0x01;
		pg_rtc_ds1302_wr_time( ds1302_hour, ds1302_min, ds1302_sec );
	}
	
#endif


