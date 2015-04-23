/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_buzzer.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_buzzer.c

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
		\file		pgim_buzzer.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Functions to drive a buzzer.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_BUZZER_H_
	#define _PGIM_BUZZER_H_

	#if defined( __18CXX )
		#include <delays.h>
	#endif

    #if ( PGIM_BUZZER == PG_ENABLE )
	
		/*!
		 *  \brief		This function generates a beep length and varying tones by a buzzer.
		 *  \param		[tone]	The tone which is to be generated beep.
		 *  \param		[len]	The duration of which must be generated a beep.
		 *  \return		Nothing.
		 */
		void    pg_buzzer_beep( _pg_Uint8 tone , _pg_Uint16 len );

	#endif
#endif /* _PGIM_BUZZER_H_ */


/*!
	\page	HWE_buzzer		Buzzer

		\tableofcontents
 
		\image	html	buzzer.png

		This small module has the function to simplify to generate small acoustic signals. \n
		\n \n

		\section	buzconf		Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref ieeerruptconfen  \n

					&nbsp; \n \n \n

			\attention	Here a link to the file : \ref pgim_buzzer.h \n
						This is not a file defined as public and therefore would not be edited. \n
						We suggest to edit the file only if absolutely necessary.

			</p>
			\n \n \n

			\subsection	buzconfen		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
				 	#define PGIM_BUZZER					PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Buzzer module enabled.
					\arg \b PG_DISABLE : Buzzer module disabled.
					\endcode

				\subsubsection	ieemodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_BUZZER \n

		 			\htmlonly <br><br> \endhtmlonly


			\subsection	buzzcnbperrorset	Indicator LED setting
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PG_BUZZER_PIN						L_C2
					#define	PG_BUZZER_PIN_TRIS					T_C2
				\endcode
					These defines enable or disable the indicator LED. \n
					They may be: \n
					\arg For \ref PG_BUZZER_PIN		: A LAT bit correctly defined in relation to the MCU used. \n
					e.g. : L_C2
					\arg For \ref PG_BUZZER_PIN_TRIS : The TRIS bits used for \ref PG_ERROR_LED . \n
					e.g. : T_C2

				\subsubsection	errorchensetref		References
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_ERROR_LED_PRESENT \n


		\section	buzcfunct		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n \n

 			\subsection	buzpubfunc	Public functions
				\endcode

				\arg \b pg_buzzer_beep() : This function generates a beep length and varying tones by a buzzer.

				\endcode

			\htmlonly <br><br> \endhtmlonly

	\section	buzzexampleuse	A code example
		\htmlonly <hr> \endhtmlonly
		\endhtmlonly

		Here is a simple example of how to use the module in your code.
		\warning	In order to compile this example, the module must be enabled and properly configured.

		\code
			...
			pg_buzzer_beep( PG_BEEP_LOW , PG_BEEP_SHORT );
			pg_buzzer_beep( PG_BEEP_MID , PG_BEEP_SHORT );
			pg_buzzer_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
			...

		\endcode

		\htmlonly <br><br> \endhtmlonly


 */

