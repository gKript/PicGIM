//GCP - General Communication Protocol

#ifndef _PGIM_GCP_H_
	#define _PGIM_GCP_H_

	#if ( PGIM_GCP == PG_ENABLE )
	
		//---[ Debug ]---
		#define	PG_GCP_DEBUG_GLOBAL								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		//---
		#define	PG_GCP_DEBUG_ESCAPE								PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ESCAPE_REPLY						PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ENGAGE								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ENGAGE_REPLY						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ENGAGE_END							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_ENGAGE_END_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_DATA								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_DATA_REPLY							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_DATA_END							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_DATA_END_REPLY						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CRC								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CRC_REPLY							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CRC_OK								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CRC_BYTE							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CRC_FAILED							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_REQUEST							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CONFIG								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CONFIG_REPLY						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CONFIG_OK							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CONFIG_NUMBER						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_CONFIG_NUMBER_REPLY				PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STATUS_SYNC						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STATUS_SYNC_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STATUS_MOD							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STATUS_MOD_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_RESET								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_RESET_REPLY						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_RESET_CLEAR_LCD					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
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
		#define	PG_GCP_BUFFER_UNKNOWN							'?'
		
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
		#define PG_GCP_COMMAND_STATUS_SYNC						'S'
		#define PG_GCP_COMMAND_STATUS_SYNC_REPLY				's'
		//---
		#define PG_GCP_COMMAND_STATUS_MOD						'M'
		#define PG_GCP_COMMAND_STATUS_MOD_REPLY					'm'
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
			PG_GCP_DUMMY = 100,
			PG_GCP_COMMAND_ESCAPE_CHAR_SAVED,
			PG_GCP_COMMAND_DATA_MODE_END_DONE,
			PG_GCP_COMMAND_DATA_MODE_DONE,
			PG_GCP_COMMAND_ENGAGE_END_DONE,
			PG_GCP_RESET_FAILED,
			PG_GCP_WAITING_DATA,
			PG_GCP_ENGAGE_FAILED,
			PG_GCP_ENGAGE_END_FAILED,
			PG_GCP_CONFIG_OK,
			PG_GCP_DATA_FAILED,
			PG_GCP_DATA_END_FAILED,
			PG_GCP_CONFIG_FAILED,
			PG_GCP_STATUS_FAILED,
			PG_GCP_STATUS_WAITING,
			PG_GCP_STATUS_MOD_OK,
			PG_GCP_STATUS_MOD_FAILED,
			PG_GCP_REQUEST_FAILED,
			PG_GCP_SAVE_BYTE_BUFFER_FAILED,
			PG_GCP_READ_BYTE_SERIAL_TIMEOUT,
			PG_GCP_SEND_COMMAND_FAILED,
			PG_GCP_TX_BUFFER_FAILED,
			PG_GCP_RX_DATA_READY_NO,
			PG_GCP_RX_COMMAND_TIMEOUT,
			PG_GCP_RX_BYTE_TIMEOUT,
			PG_GCP_RX_DATA_READY_NONE,
			PG_GCP_ERROR_RX_CONFIG_FAILED,
			PG_GCP_ERROR_RX_REQUEST_FAILED,
			PG_GCP_ERROR_RX_STATUS_FAILED,
			PG_GCP_ERROR_RX_MOD_STATUS_FAILED,
			PG_GCP_ERROR_RX_CRC_TIMEOUT,
			PG_GCP_ERROR_RX_CRC_COMPARE_FAILED,
			PG_GCP_ERROR_CRC_FAILED,
			PG_GCP_ERROR_CRC32_CANNOT_MATH,
			PG_GCP_CRC_OK,
			PG_GCP_CRC_TX_FAILED,
			PG_GCP_CRC_COMPARE_FAILED
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
			#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
				_pg_Uint8	xbuffer_status;					//!<Status of buffer: PG_GCP_BUFFER_EMPTY, PG_GCP_BUFFER_INCOMPLETE, PG_GCP_BUFFER_FULL>		
			#endif
		};
		
		extern struct pg_gcp_str_config pg_gcp_v_config[ ( PG_GCP_CONFIGS_NUMBER + 1 ) ];	//Config struct vector
		
		//#######################################################################
		//---[   C O M M A N D   ]---
		//#######################################################################
		
		/*!
			\brief			Command to initialize all protocol variables and set hardware.\n
							Must be run by the first.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.

		*/
		void		pg_gcp_init								( void );

		/*!
			\brief			Command to execute local reset function to remote host and then locally.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		 
		_pg_Uint8	pg_gcp_reset							( void );	

		/*!
			\brief			Command to reset all variables locally.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		void 		pg_gcp_reset_local						( void );		

		/*!
			\brief			Command to occupy hardware channel and have the right to transmit.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage							( void );

		/*!
			\brief			Command to release hardware channel.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage_end						( void );

		#if ( PG_GCP_REQUEST_ENABLE == PG_ENABLE )
			/*!
				\brief			Command sent from receiving host, requiring to transmitter.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_request							( void );
			

			/*!
				\brief			Command to set transmission request flag. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			void		pg_gcp_request_set						( _pg_Uint8 qvalue );
		#endif

		/*!
			\brief			Command to change configuration. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_config							( _pg_Uint8 configuration );	

		/*!
			\brief			Command to enter in data mode. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data								( void );	

		/*!
			\brief			Command to exit data mode.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data_end							( void ); 

		#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
			/*!
				\brief			Command to syncronize and retrieve remote status to local one.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_status_sync						( void );
		#endif
		
		#if ( PG_GCP_STATUS_MOD_ENABLE == PG_ENABLE )
			/*!
				\brief			Command to overwrite remote status. It is usefull with short string transmission, because void need to send full buffer, allowing to set buffer to full without complete transmission of buffer containing string.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8 		pg_gcp_status_mod					( _pg_Uint8 value );
		#endif
		
		//#######################################################################
		//---[   F U N C T I O N   ]---
		//#######################################################################

		/*!
			\brief			Command to send a byte.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_send_command_byte				( _pg_Uint8 xcommand );

		/*!
			\brief			Command to transmit a buffer.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_tx_buffer						( _pg_Uint8 * tbuffer );		

		/*!
			\brief			Receiving routine. Inserted within a loop of the user code allows dialogue with the transmitting part.//BLOCKING or NOT BLOCKING\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx								( void );

		/*!
			\brief			This function checks for incoming data.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data_ready					( void );

		/*!
			\brief			This function must be used to read data from buffer, because manages parameters and status. //BLOCKING or NOT BLOCKING\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	*	pg_gcp_rx_data_read					( void );

		/*!
???			\brief			What it do. //BLOCKING or NOT BLOCKING\n
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
						/*!
				\brief			What it do. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_rx_crc							( void );
		#endif
		
		//#######################################################################
		//---[   R X   ]---
		//#######################################################################
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_reset								( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_engage							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_config							( void );		
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_request							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_escape							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data_end							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data								( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_engage_end						( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_status_sync							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/_pg_Uint8	pg_gcp_rx_status_mod						( void );

		//---[ End Prototype ]---
 	#endif
#endif /* _PGIM_GCP_H_ */
 
 

