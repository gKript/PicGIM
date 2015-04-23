/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ftoa.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_ftoa.c

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
		\file		pgim_ftoa.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To convert a float to string.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_FTOA_H
	#define	_PGIM_FTOA_H
	#if ( PGIM_FTOA == PG_ENABLE )
		//---[ Decimal Digits ]---
		#define PG_FTOA_DECIMAL_DIGITS_1			1					//!< One decimal digit after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_2			2					//!< Two decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_3			3					//!< Three decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_4			4					//!< Four decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_5			5					//!< Five decimal digits after decimal point.
		#define PG_FTOA_DECIMAL_DIGITS_6			6					//!< Six decimal digits after decimal point.
//		#define PG_FTOA_DECIMAL_DIGITS_7			7					//!< Seven decimal digits after decimal point.
		
		#define PG_FTOA_MAX_DIGITS					7					//!< Maximum manageable total digit number with high accuracy.
		//---[ END Decimal Digits ]---
		
		//---[ Errors ]---
		#define PG_FTOA_ERROR_OK					201					//!< No errors.
		#define PG_FTOA_ERROR_OVER_8_ACCURACY		202					//!< Digits are more than PG_FTOA_MAX_DIGITS. Accuracy required.
		#define PG_FTOA_ERROR_OVER_8_ACCURACY_NO	203					//!< Digits are more than PG_FTOA_MAX_DIGITS. Accuracy is not required.
		//---[ END Errors ]---

		//---[ Prototypes FtoA ]---
		extern	char		pg_ftoa_internal_buffer[ ];					//!< String with float value converted in char
		
		/*!
			\brief			Converts a float to string, managing the sign.
			
			\return			It returns a pointer to an internal buffer containing the string.
			
			If \ref PGIM_ERROR module is enabled it set:
			
			\b PG_FTOA_ERROR_OK : if everything is ok. \n
			\b PG_FTOA_ERROR_OVER_8_ACCURACY : if gigits are more than \a PG_FTOA_MAX_DIGITS and accuracy is required.
			\b PG_FTOA_ERROR_OVER_8_ACCURACY_NO : if gigits are more than \a PG_FTOA_MAX_DIGITS and accuracy is not required.
							
			\param			pg_ftoa_value					The float value to be converted to string.
			\param			pg_ftoa_trunc_decimal_digits	The number of digits after the decimal point at which to truncate. \n
															
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
		
		This module converts a float in a character string, managing the sign. \n
		In the public configuration file \ref pgim_module_setup_public.h are specified clearly \n
		the possible values for the various parameters. \n
		For software reference please read the documentation in \ref pgim_ftoa.h
		The module performs always the conversion, but: \n
		\arg  If the number of digits of the integer part plus the number of truncated decimal part \n
		(specified by \b pg_ftoa_trunc_decimal_digits parameter) is less than or equal to \ref PG_FTOA_MAX_DIGITS, \n
		it corresponds exactly to the digits of the value to be converted; \n \n
		\arg  If the number of digits of the integer part plus the number of truncated decimal part, \n
		the precision fells correspondingly and goes out of control. \n
		In this case if the \ref PG_FTOA_CONVERSION_ACCURATE define in \ref pgim_module_setup_public.h file, \n
		is set to \ref PG_YES (high accuracy), the module performs the conversion and sets a \a CRITICAL message, \n
		otherwise if it is set to \ref PG_NO, the module performs the conversion and sets only a \a WARNING message. \n
		See \ref PGIM_ERROR documentation.
		
		\attention	Here a link to the file : \ref pgim_ftoa.h \n
					This is not a file defined as public and therefore would not be edited. \n 
					We suggest that you edit this file only if necessary and only if you know what you are doing. \n \n
		
		\attention	The maximum number of digits manageable is \ref PG_FTOA_MAX_DIGITS. \n
					The string produced will contain a maximum of \ref PG_FTOA_MAX_DIGITS characters, \n
					excluding the decimal point and the possible sign.

		\note		The module is not able to handle float expressed in the format "E+000".

		\htmlonly <BR><BR><BR> \endhtmlonly

		\section	ftoaconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be included in the project. \n
					In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref fewtimerconfenm  \n
					\n \n \n

			\attention	For software reference, please read the documentation about \b pgim_ftoa.h . \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>

  			\n \n \n

		\subsection	ftoaen		Module enabling
			\htmlonly <hr> \endhtmlonly
			\code
				#define PGIM_FTOA							PG_ENABLE
			\endcode
				This define enables or disables the module.<br>
			\htmlonly
				It must be:<br>
			\endhtmlonly
				\arg \b PG_ENABLE : FtoA module enabled.
				\arg \b PG_DISABLE : FtoA module disabled.
				\endcode

			\subsubsection	ftoaenref		References
				\li \e File : pgim_module_setup_public.h \n
				\li \e Reference : \ref PGIM_FTOA \n
				
		\subsection	ftoapar		Module parameter
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_FTOA_CONVERSION_ACCURATE			PG_YES
			\endcode
				This #define declares that the precision required in the conversion is high.<BR>
				If not, it will return an error (the module \ref PGIM_ERROR must be enabled and configured).
			\htmlonly
				It must be:<br>
			\endhtmlonly
				\arg \b PG_YES : The precision required in the conversion is high.
				\arg \b PG_NO : The precision required in the conversion is not high.
				\endcode

			\subsubsection	ftoaconvref		References
				\li \e File : pgim_module_setup_public.h \n
				\li \e Reference : \ref PGIM_FTOA \n

		\section	ftoaexampleuse	A code example
			\htmlonly <hr> \endhtmlonly
			\endcode
	 
			Here is a simple example of how to use the module in the user code.
			\warning	In order to compile this example, the module must be enabled and properly configured.

			\code
				...
				
				pg_ftoa( 1.234567, PG_FLOAT_DECIMAL_DIGITS_3 ); //Returns a pointer to string: "1.234"
				
				...
			\endcode

		\htmlonly <br><br> \endhtmlonly
*/

//#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_SERIAL == PG_ENABLE ) || ( PGIM_SPI == PG_ENABLE ) )
