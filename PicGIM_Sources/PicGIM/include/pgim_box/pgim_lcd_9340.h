//
// pgim_lcd_9340.h
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

/*!		\file			pgim_lcd_9340.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_LCD_9340_H_
	#define _PGIM_LCD_9340_H_
	
	#if ( PGIM_LCD_9340 == PG_ENABLE )
	
		#define	PG_LCD_9340_DATA				1
		#define	PG_LCD_9340_COMMAND				0
		
		#define PG_LCD_9340_WHITE				0xFFFF
		#define PG_LCD_9340_BLACK				0x0000
		#define PG_LCD_9340_BLUE				0x001F
		#define PG_LCD_9340_BLUE2				0x051F
		#define PG_LCD_9340_RED					0xF800
		#define PG_LCD_9340_MAGENTA				0xF81F
		#define PG_LCD_9340_GREEN				0x07E0
		#define PG_LCD_9340_CYAN				0x7FFF
		#define PG_LCD_9340_YELLOW				0xFFE0
/*
		#define	PG_PCD8544_CONFIGURATION		0x08
		#define	PG_PCD8544_FUNCTION				0x20
		#define	PG_PCD8544_ADDRESS_Y			0x40
		#define	PG_PCD8544_ADDRESS_X			0x80
		#define	PG_PCD8544_EXT_TEMP_CONTROL		0x04
		#define	PG_PCD8544_EXT_BIAS_CONTROL		0x10
		#define	PG_PCD8544_EXT_SET_VOP			0x80
*/
		void	pg_lcd_9340_init					( void );
		void	pg_lcd_9340_WR_command_8			( unsigned char cmd );
		void	pg_lcd_9340_WR_command_16			( unsigned char cmd_1, unsigned char cmd_0 );
		void	pg_lcd_9340_WR_command_16INT		( unsigned int icmd );
		void	pg_lcd_9340_WR_data_8				( unsigned char data );
		void	pg_lcd_9340_WR_data_16				( unsigned char data1, unsigned char data0 );
		void	pg_lcd_9340_WR_data_16INT			( unsigned int idato );
		void	pg_lcd_9340_reset					( void );
		void	pg_lcd_9340_sleep					( void );
		void	pg_lcd_9340_exit_sleep				( void );
		void	pg_lcd_9340_disp_single_color		( unsigned char DH, unsigned char DL );
		void	pg_lcd_9340_test_single_color		( int color );
		void	pg_lcd_9340_test_single_gradient	( int color );
		void	pg_lcd_9340_address_set				( unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2 );
		void	pg_lcd_9340_set_pos					( unsigned int x, unsigned int y );                                                                             //VERIFICARE!
		void	pg_lcd_9340_set_pos_2				( unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1 ); //VERIFICARE!   static
		void	pg_lcd_9340_ram_adress_set			( void );
		void	pg_lcd_9340_test_picture			( unsigned char *map );
		void	pg_lcd_9340_show_image				( const unsigned char *image );
		void	pg_lcd_9340_put_char				( unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor );
		void	pg_lcd_9340_put_string				( unsigned short x, unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor );

		
		#if defined( PG_LCD_9340_VMEM_AMOUNT ) 
			#undef	PG_LCD_9340_VMEM_AMOUNT
		#endif

		//#if defined( PG_LCD_9340_COLOR_24BIT_VMEM_AMOUNT ) 
		//	#undef	PG_LCD_9340_COLOR_24BIT_VMEM_AMOUNT
		//#endif
		
		#define PG_LCD_9340_VMEM_AMOUNT						9600	//  9600[Byte] or 76800[Bit];   1 bit/pixel
		//#define PG_LCD_9340_COLOR_24BIT_VMEM_AMOUNT		230400	//230400[Byte] or 1843200[Bit]; 24 bit/pixel
		
		#if ( PG_MAX_RAM > ( 1.25 * PG_LCD_9340_VMEM_AMOUNT ) )
			#if	( PG_LCD_9340_VIDEO_MEMORY == PG_ENABLE )
				_pg_Ubuffer vbuff_9340[ PG_LCD_9340_VMEM_AMOUNT ];
				#if defined( _GIM_H_ )
					#if ( PG_VERBOSE == PG_ENABLE )
						#warning	PG_HS_PG PG_HM_LCD_9340 This amount of allocated RAM ( 9600 Bytes ) may cause errors during linking. Use the correct file LKR equipped by PicGIM relating to the selected MCU.
					#endif
				#endif
			#else
				#if defined( _GIM_H_ )
					#if ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
						#warning	PG_HS_PG PG_HM_LCD_9340 PG_HS_SUGG This MCU can use the VIDEO BUFFER. Keep on mind.
					#endif
				#endif
			#endif
		#else
			#if defined( _GIM_H_ )
				#if ( PG_VERBOSE == PG_ENABLE )
					#warning	PG_HS_PG PG_HM_LCD_9340 Not enough RAM ( PG_MAX_RAM Bytes ) to use VIDEO BUFFER
				#endif
			#endif
		#endif
	#endif
#endif /* _PGIM_LCD_9340_H_ */


/*!	\page 		PGIM_LCD_9340			LCD 9340 module


*/


