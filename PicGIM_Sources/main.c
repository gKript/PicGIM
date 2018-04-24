//PCD8544

#include "picgim_main.h"

_pg_Uint8	buffer_fill[ 256 ];
_pg_Uint8	buffer_mx[ 256 ];

void main( void ) {
	//_pg_Uint16 idx;
	_pg_Uint8 idx;
	
	pg_initialize();

 	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	
	pg_lcd_pcd8544_set_pos( 0 , 5 );
	pg_lcd_pcd8544_font_select( pg_font_5x7_std );
	pg_lcd_pcd8544_send_string_rom( "ok:" );

	//clear buffer_mx
	idx = 0;			//_pg_Uint8 idx;
	do {
		buffer_mx[ idx ] = 0xFF;	//0x18;
		idx++;
	} while ( idx != 0 );

	//fill buffer_fill
	idx = 0;			//_pg_Uint8 idx;
	do {
		buffer_fill[ idx ] = 0xAA;	//0x18;
		idx++;
	} while ( idx != 0 );
	pg_lcd_pcd8544_send_string_rom( "w" );
	pg_delay_sec( 3 );
	
	//wr page on mx
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_BLOCK , 1 );     //Block #1 is the free first one
	pg_external_memory_set_address( PG_EXTERNAL_MEMORY_SET_ADDRESS_SECTOR , 0 );
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_PAGE , 0 );
	pg_external_memory_write_page( buffer_fill );
	
	pg_lcd_pcd8544_send_string_rom( "r" );
	pg_delay_sec( 3 );
	//rd page from mx
	pg_external_memory_read_page( buffer_mx );
	
	//print buffer_mx
	idx = 0;			//_pg_Uint8 idx;
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	do {
		pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
		idx++;
	} while ( idx != 0 );
	pg_lcd_pcd8544_send_string_rom( "m" );
	pg_delay_sec( 3 );
	
	//mod to buffer_mx
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 42 );
	pg_external_memory_write_byte( 0x18 , PG_NOT_VERIFY );	//PG_VERIFY || PG_NOT_VERIFY
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 44 );
	pg_external_memory_write_byte( 0x18 , PG_NOT_VERIFY );	//PG_VERIFY || PG_NOT_VERIFY
	pg_external_memory_set_address(PG_EXTERNAL_MEMORY_SET_ADDRESS_BYTE , 46 );
	pg_external_memory_write_byte( 0x18 , PG_NOT_VERIFY );	//PG_VERIFY || PG_NOT_VERIFY

	//rd page
	pg_external_memory_read_page( buffer_mx );

	//print buffer_mx
	idx = 0;			//_pg_Uint8 idx;
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	do {
		pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ idx ] );
		idx++;
	} while ( idx != 0 );
	pg_lcd_pcd8544_send_string_rom( "ooo" );
	//pg_delay_sec( 2 );
	
	
	
	
	
	
	
		// pg_lcd_pcd8544_set_pos( 0 , 1 );
	// pg_lcd_pcd8544_font_select( pg_font_5x7_std );
	// pg_lcd_pcd8544_send_string_rom( "f>" );
	// for( idx = 0; idx < 256; idx++ ) {
		// pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_fill[ (_pg_Uint8)idx ] );
		// //pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ (_pg_Uint8)idx ] );
		// //pg_lcd_pcd8544_send( PG_PCD8544_DATA , 0xFF ); 
	// }

	//pg_lcd_pcd8544_set_pos( 0 , 0 );
	//pg_lcd_pcd8544_font_select( pg_font_5x7_std );
	//pg_lcd_pcd8544_send_string_rom( "b>" );
	// for( idx = 0; idx < 255; idx++ ) {
		// //pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_fill[ (_pg_Uint8)idx ] );
		// pg_lcd_pcd8544_send( PG_PCD8544_DATA , buffer_mx[ (_pg_Uint8)idx ] );
		// //pg_lcd_pcd8544_send( PG_PCD8544_DATA , 0xFF ); 
	// }
	
	
	
	
	
	
	
