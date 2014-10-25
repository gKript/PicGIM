//
// pgim_dac8211.h
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

/*!		\file			pgim_dac8211.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

//main.h
//Kappa, 26 Gennaio 2013

//----------------------------------------------------------------------------
//	PINS		( If mod.: aggiornare skm_hw.txt)
//----------------------------------------------------------------------------
//	LCD
#define PT8211_CL			LATDbits.LATD0		//BCK	CLOCK
#define PT8211_CL_TRIS		TRISDbits.TRISD0

#define PT8211_CH 			LATDbits.LATD1		//WS		CANALE DX=0 SX=1
#define PT8211_CH_TRIS		TRISDbits.TRISD1

#define PT8211_DT			LATDbits.LATD2		//DIN	DATO
#define PT8211_DT_TRIS		TRISDbits.TRISD2

//	LED
#define	LED					LATDbits.LATD3
#define	LED_TRIS			TRISDbits.TRISD3	//rinominare per picgim con pt8211_...

//	CHANNELS
#define	DX					0
#define	SX					1

//----------------------------------------------------------------------------
//	PROTOTIPI
//----------------------------------------------------------------------------
void Flash_Led				( void );
void Write_Word				( unsigned char ch, int campione );

//------------------------------------------------------------------------------
// EOF
//------------------------------------------------------------------------------


