//PCD8544

#include "picgim_main.h"

void main( void ) {
	pg_initialize();

	pg_lcd_pcd8544_clear( 1 );			//white = 0; black = 1
	pg_delay_sec( 1 );
	pg_lcd_pcd8544_clear( 0 );			//white = 0; black = 1
	pg_delay_sec( 2 );
	
	pg_lcd_pcd8544_font_select( font_3x4 );
	pg_lcd_pcd8544_font_select( font_3x5 );
	pg_lcd_pcd8544_font_select( font_4x6 );
	pg_lcd_pcd8544_font_select( font_5x5 );
	pg_lcd_pcd8544_font_select( font_5x6 );
	pg_lcd_pcd8544_font_select( font_5x7 );
	pg_lcd_pcd8544_font_select( font_5x7_matrix_6x8_v );
	pg_lcd_pcd8544_font_select( font_5x8 );
	pg_lcd_pcd8544_font_select( font_6x8 );
	pg_lcd_pcd8544_font_select( font_8x8 );
	pg_lcd_pcd8544_font_select( font_sgu_3x8 );
	pg_lcd_pcd8544_font_select( font_sgu_6x16 );
	pg_lcd_pcd8544_font_select( font_sgu_6x16_8up );
	pg_lcd_pcd8544_font_select( font_sgu_6x16_8dw );
			
	pg_lcd_pcd8544_font_select( font_3x4 );
	pg_lcd_pcd8544_set_pos( 5 , 1 );
	pg_lcd_pcd8544_send_string_rom( " [Font 3x4]" );
	pg_lcd_pcd8544_set_pos( 5 , 2 );
	pg_lcd_pcd8544_send_string_rom( " Ciao Zanna!" );
	pg_lcd_pcd8544_font_select( font_5x7 );
	pg_lcd_pcd8544_set_pos( 5 , 3 );
	pg_lcd_pcd8544_send_string_rom( " [Font 5x7]" );
	pg_lcd_pcd8544_set_pos( 5 , 4 );
	pg_lcd_pcd8544_send_string_rom( " PicGIM   :)" );
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
 
 