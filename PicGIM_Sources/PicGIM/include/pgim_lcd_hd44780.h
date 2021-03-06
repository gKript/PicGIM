/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_lcd_hd44780.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_lcd_hd44780.c

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
		\file		pgim_lcd_hd44780.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		Configures and manages character lcd display with HD44780 controller1
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_LCD_HD44780_H_
	#define _PGIM_LCD_HD44780_H_

	#if defined( __18CXX )
		#include <delays.h>
	#endif

	#if ( PGIM_LCD_HD44780 == PG_ENABLE )
	
		#define PG_LCD_HD44780_TIMEOUT_MAX			1000					//!< The delay time required, when the BUSY-FLAG is NOT used

		#if ( PG_LCD_HD44780_BUSY_FLAG == PG_ENABLE )
		
			/*!
				\brief			Wait for the display is ready to receive next comand or data.
				\return			Nothing.
				\param			ControllerNumber		The number of the controller.
			*/	
			void pg_lcd_hd44780_wait_busy			( _pg_Uint8 ControllerNumber );
			
		#endif
		
		/*!
			\brief			Checks for the controllers to be initialized.
			\attention		Internal use only !
			\return			Nothing.
			\param			Nothing.
			\deprecated		Do not call directly. \n
							Already called in pg_initialize().
		*/
		void	pg_lcd_hd44780_init					( void );

		/*!
			\brief			Properly initializes all present controllers. 
			\attention		Internal use only !
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\deprecated		Do not call directly. \n
							Already called in pg_initialize().
		*/		
		void	pg_lcd_hd44780_init_routine			( _pg_Uint8 ControllerNumber );

		/*!
			\brief			Turn on all the pixels of the display. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
		*/			
		void	pg_lcd_hd44780_splash_full( _pg_Uint8 ControllerNumber );
		
		/*!
			\brief			Show full cursor moving.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
		*/			
		void	pg_lcd_hd44780_splash_slide( _pg_Uint8 ControllerNumber );

		/*!
			\brief			Delete all character on the display. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
		*/	
		void	pg_lcd_hd44780_clear				( _pg_Uint8 ControllerNumber );
		
		/*!
			\brief			Places the cursor, in a specific position.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
		*/	
		void	pg_lcd_hd44780_goto					( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos );
		
		/*!
			\brief			Print a character, at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Data					The character to print.
		*/	
		void	pg_lcd_hd44780_put_char				( _pg_Uint8 ControllerNumber , _pg_Uint8 Data );
		
		/*!
			\brief			Print a character, in a specific position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Data					The character to print.
		*/	
		void 	pg_lcd_hd44780_put_p_char			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Data );
		
		/*!
			\brief			Print a byte, at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Data					The byte to print.
		*/	
		void	pg_lcd_hd44780_put_byte				( _pg_Uint8 ControllerNumber , _pg_Uint8 Val );
		
		/*!
			\brief			Print a byte, in a specific position.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Data					The byte to print.
		*/	
		void 	pg_lcd_hd44780_put_p_byte			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint8 Val );
		
		/*!
			\brief			Print a character from display CGRAM at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			location				The storage location in the CGRAM.
			\param			new_char				The new char.
		*/	
		void	pg_lcd_hd44780_char_generator		( _pg_Uint8 ControllerNumber , char location , char * new_char );

	#if	( PGIM_EE == PG_ENABLE )
	
		/*!
			\brief			Print a character from micro-controller internal EEPROM at the current position.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			location				The storage location in the EEPROM.
			\param			ee_addy					The char address in the microcontroller eeprom.
		*/	
		void	pg_lcd_hd44780_char_generator_from_EE( _pg_Uint8 ControllerNumber ,char location , _pg_Uint16 ee_addy );
		
	#endif
	
		/*!
			\brief			Write a nibble on the display data bus. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			DataType				The type of the data: a command or a data.
			\param			Dat						The command or the data to send.
		*/	
		void	pg_ldc_hd44780_write_nibble			( _pg_Uint8 ControllerNumber , _pg_Uint8 DataType , _pg_Uint8 Dat );
		
		/*!
			\brief			Write a byte on the display data bus.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			DataType				The type of the data: a command or a data.
			\param			Dat						The command or the data to send.
		*/	
		void	pg_lcd_hd44780_write_byte			( _pg_Uint8 ControllerNumber , _pg_Uint8 DataType , _pg_Uint8 Dat );
		
		/*!
			\brief			Enables selected controller. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			EnState					The state in which, the enable must be set.
								Use \b PG_ENABLE to activate the controller \n
								Use \b PG_DISABLE to deactivate the controller
		*/	
		void	pg_lcd_hd44780_en_select			( _pg_Uint8 ControllerNumber , _pg_Uint8 EnState );
		
		/*!
			\brief			Print with the \a PRINTF \a FORMAT, at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Format					The Format to use.
		*/	
		//void	pg_lcd_hd44780_write				( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Format , ... );
		void	pg_lcd_hd44780_write				( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Format , ... );
		
		/*!
			\brief			Print a string by a pointer, at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Str						The pointer to the string in \a RAM.
		*/	
		void	pg_lcd_hd44780_write_string			( _pg_Uint8 ControllerNumber , _pg_int8 * Str );
		
		/*!
			\brief			Print a constant string by a pointer, at the current position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Str						The pointer to the string in \a ROM.
		*/	
		//void	pg_lcd_hd44780_write_string_rom		( _pg_Uint8 ControllerNumber , const rom _pg_int8 * Str );
        void	pg_lcd_hd44780_write_string_rom		( _pg_Uint8 ControllerNumber , const _pg_int8 * Str );
		
		/*!
			\brief			Print a string by a pointer, in a specific position.
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Str						The pointer to the string in \a RAM.
		*/	
		void	pg_lcd_hd44780_write_p_string		( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8 * Str );


		void	pg_lcd_hd44780_write_p_string_flash	( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_int8  *Str , _pg_Uint8 time , _pg_Uint8 unit );

		/*!
			\brief			Print a constant string by a pointer, in a specific position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Str						The pointer to the string in \a ROM.
		*/	
		//void	pg_lcd_hd44780_write_p_string_rom	( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Str );
		void	pg_lcd_hd44780_write_p_string_rom	( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Str );

		//void	pg_lcd_hd44780_write_p_string_flash_rom	( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Str , _pg_Uint8 time , _pg_Uint8 unit );
		void	pg_lcd_hd44780_write_p_string_flash_rom	( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Str , _pg_Uint8 time , _pg_Uint8 unit );

		/*!
			\brief			Print an integer, specifying the Format, in a specific position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Format					The Format to use.
		*/	
		//void	pg_lcd_hd44780_write_p_int			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Format , _pg_int16 Val );
		void	pg_lcd_hd44780_write_p_int			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Format , _pg_int16 Val );
		
		/*!
			\brief			Print a float, specifying the Format, in a specific position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Format					The Format to use.
		*/	
		void	pg_lcd_hd44780_write_p_float		( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , _pg_Uint24 Decimal_Digits , float Flt );
		
		/*!
			\brief			Print a char, specifying the Format, in a specific position. 
			\return			Nothing.
			\param			ControllerNumber		The number of the controller.
			\param			Ln						It specifies the line.
			\param			Pos						It specifies the column.
			\param			Decimal_Digits			Number of digits of truncation, after the decimal point of the float value.
			\param			Flt						Float value to be printed.
		*/	
		//void	pg_lcd_hd44780_write_p_char			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8 * Format , _pg_int8 chr );
		void	pg_lcd_hd44780_write_p_char			( _pg_Uint8 ControllerNumber , _pg_Uint8 Ln , _pg_Uint8 Pos , const _pg_int8 * Format , _pg_int8 chr );
		
