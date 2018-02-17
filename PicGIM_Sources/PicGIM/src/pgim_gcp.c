/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_gcp.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.6
	Current version :		0.6-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_caldelay.h

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
		\file		pgim_gcp.c
		\version	0.6-0
		\date		2002 - 2017
		\brief		GCP - General Communication Protocol
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

//GCP - General Communication Protocol
//--------------------------------------------------------------------------
//All byte are binary, otherwise specified.
//Communication is always 1 byte at time.
//Check linker for memory allocation sizeof(config struct x # struct).
//Call gcp_Init() one time before use!
//controllare che nessun valore degli errori sia il ':' PG_GCP_CONTROL_ESCAPE
//
//Buffer-RX(A) = Buffer-TX(B) &&
//Buffer-RX(B) = Buffer-TX(A)
//
//--------------------------------------------------------------------------
//	Step order:
//	- Engage (Controlla la versione (opzioonale) e poi impegna la linea. Crea collegamento. Determina il verso: chi lo esegue trasmette dei dati. Tutti i comandi seguenti sono accettati previo questo.)
//	- Version (Verifica della versione (optzionale) sia use app che PicGIM version.
//	- Config (Modifica il tipo di dato. Default #1 byte alla volta. Opzionale. Puo' essere eseguito dentro e fuori la tx data, ma dentro engage.)
//	- Data (Modalita' di trasferimento dei dati. Tra un dato e l'altro, puo' essere eseguito il config.)
//	- <send data> e/o Config. Si puo' anche escire dal modo Data e rientrare, cambiare configurazione dentro e fuori e tx dati in modo asincrono.
//	- Request (La esegue chi riceve per poter trasmettere invertendo i ruoli rispettando l'engage)
//	- Data_End (Solo dopo comando data. Per uscira dalla modalita' Data)
//	- Status (Verifica quanti byte sono giunti a destinazione. Se il buffer e' pieno setta un flag nella configurazione. Eseguibile solo fuori dal modo data.)
//	- Mod_Status (Forza il cambio dello stato del valore di stato del buzzer; utile in caso di stringhe che possono limitare la trasmissime alla loro lunghezza e non a quella di tutto il buffer, impostando manualmente lo status a full.
//	- Crc (Esegue crc del buffer locale, lo trasmette a remoto che lo confronta e ritorna esito. Eseguibile solo fuori dal modo data.)
//	- Engage_End (Libera la linea. Chiude collegamento. Permette all corrispondente di eseguire l'engage per trasmettere a sua volta.)
//	- Reset (Reinizializza solo in locale; eseguibile in qualunque momento)
//	- Reset-Local (Reinizializza prima a remoto e poi in locale; eseguibile in qualunque momento)
//	- Streaming (Blocca la rx() fino a che riceve e ritorna direttamente un byte)
//	Usage:	Execute gcp_Init(), Engage(), Config(), Data()... tx data... Data_End(), Engage_End()...
//--------------------------------------------------------------------------

//considerare di clear_buffer quando non c'e' risposta che si accumulano nel buffer

#include "picgim.h"

#if ( PGIM_GCP == PG_ENABLE )

	#if	( PG_PROJECT_STATE == PG_DEBUG )
		#warning	PicGIM >>> Message >>> This file is compiling.
	#endif
	
	//---[ Global Statements ]-------------------------------------------------
	
	//---[ Rx varuable ]---
	_pg_Uint8	pg_gcp_dbyte;							//rx byte
	
	//---[ Buffer variable ]---
	_pg_Uint8	pg_gcp_nconfig;							//config id number
	_pg_Uint16	pg_gcp_bindex;							//variabile di supporto alla modifica dell'indice del buffer
	
	//---[ Index ]---
	_pg_Uint8 	pg_gcp_rdr_index;						//non parte sempre da zero e permette la scansione continua di tutti i buffer
	_pg_Uint8 	pg_gcp_rdu_index;						//non parte sempre da zero e permette la scansione continua di tutti i buffer
	_pg_Uint8 	pg_gcp_rde_index;						//non parte sempre da zero e permette la scansione continua di tutti i buffer
	
	//---[ Flag ]---
	_pg_Uint8	pg_gcp_flag_tx;							//(no 1 bit flag, too slow )	E' il master, chi invia control.
	_pg_Uint8	pg_gcp_flag_engage;						//(no 1 bit flag, too slow)
	_pg_Uint8	pg_gcp_flag_data_mode;					//(no 1 bit flag, too slow)
	_pg_Uint8	pg_gcp_flag_request;					//(no 1 bit flag, too slow)
	_pg_Uint8	pg_gcp_flag_streaming;					//(no 1 bit flag, too slow)
	
 	//---[ Crc variable ]---
	#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
		_pg_Uint32_VAL	pg_gcp_crc32_local;				//variabile di supporto al calcolo e contenimento della crc del buffer
		_pg_Uint32_VAL	pg_gcp_crc32_remote;			//variabile di supporto al calcolo e contenimento della crc del buffer
	#endif

	//---[ Struct Version Typedef ]---
	struct pg_gcp_str_version {
		_pg_Uint8	user_app_name[ 4 ];
		_pg_Uint8	user_app_version_major;
		_pg_Uint8	user_app_version_minor;
		_pg_Uint8	picgim_version_major;
		_pg_Uint8	picgim_version_minor;
	};
	
	//---[ Config Struct Typedef ]---
	struct	pg_gcp_str_config {
		void		* xbuffer_ptr;												//!<Payload buffer pointer>
		_pg_Uint8	xbuffer_mode;												//!<It specifies the type of use: as buffer or as string <PG_GCP_BUFFER, PG_GCP_STRING>
		_pg_Uint16	xbuffer_length;												//!<Payload length. Total byte quantity to send in a packet; 0 = stream>
		_pg_Uint16	xbuffer_index;												//!<Current position to write to next byte in buffer; 0 to ( PG_GCP_BUFFER_RX_xx_LENGTH - 1 ) >
		#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
			_pg_Uint8	xbuffer_status;											//!<Status of buffer: PG_GCP_BUFFER_EMPTY, PG_GCP_BUFFER_INCOMPLETE, PG_GCP_BUFFER_FULL>
		#endif
	};
	
	//---[ User Data Struct Typedef ]---
	struct	pg_gcp_str_udata { 
		_pg_Uint8	uconf;	//#configuration
		void *		uptr;	//buffer-ptr
		_pg_Uint16	ulen;	//#byte rx
	};
	
	//---[ Struct ]---
	struct	pg_gcp_str_version	pg_gcp_version;
	struct	pg_gcp_str_config 	pg_gcp_v_config[ PG_GCP_CONFIGS_NUMBER + 1 ];	//Configuration types structures vector
	struct	pg_gcp_str_udata	pg_gcp_udata;
	
	//---[ Default Buffer ]---
	_pg_Uint8	pg_gcp_buffer_rx_default[ PG_GCP_BUFFER_RX_DEFAULT_LENGTH ];	//rx user buffer (config 00) - DEFAULT
	
	//---[ User Buffer ]---
	#if ( PG_GCP_BUFFER_RX_01_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_01[ PG_GCP_BUFFER_RX_01_LENGTH ];			//rx user buffer (config 01)
	#endif
	#if ( PG_GCP_BUFFER_RX_02_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_02[ PG_GCP_BUFFER_RX_02_LENGTH ];			//rx user buffer (config 02)
	#endif
	#if ( PG_GCP_BUFFER_RX_03_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_03[ PG_GCP_BUFFER_RX_03_LENGTH ];			//rx user buffer (config 03)
	#endif
	#if ( PG_GCP_BUFFER_RX_04_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_04[ PG_GCP_BUFFER_RX_04_LENGTH ];			//rx user buffer (config 04)
	#endif
	#if ( PG_GCP_BUFFER_RX_05_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_05[ PG_GCP_BUFFER_RX_05_LENGTH ];			//rx user buffer (config 05)
	#endif
	#if ( PG_GCP_BUFFER_RX_06_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_06[ PG_GCP_BUFFER_RX_06_LENGTH ];			//rx user buffer (config 06)
	#endif
	#if ( PG_GCP_BUFFER_RX_07_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_07[ PG_GCP_BUFFER_RX_07_LENGTH ];			//rx user buffer (config 07)
	#endif
	#if ( PG_GCP_BUFFER_RX_08_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_08[ PG_GCP_BUFFER_RX_08_LENGTH ];			//rx user buffer (config 08)
	#endif
	#if ( PG_GCP_BUFFER_RX_09_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_09[ PG_GCP_BUFFER_RX_09_LENGTH ];			//rx user buffer (config 09)
	#endif
	#if ( PG_GCP_BUFFER_RX_10_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_10[ PG_GCP_BUFFER_RX_10_LENGTH ];			//rx user buffer (config 10)
	#endif
	#if ( PG_GCP_BUFFER_RX_11_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_11[ PG_GCP_BUFFER_RX_11_LENGTH ];			//rx user buffer (config 11)
	#endif
	#if ( PG_GCP_BUFFER_RX_12_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_12[ PG_GCP_BUFFER_RX_12_LENGTH ];			//rx user buffer (config 12)
	#endif
	#if ( PG_GCP_BUFFER_RX_13_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_13[ PG_GCP_BUFFER_RX_13_LENGTH ];			//rx user buffer (config 13)
	#endif
	#if ( PG_GCP_BUFFER_RX_14_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_14[ PG_GCP_BUFFER_RX_14_LENGTH ];			//rx user buffer (config 14)
	#endif
	#if ( PG_GCP_BUFFER_RX_15_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_15[ PG_GCP_BUFFER_RX_15_LENGTH ];			//rx user buffer (config 15)
	#endif
	#if ( PG_GCP_BUFFER_RX_16_ENABLE == PG_ENABLE )
		_pg_Uint8	pg_gcp_buffer_rx_16[ PG_GCP_BUFFER_RX_16_LENGTH ];			//rx user buffer (config 16)
	#endif
	
	//---[ Function ]--------------------------------------------------------
	
	//---[ Clear Serial Buffer ]---
	void	pg_gcp_empty_serial( void ) {
		//--------------------------------------------------------------------------
		while( DataRdyUSART() ) { //DataRdyUSART() ret 1 if data is present.
			ReadUSART();
		}
	}
	
	//#######################################################################
	//		I N I T
	//#######################################################################
	void pg_gcp_init( void ) {		
		//--------------------------------------------------------------------------
		pg_gcp_reset_local();
		
		//---[ Init HW ]---
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_OFF;
			PG_GCP_LED_ENGAGE_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_DATA_LAT = PG_OFF;
			PG_GCP_LED_DATA_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CONFIG_LAT = PG_OFF;
			PG_GCP_LED_CONFIG_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CRC_LAT = PG_OFF;
			PG_GCP_LED_CRC_TRIS = PG_OUT;
		#endif		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_OFF;
			PG_GCP_LED_RESET_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_COMMAND_LAT = PG_OFF;
			PG_GCP_LED_COMMAND_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_STREAMING_LAT = PG_OFF;
			PG_GCP_LED_STREAMING_TRIS = PG_OUT;
		#endif		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_TX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_TX_LAT = PG_OFF;
			PG_GCP_LED_TX_TRIS = PG_OUT;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RX_LAT = PG_OFF;
			PG_GCP_LED_RX_TRIS = PG_OUT;
		#endif
		
		//---[ Led Test Scan ]---
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_ENGAGE_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_DATA_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_DATA_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CONFIG_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_CONFIG_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CRC_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_CRC_LAT = PG_OFF;
		#endif		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_RESET_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_COMMAND_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_COMMAND_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_STREAMING_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_STREAMING_LAT = PG_OFF;
		#endif	
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_TX_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_TX_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_TX_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_SCAN_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RX_LAT = PG_ON;
			pg_delay_msec( 200 );
			PG_GCP_LED_RX_LAT = PG_OFF;
		#endif
	}
	
	//#######################################################################
	//		R E S E T
	//#######################################################################
	//---[ TX - Reset Control ]---
 	_pg_Uint8 pg_gcp_reset( void ) {	//Reset ( remote and local )
		//--------------------------------------------------------------------------
		if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_RESET ) == PG_OK ) {
			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
				PG_GCP_LED_RESET_LAT = PG_ON;
			#endif
			//
			pg_delay_msec( PG_GCP_DELAY_RESET_TX );
			Reset();
//			pg_gcp_reset_local();
//			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
//				PG_GCP_LED_RESET_LAT = PG_OFF;
//			#endif
//			#if PG_ERROR_IS_ENABLE
//				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
//			#endif
//			return( PG_OK );
//		}
//		else {
//			#if PG_ERROR_IS_ENABLE
//				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RESET_FAILED , PG_ERROR_CRITICAL );
//			#endif
			return( PG_NOK );
		}
	}

	//---[ RX - Reset Control ]---
	_pg_Uint8 pg_gcp_rx_reset( void ) {
		//--------------------------------------------------------------------------
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_RESET_REPLY );
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_RESET_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_RESET_REPLY  );
		#endif
		//
		pg_delay_msec( PG_GCP_DELAY_RESET_RX );
		Reset();
