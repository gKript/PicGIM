//#################################################################################
//#################################################################################
//#################################################################################
//GCP - General Communication Protocol
//main_TX.c
//#################################################################################
//#################################################################################
//#################################################################################



#include "picgim_main.h"

#define	PG_GCP_DEBUG_DELAY			1
#define	PG_GCP_DEBUG_DELAY_TIME1		500
#define	PG_GCP_DEBUG_DELAY_TIME2		3000
void main( void ) {

	_pg_Uint8 buffer_to_tx[ 3 ] = "jj\0";			//buffer creati dell' utente con stesse dimensioni del pg_gcp_buffer_rx_1[5] del protocollo opposto
	
	pg_initialize( );
	pg_serial_open();
	pg_lcd_hd44780_clear( 0 );
 	pg_gcp_init( );
	pg_lcd_hd44780_put_char( 0 , 'T' );
	
	while( 1 ) {
		pg_gcp_reset( );
		pg_lcd_hd44780_clear( 0 );
		pg_delay_sec( 1 );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_engage( );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_config( 1 );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_data( );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_tx_buffer( buffer_to_tx );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_data_end( );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_crc( buffer_to_tx, 3 );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_gcp_engage_end( );
											if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
		pg_delay_sec( 2 );
	}										
	PG_HALT;
}



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
	
	pg_initialize( );
	pg_gcp_init( );
	pg_serial_open( );
	pg_lcd_hd44780_clear( 0 );
	pg_lcd_hd44780_put_char( 0 , 'R' );
	
 	while( 1 ) {
		pg_gcp_rx();
		//pg_delay_sec( 1 );
		if( pg_gcp_rx_data_ready( ) != PG_GCP_RX_DATA_READY_NONE ) {
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_nconfig + 48 );				//config attuale !!!
			//pg_lcd_hd44780_put_char( 0 , rdr + 48 );						//config attuale !!!
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 0 ].xbuffer_ptr );	//ok	???
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr );	//atroie
			//*(_pg_int16 *)(pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr + 2) = 0;
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read( ) );	//ok	???
			//pg_lcd_hd44780_put_char( 0 , *pg_gcp_rx_data_read( ) );
			pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read( ) );
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
 
 