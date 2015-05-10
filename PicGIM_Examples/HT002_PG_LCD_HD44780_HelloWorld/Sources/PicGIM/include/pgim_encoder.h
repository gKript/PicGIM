/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_encoder.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_encoder.c

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
		\file		pgim_encoder.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To drive a Gk encoder.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_ENCODER_H_
	#define _PGIM_ENCODER_H_
	
	#if defined( __18CXX )
		#include <delays.h>
	#endif

	#if ( PGIM_ENCODER == PG_ENABLE )

//		#define PG_ENCODER_GKPD

		#define	DELAY_AR					1													//!<	Thisi is the delay for the debounce
//		#define	DELAY_OUT					40
//		#define	ITERATION					7000

		#define	PG_ENCODER_UNK				-1													//!<	This is the state of the encoder without having been moved.
		#define	PG_ENCODER_CW				0													//!<	This is the state of the encoder after a clockwise rotation.
		#define	PG_ENCODER_CCW				1													//!<	This is the state of the encoder after a counterclockwise rotation.
		#define	PG_ENCODER_PRESSED			2													//!<	This is the state of the encoder after a button pressed.
		#define	PG_ENCODER_EVENT_OCCURRED	3

		#define	PG_ENCODER_SW_STATE			( ! PG_ENCODER_SW )									//!<	This macro feels the pressing of encoder button.
		#define	PG_ENCODER_ANY				( ENCODER_STEP  || ENCODER_DIR || ENCODER_SW )		//!<	This macro feels the event of each encoder signal.

//		#define	PG_ENCODER_DELAY_1		1
//		#define	PG_ENCODER_DELAY_2		3
//		#define	PG_ENCODER_DELAY_3		5
//		#define	PG_ENCODER_DELAY_4		7


		extern	_pg_int8					pg_encoder_button;									//!<	This variable will contain the status of the encoder button.
		extern	_pg_int8					pg_encoder_direction;								//!<	This variable will contain the status of the encoder direction.


		/*!
		 *	\brief			This is the initialization function of the Encoder module.
		 *	\warning		Internal use only.
		 *	\deprecated		Do not call directly. Already called in pg_initialize()
		 */
		void		pg_encoder_init							( void );


		/*!
		 *	\brief		This function waits for the event of the pulse encoder and waits until the end. \n
						This function is blocking.
			\return		Nothing.
		 	\param		Nothing.
		*/
		void		pg_encoder_start_end_pulse_block		( void );


		/*!
		 *	\brief		This function waits for the event of the pulse encoder and waits until the end. \n
						The function is NOT blocking.
			\return		\b PG_EVENT_OCCURRED if a pulse was detected, \b PG_NONE if no pulse.
		 	\param		Nothing.
		*/
		_pg_Uint8	pg_encoder_start_end_pulse_non_block	( void );


		/*!
		 *	\brief		This function waits for any event from the encoder and then return the event type. \n
						The function is blocking.
			\return		\b PG_ENCODER_PRESSED if the button was pressed, \b PG_ENCODER_CW if the event was a rotation in CW, \b PG_ENCODER_CCW if the event was a rotation in CCW.
		 	\param		Nothing.
		*/
		_pg_int8	pg_encoder_pulse						( void );


		/*!
		 *	\brief		It is possible to know at any time the last direction of the encoder rotation.
			\return		\b PG_ENCODER_CW if the event was a rotation in CW, \b PG_ENCODER_CCW if the event was a rotation in CCW or \b PG_ENCODER_UNK if the encoder is never been rotated.
		 	\param		Nothing.
		*/
		_pg_int8	pg_encoder_get_direction				( void );

	#endif	
#endif /* _PGIM_ENCODER_H_ */

