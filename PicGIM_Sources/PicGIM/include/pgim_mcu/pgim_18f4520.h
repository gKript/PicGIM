/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f4520.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f4520_public.h

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
		\file		pgim_18f4520.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The private configuration file for the 18F4520 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_18F4520_PRIVATE_H_
	#define _PGIM_18F4520_PRIVATE_H_
	
	//---[ Internal Oscillator ]---
	#if defined( PG_DOXYGEN )
		#undef		PG_USE_INTERNAL_OSC
		#define		PG_USE_INTERNAL_OSC		PG_ENABLE
	#elif ( PGIM_ALL_MODULES_DISABLED == PG_ENABLE ) && ( PG_PROJECT_STATE == PG_DEBUG )
		#undef		PG_USE_INTERNAL_OSC
		#define		PG_USE_INTERNAL_OSC		PG_DISABLE
	#endif
	#if ( PG_USE_INTERNAL_OSC == PG_ENABLE )
		#include "pgim_int_osc.h"
		#ifdef _GIM_H_
			#pragma	config OSC = INTIO67						//!< Internal oscillator block, port function on RA6 and RA7    
		#endif
		#undef	PG_CLOCK
		#define	PG_CLOCK 8.000								//!< Re-define new oscillator frequency
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using INTERNAL oscillator requested by user ( PG_CLOCK [MHz] )
		#endif
	#else
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PG_HS_PG PG_HS_CORE Using EXTERNAL oscillator configured by user ( PG_CLOCK [MHz] )
		#endif
	#endif
	//---[ END Internal Oscillator ]---
	
	//---[ Public ]---
	#include ".\pgim_mcu\pgim_18f4520_public.h"
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
	
	#define		PG_MAX_RAM					1536				//!<	The maximum amount of RAM
	#define		PG_MAX_EEPROM				256					//!<	If ( PG_MAX_EEPROM == 0 ) there is no EEPROM memory
	
	#define		PG_MCU_SUPPLY_VOLT_MAX		5.50				//!<	The maximum power supply voltage
	#define		PG_MCU_SUPPLY_VOLT_MIN		2.00				//!<	The minimum power supply voltage
	
	#define		PG_ADC_RES_BITS				10					//!<	ADC resolution bits
	#define		PG_ADC_RES_STEPS			1024				//!<	ADC resolution steps.
	
	#define		PG_PWM_1_MODE				PG_ENHANCED			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_2_MODE				PG_STANDARD			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_FOSC_DIVIDER			4.000				//!<	Internal clock divider to drive timer
	#define		PG_PWM_2_MPLEX_AVAILABLE	PG_YES				//!<	Available output pin multiplexed with other pin
	
	#define		PG_SERIAL_TX_TRIS			TRISCbits.TRISC6	//!<	Tx pin of USART port
	#define		PG_SERIAL_RX_TRIS			TRISCbits.TRISC7	//!<	Rx pin of USART port
	
	#define		PG_SPI_SDO_TRIS				TRISCbits.TRISC5	//!<	SPI output; Set tris to '0' as output
	#define		PG_SPI_SDI_TRIS				TRISCbits.TRISC4	//!<	SPI input; Tris is automatically controlled by the SPI module
	#define		PG_SPI_SCK_TRIS				TRISCbits.TRISC3	//!<	SPI clock; Master mode: set tris to '0' as output; Slave mode: set tris to '1' as input;
	#define		PG_SPI_SS_TRIS				TRISAbits.TRISA5	//!<	SPI slave-select

	#define		PG_I2C_SDA_TRIS				TRISCbits.TRISC4	//!<	I2C data I/O
	#define		PG_I2C_SCL_TRIS				TRISCbits.TRISC3	//!<	I2C clock
	
	#define		PG_HW_PIN_SERIAL_TX			25					//!<	Serial(Uart)transmission hardware pin number
	#define		PG_HW_PIN_SERIAL_TX_N		RC6					//!<	Serial(Uart)transmission hardware pin name
	#define		PG_HW_PIN_SERIAL_RX			26					//!<	Serial(Uart)reception hardware pin number
	#define		PG_HW_PIN_SERIAL_RX_N		RC7					//!<	Serial(Uart)reception hardware pin name
	#define		PG_HW_PIN_SPI_SDI			23					//!<	SPI Input hardware pin number
	#define		PG_HW_PIN_SPI_SDI_N			RC4					//!<	SPI Input hardware pin name
	#define		PG_HW_PIN_SPI_SDO			24					//!<	SPI Output hardware pin number
	#define		PG_HW_PIN_SPI_SDO_N			RC5					//!<	SPI Output hardware pin name
	#define		PG_HW_PIN_SPI_SCK			18					//!<	SPI Clock hardware pin number
	#define		PG_HW_PIN_SPI_SCK_N			RC3					//!<	SPI Clock hardware pin name
	#define		PG_HW_PIN_SPI_SS			7					//!<	SPI Slave Select hardware pin number
	#define		PG_HW_PIN_SPI_SS_N			RA5					//!<	SPI Slave Select hardware pin name
	#define		PG_HW_PIN_IRQ_INT0			33					//!<	Event (IRQ) Int0 hardware pin number
	#define		PG_HW_PIN_IRQ_INT0_N		RB0					//!<	Event (IRQ) Int0 hardware pin name
	#define		PG_HW_PIN_IRQ_INT1			34					//!<	Event (IRQ) Int1 hardware pin number
	#define		PG_HW_PIN_IRQ_INT1_N		RB1					//!<	Event (IRQ) Int1 hardware pin name
	#define		PG_HW_PIN_IRQ_INT2			35					//!<	Event (IRQ) Int2 hardware pin number
	#define		PG_HW_PIN_IRQ_INT2_N		RB2					//!<	Event (IRQ) Int2 hardware pin name
	#define		PG_HW_PIN_PWM1				17					//!<	PWM1 output hardware pin number
	#define		PG_HW_PIN_PWM1_N			RC2					//!<	PWM1 output hardware pin name	
	#define		PG_HW_PIN_PWM2				16					//!<	PWM2 output hardware pin number
	#define		PG_HW_PIN_PWM2_N			RC1					//!<	PWM2 output hardware pin name
	//---[ END Hardware Resources ]---
	
