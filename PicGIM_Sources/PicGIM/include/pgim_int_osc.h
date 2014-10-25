//
// pgim_int_osc.h
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

/*!		\file			pgim_int_osc.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is NOT a file defined as PUBLIC and therefore it would not be edited. \n
						It is advisable to edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_INT_OSC_H_
	#define _PGIM_INT_OSC_H_

	#if	( PG_USE_INTERNAL_OSC == PG_ENABLE )

		/*!
			\brief			This function initializes properly the registers for the internal oscillator.
			\warning		Internal use only !
			\deprecated		Do not call directly. Already called in pg_initialize().
		 */
		void pg_internal_osc_init( void );					//!< Return PG_INTERNAL_OSC_CONFIGURED defined on success.
		
	#endif
#endif

/*!
	\page	HWI_intosc		Internal oscillator

		\tableofcontents
	
		All the <b> PIC18F </b> MCU family have an internal oscillator which can be useful in many applications, for example where it is necessary to install just a few hardware components, or to quickly test the device. \n
		To enable the internal oscillator, please set to \ref PG_ENABLE the define \ref PG_USE_INTERNAL_OSC in the file: \ref pgim_project_setup_public.h . \n
		If possible, the frequency of the internal oscillator, will be set to the maximum value. \n

		\n \n

		\section	intoscconf	Module configuration
			\htmlonly <hr> \endhtmlonly
			\endcode
			
			<p>
			In order to use this module just enough to enable it. \n
				
			\attention	Here is a link to the file: \ref pgim_int_osc.h . \n
					This is NOT a file defined as PUBLIC and therefore it would not be edited. \n
					It is advisable to edit this file only if necessary and only if you know what you are doing. \n
			</p>
			\n \n \n

			\subsection	intoscconfen	Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_USE_INTERNAL_OSC					PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Iternal oscillator enabled.
					\arg \b PG_DISABLE : Iternal oscillator disabled.
					
				\note	When this module is enabled, the value of \ref PG_CLOCK is ignored.
			
				\subsubsection	intoscmodenref	References
					\li \e File : pgim_project_setup_public.h \n
					\li \e Reference : \ref PG_USE_INTERNAL_OSC \n
					
			
		
		
		
 */


 