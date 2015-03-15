//
// pgim_ftoa.h
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

/*!		\file			pgim_ftoa.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			Converts a float to string.
		\details
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_FTOA_H
	#define	_PGIM_FTOA_H
	#if ( PGIM_FTOA == PG_ENABLE )
		//---[ Decimal Digits ]---
		#define PG_FTOA_DECIMAL_DIGITS_1			10					//!< One decimal digit after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_2			100					//!< Two decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_3			1000				//!< Three decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_4			10000				//!< Four decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_5			100000				//!< Five decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_6			1000000				//!< Six decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_7			10000000			//!< Seven decimal digits after decimal point.
		
		#define PG_FTOA_MAX_DIGITS					7					//!< Maximum manageable total digit number with high accuracy.
		//---[ END Decimal Digits ]---
		
		//---[ Errors ]---
		#define PG_FTOA_ERROR_OK					201					//!< No errors.
		#define PG_FTOA_ERROR_OVER_8_ACCURACY		202					//!< Digits are more than PG_FTOA_MAX_DIGITS. Accuracy required.
		#define PG_FTOA_ERROR_OVER_8_ACCURACY_NO	203					//!< Digits are more than PG_FTOA_MAX_DIGITS. Accuracy is not required.
		//#define PG_FTOA_ERROR_BUFFER_DISABLED		204					//!< Trying to use the internal buffer, but that is disabled
		//#define PG_FTOA_ERROR_WRONG_CONFIG_BUFFER	205					//!< Wrong configuration of the buffer in "pgim_module_setup_public.h"
		//---[ END Errors ]---

		//---[ Prototypes FtoA ]---
		extern	char		pg_ftoa_internal_buffer[ ];					//!< String with float value converted in char
		
		/*!
			\brief			Converts a float to string.
		*/			
		char *	pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint24 pg_ftoa_trunc_decimal_digits );
		//---[ END Prototypes FtoA ]---
	#endif
#endif	/* _PGIM_FTOA_H */

/*!	
	\page 		SWG_float			Float to Ascii
		
		\tableofcontents
		
		\n \n
		\image html	ftoa.png
		\n \n
		
		This function converts a float in a character string, managing the sign. \n
		
		\code
			pg_ftoa( 1.234567, PG_FLOAT_DECIMAL_DIGITS_3 ); //Returns a pointer to string: "1.234"
		\endcode
		
		The function performs always the conversion, but: \n
		\arg  If the number of digits of the integer part plus the number of truncated decimal part \n
		(specified by \b pg_ftoa_trunc_decimal_digits parameter) is less than or equal to \ref PG_FTOA_MAX_DIGITS, \n
		it corresponds exactly to the digits of the value to be converted; \n \n
		\arg  If the number of digits of the integer part plus the number of truncated decimal part, \n
		the precision fells correspondingly and goes out of control. \n
		In this case if the \ref PG_FTOA_CONVERSION_ACCURATE define in \ref pgim_module_setup_public.h file, \n
		is set to \ref PG_YES (high accuracy), the function performs the conversion and sets a CRITICAL message, \n
		otherwise if it is set to \ref PG_NO, the function performs the conversion and sets only a WARNING message. \n
		See \ref PGIM_ERROR documentation.
		
		\return			It returns a pointer to an internal buffer containing the string.

		\param			pg_ftoa_value					The 32-bit float value to converted to string. \n
		\param			pg_ftoa_trunc_decimal_digits	The number of digits after the decimal point at which to truncate. \n
			
		\htmlonly
			<br><br><br><br>
		\endhtmlonly
				
		\attention	Here a link to the file : \ref pgim_ftoa.h \n
				This is not a file defined as public and therefore would not be edited. \n 
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

//#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_SERIAL == PG_ENABLE ) || ( PGIM_SPI == PG_ENABLE ) )