#endif /* _PGIM_18F4520_PRIVATE_H_ */

/*!
	\page	MCU_PIC18F4520	PIC18F4520 : Settings

		\brief	40/44-Pin Enhanced Flash Microcontrollers with 10-Bit A/D and nanoWatt Technology \n

		\htmlonly
			<table width="100%" border="0" >
				<tr align="center">
					<td><IMG src="18f40pin.jpg" align="center" border="0" ></td>
					<td><IMG src="18f44tpin.jpg" align="center" border="0" ></td>
				</tr>
			</table>
			<big><h1 align="center">P I C 1 8 F 4 5 2 0</h1></big>
			<BR>
		\endhtmlonly

		\section	datasheet4520	MicroChip official datasheet

			\htmlonly
				We think that if you are reading this documentation you will certainly already decided the hardware part of your project.<br>
				However, for your convenience we put a link to the official datasheet from Microchip.
				<br><br>
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<A href="http://ww1.microchip.com/downloads/en/DeviceDoc/39631E.pdf" target="_blank" ><IMG src="icona-pdf.gif" align="center" border="0" ></A>
				<br><br><br><br>
			\endhtmlonly

		\section	Constant4520	Various constants

			\subsection		TCYCLEPERI4520		PG_TCYCLEPERI
			Is the number of cycles required for a single instruction for the family PIC18. This is  a constant.
			\code
				#define		PG_TCYCLEPERI		4
			\endcode

			\subsection		MAX_OSC_FREQ4520		PG_MAX_OSC_FREQ
			Is the maximum working frequency for this specific MCU. This is  a constant.
			\code
				#define		PG_MAX_OSC_FREQ		40.000
			\endcode

			\subsection		MAX_RAM4520		PG_MAX_RAM
			Is the maximum amount of RAM for this specific MCU. This is  a constant.
			\code
				#define		PG_MAX_RAM			1536
			\endcode

			\subsection		PSUPPLY4520_VMAX		PG_MCU_SUPPLY_VOLT_MAX
				Is the supply voltage of the MCU. This voltage is a reference for PicGIM but is not precise. \n
				For the precise voltage refer to the datasheet from the previous chapter : \ref datasheet
				\code
					#define		PG_MCU_SUPPLY_VOLT_MAX			5.50
				\endcode

			\subsection		PSUPPLY4520_VMIN		PG_MCU_SUPPLY_VOLT_MIN
				It is the minimum applicable power supply voltage of the MCU. \n
				For the precise voltage to use, refer to the datasheet from the previous chapter : \ref datasheet
				Also make sure that the voltage is enough for the clock frequency chosen.
				\code
					#define		PG_MCU_SUPPLY_VOLT_MIN			2.00
				\endcode
				
		\section	SXINST4520			Extended Instruction Code
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

		\section	Defaultasv4520		Default FUSE configuration

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
				#pragma	config EBTR0			= OFF
				#pragma	config EBTR1			= OFF
				#pragma	config EBTR2			= OFF
				#pragma	config EBTR3			= OFF
				#pragma	config EBTRB			= OFF
			\endcode

		\section	Fuse4520	Specific FUSE settings

			\subsection		Oscillator4520 		Oscillator Selection
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

			\subsection		Fail4520				Fail-Safe Clock Monitor
				\code
					FCMEN = OFF		Disabled
					FCMEN = ON		Enabled
				\endcode

			\subsection		Internal4520 		Internal External Osc. Switch Over
				\code
					IESO = OFF		Disabled
					IESO = ON		Enabled
				\endcode

			\subsection		Power4520		Power-up Timer
				\code
					PWRT = ON		Enabled
					PWRT = OFF		Disabled
				\endcode

			\subsection		Brownvda4520			Brown-out Reset:
				\code
					BOREN = OFF			SBOREN Disabled
					BOREN = ON				SBOREN Enabled
					BOREN = NOSLP		Enabled except Sleep, SBOREN Disabled
					BOREN = SBORDIS	Enabled, SBOREN Disabled
				\endcode

			\subsection		Brownas4520			Brown-out Voltage
				\code
					BORV = 0		Maximum setting
					BORV = 1
					BORV = 2
					BORV = 3		Minimum setting

			\subsection		Watchdog4520 			Watchdog Timer
				\code
					WDT = OFF		Disabled
					WDT = ON		Enabled
			\endcode

			\subsection		Watchdogas4520 		Watchdog Postscaler
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

			\subsection		MCLR4520 			MCLR Enable
				\code
					MCLRE = OFF	Disabled
					MCLRE = ON		Enabled
			\endcode

			\subsection		T14520 			T1 Oscillator Enable
				\code
					LPT1OSC = OFF	Disabled
					LPT1OSC = ON		Enabled
			\endcode

			\subsection		PORTB4520 			PORTB A/D Enable
				\code
					PBADEN = OFF		PORTB<4:0> digital on Reset
					PBADEN = ON		PORTB<4:0> analog on Reset
			\endcode

			\subsection		CCP24520 			CCP2 MUX
				\code
					CCP2MX = PORTBE	Multiplexed with RB3
					CCP2MX = PORTC		Multiplexed with RC1
			\endcode

			\subsection		Stack4520 			Stack Overflow Reset
				\code
					STVREN = OFF		Disabled
					STVREN = ON		Enabled
			\endcode

			\subsection		Low4520 			Low Voltage ICSP
				\code
					LVP = OFF		Disabled
					LVP = ON			Enabled
			\endcode

			\subsection		XINSTs4520 			XINST Enable
				\code
					XINST = OFF		Disabled
					XINST = ON		Enabled
			\endcode

			\subsection		Backgroundas4520 			Background Debugger Enable
				\code
					DEBUG = ON		Enabled
					DEBUG = OFF		Disabled
			\endcode

			\subsection	Codeasv4520		Code Protection bit Block 0
			\code
				CP0 = ON			Block 0 (000800-001FFFh) code-protected
				CP0 = OFF		Block 0 (000800-001FFFh) not code-protected
			\endcode

			\subsection	Code14520		Code Protection bit Block 1
			\code
				CP1 = ON			Block 1 (002000-003FFFh) code-protected
				CP1 = OFF		Block 1 (002000-003FFFh) not code-protected
			\endcode

			\subsection	Code24520		Code Protection bit Block 2
			\code
				CP2 = ON			Block 2 (004000-005FFFh) code-protected
				CP2 = OFF		Block 2 (004000-005FFFh) not code-protected
			\endcode

			\subsection	Code34520		Code Protection bit Block 3
			\code
				CP3 = ON			Block 3 (006000-007FFFh) code-protected
				CP3 = OFF		Block 3 (006000-007FFFh) not code-protected
			\endcode

			\subsection	Boot4520		Boot Block Code Protection bit
			\code
				CPB = ON			Boot block (000000-0007FFh) code-protected
				CPB = OFF		Boot block (000000-0007FFh) not code-protected
			\endcode

			\subsection	Data4520		Data EEPROM Code Protection bit
			\code
				CPD = ON			Data EEPROM code-protected
				CPD = OFF		Data EEPROM not code-protected
			\endcode

			\subsection	Write4520		Write Protection bit Block 0
			\code
				WRT0 = ON		Block 0 (000800-001FFFh) write-protected
				WRT0 = OFF		Block 0 (000800-001FFFh) not write-protected
			\endcode

			\subsection	Write14520		Write Protection bit Block 1
			\code
				WRT1 = ON		Block 1 (002000-003FFFh) write-protected
				WRT1 = OFF		Block 1 (002000-003FFFh) not write-protected
			\endcode

			\subsection	Write24520		Write Protection bit Block 2
			\code
				WRT2 = ON		Block 2 (004000-005FFFh) write-protected
				WRT2 = OFF		Block 2 (004000-005FFFh) not write-protected
			\endcode

			\subsection	Write34520		Write Protection bit Block 3
			\code
				WRT3 = ON		Block 3 (006000-007FFFh) write-protected
				WRT3 = OFF		Block 3 (006000-007FFFh) not write-protected
			\endcode

			\subsection	Boot1as4520		Boot Block Write Protection bit
			\code
				WRTB = ON		Boot block (000000-0007FFh) write-protected
				WRTB = OFF		Boot block (000000-0007FFh) not write-protected
			\endcode

			\subsection	Configurationa4520		Configuration Register Write Protection bit
			\code
				WRTC = ON		Configuration registers (300000-3000FFh) write-protected
				WRTC = OFF		Configuration registers (300000-3000FFh) not write-protected
			\endcode

			\subsection	Data1sdvd4520	Data EEPROM Write Protection bit
			\code
				WRTD = ON		Data EEPROM write-protected
				WRTD = OFF		Data EEPROM not write-protected
			\endcode

			\subsection	Tablesvb4520		Table Read Protection bit Block 0
			\code
				EBTR0 = ON		Block 0 (000800-001FFFh) protected from table reads executed in other blocks
				EBTR0 = OFF	Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table1ds4520		Table Read Protection bit Block 1
			\code
				EBTR1 = ON		Block 1 (002000-003FFFh) protected from table reads executed in other blocks
				EBTR1 = OFF	Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table24520		Table Read Protection bit Block 2
			\code
				EBTR2 = ON		Block 2 (004000-005FFFh) protected from table reads executed in other blocks
				EBTR2 = OFF	Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table34520		Table Read Protection bit Block 3
			\code
				EBTR3 = ON		Block 3 (006000-007FFFh) protected from table reads executed in other blocks
				EBTR3 = OFF	Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Boot2svd4520		Boot Block Table Read Protection
			\code
				EBTRB = ON		Boot block (000000-0007FFh) protected from table reads executed in other blocks
				EBTRB = OFF	Boot block (000000-0007FFh) not protected from table reads executed in other blocks
			\endcode
*/