/* 	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_sec( 1 );

	pg_lcd_pcd8544_font_select( pg_font_5x5_std );
	pg_lcd_pcd8544_set_pos( 0 , 0 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+" );
	pg_lcd_pcd8544_font_select( pg_font_5x5_std_m );
	pg_lcd_pcd8544_set_pos( 0 , 1 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+-" );

	pg_lcd_pcd8544_font_select( pg_font_5x6_std );
	pg_lcd_pcd8544_set_pos( 0 , 2 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+-" );
	pg_lcd_pcd8544_font_select( pg_font_5x6_std_m );
	pg_lcd_pcd8544_set_pos( 0 , 3 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+-" );

	pg_lcd_pcd8544_font_select( pg_font_5x7_std );
	pg_lcd_pcd8544_set_pos( 0 , 4 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+-" );
	pg_lcd_pcd8544_font_select( pg_font_5x7_std_m );
	pg_lcd_pcd8544_set_pos( 0 , 5 );
	pg_lcd_pcd8544_send_string_rom( "ABCabc!$%&[^+-" ); */



//	pg_lcd_pcd8544_font_select( pg_font_5x5_std );
//	pg_lcd_pcd8544_set_pos( 0 , 0 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );
//	pg_lcd_pcd8544_font_select( pg_font_5x5_std_m );
//	pg_lcd_pcd8544_set_pos( 0 , 1 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );
//
//	pg_lcd_pcd8544_font_select( pg_font_5x6_std );
//	pg_lcd_pcd8544_set_pos( 0 , 2 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );
//	pg_lcd_pcd8544_font_select( pg_font_5x6_std_m );
//	pg_lcd_pcd8544_set_pos( 0 , 3 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );
//
//	pg_lcd_pcd8544_font_select( pg_font_5x7_std );
//	pg_lcd_pcd8544_set_pos( 0 , 4 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );
//	pg_lcd_pcd8544_font_select( pg_font_5x7_std_m );
//	pg_lcd_pcd8544_set_pos( 0 , 5 );
//	pg_lcd_pcd8544_send_string_rom( "1+2=\"3\"" );

	PG_HALT;
}



//#################################################################################
//#################################################################################
//#################################################################################
//GCP - General Communication Protocol
//main_TX.c
//#################################################################################
//#################################################################################
//#################################################################################

/*

#include "picgim_main.h"

void main( void ) {

	_pg_Uint8 mys[ 4 ];
	_pg_Uint16 num = 0;
	
	pg_initialize();
	pg_serial_open();
 	pg_gcp_init();
	pg_lcd_hd44780_put_char( 0 , 'T' );
	pg_delay_sec( 1 );
	pg_lcd_hd44780_clear( 0 );
	
	pg_gcp_engage( );
	while( 1 ) {
		pg_gcp_send( itoa( num, mys ), PG_GCP_CONFIG_01, PG_GCP_CRC_ON );
		num++;		
		
		pg_delay_sec( 1 );
		pg_lcd_hd44780_clear( 0 );
	}										
	pg_gcp_engage_end( );
	PG_HALT;
}


*/

//#################################################################################
//#################################################################################
//#################################################################################
//GCP - General Communication Protocol
//main_RX.c
//#################################################################################
//#################################################################################
//#################################################################################

/*

#include "picgim_main.h"

void main( void ) {

	pg_initialize();
	pg_gcp_init();
	pg_serial_open(); 
	
	pg_lcd_hd44780_put_char( 0 , 'R' );
	pg_delay_sec( 1 );
	pg_lcd_hd44780_clear( 0 );
	
 	while( 1 ) {
		pg_gcp_rx();
		if( pg_gcp_read() == PG_OK ) {
			pg_delay_sec( 2 );
			pg_lcd_hd44780_clear( 0 );
			
			pg_lcd_hd44780_put_char( 0 , ( pg_gcp_udata.uconf + 48 ) );
			pg_lcd_hd44780_write_string( 0 , pg_gcp_udata.uptr );
			pg_lcd_hd44780_put_char( 0 , ( pg_gcp_udata.ulen + 48 ) );
			
			pg_delay_sec( 1 );
			//pg_delay_sec( 6 ); //if delay too long, rx 'D' in udata!!!
		}
		//errori
		// else {
			// pg_lcd_hd44780_put_char( 0 , '!' );
			// pg_delay_sec( 1 );
		// }
	}
	PG_HALT;
}

*/





