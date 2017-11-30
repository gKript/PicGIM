//GCP - General Communication Protocol

#ifndef _PGIM_GCP_H_
	#define _PGIM_GCP_H_

	#if ( PGIM_GCP == PG_ENABLE )
	
		//---[ Debug ]---
		#define	PG_GCP_DEBUG_GLOBAL								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		//---
		#define	PG_GCP_DEBUG_COMMAND_ESCAPE						PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_ESCAPE_REPLY				PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_ENGAGE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_ENGAGE_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_ENGAGE_END					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_ENGAGE_END_REPLY			PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_DATA						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_DATA_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_DATA_END					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_DATA_END_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CRC						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CRC_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CRC_BYTE					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_OK_CRC								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ERROR_CRC_FAILED					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_REQUEST					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CONFIG						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CONFIG_NUMBER				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CONFIG_OK					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CONFIG_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_CONFIG_NUMBER_REPLY		PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_STATUS						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_STATUS_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_MOD_STATUS					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_MOD_STATUS_REPLY			PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_RESET						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_RESET_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_COMMAND_RESET_CLEAR_LCD			PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STATUS_VALUE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_WAITING_DATA						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_TX_BUFFER							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE

		//---
		#define PG_GCP_DEBUG_CHAR_ASCII_OFFSET					48
		//---[ End Debug ]---
		
		//---[ Buffer Status ]---
		#define	PG_GCP_BUFFER_EMPTY								'e'
		#define	PG_GCP_BUFFER_INCOMPLETE						'i'
		#define	PG_GCP_BUFFER_FULL								'f'
		//---[ End Buffer Status ]---
		
		//---[ Buffer Rx Default ]---
		#define PG_GCP_BUFFER_RX_DEFAULT_LENGTH					1		//!< Only 1 byte at time>
		//---[ End Buffer Rx Default ]---		
		
		//---[ Offset Reply Byte ]---
		#define	PG_GCP_REPLY_OFFSET_ADD							32		//!< Must match "Command Byte" below defined.
		//---[ End Offset Reply Byte ]---
		
		//---[ Identifier Command Byte ]---
		#define	PG_GCP_COMMAND_ESCAPE							'>'		//!< Escape char>
		#define	PG_GCP_COMMAND_ESCAPE_REPLY						'^'		//!< Escape char reply>
		//---[ End Identifier Command Byte ]---
		
		//---[ Command Byte ]---
		#define	PG_GCP_COMMAND_ENGAGE							'K'	
		#define	PG_GCP_COMMAND_ENGAGE_REPLY						'k'		//!< PG_GCP_COMMAND_ENGAGE_REPLY = PG_GCP_COMMAND_ENGAGE + PG_GCP_REPLY_OFFSET_ADD>
		//---
		#define PG_GCP_COMMAND_CONFIG							'C'
		#define PG_GCP_COMMAND_CONFIG_REPLY						'c'
		//---
		#define PG_GCP_COMMAND_DATA								'D'
		#define PG_GCP_COMMAND_DATA_REPLY						'd'
		//---
		#define PG_GCP_COMMAND_DATA_END							'Z'
		#define PG_GCP_COMMAND_DATA_END_REPLY					'z'
		//---
		#define PG_GCP_COMMAND_STATUS							'S'
		#define PG_GCP_COMMAND_STATUS_REPLY						's'
		//---
		#define PG_GCP_COMMAND_MOD_STATUS						'M'
		#define PG_GCP_COMMAND_MOD_STATUS_REPLY					'm'
		//---
		#define PG_GCP_COMMAND_CRC								'V'
		#define PG_GCP_COMMAND_CRC_REPLY						'v'
		//---
		#define PG_GCP_COMMAND_ENGAGE_END						'X'
		#define PG_GCP_COMMAND_ENGAGE_END_REPLY					'x'
		//---
		#define PG_GCP_COMMAND_RESET							'R'
		#define PG_GCP_COMMAND_RESET_REPLY						'r'
		//---
		#define PG_GCP_COMMAND_REQUEST							'Q'
		#define PG_GCP_COMMAND_REQUEST_REPLY					'q'
		//---[ End Command Byte ]---
		
		//---[ Return Messages ]---			
		enum _pg_gcp_return_code_enum {
			PG_GCP_OK_RESET = 0,
			PG_GCP_ERROR_RESET_REMOTE_FAILED,
			PG_GCP_OK_ENGAGE,
			PG_GCP_ERROR_ENGAGE_FAILED,
			PG_GCP_ERROR_ENGAGE_ALREADY,
			PG_GCP_OK_ENGAGE_END,
			PG_GCP_ERROR_ENGAGE_END_FAILED,
			PG_GCP_ERROR_ENGAGE_NOT_ENGAGED,
			PG_GCP_ERROR_ENGAGE_DATA_MODE_ACTIVE,
			PG_GCP_OK_REQUEST,
			PG_GCP_ERROR_REQUEST_COMMAND_FAILED,
			PG_GCP_ERROR_REQUEST_NOT_ENGAGED,
			PG_GCP_OK_CONFIG,
			PG_GCP_ERROR_CONFIG_PARAMETER_MISMATCH,
			PG_GCP_ERROR_CONFIG_RX_COMMAND_TIMEOUT,
			PG_GCP_ERROR_CONFIG_COMMAND_FAILED,
			PG_GCP_ERROR_CONFIG_NOT_ENGAGED,
			PG_GCP_OK_DATA_MODE,
			PG_GCP_ERROR_DATA_MODE_COMMAND_FAILED,
			PG_GCP_ERROR_DATA_MODE_ALREADY,
			PG_GCP_ERROR_DATA_NOT_ENGAGED,
			PG_GCP_OK_DATA_MODE_END,
			PG_GCP_ERROR_DATA_END_COMMAND_FAILED,
			PG_GCP_ERROR_DATA_END_NOT_DATA_MODE,
			PG_GCP_ERROR_DATA_END_NOT_ENGAGED,
			PG_GCP_PG_GCP_TIMEOUT_MS,
			PG_GCP_ERROR_STATUS_COMMAND_FAILED,
			PG_GCP_ERROR_STATUS_DATA_MODE_ACTIVE,
			PG_GCP_ERROR_STATUS_NOT_ENGAGED,
			PG_GCP_STATUS_WAITING,
			PG_GCP_ERROR_STATUS_WRONG_WAITING,
			PG_GCP_OK_STATUS_SEND,
			PG_GCP_ERROR_STATUS_NO_REPLY_TIMEOUT,
			PG_GCP_OK_SEND_COMMAND,
			PG_GCP_ERROR_SEND_WRONG_COMMAND_REPLY_PLUS,
			PG_GCP_ERROR_SEND_RX_BYTE_TIMEOUT,
			PG_GCP_ERROR_SEND_WRONG_COMMAND_REPLY,
			PG_GCP_ERROR_SEND_NO_REPLY_TIMEOUT,
			PG_GCP_OK_TX,
			PG_GCP_ERROR_TX_NOT_DATA_MODE,
			PG_GCP_ERROR_TX_NOT_ENGAGED,
			PG_GCP_OK_RESET_DONE,
			PG_GCP_OK_ENGAGE_DONE,
			PG_GCP_ERROR_ENGAGE_WRONG_COMMAND,
			PG_GCP_OK_CONFIG_DONE,
			PG_GCP_ERROR_CONFIG_NOT_CONFIRMED,
			PG_GCP_ERROR_CONFIG_NO_REPLY_TIMEOUT_CONFIRM,
			PG_GCP_ERROR_CONFIG_NO_REPLY_TIMEOUT,
			PG_GCP_OK_REQUEST_DONE,
			PG_GCP_ERROR_REQUEST_CONFIRM_FAILED,
			PG_GCP_ERROR_REQUEST_NO_REPLY_TIMEOUT,
			PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_E,
			PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_ED,
			PG_GCP_ERROR_CRC_NO_REPLY_TIMEOUT,
			PG_GCP_ERROR_CRC_DATA_MODE_ACTIVE,
			PG_GCP_ERROR_CRC_FAILURE,
			PG_GCP_ERROR_CRC_COMMAND_FAILED,
			PG_GCP_ERROR_CRC_MATH_TIMEOUT,
			PG_GCP_WAITING_DATA,
			PG_GCP_OK_CRC,
			PG_GCP_ERROR_CRC_FAILED,
			PG_GCP_ERROR_CRC_NOT_DATA_MODE,
			PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_EE,
			PG_GCP_ERROR_RX_COMMAND_TIMEOUT_COMMAND,
			PG_GCP_ERROR_RX_BYTE_TIMEOUT,
			PG_GCP_OK_READ,
			PG_GCP_ERROR_READ_BYTE_TIMEOUT,
			PG_GCP_ERROR_CRC_TX,
			PG_GCP_ERROR_CRC_NOT_ENGAGED,
			PG_GCP_ERROR_CRC32_CANNOT_MATH,
			PG_GCP_CRC32_DONE,
			WAITING_DATA,
			PG_GCP_COMMAND_ESCAPE_CHAR_SAVED,
			PG_GCP_COMMAND_DATA_MODE_END_DONE,
			PG_GCP_COMMAND_DATA_MODE_DONE,
			PG_GCP_COMMAND_ENGAGE_END_DONE,
			PG_GCP_RX_DATA_READY_NONE,
			PG_GCP_ERROR_WAITING_READ,
			PG_GCP_OK_SAVED,
			PG_GCP_RX_DATA_READ_NONE,
			PG_GCP_ERROR_DATA_MODE_ACTIVE,
			PG_GCP_OK_MOD,
			PG_GCP_ERROR_MOD_FAILED,
			PG_GCP_ERROR_MOD_TX_COMMAND_TIMEOUT,
			PG_GCP_ERROR_MOD_WRONG_VALUE,
			PG_GCP_ERROR_MOD_RX_VALUE_MISMATCH,
			PG_GCP_ERROR_MOD_RX_COMMAND_TIMEOUT,
			PG_GCP_ERROR_MOD_COMMAND_FAILED,
			PG_GCP_ERROR_MOD_DATA_MODE_ACTIVE,
			PG_GCP_ERROR_MOD_NOT_ENGAGED,
			
			//error
			PG_GCP_RESET_FAILED,
			PG_GCP_CONFIG_OK,
			PG_GCP_MOD_STATUS_OK,
			PG_GCP_CRC_OK,
			
			PG_GCP_ENGAGE_FAILED,
			PG_GCP_ENGAGE_END_FAILED,
			PG_GCP_DATA_FAILED,
			PG_GCP_DATA_END_FAILED,
			PG_GCP_CONFIG_FAILED,
			PG_GCP_MOD_STATUS_FAILED,
			PG_GCP_STATUS_FAILED,

			PG_GCP_REQUEST_FAILED,
			PG_GCP_SAVE_BYTE_BUFFER_FAILED,
			PG_GCP_RX_DATA_READY_NO,
			PG_GCP_READ_BYTE_SERIAL_TIMEOUT,
			PG_GCP_SEND_COMMAND_FAILED,
			PG_GCP_TX_BUFFER_FAILED,
			PG_GCP_CRC_TX_FAILED,
			PG_GCP_CRC_COMPARE_FAILED,
			PG_GCP_RX_COMMAND_TIMEOUT,
			PG_GCP_RX_BYTE_TIMEOUT,
			PG_GCP_ERROR_RX_CONFIG_FAILED,
			PG_GCP_ERROR_RX_REQUEST_FAILED,
			PG_GCP_ERROR_RX_STATUS_FAILED,
			PG_GCP_ERROR_RX_MOD_STATUS_FAILED,
			PG_GCP_ERROR_RX_CRC_TIMEOUT,
			PG_GCP_ERROR_RX_CRC_COMPARE_FAILED
			//...definirli tutti
			
		};
		//---[ END Return Message ]---
		
		//---[ Prototype ]---
		extern _pg_Uint8	pg_gcp_dbyte;							//!< Generic rx byte>
		extern _pg_Uint8	pg_gcp_nconfig;							//!< Config id number>
		extern _pg_Uint16	pg_gcp_bindex;							//!< variabile di supporto alla modifica dell'indice del buffer
		
		extern _pg_Uint8 rdr;	//non parte sempre da zero ed evita il blocco del buffer 0 da 1 byte
		
		extern _pg_Uint8	pg_gcp_flag_data_mode;					//!<(1 bit flag todo?)
		extern _pg_Uint8	pg_gcp_flag_engage;						//!<(1 bit flag todo?)
		
		#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
			extern _pg_Uint32_VAL	pg_gcp_crc32_local;				//variabile di supporto al calcolo e contenimento della crc del buffer
			extern _pg_Uint32_VAL	pg_gcp_crc32_remote;			//variabile di supporto al calcolo e contenimento della crc del buffer
		#endif	

		extern _pg_Uint8	pg_gcp_buffer_rx_default[ PG_GCP_BUFFER_RX_DEFAULT_LENGTH ];	//!< Rx user buffer (config 00) - DEFAULT
		#if ( PG_GCP_BUFFER_RX_01_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_01[ PG_GCP_BUFFER_RX_01_LENGTH ];			//!< Rx user buffer (config 01)
		#endif
		#if ( PG_GCP_BUFFER_RX_02_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_02[ PG_GCP_BUFFER_RX_02_LENGTH ];			//!< Rx user buffer (config 02)
		#endif
		#if ( PG_GCP_BUFFER_RX_03_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_03[ PG_GCP_BUFFER_RX_03_LENGTH ];			//!< Rx user buffer (config 03)
		#endif
		#if ( PG_GCP_BUFFER_RX_04_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_04[ PG_GCP_BUFFER_RX_04_LENGTH ];			//!< Rx user buffer (config 04)
		#endif
		#if ( PG_GCP_BUFFER_RX_05_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_05[ PG_GCP_BUFFER_RX_05_LENGTH ];			//!< Rx user buffer (config 05)
		#endif
		#if ( PG_GCP_BUFFER_RX_06_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_06[ PG_GCP_BUFFER_RX_06_LENGTH ];			//!< Rx user buffer (config 06)
		#endif
		#if ( PG_GCP_BUFFER_RX_07_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_07[ PG_GCP_BUFFER_RX_07_LENGTH ];			//!< Rx user buffer (config 07)
		#endif
		#if ( PG_GCP_BUFFER_RX_08_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_08[ PG_GCP_BUFFER_RX_08_LENGTH ];			//!< Rx user buffer (config 08)
		#endif
		#if ( PG_GCP_BUFFER_RX_09_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_09[ PG_GCP_BUFFER_RX_09_LENGTH ];			//!< Rx user buffer (config 09)
		#endif
		#if ( PG_GCP_BUFFER_RX_10_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_10[ PG_GCP_BUFFER_RX_10_LENGTH ];			//!< Rx user buffer (config 10)
		#endif
		#if ( PG_GCP_BUFFER_RX_11_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_11[ PG_GCP_BUFFER_RX_11_LENGTH ];			//!< Rx user buffer (config 11)
		#endif
		#if ( PG_GCP_BUFFER_RX_12_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_12[ PG_GCP_BUFFER_RX_12_LENGTH ];			//!< Rx user buffer (config 12)
		#endif
		#if ( PG_GCP_BUFFER_RX_13_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_13[ PG_GCP_BUFFER_RX_13_LENGTH ];			//!< Rx user buffer (config 13)
		#endif
		#if ( PG_GCP_BUFFER_RX_14_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_14[ PG_GCP_BUFFER_RX_14_LENGTH ];			//!< Rx user buffer (config 14)
		#endif
		#if ( PG_GCP_BUFFER_RX_15_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_15[ PG_GCP_BUFFER_RX_15_LENGTH ];			//!< Rx user buffer (config 15)
		#endif
		#if ( PG_GCP_BUFFER_RX_16_ENABLE == PG_ENABLE )
			extern _pg_Uint8	pg_gcp_buffer_rx_16[ PG_GCP_BUFFER_RX_16_LENGTH ];			//!< Rx user buffer (config 16)
		#endif
		
		extern struct pg_gcp_str_config {
			void		* xbuffer_ptr;						//!<Payload buffer pointer>
			_pg_Uint16	xbuffer_length;						//!<Payload length. Total byte quantity to send in a packet; 0 = stream>
			_pg_Uint8	xbuffer_index;						//!<Current position to write to next byte in buffer; 0 to ( PG_GCP_BUFFER_RX_xx_LENGTH - 1 ) >
			#if ( PG_GCP_STATUS_ENABLE ==  PG_ENABLE )
				_pg_Uint8	xbuffer_status;					//!<Status of buffer: PG_GCP_BUFFER_EMPTY, PG_GCP_BUFFER_INCOMPLETE, PG_GCP_BUFFER_FULL>		
			#endif
		};
		
		extern struct pg_gcp_str_config pg_gcp_v_config[ ( PG_GCP_CONFIGS_NUMBER + 1 ) ];	//Config struct vector
				
		/*!
			\brief			Initialize all protocol variables. \n
							Must be run by the first.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.

		*/
		void		pg_gcp_init								( void );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		 
		_pg_Uint8	pg_gcp_reset							( void );	

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		void 		pg_gcp_reset_local						( void );		

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage							( void );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage_end						( void );

		#if ( PG_GCP_REQUEST_ENABLE == PG_ENABLE )
			/*!
				\brief			What it do. \n 		//!!! La esegue il ricevente, al contrario degli a ltri comandi !!! 
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_request							( void );
		#endif

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_config							( _pg_Uint8 configuration );	

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data								( void );	

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data_end							( void ); 

		#if ( PG_GCP_STATUS_ENABLE ==  PG_ENABLE )
			/*!
				\brief			What it do. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_status						( void );
		#endif

		/*!
			\brief			What it do.//cambia lo stato del buffer, utile se con le stringhe non lo si riempe tutto, lo si puo' mettere full \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8 		pg_gcp_mod_status					( _pg_Uint8 value );
			
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_send_command_byte				( _pg_Uint8 xcommand );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_tx_buffer						( _pg_Uint8 * tbuffer );		

		/*!
			\brief			What it do. \n//BLOCKING or NOT BLOCKING!!! Verifica per poco tempo (BYTEDELAY) se e' arrivato un byte e ritorna... richiamarla a ciclo dal main... Se BYTEDELAY=0 bloccante fino alla ricezione di un byte.
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx								( void );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data_ready					( void );

		/*!
			\brief			What it do. //BLOCKING or NOT BLOCKING\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	*	pg_gcp_rx_data_read					( void );

		/*!
			\brief			What it do. //BLOCKING or NOT BLOCKING\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_send_byte_serial					( _pg_Uint8 sbyte );		

		/*!
			\brief			What it do. //cicla, o arriva il dato, o quando a zero esce con errore //BLOCKING or NOT BLOCKING\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_read_byte_serial					( _pg_Uint16 tdelay );

		/*!
			\brief			What it do. \n   ////Scrive con parametri idella config attuale; setta il full se scrive l'ultimo byte del buffer ed al successivo byte ricomincia da index=0 e setta l'INCOMPLETE
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_save_byte_buffer					( void );
		
		#if ( PG_GCP_STATUS_ENABLE ==  PG_ENABLE )
			/*!
				\brief			What it do. \n	
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_check_buffer_status				( void );	
		#endif
		
		#if ( PG_GCP_CRC_ENABLE == PG_ENABLE )
			/*!
				\brief			What it do. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_crc								( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );

			/*!
				\brief			What it do. //write directly in pg_gcp_crc32_local\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_crc32_calc						( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );//( _pg_Uint8 * cbuffer );		
		#endif
		
		_pg_Uint8 pg_gcp_rx_reset( void );
		_pg_Uint8 pg_gcp_rx_engage( void );
		_pg_Uint8 pg_gcp_rx_config( void );		
		_pg_Uint8 pg_gcp_rx_request( void );
		_pg_Uint8 pg_gcp_rx_escape( void );
		_pg_Uint8 pg_gcp_rx_data_end( void );
		_pg_Uint8 pg_gcp_rx_data( void );
		_pg_Uint8 pg_gcp_rx_engage_end( void );
		_pg_Uint8 pg_gcp_rx_status ( void );
		_pg_Uint8 pg_gcp_rx_mod_status( void );
		_pg_Uint8 pg_gcp_rx_crc( void );

		//---[ End Prototype ]---
 	#endif
#endif /* _PGIM_GCP_H_ */
 
 
 
 
 
 

 
 
 /* 		//---[ Return Messages ]---	
		#define PG_GCP_OK_RESET									110
		#define PG_GCP_ERROR_RESET_REMOTE_FAILED				111
		#define PG_GCP_OK_ENGAGE								113
		#define PG_GCP_ERROR_ENGAGE_FAILED						114
		#define PG_GCP_ERROR_ENGAGE_ALREADY						115
		#define PG_GCP_OK_ENGAGE_END							116
		#define PG_GCP_ERROR_ENGAGE_END_FAILED					117
		#define PG_GCP_ERROR_ENGAGE_NOT_ENGAGED					118
		#define PG_GCP_ERROR_ENGAGE_DATA_MODE_ACTIVE			119
		#define PG_GCP_OK_REQUEST								120
		#define PG_GCP_ERROR_REQUEST_COMMAND_FAILED				121
		#define PG_GCP_ERROR_REQUEST_NOT_ENGAGED				122
		#define PG_GCP_OK_CONFIG								123
		#define PG_GCP_ERROR_CONFIG_PARAMETER_MISMATCH			124
		#define PG_GCP_ERROR_CONFIG_RX_COMMAND_TIMEOUT			125
		#define PG_GCP_ERROR_CONFIG_COMMAND_FAILED				126
		#define PG_GCP_ERROR_CONFIG_NOT_ENGAGED					127
		#define PG_GCP_OK_DATA_MODE								128
		#define PG_GCP_ERROR_DATA_MODE_COMMAND_FAILED			129
		#define PG_GCP_ERROR_DATA_MODE_ALREADY					130
		#define PG_GCP_ERROR_DATA_NOT_ENGAGED					131
		#define PG_GCP_OK_DATA_MODE_END							132
		#define PG_GCP_ERROR_DATA_END_COMMAND_FAILED			133
		#define PG_GCP_ERROR_DATA_END_NOT_DATA_MODE				134
		#define PG_GCP_ERROR_DATA_END_NOT_ENGAGED				135
		#define PG_GCP_PG_GCP_TIMEOUT_MS						136
		#define PG_GCP_ERROR_STATUS_COMMAND_FAILED				137
		#define PG_GCP_ERROR_STATUS_DATA_MODE_ACTIVE			138
		#define PG_GCP_ERROR_STATUS_NOT_ENGAGED	
		#define PG_GCP_STATUS_WAITING
		#define PG_GCP_ERROR_STATUS_WRONG_WAITING
		#define PG_GCP_OK_STATUS_SEND
		#define PG_GCP_ERROR_STATUS_NO_REPLY_TIMEOUT
		#define PG_GCP_OK_SEND_COMMAND							139
		#define PG_GCP_ERROR_SEND_WRONG_COMMAND_REPLY_PLUS		140
		#define PG_GCP_ERROR_SEND_RX_BYTE_TIMEOUT				141
		#define PG_GCP_ERROR_SEND_WRONG_COMMAND_REPLY			142
		#define PG_GCP_ERROR_SEND_NO_REPLY_TIMEOUT				143
		#define PG_GCP_OK_TX									144
		#define PG_GCP_ERROR_TX_NOT_DATA_MODE					145
		#define PG_GCP_ERROR_TX_NOT_ENGAGED						146
		#define PG_GCP_OK_RESET_DONE							147
		#define PG_GCP_OK_ENGAGE_DONE							148
		#define PG_GCP_ERROR_ENGAGE_WRONG_COMMAND				149
		#define PG_GCP_OK_CONFIG_DONE							150
		#define PG_GCP_ERROR_CONFIG_NOT_CONFIRMED				151
		#define PG_GCP_ERROR_CONFIG_NO_REPLY_TIMEOUT_CONFIRM	152
		#define PG_GCP_ERROR_CONFIG_NO_REPLY_TIMEOUT			153
		#define PG_GCP_OK_REQUEST_DONE							154
		#define PG_GCP_ERROR_REQUEST_CONFIRM_FAILED				155
		#define PG_GCP_ERROR_REQUEST_NO_REPLY_TIMEOUT			156
		#define PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_E			157
		#define PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_ED		158
		#define PG_GCP_ERROR_CRC_NO_REPLY_TIMEOUT				159
		#define PG_GCP_ERROR_CRC_DATA_MODE_ACTIVE
		#define PG_GCP_ERROR_CRC_FAILURE
		#define PG_GCP_ERROR_CRC_COMMAND_FAILED
		#define PG_GCP_ERROR_CRC_MATH_TIMEOUT
		#define PG_GCP_WAITING_DATA								160
		#define PG_GCP_OK_CRC									161
		#define PG_GCP_ERROR_CRC_FAILED							162
		#define PG_GCP_ERROR_CRC_NOT_DATA_MODE					163
		#define PG_GCP_ERROR_UNKNOWN_OR_WRONG_COMMAND_EE		164
		#define PG_GCP_ERROR_RX_COMMAND_TIMEOUT_COMMAND			165
		#define PG_GCP_ERROR_RX_BYTE_TIMEOUT					166
		#define PG_GCP_OK_READ									167
		#define PG_GCP_ERROR_READ_BYTE_TIMEOUT					168
		#define PG_GCP_BUFFER_EMPTY								169
		#define PG_GCP_BUFFER_MODIFIED							170
		#define PG_GCP_BUFFER_INCOMPLETE						171
		#define PG_GCP_BUFFER_FULL								172
		#define PG_GCP_BUFFER_OVERLOADED						173
		#define PG_GCP_ERROR_CRC_TX								174
		#define PG_GCP_ERROR_CRC_NOT_ENGAGED					175
		#define PG_GCP_ERROR_CRC32_CANNOT_MATH					176
		#define PG_GCP_CRC32_DONE
		#define WAITING_DATA									177
		//---[ END Return Message ]--- */