//		pg_gcp_reset_local();
//		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
//			PG_GCP_LED_RESET_LAT = PG_OFF;
//		#endif
//		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_RESET_CLEAR_LCD == PG_ENABLE ) )
//			pg_lcd_hd44780_clear( 0 );
//		#endif
//		#if PG_ERROR_IS_ENABLE
//			pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
//		#endif
		//return( PG_GCP_OK_RESET_DONE );
		return( PG_OK );
	}
	
/*
	//---[ TX - Reset Control ]---
	_pg_Uint8 pg_gcp_reset( void ) {	//Reset ( remote and local )
		//--------------------------------------------------------------------------
		while( pg_gcp_tx_control_byte( PG_GCP_CONTROL_RESET ) == PG_OK ) {
			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
				PG_GCP_LED_RESET_LAT = PG_ON;
			#endif
			//
			pg_delay_msec( PG_GCP_DELAY_RESET_TX );
			pg_gcp_reset_local();
			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
				PG_GCP_LED_RESET_LAT = PG_OFF;
			#endif
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
		#endif
		return( PG_OK );
	}
	
	//---[ RX - Reset ]---
	_pg_Uint8 pg_gcp_rx_reset( void ) {
		//--------------------------------------------------------------------------
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_RESET_REPLY );
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_RESET_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_RESET_REPLY  );
		#endif
		//
		pg_delay_msec( PG_GCP_DELAY_RESET_RX );	//to show led
		pg_gcp_reset_local();
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_RESET_CLEAR_LCD == PG_ENABLE ) )
			pg_lcd_hd44780_clear( 0 );
		#endif
 		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
		#endif
		//return( PG_GCP_OK_RESET_DONE );
		return( PG_OK ); 
	}
*/	
	//---[ Reset Local ]---
	void pg_gcp_reset_local( void ) {	//Reset ( local only )
		//--------------------------------------------------------------------------
		//---[ Variables Initialization ]---
		pg_gcp_nconfig				= 0;
		pg_gcp_flag_tx				= PG_NO;
		pg_gcp_flag_engage			= PG_NO;
		//pg_gcp_flag_version		= PG_NO;
		pg_gcp_flag_data_mode		= PG_NO;
		pg_gcp_flag_request			= PG_NO;
		pg_gcp_flag_streaming		= PG_NO;
		pg_gcp_bindex				= 0;
		pg_gcp_rdr_index			= 0;
		pg_gcp_rdu_index			= 0;
		pg_gcp_rde_index			= 0;
		//pg_gcp_dbyte				= 0;		//!< Doesn't need.>
		//pg_gcp_crc32_local		= 0;		//!< Doesn't need.>
		//pg_gcp_crc32_remote		= 0;		//!< Doesn't need.>
		
		//---[ Clear Serial Buffer ]---
		pg_gcp_empty_serial();
		
		//---[ Clear Led ]---
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_DATA_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CONFIG_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CRC_LAT = PG_OFF;
		#endif		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RESET_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RESET_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_COMMAND_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_STREAMING_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_TX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_TX_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RX_LAT = PG_OFF;
		#endif
		
		//---[ Clear Lcd ]---
		#if ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) 
			pg_lcd_hd44780_clear( 0 );
		#endif
		
		//---[ Version Struct Initialization ]---
		strcpypgm2ram( pg_gcp_version.user_app_name , PG_GCP_APPLICATION_NAME );
		pg_gcp_version.user_app_version_major	= PG_GCP_APPLICATION_VERSION_MAJOR;
		pg_gcp_version.user_app_version_minor	= PG_GCP_APPLICATION_VERSION_MINOR;
		pg_gcp_version.picgim_version_major		= PG_MAJOR;
		pg_gcp_version.picgim_version_minor		= PG_MINOR;

		//---[ Config Struct Initialization ]---
		//---[ Config Buffer 00 - Default ]---
		pg_gcp_v_config[ 0 ].xbuffer_ptr 	= pg_gcp_buffer_rx_default;
		pg_gcp_v_config[ 0 ].xbuffer_length = PG_GCP_BUFFER_RX_DEFAULT_LENGTH;
		pg_gcp_v_config[ 0 ].xbuffer_index	= 0;
		
		#if ( PG_GCP_BUFFER_RX_01_ENABLE == PG_ENABLE )
			//---[ Config Buffer 01 ]---
			pg_gcp_v_config[ 1 ].xbuffer_ptr			= pg_gcp_buffer_rx_01;
			pg_gcp_v_config[ 1 ].xbuffer_mode			= PG_GCP_BUFFER_RX_01_MODE;
			pg_gcp_v_config[ 1 ].xbuffer_length			= PG_GCP_BUFFER_RX_01_LENGTH;
			pg_gcp_v_config[ 1 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 1 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_02_ENABLE == PG_ENABLE )
			//---[ Config Buffer 02 ]---
			pg_gcp_v_config[ 2 ].xbuffer_ptr			= pg_gcp_buffer_rx_02;
			pg_gcp_v_config[ 2 ].xbuffer_mode			= PG_GCP_BUFFER_RX_02_MODE;
			pg_gcp_v_config[ 2 ].xbuffer_length			= PG_GCP_BUFFER_RX_02_LENGTH;
			pg_gcp_v_config[ 2 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 2 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_03_ENABLE == PG_ENABLE )
			//---[ Config Buffer 03 ]---
			pg_gcp_v_config[ 3 ].xbuffer_ptr			= pg_gcp_buffer_rx_03;
			pg_gcp_v_config[ 3 ].xbuffer_mode			= PG_GCP_BUFFER_RX_03_MODE;
			pg_gcp_v_config[ 3 ].xbuffer_length			= PG_GCP_BUFFER_RX_03_LENGTH;
			pg_gcp_v_config[ 3 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 3 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif	
		#if ( PG_GCP_BUFFER_RX_04_ENABLE == PG_ENABLE )
			//---[ Config Buffer 04 ]---
			pg_gcp_v_config[ 4 ].xbuffer_ptr			= pg_gcp_buffer_rx_04;
			pg_gcp_v_config[ 4 ].xbuffer_mode			= PG_GCP_BUFFER_RX_04_MODE;
			pg_gcp_v_config[ 4 ].xbuffer_length			= PG_GCP_BUFFER_RX_04_LENGTH;
			pg_gcp_v_config[ 4 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 4 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_05_ENABLE == PG_ENABLE )
			//---[ Config Buffer 05 ]---
			pg_gcp_v_config[ 5 ].xbuffer_ptr			= pg_gcp_buffer_rx_05;
			pg_gcp_v_config[ 5 ].xbuffer_mode			= PG_GCP_BUFFER_RX_05_MODE;
			pg_gcp_v_config[ 5 ].xbuffer_length			= PG_GCP_BUFFER_RX_05_LENGTH;
			pg_gcp_v_config[ 5 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 5 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_06_ENABLE == PG_ENABLE )
			//---[ Config Buffer 06 ]---
			pg_gcp_v_config[ 6 ].xbuffer_ptr			= pg_gcp_buffer_rx_06;
			pg_gcp_v_config[ 6 ].xbuffer_mode			= PG_GCP_BUFFER_RX_06_MODE;
			pg_gcp_v_config[ 6 ].xbuffer_length			= PG_GCP_BUFFER_RX_06_LENGTH;
			pg_gcp_v_config[ 6 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 6 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_07_ENABLE == PG_ENABLE )
			//---[ Config Buffer 07 ]---
			pg_gcp_v_config[ 7 ].xbuffer_ptr			= pg_gcp_buffer_rx_07;
			pg_gcp_v_config[ 7 ].xbuffer_mode			= PG_GCP_BUFFER_RX_07_MODE;
			pg_gcp_v_config[ 7 ].xbuffer_length			= PG_GCP_BUFFER_RX_07_LENGTH;
			pg_gcp_v_config[ 7 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 7 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_08_ENABLE == PG_ENABLE )
			//---[ Config Buffer 08 ]---
			pg_gcp_v_config[ 8 ].xbuffer_ptr			= pg_gcp_buffer_rx_08;
			pg_gcp_v_config[ 8 ].xbuffer_mode			= PG_GCP_BUFFER_RX_08_MODE;
			pg_gcp_v_config[ 8 ].xbuffer_length			= PG_GCP_BUFFER_RX_08_LENGTH;
			pg_gcp_v_config[ 8 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 8 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_09_ENABLE == PG_ENABLE )
			//---[ Config Buffer 09 ]---
			pg_gcp_v_config[ 9 ].xbuffer_ptr			= pg_gcp_buffer_rx_09;
			pg_gcp_v_config[ 9 ].xbuffer_mode			= PG_GCP_BUFFER_RX_09_MODE;
			pg_gcp_v_config[ 9 ].xbuffer_length			= PG_GCP_BUFFER_RX_09_LENGTH;
			pg_gcp_v_config[ 9 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 9 ].xbuffer_status		= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_10_ENABLE == PG_ENABLE )
			//---[ Config Buffer 10 ]---
			pg_gcp_v_config[ 10 ].xbuffer_ptr			= pg_gcp_buffer_rx_10;
			pg_gcp_v_config[ 10 ].xbuffer_mode			= PG_GCP_BUFFER_RX_10_MODE;
			pg_gcp_v_config[ 10 ].xbuffer_length		= PG_GCP_BUFFER_RX_10_LENGTH;
			pg_gcp_v_config[ 10 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 10 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_11_ENABLE == PG_ENABLE )
			//---[ Config Buffer 011 ]---
			pg_gcp_v_config[ 11 ].xbuffer_ptr			= pg_gcp_buffer_rx_11;
			pg_gcp_v_config[ 11 ].xbuffer_mode			= PG_GCP_BUFFER_RX_11_MODE;
			pg_gcp_v_config[ 11 ].xbuffer_length		= PG_GCP_BUFFER_RX_11_LENGTH;
			pg_gcp_v_config[ 11 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 11 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_12_ENABLE == PG_ENABLE )
			//---[ Config Buffer 012 ]---
			pg_gcp_v_config[ 12 ].xbuffer_ptr			= pg_gcp_buffer_rx_12;
			pg_gcp_v_config[ 12 ].xbuffer_mode			= PG_GCP_BUFFER_RX_12_MODE;
			pg_gcp_v_config[ 12 ].xbuffer_length		= PG_GCP_BUFFER_RX_12_LENGTH;
			pg_gcp_v_config[ 12 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 12 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_13_ENABLE == PG_ENABLE )
			//---[ Config Buffer 013 ]---
			pg_gcp_v_config[ 13 ].xbuffer_ptr			= pg_gcp_buffer_rx_13;
			pg_gcp_v_config[ 13 ].xbuffer_mode			= PG_GCP_BUFFER_RX_13_MODE;
			pg_gcp_v_config[ 13 ].xbuffer_length		= PG_GCP_BUFFER_RX_13_LENGTH;
			pg_gcp_v_config[ 13 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 13 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_14_ENABLE == PG_ENABLE )
			//---[ Config Buffer 14 ]---
			pg_gcp_v_config[ 14 ].xbuffer_ptr			= pg_gcp_buffer_rx_14;
			pg_gcp_v_config[ 14 ].xbuffer_mode			= PG_GCP_BUFFER_RX_14_MODE;
			pg_gcp_v_config[ 14 ].xbuffer_length		= PG_GCP_BUFFER_RX_14_LENGTH;
			pg_gcp_v_config[ 14 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 14 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_15_ENABLE == PG_ENABLE )
			//---[ Config Buffer 15 ]---
			pg_gcp_v_config[ 15 ].xbuffer_ptr			= pg_gcp_buffer_rx_15;
			pg_gcp_v_config[ 15 ].xbuffer_mode			= PG_GCP_BUFFER_RX_15_MODE;
			pg_gcp_v_config[ 15 ].xbuffer_length		= PG_GCP_BUFFER_RX_15_LENGTH;
			pg_gcp_v_config[ 15 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 15 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif
		#if ( PG_GCP_BUFFER_RX_16_ENABLE == PG_ENABLE )
			//---[ Config Buffer 16 ]---
			pg_gcp_v_config[ 16 ].xbuffer_ptr			= pg_gcp_buffer_rx_16;
			pg_gcp_v_config[ 16 ].xbuffer_mode			= PG_GCP_BUFFER_RX_16_MODE;
			pg_gcp_v_config[ 16 ].xbuffer_length		= PG_GCP_BUFFER_RX_16_LENGTH;
			pg_gcp_v_config[ 16 ].xbuffer_index			= 0;
			#if ( ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE ) || ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE ) )
				pg_gcp_v_config[ 16 ].xbuffer_status	= PG_GCP_BUFFER_EMPTY;
			#endif
		#endif		
	}
	
	//#######################################################################
	//		V E R S I O N   -   C H E C K
	//#######################################################################
	//---[ TX - Version Check ]---
	_pg_Uint8 pg_gcp_tx_version( void ) {	
		//--------------------------------------------------------------------------
		//	Called by Engage, NOT directly.
		//--------------------------------------------------------------------------
		if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_VERSION ) == PG_OK ) {
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_name[ 0 ] );
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_name[ 1 ] );
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_name[ 2 ] );
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_name[ 3 ] );
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_version_major );
			pg_gcp_send_byte_serial( pg_gcp_version.user_app_version_minor );
			pg_gcp_send_byte_serial( pg_gcp_version.picgim_version_major );
			pg_gcp_send_byte_serial( pg_gcp_version.picgim_version_minor );
			//
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				if( pg_gcp_dbyte == PG_OK )
					//pg_gcp_flag_version = PG_YES;
					#if ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE )
						pg_lcd_hd44780_put_char( 0 , '=' );
					#endif
					return( PG_OK );
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Version Check ]---
	_pg_Uint8 pg_gcp_rx_version( void ) {
		//--------------------------------------------------------------------------
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_VERSION_REPLY  );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_VERSION_REPLY );
		//---[ Version Check ]---
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_name[ 0 ] = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_name[ 1 ] = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_name[ 2 ] = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_name[ 3 ] = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_version_major = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.user_app_version_minor = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.picgim_version_major = pg_gcp_dbyte;
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK )
			pg_gcp_version.picgim_version_minor = pg_gcp_dbyte;
		
		if( strcmppgm2ram( pg_gcp_version.user_app_name, PG_GCP_APPLICATION_NAME ) == 0 ) {		//signed char strcmppgm2ram( const char * str1, const rom char * str2 ) return 0 if matched.
			if( pg_gcp_version.user_app_version_major == PG_GCP_APPLICATION_VERSION_MAJOR ) {
				if( pg_gcp_version.user_app_version_minor == PG_GCP_APPLICATION_VERSION_MINOR ) {
					if( pg_gcp_version.picgim_version_major == PG_MAJOR ) {
						if( pg_gcp_version.picgim_version_minor == PG_MINOR ) {
							pg_gcp_send_byte_serial( PG_OK );
							//pg_gcp_flag_version = PG_YES;
							return( PG_OK );
						}
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_WRONG_PICGIM_MINOR , PG_ERROR_ERROR );
						#endif
						return( PG_NOK );
					}
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_WRONG_PICGIM_MAJOR , PG_ERROR_ERROR );
					#endif
					return( PG_NOK );
				}
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_WRONG_APPLICATION_MINOR , PG_ERROR_ERROR );
				#endif
				return( PG_NOK );
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_WRONG_APPLICATION_MAIOR , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_VERSION_WRONG_APPLICATION_NAME , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
		//PG_GCP_ERROR_VERSION_FAILED
	}
		
	//#######################################################################
	//---[   E N G A G E   ]---
	//#######################################################################
	//---[ TX - Engage Control ]---
	_pg_Uint8 pg_gcp_engage( void ) {	
		//--------------------------------------------------------------------------
		if( pg_gcp_flag_engage == PG_NO ) {
			#if ( PG_GCP_VERSION_CHECK_ENABLE == PG_ENABLE )
				if( pg_gcp_tx_version() != PG_OK )
					return( PG_NOK );
			#endif
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_ENGAGE ) == PG_OK ) {
				pg_gcp_flag_engage = PG_YES;
				pg_gcp_flag_tx = PG_YES;
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_ENGAGE_LAT = PG_ON;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( PG_OK );
			}
  			// #if ( PG_GCP_AUTORESET_ENGAGE_ENABLE == PG_ENABLE )
				// if( pg_gcp_reset() == PG_OK ) {
					// #if PG_ERROR_IS_ENABLE
						// pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_RESETTED , PG_ERROR_WARNING );
					// #endif
					// return( PG_OK );
				// }
			// #endif
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Engage ]---
	_pg_Uint8 pg_gcp_rx_engage( void ) {
		//--------------------------------------------------------------------------
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ENGAGE_REPLY  );
		#endif
		// #if ( PG_GCP_VERSION_CHECK_ENABLE == PG_ENABLE )
			// if( pg_gcp_rx_version() != PG_YES )
				// return( PG_NOK );
		// #endif
