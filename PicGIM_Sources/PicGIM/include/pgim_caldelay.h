/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_caldelay.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_caldelay.c

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
		\file		pgim_caldelay.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Delay functions for PicGIM.
		\details	To easily delays with acceptable error in seconds, milliseconds and microseconds. It is necessary to correctly set the oscillator frequency to obtain the correct functioning of the delays.
		\note		It is necessary to correctly set the oscillator frequency to obtain the correct functioning of the delays in the \ref PG_CLOCK define : \ref hwdelay
					These delay functions are not perfectly accurate. \n Have been written to give to the programmer a delay in the order of time needed with any system clock. \n
					Here is a table of accuracy:
					\htmlonly
					<br><br>
					<table width=50% border=1 >
						<tr align="center">
							<td width=40%><b>pg_delay_Sec</b></td><td>quite accurate</td>
						</tr>
						<tr align="center">
							<td width=40%><b>pg_delay_mSec</b></td><td>quite accurate</td>
						</tr>
						<tr align="center">
							<td width=40%><b>pg_delay_uSec</b></td><td>very inaccurate</td>
						</tr>
					</table>
					\endhtmlonly
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n 
*/

#ifndef _PGIM_CALDELAY_H_
	#define _PGIM_CALDELAY_H_

//	#include <plib/delays.h>

	#if	( PGIM_CAL_DELAY == PG_ENABLE )

		#if defined( __18CXX ) && ( PG_CLOCK > PG_MAX_OSC_FREQ )
			#error	FREQUENCY TOO HIGH FOR THIS MCU.
		#endif

		#if defined( __18CXX )
//		#if defined( __XC8 )
			/*!
				A litle offset to fine adjust the delay
			*/
			#define PG_NINSTUS_OFFSET	0.500           //kmod
//			#define PG_NINSTUS_OFFSET	5

			/*!
				A macro to obtain 10 usec
			 */
			#define PG_DELAY_TENUS	Delay10TCYx(  pg_ninstus )

			extern _pg_Uint8	pg_ninstus;		//!< The number of instruction in a usec

			/*!
				\brief			To calculate the number of instruction in a usec.
			 	\attention		Internal use only !
			 	\deprecated		Do not call directly. \n
								Already called in pg_initialize().
			*/
			void	pg_delay_NinstusCalc	( void );

			#if ( PG_DELAY_SEC == PG_INCLUDE )
				/*!
					\brief		To do a delay in seconds.
					\param		sec	The seconds of delay you want to do, \n
									\a sec > 0
									\a sec <= 255
				*/
				void	pg_delay_sec			( _pg_Uint8 sec );
			#endif
			
			#if ( PG_DELAY_MSEC == PG_INCLUDE )
				/*!	
					\brief		To do a delay in milliseconds.
					\param		msec	The milliseconds of delay you want to do, \n
									\a msec > 0
									\a msec <= 255
				*/
				void	pg_delay_msec		( _pg_Uint16 msec );
			#endif
			
			#if ( PG_DELAY_USEC == PG_INCLUDE )
				/*!
					\brief		To do a delay in microseconds.
					\param		usec	The microseconds of delay you want to do, \n
									\a usec > 0 \n
									\a usec <= 65534 \n
					\note		This function provides a delay very inaccurate. \n
									If you need an accuracy delay based on the system clock please write it.
				*/
				void	pg_delay_usec			( _pg_Uint16 usec );
			#endif
			
			#if ( PG_DELAY == PG_INCLUDE )
				/*!
					\brief		To do a delay in various units of time.
					\param		req_delay	The delay you want to do, \n
									\a req_delay > 0 \n
									\a req_delay <= 255
					\param		unit		The unit of time request. \n
									\a unit = \a PG_SEC  ||  \a unit = \a PG_MSEC  ||  \a unit = \a PG_USEC

					\note		When you use this function with \a PG_USEC it provides a delay very inaccurate. \n
									If you need an accuracy in uSec delay based on the system clock please write it yourself in asm.
				*/
				void	pg_delay	( _pg_Uint16 req_delay , _pg_Uint8 unit );
			#endif
			
			#if ( ( PGIM_EVENTS == PG_ENABLE ) && ( PG_DELAY_HIGH_PRIORITY == PG_INCLUDE ) )
				/*!
					\brief		To do a delay in various units of time. This function is uninterruptable.
					\param		req_delay	The delay you want to do, \n
									\a req_delay > 0 \n
									\a req_delay <= 255
					\param		unit		The unit of time request. \n
									\a unit = \a PG_SEC  ||  \a unit = \a PG_MSEC  ||  \a unit = \a PG_USEC
					
					\attention	\b "high priority" means that during the delay \b interrupts \b are \b not \b enabled.

					\note		This function will compiled only if the Interrupts module is enabled.
					
					\note		When you use this function with \a PG_USEC it provides a delay very inaccurate. \n
									If you need an accuracy in uSec delay based on the system clock please write it yourself in asm. \n
				*/
				void pg_delay_high_priority( _pg_Uint16 req_delay , _pg_Uint8 unit );
			#endif
		#endif
	#endif
