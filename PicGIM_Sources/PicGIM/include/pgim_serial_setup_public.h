//
// pgim_serial_setup_public.h
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

/*!		\file			pgim_serial_setup_public.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			SERIAL module configuration public file.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_SERIAL_SETUP_PUBLIC_H_
	#define _PGIM_SERIAL_SETUP_PUBLIC_H_

//	#if ( PGIM_SERIAL == PG_ENABLE )

		// 		C O N F I G   M O D E
		#define PGIM_SERIAL_BAUDRATE_MODE				PG_MANUAL			//!< Must be: PG_MANUAL || PG_SEMI_AUTOMATIC || PG_AUTOMATIC

		
		//		P A R A M E T E R S
		//( CONFIG ONLY IN MANUAL MODE )
		#define PGIM_SERIAL_BAUDRATE_SPEED				USART_BRGH_LOW		//!< Must be: USART_BRGH_LOW || USART_BRGH_HIGH \n Refer to the datasheet for the micro-controller chosen.
		#define PGIM_SERIAL_BAUDRATE_REGISTER			25					//!< Set the registry value of the baud-rate. \n Refer to the datasheet for the micro-controller chosen.
		
		//( CONFIG ONLY IN SEMI_AUTOMATIC MODE )
		#define PGIM_SERIAL_BAUDRATE					2400				//!< The possible values are: 300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200

		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_BAUDRATE_ACCURACY			1.00				//!< Percentage baudrate error value. \n It is the reference for the calculation of the automatic configuration.
		
		
		//		R X   M O D E
		//( CONGIF ALWAYS )
		#define PGIM_SERIAL_RX_MODE						USART_CONT_RX		//!< Must be: USART_SINGLE_RX || USART_CONT_RX		
		

		//		B A U D R A T E   D E B U G   O U T P U T   T O   P I N
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_DEBUG_TO_PIN				PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		#define PGIM_SERIAL_DEBUG_PIN					L_B3				//!< Output pin for debugging
		#define PGIM_SERIAL_DEBUG_PIN_TRIS				T_B3				//!< Debugging output pin tris
		
		
		//		B A U D R A T E   D E B U G   O U T P U T   T O   B U Z Z E R
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		#define PGIM_SERIAL_DEBUG_TO_BUZZER				PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		
		
		//		B A U D R A T E   D E B U G   O U T P U T   T O   L C D
		//( CONFIG ONLY IN SEMI_AUTOMATIC AND AUTOMATIC MODE )
		//#define PGIM_SERIAL_DEBUG_TO_LCD_PCD8544		PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE. It is not yet supported.
		#define PGIM_SERIAL_DEBUG_TO_LCD_HD44780		PG_ENABLE			//!< Must be: PG_ENABLE || PG_DISABLE
		
		
//	#endif
#endif /* _PGIM_SERIAL_SETUP_PUBLIC_H_ */


		