//		pg_gcp_empty_serial(); ???qua?
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_ENGAGE_REPLY );
		pg_gcp_flag_engage = PG_YES;
		pg_gcp_flag_tx = PG_NO;
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
		#endif
		return( PG_OK );
	}
	
	//#######################################################################
	//		E N G A G E   -   E N D
	//#######################################################################
	//---[ TX - Engage End Control ]---
	_pg_Uint8 pg_gcp_engage_end( void ) {	
		//--------------------------------------------------------------------------
		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_ENGAGE_END ) == PG_OK ) {
				pg_gcp_flag_engage = PG_NO;
				pg_gcp_flag_tx = PG_NO;
				//pg_gcp_flag_version = PG_NO;
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_ENGAGE_LAT = PG_OFF;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( PG_OK );
			}
		}	
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_END_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Engage End Control ]---
	_pg_Uint8 pg_gcp_rx_engage_end( void ) {
		//--------------------------------------------------------------------------
		pg_gcp_flag_engage = PG_NO;
		pg_gcp_flag_tx = PG_NO;
		//pg_gcp_flag_version = PG_NO;
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE_END_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ENGAGE_END_REPLY );
		#endif
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_OFF;
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_ENGAGE_END_REPLY );						//rispondere con ':x' per chiudere la comunicazione; si dovra' reiniziare con 'k'
		//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr );	//???? //mod //questa funziona, ma se messa nel main, no! bisogna usare indice 0!?!?
		//get = 0;
		return( PG_OK );
	}
	
	//#######################################################################
	//		D A T A
	//#######################################################################
	//---[ TX - Data Control ]---
	_pg_Uint8 pg_gcp_data( void ) {		
		//--------------------------------------------------------------------------
		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_DATA ) == PG_OK ) {
				pg_gcp_flag_data_mode = PG_YES;
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_DATA_LAT = PG_ON;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( PG_OK );
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_DATA_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Data Control ]---
	_pg_Uint8 pg_gcp_rx_data( void ) {
		//--------------------------------------------------------------------------
		pg_gcp_flag_data_mode = PG_YES;
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_DATA_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_DATA_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_DATA_REPLY );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_DATA_REPLY );
		return( PG_OK );
	}
	
	//#######################################################################
	//		D A T A   -   E N D
	//#######################################################################
	//---[ TX - Data End Control ]---
	_pg_Uint8 pg_gcp_data_end( void ) { 		
		//--------------------------------------------------------------------------
		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_YES ) ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_DATA_END ) == PG_OK ) {
				pg_gcp_flag_data_mode = PG_NO;
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_DATA_LAT = PG_OFF;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( PG_OK );
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_DATA_END_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Data End Control ]---
	_pg_Uint8 pg_gcp_rx_data_end( void ) {
		//--------------------------------------------------------------------------
		pg_gcp_flag_data_mode = PG_NO;
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_DATA_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_DATA_LAT = PG_OFF;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_DATA_END_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_DATA_END_REPLY );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_DATA_END_REPLY );
		return( PG_OK );
	}
	
	//#######################################################################
	//		C O N F I G
	//#######################################################################
	//---[ TX - Config Control ]---
	_pg_Uint8 pg_gcp_config( _pg_Uint8 configuration ) {	
		//--------------------------------------------------------------------------
		if( pg_gcp_flag_engage == PG_YES ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_CONFIG ) == PG_OK ) {
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_CONFIG_LAT = PG_ON;
				#endif
				pg_gcp_send_byte_serial( configuration );
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
					if( pg_gcp_dbyte == configuration ) {
						//pg_gcp_send_byte_serial( PG_GCP_CONFIG_OK );
						pg_gcp_send_byte_serial( PG_OK );
						pg_gcp_nconfig = configuration;
						#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CONFIG_NUMBER == PG_ENABLE ) )
							pg_lcd_hd44780_put_char( 0 , configuration + PG_GCP_DEBUG_CHAR_ASCII_OFFSET  );
						#endif
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_CONFIG_LAT = PG_OFF;
						#endif
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						return( PG_OK );
					}
				}
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CONFIG_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Config Control ]---
	_pg_Uint8 pg_gcp_rx_config( void ) {
		//--------------------------------------------------------------------------
		_pg_Uint8 temp;
		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_CONFIG_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CONFIG_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_CONFIG_REPLY  );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_CONFIG_REPLY );
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
			//pg_gcp_nconfig = pg_gcp_dbyte;
			temp = pg_gcp_dbyte;
			//pg_gcp_send_byte_serial( pg_gcp_nconfig );
			pg_gcp_send_byte_serial( temp );
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				//if( pg_gcp_dbyte == PG_GCP_CONFIG_OK ) {
				if( pg_gcp_dbyte == PG_OK ) {
					pg_gcp_nconfig = temp;
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CONFIG_NUMBER_REPLY == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , pg_gcp_nconfig + PG_GCP_DEBUG_CHAR_ASCII_OFFSET  );
					#endif
					#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
						PG_GCP_LED_CONFIG_LAT = PG_OFF;
					#endif 
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					//return( PG_GCP_OK_CONFIG_DONE );
					return( PG_OK );
				}
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_CONFIG_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );							
	}
	
	//#######################################################################
	//		S T A T U S   -   S Y N C
	//#######################################################################
	//---[ TX - Status Sync Control ]---
	#if ( PG_GCP_STATUS_SYNC_ENABLE == PG_ENABLE )
		_pg_Uint8 pg_gcp_status_sync( void ) {		//ritorna lo stato del buffer a remoto; verifica non possibile
			//--------------------------------------------------------------------------
			// Query receiver (RX) about buffer status value, than sync it on sender (TX).
			//--------------------------------------------------------------------------
			if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
				if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_STATUS_SYNC ) == PG_OK ) {
					pg_gcp_send_byte_serial( PG_GCP_STATUS_WAITING );
					if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
						pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = pg_gcp_dbyte;	//update status on tx
						#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_SYNC == PG_ENABLE ) )
							switch ( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status ) {
								case PG_GCP_BUFFER_EMPTY :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_EMPTY );
								break;
								case PG_GCP_BUFFER_INCOMPLETE :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_INCOMPLETE );
								break;
								case PG_GCP_BUFFER_FULL :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_FULL );
								break;
								case PG_GCP_BUFFER_CRC :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_CRC );
								break;
