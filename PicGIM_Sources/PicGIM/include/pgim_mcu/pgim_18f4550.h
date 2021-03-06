/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_18f4550.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (AsYntote) - Corrado Tumiati (SkyMatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_18f4550_public.h

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
		\file		pgim_18f4550.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		The private configuration file for the 18F4550 uController.
		\author		Danilo Zannoni (AsYntote)
		\author		Corrado Tumiati (SkyMatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_18F4550_PRIVATE_H_
	#define _PGIM_18F4550_PRIVATE_H_

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
			#pragma	config FOSC = INTOSCIO_EC				//!< Internal oscillator, port function on RA6, EC (External Clock) used by USB  
		#endif
		#undef	PG_CLOCK
		#define	PG_CLOCK 8000000							//!< Re-define new oscillator frequency
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PicGIM >>> Core >>> Using INTERNAL oscillator requested by user ( PG_CLOCK [Hz] )
		#endif
	#else
		#if	defined( _GIM_H_ ) && PG_VERBOSE == PG_ENABLE
			#warning	PicGIM >>> Core >>> Using EXTERNAL oscillator configured by user ( PG_CLOCK [Hz] )
		#endif
	#endif
	//---[ END Internal Oscillator ]---
	
	//---[ Public ]---
	#include ".\pgim_mcu\pgim_18f4550_public.h"
	//---[ END Public ]---
	
	//---[ Extended Instructions Set ]--- NOT SUPPORTED
	#ifdef _GIM_H_
		#if defined( __EXTENDED18__ )
			#error	PicGIM >>> This MCU don't support the Extended Instructions Set feature
		#endif
	#endif
	//---[ END Extended Instructions Set ]---
	
	//---[ Hardware Resources ]---
	#define		PG_PIN_NUMBER				40					//!<	The number of pins

	#define		PG_TCYCLEPERI				4					//!<	The number of cycles required for an instruction for the family PIC18
	#define		PG_MAX_OSC_FREQ				40.000				//!<	The maximum working frequency [Hz] for this specific processor
	
	#define		PG_MAX_RAM					2048				//!<	The maximum amount of RAM for this specific processor
	#define		PG_MAX_EEPROM				256					//!<	If ( PG_MAX_EEPROM == 0 ) there is no EEPROM memory

	#define		PG_MCU_SUPPLY_VOLT_MAX		5.50				//!<	The maximum power supply voltage [V]
	#define		PG_MCU_SUPPLY_VOLT_MIN		2.00				//!<	The minimum power supply voltage [V]
	
	#define		PG_ADC_RES_BITS				10					//!<	ADC resolution bits
	#define		PG_ADC_RES_STEPS			1024				//!<	ADC resolution steps.
	
	#define		PG_PWM_1_MODE				PG_ENHANCED			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_2_MODE				PG_STANDARD			//!<	Available mode: PG_NONE, PG_STANDARD or PG_ENHANCED
	#define		PG_PWM_FOSC_DIVIDER			4					//!<	Internal clock divider to drive timer
	
	#define		PG_SERIAL_TX_TRIS			TRISCbits.TRISC6	//!<	Tx pin of USART port
	#define		PG_SERIAL_RX_TRIS			TRISCbits.TRISC7	//!<	Rx pin of USART port
	
	#define		PG_SPI_SDO_TRIS				TRISCbits.TRISC7	//!<	SPI output; Set tris to '0' as output
	#define		PG_SPI_SDI_TRIS				TRISBbits.TRISB0	//!<	SPI input; Tris is automatically controlled by the SPI module
	#define		PG_SPI_SCK_TRIS				TRISBbits.TRISB1	//!<	SPI clock; Master mode: set tris to '0' as output; Slave mode: set tris to '1' as input;
	#define		PG_SPI_SS_TRIS				TRISAbits.TRISA5	//!<	SPI slave-select

	#define		PG_I2C_SDA_TRIS				TRISBbits.TRISB0	//!<	I2C data I/O
	#define		PG_I2C_SCL_TRIS				TRISBbits.TRISB1	//!<	I2C clock
	
	#define		PG_HW_PIN_SERIAL_TX			25					//!<	Serial(Uart)transmission hardware pin number
	#define		PG_HW_PIN_SERIAL_TX_N		RC6					//!<	Serial(Uart)transmission hardware pin name
	#define		PG_HW_PIN_SERIAL_RX			26					//!<	Serial(Uart)reception hardware pin number
	#define		PG_HW_PIN_SERIAL_RX_N		RC7					//!<	Serial(Uart)reception hardware pin name
	#define		PG_HW_PIN_SPI_SDI			33					//!<	SPI Input hardware pin number
	#define		PG_HW_PIN_SPI_SDI_N			RB0					//!<	SPI Input hardware pin name
	#define		PG_HW_PIN_SPI_SDO			26					//!<	SPI Output hardware pin number
	#define		PG_HW_PIN_SPI_SDO_N			RC7					//!<	SPI Output hardware pin name
	#define		PG_HW_PIN_SPI_SCK			34					//!<	SPI Clock hardware pin number
	#define		PG_HW_PIN_SPI_SCK_N			RB1					//!<	SPI Clock hardware pin name
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

	#define		PG_HW_PIN_USB_DPOS			24					//!<	USB Positive Data hardware pin number
	#define		PG_HW_PIN_USB_DPOS_N		RC5					//!<	USB Positive Data hardware pin name
	#define		PG_HW_PIN_USB_DNEG			23					//!<	USB Negative Data hardware pin number
	#define		PG_HW_PIN_USB_DNEG_N		RC4					//!<	USB Negative Data hardware pin name
	//---[ END Hardware Resources ]---
	
#endif /* _PGIM_18F4550_PRIVATE_H_ */

/*!
	\page	MCU_PIC18F4550	PIC18F4550 : Settings

		\brief	40/44-Pin, High-Performance, Enhanced Flash, USB Microcontrollers with nanoWatt Technology \n

		\htmlonly
			<table width="100%" border="0" >
				<tr align="center">
					<td><IMG src="18f40pin.jpg" align="center" border="0" ></td>
					<td><IMG src="18f44tpin.jpg" align="center" border="0" ></td>
				</tr>
			</table>
			<big><h1 align="center">P I C 1 8 F 4 5 5 0</h1></big>
			<BR>
		\endhtmlonly

		\section	datasheet4550	MicroChip official datasheet

			\htmlonly
				We think that if you are reading this documentation you will certainly already decided the hardware part of your project.<br>
				However, for your convenience we put a link to the official datasheet from Microchip.
				<br><br>
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<A href="http://ww1.microchip.com/downloads/en/DeviceDoc/39632e.pdf" target="_blank" ><IMG src="icona-pdf.gif" align="center" border="0" ></A>
				<br><br><br><br>
			\endhtmlonly

		\section	Constant4550	Various constants

			\subsection		TCYCLEPERI4550		PG_TCYCLEPERI
			Is the number of cycles required for a single instruction for the family \a PIC18. This is  a constant.
			\code
				#define		PG_TCYCLEPERI		4
			\endcode

			\subsection		MAX_OSC_FREQ4550		PG_MAX_OSC_FREQ
			Is the maximum working frequency for this specific \a MCU. This is  a constant.
			\code
				#define		PG_MAX_OSC_FREQ		48.000
			\endcode

			\subsection		MAX_RAM4550		PG_MAX_RAM
			Is the maximum amount of RAM for this specific \a MCU. This is  a constant.
			\code
				#define		PG_MAX_RAM			2048
			\endcode

			\subsection		PSUPPLY4550_VMAX		PG_MCU_SUPPLY_VOLT_MAX
				Is the supply voltage of the MCU. This voltage is a reference for PicGIM but is not precise. \n
				For the precise voltage refer to the datasheet from the previous chapter : \ref datasheet
				\code
					#define		PG_MCU_SUPPLY_VOLT_MAX			5.50
				\endcode

			\subsection		PSUPPLY4550_VMIN		PG_MCU_SUPPLY_VOLT_MIN
				It is the minimum applicable power supply voltage of the MCU. \n
				For the precise voltage to use, refer to the datasheet from the previous chapter : \ref datasheet
				Also make sure that the voltage is enough for the clock frequency chosen.
				\code
					#define		PG_MCU_SUPPLY_VOLT_MIN			2.00
				\endcode
				
		\section	SXINST4550	Extended Instruction Code
			\htmlonly
				<b>This MCU doesn't support this feature.</b> \a PicGim will produce an error if you try to enable it.
			\endhtmlonly

		\section	Default4550		Default FUSE configuration

			\code
				#pragma	config PLLDIV	= 5
				#pragma	config CPUDIV	= OSC1_PLL2
				#pragma	config FOSC		= ECPLLIO_EC
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

		\section	Fuse4550	Specific FUSE settings

			\subsection	PLL4550		PLL Prescaler Selection bits
			\code
				PLLDIV = 1		No prescale (4 MHz oscillator input drives PLL directly)
				PLLDIV = 2		Divide by 2 (8 MHz oscillator input)
				PLLDIV = 3		Divide by 3 (12 MHz oscillator input)
				PLLDIV = 4		Divide by 4 (16 MHz oscillator input)
				PLLDIV = 5		Divide by 5 (20 MHz oscillator input)
				PLLDIV = 6		Divide by 6 (24 MHz oscillator input)
				PLLDIV = 10		Divide by 10 (40 MHz oscillator input)
				PLLDIV = 12		Divide by 12 (48 MHz oscillator input)
			\endcode

			\subsection	CPU4550 		CPU System Clock Postscaler
			\code
				CPUDIV = OSC1_PLL2		[OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
				CPUDIV = OSC2_PLL3		[OSC1/OSC2 Src: /2][96 MHz PLL Src: /3]
				CPUDIV = OSC3_PLL4		[OSC1/OSC2 Src: /3][96 MHz PLL Src: /4]
				CPUDIV = OSC4_PLL6		[OSC1/OSC2 Src: /4][96 MHz PLL Src: /6]
			\endcode

			\subsection	USB4550 		USB Clock Selection bit (used in Full Speed USB mode only; UCFG:FSEN = 1):
			\code
				USBDIV = 1		USB clock source comes directly from the primary oscillator block with no postscale
				USBDIV = 2		USB clock source comes from the 96 MHz PLL divided by 2
			\endcode

			\subsection	Oscillator4550 		Oscillator Selection bits:
			\code
				FOSC = XT_XT				XT oscillator, XT used by USB
				FOSC = XTPLL_XT			XT oscillator, PLL enabled, XT used by USB
				FOSC = ECIO_EC			External clock, port function on RA6, EC used by USB
				FOSC = EC_EC				External clock, CLKOUT on RA6, EC used by USB
				FOSC = ECPLLIO_EC		External clock, PLL enabled, port function on RA6, EC used by USB
				FOSC = ECPLL_EC		External clock, PLL enabled, CLKOUT on RA6, EC used by USB
				FOSC = INTOSCIO_EC	Internal oscillator, port function on RA6, EC used by USB
				FOSC = INTOSC_EC		Internal oscillator, CLKOUT on RA6, EC used by USB
				FOSC = INTOSC_XT		Internal oscillator, XT used by USB
				FOSC = INTOSC_HS		Internal oscillator, HS used by USB
				FOSC = HS					HS oscillator, HS used by USB
				FOSC = HSPLL_HS		HS oscillator, PLL enabled, HS used by USB
			\endcode

			\subsection	Fail-Safe4550	Fail-Safe Clock Monitor Enable bit
			\code
				FCMEN = OFF	Fail-Safe Clock Monitor disabled
				FCMEN = ON	Fail-Safe Clock Monitor enabled
			\endcode

			\subsection	Internal4550		Internal/External Oscillator Switchover bit
			\code
				IESO = OFF		Oscillator Switchover mode disabled
				IESO = ON		Oscillator Switchover mode enabled
			\endcode

			\subsection	Power4550		Power-up Timer Enable bit
			\code
				PWRT = ON		PWRT enabled
				PWRT = OFF		PWRT disabled
			\endcode

			\subsection		Brown4550		Brown-out Reset Enable bits
			\code
				BOR = OFF				Brown-out Reset disabled in hardware and software
				BOR = SOFT				Brown-out Reset enabled and controlled by software (SBOREN is enabled)
				BOR = ON_ACTIVE	Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
				BOR = ON					Brown-out Reset enabled in hardware only (SBOREN is disabled)
			\endcode

			\subsection		Brownv4550		Brown-out Voltage bits
			\code
				BORV = 0		Maximum setting
				BORV = 1
				BORV = 2
				BORV = 3		Minimum setting
			\endcode

			\subsection	USBV		USB Voltage Regulator Enable bit
			\code
				VREGEN = OFF		USB voltage regulator disabled
				VREGEN = ON		USB voltage regulator enabled
			\endcode

			\subsection	Watchdog4550		Watchdog Timer Enable bit
			\code
				WDT = OFF			HW Disabled - SW Controlled
				WDT = ON			HW Enabled - SW Disabled
			\endcode

			\subsection	WatchdogT4550		Watchdog Timer Postscale Select bits
			\code
				WDTPS = 1			1:1
				WDTPS = 2			1:2
				WDTPS = 4			1:4
				WDTPS = 8			1:8
				WDTPS = 16			1:16
				WDTPS = 32			1:32
				WDTPS = 64			1:64
				WDTPS = 128		1:128
				WDTPS = 256		1:256
				WDTPS = 512		1:512
				WDTPS = 1024		1:1024
				WDTPS = 2048		1:2048
				WDTPS = 4096		1:4096
				WDTPS = 8192		1:8192
				WDTPS = 16384	1:16384
				WDTPS = 32768	1:32768
			\endcode

			\subsection	MCLR4550		MCLR Pin Enable bit
			\code
				MCLRE = OFF		RE3 input pin enabled; MCLR disabled
				MCLRE = ON			MCLR pin enabled; RE3 input pin disabled
			\endcode

			\subsection		LowP4550	Low-Power Timer 1 Oscillator Enable bit
			\code
				LPT1OSC = OFF		Timer1 configured for higher power operation
				LPT1OSC = ON			Timer1 configured for low-power operation
			\endcode

			\subsection	PORTB4550		PORTB A/D Enable bit
			\code
				PBADEN = OFF		PORTB<4:0> pins are configured as digital I/O on Reset
				PBADEN = ON		PORTB<4:0> pins are configured as analog input channels on Reset
			\endcode

			\subsection	CCP24550		CCP2 MUX bit
			\code
				CCP2MX = OFF		CCP2 input/output is multiplexed with RB3
				CCP2MX = ON		CCP2 input/output is multiplexed with RC1
			\endcode

			\subsection	Stack4550		Stack Full/Underflow Reset Enable bit
			\code
				STVREN = OFF		Stack full/underflow will not cause Reset
				STVREN = ON		Stack full/underflow will cause Reset
			\endcode

			\subsection		SingleSingle-Supply4550		 ICSP Enable bit
			\code
				LVP = OFF		Single-Supply ICSP disabled
				LVP = ON			Single-Supply ICSP enabled
			\endcode

			\subsection	Dedicated4550		Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit
			\code
				ICPRT = OFF		ICPORT disabled
				ICPRT = ON		ICPORT enabled
			\endcode

			\subsection	Extended4550		Extended Instruction Set Enable bit
			\code
				XINST = OFF		Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
				XINST = ON		Instruction set extension and Indexed Addressing mode enabled
			\endcode

			\subsection	Background4550		Background Debugger Enable bit
			\code
				DEBUG = ON	Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
				DEBUG = OFF	Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
			\endcode

			\subsection	Code4550		Code Protection bit Block 0
			\code
				CP0 = ON			Block 0 (000800-001FFFh) code-protected
				CP0 = OFF		Block 0 (000800-001FFFh) not code-protected
			\endcode

			\subsection	Code14550		Code Protection bit Block 1
			\code
				CP1 = ON			Block 1 (002000-003FFFh) code-protected
				CP1 = OFF		Block 1 (002000-003FFFh) not code-protected
			\endcode

			\subsection	Code24550		Code Protection bit Block 2
			\code
				CP2 = ON			Block 2 (004000-005FFFh) code-protected
				CP2 = OFF		Block 2 (004000-005FFFh) not code-protected
			\endcode

			\subsection	Code34550		Code Protection bit Block 3
			\code
				CP3 = ON			Block 3 (006000-007FFFh) code-protected
				CP3 = OFF		Block 3 (006000-007FFFh) not code-protected
			\endcode

			\subsection	Boot4550		Boot Block Code Protection bit
			\code
				CPB = ON			Boot block (000000-0007FFh) code-protected
				CPB = OFF		Boot block (000000-0007FFh) not code-protected
			\endcode

			\subsection	Data4550		Data EEPROM Code Protection bit
			\code
				CPD = ON			Data EEPROM code-protected
				CPD = OFF		Data EEPROM not code-protected
			\endcode

			\subsection	Write4550		Write Protection bit Block 0
			\code
				WRT0 = ON		Block 0 (000800-001FFFh) write-protected
				WRT0 = OFF		Block 0 (000800-001FFFh) not write-protected
			\endcode

			\subsection	Write14550		Write Protection bit Block 1
			\code
				WRT1 = ON		Block 1 (002000-003FFFh) write-protected
				WRT1 = OFF		Block 1 (002000-003FFFh) not write-protected
			\endcode

			\subsection	Write24550		Write Protection bit Block 2
			\code
				WRT2 = ON		Block 2 (004000-005FFFh) write-protected
				WRT2 = OFF		Block 2 (004000-005FFFh) not write-protected
			\endcode

			\subsection	Write34550		Write Protection bit Block 3
			\code
				WRT3 = ON		Block 3 (006000-007FFFh) write-protected
				WRT3 = OFF		Block 3 (006000-007FFFh) not write-protected
			\endcode

			\subsection	Boot14550		Boot Block Write Protection bit
			\code
				WRTB = ON		Boot block (000000-0007FFh) write-protected
				WRTB = OFF		Boot block (000000-0007FFh) not write-protected
			\endcode

			\subsection	Configurationsvs4550		Configuration Register Write Protection bit
			\code
				WRTC = ON		Configuration registers (300000-3000FFh) write-protected
				WRTC = OFF		Configuration registers (300000-3000FFh) not write-protected
			\endcode

			\subsection	Data14550	Data EEPROM Write Protection bit
			\code
				WRTD = ON		Data EEPROM write-protected
				WRTD = OFF		Data EEPROM not write-protected
			\endcode

			\subsection	Table4550		Table Read Protection bit Block 0
			\code
				EBTR0 = ON		Block 0 (000800-001FFFh) protected from table reads executed in other blocks
				EBTR0 = OFF	Block 0 (000800-001FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table14550		Table Read Protection bit Block 1
			\code
				EBTR1 = ON		Block 1 (002000-003FFFh) protected from table reads executed in other blocks
				EBTR1 = OFF	Block 1 (002000-003FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table24550		Table Read Protection bit Block 2
			\code
				EBTR2 = ON		Block 2 (004000-005FFFh) protected from table reads executed in other blocks
				EBTR2 = OFF	Block 2 (004000-005FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Table34550		Table Read Protection bit Block 3
			\code
				EBTR3 = ON		Block 3 (006000-007FFFh) protected from table reads executed in other blocks
				EBTR3 = OFF	Block 3 (006000-007FFFh) not protected from table reads executed in other blocks
			\endcode

			\subsection	Boot2s4550		Boot Block Table Read Protection
			\code
				EBTRB = ON		Boot block (000000-0007FFh) protected from table reads executed in other blocks
				EBTRB = OFF	Boot block (000000-0007FFh) not protected from table reads executed in other blocks
			\endcode
*/


