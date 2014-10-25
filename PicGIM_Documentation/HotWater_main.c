//
// main.c
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

/*!		\file			main.c
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#include "picgim_main.h"
#include "hotwater.h"

//---[ Variables ]---
_pg_Uint8	Statem;					//state-machine
_pg_Uint8	SubStatem;				//sub-state-machine
_pg_Uint8	SubMenu;				//sub--menu
_pg_Uint8	SubStateMenu;			//sub-state-menu

_pg_int16	Temp_Panel;				//con segno!
_pg_int16	Temp_Tank;				//con segno!
_pg_int16	Temp_Amb;				//con segno!
_pg_int16	Delta_Panel_Tank;
_pg_int8	Volt_Vdd;
									//------------------------------Dec------Hex----Address
_pg_int16	Delta_Start_Pump_1;		//con segno!	Default value:	10d		0x000A	0x0000
_pg_int16	Delta_Stop_Pump_1;		//con segno!	Default value:	 5d		0x0005	0x0002
_pg_int16	Temp_Freeze_1_Start;	//con segno!
_pg_int16	Temp_Freeze_1_Stop;		//con segno!
_pg_int16	Temp_Valve_2_Start;		//con segno!	Default value:	85d		0x0055	0x0004
_pg_int16	Temp_Valve_2_Stop;		//con segno!	Default value:	75d		0x004B	0x0006
_pg_int16	Temp_Siren_3_Start;		//con segno!	Default value:	90d		0x005A	0x0008
_pg_int16	Temp_Siren_3_Stop;		//con segno!	Default value:	80d		0x0050	0x000A

_pg_int16	Temp_Offset_1;			//con segno!	Default value:	 0d		0x0000	0x000C
_pg_int16	Temp_Offset_2;			//con segno!	Default value:	 0d		0x0000	0x000E
_pg_int16	Temp_Offset_3;			//con segno!	Default value:	 0d		0x0000	0x0010

_pg_int16	Ntc_Beta_1;				//no  segno!	Default value:	3988d	0x0F94	0x0012
_pg_int16	Ntc_Beta_2;				//no  segno!	Default value:	3988d	0x0F94	0x0014
_pg_int16	Ntc_Beta_3;				//no  segno!	Default value:	3988d	0x0F94	0x0016

_pg_Uint16	Index_Button;
_pg_int16	State_Button;

_pg_int8	Temp_String[ 5 ];
_pg_int8	EPos;					//con segno!
_pg_Uint8	Editing;
_pg_Uint8	Healt_Pass;
_pg_Uint8	Lock_Manual_Mode;
_pg_Uint8	Reset_Confirmed;
_pg_Uint8	Temp_BL;

_pg_Uint8	Slow_Green_Led;
_pg_int16	Temp_Error_Val_1;
_pg_int16	Temp_Error_Val_2;

_pg_int8 res = 0;					//Debug

//---[ Menu Edit Positions ]---		//Aggiornare Edit Cursor Position Defines (item - 1) 
_pg_Uint8	Edit_Delta_Line[]	=	{L3, L1, L1, L1, L2, L2, L2, L0, L1};	//item 9
_pg_Uint8	Edit_Delta_Pos[]	=	{15,  3,  4,  5,  3,  4,  5, 15, 15};
_pg_Uint8	Edit_Freeze_Line[]	=	{L3, L1, L1, L2, L2, L0, L1};	//item 7
_pg_Uint8	Edit_Freeze_Pos[]	=	{15,  4,  5,  4,  5, 15, 15};
_pg_Uint8	Edit_Valve_2_Line[]	=	{L3, L1, L1, L1, L2, L2, L2, L0, L1};	//item 9
_pg_Uint8	Edit_Valve_2_Pos[]	=	{15,  4,  5,  6,  4,  5,  6, 15, 15};
_pg_Uint8	Edit_Siren_3_Line[]	=	{L3, L1, L1, L1, L2, L2, L2, L0, L1};	//item 9
_pg_Uint8	Edit_Siren_3_Pos[]	=	{15,  4,  5,  6,  4,  5,  6, 15, 15};
_pg_Uint8	Edit_Manual_Line[]	=	{L3, L0, L1, L2, L3, L0};	//item 6
_pg_Uint8	Edit_Manual_Pos[]	=	{15, 11,  4,  4,  4, 15};
_pg_Uint8	Edit_Offset_Line[]	=	{L3, L1, L1, L2, L2, L3, L3, L0, L1};	//item 9
_pg_Uint8	Edit_Offset_Pos[]	=	{15,  4,  5,  4,  5,  4,  5, 15, 15};
_pg_Uint8	Edit_Beta_Line[]	=	{L3, L1, L1, L1, L1, L1, L2, L2, L2, L2, L2, L3, L3, L3, L3, L3, L0, L1, L2};	//item 19
_pg_Uint8	Edit_Beta_Pos[]		=	{15,  8,  9, 10, 11, 12,  8,  9, 10, 11, 12,  8,  9, 10, 11, 12, 15, 15, 15};
_pg_Uint8	Edit_Reset_Line[]	=	{L3, L2, L0, L2};	//item 4
_pg_Uint8	Edit_Reset_Pos[]	=	{15,  2, 15, 15};

//---[ CGRAM Char Data ]---
char	Pattern_Celsius[ 8 ]	= 	{0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00};	//Celsius grade
char	Pattern_Arrow_Dx[ 8 ]	= 	{0x08, 0x0c, 0x1e, 0x1f, 0x1e, 0x0c, 0x08, 0x00};	//->
char	Pattern_Bell[ 8 ]		= 	{0x04, 0x0e, 0x0e, 0x0e, 0x1f, 0x00, 0x04, 0x00};	//campana
//char	Pattern_Exchange[ 8 ]	= 	{0x07, 0x03, 0x05, 0x08, 0x02, 0x14, 0x18, 0x1c};	//scambio
char	Pattern_Pump[ 8 ]		= 	{0x0e, 0x06, 0x0a, 0x10, 0x10, 0x11, 0x0e, 0x00};	//pompa
char	Pattern_Exit[ 8 ]		= 	{0x1e, 0x11, 0x11, 0x11, 0x19, 0x11, 0x11,  0xf};	//porta
char	Pattern_Ball[ 8 ]		= 	{0x00,  0xe, 0x1f, 0x1f, 0x1f, 0x1f,  0xe, 0x00};	//pallino
char	Pattern_Full[ 8 ]		= 	{0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};	//pieno
 
//---[ Main ]---
void main( void ) {
	
	//---[ PicGIM Initialize ]---
	pg_initialize( );

	//---[ Default Tris ]---
	LED_PWR_EDIT_TRIS		= PG_OUT;
	LED_PUMP_1_TRIS			= PG_OUT;
	LED_VALVE_2_TRIS		= PG_OUT;
	
	OUT_OC_PUMP_1_TRIS		= PG_OUT;
	OUT_OC_VALVE_2_TRIS		= PG_OUT;
	OUT_OC_SIREN_3_TRIS		= PG_OUT;
	
	IN_NTC_PANEL_TRIS		= PG_IN;
	IN_NTC_TANK_TRIS		= PG_IN;
	IN_NTC_AMBIENT_TRIS		= PG_IN;
	IN_NTC_VOLT_VDD_TRIS	= PG_IN;
	
	//---[ Default Pin State ]---
	LED_PWR_EDIT		= !PG_OFF;				//Negative logic (!PG_ON = ON)
	LED_PUMP_1			= !PG_OFF;				//Negative logic (!PG_ON = ON)
	LED_VALVE_2			= !PG_OFF;				//Negative logic (!PG_ON = ON)
	
	OUT_OC_PUMP_1		= PG_OFF;
	OUT_OC_VALVE_2		= PG_OFF;
	OUT_OC_SIREN_3		= PG_OFF;
	
	//---[ Initialize ]---
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 0 , Pattern_Celsius );		//char to print = 0x00
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 1 , Pattern_Arrow_Dx );	//char to print = 0x01
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 2 , Pattern_Bell );		//char to print = 0x02
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 3 , Pattern_Pump );		//char to print = 0x03
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 4 , Pattern_Exit );		//char to print = 0x04
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 5 , Pattern_Ball );		//char to print = 0x05
	pg_lcd_hd44780_char_generator( PG_CONTROLLER_0 , 6 , Pattern_Full );		//char to print = 0x06
	
	pg_adc_set( PG_ANALOG_CHANNELS_PARAM , PG_4_CHANNELS );
	pg_adc_set( PG_ADC_MODULE , PG_ON );
	
	//Statem		= STATE_FIRST_RUN / STATE_NORMAL / STATE_ALARM / STATE_MENU
	//SubStatem		= SSTATE_IN / SSTATE_GO / SSTATE_OUT
	//SubMenu		= SMENU_DELTA / SMENU_FREEZE / SMENU_VALVE_2 / SMENU_SIREN_3 / SMENU_TEST / SMENU_OFFSET / SMENU_BETA
	//SubStateMenu	= SSMENU_IN / SSMENU_GO / SSMENU_OUT

	Statem			= STATE_FIRST_RUN;
	SubStatem		= SSTATE_IN;
	SubMenu			= SMENU_MANUAL;
	SubStateMenu	= SSMENU_IN;
	
	Slow_Green_Led		= 0;
	Editing				= PG_YES;
	Healt_Pass 			= PG_YES;
	Lock_Manual_Mode	= PG_NO;
	Reset_Confirmed		= PG_NO;
	Temp_BL				= PG_OFF;
	
	//--------------------------------------------------------------------
	PG_INFINITE_LOOP {

		switch ( Statem ) {
			case STATE_FIRST_RUN : {
			//-----------------
				switch ( SubStatem ) {
					case SSTATE_IN : {
					//------------------------------------ FIRST_RUN
						Statem			= STATE_FIRST_RUN;	//Ritorno al main spegnendo tutto
						SubStatem		= SSTATE_GO;
						//SubMenu		<none>
						//SubStateMenu	<none>
						break;
					}
					case SSTATE_GO : {
					//----------------
						#if ( !DEBUG )
							//Check Display Pixel
							Check_Display_Pixels( );
							
							//Check Led
							pg_delay( 1 , PG_SEC );
							LED_PWR_EDIT	= !PG_ON;
							pg_delay( 1, PG_SEC );
							LED_PUMP_1		= !PG_ON;
							pg_delay( 1, PG_SEC );
							LED_VALVE_2		= !PG_ON;
							pg_delay( 1, PG_SEC );
							
							
							//Check Buzzer
							pg_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
							
							Print_Screen_Logo( );
							pg_delay( 7 , PG_SEC );
							
							LED_PWR_EDIT	= !PG_OFF;
							LED_PUMP_1		= !PG_OFF;
							LED_VALVE_2		= !PG_OFF;
						#endif
						
						Load_All_From_Eeprom( );
						
						Statem			= STATE_FIRST_RUN;
						SubStatem		= SSTATE_OUT;
						//SubMenu		<none>
						//SubStateMenu	<none>
						break;
					}
					case SSTATE_OUT : {
					//----------------
						Statem			= STATE_NORMAL;
						SubStatem		= SSTATE_IN;
						//SubMenu		<none>
						//SubStateMenu	<none>
						break;
					}
				}
				break;
			}
			case STATE_ALARM : {
			//-----------------
				switch ( SubStatem ) {
					case SSTATE_IN : {
					//------------------------------------ ALARM
						Pump_Off_Valve_On_Pump_On( );
						
						Statem			= STATE_ALARM;	//Ritorno al main spegnendo tutto
						SubStatem		= SSTATE_GO;
						//SubMenu		<none>
						//SubStateMenu	<none>
						break;
					}
					case SSTATE_GO : {
					//----------------
						if( PG_ENCODER_SW == PG_LOW ) {
							State_Button = Check_Button( );
							if( State_Button == PG_SHORT ) {	//PUSH on/off BL
								PG_LCD_HD44780_BL ^= 1;
								if( PG_LCD_HD44780_BL )
									pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001100 );	//1DCB
								else
									pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001000 );	//1DCB
								pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
								State_Button = PG_NONE;
							}
							if( ( State_Button == PG_LONG ) && ( PG_LCD_HD44780_BL ) ) {	//LONG-PUSH enter menu
								pg_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
								State_Button = PG_NONE;

								Statem			= STATE_MENU;
								SubStatem		= SSTATE_IN;
								//SubMenu		= <none>
								//SubStateMenu	= <none>
								break;
							}
						}
						
						pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001100 );	//1DCB
						
						//Check healt ntc sensor cto-cto or open circuit
						Check_Sensor_Health( );
						
						if( !Healt_Pass ) {		// Il problema e' scomparso e ripristino lo screen
							//Print_Screen_Main_Mask( );
							Healt_Pass = PG_YES;
							
							Print_Screen_Main_Mask( );
							Update_Adc_Value( );
							Delta_Panel_Tank = ( Temp_Panel - Temp_Tank );
							Print_Screen_Main_Data( );
							Pump_Off_Valve_Off( );
							
							Statem			= STATE_ALARM;		//Statem		= STATE_NORMAL;
							SubStatem		= SSTATE_OUT;		//SubStatem		= SSTATE_IN;
							//SubMenu		= <none>
							//SubStateMenu	= <none>
							break;
						}
						
						Update_Adc_Value( );
						Delta_Panel_Tank = ( Temp_Panel - Temp_Tank );
						Print_Screen_Main_Data( );
						
						if ( Temp_Panel < Temp_Valve_2_Stop ) {
							Statem			= STATE_ALARM;	//Ritorno al main spegnendo tutto
							SubStatem		= SSTATE_OUT;
							//SubMenu		<none>
							//SubStateMenu	<none>
							break;
						}
						
						//LED_PWR_EDIT = Slow_Green_Led++ % 10;
						
						//Blink Led
						if ( Slow_Green_Led == 1 )
							LED_PWR_EDIT = !PG_ON;
						else 
							LED_PWR_EDIT = !PG_OFF;
						Slow_Green_Led++;
						if( Slow_Green_Led > 5 )
							Slow_Green_Led = 0;
						
						break;
					}
					case SSTATE_OUT : {
					//-----------------
						Pump_Off_Valve_Off( );
						
						Statem			= STATE_NORMAL;
						SubStatem		= SSTATE_IN;
						//SubMenu		<none>
						//SubStateMenu	<none>
						break;
					}
				}
				break;
			}
			case STATE_NORMAL : {
			//-------------------
				switch ( SubStatem ) {
					case SSTATE_IN : {
					//------------------------------------ NORMAL	( Main screen )
						Print_Screen_Main_Mask( );
						
						Statem			= STATE_NORMAL;
						SubStatem		= SSTATE_GO;
						//SubMenu		  <none>
						//SubStateMenu	  <none>
						break;
					}
					case SSTATE_GO : {
					//----------------
						if( PG_ENCODER_SW == PG_LOW ) {
							State_Button = Check_Button( );
							
							//PUSH on/off BL
							if( State_Button == PG_SHORT ) {
								PG_LCD_HD44780_BL ^= 1;
								if( PG_LCD_HD44780_BL )
									pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001100 );	//1DCB
								else
									pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001000 );	//1DCB
								pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
								State_Button = PG_NONE;
							}
							
							//LONG-PUSH enter menu
							if( ( State_Button == PG_LONG ) && ( PG_LCD_HD44780_BL ) ) {
								pg_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
								State_Button = PG_NONE;

								Statem			= STATE_NORMAL;
								SubStatem		= SSTATE_OUT;
								//SubMenu		= <none>
								//SubStateMenu	= <none>
								break;
							}
						}
						
						if ( !Lock_Manual_Mode ) {
							//Check healt ntc sensor cto-cto or open circuit
							Check_Sensor_Health( );
							
							if( !Healt_Pass ) {		// Il problema e' scomparso e ripristino lo screen
								Healt_Pass = PG_YES;
								
								Print_Screen_Main_Mask( );
								Update_Adc_Value( );
								Delta_Panel_Tank = ( Temp_Panel - Temp_Tank );
								Print_Screen_Main_Data( );
								Pump_Off_Valve_Off( );
								
								Statem			= STATE_NORMAL;
								SubStatem		= SSTATE_IN;
								//SubMenu		= <none>
								//SubStateMenu	= <none>
								break;
							}
						}
						
						Update_Adc_Value( );
						Delta_Panel_Tank = ( Temp_Panel - Temp_Tank );
						Print_Screen_Main_Data( );
						
						if ( !Lock_Manual_Mode ) {
							Out_Manage( );
							LED_PWR_EDIT = ( Slow_Green_Led++ % 10 ) ? 1 : 0;
						}
						else {
							LED_PWR_EDIT ^= 1;
						}
						
				/*		//Blink Led
						if ( Slow_Green_Led == 1 )
							LED_PWR_EDIT = !PG_ON;
						else 
							LED_PWR_EDIT = !PG_OFF;
						Slow_Green_Led++;
						if( Slow_Green_Led > 10 )
							Slow_Green_Led = 0;
				*/			
						break;
					}
					case SSTATE_OUT : {
					//-----------------
						if( PG_LCD_HD44780_BL ) {
							LED_PWR_EDIT = !PG_OFF;
							
							Statem 			= STATE_MENU;
							SubStatem		= SSTATE_IN;
							//bMenu			= <none>
							//bStateMenu	= <none>
							//break;
						}
						else {
							Statem 			= STATE_NORMAL;
							SubStatem		= SSTATE_GO;
							//SubMenu		<none>;
							//SubStateMenu	<none>;
							//break;
						}
						break;
					}
				}
				break;
			}
			case STATE_MENU : {
			//-----------------
				switch ( SubStatem ) {
					case SSTATE_IN : {
					//----------------
						while ( ENCODER_SW ) ;
						LED_PWR_EDIT = !PG_ON;
						
						Statem 			= STATE_MENU;
						SubStatem		= SSTATE_GO;
						SubMenu			= SMENU_MANUAL;
						SubStateMenu	= SSMENU_IN;
						break;
					}
					case SSTATE_GO : {
					//----------------
						switch ( SubMenu ) {
							case SMENU_MANUAL : {
								//------------------------------------ MANUAL
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Manual( );
										
										Statem 			= STATE_MENU;
										SubStatem		= SSTATE_GO;
										SubMenu			= SMENU_MANUAL;
										SubStateMenu	= SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											while ( ENCODER_SW );
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu
											if ( ( Edit_Manual_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Manual_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												if ( !Lock_Manual_Mode ) {
													Pump_Off_Valve_Off( );
													
													if ( OUT_OC_SIREN_3	==  PG_ON ) {
														pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
														OUT_OC_SIREN_3	=  PG_OFF;
													}
												}

												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_FREEZE;
												SubStateMenu	= SSMENU_IN;
												break;
											}
											
											//	EXIT ICON, go to Main
											if ( ( Edit_Manual_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Manual_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
												if ( !Lock_Manual_Mode ) {
													Pump_Off_Valve_Off( );
													
													if ( OUT_OC_SIREN_3	==  PG_ON ) {
														pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
														OUT_OC_SIREN_3	=  PG_OFF;
													}
												}
																			
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	Manual mode check
											if ( ( Edit_Manual_Line[ EPos ] == PG_LINE_0 ) && ( Edit_Manual_Pos[ EPos ] == 11 ) ) {
												if ( Lock_Manual_Mode == PG_NO ) {
													Lock_Manual_Mode = PG_YES;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_0 , 11 , 0x05 );	//Print Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_0 , 11 );					//Ritorno sul pallino
												}
												else {
													Lock_Manual_Mode = PG_NO;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_0 , 11 , ' ' );	//Clear Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_0 , 11 );					//Ritorno sul pallino
												}
											}
											
											//	OUT1
											if ( ( Edit_Manual_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Manual_Pos[ EPos ] == 4 ) ) {
												if ( OUT_OC_PUMP_1 == PG_OFF ) {
													OUT_OC_PUMP_1 = PG_ON;
													LED_PUMP_1 = !PG_ON;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_1 , 4 , 0x05 );	//Print Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_1 , 4 );					//Ritorno sul pallino
												}
												else {
													OUT_OC_PUMP_1 = PG_OFF;
													LED_PUMP_1 = !PG_OFF;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_1 , 4 , ' ' );	//Clear Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_1 , 4 );					//Ritorno sul pallino
												}
											}
											
											//	OUT2
											if ( ( Edit_Manual_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Manual_Pos[ EPos ] == 4 ) ) {
												if ( OUT_OC_VALVE_2 == PG_OFF ) {
													OUT_OC_VALVE_2 = PG_ON;
													LED_VALVE_2 = !PG_ON;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_2 , 4 , 0x05 );	//Print Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_2 , 4 );					//Ritorno sul pallino
												}
												else {
													OUT_OC_VALVE_2 = PG_OFF;
													LED_VALVE_2 = !PG_OFF;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_2 , 4 , ' ' );	//Clear Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_2 , 4 );					//Ritorno sul pallino
												}
											}
											
											//	OUT3
											if ( ( Edit_Manual_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Manual_Pos[ EPos ] == 4 ) ) {
												if ( OUT_OC_SIREN_3 == PG_OFF ) {
													OUT_OC_SIREN_3 = PG_ON;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_3 , 4 , 0x05 );	//Print Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_3 , 4 );					//Ritorno sul pallino
												}
												else {
													OUT_OC_SIREN_3 = PG_OFF;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_3 , 4 , ' ' );	//Clear Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_3 , 4 );					//Ritorno sul pallino
												}
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_MANUAL_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Manual_Line[ EPos ] , Edit_Manual_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_MANUAL_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Manual_Line[ EPos ] , Edit_Manual_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
							case SMENU_FREEZE : {
							//---------------------------------------- FREEZE
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Freeze( );
										
										Statem 			= STATE_MENU;
										SubStatem		= SSTATE_GO;
										SubMenu			= SMENU_FREEZE;
										SubStateMenu	= SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Freeze_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Freeze_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Freeze_1_Start , TEMP_FREEZE_START_PUMP_1_ADDRESS );
												Load_Eeprom_Data( &Temp_Freeze_1_Stop , TEMP_FREEZE_STOP_PUMP_1_ADDRESS );
												
												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_DELTA;
												SubStateMenu	= SSMENU_IN;
												break;
											}
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Freeze_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Freeze_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {	
												//Restore value
												Load_Eeprom_Data( &Temp_Freeze_1_Start , TEMP_FREEZE_START_PUMP_1_ADDRESS );
												Load_Eeprom_Data( &Temp_Freeze_1_Stop , TEMP_FREEZE_STOP_PUMP_1_ADDRESS );
												//Print_Screen_Main_Mask( );
												
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Freeze_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Freeze_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) ) {
												Save_Freeze_Value( );
												//Save_Start_And_Stop_Value( &Temp_Freeze_1_Start , &Temp_Freeze_1_Stop , TEMP_FREEZE_START_PUMP_1_ADDRESS , TEMP_FREEZE_STOP_PUMP_1_ADDRESS , Edit_Freeze_Line , Edit_Freeze_Pos );
											}
											
											//	TA
											if ( ( Edit_Freeze_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Freeze_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Freeze_1_Start , 10 , EDIT_FREEZE_VALUE_MAX , EDIT_FREEZE_VALUE_MIN , Edit_Freeze_Line ,Edit_Freeze_Pos );
											}
											if ( ( Edit_Freeze_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Freeze_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Freeze_1_Start , 1 , EDIT_FREEZE_VALUE_MAX , EDIT_FREEZE_VALUE_MIN , Edit_Freeze_Line ,Edit_Freeze_Pos );
											}
											//	TS
											if ( ( Edit_Freeze_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Freeze_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Freeze_1_Stop , 10 , EDIT_FREEZE_VALUE_MAX , EDIT_FREEZE_VALUE_MIN , Edit_Freeze_Line ,Edit_Freeze_Pos );
											}
											if ( ( Edit_Freeze_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Freeze_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Freeze_1_Stop , 1 , EDIT_FREEZE_VALUE_MAX , EDIT_FREEZE_VALUE_MIN , Edit_Freeze_Line ,Edit_Freeze_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_FREEZE_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Freeze_Line[ EPos ] , Edit_Freeze_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_FREEZE_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Freeze_Line[ EPos ] , Edit_Freeze_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
							case SMENU_DELTA : {
							//---------------------------------------- DELTA
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Delta( );
										
										Statem 			= STATE_MENU;
										SubStatem		= SSTATE_GO;
										SubMenu			= SMENU_DELTA;
										SubStateMenu	= SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Delta_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Delta_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Delta_Start_Pump_1 , DELTA_START_PUMP_1_ADDRESS );
												Load_Eeprom_Data( &Delta_Stop_Pump_1 , DELTA_STOP_PUMP_1_ADDRESS );
												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_VALVE_2;
												SubStateMenu	= SSMENU_IN;
												break;
											}
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Delta_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Delta_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {	
												//Restore value
												Load_Eeprom_Data( &Delta_Start_Pump_1 , DELTA_START_PUMP_1_ADDRESS );
												Load_Eeprom_Data( &Delta_Stop_Pump_1 , DELTA_STOP_PUMP_1_ADDRESS );
												
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Delta_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Delta_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) ) {
												Save_Start_And_Stop_Value( &Delta_Start_Pump_1 , &Delta_Stop_Pump_1 , DELTA_START_PUMP_1_ADDRESS , DELTA_STOP_PUMP_1_ADDRESS , Edit_Delta_Line , Edit_Delta_Pos);
											}
											//	A1
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Delta_Pos[ EPos ] == 3 ) ) {
												Edit_Digit( &Delta_Start_Pump_1 , 100 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line , Edit_Delta_Pos );
											}
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Delta_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Delta_Start_Pump_1 , 10 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line ,Edit_Delta_Pos );
											}
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Delta_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Delta_Start_Pump_1 , 1 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line ,Edit_Delta_Pos );
											}
											//	S1
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Delta_Pos[ EPos ] == 3 ) ) {
												Edit_Digit( &Delta_Stop_Pump_1 , 100 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line , Edit_Delta_Pos );
											}
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Delta_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Delta_Stop_Pump_1 , 10 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line ,Edit_Delta_Pos );
											}
											if ( ( Edit_Delta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Delta_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Delta_Stop_Pump_1 , 1 , EDIT_DELTA_VALUE_MAX , EDIT_DELTA_VALUE_MIN , Edit_Delta_Line ,Edit_Delta_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_DELTA_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Delta_Line[ EPos ] , Edit_Delta_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_DELTA_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Delta_Line[ EPos ] , Edit_Delta_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
							case SMENU_VALVE_2 : {
							//---------------------------------------- ALARM_2
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Valve_2( );
										
										SubStateMenu = SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Valve_2_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Valve_2_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Valve_2_Start , TEMP_VALVE_2_START_ADDRESS );
												Load_Eeprom_Data( &Temp_Valve_2_Stop , TEMP_VALVE_2_STOP_ADDRESS );
												
												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_SIREN_3;
												SubStateMenu	= SSMENU_IN;
												break;
											}	
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Valve_2_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Valve_2_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Valve_2_Start , TEMP_VALVE_2_START_ADDRESS );
												Load_Eeprom_Data( &Temp_Valve_2_Stop , TEMP_VALVE_2_STOP_ADDRESS );
												
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Valve_2_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Valve_2_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) ) {
												Save_Start_And_Stop_Value( &Temp_Valve_2_Start , &Temp_Valve_2_Stop , TEMP_VALVE_2_START_ADDRESS , TEMP_VALVE_2_STOP_ADDRESS , Edit_Valve_2_Line , Edit_Valve_2_Pos );
											}
											//	A2
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Valve_2_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Valve_2_Start , 100 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line , Edit_Valve_2_Pos );
											}
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Valve_2_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Valve_2_Start , 10 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line ,Edit_Valve_2_Pos );
											}
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Valve_2_Pos[ EPos ] == 6 ) ) {
												Edit_Digit( &Temp_Valve_2_Start , 1 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line ,Edit_Valve_2_Pos );
											}
											//	S2
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Valve_2_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Valve_2_Stop , 100 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line , Edit_Valve_2_Pos );
											}
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Valve_2_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Valve_2_Stop , 10 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line ,Edit_Valve_2_Pos );
											}
											if ( ( Edit_Valve_2_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Valve_2_Pos[ EPos ] == 6 ) ) {
												Edit_Digit( &Temp_Valve_2_Stop , 1 , EDIT_VALVE_2_VALUE_MAX , EDIT_VALVE_2_VALUE_MIN , Edit_Valve_2_Line ,Edit_Valve_2_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_VALVE_2_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Valve_2_Line[ EPos ] , Edit_Valve_2_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_VALVE_2_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Valve_2_Line[ EPos ] , Edit_Valve_2_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
							break;
							}
							case SMENU_SIREN_3 : {
							//---------------------------------------- ALARM_3
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Siren_3( );
										
										SubStateMenu = SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Siren_3_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Siren_3_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Siren_3_Start , TEMP_SIREN_3_START_ADDRESS );
												Load_Eeprom_Data( &Temp_Siren_3_Stop , TEMP_SIREN_3_STOP_ADDRESS );

												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_OFFSET;
												SubStateMenu	= SSMENU_IN;
												break;
											}	
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Siren_3_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Siren_3_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Siren_3_Start , TEMP_SIREN_3_START_ADDRESS );
												Load_Eeprom_Data( &Temp_Siren_3_Stop , TEMP_SIREN_3_STOP_ADDRESS );
												
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Siren_3_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Siren_3_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) ) {
												Save_Start_And_Stop_Value( &Temp_Siren_3_Start , &Temp_Siren_3_Stop , TEMP_SIREN_3_START_ADDRESS , TEMP_SIREN_3_STOP_ADDRESS , Edit_Siren_3_Line , Edit_Siren_3_Pos);
											}
											//	A3
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Siren_3_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Siren_3_Start , 100 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line , Edit_Siren_3_Pos );
											}
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Siren_3_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Siren_3_Start , 10 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line ,Edit_Siren_3_Pos );
											}
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Siren_3_Pos[ EPos ] == 6 ) ) {
												Edit_Digit( &Temp_Siren_3_Start , 1 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line ,Edit_Siren_3_Pos );
											}
											//	S3
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Siren_3_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Siren_3_Stop , 100 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line , Edit_Siren_3_Pos );
											}
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Siren_3_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Siren_3_Stop , 10 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line ,Edit_Siren_3_Pos );
											}
											if ( ( Edit_Siren_3_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Siren_3_Pos[ EPos ] == 6 ) ) {
												Edit_Digit( &Temp_Siren_3_Stop , 1 , EDIT_SIREN_3_VALUE_MAX , EDIT_SIREN_3_VALUE_MIN , Edit_Siren_3_Line ,Edit_Siren_3_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_SIREN_3_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Siren_3_Line[ EPos ] , Edit_Siren_3_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_SIREN_3_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Siren_3_Line[ EPos ] , Edit_Siren_3_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
							case SMENU_OFFSET : {
							//---------------------------------------- OFFSET
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Offset( );
										
										SubStateMenu = SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Offset_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Offset_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Offset_1 , TEMP_OFFSET_1_ADDRESS );
												Load_Eeprom_Data( &Temp_Offset_2 , TEMP_OFFSET_2_ADDRESS );
												Load_Eeprom_Data( &Temp_Offset_3 , TEMP_OFFSET_3_ADDRESS );

												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_BETA;
												SubStateMenu	= SSMENU_IN;
												break;
											}	
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Offset_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Offset_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Temp_Offset_1 , TEMP_OFFSET_1_ADDRESS );
												Load_Eeprom_Data( &Temp_Offset_2 , TEMP_OFFSET_2_ADDRESS );
												Load_Eeprom_Data( &Temp_Offset_3 , TEMP_OFFSET_3_ADDRESS );
																							
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Offset_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Offset_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) ) {
												Save_Offset_Value( );
											}
											//	O1
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Offset_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Offset_1 , 10 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Offset_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Offset_1 , 1 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
											//	O2
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Offset_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Offset_2 , 10 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Offset_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Offset_2 , 1 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
											//	O3
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Offset_Pos[ EPos ] == 4 ) ) {
												Edit_Digit( &Temp_Offset_3 , 10 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
											if ( ( Edit_Offset_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Offset_Pos[ EPos ] == 5 ) ) {
												Edit_Digit( &Temp_Offset_3 , 1 , EDIT_OFFSET_VALUE_MAX , EDIT_OFFSET_VALUE_MIN , Edit_Offset_Line ,Edit_Offset_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_OFFSET_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Offset_Line[ EPos ] , Edit_Offset_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_OFFSET_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Offset_Line[ EPos ] , Edit_Offset_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
							case SMENU_BETA : {
							//---------------------------------------- BETA
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Init_Menu_Beta( );
										
										Statem 			= STATE_MENU;
										SubStatem		= SSTATE_GO;
										SubMenu			= SMENU_BETA;
										SubStateMenu	= SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Beta_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Beta_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Ntc_Beta_1 , NTC_BETA_1_ADDRESS );
												Load_Eeprom_Data( &Ntc_Beta_2 , NTC_BETA_2_ADDRESS );
												Load_Eeprom_Data( &Ntc_Beta_3 , NTC_BETA_3_ADDRESS );

												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_RESET;
												SubStateMenu	= SSMENU_IN;
												break;
											}
											
											//	EXIT ICON, go to main menu without save! Losing new value. Load original from Eeprom
											if ( ( Edit_Beta_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Beta_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
												//Restore value
												Load_Eeprom_Data( &Ntc_Beta_1 , NTC_BETA_1_ADDRESS );
												Load_Eeprom_Data( &Ntc_Beta_2 , NTC_BETA_2_ADDRESS );
												Load_Eeprom_Data( &Ntc_Beta_3 , NTC_BETA_3_ADDRESS );
												
												LED_PWR_EDIT 	= !PG_OFF;
											
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	RESTORE ICON, reload original default rom value
											if ( ( Edit_Beta_Line[ EPos ] == EDIT_RELOAD_BETA_ICON_LINE ) && ( Edit_Beta_Pos[ EPos ] == EDIT_RELOAD_BETA_ICON_POS ) ) {
												//Restore value
												Ntc_Beta_1 = NTC_BETA_1;
												Ntc_Beta_2 = NTC_BETA_1;
												Ntc_Beta_3 = NTC_BETA_1;
												Init_Menu_Beta( );
											}
											
											//	SAVE ICON, sync eeprom with new or not variables in ram!
											if ( ( Edit_Beta_Line[ EPos ] == EDIT_SAVE_ICON_LINE ) && ( Edit_Beta_Pos[ EPos ] == EDIT_SAVE_ICON_POS ) )
												Save_Beta_Value( );
											//	O1
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Beta_Pos[ EPos ] == 8 ) ) {
												Edit_Digit( &Ntc_Beta_1 , 10000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Beta_Pos[ EPos ] == 9 ) ) {
												Edit_Digit( &Ntc_Beta_1 , 1000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Beta_Pos[ EPos ] == 10 ) ) {
												Edit_Digit( &Ntc_Beta_1 , 100 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Beta_Pos[ EPos ] == 11 ) ) {
												Edit_Digit( &Ntc_Beta_1 , 10 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_1 ) && ( Edit_Beta_Pos[ EPos ] == 12 ) ) {
												Edit_Digit( &Ntc_Beta_1 , 1 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											//	O2
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Beta_Pos[ EPos ] == 8 ) ) {
												Edit_Digit( &Ntc_Beta_2 , 10000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Beta_Pos[ EPos ] == 9 ) ) {
												Edit_Digit( &Ntc_Beta_2 , 1000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Beta_Pos[ EPos ] == 10 ) ) {
												Edit_Digit( &Ntc_Beta_2 , 100 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Beta_Pos[ EPos ] == 11 ) ) {
												Edit_Digit( &Ntc_Beta_2 , 10 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Beta_Pos[ EPos ] == 12 ) ) {
												Edit_Digit( &Ntc_Beta_2 , 1 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											//	O3
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Beta_Pos[ EPos ] == 8 ) ) {
												Edit_Digit( &Ntc_Beta_3 , 10000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Beta_Pos[ EPos ] == 9 ) ) {
												Edit_Digit( &Ntc_Beta_3 , 1000 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Beta_Pos[ EPos ] == 10 ) ) {
												Edit_Digit( &Ntc_Beta_3 , 100 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Beta_Pos[ EPos ] == 11 ) ) {
												Edit_Digit( &Ntc_Beta_3 , 10 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
											if ( ( Edit_Beta_Line[ EPos ] == PG_LINE_3 ) && ( Edit_Beta_Pos[ EPos ] == 12 ) ) {
												Edit_Digit( &Ntc_Beta_3 , 1 , EDIT_BETA_VALUE_MAX , EDIT_BETA_VALUE_MIN , Edit_Beta_Line , Edit_Beta_Pos );
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_BETA_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Beta_Line[ EPos ] , Edit_Beta_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_BETA_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Beta_Line[ EPos ] , Edit_Beta_Pos[ EPos ] );
										}

										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
							break;
							}
							case SMENU_RESET : {
								//------------------------------------ RESET
								switch ( SubStateMenu ) {
									case SSMENU_IN : {
									//----------------
										Print_Screen_Reset_Mask( );
										pg_lcd_hd44780_goto( PG_CONTROLLER_0 , EDIT_ARROW_ICON_LINE , EDIT_ARROW_ICON_POS );	//pos su freccia; EPos = 0
										EPos = 0;
										pg_lcd_hd44780_write_byte( PG_CONTROLLER_0 , PG_COMMAND , 0b00001101 );	//1DCB
										
										//LED_PUMP_1	= !PG_OFF;
										//LED_VALVE_2 = !PG_OFF;
										
										Statem 			= STATE_MENU;
										SubStatem		= SSTATE_GO;
										SubMenu			= SMENU_RESET;
										SubStateMenu	= SSMENU_GO;
										break;
									}
									case SSMENU_GO : {
									//----------------
										Editing = PG_YES;
										while ( ENCODER_SW );
										res = encoder_pulse();
										while ( ENCODER_SW );
										if ( pg_encoder_button ) {
											while ( ENCODER_SW );
											pg_beep( PG_BEEP_HIGH , PG_BEEP_SHORT );
											
											//	ARROW ICON, go to next menu
											if ( ( Edit_Reset_Line[ EPos ] == EDIT_ARROW_ICON_LINE ) && ( Edit_Reset_Pos[ EPos ] == EDIT_ARROW_ICON_POS ) ) {

												Statem 			= STATE_MENU;
												SubStatem		= SSTATE_GO;
												SubMenu			= SMENU_MANUAL;
												SubStateMenu	= SSMENU_IN;
												break;
											}
											
											//	EXIT ICON, go to Main
											if ( ( Edit_Reset_Line[ EPos ] == EDIT_EXIT_ICON_LINE ) && ( Edit_Reset_Pos[ EPos ] == EDIT_EXIT_ICON_POS ) ) {
	
												Statem			= STATE_NORMAL;
												SubStatem		= SSTATE_IN;
												//SubMenu		<none>
												//SubStateMenu	<none>
												break;
											}
											
											//	CONFERMA
											if ( ( Edit_Reset_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Reset_Pos[ EPos ] == 2 ) ) {
												if ( Reset_Confirmed == PG_NO ) {
													Reset_Confirmed = PG_YES;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_2 , 2 , 0x05 );	//Print Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_2 , 2 );					//Ritorno sul pallino
												}
												else {
													Reset_Confirmed == PG_NO;
													pg_lcd_hd44780_put_p_char ( PG_CONTROLLER_0 , PG_LINE_2 , 2 , ' ' );	//Clear Ball Icon
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , PG_LINE_2 , 2 );					//Ritorno sul pallino
												}
											}
											
											//	ESEGUI Reset
											if ( ( Edit_Reset_Line[ EPos ] == PG_LINE_2 ) && ( Edit_Reset_Pos[ EPos ] == 15 ) ) {
												if ( Reset_Confirmed == PG_YES ) {
													pg_lcd_hd44780_clear( PG_CONTROLLER_0 );
													//--------------------------------------------------------------------0123456789012345
													pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_1 , 2 , "Riavvio..." );
													pg_delay( 3 , PG_SEC );
													Reset_Confirmed == PG_NO;
													Reset( );
												}
												else {
													//--------------------------------------------------------------------0123456789012345
													pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_3 , 0 , "Manca conferma!" );
													pg_delay( 3 , PG_SEC );
													pg_lcd_hd44780_write_p_string_rom( PG_CONTROLLER_0 , PG_LINE_3 , 0 , "               " );
													pg_lcd_hd44780_goto( PG_CONTROLLER_0 , EDIT_ARROW_ICON_LINE , EDIT_ARROW_ICON_POS );	//pos su freccia; EPos = 0
													EPos = 0;
												}
											}
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CW ) ) {
											EPos++;
											if ( EPos > EDIT_RESET_THE_LAST )
												EPos = 0;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Reset_Line[ EPos ] , Edit_Reset_Pos[ EPos ] );
										}
										if ( ( pg_encoder_intensity ) && ( pg_encoder_direction == ENC_CCW ) ) {
											EPos--;
											if ( EPos < 0 )
												EPos = EDIT_RESET_THE_LAST;
											pg_lcd_hd44780_goto( PG_CONTROLLER_0 , Edit_Reset_Line[ EPos ] , Edit_Reset_Pos[ EPos ] );
										}
										break;
									}
									case SSMENU_OUT : {
									//-----------------
										;
										break;
									}
								}
								break;
							}
						}
						break;
					}
					case SSTATE_OUT : {
					//-----------------
						break;
					}
				}
				break;
			}
		}
	}
}	
