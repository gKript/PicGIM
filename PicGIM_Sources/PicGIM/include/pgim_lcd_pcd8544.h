//
// pgim_lcd_pcd8544.h
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

/*!		\file			pgim_lcd_pcd8544.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_LCD_PCD8544_H_
	#define _PGIM_LCD_PCD8544_H_
	
	#if	( PGIM_LCD_PCD8544 == PG_ENABLE )
		
		#define	PG_PCD8544_DATA							1
		#define	PG_PCD8544_COMMAND						0
		
		#define	PG_PCD8544_CONFIGURATION				0x08
		#define	PG_PCD8544_FUNCTION						0x20
		#define	PG_PCD8544_ADDRESS_Y					0x40
		#define	PG_PCD8544_ADDRESS_X					0x80
		#define	PG_PCD8544_EXT_TEMP_CONTROL				0x04
		#define	PG_PCD8544_EXT_BIAS_CONTROL				0x10
		#define	PG_PCD8544_EXT_SET_VOP					0x80

		void 	pg_lcd_pcd8544_reset					( void );
		void	pg_lcd_pcd8544_init						( void );
		void	pg_lcd_pcd8544_send						( _pg_Uint8 dc , _pg_Uint8 chr );
		void	pg_lcd_pcd8544_clear					( _pg_Uint8 wb );			//white = 0; black = 1

		void	pg_lcd_pcd8544_backlight				( _pg_int8 flag );
		void	pg_lcd_pcd8544_set_pos					( _pg_Uint8 x , _pg_Uint8 y );
		
		#if ( PGIM_FONT == PG_ENABLE )
			void	pg_lcd_pcd8544_send_char			( _pg_Uint8 character );
			void    pg_lcd_pcd8544_font_select			( rom const _pg_Uint8 * font );
			void	pg_lcd_pcd8544_send_string_rom		( rom _pg_int8* string );
			void	pg_lcd_pcd8544_send_string			( _pg_int8 * string );
		#endif
		
		#if defined( PG_LCD_PCD8544_VMEM_AMOUNT ) 
			#undef	PG_LCD_PCD8544_VMEM_AMOUNT
		#endif
		
		#define PG_LCD_PCD8544_VMEM_AMOUNT		504
		
		#if ( PG_MAX_RAM > ( 2.5 * PG_LCD_PCD8544_VMEM_AMOUNT ) )
			#if	( PG_LCD_PCD8544_VIDEO_MEMORY == PG_YES )
				_pg_Ubuffer vbuff_pcd8544[ PG_LCD_PCD8544_VMEM_AMOUNT ];
				#if defined( _GIM_H_ )
					#if ( PG_VERBOSE == PG_ENABLE )
						#warning	PG_HS_PG PG_HM_LCD_PCD8544 This amount of allocated RAM ( 504 Bytes ) may cause errors during linking. Use the correct file LKR equipped by PicGIM relating to the selected MCU.
					#endif
				#endif
			#else
				#if defined( _GIM_H_ )
					#if ( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
						#warning	PG_HS_PG PG_HM_LCD_PCD8544 PG_HS_SUGG This MCU can use the VIDEO BUFFER. Keep on mind.
					#endif
				#endif
			#endif
		#else
			#if defined( _GIM_H_ )
				#if ( PG_VERBOSE == PG_ENABLE )
					#warning	PG_HS_PG PG_HM_LCD_PCD8544 Not enough RAM ( PG_MAX_RAM Bytes ) to use VIDEO BUFFER
				#endif
			#endif
		#endif
	#endif
#endif /* _PGIM_LCD_PCD8544_H_ */

/*!	\page 		PGIM_LCD_PCD8544			LCD PCD8544 module


*/


