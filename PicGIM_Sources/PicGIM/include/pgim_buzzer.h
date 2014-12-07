//
// pgim_buzzer.h
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

/*!		\file			pgim_buzzer.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_BUZZER_H_
	#define _PGIM_BUZZER_H_

	#if defined( __18CXX )
		#include <delays.h>
	#endif

    #if ( PGIM_BUZZER == PG_ENABLE )
	
		#define PG_BEEP_LONG        100			/*!	Defines the long duration of the beep		*/
		#define	PG_BEEP_SHORT       40			/*!	Defines the short duration of the beep	*/
//		#define	PG_BEEP_PRESS_L     90
//		#define	PG_BEEP_PRESS_S     30
		#define	PG_BEEP_HIGH		1			/*!	Defines the high tone of the beep		*/
		#define	PG_BEEP_MID         3			/*!	Defines the mean tone of the beep		*/
		#define	PG_BEEP_LOW         7			/*!	Defines the low tone of the beep		*/

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
					\arg \b PG_ENABLE : Interrupts module enabled.
					\arg \b PG_DISABLE : Interrupts module disabled.
					\endcode

				\subsubsection	ieemodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_BUZZER \n

		 			\htmlonly <br><br> \endhtmlonly

		\section	buzcfunct		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n \n

 			\subsection	buzpubfunc	Public functions
				\endcode

				\arg \b pg_buzzer_beep() : This function generates a beep length and varying tones by a buzzer.

				\endcode

			\htmlonly <br><br> \endhtmlonly



 */

