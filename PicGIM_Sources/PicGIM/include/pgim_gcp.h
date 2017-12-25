//GCP - General Communication Protocol

#ifndef _PGIM_GCP_H_
	#define _PGIM_GCP_H_

	#if ( PGIM_GCP == PG_ENABLE )

 		//---[ Version ]---
		#define	PG_GCP_VERSION_MAJOR							0
		#define	PG_GCP_VERSION_MINOR							1
		//---[ End Version ]---
	
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
		#define	PG_GCP_DEBUG_STREAMING							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_STREAMING_REPLY					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_VERSION							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define	PG_GCP_DEBUG_VERSION_REPLY						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
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
		#define	PG_GCP_BUFFER_CRC								'c'
		#define	PG_GCP_BUFFER_READ								'r'
		#define	PG_GCP_BUFFER_UNKNOWN							'?'
		//---[ End Buffer Status ]---
		
		//---[ Buffer Rx Default ]---
		#define PG_GCP_BUFFER_RX_DEFAULT_LENGTH					1		//!< Only 1 byte at time>
		//---[ End Buffer Rx Default ]---		
		
		//---[ Config Number ]---
		#define	PG_GCP_CONFIG_00								0
		#define	PG_GCP_CONFIG_01								1
		#define	PG_GCP_CONFIG_02								2
		#define	PG_GCP_CONFIG_03								3
		#define	PG_GCP_CONFIG_04								4
		#define	PG_GCP_CONFIG_05								5
		#define	PG_GCP_CONFIG_06								6
		#define	PG_GCP_CONFIG_07								7
		#define	PG_GCP_CONFIG_08								8
		#define	PG_GCP_CONFIG_09								9
		#define	PG_GCP_CONFIG_10								10
		#define	PG_GCP_CONFIG_11								11
		#define	PG_GCP_CONFIG_12								12
		#define	PG_GCP_CONFIG_13								13
		#define	PG_GCP_CONFIG_14								14
		#define	PG_GCP_CONFIG_15								15
		#define	PG_GCP_CONFIG_16								16
		//---[ End Config Number ]---
		
		//---[ CRC Flag]---
		#define	PG_GCP_CRC_OFF									0
		#define	PG_GCP_CRC_ON									1
		//---[ End CRC Flag ]---

		//---[ Flag ]---
		#define	PG_GCP_FLAG_SET_TX								0b00000001
		#define	PG_GCP_FLAG_SET_ENGAGE							0b00000010
		#define	PG_GCP_FLAG_SET_DATA_MODE						0b00000100
		#define	PG_GCP_FLAG_SET_REQUEST							0b00001000
		#define	PG_GCP_FLAG_SET_STREAMING						0b00010000
		#define	PG_GCP_FLAG_SET_CRYPT							0b00100000
	//	#define	PG_GCP_FLAG_SET_6								0b01000000
	//	#define	PG_GCP_FLAG_SET_7								0b10000000
		//---[ And Flag ]---
		
		//---[ Buffer Mode ]---
		#define	PG_GCP_BUFFER									0
		#define	PG_GCP_STRING									1
		//---[ End Buffer Mode ]---

		//---[ Offset Reply Byte ]---
		#define	PG_GCP_REPLY_OFFSET_ADD							32		//!< Must match "Control Byte" below defined.
		//---[ End Offset Reply Byte ]---
		
		//---[ Identifier Control Byte ]---
		#define	PG_GCP_CONTROL_ESCAPE							'>'		//!< Escape char>
		#define	PG_GCP_CONTROL_ESCAPE_REPLY						'^'		//!< Escape char reply>
		//---[ End Identifier Control Byte ]---
		