/*
		
		//pg_lcd_hd44780_write_string( 0 , ( itoa( pg_gcp_udata.ulen, mystr ) ) );
		
		//_pg_Uint8 *	pg_gcp_read( void ) {
		//pg_gcp_udata.uconf = pg_gcp_rdu_index;
		//pg_gcp_udata.uptr = pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_ptr;
		//pg_gcp_udata.len = ( p
					
					
		//if( pg_gcp_rx_data_ready( ) != PG_GCP_RX_DATA_READY_NO ) {
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_nconfig + 48 );				//config attuale !!!
			//pg_lcd_hd44780_put_char( 0 , rdr + 48 );						//config attuale !!!
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 0 ].xbuffer_ptr );	//ok	???
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr );	//atroie
			//*(_pg_int16 *)(pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr + 2) = 0;
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read( ) );	//ok	???
			//pg_lcd_hd44780_put_char( 0 , *pg_gcp_rx_data_read( ) );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read( ) );
		//}
		
*/


/*

#include "picgim_main.h"

#define	PG_GCP_DEBUG_DELAY				1
#define	PG_GCP_DEBUG_DELAY_TIME1		500
#define	PG_GCP_DEBUG_DELAY_TIME2		3000
void main( void ) {

	_pg_Uint8 buffer_to_tx[ 3 ] = "jj\0";			//buffer creati dell' utente con stesse dimensioni del pg_gcp_buffer_rx_1[5] del protocollo opposto
	
	pg_initialize( );
	pg_serial_open();
	pg_lcd_hd44780_clear( 0 );
 	pg_gcp_init( );
	//pg_lcd_hd44780_put_char( 0 , 'T' );
	//pg_delay_sec( 1 );
	
	while( 1 ) {
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		if( pg_gcp_engage( ) != PG_OK ) {	
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_reset( );
		}
		else {
			pg_gcp_config( 1 );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_data( );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_tx_string( buffer_to_tx );
			//pg_gcp_tx_buffer( buffer_to_tx );
			//pg_gcp_send_byte_serial( buffer_to_tx[ 2 ] );
			//pg_gcp_send_byte_serial( buffer_to_tx[ 3 ] );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_data_end( );
			//pg_gcp_status_mod( PG_GCP_BUFFER_FULL );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_status_sync( );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_crc( buffer_to_tx, 3 );
												if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
			pg_gcp_engage_end( );
			
			pg_delay_sec( 2 );
			pg_gcp_reset( );
			pg_lcd_hd44780_clear( 0 );
		}
	}										
	PG_HALT;
}

*/










































// 	while( 1 ) {
//		while( !DataRdyUSART() ); 	//DataRdyUSART ret 1 if data is present
//		pg_lcd_hd44780_put_char( 0 , ReadUSART() );
//	}

	//strcpypgm2ram( pg_gcp_buffer_rx_01, "hallo\0" );

	//pg_lcd_hd44780_put_char( 0 , (pg_gcp_rx() - 77)  );
	//pg_gcp_rx( );
	//pg_lcd_hd44780_write_p_string		( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8 * Str );
	//pg_lcd_hd44780_write_p_string( 0 , 0 , 5 , pg_gcp_buffer_rx_01 );
	//pg_gcp_rx();
	//pg_gcp_reset( );





		//get = pg_gcp_rx_data_ready( );
		//if( get != PG_GCP_RX_DATA_READY_NONE ) {
			//pg_lcd_hd44780_write_p_string( 0 , 1 , 0 , pg_gcp_v_config[ get ].xbuffer_ptr );
			//stampa bene quella in engage end
			//pg_delay_sec( 1 );
			//pg_lcd_hd44780_clear( 0 );
			//pg_lcd_hd44780_put_char( 0 , '_' );
			//pg_lcd_hd44780_put_char( 0 , get + 48 ); 
			//pg_lcd_hd44780_put_char( 0 , '_' );
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_nconfig + 48 );
			//pg_lcd_hd44780_put_char( 0 , (_pg_Uint8)pg_gcp_bindex + 48 );	
			//pg_gcp_rx_data_read( get );  //=1
			//pg_lcd_hd44780_put_char( 0 , ' ' );
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ 0 ].xbuffer_ptr[ 0 ] );
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ 0 ].xbuffer_ptr[ 1 ] );
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr[ 0 ] );
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr[ 1 ] );
			//pg_delay_sec( 1 );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ get ].xbuffer_ptr ); sbaglia!
		//}
		
		//if( pg_gcp_v_config[ 1 ].xbuffer_status == PG_GCP_BUFFER_FULL ) {
//		if( pg_gcp_v_config[ 1 ].xbuffer_status > 169 ) {
//			break;
//		}
	//pg_gcp_buffer_rx_01[7]='\0';
	//pg_lcd_hd44780_write_p_string( 0 , 1 , 0 , pg_gcp_buffer_rx_01 );
 
 