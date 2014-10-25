//
// pgim_ee.h
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

/*!		\file			pgim_ee.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			The module to easily handle the internal EEprom
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_EE_H_
	#define _PGIM_EE_H_

	#if ( PGIM_EE == PG_ENABLE )

		/*!
		 *  \brief 			This function initializes properly the registers for read / write from the internal EEPROM.
			\return			Nothing.
		 *	\attention		Internal use only !
		 *	\deprecated	Do not call directly. Already called in pg_initialize().
		 */
		void	pg_ee_init( void );
		
		/*!
		 * \brief	This Function write a byte to the internal EEPROM of the MCU
		 * \param	[in] ee_data The byte to write in EEPROM
		 * \param	[in] ee_addy The EEPROM address where to write the byte
			\return	This function performs the \b writing \b verification. If the test is successful returns \b PG_OK otherwise it returns \b PG_NOK.
		 */
		 _pg_Uint8 pg_ee_write( _pg_Uint8 ee_data , _pg_Uint16 ee_addy );

		/*!
		 *  \brief 		This Function read a byte from the internal EEPROM of the MCU
		 *  \param 	[in] ee_addy The EEPROM address where to read the byte
		 *  \return 	The read byte.
		 */
		char pg_ee_read( _pg_Uint16 ee_addy );

		/*!
		 *  \brief 		This Function write a buffer to the internal EEPROM of the MCU
		 *  \param 	[in] ee_addy The address at which the buffer will be written
		 *  \param 	[in] buffer The buffer to write
		 *  \param 	[in] buflen The buffer lenght
			\return		Nothing.
		 */ 
		void	pg_ee_write_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen );

		/*!
		 *  \brief 		This Function read a buffer from the internal EEPROM of the MCU
		 *  \param	[in] ee_addy The address at which the buffer will be read
		 *  \param 	[out] buffer The buffer to read
		 *  \param 	[in] buflen The buffer lenght
			\return		Nothing.
		 */
		void	pg_ee_read_buffer( _pg_Uint16 ee_addy , char * buffer , _pg_Uint16 buflen );

	#endif
	
#endif

/*!
	\page	HWI_ee		Internal EEPROM

		\tableofcontents

		This module makes use of the \b PIC \b internal \b eeprom really simple. \n
		Sometimes it can be useful to be able to save the state of some bits or special configurations then resume on the next boot.

		\n \n

		\section	ieeconf		Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref ieeerruptconfen  \n
					
					&nbsp; \n \n \n

				\attention	Here a link to the file : \ref pgim_ee.h \n
								This is not a file defined as public and therefore would not be edited. \n 
								We suggest to edit the file only if absolutely necessary. \n
			</p>
			\n \n \n

			\subsection	ieeerruptconfen		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_EE							PG_DISABLE
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
					\li \e Reference : \ref PGIM_EE \n
				
		\section	ieecsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\htmlonly <br><br> \endhtmlonly

			\subsection	ieeprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_ee_init() : This is the initialization function of AD handler module.

				\htmlonly <br><br> \endhtmlonly
				
			\subsection	ieepubfunc	Public functions
				\endcode
				
				\arg \b pg_ee_write() : This is the function to set the main parameters of the module. 
				\arg \b pg_ee_read() : When this function is called the acquisition is carried out. 
				\arg \b pg_ee_write_buffer() : This function returns the value of the last acquisition made.
				\arg \b pg_ee_read_buffer() : This function acquires with [n] averages.
				
				\endcode
				
			\htmlonly <br><br> \endhtmlonly
			


	\section	ieeexampleuse	A code example
		\endhtmlonly
		
		Here is a simple example of how to use the module in your code. 
		\warning	In order to compile this example, the module must be enabled and properly configured.
		
		\code
			...
			
			outcome = pg_ee_write( status , 0x0004 );
			if ( outcome == PG_OK ) {
				pg_ee_read_buffer( 0x0100 , buffer , 25 );
			}
			
			...
		\endcode

		\htmlonly <br><br> \endhtmlonly

*/


