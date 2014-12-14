//
// pgim_18f4620.h
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

/*!		\file			pgim_18f4620.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
*/

#ifndef _PGIM_18F4620_PRIVATE_H_
	#define _PGIM_18F4620_PRIVATE_H_

	//---[ Internal Oscillator ]---
	#if defined( PG_DOXYGEN )
		#undef		PG_USE_INTERNAL_OSC
		#define		PG_USE_INTERNAL_OSC		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PG_USE_INTERNAL_OSC
		#define		PG_USE_INTERNAL_OSC		PG_DISABLE
	#endif
	
	//-----------------------------------------------------
	#if ( PG_USE_INTERNAL_OSC == PG_ENABLE )
		#include "pgim_int_osc.h"
		#ifdef _GIM_H_
			#pragma	config OSC = INTIO67					//!< Internal oscillator, port function OSC2 as RA6, OSC1 as RA7
		#endif
		#undef	PG_CLOCK
		#define	PG_CLOCK 8.000								// Re-define new oscillator frequency with PLL enabled ( 8MHz x 4 = 32 MHz )
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using INTERNAL oscillator ( PG_CLOCK [MHz] )
		#endif
	#else
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using EXTERNAL oscillator ( PG_CLOCK [MHz] )
		#endif
	#endif
	//---[ END Internal Oscillator ]---
	
	
	//---[ Public ]---
	#include ".\pgim_mcu\pgim_18f4620_public.h"
	//---[ END Public ]---
					
					
	//---[ Extended Instructions Set ]--- SUPPORTED
	#ifdef _GIM_H_
		#if defined( __EXTENDED18__ )
			#pragma	config XINST = ON
			#if	( PG_VERBOSE == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE Extended Instructions Set successful activated
			#endif
		#else
			#pragma	config XINST = OFF
			#if	( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
				#warning	PG_HS_PG PG_HS_CORE PG_HS_SUGG TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
			#endif
		#endif
	#endif	
	//---[ END Extended Instructions Set ]---
	
	
	//---[ Hardware Resources ]---
	#define		PG_PIN_NUMBER				40					//!<	The number of pins

	#define		PG_TCYCLEPERI				4					//!<	The number of cycles required for an instruction for the family PIC18
	#define		PG_MAX_OSC_FREQ				40.000				//!<	The maximum working frequency
	
	#define		PG_MAX_RAM					3986				//!<	The maximum amount of RAM				
	#define		PG_MAX_EEPROM				1024				//!<	If ( PG_MAX_EEPROM == 0 ) there is no EEPROM memory
	#define		PG_MCU_SUPPLY_MAX			5.00				//!<	The maximum power supply voltage
	
	#define		PG_ADC_RES_BITS				10					//!<	ADC resolution bits
	#define		PG_ADC_RES_STEPS			1024				//!<	ADC resolution steps.
	
	#define		PG_PWM_1_MODE				PG_ENHANCED			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_2_MODE				PG_STANDARD			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_FOSC_DIVIDER			4.000				//!<	Internal clock divider to drive timer
	
	#define		PG_SERIAL_TX_TRIS			TRISCbits.TRISC6	//!<	Tx pin of USART port
	#define		PG_SERIAL_RX_TRIS			TRISCbits.TRISC7	//!<	Rx pin of USART port
	
	#define		PG_SPI_SDO_TRIS				TRISCbits.TRISC5	//!<	SPI output; Set tris to '0' as output
	#define		PG_SPI_SDI_TRIS				TRISCbits.TRISC4	//!<	SPI input; Tris is automatically controlled by the SPI module
	#define		PG_SPI_SCK_TRIS				TRISCbits.TRISC3	//!<	SPI clock; Master mode: set tris to '0' as output; Slave mode: set tris to '1' as input;; Slave mode: set tris to '1' as input;
	#define		PG_SPI_SS_TRIS				TRISAbits.TRISA5	//!<	SPI slave-select
	
	#define		PG_I2C_SDA_TRIS				TRISCbits.TRISC4	//!<	I2C data I/O
	#define		PG_I2C_SCL_TRIS				TRISCbits.TRISC3	//!<	I2C clock
	
	#define		PG_RESET_POR				0b11110000			//!<	Power-On reset
	#define		PG_RESET_POR_MASK			0b11111111			//!<	Power-On reset mask
	#define		PG_RESET_RI					0b00000000			//!<	Reset instruction
	#define		PG_RESET_RI_MASK			0b01000000			//!<	Reset instruction mask
	#define		PG_RESET_BOR				0b01110000			//!<	Brown-out reset
	#define		PG_RESET_BOR_MASK			0b01110100			//!<	Brown-out reset mask
	#define		PG_RESET_MCLR_PMRM			0b00100000			//!<	MCLR during power-managed Run Modes
	#define		PG_RESET_MCLR_PMRM_MASK		0b00100000			//!<	MCLR during power-managed Run Modes mask
	#define		PG_RESET_MCLR_PMISM			0b00100000			//!<	MCLR during power-managed Idle modes and Sleep mode
	#define		PG_RESET_MCLR_PMISM_MASK	0b00110000			//!<	MCLR during power-managed Idle modes and Sleep mode mask
	#define		PG_RESET_WDT_FP_PMRM		0b00000000			//!<	WDT time-out during full power or power-managed Run mode
	#define		PG_RESET_WDT_FP_PMRM_MASK	0b00100000			//!<	WDT time-out during full power or power-managed Run mode mask
	#define		PG_RESET_MCLR_FPM			0b00000000			//!<	MCLR during full-power execution
	#define		PG_RESET_MCLR_FPM_MASK		0b00000000			//!<	MCLR during full-power execution mask
	#define		PG_RESET_SFR				0b00000010			//!<	Stack Full Reset (STVREN = 1)
	#define		PG_RESET_SFR_MASK			0b00000010			//!<	Stack Full Reset mask (STVREN = 1)
	#define		PG_RESET_SUR				0b00000001			//!<	Stack Underflow Reset (STVREN = 1)
	#define		PG_RESET_SUR_MASK			0b00000001			//!<	Stack Underflow Reset mask (STVREN = 1)
	#define		PG_RESET_WDT_PMISM			0b00000000			//!<	WDT time-out during power-managed Idle or Sleep modes
	#define		PG_RESET_WDT_PMISM_MASK		0b00110000			//!<	WDT time-out during power-managed Idle or Sleep modes mask
	#define		PG_RESET_INT_EXIT_PMM		0b00000000			//!<	Interrupt exit from power-managed modes
	#define		PG_RESET_INT_EXIT_PMM_MASK	0b00010000			//!<	Interrupt exit from power-managed modes mask
	#define		PG_RESET_POR				0b11110000			//!<	Power-On reset 
	#define		PG_RESET_POR_MASK			0b11111111			//!<	Power-On reset mask 
	#define		PG_RESET_RI					0b00000000			//!<	Reset instruction 
	#define		PG_RESET_RI_MASK			0b01000000			//!<	Reset instruction mask 
	#define		PG_RESET_BOR				0b01110000			//!<	Brown-out reset 
	#define		PG_RESET_BOR_MASK			0b01110100			//!<	Brown-out reset mask 
	#define		PG_RESET_MCLR_PMRM			0b00100000			//!<	MCLR during power-managed Run Modes 
	#define		PG_RESET_MCLR_PMRM_MASK		0b00100000			//!<	MCLR during power-managed Run Modes mask 
	#define		PG_RESET_MCLR_PMISM			0b00100000			//!<	MCLR during power-managed Idle modes and Sleep mode 
	#define		PG_RESET_MCLR_PMISM_MASK	0b00110000			//!<	MCLR during power-managed Idle modes and Sleep mode mask 
	#define		PG_RESET_WDT_FP_PMRM		0b00000000			//!<	WDT time-out during full power or power-managed Run mode 
	#define		PG_RESET_WDT_FP_PMRM_MASK	0b00100000			//!<	WDT time-out during full power or power-managed Run mode mask 
	#define		PG_RESET_MCLR_FPM			0b00000000			//!<	MCLR during full-power execution 
	#define		PG_RESET_MCLR_FPM_MASK		0b00000000			//!<	MCLR during full-power execution mask
	#define		PG_RESET_SFR				0b00000010			//!<	Stack Full Reset (STVREN = 1) 
	#define		PG_RESET_SFR_MASK			0b00000010			//!<	Stack Full Reset mask (STVREN = 1) 
	#define		PG_RESET_SUR				0b00000001			//!<	Stack Underflow Reset (STVREN = 1) 
	#define		PG_RESET_SUR_MASK			0b00000001			//!<	Stack Underflow Reset mask (STVREN = 1) 
	#define		PG_RESET_WDT_PMISM			0b00000000			//!<	WDT time-out during power-managed Idle or Sleep modes 
	#define		PG_RESET_WDT_PMISM_MASK		0b00110000			//!<	WDT time-out during power-managed Idle or Sleep modes mask 
	#define		PG_RESET_INT_EXIT_PMM		0b00000000			//!<	Interrupt exit from power-managed modes 
	#define		PG_RESET_INT_EXIT_PMM_MASK	0b00010000			//!<	Interrupt exit from power-managed modes mask 
	//---[ END Hardware Resources ]---

