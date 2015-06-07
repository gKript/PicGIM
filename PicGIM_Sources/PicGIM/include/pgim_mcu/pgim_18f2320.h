/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f2320.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f2320_public.h

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
		\file		pgim_18f2320.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The private configuration file for the 18F2320 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_18F2320_PRIVATE_H_
	#define _PGIM_18F2320_PRIVATE_H_
	
	//---[ Internal Oscillator ]---
	#if ( PG_USE_INTERNAL_OSC == PG_ENABLE )
		#include "pgim_int_osc.h"
		#ifdef _GIM_H_
			#pragma	config OSC = INTIO2					//!< Internal oscillator, OSC1 as RA7, OSC2 as RA6  		
		#endif
		#undef	PG_CLOCK
		#define	PG_CLOCK 8.000								// Re-define new oscillator frequency
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
	#include ".\pgim_mcu\pgim_18f2320_public.h"
	//---[ END Public ]---

	//---[ Extended Instructions Set ]--- NOT SUPPORTED
	#ifdef _GIM_H_
		#if defined( __EXTENDED18__ )
			#error	PG_HS_PG This MCU don't support the Extended Instructions Set feature
		#endif
	#endif
	//---[ END Extended Instructions Set ]---
		
	//---[ Hardware Resources ]---
	#define		PG_PIN_NUMBER				28					//!<	The number of pins

	#define		PG_TCYCLEPERI				4					//!<	The number of cycles required for an instruction for the family PIC18
	#define		PG_MAX_OSC_FREQ				40.000				//!<	The maximum working frequency
	
	#define		PG_MAX_RAM					512					//!<	The maximum amount of RAM
	#define		PG_MAX_EEPROM				256					//!<	If ( PG_MAX_EEPROM == 0 ) there is no EEPROM memory
	
	#define		PG_MCU_SUPPLY_VOLT_MAX		5.50				//!<	The maximum power supply voltage
	#define		PG_MCU_SUPPLY_VOLT_MIN		2.00				//!<	The minimum power supply voltage
	
	#define		PG_ADC_RES_BITS				10					//!<	ADC resolution bits
	#define		PG_ADC_RES_STEPS			1024				//!<	ADC resolution steps.
	
	#define		PG_PWM_1_MODE				PG_STANDARD			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
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
	
	#define		PG_HW_PIN_SERIAL_TX			17					//!<	Serial(Uart)transmission hardware pin number
	#define		PG_HW_PIN_SERIAL_TX_N		RC6					//!<	Serial(Uart)transmission hardware pin name
	#define		PG_HW_PIN_SERIAL_RX			18					//!<	Serial(Uart)reception hardware pin number
	#define		PG_HW_PIN_SERIAL_RX_N		RC7					//!<	Serial(Uart)reception hardware pin name
	#define		PG_HW_PIN_SPI_SDI			15					//!<	SPI Input hardware pin number
	#define		PG_HW_PIN_SPI_SDI_N			RC4					//!<	SPI Input hardware pin name
	#define		PG_HW_PIN_SPI_SDO			16					//!<	SPI Output hardware pin number
	#define		PG_HW_PIN_SPI_SDO_N			RC5					//!<	SPI Output hardware pin name
	#define		PG_HW_PIN_SPI_SCK			14					//!<	SPI Clock hardware pin number
	#define		PG_HW_PIN_SPI_SCK_N			RC3					//!<	SPI Clock hardware pin name
	#define		PG_HW_PIN_SPI_SS			7					//!<	SPI Slave Select hardware pin number
	#define		PG_HW_PIN_SPI_SS_N			RA5					//!<	SPI Slave Select hardware pin name
	#define		PG_HW_PIN_IRQ_INT0			21					//!<	Event (IRQ) Int0 hardware pin number
	#define		PG_HW_PIN_IRQ_INT0_N		RB0					//!<	Event (IRQ) Int0 hardware pin name
	#define		PG_HW_PIN_IRQ_INT1			22					//!<	Event (IRQ) Int1 hardware pin number
	#define		PG_HW_PIN_IRQ_INT1_N		RB1					//!<	Event (IRQ) Int1 hardware pin name
	#define		PG_HW_PIN_IRQ_INT2			23					//!<	Event (IRQ) Int2 hardware pin number
	#define		PG_HW_PIN_IRQ_INT2_N		RB2					//!<	Event (IRQ) Int2 hardware pin name
	#define		PG_HW_PIN_PWM1				13					//!<	PWM1 output hardware pin number
	#define		PG_HW_PIN_PWM1_N			RC2					//!<	PWM1 output hardware pin name	
	#define		PG_HW_PIN_PWM2				12					//!<	PWM2 output hardware pin number
	#define		PG_HW_PIN_PWM2_N			RC1					//!<	PWM2 output hardware pin name
	//---[ END Hardware Resources ]---	
	