//									case PG_GCP_BUFFER_DECRYPTED :
//										pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_DECRYPTED );
//									break;
								case PG_GCP_BUFFER_READ :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_READ );
								break;
								default :
									pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_UNKNOWN );
								break;
							}
						#endif
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						return( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status );
					}
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_STATUS_SYNC_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
	#endif
		
	//---[ RX - Status Sync Control ]---
	#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
		_pg_Uint8 pg_gcp_rx_status_sync ( void ) {
			//--------------------------------------------------------------------------
			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STATUS_ENABLE == PG_ENABLE ) )
				PG_GCP_LED_STATUS_LAT = PG_ON;
			#endif
			#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_SYNC_REPLY == PG_ENABLE ) )
				pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_STATUS_SYNC_REPLY );
			#endif
			pg_gcp_send_byte_serial( PG_GCP_CONTROL_STATUS_SYNC_REPLY );								//rispondere con ':d' per richiedere la tx immediata dei dati
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				if( pg_gcp_dbyte == PG_GCP_STATUS_WAITING ) {
					pg_gcp_send_byte_serial( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status );	//send status to tx
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_VALUE == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status );
					#endif
					#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STATUS_ENABLE == PG_ENABLE ) )
						PG_GCP_LED_STATUS_LAT = PG_OFF;
					#endif
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					return( PG_OK );
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_STATUS_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
	#endif	

	//#######################################################################
	//		S T A T U S   -   M O D
	//#######################################################################
	//---[ TX - Status Mod Control ]---
	#if ( PG_GCP_STATUS_MOD_ENABLE == PG_ENABLE )
		_pg_Uint8 pg_gcp_status_mod( _pg_Uint8 value ) {
			//--------------------------------------------------------------------------
			// Set an arbitrary status value and sync it in RX and TX.
			//--------------------------------------------------------------------------
			if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
				if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_STATUS_MOD ) == PG_OK ) {
					//
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , value );
					#endif
					pg_gcp_send_byte_serial( value );
					if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
						if( pg_gcp_dbyte == value ) {
							pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = value; //... e io  faccio qua.
							//pg_gcp_send_byte_serial( PG_GCP_STATUS_MOD_OK );	// che vuol dire "ok fai!" (in rx da implementare) //senza reply
							pg_gcp_send_byte_serial( PG_OK );	// che vuol dire "ok fai!" (in rx da implementare) //senza reply
							#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
								pg_lcd_hd44780_put_char( 0 , '=' );
							#endif
							#if PG_ERROR_IS_ENABLE
								pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
							#endif
							return( PG_OK );
						}
						else {
							#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
								pg_lcd_hd44780_put_char( 0 , '4' );
							#endif
						}
					}
				}
			}
			#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
				pg_lcd_hd44780_put_char( 0 , '5' );
			#endif
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_STATUS_MOD_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
	#endif
	
	//---[ RX - Status Mod Control ]---		
	#if ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE )
		_pg_Uint8 pg_gcp_rx_status_mod( void ) {
			//--------------------------------------------------------------------------
			_pg_Uint8 mtemp;
			
			#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD_REPLY == PG_ENABLE ) )
				pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_STATUS_MOD_REPLY );
			#endif
			pg_gcp_send_byte_serial( PG_GCP_CONTROL_STATUS_MOD_REPLY );
			//
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				mtemp = pg_gcp_dbyte;
				#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD_REPLY == PG_ENABLE ) )
					pg_lcd_hd44780_put_char( 0 , mtemp );
				#endif
				pg_gcp_send_byte_serial( mtemp );
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
					pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = mtemp;
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , '=' );
					#endif
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					return( PG_OK );
				}
				else {
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , '6' );
					#endif
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_MOD_STATUS_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
	#endif
	
	//#######################################################################
	//		S T R E A M I N G
	//#######################################################################
	//---[ TX - Streaming Control ]---
	_pg_Uint8 pg_gcp_streaming( _pg_Uint8 mode ) {	//PG_GCP_STREAMING_ON || PG_GCP_STREAMING_OFF
		//--------------------------------------------------------------------------
		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_YES ) ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_STREAMING ) == PG_OK ) {
				pg_gcp_send_byte_serial( mode );
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
					if( pg_gcp_dbyte == mode ) {
						pg_gcp_flag_streaming = PG_YES;
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_STREAMING_LAT = PG_ON;
						#endif
					}
					else {
						pg_gcp_flag_streaming = PG_NO;
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_STREAMING_LAT = PG_OFF;
						#endif
					}
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					return( PG_OK );
				}
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_STREAMING_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	//??? da verificare
	//---[ RX - Streaming Control ]---
	_pg_Uint8 pg_gcp_rx_streaming( void ) {
		//--------------------------------------------------------------------------
/* 		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_STREAMING_LAT = PG_ON;
		#endif */
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STREAMING_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_STREAMING_REPLY );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_STREAMING_REPLY );
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
			if( pg_gcp_dbyte == PG_GCP_STREAMING_ON ) {
				pg_gcp_flag_streaming = PG_YES;
				pg_gcp_send_byte_serial( PG_GCP_STREAMING_ON );
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_STREAMING_LAT = PG_ON;
				#endif
			}
			else {
				pg_gcp_flag_streaming = PG_NO;
				pg_gcp_send_byte_serial( PG_GCP_STREAMING_OFF );	
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_STREAMING_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_STREAMING_LAT = PG_OFF;
				#endif
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_STREAMING_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//#######################################################################
	//		F U N C T I O N S
	//#######################################################################
/*
	//---[ Save Byte ]---
	_pg_Uint8 pg_gcp_save_byte_buffer( void ) {	
		//--------------------------------------------------------------------------
		//Internal use.
		if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status == PG_GCP_BUFFER_FULL ) {		//pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index = 0; lo azzerera' chi leggera' il buffer!
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_SAVE_BYTE_BUFFER_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
		pg_gcp_bindex = pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index;											//copio la posizione del vettore della config attuale in bindex, per chiarezza.
		*(_pg_Uint8 *)(pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr + pg_gcp_bindex ) = pg_gcp_dbyte;				//scrivo il dato	//ex: pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr[ pg_gcp_bindex ] = pg_gcp_dbyte;							
		pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index = ( pg_gcp_bindex + 1 );									//salvo l'indice della posizione nel buffer del config attuale //punta alla prossima posizione in cui scrivere.
		if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index == pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_length ) { //sono gia' entrambi maggiori di una unita' rispetto al massimo valore acquisibile dall'indice
			if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_mode != PG_GCP_STRING ) {									//se sto scrivendo una stringa ed arrivo esattamnte in fondo con lo 0 a riempire il buffer, si setta due volte il buffer_full uno con la write-byte e l'altro con la send-string e nel mentre la read lo azzeera ad empty, quindi stampa 2 volte. Quindi con le stringhe qui non si setta il full .
				pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_FULL;								//se sono arrivato in fondo al buffer setto il full!
			}
		}
		else {
			pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_INCOMPLETE;
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
		#endif
		return( PG_OK );
	}
*/
	
	//---[ Save Byte ]---
	_pg_Uint8 pg_gcp_save_byte_buffer( void ) {	
		//--------------------------------------------------------------------------
		//Internal use.
		#if ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE )
			pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status );
		#endif
		
		if( ( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status == PG_GCP_BUFFER_EMPTY ) || 		//Se FULL non si sovrascrive; se READ bisogna prima azzerare indice etc... quindi ci pensa la set_empty()
			( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status == PG_GCP_BUFFER_INCOMPLETE ) ) {
			//Write it!
			pg_gcp_bindex = pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index;											//copio la posizione del vettore della config attuale in bindex, per chiarezza.
			*(_pg_Uint8 *)(pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr + pg_gcp_bindex ) = pg_gcp_dbyte;				//scrivo il dato	//ex: pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr[ pg_gcp_bindex ] = pg_gcp_dbyte;							
			pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index = ( pg_gcp_bindex + 1 );									//salvo l'indice della posizione nel buffer del config attuale //punta alla prossima posizione in cui scrivere.
			if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index == pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_length ) { //sono gia' entrambi maggiori di una unita' rispetto al massimo valore acquisibile dall'indice
				if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_mode != PG_GCP_STRING ) {									//se sto scrivendo una stringa ed arrivo esattamnte in fondo con lo 0 a riempire il buffer, si setta due volte il buffer_full uno con la write-byte e l'altro con la send-string e nel mentre la read lo azzeera ad empty, quindi stampa 2 volte. Quindi con le stringhe qui non si setta il full .
					pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_FULL;								//se sono arrivato in fondo al buffer setto il full!
				}
			}
			else {
				pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_INCOMPLETE;
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_SAVE_BYTE_BUFFER_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );		
	}

	//---[ Rx Data Ready ]---
	_pg_Uint8 pg_gcp_rx_data_ready( void ) {
		//--------------------------------------------------------------------------
		for( ; pg_gcp_rdr_index < ( PG_GCP_CONFIGS_NUMBER + 1 ); pg_gcp_rdr_index++ ) {
			if( pg_gcp_v_config[ pg_gcp_rdr_index ].xbuffer_status == PG_GCP_BUFFER_FULL ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( pg_gcp_rdr_index );
			}
		}
		pg_gcp_rdr_index = 0;
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_DATA_READY_NO , PG_ERROR_WARNING );
		#endif
		return PG_GCP_RX_DATA_READY_NO;
		//return( PG_NOK ); scrive male lcd rx  //???!!!
	}
	
	//---[ Rx Data Read ]---
	_pg_Uint8 * pg_gcp_rx_data_read( void ) {	//USARE QUESTA PER LEGGERE BUFFER o STRINGA, oppure la pg_gcp_read() utente.
		//--------------------------------------------------------------------------
		if( pg_gcp_v_config[ pg_gcp_rdr_index ].xbuffer_status == PG_GCP_BUFFER_FULL ) {
			pg_gcp_v_config[ pg_gcp_rdr_index ].xbuffer_status = PG_GCP_BUFFER_EMPTY;
			pg_gcp_v_config[ pg_gcp_rdr_index ].xbuffer_index = 0;
			return( pg_gcp_v_config[ pg_gcp_rdr_index ].xbuffer_ptr );
		}
	}
	
	//---[ RX Set Empty ]---
	void pg_gcp_rx_set_empty( void ) {
		//--------------------------------------------------------------------------
		// Checking for buffer "read" and set ALL them "empty".
		for( ; pg_gcp_rde_index < ( PG_GCP_CONFIGS_NUMBER + 1 ); pg_gcp_rde_index++ ) {
			if( pg_gcp_v_config[ pg_gcp_rde_index ].xbuffer_status == PG_GCP_BUFFER_READ ) {
				pg_gcp_v_config[ pg_gcp_rde_index ].xbuffer_status = PG_GCP_BUFFER_EMPTY;
				pg_gcp_v_config[ pg_gcp_rde_index ].xbuffer_index = 0;
			}
		}
		pg_gcp_rde_index = 0;
	}
	
	//---[ Tx Byte Serial ]---
	_pg_Uint8 pg_gcp_send_byte_serial( _pg_Uint8 sbyte ) {		
		//--------------------------------------------------------------------------
		//Internal use.
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_TX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_TX_LAT = PG_ON;
		#endif
		while( BusyUSART() );
		WriteUSART( sbyte );
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_TX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_TX_LAT = PG_OFF;
		#endif
	}
	 
	//---[ Read Byte Serial ]---
	_pg_Uint8 pg_gcp_read_byte_serial( _pg_Uint16 tdelay ) { //Blocking (streaming) or NOT-Blocking
		//--------------------------------------------------------------------------
		//Internal use.
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_RX_LAT = PG_ON;
		#endif		
		while( 1 ) {
			if( DataRdyUSART() ) { //DataRdyUSART() ret 1 if data is present.
				pg_gcp_dbyte = ReadUSART();
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_RX_LAT = PG_OFF;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				return( PG_OK );
			}
			else {
				if( pg_gcp_flag_streaming ) {
					continue; //Blocking
				}		
				else { //NOT-Blocking
					pg_delay_msec( 1 );
					tdelay--;
					if( !tdelay ) {
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_RX_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_RX_LAT = PG_OFF;
						#endif
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_READ_BYTE_SERIAL_TIMEOUT , PG_ERROR_WARNING );
						#endif
 						 #if ( PG_GCP_AUTORESET_TIMEOUT == PG_ENABLE )
							 if( pg_gcp_flag_tx == PG_YES ) {	//TX reset remote ad local
								 pg_gcp_reset( );
							 }
							 if( pg_gcp_flag_tx == PG_NO ) {		//RX reset only local
								 pg_gcp_reset_local( );
							 } 
						 #endif
						return( PG_NOK );
					}
				}
			}
		}
	}
	
	//---[ Tx Control Byte ]---
	_pg_Uint8 pg_gcp_tx_control_byte( _pg_Uint8 control ) {
		//--------------------------------------------------------------------------
		//Internal use.
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ESCAPE == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ESCAPE  );
		#endif
		//---[ Tx Escape ]---
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_ESCAPE );
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_TX ) == PG_OK ) {
			if( pg_gcp_dbyte == PG_GCP_CONTROL_ESCAPE_REPLY ) {
				switch( control ) {
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_RESET == PG_ENABLE ) )
						case PG_GCP_CONTROL_RESET :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_RESET );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE == PG_ENABLE ) )
						case PG_GCP_CONTROL_ENGAGE :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ENGAGE  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE_END == PG_ENABLE ) )
						case PG_GCP_CONTROL_ENGAGE_END :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ENGAGE_END  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_DATA == PG_ENABLE ) )
						case PG_GCP_CONTROL_DATA :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_DATA  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_DATA_END == PG_ENABLE ) )
						case PG_GCP_CONTROL_DATA_END :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_DATA_END  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CONFIG == PG_ENABLE ) )
						case PG_GCP_CONTROL_CONFIG :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_CONFIG  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_SYNC == PG_ENABLE ) )
						case PG_GCP_CONTROL_STATUS_SYNC :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_STATUS_SYNC  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
						case PG_GCP_CONTROL_STATUS_MOD :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_STATUS_MOD  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_REQUEST == PG_ENABLE ) )
						case PG_GCP_CONTROL_REQUEST :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_REQUEST  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC == PG_ENABLE ) )
						case PG_GCP_CONTROL_CRC :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_CRC  );
						break;
					#endif
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_VERSION == PG_ENABLE ) )
						case PG_GCP_CONTROL_VERSION :
							pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_VERSION  );
						break;
					#endif
				}
				//---[ Tx Control ]---
				pg_gcp_send_byte_serial( control );						
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
					if( pg_gcp_dbyte == ( control + PG_GCP_REPLY_OFFSET_ADD ) ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					return( PG_OK );
					}
 					else{
						//se ritorna un reply diverso da quello atteso
						// #if ( PG_GCP_AUTORESET_CONTROLBYTE_ENABLE == PG_ENABLE )
							// if( pg_gcp_reset() == PG_OK ) {
								// #if PG_ERROR_IS_ENABLE
									// pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CONTROLBYTE_RESETTED , PG_ERROR_WARNING );
								// #endif
								// return( PG_NOK );
							// }
						// #endif
					}
				}
			}
 			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_TX_CONTROL_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
  		// #if ( PG_GCP_AUTORESET_CONTROLBYTE_ENABLE == PG_ENABLE )
			// if( pg_gcp_reset() == PG_OK ) {
				// #if PG_ERROR_IS_ENABLE
					// pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CONTROLBYTE_RESETTED , PG_ERROR_WARNING );
				// #endif
				// return( PG_NOK );
			// }
		// #endif
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CONTROLBYTE_RESET_FAIL , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
		
	//---[ Tx Buffer Control ]---
	_pg_Uint8 pg_gcp_tx_buffer( _pg_Uint8 * tbuffer ) {		
		//--------------------------------------------------------------------------
		_pg_Uint16 idx;
		
		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_YES ) ) {
			for( idx = 0; idx < pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_length; idx++ ) {			//i buffer devono esere uguali
				#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_TX_BUFFER == PG_ENABLE ) )
					pg_lcd_hd44780_put_char( 0 , tbuffer[ idx ]  );
				#endif
				pg_gcp_send_byte_serial( tbuffer[ idx ] );
				if  ( tbuffer[idx] == PG_GCP_CONTROL_ESCAPE )
					pg_gcp_send_byte_serial( tbuffer[ idx ] );
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_TX_BUFFER_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ Tx String Control ]---
	_pg_Uint8 pg_gcp_tx_string( _pg_Uint8 * tstring ) {		
		//--------------------------------------------------------------------------
		//String must be null terminated.
		_pg_Uint16 sidx = 0;

		if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_YES ) ) {
			while( tstring[ sidx ] ) {
				pg_gcp_send_byte_serial( tstring[ sidx ] );
				if ( tstring[ sidx ] == PG_GCP_CONTROL_ESCAPE )
					pg_gcp_send_byte_serial( tstring[ sidx++ ] );
				//sidx++;
			}
			pg_gcp_send_byte_serial( 0 );	//add null to terminate string
			pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index--;	//one step back to sync length for crc 
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_TX_STRING_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//#######################################################################
	//		R X
	//#######################################################################
	//---[ Rx ]---
	_pg_Uint8 pg_gcp_rx( void ) {		//BLOCKING (streaming)or NOT BLOCKING!!! Verifica per il tempo ( PG_GCP_TIMEOUT_MS ) se e' arrivato un byte e ritorna... richiamarla a ciclo dal main... Se BYTEDELAY=0 bloccante fino alla ricezione di un byte.
		//--------------------------------------------------------------------------
		while( 1 ) {
			pg_gcp_rx_set_empty();
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_RX ) == PG_OK ) {
				//---[ Escape ]---
				if( pg_gcp_dbyte == PG_GCP_CONTROL_ESCAPE ) {
					//--------------------------------------------------------------------------
					//---[ Control Mode ]-------------------------------------------------------
					//--------------------------------------------------------------------------
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ESCAPE_REPLY == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ESCAPE_REPLY  );
					#endif
					pg_gcp_send_byte_serial( PG_GCP_CONTROL_ESCAPE_REPLY );
					if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
						//--------------------------------------------------------------------------
						//---[ Any Status ]---
						//--------------------------------------------------------------------------
						if( pg_gcp_dbyte == PG_GCP_CONTROL_RESET ) {
							//---[ Reset  ]---
							return( pg_gcp_rx_reset() );
						}
						if( pg_gcp_dbyte == PG_GCP_CONTROL_VERSION ) {
							//---[ Version Check ]---
							return( pg_gcp_rx_version() );
						}
						if( pg_gcp_dbyte == PG_GCP_CONTROL_COMMAND ) {
							//---[ Command ]---
							//chiamare i puntatori a funzione per eseguire i comandi com feedback verso tx
							//typedef		void (* pg_Uint8(_cb_ptr)(void);
							//aggiungere comandi utente (callback )da passare a remoto #16
							return( pg_gcp_rx_command() );
						}
						//--------------------------------------------------------------------------
						//---[ Status NOT Engaged ]---
						//--------------------------------------------------------------------------
						if( pg_gcp_flag_engage == PG_NO ) {
							//---[ Engage ]---
							if( pg_gcp_dbyte == PG_GCP_CONTROL_ENGAGE ) {
								return( pg_gcp_rx_engage() );
							}
						}
						//--------------------------------------------------------------------------
						//---[ Status Engaged - Data Mode Independently ]---
						//--------------------------------------------------------------------------
						else {
							//---[ Config ]---
							if( pg_gcp_dbyte == PG_GCP_CONTROL_CONFIG) {
								return( pg_gcp_rx_config() );
							}
							//--------------------------------------------------------------------------
							//---[ Status Engaged && Data-Mode ]---
							//--------------------------------------------------------------------------
							if( pg_gcp_flag_data_mode == PG_YES ) {
								//---[ Escape-Char ]---
								if( pg_gcp_dbyte == PG_GCP_CONTROL_ESCAPE ) { //"Escape-char" as valid data.
									return( pg_gcp_rx_escape() );
								}
								//---[ Data End ]---
								if( pg_gcp_dbyte == PG_GCP_CONTROL_DATA_END ) {
									return( pg_gcp_rx_data_end() );
								}
							}
							//--------------------------------------------------------------------------
							//---[ Status Engaged but NO-Data-Mode ]---
							//--------------------------------------------------------------------------
							else {
								//---[ Data ]---
								if( pg_gcp_dbyte == PG_GCP_CONTROL_DATA ) {
									return( pg_gcp_rx_data() );
								}
								//---[ Engage End ]---
								if( pg_gcp_dbyte == PG_GCP_CONTROL_ENGAGE_END ) {
									return( pg_gcp_rx_engage_end() );
								}
								//---[ Status Sync ]---
								#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
									if( pg_gcp_dbyte == PG_GCP_CONTROL_STATUS_SYNC ) {
										return( pg_gcp_rx_status_sync() );
									}
								#endif
								//---[ Status Mod ]---		
								#if ( PG_GCP_STATUS_MOD_ENABLE ==  PG_ENABLE )
									if( pg_gcp_dbyte == PG_GCP_CONTROL_STATUS_MOD ) {
										return( pg_gcp_rx_status_mod() );
									}
								#endif
								//---[ Request ]---
								#if ( PG_GCP_REQUEST_ENABLE == PG_ENABLE )
									if( pg_gcp_dbyte == PG_GCP_CONTROL_REQUEST ) {
										return( pg_gcp_rx_request() );
									}
								#endif
								//---[ Crc ]---
								#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )	
									if( pg_gcp_dbyte == PG_GCP_CONTROL_CRC ) {
										return( pg_gcp_rx_crc() );
									}
								#endif
							}
						}
					}
					else {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_CONTROL_TIMEOUT , PG_ERROR_WARNING );
						#endif
						return( PG_NOK );
					}
				}	
				else {
					//--------------------------------------------------------------------------
					//---[ Data Mode ]----------------------------------------------------------
					//--------------------------------------------------------------------------
					if( pg_gcp_flag_engage == PG_YES ) {	//evita scrivere byte sporchi all'accensione!!!!!!!!!!
						if( pg_gcp_flag_streaming == PG_YES ) {
							return( pg_gcp_dbyte ); 		//meglio passare il ptr &pg_gcp_dbyte?
						}
						else {
							pg_gcp_save_byte_buffer( );		//Save data byte in buffer (no streaming)
						}
					}
				}
			}
			else {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_BYTE_TIMEOUT , PG_ERROR_WARNING );
				#endif
				//return(  PG_GCP_ERROR_RX_BYTE_TIMEOUT );	//NO "byte: control or data" on rx buffer over waiting time!
				return( PG_NOK );
			}
		}
	}

	//---[ RX - Escape ]---
	_pg_Uint8 pg_gcp_rx_escape( void ) {
		//--------------------------------------------------------------------------
		if( pg_gcp_flag_streaming == PG_YES ) {
			return( pg_gcp_dbyte );
		}
		else {
			pg_gcp_save_byte_buffer( );
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
	}
	
	//#######################################################################
	//		C R C
	//#######################################################################
	#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
		//---[ TX - Crc Control ]---
		_pg_Uint8 pg_gcp_crc( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length ) {			//buffer trasmesso	//da utilizzare prima della read che azzera "index" e setta "empty"!!!	
			//--------------------------------------------------------------------------	//la lunghezza potra' essere di tutto il buffer o, nel caso di una stringa piu' corta del buffer, la lunghezza della sola stringa (ovviamente dovra' essere chiamata la "set_full" ed in rx si usera' (sempre?) l'"index -1" come lunghezza su cui fare la crc.
			_pg_Uint16 i;
			
			if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
				if( pg_gcp_crc32_calc( cbuffer, cbuffer_length ) == PG_OK ) { 			//Adesso in pg_gcp_crc32_local.Val c'e' la crc da 32bit del buffer trasmesso; non verifichiamo cosa ritorna la crc32...
					#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
						PG_GCP_LED_CRC_LAT = PG_ON;
					#endif
					if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_CRC ) == PG_OK ) {
						for( i = 0; i < 4; i++ ) {
							#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC_BYTE == PG_ENABLE ) )
								pg_lcd_hd44780_put_char( 0 , pg_gcp_crc32_local.v[ i ]  );
							#endif
							pg_gcp_send_byte_serial( pg_gcp_crc32_local.v[ i ] );
							if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) != PG_OK ) {
								#if PG_ERROR_IS_ENABLE
									pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CRC_TX_FAILED , PG_ERROR_ERROR );
								#endif
								return( PG_NOK );
							}	
						}
						if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_CRC ) == PG_OK ) {
							//if( pg_gcp_dbyte == PG_GCP_CRC_OK ) {
							if( pg_gcp_dbyte == PG_OK ) {
								#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC_OK == PG_ENABLE ) )
									pg_lcd_hd44780_put_char( 0 , '=' );
								#endif
								#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
									PG_GCP_LED_CRC_LAT = PG_OFF;
								#endif
								#if PG_ERROR_IS_ENABLE
									pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
								#endif
								
								pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_CRC;
								//fatto
								//pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_CRC;
								//oppure chiamare la sync (ma attenzione che e' disabilitabiile!!!)...
								// ... ed in tal caso, alla 1016 aggingere
								// case PG_GCP_BUFFER_CRC :
									// pg_lcd_hd44780_put_char( 0 , PG_GCP_BUFFER_CRC );
								// break;
								
								
								
								//return( PG_OK );
								//return( PG_GCP_CRC_OK ); //??? PG_YES
								return( PG_OK ); //??? PG_YES
							}
							else {
								#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_STATUS_MOD == PG_ENABLE ) )
									pg_lcd_hd44780_put_char( 0 , '1' );
								#endif
								#if PG_ERROR_IS_ENABLE
									pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CRC_COMPARE_FAILED , PG_ERROR_ERROR );
								#endif
								return( PG_NOK );
							}
						}
					}
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CRC32_CANNOT_MATH , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
		
		//---[ RX - Crc ]---
		_pg_Uint8 pg_gcp_rx_crc( void ) {
		//--------------------------------------------------------------------------
			_pg_Uint8 c;
				
			#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
				PG_GCP_LED_CRC_LAT = PG_ON;
			#endif
			#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC_REPLY == PG_ENABLE ) )
				pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_CRC_REPLY );
			#endif
			pg_gcp_send_byte_serial( PG_GCP_CONTROL_CRC_REPLY );
			for( c = 0; c < 4; c++ ) {
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_CRC ) == PG_OK ) {
					pg_gcp_crc32_remote.v[ c ] = pg_gcp_dbyte;
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_WAITING_DATA == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , pg_gcp_dbyte );
					#endif
					pg_gcp_send_byte_serial( PG_GCP_WAITING_DATA );
				}
				else {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_CRC_TIMEOUT , PG_ERROR_ERROR );
					#endif
					return( PG_NOK );
				}
			}
			pg_gcp_crc32_calc( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr, ( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_index - 1 ) );	//calcolo crc locale buffer attivo, usando come lunghezza, non quella del buffer ma quella dell'"index - 1", cosi' da poterlo calcolare anche per le stringhe piu' corte della lunghezza del buffer intero, dopo aver usato la "set_full".
			if( ( pg_gcp_crc32_local.Val - pg_gcp_crc32_remote.Val ) == 0 ) {
				#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC_OK == PG_ENABLE ) )
					pg_lcd_hd44780_put_char( 0 , '=' );
				#endif
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CRC_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_CRC_LAT = PG_OFF;
				#endif
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
				#endif
				pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_status = PG_GCP_BUFFER_CRC;
				//pg_gcp_send_byte_serial( PG_GCP_CRC_OK );
				pg_gcp_send_byte_serial( PG_OK );
				return( PG_OK );
			}
			else {
				#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CRC_FAILED == PG_ENABLE ) )
					pg_lcd_hd44780_put_char( 0 , '2' );
				#endif
				pg_gcp_send_byte_serial( PG_GCP_ERROR_CRC_FAILED );
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_CRC_COMPARE_FAILED , PG_ERROR_ERROR );
				#endif
				return( PG_NOK );
			}
		}
	
		//---[ Crc32 ]---
		_pg_Uint8 pg_gcp_crc32_calc( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length ) {      // mi hai detto generica e se generica deve essere allora generico puntatore a buffer e generica lunghezza.
			//--------------------------------------------------------------------------
			//Internal use.
			_pg_Uint16 m;
			
			if( cbuffer_length < 1 ) {    // così escludiamo gli stream //??? verificare condizione: ora c'e' un flag...
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CRC32_CANNOT_MATH , PG_ERROR_ERROR );
				#endif
				return( PG_NOK );
			}
			pg_gcp_crc32_local.Val = 0;
			for( m = 0; m < cbuffer_length ; m++ ) {
				if( m % 1 ) {
					pg_gcp_crc32_local.Val -= *( cbuffer + m );
				}
				else {
					pg_gcp_crc32_local.Val *= *( cbuffer + m );
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}		
	#endif
		
	//#######################################################################
	//		R E Q U E S T
	//#######################################################################
	
	#if ( PG_GCP_REQUEST_ENABLE == PG_ENABLE )
		//---[ RX - Request Set ]---
		void pg_gcp_request_set( _pg_Uint8 qvalue ) {	//PG_YES or PG_NO
			//--------------------------------------------------------------------------
			//User set flag PG_YES or PG_NO by this function.
			//Tx ask rx flag value by Request-Control.
			//If flag is set, they run pg_gcp_engage_end() togheter.
			//
			#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_REQUEST == PG_ENABLE ) )
				pg_lcd_hd44780_put_char( 0 , '3' );
			#endif
			pg_gcp_flag_request = qvalue;
		}
		
		//---[ TX - Request Control ]---
		_pg_Uint8 pg_gcp_request( void ) {
			//--------------------------------------------------------------------------
			_pg_Uint8 qtemp;
			
			if( ( pg_gcp_flag_engage == PG_YES ) && ( pg_gcp_flag_tx == PG_YES ) && ( pg_gcp_flag_data_mode == PG_NO ) ) {
				if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_REQUEST ) == PG_OK ) {
					if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
						//pg_gcp_dbyte = qtemp;
						qtemp = pg_gcp_dbyte;
						pg_gcp_send_byte_serial( qtemp );
						if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
							if( pg_gcp_dbyte == PG_OK ) {
								pg_gcp_engage_end( );	//Tx release channel occupation and clear tx flag.
								pg_gcp_flag_tx = PG_NO;
								#if PG_ERROR_IS_ENABLE
									pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
								#endif
								return( PG_OK );
							}
						}		
					}						
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_REQUEST_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
		
		//---[ RX - Request ]---
		_pg_Uint8 pg_gcp_rx_request( void ) {
			//--------------------------------------------------------------------------
			pg_gcp_send_byte_serial( PG_GCP_CONTROL_REQUEST_REPLY );
			pg_gcp_send_byte_serial( pg_gcp_flag_request );
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				if( pg_gcp_dbyte == pg_gcp_flag_request ) {
					pg_gcp_flag_request = PG_NO;
					//il flag_tx lo setta l'engage e lo cancella il tx qua sopra
					pg_gcp_send_byte_serial( PG_OK );
					//Now rx can call engage then transmit.
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					return( PG_OK );
				}
			}
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_REQUEST_FAILED , PG_ERROR_ERROR );
			#endif
			return( PG_NOK );
		}
	#endif
	
	//#######################################################################
	//		C O M M A N D
	//#######################################################################
	//---[ TX - Command Control ]---
	_pg_Uint8 pg_gcp_command( _pg_Uint8 command ) {	
		//--------------------------------------------------------------------------
		if( pg_gcp_flag_engage == PG_YES ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_COMMAND ) == PG_OK ) {
				#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) )
					PG_GCP_LED_COMMAND_LAT = PG_ON;
				#endif
				pg_gcp_send_byte_serial( command );
				if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
					if( pg_gcp_dbyte == command ) {
						//pg_gcp_send_byte_serial( PG_GCP_COMMAND_OK );
						pg_gcp_send_byte_serial( PG_OK );
						
						//utilizzare qua parametro command, se necessario...
						
						#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_CONFIG_NUMBER == PG_ENABLE ) )
							pg_lcd_hd44780_put_char( 0 , command + PG_GCP_DEBUG_CHAR_ASCII_OFFSET  );
						#endif
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_CONFIG_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_COMMAND_LAT = PG_OFF;
						#endif
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						return( PG_OK );
					}
				}
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_COMMAND_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Command ]---
	_pg_Uint8 pg_gcp_rx_command( void ) {
		//--------------------------------------------------------------------------
		_pg_Uint8 ctemp;
		
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_COMMAND_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_COMMAND_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_COMMAND_REPLY  );
		#endif
		pg_gcp_send_byte_serial( PG_GCP_CONTROL_COMMAND_REPLY );
		if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
			ctemp = pg_gcp_dbyte;
			pg_gcp_send_byte_serial( ctemp );
			if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
				//if( pg_gcp_dbyte == PG_GCP_COMMAND_OK ) {
				if( pg_gcp_dbyte == PG_OK ) {
					
					//utilizzare qua "ctemp" che contiene il parametro command ricevuto...
					//Asy will work here...
					
					#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_COMMAND_NUMBER_REPLY == PG_ENABLE ) )
						pg_lcd_hd44780_put_char( 0 , ctemp + PG_GCP_DEBUG_CHAR_ASCII_OFFSET  );
					#endif
					#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_COMMAND_ENABLE == PG_ENABLE ) )
						PG_GCP_LED_COMMAND_LAT = PG_OFF;
					#endif 
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
					#endif
					//return( PG_GCP_OK_CONFIG_DONE );
					return( PG_OK );
				}
			}
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_COMMAND_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );							
	}
	
	//#######################################################################
	//		U S E R   F U N C T I O N
	//#######################################################################
	//---[ User Send Buffer/String ]---
	_pg_Uint8 pg_gcp_send( void * buffer_pointer, _pg_Uint8 config, _pg_Uint8 crc_flag ) {
		//--------------------------------------------------------------------------	
		//	<* user-buffer-ptr>, PG_GCP_CONFIG_xx, PG_CRC_ON/OFF
		//	User must call only engage() before.
		//--------------------------------------------------------------------------
		//	con le stringhe bisogna avere la status_mod... verificare.
		if( pg_gcp_flag_engage == PG_YES ) {
			//data
			if( pg_gcp_flag_data_mode == PG_NO ) {
				if( pg_gcp_data() != PG_OK ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_DATA_FAILED , PG_ERROR_ERROR );
					#endif
					return( PG_NOK );
				}
			}	
			//config
			if( pg_gcp_config( config ) != PG_OK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CONFIG_FAILED , PG_ERROR_ERROR );
				#endif
				return( PG_NOK );
			}
			//buffer
			if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_mode == PG_GCP_BUFFER ) {
				if( pg_gcp_tx_buffer( buffer_pointer ) != PG_OK ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_TX_BUFFER_FAILED , PG_ERROR_ERROR );
					#endif
					return( PG_NOK );
				}
			}
			//string
			if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_mode == PG_GCP_STRING ) {
				if( pg_gcp_tx_string( buffer_pointer ) != PG_OK ) {
					#if PG_ERROR_IS_ENABLE
						pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_TX_STRING_FAILED , PG_ERROR_ERROR );
					#endif
					return( PG_NOK );
				}
			}
			//data_end
			if( pg_gcp_data_end() != PG_OK ) {
				#if PG_ERROR_IS_ENABLE
					pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_DATA_END_FAILED , PG_ERROR_ERROR );
				#endif
				return( PG_NOK );
			}
			//status_mod //???
			#if ( PG_GCP_STATUS_MOD_ENABLE == PG_ENABLE )
				if( pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_mode == PG_GCP_STRING ) {
					if( pg_gcp_status_mod( PG_GCP_BUFFER_FULL ) != PG_OK ) {
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_STATUS_MOD_FAILED , PG_ERROR_ERROR );
						#endif
						return( PG_NOK );
					}
				}
			#endif
			//crc
			#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
				if( crc_flag == PG_YES ) {
					if( pg_gcp_crc( buffer_pointer, pg_gcp_v_config[ config ].xbuffer_length ) != PG_OK ) {
						//pg_gcp_v_config[ config ].xbuffer_length per i buffer; gestire per le stringhe
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_CRC_FAILED , PG_ERROR_ERROR );
						#endif
						return( PG_NOK );
					}
				}
			#endif
			//
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_NO , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ User Data Read ]---
	//_pg_Uint8 *	pg_gcp_read( void ) {
	_pg_Uint8	pg_gcp_read( void ) {
		//--------------------------------------------------------------------------
		// Checking for buffer "full" and set only it "read".
		// Return a ptr to the first full buffer/string user data struct.
		if( pg_gcp_flag_engage == PG_YES ) {
			for( ; pg_gcp_rdu_index < ( PG_GCP_CONFIGS_NUMBER + 1 ); pg_gcp_rdu_index++ ) {
				#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
					if( pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status == PG_GCP_BUFFER_CRC ) {	//CRC
						pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status = PG_GCP_BUFFER_READ;
						//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status );
						//Fill user struct
						pg_gcp_udata.uconf = pg_gcp_rdu_index;
						pg_gcp_udata.uptr = pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_ptr;
						pg_gcp_udata.ulen = ( pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_index - 1 );	// index for buffer and string (no .length)
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						//return( &pg_gcp_udata );
						return( PG_OK );
					}
				#else
					if( pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status == PG_GCP_BUFFER_FULL ) { //FULL
						pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status = PG_GCP_BUFFER_READ;
						//pg_lcd_hd44780_put_char( 0 , pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_status );
						//Fill user struct
						pg_gcp_udata.uconf = pg_gcp_rdu_index;
						pg_gcp_udata.uptr = pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_ptr;
						pg_gcp_udata.ulen = ( pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_index - 1 );	// index for buffer and string (no .length)
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						//return( &pg_gcp_udata );
						return( PG_OK );
					}
				#endif
			}
			pg_gcp_rdu_index = 0;
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_RX_DATA_READY_NO , PG_ERROR_WARNING );
			#endif
			return( PG_NOK );
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_NO , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );		
	}
	
