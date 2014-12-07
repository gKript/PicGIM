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
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing.
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

		\tableofcontents

		\image html	serial.png
		
		The \b SERIAL module provides a set of functions to easily configure and manage asynchronous serial device (EUSART). \n 
		The only configurable mode is 8N1: 8 bits, no parity, 1 stop bit. \n \n

 		The serial device can be configured in three ways: \n
			\arg \b MANUAL : Directly specify the values of the registers. Only set the necessary parameters.
			\arg \b SEMI-AUTOMATIC : The value of the baud rate is set as explicitly required. Only set the necessary parameters.
			\arg \b AUTOMATIC : The maximum speed will be calculated and set. Only set the necessary parameters.

		In automatic and semi-automatic mode, the calculations are performed according to the required accuracy
		(expressed as a percentage) and other parameters. \n \n
		If the configuration fails, try increasing the tolerance. \n
		Refer to the respective datasheets of the micro-controller to the order of magnitude of the precision obtainable. \n \n

		\htmlonly
			<br><br>
		\endhtmlonly


 		\section	confserial	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg	\b pgim_module_setup_public.h : the main management file for the modules. \n
						In this file there are these configurations  : \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref serialconfenm  \n
						\n \n \n
				\arg	\b pgim_serial_setup_public.h : where are collected all the features of the module. \n
						Here are specified the possible values for the various parameters
						and when they have to be set depending on the chosen mode of operation of the module. \n In this file there are these configurations  : \n \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref configserialmanual \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref configserialsemiauto \n
						&nbsp;&nbsp;&nbsp;&nbsp; \ref configserialauto \n
						\n \n \n &nbsp;&nbsp;&nbsp;&nbsp;

			\attention	For software reference, please read the documentation about \b pgim_serial.h. \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.

			</p>
			\n \n \n


			\subsection	serialconfenm	Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SERIAL						PG_ENABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : pwm module enabled.
					\arg \b PG_DISABLE : pwm module disabled.
					\endcode

				\subsubsection	serialmodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_SERIAL \n

				\htmlonly <br> \endhtmlonly


			\subsection	configserialmanual		Manual mode
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SERIAL_BAUDRATE_MODE			PG_MANUAL

				\endcode
					This define enable the manual mode for the SERIAL module. \n
					They must be: \n
					\arg \b PG_MANUAL : Manual mode enabled.

				\code
			 		#define PGIM_SERIAL_BAUDRATE_SPEED			USART_BRGH_LOW

				\endcode
					Refer to the datasheet for the micro-controller chosen. \n
					They must be: \n
					\arg \b USART_BRGH_LOW : Low baud rate.
					\arg \b USART_BRGH_HIGH : High baud rate.

				\code
			 		#define PGIM_SERIAL_RX_MODE					USART_CONT_RX

				\endcode
					Continuos or single reception. \n
					They must be: \n
					\arg \b USART_SINGLE_RX : Single reception.
					\arg \b USART_CONT_RX : Continuos reception.

				\code
					#define PGIM_SERIAL_BAUDRATE_REGISTER		25

				\endcode
					Set the registry value of the baud-rate. \n Refer to the datasheet for the micro-controller chosen. \n

				\subsubsection	configserialmanualref		References
					\li \e File : pgim_serial_setup_public.h \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_MODE \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_SPEED \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_REGISTER \n

				\htmlonly <br> \endhtmlonly


 			\subsection	configserialsemiauto		Semi-Automatic mode
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SERIAL_BAUDRATE_MODE		PG_SEMI_AUTOMATIC

				\endcode
					This define enable the manual mode for the SERIAL module. \n
					They must be: \n
					\arg \b PG_SEMI_AUTOMATIC : Semi-Automatic mode enabled.

				\code
					#define PGIM_SERIAL_BAUDRATE				2400

				\endcode
					The baudtrate of the serial. \n
					They must be: \n
					\arg \b 300
					\arg \b 1200
					\arg \b 2400
					\arg \b 4800
					\arg \b 9600
					\arg \b 19200
					\arg \b 38400
					\arg \b 57600
					\arg \b 115200

 				\code
					#define PGIM_SERIAL_BAUDRATE_ACCURACY		1.00

				\endcode
					Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration. \n

				\code
			 		#define PGIM_SERIAL_RX_MODE					USART_CONT_RX

				\endcode
					Continuos or single reception. \n
					They must be: \n
					\arg \b USART_SINGLE_RX : Single reception.
					\arg \b USART_CONT_RX : Continuos reception.

 				\subsubsection	configserialsemiautoref		References
					\li \e File : pgim_serial_setup_public.h \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_MODE \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_ACCURACY \n

				\htmlonly <br> \endhtmlonly


			\subsection	configserialauto		Automatic mode
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SERIAL_BAUDRATE_MODE			PG_AUTOMATIC

				\endcode
					This define enable the manual mode for the SERIAL module. \n
					They must be: \n
					\arg \b PG_MANUAL : Manual mode enabled.

 				\code
					#define PGIM_SERIAL_BAUDRATE_ACCURACY		1.00

				\endcode
					Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration. \n

				\code
			 		#define PGIM_SERIAL_RX_MODE					USART_CONT_RX

				\endcode
					Continuos or single reception. \n
					They must be: \n
					\arg \b USART_SINGLE_RX : Single reception.
					\arg \b USART_CONT_RX : Continuos reception.

				\subsubsection	configserialautoref		References
					\li \e File : pgim_serial_setup_public.h \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_MODE \n
					\li \e Reference : \ref PGIM_SERIAL_BAUDRATE_ACCURACY \n



			\htmlonly
				<br><br>
			\endhtmlonly

			\attention	Here a link to the file : \ref pgim_serial.h \n
						This is not a file defined as public and therefore would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.

			\htmlonly
				<br><br>
			\endhtmlonly


 		\section	serialcsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

				\subsection	serialprivfunc	Private functions
					\note With \b "private" we mean a function that should not be used by the user in its code. \n In the documents are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

					\arg \b pg_serial_init()
					\arg \b pg_serial_baudrate_converter() : Converts the value of an index in the corresponding value of the baud-rate.


			\subsection	serialpubfunc	Public functions
				\arg \b pg_serial_open() : Allows to open the serial device.
				\arg \b pg_serial_close() : Allows to close the serial device.

			\htmlonly
				<br><br>
			\endhtmlonly


		\section	serialexampleuse	A code example
			\htmlonly <hr> \endhtmlonly
			\endhtmlonly

			Here is a simple example of how to use the module in your code.
			\warning	In order to compile this example, the module must be enabled and properly configured.
			\note 		This example use the Delay module also.

			\code
				...
				pg_serial_open();
				...
				pg_serial_close();
				...
			\endcode

			\htmlonly <br><br> \endhtmlonly


 	\section	serialinterrupthowto	Using this module with interrupts
		\endhtmlonly

		If the interrupt handling is enable is possible, through the interrupt signal \ref PG_EVENT_SET_USARTRC and \ref PG_EVENT_SET_USARTTX, have an interrupt at every char received or trasmitted. \n
		If using the \b Automatic \b Interrupts \b Handler pg_event_auto_handler() your associated callback will be called at each event. \n \n

		\b References : \n
			Interrups configuration :\ref iterruptconf \n
			Internal interrupts configuration : \ref interdefinesintern \n
			Callback configuration : \ref interruptcallbackhowto \n

		\htmlonly <br><br> \endhtmlonly

 */

