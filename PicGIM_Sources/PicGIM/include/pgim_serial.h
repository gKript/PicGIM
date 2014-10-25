//
// pgim_serial.h
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

/*!		\file			pgim_serial.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			Automatically configures the USART.
		\details		Calculates the parameters needed to obtain the baud rate defined by the user, or automatically searches for the highest.
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_SERIAL_H_
	#define _PGIM_SERIAL_H_

	#if ( PGIM_SERIAL == PG_ENABLE )

		//---[ Baudrate ]---
		#define PG_SERIAL_BAUDRATE_300						300				//!< Baudrate value. The relative index is: 8
		#define PG_SERIAL_BAUDRATE_1200						1200			//!< Baudrate value. The relative index is: 7
		#define PG_SERIAL_BAUDRATE_2400						2400			//!< Baudrate value. The relative index is: 6
		#define PG_SERIAL_BAUDRATE_4800						4800			//!< Baudrate value. The relative index is: 5
		#define PG_SERIAL_BAUDRATE_9600						9600			//!< Baudrate value. The relative index is: 4
		#define PG_SERIAL_BAUDRATE_19200					19200			//!< Baudrate value. The relative index is: 3
		#define PG_SERIAL_BAUDRATE_38400					38400			//!< Baudrate value. The relative index is: 2
		#define PG_SERIAL_BAUDRATE_57600					57600			//!< Baudrate value. The relative index is: 1
		#define PG_SERIAL_BAUDRATE_115200					115200			//!< Baudrate value. The relative index is: 0
		
		#define PG_SERIAL_BAUDRATE_VALUE_QUANTITY			9				//!< How many baudrate value are available
		//---[ END Baudrate ]---

		//---[ Errors ]---	
		#define PG_SERIAL_ERROR_BAUDRATE_NOT_FOUND			-1				//!< System clock too slow, or accuracy too close.
		//---[ END Errors ]---
		
		//---[ Prototypes ]---
		/*!
			\brief			This function properly initializes the SERIAL module. \n
							This module uses the serial device EUSART in asynchronous mode.
			\attention		Internal use only !
			\return			\b PG_OK : if the initialization was successful. \n
							\b PG_SERIAL_ERROR_BAUDRATE_NOT_FOUND : if the initialization has failed. \n
								It was not possible to correctly calculate the baud rate according to the set parameters.
			\param			Nothing.
			\deprecated		Do not call directly. \n
							Already called in pg_initialize().
		*/
		_pg_int8 	pg_serial_init							( void );
		
		/*!
			\brief			Allows to open the serial device.
			\return 		Nothing.
			\param			Nothing.
		*/
		void 		pg_serial_open							( void );
		
		/*!
			\brief			Allows to close the serial device.
			\return 		Nothing.
			\param			Nothing.
		*/
		void	 	pg_serial_close							( void );
		
		/*!
			\brief			Converts the value of an index in the corresponding value of the baud-rate.
			\attention		Internal use only !
			\return 		Returns the value of the baud-rate as a function of the index.
			\param			pg_serial_baudrate_index			The value of the index.
		*/
		_pg_Uint32	pg_serial_baudrate_converter			( _pg_Uint8 pg_serial_baudrate_index );
		
		/*!
			\brief			Notifies that the configuration of the serial device was successful. \n
							It can operate on a pin or on display.
			\attention		Internal use only !
			\return 		Nothing.
			\param			Nothing.
		*/
		void		pg_serial_debug_ok						( void );
		
		/*!
			\brief			Notifies that the configuration of the serial device has failed. \n
							It can operate on a pin or on display.
			\attention		Internal use only !
			\return 		Nothing.
			\param			Nothing.
		*/
		void		pg_serial_debug_fail					( void );
		//---[ END Prototypes ]---
		
	#endif
#endif /* _PGIM_SERIAL_H_ */

/*!	\page 		HWI_serial			Serial [EUSART]

		\htmlonly
			<IMG src="serial.png" align="center" border="0" ><br><br>
		\endhtmlonly
		
		The \b SERIAL module provides a set of functions to easily configure and manage asynchronous serial device (EUSART). \n \n
		The only configurable mode is 8N1: 8 bits, no parity, 1 stop bit. \n \n
		The serial device can be configured in three ways: \n
			\arg \b MANUAL : Directly specify the values of the registers. Only set the necessary parameters.
			\arg \b SEMI-AUTOMATIC : The value of the baud rate is set as explicitly required. Only set the necessary parameters.
			\arg \b AUTOMATIC : The maximum speed will be calculated and set. Only set the necessary parameters.
			
		In the public configuration file \ref pgim_serial_setup_public.h are specified clearly the possible values 
		for the various parameters and when they have to be set depending on the chosen mode of operation of the SERIAL module. \n \n
		In automatic and semi-automatic mode, the calculations are performed according to the required accuracy 
		(expressed as a percentage) and other parameters such as the value of the clock frequency the speed
		of the baud-rate calculated will be revealed through the output devices set to debug. \n \n
		If the configuration fails, try increasing the tolerance. \n 
		Refer to the respective datasheets of the micro-controller to the order of magnitude of the precision obtainable. \n \n
		The module can be configured by editing the file \ref pgim_serial_setup_public.h \n \n
		For software reference, please read the documentation in \ref pgim_serial.h

		\htmlonly
			<br><br><br><br>
		\endhtmlonly
		
	\attention	Here a link to the file : \ref pgim_serial.h \n
				This is not a file defined as public and therefore would not be edited. \n 
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/