#endif
		
		
		


//strlen in rx se funziona...
//r307 e r270 tempi reset
//tx a richiesta o continua
//autoreset non funziona se si schianta l'rx dentro il controllo config o crc perche' e' messa solo dentro la send-control; nella control ci sono 2 autoreset...

//se crc abilitata la read-user deve leggere non il full, ma il crc-ok




	

		
		
	
	
		
				

 
 
 
 
 
 
 
 //main
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

#define	PG_GCP_DEBUG_DELAY				1
#define	PG_GCP_DEBUG_DELAY_TIME1		500
#define	PG_GCP_DEBUG_DELAY_TIME2		3000
void main( void ) {

	_pg_Uint8 buffer_to_tx[ 4 ] = "aaa";			//buffer creati dell' utente con stesse dimensioni del pg_gcp_buffer_rx_1[5] del protocollo opposto
	_pg_Uint8 mys[ 4 ];
	_pg_Uint16 num = 0;
	
	pg_initialize( );
	pg_serial_open();
	pg_lcd_hd44780_clear( 0 );
 	pg_gcp_init( );
	//pg_lcd_hd44780_put_char( 0 , 'T' );
	//pg_delay_sec( 1 );
	//if( PG_GCP_DEBUG_DELAY ) pg_delay_msec( PG_GCP_DEBUG_DELAY_TIME1 );
	
		pg_gcp_engage( );
	while( 1 ) {
																				
		
		la crc da togliere !!! modulo a parte (anche se funzionava... :(   
		
		
		pg_gcp_send( itoa( num, mys ), PG_GCP_CONFIG_01, PG_GCP_CRC_ON );
		num++;																		
		//pg_gcp_status_sync( );
																				
		//pg_gcp_crc( buffer_to_tx, 3 );
																				
		
		pg_delay_sec( 1 );
		//pg_gcp_reset( );
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
	//_pg_Uint8	mystr[ 6 ];
	
	pg_initialize( );
	pg_gcp_init( );
	pg_serial_open( );
	pg_lcd_hd44780_clear( 0 );
	//pg_lcd_hd44780_put_char( 0 , 'R' );
	//pg_delay_sec( 1 );
	
 	while( 1 ) {
		pg_gcp_rx();
		
		if( pg_gcp_read() != PG_NOK ) {
			pg_lcd_hd44780_put_char( 0 , ( pg_gcp_udata.uconf + 48 ) );
			pg_lcd_hd44780_write_string( 0 , pg_gcp_udata.uptr );
			pg_lcd_hd44780_put_char( 0 , ( pg_gcp_udata.ulen + 48 ) );
			
		pg_delay_sec( 1 );
		pg_lcd_hd44780_clear( 0 );
		}
		
		
		//pg_lcd_hd44780_write_string( 0 , ( itoa( pg_gcp_udata.ulen, mystr ) ) );
		
		//_pg_Uint8 *	pg_gcp_read( void ) {
		//pg_gcp_udata.uconf = pg_gcp_rdu_index;
		//pg_gcp_udata.uptr = pg_gcp_v_config[ pg_gcp_rdu_index ].xbuffer_ptr;
		//pg_gcp_udata.len = ( p
					
					
		//if( pg_gcp_rx_data_ready() != PG_GCP_RX_DATA_READY_NO ) {
			//pg_lcd_hd44780_put_char( 0 , pg_gcp_nconfig + 48 );				//config attuale !!!
			//pg_lcd_hd44780_put_char( 0 , rdr + 48 );						//config attuale !!!
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 0 ].xbuffer_ptr );	//ok	???
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ 1 ].xbuffer_ptr );	//atroie
			//*(_pg_int16 *)(pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr + 2) = 0;
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_v_config[ pg_gcp_nconfig ].xbuffer_ptr );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read() );	//ok	???
			//pg_lcd_hd44780_put_char( 0 , *pg_gcp_rx_data_read() );
			//pg_lcd_hd44780_write_string( 0 , pg_gcp_rx_data_read() );
		//}
	}
	PG_HALT;
}