/*!
	\page	HWG_encoder		Encoder
		\tableofcontents

		\image html encoder.png

		This module is needed to easily handle a quadrature encoder in gKript hardware configuration. \n
		The hardware schema of the gkript configuration is the following :
 
		\image html	encoder_schema.png

		The quadrature encoder normally has as output the \b Phase \b A and \b Phase \b B. \n
		This hardware configuration has \b Direction and \b Pulse as outputs.
		
		\note	This module can be used by associating it to an external interrupt : \ref PG_EVENT_SET_INT0 or \ref PG_EVENT_SET_INT1 or \ref PG_EVENT_SET_INT2 or \ref PG_EVENT_SET_RB0 \n It is possible to find out how to use it in this section : \ref encinterrupthowto \n

		\n \n

 		\section	encconf		Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref encerruptconfen

					&nbsp;\n \n

			\arg \b pgim_hardware_setup_public.h : where are collected configuration details for the encoder pins. \n
					In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref enccnbperrorset \n
					\n \n \n &nbsp;&nbsp;&nbsp;&nbsp;

			\attention	Here a link to the file : \ref pgim_encoder.h \n
						This is \b NOT a file defined as public and therefore would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing. \n

 			</p>
			\n \n \n



			\subsection	encerruptconfen		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_ENCODER					PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Encoder module enabled.
					\arg \b PG_DISABLE : Encoder module disabled.
					\endcode

					\subsubsection	encmodenref		References
						\li \e File : pgim_module_setup_public.h \n
						\li \e Reference : \ref PGIM_ENCODER \n

 
 			\subsection	enccnbperrorset	Encoder hardware setting
				\htmlonly <hr> \endhtmlonly
				\code
					#define	PG_ENCODER_STEP						P_B0
					#define	PG_ENCODER_DIR						P_B5
					#define	PG_ENCODER_SW						P_B6

					#define	PG_ENCODER_STEP_TRIS				T_B0
					#define	PG_ENCODER_DIR_TRIS					T_B5
					#define	PG_ENCODER_SW_TRIS					T_B6
				\endcode
					These defines enable or disable the indicator LED. \n
					They may be: \n
					\arg For \ref PG_ENCODER_STEP			: A PORT bit correctly defined in relation to the MCU used. \n
					e.g. : P_B0
					\arg For \ref PG_ENCODER_DIR			: A PORT bit correctly defined in relation to the MCU used. \n
					e.g. : P_D1
					\arg For \ref PG_ENCODER_SW				: A PORT bit correctly defined in relation to the MCU used. \n
					e.g. : P_B1
					\arg For \ref PG_ENCODER_STEP_TRIS		: The TRIS bits used for \ref PG_ENCODER_STEP . \n
					e.g. : T_B0
					\arg For \ref PG_ENCODER_DIR_TRIS		: The TRIS bits used for \ref PG_ENCODER_DIR . \n
					e.g. : T_D1
					\arg For \ref PG_ENCODER_SW_TRIS		: The TRIS bits used for \ref PG_ENCODER_SW . \n
					e.g. : T_B1

				\subsubsection	encorchensetref		References
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_ENCODER_STEP \n
					\li \e Reference : \ref PG_ENCODER_DIR \n
					\li \e Reference : \ref PG_ENCODER_SW \n
					\li \e Reference : \ref PG_ENCODER_STEP_TRIS \n
					\li \e Reference : \ref PG_ENCODER_DIR_TRIS \n
					\li \e Reference : \ref PG_ENCODER_SW_TRIS \n


		\section	enccsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\htmlonly <br> \endhtmlonly

			\subsection	encprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_encoder_init() : This is the initialization function of Encoder module.

				\htmlonly <br><br> \endhtmlonly

			\subsection	encpubfunc	Public functions
				\endcode

				\arg \b pg_encoder_start_end_pulse_block() : This function waits for the event of the pulse encoder and waits until the end. \n This function is blocking.
				\arg \b pg_encoder_start_end_pulse_non_block() : This function waits for the event of the pulse encoder and waits until the end. \n The function is NOT blocking.
				\arg \b pg_encoder_pulse() : This function waits for any event from the encoder and then return the event type. \n The function is blocking.
				\arg \b pg_encoder_get_direction() : It is possible to know at any time the last direction of the encoder rotation.

				\endcode

			\htmlonly <br><br> \endhtmlonly

	\section	encexampleuse	A code example
		\htmlonly <hr> \endhtmlonly
		\endhtmlonly

		Here is a simple example of how to use the module in your code.
		\warning	In order to compile this example, the module must be enabled and properly configured.

		\code
			...
			switch( pg_encoder_pulse() ) {
				case PG_ENCODER_CW : {
					pg_pin_toggle( L_D2 );
				}
				case PG_ENCODER_CCW : {
					pg_pin_toggle( L_D3 );
				}
				case PG_ENCODER_PRESSED : {
					pg_pin_toggle( L_D4 );
				}
			}
			...

		\endcode

		\htmlonly <br><br> \endhtmlonly

	\section	encinterrupthowto	Using this module with interrupts
		\htmlonly
		<p>
		\endhtmlonly

		If the interrupt handling is enable is possible, through the external interrupt signals \ref PG_EVENT_SET_INT0 or \ref PG_EVENT_SET_INT1 or \ref PG_EVENT_SET_INT2 or \ref PG_EVENT_SET_RB0 , have an interrupt at every pulse or each button pressed. \n
		If using the \b Automatic \b Interrupts \b Handler pg_event_auto_handler() will call the user attached callback. \n
		So once entered the code inside the callback it will be executed at every related event. \n \n

		\b References : \n
			Interrups configuration :\ref iterruptconf \n
			External interrupts configuration : \ref interdefinesextern \n
			Callback configuration : \ref interruptcallbackhowto \n

  		\htmlonly
		</p>
		\endhtmlonly

		\htmlonly <br><br> \endhtmlonly

*/