#endif /* _PGIM_18F4620_PRIVATE_H_ */



/*!	\page		MCU_PIC18F4620 	PIC18F4620 : Settings

		\brief	40/44-Pin Enhanced Flash Microcontrollers with 10-Bit A/D and nanoWatt Technology \n

		\htmlonly
			<table width="100%" border="0" >
				<tr align="center">
					<td><IMG src="18f40pin.jpg" align="center" border="0" ></td>
					<td><IMG src="18f44tpin.jpg" align="center" border="0" ></td>
				</tr>
			</table>
			<big><h1 align="center">P I C 1 8 F 4 6 2 0</h1></big>
			<BR>
		\endhtmlonly

		\section	datasheet4620	MicroChip official datasheet
		
			\htmlonly
				We think that if you are reading this documentation you will certainly already decided the hardware part of your project.<br>
				However, for your convenience we put a link to the official datasheet from Microchip.
				<br><br>
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<A href="http://ww1.microchip.com/downloads/en/DeviceDoc/39626e.pdf" target="_blank" ><IMG src="icona-pdf.gif" align="center" border="0" ></A>
				<br><br><br><br>
			\endhtmlonly
		
		\section	Constant4620	Various constants
		
			\subsection		TCYCLEPERI4620		PG_TCYCLEPERI
			Is the number of cycles required for a single instruction for the family PIC18. This is  a constant.
			\code
				#define		PG_TCYCLEPERI		4
			\endcode
			
			\subsection		MAX_OSC_FREQ4620		PG_MAX_OSC_FREQ
			Is the maximum working frequency for this specific MCU. This is  a constant.
			\code
				#define		PG_MAX_OSC_FREQ		40.000
			\endcode

			\subsection		MAX_RAM4620		PG_MAX_RAM
			Is the maximum amount of RAM for this specific MCU. This is  a constant.
			\code
				#define		PG_MAX_RAM			3986
			\endcode

			\subsection		PSUPPLY4620		PG_MCU_SUPPLY_MAX
				Is the supply voltage of the MCU. This voltage is a reference for PicGIM but is not precise. \n
				For the precise voltage refer to the datasheet from the previous chapter : \ref datasheet
				\code
					#define		PG_MCU_SUPPLY_MAX			5.0
				\endcode

		\section	SXINST4620			Extended Instruction Code
			\endhtmlonly
			\endcode
			<b>This MCU can support this feature.</b> \n
			Under MPLAB 8 it is simply to enable it just following this figure : \n
			\n \n
			\image	html	xinst.jpg
			\n \n
			<b>PicGIM</b> will automatically choose the correct FUSE intercepting the flag from C18. \n \n

			In MPLAB X is not so simple but they are only need three steps.
			Follow this step by step guide:	\ref getstartmpxhowtoxinst \n

			\attention		Even if it is properly flagged check for Extended instruction code, MPLAB X will ignore it. \n
						It will be necessary, as well as to flag, the extended instruction code, manually force the definition of "__EXTENDED18__" in Compiler and Linker. \n
						Here is the guide : \ref getstartmpxhowtoxins

			\n

			\code
				//---[ Extended Instructions Set ]--- SUPPORTED
				#ifdef _GIM_H_
					#if defined( __EXTENDED18__ )
						#pragma	config XINST = ON
						#if	( PG_VERBOSE == PG_ENABLE )
							#warning	PG_HS_PG PG_HS_CORE Extended Instructions Set successful activated
						#endif
					#else
						#pragma	config XINST = OFF
						#if	( PG_VERBOSE == PG_ENABLE ) && ( PG_SUGGESTION == PG_ENABLE )
							#warning	PG_HS_PG PG_HS_CORE PG_HS_SUGG TRADITIONAL code activated but EXTENDED Instructions Set is available with this MCU. Keep on mind!
						#endif
					#endif
				#endif
				//---[ END Extended Instructions Set ]---
			\endcode
			
		\section	Default4620		Default FUSE configuration
			
			\code
				#pragma	config PLLDIV		= 1
				#pragma	config CPUDIV		= OSC1_PLL2
				#pragma	config FOSC			= ECPLLIO_EC  
				#pragma	config USBDIV		= 1
				#pragma	config FCMEN		= OFF
				#pragma	config IESO			= OFF
				#pragma	config VREGEN		= OFF
				#pragma	config BOR			= ON
				#pragma	config BORV			= 2
				#pragma	config WDT			= OFF
				#pragma	config WDTPS		= 32768
				#pragma	config MCLRE		= ON
				#pragma	config LPT1OSC	= OFF
				#pragma	config PBADEN		= OFF
				#pragma	config STVREN		= OFF
				#pragma	config LVP				= OFF
				#if defined( __EXTENDED18__ )
					#pragma	config XINST		= ON
				#else
					#pragma	config XINST		= OFF
				#endif
				#pragma	config DEBUG		= OFF
				#pragma	config CP0			= OFF
				#pragma	config CP1			= OFF
				#pragma	config CP2			= OFF
				#pragma	config CP3			= OFF
				#pragma	config CPB			= OFF
				#pragma	config WRT0			= OFF
				#pragma	config WRT1			= OFF
				#pragma	config WRT2			= OFF
				#pragma	config WRT3			= OFF
				#pragma	config WRTB			= OFF
				#pragma	config WRTC			= OFF
				#pragma	config WRTD			= OFF
				#pragma	config EBTR0		= OFF
				#pragma	config EBTR1		= OFF
				#pragma	config EBTR2		= OFF
				#pragma	config EBTR3		= OFF
				#pragma	config EBTRB		= OFF
			\endcode

		\section	Fuse4620	Specific FUSE settings
		
			\subsection		Oscillator4620 		Oscillator Selection
				\code
					OSC = LP					LP  
					OSC = XT					XT  
					OSC = HS					HS  
					OSC = RC					RC  
					OSC = EC					EC-OSC2 as Clock Out  
					OSC = ECIO6			EC-OSC2 as RA6  
					OSC = HSPLL			HS-PLL Enabled  
					OSC = RCIO6			RC-OSC2 as RA6  
					OSC = INTIO67			INTRC-OSC2 as RA6, OSC1 as RA7  
					OSC = INTIO7			INTRC-OSC2 as Clock Out, OSC1 as RA7
				\endcode

			\subsection		Fail4620				Fail-Safe Clock Monitor
				\code
					FCMEN = OFF		Disabled  
					FCMEN = ON		Enabled  
				\endcode

			\subsection		Internal4620 		Internal External Osc. Switch Over
				\code
					IESO = OFF		Disabled  
					IESO = ON		Enabled  
				\endcode

			\subsection		Power4620		Power-up Timer
				\code
					PWRT = ON		Enabled  
					PWRT = OFF		Disabled
				\endcode

			\subsection		Brown4620			Brown-out Reset:
				\code
					BOREN = OFF			SBOREN Disabled  
					BOREN = ON				SBOREN Enabled  
					BOREN = NOSLP		Enabled except Sleep, SBOREN Disabled  
					BOREN = SBORDIS	Enabled, SBOREN Disabled  
				\endcode

			\subsection		Brownss4620			Brown-out Voltage
				\code
					BORV = 0		Maximum setting  
					BORV = 1		  
					BORV = 2
					BORV = 3		Minimum setting  

			\subsection		Watchdogs4620 			Watchdog Timer
				\code
					WDT = OFF		Disabled  
					WDT = ON		Enabled  
			\endcode

			\subsection		Watchdogsss4620 		Watchdog Postscaler
				\code
					WDTPS = 1				1:1  
					WDTPS = 2				1:2  
					WDTPS = 4				1:4  
					WDTPS = 8				1:8  
					WDTPS = 16				1:16  
					WDTPS = 32				1:32  
					WDTPS = 64				1:64  
					WDTPS = 128			1:128  
					WDTPS = 256			1:256  
					WDTPS = 512			1:512  
					WDTPS = 1024			1:1024  
					WDTPS = 2048			1:2048  
					WDTPS = 4096			1:4096  
					WDTPS = 8192			1:8192  
					WDTPS = 16384		1:16384  
					WDTPS = 32768		1:32768  
			\endcode

			\subsection		MCLR4620 			MCLR Enable
				\code
					MCLRE = OFF	Disabled  
					MCLRE = ON		Enabled  
			\endcode

			\subsection		T14620 			T1 Oscillator Enable
				\code
					LPT1OSC = OFF	Disabled  
					LPT1OSC = ON		Enabled  
			\endcode

			\subsection		PORTB4620 			PORTB A/D Enable
				\code
					PBADEN = OFF		PORTB<4:0> digital on Reset  
					PBADEN = ON		PORTB<4:0> analog on Reset  
			\endcode

			\subsection		CCP24620 			CCP2 MUX
				\code
					CCP2MX = PORTBE	Multiplexed with RB3  
					CCP2MX = PORTC		Multiplexed with RC1  
			\endcode

			\subsection		Stackss4620 			Stack Overflow Reset
				\code
					STVREN = OFF		Disabled  
					STVREN = ON		Enabled  
			\endcode

			\subsection		Low4620ss 			Low Voltage ICSP
				\code
					LVP = OFF		Disabled  
					LVP = ON			Enabled  
			\endcode

			\subsection		XINSTas4620 			XINST Enable
				\code
					XINST = OFF		Disabled  
					XINST = ON		Enabled  
			\endcode

			\subsection		Background4620s 			Background Debugger Enable
				\code
					DEBUG = ON		Enabled  
					DEBUG = OFF		Disabled  
			\endcode

			\subsection	Codes4620		Code Protection bit Block 0
			\code
				CP0 = ON			Block 0 (000800-001FFFh) code-protected  
				CP0 = OFF		Block 0 (000800-001FFFh) not code-protected  
			\endcode

			\subsection	Code14620		Code Protection bit Block 1
			\code
				CP1 = ON			Block 1 (002000-003FFFh) code-protected  
				CP1 = OFF		Block 1 (002000-003FFFh) not code-protected  
			\endcode

			\subsection	Code24620		Code Protection bit Block 2
			\code
				CP2 = ON			Block 2 (004000-005FFFh) code-protected  
				CP2 = OFF		Block 2 (004000-005FFFh) not code-protected  
			\endcode

			\subsection	Code34620		Code Protection bit Block 3
			\code
				CP3 = ON			Block 3 (006000-007FFFh) code-protected  
				CP3 = OFF		Block 3 (006000-007FFFh) not code-protected  
			\endcode

			\subsection	Boots4620		Boot Block Code Protection bit
			\code
				CPB = ON			Boot block (000000-0007FFh) code-protected  
				CPB = OFF		Boot block (000000-0007FFh) not code-protected  
			\endcode

			\subsection	Datas4620		Data EEPROM Code Protection bit
			\code
				CPD = ON			Data EEPROM code-protected  
				CPD = OFF		Data EEPROM not code-protected  
			\endcode

			\subsection	Writesv4620		Write Protection bit Block 0
			\code
				WRT0 = ON		Block 0 (000800-001FFFh) write-protected  
				WRT0 = OFF		Block 0 (000800-001FFFh) not write-protected  
			\endcode

			\subsection	Write14620		Write Protection bit Block 1
			\code
				WRT1 = ON		Block 1 (002000-003FFFh) write-protected  
				WRT1 = OFF		Block 1 (002000-003FFFh) not write-protected  
			\endcode

			\subsection	Write24620		Write Protection bit Block 2
			\code
				WRT2 = ON		Block 2 (004000-005FFFh) write-protected  
				WRT2 = OFF		Block 2 (004000-005FFFh) not write-protected  
			\endcode

			\subsection	Write34620		Write Protection bit Block 3
			\code
				WRT3 = ON		Block 3 (006000-007FFFh) write-protected  
				WRT3 = OFF		Block 3 (006000-007FFFh) not write-protected  
			\endcode

			\subsection	Boot1s4620		Boot Block Write Protection bit
			\code
				WRTB = ON		Boot block (000000-0007FFh) write-protected  
				WRTB = OFF		Boot block (000000-0007FFh) not write-protected  
			\endcode

			\subsection	Configurationvs4620		Configuration Register Write Protection bit
			\code
				WRTC = ON		Configuration registers (300000-3000FFh) write-protected  
				WRTC = OFF		Configuration registers (300000-3000FFh) not write-protected  
			\endcode

			\subsection	Data1ve4620	Data EEPROM Write Protection bit
			\code
				WRTD = ON		Data EEPROM write-protected  
				WRTD = OFF		Data EEPROM not write-protected  
			\endcode

			\subsection	Tablevr4620		Table Read Protection bit Block 0
			\code
				EBTR0 = ON		Block 0 (000800-001FFFh) protected from table reads executed in other blocks  
				EBTR0 = OFF	Block 0 (000800-001FFFh) not protected from table reads executed in other blocks  
			\endcode

			\subsection	Table1vs4620		Table Read Protection bit Block 1
			\code
				EBTR1 = ON		Block 1 (002000-003FFFh) protected from table reads executed in other blocks  
				EBTR1 = OFF	Block 1 (002000-003FFFh) not protected from table reads executed in other blocks  
			\endcode

			\subsection	Table2saav4620		Table Read Protection bit Block 2
			\code
				EBTR2 = ON		Block 2 (004000-005FFFh) protected from table reads executed in other blocks  
				EBTR2 = OFF	Block 2 (004000-005FFFh) not protected from table reads executed in other blocks  
			\endcode

			\subsection	Table3sa4620		Table Read Protection bit Block 3
			\code
				EBTR3 = ON		Block 3 (006000-007FFFh) protected from table reads executed in other blocks  
				EBTR3 = OFF	Block 3 (006000-007FFFh) not protected from table reads executed in other blocks  
			\endcode

			\subsection	Boot2vsa4620		Boot Block Table Read Protection
			\code
				EBTRB = ON		Boot block (000000-0007FFh) protected from table reads executed in other blocks  
				EBTRB = OFF	Boot block (000000-0007FFh) not protected from table reads executed in other blocks  
			\endcode
*/