*/




/*






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
		if( pg_gcp_engage() != PG_OK ) {	
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
 
 
 /*
	primo tentativo con version inglobata
 	//#######################################################################
	//		E N G A G E
	//#######################################################################
	//---[ TX - Engage Control ]---
	_pg_Uint8 pg_gcp_engage( void ) {	
		//--------------------------------------------------------------------------
		if( pg_gcp_flag_engage == PG_NO ) {
			if( pg_gcp_tx_control_byte( PG_GCP_CONTROL_ENGAGE ) == PG_OK ) {
			//if( pg_gcp_send_byte_serial( PG_GCP_CONTROL_ENGAGE ) == PG_OK ) {
				//---[ Version Check ]---
				//if( pg_gcp_tx_version() == PG_OK ) {
					if( pg_gcp_read_byte_serial( PG_GCP_TIMEOUT_MS_DIAL ) == PG_OK ) {
						if( pg_gcp_dbyte == PG_GCP_CONTROL_ENGAGE_REPLY )
						pg_gcp_flag_engage = PG_YES;
						pg_gcp_flag_tx = PG_YES;
						#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
							PG_GCP_LED_ENGAGE_LAT = PG_ON;
						#endif
						#if PG_ERROR_IS_ENABLE
							pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
						#endif
						return( PG_OK );
					}
				//}
			}
   			// #if ( PG_GCP_AUTORESET_ENGAGE_ENABLE == PG_ENABLE )
				// if( pg_gcp_reset() == PG_OK ) {
					// #if PG_ERROR_IS_ENABLE
						// pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_RESETTED , PG_ERROR_WARNING );
					// #endif
					// return( PG_OK );
				// }
			// #endif 
		}
		#if PG_ERROR_IS_ENABLE
			pg_error_set( PG_ERROR_GCP , PG_GCP_ERROR_ENGAGE_FAILED , PG_ERROR_ERROR );
		#endif
		return( PG_NOK );
	}
	
	//---[ RX - Engage ]---
	_pg_Uint8 pg_gcp_rx_engage( void ) {
		//--------------------------------------------------------------------------
		#if ( ( PG_GCP_LED_GLOBAL_ENABLE == PG_ENABLE ) && ( PG_GCP_LED_ENGAGE_ENABLE == PG_ENABLE ) )
			PG_GCP_LED_ENGAGE_LAT = PG_ON;
		#endif
		#if ( ( PG_GCP_DEBUG_GLOBAL == PG_ENABLE ) && ( PG_GCP_DEBUG_ENGAGE_REPLY == PG_ENABLE ) )
			pg_lcd_hd44780_put_char( 0 , PG_GCP_CONTROL_ENGAGE_REPLY  );
		#endif
		//---[ Version Check ]---
		//if( pg_gcp_rx_version() == PG_OK ) {
			pg_gcp_send_byte_serial( PG_GCP_CONTROL_ENGAGE_REPLY );
			pg_gcp_flag_engage = PG_YES;
			pg_gcp_flag_tx = PG_NO;
			#if PG_ERROR_IS_ENABLE
				pg_error_set( PG_ERROR_GCP , PG_OK , PG_ERROR_OK );
			#endif
			return( PG_OK );
		//}
		//return( PG_NOK );
	}
	
*/
	