#endif /* _PGIM_18F2320_PRIVATE_H_ */

/*!	\page		MCU_PIC18F2320 	PIC18F2320 : Settings

		\brief	28-Pin High-Performance, Enhanced Flash Microcontrollers with 10-Bit A/D and nanoWatt Technology \n

		\htmlonly
			<table width="100%" border="0" >
				<tr align="center">
					<td><IMG src="18f28pin.jpg" align="center" border="0" ></td>
					<td><IMG src="18f28spin.jpg" align="center" border="0" ></td>
				</tr>
			</table>
			<big><h1 align="center">P I C 1 8 F 2 3 2 0</h1></big>
			<BR>
		\endhtmlonly

		\section	datasheet	MicroChip official datasheet

			\htmlonly
				We think that if you are reading this documentation you will certainly already decided the hardware part of your project.<br>
				However, for your convenience we put a link to the official datasheet from Microchip.
				<br><br>
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<A href="http://ww1.microchip.com/downloads/en/DeviceDoc/39599g.pdf" target="_blank" ><IMG src="icona-pdf.gif" align="center" border="0" ></A>
				<br><br><br><br>
			\endhtmlonly

		\section	Constant	Various constants

			\subsection		TCYCLEPERI		PG_TCYCLEPERI
			Is the number of cycles required for a single instruction for the family \a PIC18. This is  a constant.
			\code
				#define		PG_TCYCLEPERI		4
			\endcode

			\subsection		MAX_OSC_FREQ		PG_MAX_OSC_FREQ
			Is the maximum working frequency for this specific \a MCU. This is  a constant.
			\code
				#define		PG_MAX_OSC_FREQ		40.000
			\endcode

			\subsection		MAX_RAM		PG_MAX_RAM
			Is the maximum amount of RAM for this specific \a MCU. This is  a constant.
			\code
				#define		PG_MAX_RAM			512
			\endcode

			\subsection		PSUPPLY2320_VMAX		PG_MCU_SUPPLY_VOLT_MAX
				It is the maximum applicable power supply voltage of the MCU. \n
				For the precise voltage to use, refer to the datasheet from the previous chapter : \ref datasheet
				Also make sure that the voltage is enough for the clock frequency chosen.
				\code
					#define		PG_MCU_SUPPLY_VOLT_MAX			5.50
				\endcode

			\subsection		PSUPPLY2320_VMIN		PG_MCU_SUPPLY_VOLT_MIN
				It is the minimum applicable power supply voltage of the MCU. \n
				For the precise voltage to use, refer to the datasheet from the previous chapter : \ref datasheet
				Also make sure that the voltage is enough for the clock frequency chosen.
				\code
					#define		PG_MCU_SUPPLY_VOLT_MIN			2.00
				\endcode

		\section	SXINST	Extended Instruction Code
			\htmlonly
				<b>This MCU doesn't support this feature.</b> \a PicGim will produce an error if you try to enable it.
			\endhtmlonly

		\section	Default		Default FUSE configuration

			\code
				#pragma	config PLLDIV	= 5
				#pragma	config CPUDIV	= OSC1_PLL2
				#pragma	config OSC		= ECPLLIO_EC
				#pragma	config USBDIV	= 1
				#pragma	config FCMEN	= OFF
				#pragma	config IESO		= OFF
				#pragma	config VREGEN	= OFF
				#pragma	config BOR		= ON
				#pragma	config BORV		= 2
				#pragma	config WDT		= OFF
				#pragma	config WDTPS	= 32768
				#pragma	config MCLRE	= ON
				#pragma	config LPT1OSC	= OFF
				#pragma	config PBADEN	= OFF
				#pragma	config STVREN	= OFF
				#pragma	config LVP		= OFF
				#pragma	config XINST	= OFF
				#pragma	config DEBUG	= OFF
				#pragma	config CP0		= OFF
				#pragma	config CP1		= OFF
				#pragma	config CP2		= OFF
				#pragma	config CP3		= OFF
				#pragma	config CPB		= OFF
				#pragma	config WRT0		= OFF
				#pragma	config WRT1		= OFF
				#pragma	config WRT2		= OFF
				#pragma	config WRT3		= OFF
				#pragma	config WRTB		= OFF
				#pragma	config WRTC		= OFF
				#pragma	config WRTD		= OFF
				#pragma	config EBTR0	= OFF
				#pragma	config EBTR1	= OFF
				#pragma	config EBTR2	= OFF
				#pragma	config EBTR3	= OFF
				#pragma	config EBTRB	= OFF
			\endcode

		\section	Fuse	Specific FUSE settings

			\subsection		Oscillator Oscillator Selection

				\code
					OSC = LP			LP Oscillator
					OSC = XT			XT Oscillator
					OSC = HS			HS Oscillator
					OSC = EC			External Clock on OSC1, OSC2 as FOSC/4
					OSC = ECIO		External Clock on OSC1, OSC2 as RA6
					OSC = HSPLL	HS + PLL
					OSC = RCIO		External RC on OSC1, OSC2 as RA6
					OSC = INTIO2	Internal RC, OSC1 as RA7, OSC2 as RA6
					OSC = INTIO1	Internal RC, OSC1 as RA7, OSC2 as FOSC/4
					OSC = RC			External RC on OSC1, OSC2 as FOSC/4
				\endcode

			\subsection		Fail 	Fail Safe Clock Monitor
				\code
					FSCM = OFF		Disabled
					FSCM = ON		Enabled
				\endcode

			\subsection		Internal 	Internal External Osc. Switch Over
				\code
					IESO = OFF		Disabled
					IESO = ON		Enabled
				\endcode

			\subsection		Power 		Power up Timer
				\code
					PWRT = ON		Enabled
					PWRT = OFF		Disabled
				\endcode

			\subsection		Brown 		Brown out Reset
				\code
					BOR = OFF		SBOREN Disabled
					BOR = ON			SBOREN Enabled
				\endcode

			\subsection		Brown 	Brown out Voltage
				\code
					BORV = 45			Maximum setting
					BORV = 42
					BORV = 27
					BORV = 20			Minimum setting
				\endcode

			\subsection		Watchdog 	Watchdog Timer
				\code
					WDT = OFF		Disabled
					WDT = ON		Enabled
				\endcode

			\subsection		Watchdog 		Watchdog Postscaler:
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

			\subsection	MCLR		MCLR Pin Enable bit
			\code
				MCLRE = OFF		RE3 input pin enabled; MCLR disabled
				MCLRE = ON			MCLR pin enabled; RE3 input pin disabled
			\endcode

			\subsection		PORTB 		PORTB A/D Enable
				\code
					PBAD = DIG		PORTB<4:0> digital on Reset
					PBAD = ANA		PORTB<4:0> analog on Reset
				\endcode

			\subsection		CCP2 		CCP2 Pin Function
				\code
					CCP2MX = B3		RB3
					CCP2MX = OFF		RB3
					CCP2MX = C1		RC1
					CCP2MX = ON		RC1
				\endcode

			\subsection		Stack 		Stack Overflow Reset:
				\code
					STVR = OFF		Disabled
					STVR = ON		Enabled
				\endcode

			\subsection		Low 		Low Voltage ICSP
				\code
					LVP = OFF		Disabled
					LVP = ON			Enabled
				\endcode

			\subsection		Background 	Background Debugger Enable
				\code
					DEBUG = ON		Enabled
					DEBUG = OFF		Disabled
				\endcode

			\subsection	Code		Code Protection bit Block 0
			\code
				CP0 = ON			Block 0 (000800-001FFFh) code-protected
				CP0 = OFF		Block 0 (000800-001FFFh) not code-protected
			\endcode

			\subsection	Code1		Code Protection bit Block 1
			\code
				CP1 = ON			Block 1 (002000-003FFFh) code-protected
				CP1 = OFF		Block 1 (002000-003FFFh) not code-protected
			\endcode

			\subsection	Code2		Code Protection bit Block 2
			\code
				CP2 = ON			Block 2 (004000-005FFFh) code-protected
				CP2 = OFF		Block 2 (004000-005FFFh) not code-protected
			\endcode

			\subsection	Code3		Code Protection bit Block 3
			\code
				CP3 = ON			Block 3 (006000-007FFFh) code-protected
				CP3 = OFF		Block 3 (006000-007FFFh) not code-protected
			\endcode

			\subsection	Boot		Boot Block Code Protection bit
			\code
				CPB = ON			Boot block (000000-0007FFh) code-protected
				CPB = OFF		Boot block (000000-0007FFh) not code-protected
			\endcode

			\subsection	Data		Data EEPROM Code Protection bit
			\code
				CPD = ON			Data EEPROM code-protected
				CPD = OFF		Data EEPROM not code-protected
			\endcode

			\subsection	Write		Write Protection bit Block 0
			\code
				WRT0 = ON		Block 0 (000800-001FFFh) write-protected
				WRT0 = OFF		Block 0 (000800-001FFFh) not write-protected
			\endcode

			\subsection	Write1		Write Protection bit Block 1
			\code
				WRT1 = ON		Block 1 (002000-003FFFh) write-protected
				WRT1 = OFF		Block 1 (002000-003FFFh) not write-protected
			\endcode

			\subsection	Write2		Write Protection bit Block 2
			\code
				WRT2 = ON		Block 2 (004000-005FFFh) write-protected
				WRT2 = OFF		Block 2 (004000-005FFFh) not write-protected
			\endcode

			\subsection	Write3		Write Protection bit Block 3
			\code
				WRT3 = ON		Block 3 (006000-007FFFh) write-protected
				WRT3 = OFF		Block 3 (006000-007FFFh) not write-protected
			\endcode

			\subsection	Boot1		Boot Block Write Protection bit
			\code
				WRTB = ON		Boot block (000000-0007FFh) write-protected
				WRTB = OFF		Boot block (000000-0007FFh) not write-protected
			\endcode

			\subsection	Configuration		Configuration Register Write Protection bit
			\code
				WRTC = ON		Configuration registers (300000-3000FFh) write-protected
				WRTC = OFF		Configuration registers (300000-3000FFh) not write-protected
			\endcode

			\subsection	Data1	Data EEPROM Write Protection bit
			\code
				WRTD = ON		Data EEPROM write-protected
				WRTD = OFF		Data EEPROM not write-protected
			\endcode

			\subsection	Table		Table Read Protection bit Block 0
			\code
				EBTR0 = ON		Block 0 (000800-001FFFh) protected from table reads executed in other blocks
				EBTR0 = OFF	Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table1		Table Read Protection bit Block 1
			\code
				EBTR1 = ON		Block 1 (002000-003FFFh) protected from table reads executed in other blocks
				EBTR1 = OFF	Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table2		Table Read Protection bit Block 2
			\code
				EBTR2 = ON		Block 2 (004000-005FFFh) protected from table reads executed in other blocks
				EBTR2 = OFF	Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table3		Table Read Protection bit Block 3
			\code
				EBTR3 = ON		Block 3 (006000-007FFFh) protected from table reads executed in other blocks
				EBTR3 = OFF	Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Boot2		Boot Block Table Read Protection
			\code
				EBTRB = ON		Boot block (000000-0007FFh) protected from table reads executed in other blocks
				EBTRB = OFF	Boot block (000000-0007FFh) not protected from table reads executed in other blocks
			\endcode
*/


