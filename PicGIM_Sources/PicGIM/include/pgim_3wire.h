/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_3wire.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_timer.c

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

/*!		\file			pgim_3wire.h
		\version		0.6-0
		\date			2002 - 2016
		\brief			Simple 3-wire serial protocol
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_3WIRE_H_
	#define _PGIM_3WIRE_
	
	#if	( PGIM_3WIRE == PG_ENABLE )
	
		//---[ Prototypes ]---	
		void		pg_3wire_init				( void );
		void		pg_3wire_wr_byte			( _pg_Uint8 wr_byte );
		_pg_Uint8	pg_3wire_rd_byte			( void );
		//---[ End Prototypes ]---	
	
	#endif
	
#endif /* _PGIM_3WIRE_H_ */


/*!	\page 		SWD_3wire			3 Wire communication protocol

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


 





