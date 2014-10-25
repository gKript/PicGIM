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
		\brief			Converts 32-bit float to string. It is lightweight.
		\details	
		\author			DarioG(Dario Greggio), Ren and 1and0 from the forum of Microchip(R) (original version)		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_FTOA_H
	#define	_PGIM_FTOA_H
	#if ( ( PGIM_LCD_HD44780 == PG_ENABLE ) || ( PGIM_SERIAL == PG_ENABLE ) || ( PGIM_SPI == PG_ENABLE ) )

		/*!
			\brief			Converts 32-bit float to string; lightweight and high precision.
			\return			Nothing.

			\param			pg_ftoa_value			The 32-bit float value to convert to string. \n
			\param			pg_ftoa_buffer			The pointer to buffer where store the string. \n

			\attention		\b It should only be used in case it is not necessary a great accuracy.

		*/			
		void		pg_ftoa							( _pg_float pg_ftoa_value, char * pg_ftoa_buffer );
	#endif
#endif	/* _PGIM_FTOA_H */

/*!	\page 		SWG_float			Float to Ascii
		
		\tableofcontents

		\image html	ftoa.png
		
		This function converts a float value to 32-bit in a character string. \n

		\htmlonly
			<br><br><br><br>
		\endhtmlonly
	\note	This feature is automatically included by enabling the following modules: \n
					\b PGIM_LCD_HD44780 \n
					\b PGIM_SERIAL \n
					\b PGIM_SPI \n
					
	\note	This function was originally taken from the forum of Microchip site. \n
			It was written by DarioG (Dario Greggio) and modified by Ren and 1and0. \n
			The thread can be reached at the address: \n
			http://www.microchip.com/forums/m295647.aspx#295739 \n
			It has been modified to suit the PicGIM's environment. \n
				
	\attention	Here a link to the file : \ref pgim_float.h \n
				This is not a file defined as public and therefore would not be edited. \n 
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