/*
sost. 	PG_GCP_CRC_OK 			con pg-ok, ma solo mentre sta funzionando
		PG_GCP_CONFIG_OK,
		PG_GCP_COMMAND_OK,
		PG_GCP_STATUS_MOD_OK,
			
rename all f() nella forma:
	pg_gcp_tx_crc
	pg_gcp_rx_crc
		
/* 

considerare clear_buffer quando non c'e' risposta e si accumulano nel buffer

	_pg_Uin8	pg_gcp_flag_reg;
	
	pg_gcp_flag_reg = 0; 
	
	//---[ Flag ]---
	#define		PG_GCP_FLAG_SET_TX				0b00000001
	#define		PG_GCP_FLAG_SET_ENGAGE			0b00000010
	#define		PG_GCP_FLAG_SET_DATA_MODE		0b00000100
	#define		PG_GCP_FLAG_SET_REQUEST			0b00001000
	#define		PG_GCP_FLAG_SET_STREAMING		0b00010000
	#define		PG_GCP_FLAG_SET_5				0b00100000
	#define		PG_GCP_FLAG_SET_6				0b01000000
	#define		PG_GCP_FLAG_SET_7				0b10000000
 	
	// #define		PG_GCP_FLAG_CLEAR_TX			0b11111110
	// #define		PG_GCP_FLAG_CLEAR_ENGAGE		0b11111101
	// #define		PG_GCP_FLAG_CLEAR_DATA_MODE		0b11111011
	// #define		PG_GCP_FLAG_CLEAR_REQUEST		0b11110111
	// #define		PG_GCP_FLAG_CLEAR_STREAMING		0b11101111
	// #define		PG_GCP_FLAG_CLEAR_5				0b11011111
	// #define		PG_GCP_FLAG_CLEAR_6				0b10111111
	// #define		PG_GCP_FLAG_CLEAR_7				0b01111111 
	
	//complemento a 1 della maschera, cancellare l'altra
	void	pg_gcp_flag_set( _pg_Uin8 flag , _pg_Uin8 value ) {
		//--------------------------------------------------------------------------
		if( value )
			pg_gcp_flag_reg |= flag;
		else
			pg_gcp_flag_reg &= flag;
		
	}
	
	void	pg_gcp_flag_get( _pg_Uin8 flag , _pg_Uin8 val ) {
		//--------------------------------------------------------------------------
		
	}

	

	 		// //---[ Flag ]---
	// _pg_Uint8	pg_gcp_flag_tx;							//(1 bit flag todo)	E' il master, chi invia control.
	// _pg_Uint8	pg_gcp_flag_engage;						//(1 bit flag todo)
	// _pg_Uint8	pg_gcp_flag_data_mode;					//(1 bit flag todo)
	// _pg_Uint8	pg_gcp_flag_request;					//(1 bit flag todo)
	// _pg_Uint8	pg_gcp_flag_streaming;					//(1 bit flag todo)
	// //_pg_Uint8	pg_gcp_flag_version;					//(1 bit flag todo) 
	 */