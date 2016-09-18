/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_serial_setup_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

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
		\file		pgim_serial_setup_public.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		SERIAL module configuration public file.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This file is defined as public and therefore must be edited for proper configuration of the library.
*/

#ifndef _PGIM_SERIAL_SETUP_PUBLIC_H_
	#define _PGIM_SERIAL_SETUP_PUBLIC_H_

	#if ( PGIM_SERIAL == PG_ENABLE )

		// 		C O N F I G   M O D E
		#define PGIM_SERIAL_BAUDRATE_MODE				PG_SEMI_AUTOMATIC	//!< Must be: PG_MANUAL || PG_SEMI_AUTOMATIC || PG_AUTOMATIC

		
		//		P A R A M E T E R S
		//( CONFIG ONLY IN MANUAL MODE )
		#define PGIM_SERIAL_BAUDRATE_SPEED				USART_BRGH_LOW		//!< Must be: USART_BRGH_LOW || USART_BRGH_HIGH \n Refer to the datasheet for the micro-controller chosen.
		#define PGIM_SERIAL_BAUDRATE_REGISTER			25					//!< Set the registry value of the baud-rate. \n Refer to the datasheet for the micro-controller chosen.
		
		//( CONFIG ONLY IN SEMI_AUTOMATIC MODE )
		#define PGIM_SERIAL_BAUDRATE					2400				//!< The possible values are: 300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200

		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
//		#define PGIM_SERIAL_BAUDRATE_ACCURACY			1.00				//!< Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration.
		#define PGIM_SERIAL_BAUDRATE_ACCURACY			1					//!< Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration.
		
		
		//		R X   M O D E
		//( CONGIF ALWAYS )
		#define PGIM_SERIAL_RX_MODE						USART_CONT_RX		//!< Must be: USART_SINGLE_RX || USART_CONT_RX		
		
		
	#endif
#endif /* _PGIM_SERIAL_SETUP_PUBLIC_H_ */


		