//		void	pg_lcd_hd44780_write_pchar_rom		( _pg_Uint8 Ln , _pg_Uint8 Pos , const rom far _pg_int8  *Format , const rom far _pg_int8 chr );
		
	#endif
#endif /* _PGIM_LCD_HD44780_H_ */

/*!	\page	HWE_lcd_HD44780		LCD Character [Hitachi HD44780]

		\tableofcontents

		\image	html	lcd_char.png

		<p>
			This module manages the <b>Characters LCD Display</b> with <b>HD44780</b> controller.<br>
			It is able to support up to a maximum of four controllers.<br>
			For each controller, four lines are available.<br>
			For example it is possible use two 4x40 (which have 2 controllers each), or four 4x20 (which have only a controller each).<br>
			The management of the data bus, at present, is implemented only in four bit mode.<br>
			The configuration also allows to choose whether to use the <b>Busy-Flag</b>, or a software delay.<br>
		</p>
		\n \n \n 
		
		\section	CLCDconf	Module configuration
			\htmlonly <hr> \endhtmlonly
			In order to use the module, it must enabled and software configured in: \n
			\arg \b pgim_module_setup_public.h : the main management file for the modules that must be included in the project.
				
			and must be assigned to it the related control pins in: \n
			\arg \b pgim_hardware_setup_public.h : where there are all hardware configuration of all modules.
			\n \n \n	
		
		\subsection	CLCDdim		Display dimensions
			\htmlonly <hr> \endhtmlonly
			\code
				#define	PG_LCD_HD44780_COLUMN				16
				#define	PG_LCD_HD44780_LINE					2
			\endcode
			\htmlonly
				These defines set the dimensions of the display in the number of columns and rows.<br>
			\endhtmlonly

				\subsubsection	CLCDdimref	Reference
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_COLUMN \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE \n

		\subsection	CLCDbusy	Busy Time mode
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_BUSY_FLAG			PG_ENABLE
			\endcode
			\htmlonly
				With this define you change the way you manage the <i>busy time</i> of the display.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PG_ENABLE : busy flag enabled.
				\arg \b PG_DISABLE : busy flag disabled.
				\endcode
				
			\htmlonly
				With <b>PG_LCD_HD44780_BUSY_FLAG</b> <i>enabled</i> PicGIM uses the <b>busy flag</b> of the LCD.<br>
				If <i>disabled</i> PicGIM calls a delay; this is an easier method but with a light loss of performance.<br>
			\endhtmlonly

				\subsubsection	CLCDbusyref	Reference
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_COLUMN \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE \n
			
		\subsection	CLCDlina	Line addresses
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_LINE_0_ADDRESS		0x00
				#define PG_LCD_HD44780_LINE_1_ADDRESS		0x40
				#define PG_LCD_HD44780_LINE_2_ADDRESS		0x00
				#define PG_LCD_HD44780_LINE_3_ADDRESS		0x40
			\endcode	
			\htmlonly
				These defines set the addresses of the <i>first</i> character of each line.<br>
				Max four lines are available.<br>
				Missing lines <b>MUST</b> be set to <b>PG_MISSING</b> .
			\endhtmlonly

				\subsubsection	CLCDlinaref	Reference
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE_0_ADDRESS \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE_1_ADDRESS \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE_2_ADDRESS \n
					\li \e Reference : \ref PG_LCD_HD44780_LINE_3_ADDRESS \n

		\subsection	CLCDspl		Splash screen
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_SPLASH_ENABLE		PG_ENABLE
			\endcode	
			\htmlonly
				A print of a splash screen is possible enabling this define.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PG_ENABLE : splash screen enabled.
				\arg \b PG_DISABLE : splash screen disabled.
				\endcode

			\code
				#define PG_LCD_HD44780_SPLASH_TIME			1
			\endcode	
			\htmlonly
				This one is to choose how long view it.<br>
				Time is expressed in seconds [s].<br>
				It is a quick way to verify the correct initialization of the display.<br>
			\endhtmlonly

				\subsubsection	CLCDsplref	Reference
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_SPLASH_ENABLE \n
					\li \e Reference : \ref PG_LCD_HD44780_SPLASH_TIME \n
			
		\subsection	CLCDpinrw	Pin: RW
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_RW_PRESENT			PG_YES
				#define PG_LCD_HD44780_RW					L_B3
			\endcode
			\htmlonly
				This pin controls the reading or writing.<br>
			\endhtmlonly

				\subsubsection	CLCDpinrwref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_RW_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_RW \n
			
		\subsection	CLCDpinrs	Pin: RS
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_RS					L_B4
			\endcode
			\htmlonly
				This pin controls whether the display must receive a command or a data.<br>
			\endhtmlonly

				\subsubsection	CLCDpinrsref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_RS \n

		\subsection	CLCDpinen	Pin: EN
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_EN_0_PRESENT			PG_YES
				#define PG_LCD_HD44780_EN_1_PRESENT			PG_NO
				#define PG_LCD_HD44780_EN_2_PRESENT			PG_NO
				#define PG_LCD_HD44780_EN_3_PRESENT			PG_NO
			\endcode
			\htmlonly
				These defines declares the availability of enables.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PG_YES : lcd enable pin present.
				\arg \b PG_NO  : lcd enable pin not present.
				\endcode
				
			\code
				#define PG_LCD_HD44780_EN_0					L_B2
				#define PG_LCD_HD44780_EN_1					PG_MISSING
				#define PG_LCD_HD44780_EN_2					PG_MISSING
				#define PG_LCD_HD44780_EN_3					PG_MISSING
			\endcode
			\htmlonly
				These defines assign the pin to enable that was declared present.<br>
				If an enable not exist, you must set this field to PG_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpinenref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_0_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_1_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_2_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_3_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_0 \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_1 \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_2 \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_3 \n

		\subsection	CLCDpindat	Pin: DATA<0-3>
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_DATA_0				L_D7
				#define PG_LCD_HD44780_DATA_1				L_D6
				#define PG_LCD_HD44780_DATA_2				L_D5
				#define PG_LCD_HD44780_DATA_3				L_D4
			\endcode			
			\htmlonly
				Here are defined the four pins for data.<br>
				Refer to the datasheet of the display to know what are the pin relative to which to connect in four-bit mode.<br>
			\endhtmlonly
			
				\subsubsection	CLCDpindatref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_0 \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_1 \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_2 \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_3 \n

		\subsection	CLCDpinbl	Pin: BL
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_BL_PRESENT			PG_YES
			\endcode	
			\htmlonly
				This define declares the availability of the BACKLIGHT pin control.<br>
				It must be:<br>
			\endhtmlonly
				\arg \b PG_YES : backlight pin is present.
				\arg \b PG_NO : backlight pin is not present.
				\endcode
			\code
				#define PG_LCD_HD44780_BL					L_D3
			\endcode	
			\htmlonly
				This define assign the pin to control the backlight that was declared present.<br>
				If a backlight pin do not exist, you must set this field to PG_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpinblref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_BL_PRESENT \n
					\li \e Reference : \ref PG_LCD_HD44780_BL \n

		\subsection	CLCDpintr	Tris
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_RW_TRIS				T_B3
				#define PG_LCD_HD44780_RS_TRIS				T_B4
				#define PG_LCD_HD44780_EN_0_TRIS			T_B2
				#define PG_LCD_HD44780_EN_1_TRIS			PG_MISSING
				#define PG_LCD_HD44780_EN_2_TRIS			PG_MISSING
				#define PG_LCD_HD44780_EN_3_TRIS			PG_MISSING
				#define PG_LCD_HD44780_DATA_0_TRIS			T_D7
				#define PG_LCD_HD44780_DATA_1_TRIS			T_D6
				#define PG_LCD_HD44780_DATA_2_TRIS			T_D5
				#define PG_LCD_HD44780_DATA_3_TRIS			T_D4
				#define PG_LCD_HD44780_BL_TRIS				T_D3
			\endcode	
			\htmlonly
				These define concern all tris pins that were configured previously.<br>
				The name matching ensures easy association.<br>
				If a Tris pin is not used, you must set this field to PG_MISSING.<br>
			\endhtmlonly

				\subsubsection	CLCDpintrref	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_RW_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_RS_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_0_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_1_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_2_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_EN_3_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_0_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_1_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_2_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_3_TRIS \n
					\li \e Reference : \ref PG_LCD_HD44780_BL_TRIS \n

		\subsection	CLCDpinpo	Port
			\htmlonly <hr> \endhtmlonly
			\code
				#define PG_LCD_HD44780_DATA_0_PORT			P_D7
				#define PG_LCD_HD44780_DATA_1_PORT			P_D6
				#define PG_LCD_HD44780_DATA_2_PORT			P_D5
				#define PG_LCD_HD44780_DATA_3_PORT			P_D4
			\endcode
			\htmlonly
				When using the BUSY-FLAG, it is necessary to be able to read from the display.<br>
				So, it is important to specify its corresponding port pin previously declared.<br>
				The name matching ensures easy association.<br>
			\endhtmlonly

				\subsubsection	CLCDpinporef	Reference
					\li \e File : pgim_hardware_setup_public.h \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_0_PORT \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_1_PORT \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_2_PORT \n
					\li \e Reference : \ref PG_LCD_HD44780_DATA_3_PORT

			\n \n \n 


 		\section	CLCDfun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\attention	This module can use the \b Error \b Handling \b Module : \ref SWG_error \n
						In the \e TEST section of each function is specified which values ​​are set and in which cases. \n
						Please refer to the specific documentation of the file header: \ref pgim_adc.h

			\htmlonly <br> \endhtmlonly

			\subsection	CLCDfunprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_lcd_hd44780_init() : Properly initializes all present controllers.
				\arg \b pg_lcd_hd44780_init_routine() : Initializes the present controller.
				\arg \b pg_lcd_hd44780_wait_busy() : Wait for the display is ready to receive next comand or data.
				\arg \b pg_lcd_hd44780_goto() : Places the cursor, in a specific position.
				\arg \b pg_lcd_hd44780_en_select() : Enables selected controller.
				\arg \b pg_ldc_hd44780_write_nibble() : Write a nibble on the display data bus.
				\arg \b pg_lcd_hd44780_write_byte() : Write a byte on the display data bus.

				\htmlonly <br><br> \endhtmlonly

			\subsection	CLCDfunpubfunc	Public functions
				\endcode

				\arg \b pg_lcd_hd44780_clear() : Delete all characters from the display.
				\arg \b pg_lcd_hd44780_put_char() : Print a character, at the current position.
				\arg \b pg_lcd_hd44780_put_p_char() : Print a character, in a specific position.
				\arg \b pg_lcd_hd44780_put_byte() : Print a byte, at the current position.
				\arg \b pg_lcd_hd44780_put_p_byte() : Print a byte, in a specific position.
				\arg \b pg_lcd_hd44780_char_generator() : Print a character from display CGRAM at the current position.
				\arg \b pg_lcd_hd44780_char_generator_from_EE() : Print a character from micro-controller internal EEPROM at the current position.
				\arg \b pg_lcd_hd44780_write() : Print with the <i>PRINTF FORMAT</i>, at the current position.
				\arg \b pg_lcd_hd44780_write_string() : Print a string by a pointer, at the current position.
				\arg \b pg_lcd_hd44780_write_string_rom() : Print a constant string by a pointer, at the current position.
				\arg \b pg_lcd_hd44780_write_p_string() : Print a string by a pointer, in a specific position.
				\arg \b pg_lcd_hd44780_write_p_string_rom() : Print a constant string by a pointer, in a specific position.
				\arg \b pg_lcd_hd44780_write_p_int() : Print an integer, specifying the Format, in a specific position.
				\arg \b pg_lcd_hd44780_write_p_float() : Print a float, specifying the Format, in a specific position.
				\arg \b pg_lcd_hd44780_write_p_char() : Print a char, specifying the Format, in a specific position.

			\endcode

			\htmlonly <br><br> \endhtmlonly




 	\attention	Here a link to the file : \ref pgim_lcd_hd44780.h \n
				This is not a file defined as public and therefore would not be edited. \n
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/
	

