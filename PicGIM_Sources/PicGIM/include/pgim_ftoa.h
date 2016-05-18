/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ftoa.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.6
	Current version :		0.6-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_ftoa.c

	START LICENSE	GPL	V3.0

		PicGIM is a "modular library from scratch".
		PicGIM is developed to work with PIC18F (R) MCU family only.

		Copyright (C) 2016  gKript.org - We.PIC project - <http://www.gkript.org>

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
		\date		2002 - 2016
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
		
		//---[ Define ]---
		//	None.
		//---[ END Define ]---		

		//---[ Prototypes FtoA ]---
		extern	char		pg_ftoa_internal_buffer[ ];					//!< String with float value converted in char
		
		/*!
			\brief			Converts a float to string, managing the sign.
			
			\return			It returns a pointer to an internal buffer containing the string.												
		*/		
		char *	pg_ftoa( _pg_float pg_ftoa_value, _pg_Uint8 pg_ftoa_trunc_decimal_digits );
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
		
		\attention	Here a link to the file : \ref pgim_ftoa.h \n
					This is not a file defined as public and therefore would not be edited. \n 
					We suggest that you edit this file only if necessary and only if you know what you are doing. \n \n
					
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
				#define PG_FTOA_PRINT_SIGN_PLUS					PG_NO
			\endcode
				 For positive float number, with this #define it is possible to choose whether print or not a plus sign in front of the string.<BR>
			\htmlonly
				It must be:<br>
			\endhtmlonly
				\arg \b PG_YES : Print plus sign.
				\arg \b PG_NO : Does not print plus sign.
				\endcode
			
			\code
				#define PG_FTOA_PRINT_SIGN_MINUS				PG_YES
			\endcode
				For positive float number, with this #define it is possible to choose whether print or not a minus sign in front of the string.<BR>
			\htmlonly
				It must be:<br>
			\endhtmlonly
				\arg \b PG_YES : Print minus sign.
				\arg \b PG_NO : Does not print minus sign.
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
				
				pg_ftoa( -1.234567, 3 ); //Returns a pointer to string: "-1.234"
				
				...
			\endcode

		\htmlonly <br><br> \endhtmlonly
*/