/* 		//---[ Identifier Command Byte ]---
		#define	PG_GCP_CONTROL_ESCAPE							'?'		//!< Escape char>
		#define	PG_GCP_CONTROL_ESCAPE_REPLY						'_'		//!< Escape char reply>
		//---[ End Identifier Command Byte ]--- */

		//---[ Control Byte ]---
		#define	PG_GCP_CONTROL_ENGAGE							'E'	
		#define	PG_GCP_CONTROL_ENGAGE_REPLY						'e'		//!< PG_GCP_CONTROL_ENGAGE_REPLY = PG_GCP_CONTROL_ENGAGE + PG_GCP_REPLY_OFFSET_ADD>
		//---
		#define PG_GCP_CONTROL_VERSION							'V'
		#define PG_GCP_CONTROL_VERSION_REPLY					'v'
		//---
		#define PG_GCP_CONTROL_CONFIG							'C'
		#define PG_GCP_CONTROL_CONFIG_REPLY						'c'
		//---
		#define PG_GCP_CONTROL_DATA								'D'
		#define PG_GCP_CONTROL_DATA_REPLY						'd'
		//---
		#define PG_GCP_CONTROL_DATA_END							'Z'
		#define PG_GCP_CONTROL_DATA_END_REPLY					'z'
		//---
		#define PG_GCP_CONTROL_STATUS_SYNC						'S'
		#define PG_GCP_CONTROL_STATUS_SYNC_REPLY				's'
		//---
		#define PG_GCP_CONTROL_STATUS_MOD						'M'
		#define PG_GCP_CONTROL_STATUS_MOD_REPLY					'm'
		//---
		#define PG_GCP_CONTROL_CRC								'K'
		#define PG_GCP_CONTROL_CRC_REPLY						'k'
		//---
		#define PG_GCP_CONTROL_ENGAGE_END						'X'
		#define PG_GCP_CONTROL_ENGAGE_END_REPLY					'x'
		//---
		#define PG_GCP_CONTROL_RESET							'R'
		#define PG_GCP_CONTROL_RESET_REPLY						'r'
		//---
		#define PG_GCP_CONTROL_REQUEST							'Q'
		#define PG_GCP_CONTROL_REQUEST_REPLY					'q'
		//---
		#define PG_GCP_CONTROL_STREAMING						'G'
		#define PG_GCP_CONTROL_STREAMING_REPLY					'g'
		//---
		#define PG_GCP_CONTROL_COMMAND							'A'
		#define PG_GCP_CONTROL_COMMAND_REPLY					'a'
		//---[ End Control Byte ]---
		
		//---[ Return Messages ]---			
		#define	PG_GCP_RX_DATA_READY_NO							0xFF	//must be > #config					

		enum _pg_gcp_return_code_enum {
			PG_GCP_DUMMY = 100,
			PG_GCP_WAITING_DATA,
			// PG_GCP_CRC_OK,
			// PG_GCP_CONFIG_OK,
			// PG_GCP_COMMAND_OK,
			// PG_GCP_STATUS_MOD_OK,
			PG_GCP_STATUS_WAITING,
			PG_GCP_STREAMING_ON,
			PG_GCP_STREAMING_OFF,
			PG_GCP_ERROR_CONTROLBYTE_RESETTED,
			PG_GCP_ERROR_CONTROLBYTE_RESET_FAIL,
			PG_GCP_ERROR_ENGAGE_FAILED,
			PG_GCP_ERROR_ENGAGE_END_FAILED,
			PG_GCP_ERROR_ENGAGE_RESETTED,
			PG_GCP_ERROR_ENGAGE_NO,
			PG_GCP_ERROR_DATA_FAILED,
			PG_GCP_ERROR_DATA_END_FAILED,
			PG_GCP_ERROR_CONFIG_FAILED,
			PG_GCP_ERROR_STATUS_SYNC_FAILED,
			PG_GCP_ERROR_STATUS_MOD_FAILED,
			PG_GCP_ERROR_REQUEST_FAILED,
			PG_GCP_ERROR_STREAMING_FAILED,
			PG_GCP_ERROR_RESET_FAILED,
			PG_GCP_ERROR_COMMAND_FAILED,
			PG_GCP_ERROR_SAVE_BYTE_BUFFER_FAILED,
			PG_GCP_ERROR_READ_BYTE_SERIAL_TIMEOUT,
			PG_GCP_ERROR_TX_CONTROL_FAILED,
			PG_GCP_ERROR_CRC_FAILED,
			PG_GCP_ERROR_CRC_TX_FAILED,
			PG_GCP_ERROR_CRC_COMPARE_FAILED,
			PG_GCP_ERROR_CRC32_CANNOT_MATH,
			PG_GCP_ERROR_TX_BUFFER_FAILED,
			PG_GCP_ERROR_TX_STRING_FAILED,
			PG_GCP_ERROR_RX_DATA_READY_NO,
			PG_GCP_ERROR_RX_CONTROL_TIMEOUT,
			PG_GCP_ERROR_RX_BYTE_TIMEOUT,
			PG_GCP_ERROR_RX_CONFIG_FAILED,
			PG_GCP_ERROR_RX_REQUEST_FAILED,
			PG_GCP_ERROR_RX_STATUS_FAILED,
			PG_GCP_ERROR_RX_MOD_STATUS_FAILED,
			PG_GCP_ERROR_RX_CRC_TIMEOUT,
			PG_GCP_ERROR_RX_CRC_COMPARE_FAILED,
			PG_GCP_ERROR_RX_COMMAND_FAILED,
			
			PG_GCP_ERROR_VERSION_FAILED,
			PG_GCP_ERROR_VERSION_WRONG_APPLICATION_NAME,
			PG_GCP_ERROR_VERSION_WRONG_PICGIM_MINOR,
			PG_GCP_ERROR_VERSION_WRONG_PICGIM_MAJOR,
			PG_GCP_ERROR_VERSION_WRONG_APPLICATION_MINOR,
			PG_GCP_ERROR_VERSION_WRONG_APPLICATION_MAIOR
		};
		//---[ END Return Message ]---
				
		//---[ Prototype ]---
		extern _pg_Uint8	pg_gcp_dbyte;							//!< Generic rx byte>
		extern _pg_Uint8	pg_gcp_nconfig;							//!< Config id number>
		extern _pg_Uint16	pg_gcp_bindex;							//!< variabile di supporto alla modifica dell'indice del buffer
		
		extern _pg_Uint8	pg_gcp_rdr_index;
		extern _pg_Uint8	pg_gcp_rdu_index;
		extern _pg_Uint8	pg_gcp_rde_index;
		
		extern _pg_Uint8	pg_gcp_flag_tx;							//!<(1 bit flag todo?)
		extern _pg_Uint8	pg_gcp_flag_engage;						//!<(1 bit flag todo?)
		//extern _pg_Uint8	pg_gcp_flag_version;					//!<(1 bit flag todo?)
		extern _pg_Uint8	pg_gcp_flag_data_mode;					//!<(1 bit flag todo?)
		extern _pg_Uint8	pg_gcp_flag_request;					//!<(1 bit flag todo?)
		extern _pg_Uint8	pg_gcp_flag_streaming;					//!<(1 bit flag todo?)
		
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
		
		extern	struct pg_gcp_str_version {
			_pg_Uint8	user_app_name[ 4 ];					//!< Max.#4Byte. User's application name as identifier
			_pg_Uint8	user_app_version_major;				//!< #1Byte. User's application major version.
			_pg_Uint8	user_app_version_minor;				//!< #1Byte. User's application minor version.
			_pg_Uint8	picgim_version_major;				//!< #1Byte. PicGIM major version.
			_pg_Uint8	picgim_version_minor;				//!< #1Byte. PicGIM minor version.
		};
		
		extern	struct pg_gcp_str_config {
			void		* xbuffer_ptr;						//!<Payload buffer pointer>
			_pg_Uint16	xbuffer_length;						//!<Payload length. Total byte quantity to send in a packet; 0 = stream>
			_pg_Uint8	xbuffer_mode;						//!<It specifies the type of use: as buffer or as string <PG_GCP_BUFFER, PG_GCP_STRING>
			_pg_Uint8	xbuffer_index;						//!<Current position to write to next byte in buffer; 0 to ( PG_GCP_BUFFER_RX_xx_LENGTH - 1 ) >
			#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
				_pg_Uint8	xbuffer_status;					//!<Status of buffer: PG_GCP_BUFFER_EMPTY, PG_GCP_BUFFER_INCOMPLETE, PG_GCP_BUFFER_FULL>		
			#endif
		};
		extern	struct	pg_gcp_str_udata { 
			_pg_Uint8	uconf;	//#configuration
			void *		uptr;	//buffer-ptr
			_pg_Uint16	ulen;	//#byte rx
		};
		
		extern	struct	pg_gcp_str_config pg_gcp_v_config[ ( PG_GCP_CONFIGS_NUMBER + 1 ) ];
		extern	struct	pg_gcp_str_udata	pg_gcp_udata;
		
		//#######################################################################
		//---[   C O M M A N D   ]---
		//#######################################################################
		
		/*!
			\brief			Control to initialize all protocol variables and set hardware.\n
							Must be run by the first.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.

		*/
		void		pg_gcp_init								( void );

		/*!
			\brief			Control to execute local reset function to remote host and then locally.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		 
		_pg_Uint8	pg_gcp_reset							( void );	

		/*!
			\brief			Control to reset all variables locally.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		void 		pg_gcp_reset_local						( void );		

		/*!
			\brief			Control to occupy hardware channel and have the right to transmit.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage							( void );

		/*!
			\brief			Control to release hardware channel.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_engage_end						( void );

		#if ( PG_GCP_REQUEST_ENABLE == PG_ENABLE )
			
			/*!
				\brief			Control to set transmission request flag. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			void		pg_gcp_request_set					( _pg_Uint8 qvalue );
					
			/*!
				\brief			Control sent from receiving host, requiring to transmitter.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_request						( void );

			/*!
				\brief			What it do. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_rx_request					( void );
		#endif

		/*!
			\brief			Control to change configuration. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_config							( _pg_Uint8 configuration );	

		/*!
			\brief			Control to enter in data mode. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data								( void );	

		/*!
			\brief			Control to exit data mode.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_data_end							( void ); 

		/*!
			\brief			Control to exit data mode.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		
		_pg_Uint8	pg_gcp_tx_version						( void );
		
		/*!
			\brief			Control to exit data mode.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/		
		_pg_Uint8	pg_gcp_rx_version						( void );
	
		#if ( PG_GCP_STATUS_SYNC_ENABLE ==  PG_ENABLE )
			/*!
				\brief			Control to syncronize and retrieve remote status to local one.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_status_sync					( void );
		#endif
		
		#if ( PG_GCP_STATUS_MOD_ENABLE == PG_ENABLE )
			/*!
				\brief			Control to overwrite remote status. It is usefull with short string transmission, because void need to send full buffer, allowing to set buffer to full without complete transmission of buffer containing string.\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8 		pg_gcp_status_mod				( _pg_Uint8 value );
		#endif
		
		//#######################################################################
		//---[   F U N C T I O N   ]---
		//#######################################################################

		/*!
			\brief			Control to send a byte.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_tx_control_byte					( _pg_Uint8 control );

		/*!
			\brief			Control to transmit a buffer.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_tx_buffer						( _pg_Uint8 * tbuffer );


		/*!
			\brief			Control to transmit a null terminated string.\n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_tx_string						( _pg_Uint8 * tstring );

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
			_pg_Uint8	pg_gcp_crc						( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );

			/*!
				\brief			What it do. //write directly in pg_gcp_crc32_local\n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_crc32_calc				( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );//( _pg_Uint8 * cbuffer );
			/*!
				\brief			What it do. \n
								Conditions.
				\attention		Nothing.
				\return 		Nothing.
				\param			Nothing.
			*/
			_pg_Uint8	pg_gcp_rx_crc					( void );
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
		_pg_Uint8	pg_gcp_rx_reset							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_engage						( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_config						( void );		
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_escape						( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data_end						( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_data							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_engage_end					( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_status_sync					( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_status_mod					( void );

		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		_pg_Uint8	pg_gcp_rx_command						( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.						//config:	PG_GCP_CONFIG_00... PG_GCP_CONFIG_16
		*/													//crc_flag: PG_GCP_CRC_ON | PG_GCP_CRC_OFF
		_pg_Uint8	pg_gcp_send								( void * buffer_pointer, _pg_Uint8 config, _pg_Uint8 crc_flag ); // U S E R   F U N C T I O N
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		//_pg_Uint8 *	pg_gcp_read								( void ); // U S E R   F U N C T I O N
		_pg_Uint8	pg_gcp_read								( void ); // U S E R   F U N C T I O N
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		void	pg_gcp_rx_set_empty							( void );
		
		/*!
			\brief			What it do. \n
							Conditions.
			\attention		Nothing.
			\return 		Nothing.
			\param			Nothing.
		*/
		void	pg_gcp_empty_serial							( void );
	
		//---[ End Prototype ]---
 	#endif
#endif /* _PGIM_GCP_H_ */
 
 
/* 
	void		pg_gcp_init								( void );	 
	_pg_Uint8	pg_gcp_reset							( void );	
	void 		pg_gcp_reset_local						( void );	
	_pg_Uint8	pg_gcp_engage							( void );
	_pg_Uint8	pg_gcp_engage_end						( void );
	_pg_Uint8	pg_gcp_data								( void );	
	_pg_Uint8	pg_gcp_data_end							( void );
	_pg_Uint8	pg_gcp_config							( _pg_Uint8 configuration );	
	_pg_Uint8	pg_gcp_status_sync						( void );
	_pg_Uint8 	pg_gcp_status_mod						( _pg_Uint8 value );
	void		pg_gcp_request_set						( _pg_Uint8 qvalue );
	_pg_Uint8	pg_gcp_crc								( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );
	_pg_Uint8	pg_gcp_crc32_calc						( _pg_Uint8 * cbuffer, _pg_Uint16 cbuffer_length );//( _pg_Uint8 * cbuffer );
	_pg_Uint8	pg_gcp_tx_version						( void );
	_pg_Uint8	pg_gcp_rx_version						( void );
	_pg_Uint8	pg_gcp_tx_control_byte					( _pg_Uint8 control );
	_pg_Uint8	pg_gcp_tx_buffer						( _pg_Uint8 * tbuffer );
	_pg_Uint8	pg_gcp_tx_string						( _pg_Uint8 * tstring );
	_pg_Uint8	pg_gcp_rx								( void );
	_pg_Uint8	pg_gcp_rx_data_ready					( void );
	_pg_Uint8 * pg_gcp_rx_data_read						( void );
	_pg_Uint8	pg_gcp_send_byte_serial					( _pg_Uint8 sbyte );		
	_pg_Uint8	pg_gcp_read_byte_serial					( _pg_Uint16 tdelay );
	_pg_Uint8	pg_gcp_save_byte_buffer					( void );
	_pg_Uint8	pg_gcp_rx_crc							( void );
	_pg_Uint8	pg_gcp_rx_reset							( void );
	_pg_Uint8	pg_gcp_rx_engage						( void );
	_pg_Uint8	pg_gcp_rx_config						( void );		
	_pg_Uint8	pg_gcp_rx_request						( void );
	_pg_Uint8	pg_gcp_rx_escape						( void );
	_pg_Uint8	pg_gcp_rx_data_end						( void );
	_pg_Uint8	pg_gcp_rx_data							( void );
	_pg_Uint8	pg_gcp_rx_engage_end					( void );
	_pg_Uint8	pg_gcp_rx_status_sync					( void );
	_pg_Uint8	pg_gcp_rx_status_mod					( void );
	_pg_Uint8	pg_gcp_rx_command						( void );
	_pg_Uint8	pg_gcp_send								( void * buffer_pointer, _pg_Uint8 config, _pg_Uint8 crc_flag ); // U S E R   F U N C T I O N
	_pg_Uint8 *	pg_gcp_read								( void ); // U S E R   F U N C T I O N
	void		pg_gcp_rx_set_empty						( void );
	void		pg_gcp_empty_serial						( void );
*/


		// /*!
			// \brief			What it do. \n
							// Conditions.
			// \attention		Nothing.
			// \return 		Nothing.
			// \param			Nothing.
		// // #define	PG_GCP_FLAG_SET_TX								0b00000001
		// // #define	PG_GCP_FLAG_SET_ENGAGE							0b00000010
		// // #define	PG_GCP_FLAG_SET_DATA_MODE						0b00000100
		// // #define	PG_GCP_FLAG_SET_REQUEST							0b00001000
		// // #define	PG_GCP_FLAG_SET_STREAMING						0b00010000
		// // #define	PG_GCP_FLAG_SET_CRYPT							0b00100000
		
		// //	value: PG_ON | PG_OFF
		
		// */		
		// void	pg_gcp_flag_set( _pg_Uin8 flag , _pg_Uin8 value );
		
		// /*!
			// \brief			What it do. \n
							// Conditions.	
			// \attention		Nothing.
			// \return 		Nothing.
			// \param			Nothing.
		// */
		// _pg_Uin8	pg_gcp_flag_get( _pg_Uin8 flag );
		
		