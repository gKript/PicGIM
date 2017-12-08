//GCP - General Communication Protocol

#ifndef _PGIM_GCP_SETUP_PUBLIC_H_
	#define _PGIM_GCP_SETUP_PUBLIC_H_

	#if ( PGIM_GCP == PG_ENABLE )
		
		//-------------------------------------------------------------------------------------------------------------
		//		D E L A Y
		//-------------------------------------------------------------------------------------------------------------
		#define	PG_GCP_DELAY_RESET_TX							1000		//!< Min. 1ms - Max. 60000ms
		#define	PG_GCP_DELAY_RESET_RX							200			//!< Min. 1ms - Max. 60000ms
		
		//-------------------------------------------------------------------------------------------------------------
		//		T I M E O U T
		//-------------------------------------------------------------------------------------------------------------
		#define	PG_GCP_TIMEOUT_MS_TX							2000		//!< Min. 1ms - Max. 60000ms
		#define	PG_GCP_TIMEOUT_MS_RX							2000		//!< Min. 1ms - Max. 60000ms
		#define	PG_GCP_TIMEOUT_MS_DIAL							2000		//!< Min. 1ms - Max. 60000ms
		#define PG_GCP_TIMEOUT_MS_CRC							6000		//!< Min. 1ms - Max. 60000ms

		//-------------------------------------------------------------------------------------------------------------		
		//		A U T O - R E S E T
		//-------------------------------------------------------------------------------------------------------------
		#define PG_GCP_AUTORESET_ENGAGE_ENABLE					PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE			Autoreset on engage fail

		//-------------------------------------------------------------------------------------------------------------		
		//		S T A T U S
		//-------------------------------------------------------------------------------------------------------------
		#define PG_GCP_STATUS_SYNC_ENABLE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_STATUS_MOD_ENABLE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		
		//-------------------------------------------------------------------------------------------------------------
		//		C R C
		//-------------------------------------------------------------------------------------------------------------
		#define PG_GCP_CRC_ENABLE								PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		
		//-------------------------------------------------------------------------------------------------------------
		//		F U N C T I O N S
		//-------------------------------------------------------------------------------------------------------------
		#define	PG_GCP_REQUEST_ENABLE							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE	
		
		//-------------------------------------------------------------------------------------------------------------
		//		C O N F I G U R A T I O N S
		//-------------------------------------------------------------------------------------------------------------
		//	Warning: Configurations MUST be enabled sequentially.
		//	The first is "Config 01", the second is "Config 02" and so on...
		//	Config 0 is always default enabled and it is not in count.
		//-------------------------------------------------------------------------------------------------------------
		#define PG_GCP_CONFIGS_NUMBER							1				//!< Number of configurations below enabled. Set to "2" if are enabled "Config 1" and "Config 2">																	
		//-------------------------------------------------------------------------------------------------------------
		// 		C O N F I G   00 								It is always enabled and its length is #1 byte.
		//
		// 		C O N F I G   01
		#define PG_GCP_BUFFER_RX_01_ENABLE						PG_ENABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_01_LENGTH						5				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_01_MODE						PG_GCP_STRING	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   02
		#define PG_GCP_BUFFER_RX_02_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_02_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_02_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   03
		#define PG_GCP_BUFFER_RX_03_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_03_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_03_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   04
		#define PG_GCP_BUFFER_RX_04_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_04_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_04_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   05
		#define PG_GCP_BUFFER_RX_05_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_05_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_05_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   06
		#define PG_GCP_BUFFER_RX_06_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_06_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_06_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   07
		#define PG_GCP_BUFFER_RX_07_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_07_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_07_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   08
		#define PG_GCP_BUFFER_RX_08_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_08_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_08_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   09
		#define PG_GCP_BUFFER_RX_09_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_09_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_09_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   10
		#define PG_GCP_BUFFER_RX_10_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_10_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_10_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   11
		#define PG_GCP_BUFFER_RX_11_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_11_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_11_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING

		// 		C O N F I G   12
		#define PG_GCP_BUFFER_RX_12_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_12_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_12_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   13
		#define PG_GCP_BUFFER_RX_13_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_13_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_13_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   14
		#define PG_GCP_BUFFER_RX_14_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_14_LENGTH						1				//!< Min. 1 - Max. xxxxxx >
		#define	PG_GCP_BUFFER_RX_14_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   15
		#define PG_GCP_BUFFER_RX_15_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_15_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_15_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		// 		C O N F I G   16
		#define PG_GCP_BUFFER_RX_16_ENABLE						PG_DISABLE		//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_BUFFER_RX_16_LENGTH						1				//!< Min. 1 - Max. xxxxxx >		
		#define	PG_GCP_BUFFER_RX_16_MODE						PG_GCP_BUFFER	//!< Must be: PG_GCP_BUFFER || PG_GCP_STRING
		
		//-------------------------------------------------------------------------------------------------------------		
		//		L E D - I N D I C A T O R 
		//-------------------------------------------------------------------------------------------------------------
		#define PG_GCP_LED_GLOBAL_ENABLE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		//
		#define PG_GCP_LED_SCAN_ENABLE							PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		//
		#define PG_GCP_LED_ENGAGE_ENABLE						PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_DATA_ENABLE							PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_CONFIG_ENABLE						PG_ENABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_CRC_ENABLE							PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_RESET_ENABLE							PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_COMMAND_ENABLE						PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_STREAMING_ENABLE						PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_TX_ENABLE							PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		#define PG_GCP_LED_RX_ENABLE							PG_DISABLE	//!< Must be: PG_ENABLE  ||  PG_DISABLE
		//
		#define PG_GCP_LED_ENGAGE_LAT							L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_DATA_LAT								L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_CONFIG_LAT							L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_CRC_LAT								L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_RESET_LAT							L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_COMMAND_LAT							L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_STREAMING_LAT						L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_TX_LAT								L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		#define PG_GCP_LED_RX_LAT								L_C0		//!< Must be: <pin-lat-name> || PG_MISSING if not used.
		//
		#define PG_GCP_LED_ENGAGE_TRIS							T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_DATA_TRIS							T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_CONFIG_TRIS							T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_CRC_TRIS								T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_RESET_TRIS							T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_COMMAND_TRIS							T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_STREAMING_TRIS						T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_TX_TRIS								T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		#define PG_GCP_LED_RX_TRIS								T_C0		//!< Must be: <pin-tris-name> || PG_MISSING if not used.
		
		//-------------------------------------------------------------------------------------------------------------
	#endif
#endif /* _PGIM_GCP_SETUP_PUBLIC_H_ */
 
 	
	