#endif /* _PGIM_CALDELAY_H_ */

/*!
	\page	SWG_delay		Delay 
	
		\tableofcontents
		
		\image html	clessidra.gif
		
		The \b DELAY module provides a set of functions for delay in different units of time ( seconds, milliseconds, microseconds) but not accuracy. \n
		You only need one parameter for the use of this module : The system frequency   \n \n

		\endcode
		
		\n \n

		\section	delayconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref delayconfen  \n
					\n \n \n

				\arg \b pgim_project_setup_public.h : This is the main file to edit the parameters of this module. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref delaysfreq

					\n  &nbsp;&nbsp;&nbsp;&nbsp;
				
			\attention	Here a link to the file : \ref pgim_caldelay.h \n
				This is not a file defined as public and therefore would not be edited. \n
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
			</p>
			\n \n \n

			\subsection	delayconfen	Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_CAL_DELAY                      PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Delay module enabled.
					\arg \b PG_DISABLE : Delay module disabled.
			
				\subsubsection	delaymodenref	References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_CAL_DELAY \n
					
			
			\subsection		delaysfreq		System frequency
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_CLOCK   48.000
				\endcode

				The \b CORE \b FREQUENCY of the \b MCU in your project. \n Unit of measure is expressed in \e [MHz]. Accuracy: \e X.XXX. \n
				They must be: \n
					\arg \b PG_CLOCK >= 4.000 : 4 MHz is the minimum clock frequency managed by \b PicGIM.
					
				By default is set to \b 0.000 \n 

				\subsubsection	delaymodautoref	References
					\li \e File : pgim_project_setup_public.h  
					\li \e Reference : \ref PG_CLOCK 
					
				\note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, you need to consider the value of the \b oscillator/crystal and eventually of the \b PLL.
				
				\attention		4MHz is the minimum clock frequency managed by \b PicGIM. \n If you set a lower frequency 4MHz functions of delay will definitely inaccurate.
				
				\htmlonly <br><br> \endhtmlonly

		\section	delaycsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\htmlonly <br><br> \endhtmlonly

			\subsection	delayprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_delay_NinstusCalc() : To calculate the number of instruction in a usec.
					
				\note The working frequency is the \b CORE \b FREQUENCY of the \b MCU in your project. To set it correctly, you need to consider the value of the \b oscillator/crystal and eventually of the \b PLL.
				
				\attention		4MHz is the minimum clock frequency managed by \b PicGIM. \n If you set a lower frequency 4MHz functions of delay will definitely inaccurate.
				
				\htmlonly <br><br> \endhtmlonly
				
			\subsection	delaypubfunc	Public functions
				\endcode
				
				\arg \b pg_delay_sec() : To do a delay in seconds.
				\arg \b pg_delay_msec() : To do a delay in milliseconds.
				\arg \b pg_delay_usec() : To do a delay in microseconds.
				\arg \b pg_delay_high_priority() : To do a delay in various units of time. This function is uninterruptable. \attention	\b "high priority" means that during the delay \b interrupts \b are \b not \b enabled. \note		This function will compiled only if the Interrupts module is enabled. 
				\arg \b pg_delay() : To do a delay in various units of time.
				
				\endcode
				
			\htmlonly <br><br> \endhtmlonly
			
*/


