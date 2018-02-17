//
// pgim_caldelay.h
//
// picGim  -  Generic Information Manager for Pic 18 family uControllers 
// Version 0.5-x
// AsYntote - SkyMatrix
//
/*#############################################################################

	Copyright (C) 2002, 2003 
	Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	This file is part of Gim library.

	picGim is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	picGim is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with picGim; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#############################################################################*/

/*!	\file		pgim_sblcd_master.h
	\version	1.0-0
	\brief		Copyright (C) 2001, 2013<BR>
				Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)<BR>
				Released under the terms of the GNU General Public License v2<BR>
				[ http://gkript.org/gk_gpl_v2.php ]
*/ 		

#ifndef _PGIM_SBLCD_MASTER_H_
	#define _PGIM_SBLCD_MASTER_H_

	#if defined( __18CXX )
		#include <delays.h>
	#endif

	#ifdef	PGIM_SBLCD_MASTER
	
	 	#define	SBLCD_COMM_RESET					0x01
		#define	SBLCD_COMM_BLOFF					0x02
		#define	SBLCD_COMM_BLON					0x03
		#define	SBLCD_COMM_DISPOFF				0x04
		#define	SBLCD_COMM_DISPON					0x05
		#define	SBLCD_COMM_CUROFF				0x06
		#define	SBLCD_COMM_CURON					0x07
		#define	SBLCD_COMM_BLINKOFF				0x08
		#define	SBLCD_COMM_BLINKON				0x09
		#define	SBLCD_COMM_CLRSCRALL			0x0A
		#define	SBLCD_COMM_CLRSCR				0x0B
		#define	SBLCD_COMM_CEN01					0x10
		#define	SBLCD_COMM_CEN02					0x11
		#define	SBLCD_COMM_CEN03					0X12
		#define	SBLCD_COMM_CEN04					0X13
		#define	SBLCD_COMM_BLTGL					0X14
		#define	SBLCD_COMM_CRL1					0x20
		#define	SBLCD_COMM_CRL2					0x21
		#define	SBLCD_COMM_CRL3					0x22
		#define	SBLCD_COMM_CRL4					0x23
		#define	SBLCD_COMM_CLR_CURR			0x24
		#define	SBLCD_COMM_ALIMOFF				0X30
		#define	SBLCD_COMM_ALIMON				0X31
		#define	SBLCD_COMM_ALIMTGL				0X32
		#define	SBLCD_COMM_INIT						0XC0
		#define	SBLCD_COMM_GETDATA				0XD0
		#define	SBLCD_COMM_GETSTREG			0XD1
		#define	SBLCD_COMM_GETADDR				0XD2
		#define	SBLCD_COMM_RESERROR			0XF0
		#define	SBLCD_COMM_TESTERROR			0XF1
		
		/*!	\fn					void pg_sbdlc_mv1_Init( void )
				\brief				This is the 
				\deprecated	This Function is already called in 
		*/
		void					pg_sbdlc_mv1_Init						( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_ResetError			( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_ClkPulse				( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_WaitBusyDown		( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_WaitBusyUp			( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_Delay					( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		_pg_int8					pg_sblcd_mv1_Puts						( rom _pg_int8 * to_lcd );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		_pg_int8					pg_sblcd_mv1_PutsRam				( _pg_int8 * to_lcd );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		_pg_int8					pg_sblcd_mv1_SendData				( _pg_Uint8 to_send );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		void					pg_sblcd_mv1_SendCommand		( _pg_Uint8 to_send );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		_pg_Uint8	pg_sblcd_mv1_GetCommand		( void );

		/*!	\fn			void pg_sbdlc_mv1_Init( void )
				\brief		To delete an existing section from a ini file
				\param	section_name	The name of the section you want to delete\n
								\a section_name != NULL
				\return 	\a __OK		if everything it's ok\n
								\a __NOT_OK if some error occurred
		*/
		_pg_int8					pg_sbl_mv1cd_ClrRow					( _pg_Uint8 row );
		
	#endif

#endif

/*

	\page		SBLCDMP		Serial bus	LCD Master

*/
