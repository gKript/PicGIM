//
// pgim_event.h
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

/*!		\file			pgim_event.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_EVENT_H_
	#define _PGIM_EVENT_H_

	/*!
	 *	\brief	This is the initialization function of interrups handler module.
	 *	\warning		Internal use only.
	 *	\deprecated		Do not call directly. Already called in pg_initialize()
	 */
	void pg_event_init( void );
			
	#if ( PGIM_EVENTS == PG_ENABLE )

		/*!
		 *	\brief	Inside this variable resides in the name of the event detected by the automatically interrupt handler. \n Default is \ref PG_EVENT_CLEAR
		 */
		extern volatile char pg_event_name;

		/*!
		 * \brief	With this function you can clean the bit of the corresponding interrupt event.
		 * \param	int_event	The Define of the event you want to clean the bit. \n
		 *						example : \ref PG_EVENT_TMR0
			\return	Nothing.
		 */
		void pg_event_clear_bit						( char int_event );

		/*!
		 *	\brief		This is the function to enable or disable the interrupt events. 
		 *	\param		int_event	The Define of the event you want to clean the bit. \n
		 *						example : \ref PG_EVENT_TMR0
		 *  \param	int_state	The state of the interrupt. \n Only \ref PG_ENABLE or \ref PG_DISABLE
			\return		Nothing.
		 *	\warning	Only those listed as enabled in the public file : pgim_event_setup_public.h
		 */
		void pg_event_set					( char int_event , char int_state );
		
		#if ( PG_EVENT_AUTO_HANDLER == PG_ENABLE )

			/*!
			 *	\brief			This is the call for the Automatic Interrupt Handler.
				\return	
			 	\attention		Internal use only !
			 	\deprecated	Do not call directly. \n
			 */
		    char pg_event_auto_handler	    ( void );
		#else

			/*!
				\brief			This is the call for the user interrupt handler. \n The code for this function must be placed in the relative function in this file : pgim_interrupt_callbacks.c
			 	\attention		Internal use only !
			 	\deprecated		Do not call directly. \n
				\return	
			 */
//		    char pg_event_user_handler	    ( void );
		#endif

		/*!
			\brief	 		Interrupt Service Routine : The callback service
			\return			Nothing.
			\attention		Internal use only !
			\deprecated	Do not call directly. \n
		*/
		void	my_isr											( void );


		
		/*!
			\brief			This is the first and only one function called by my_isr(). Depending on the configuration, it calls pg_event_auto_handler()  or  pg_event_user_handler().
			\return			Nothing.
			\attention		Internal use only !
			\deprecated	Do not call directly. \n
		 */
		void pg_event_occurred	( void );


		/*!
		 *	\brief		This is the function to attach a callback to a specific event.
		 *	\param		event	The Define of the event you want to attach. \n
		 *						example : \ref PG_EVENT_TMR0
		 *  \param		void (*pg_event_callback)(void)		The callback pointer to attach to an event.
			\return		Nothing.
		 */
		void	pg_event_attach( int event , void (*pg_event_callback)(void) );

		#define		PG_EVENT_CLEAR						0			//!< This is the internal definition of the CLEAR interrupt flag
		#define		PG_EVENT_INT0						1			//!< This is the internal definition of the interrupt INT0
		#define		PG_EVENT_INT1						2			//!< This is the internal definition of the interrupt INT1
		#define		PG_EVENT_INT2						3			//!< This is the internal definition of the interrupt INT2
		#define		PG_EVENT_TMR0						4			//!< This is the internal definition of the interrupt TMR0
		#define		PG_EVENT_TMR1						5			//!< This is the internal definition of the interrupt TMR1
		#define		PG_EVENT_TMR2						6			//!< This is the internal definition of the interrupt TMR2
		#define		PG_EVENT_RB0						8			//!< This is the internal definition of the interrupt RB0
		#define		PG_EVENT_PSP						9			//!< This is the internal definition of the interrupt PSP
		#define		PG_EVENT_AD							10			//!< This is the internal definition of the interrupt AD
		#define		PG_EVENT_USARTRC					11			//!< This is the internal definition of the interrupt USARTRC
		#define		PG_EVENT_USARTTX					12			//!< This is the internal definition of the interrupt USARTTX
		#define		PG_EVENT_SSP						13			//!< This is the internal definition of the interrupt SSP
		#define		PG_EVENT_CCP1						14			//!< This is the internal definition of the interrupt CCP1
		#define		PG_EVENT_CCP2						15			//!< This is the internal definition of the interrupt CCP2
		#define		PG_EVENT_OSCF						16			//!< This is the internal definition of the interrupt OSCF
		#define		PG_EVENT_CM							17			//!< This is the internal definition of the interrupt CM
		#define		PG_EVENT_EE							18			//!< This is the internal definition of the interrupt EE
		#define		PG_EVENT_BCL						19			//!< This is the internal definition of the interrupt BCL
		#define		PG_EVENT_HLVD						20			//!< This is the internal definition of the interrupt HLVD

		#define		PG_EVENT_GLOBAL						100			//!< This is the internal definition of the GLOBAL interrupt
		#define		PG_EVENT_PERIPHERAL					101			//!< This is the internal definition of the PERIPHERAL interrupt
		
		#define		PG_EVENT_ANY						200			//!< This is the internal definition of the ANY interrupt events
		
		#define		PG_INTERRUPT_INT0_FLAG				INTCONbits.INT0IF			//!< This is the internal definition of the interrupt flag bit INT0
		#define		PG_INTERRUPT_INT0_ENABLE			INTCONbits.INT0IE			//!< This is the internal definition of the enable interrupt bit INT0
		#define		PG_INTERRUPT_INT1_FLAG				INTCON3bits.INT1IF			//!< This is the internal definition of the interrupt flag bit INT1
		#define		PG_INTERRUPT_INT1_ENABLE			INTCON3bits.INT1IE			//!< This is the internal definition of the enable interrupt bit	INT1
		#define		PG_INTERRUPT_INT2_FLAG				INTCON3bits.INT2IF			//!< This is the internal definition of the interrupt flag bit INT2
		#define		PG_INTERRUPT_INT2_ENABLE			INTCON3bits.INT2IE			//!< This is the internal definition of the enable interrupt bit INT2
		#define		PG_INTERRUPT_TMR0_FLAG				INTCONbits.TMR0IF			//!< This is the internal definition of the interrupt flag bit TMR0
		#define		PG_INTERRUPT_TMR0_ENABLE			INTCONbits.TMR0IE			//!< This is the internal definition of the enable interrupt bit TMR0
		#define		PG_INTERRUPT_TMR1_FLAG				PIR1bits.TMR1IF				//!< This is the internal definition of the interrupt flag bit TMR1
		#define		PG_INTERRUPT_TMR1_ENABLE			PIE1bits.TMR1IE			//!< This is the internal definition of the enable interrupt bit TMR1
		#define		PG_INTERRUPT_TMR2_FLAG				PIR1bits.TMR2IF				//!< This is the internal definition of the interrupt flag bit TMR2
		#define		PG_INTERRUPT_TMR2_ENABLE			PIE1bits.TMR2IE			//!< This is the internal definition of the enable interrupt bit TMR2
		#define		PG_INTERRUPT_RB0_FLAG				INTCONbits.RBIF				//!< This is the internal definition of the interrupt flag bit RB
		#define		PG_INTERRUPT_RB0_ENABLE				INTCONbits.RBIE			//!< This is the internal definition of the enable interrupt bit RB
		#define		PG_INTERRUPT_PSP_FLAG				PIR1bits.PSPIF				//!< This is the internal definition of the interrupt flag bit PSP
		#define		PG_INTERRUPT_PSP_ENABLE				PIE1bits.PSPIE			//!< This is the internal definition of the enable interrupt bit PSP
		#define		PG_INTERRUPT_AD_FLAG				PIR1bits.ADIF				//!< This is the internal definition of the interrupt flag bit AD
		#define		PG_INTERRUPT_AD_ENABLE				PIE1bits.ADIE			//!< This is the internal definition of the enable interrupt bit AD
		#define		PG_INTERRUPT_USARTRC_FLAG			PIR1bits.RCIF				//!< This is the internal definition of the interrupt flag bit RC
		#define		PG_INTERRUPT_USARTRC_ENABLE			PIE1bits.RCIE			//!< This is the internal definition of the enable interrupt bit RC
		#define		PG_INTERRUPT_USARTTX_FLAG			PIR1bits.TXIF				//!< This is the internal definition of the interrupt flag bit TX
		#define		PG_INTERRUPT_USARTTX_ENABLE			PIE1bits.TXIE			//!< This is the internal definition of the enable interrupt bit TX
		#define		PG_INTERRUPT_SSP_FLAG				PIR1bits.SSPIF				//!< This is the internal definition of the interrupt flag bit SSP
		#define		PG_INTERRUPT_SSP_ENABLE				PIE1bits.SSPIE			//!< This is the internal definition of the enable interrupt bit SSP
		#define		PG_INTERRUPT_CCP1_FLAG				PIR1bits.CCP1IF				//!< This is the internal definition of the interrupt flag bit CCP1
		#define		PG_INTERRUPT_CCP1_ENABLE			PIE1bits.CCP1IE			//!< This is the internal definition of the enable interrupt bit CCP1
		#define		PG_INTERRUPT_CCP2_FLAG				PIR2bits.CCP2IF				//!< This is the internal definition of the interrupt flag bit CCP2
		#define		PG_INTERRUPT_CCP2_ENABLE			PIE2bits.CCP2IE				//!< This is the internal definition of the enable interrupt bit CCP2
		#define		PG_INTERRUPT_OSCF_FLAG				PIR2bits.OSCFIF				//!< This is the internal definition of the interrupt flag bit OSCF
		#define		PG_INTERRUPT_OSCF_ENABLE			PIE2bits.OSCFIE			//!< This is the internal definition of the enable interrupt bit OSCF
		#define		PG_INTERRUPT_CM_FLAG				PIR2bits.CMIF				//!< This is the internal definition of the interrupt flag bit CM
		#define		PG_INTERRUPT_CM_ENABLE				PIE2bits.CMIE			//!< This is the internal definition of the enable interrupt bit CM
		#define		PG_INTERRUPT_EE_FLAG				PIR2bits.EEIF				//!< This is the internal definition of the interrupt flag bit EE
		#define		PG_INTERRUPT_EE_ENABLE				PIE2bits.EEIE			//!< This is the internal definition of the enable interrupt bit EE
		#define		PG_INTERRUPT_BCL_FLAG				PIR2bits.BCLIF				//!< This is the internal definition of the interrupt flag bit BCL
		#define		PG_INTERRUPT_BCL_ENABLE				PIE2bits.BCLIE			//!< This is the internal definition of the enable interrupt bit BCL
		#define		PG_INTERRUPT_HLVD_FLAG				PIR2bits.HLVDIF				//!< This is the internal definition of the interrupt flag bit HLDV
		#define		PG_INTERRUPT_HLVD_ENABLE			PIE2bits.HLVDIE			//!< This is the internal definition of the enable interrupt bit HLDV

		#define		PG_INTERRUPT_GLOBAL_ENABLE			INTCONbits.GIE			//!< This is the internal definition of the GLOBAL enable interrupt bit
		#define		PG_INTERRUPT_PERIPHERAL_ENABLE  	INTCONbits.PEIE			//!< This is the internal definition of the PERIPHERAL enable interrupt bit

		typedef		void (* pg_int0_cb_pointer)(void);
		typedef		void (* pg_int1_cb_pointer)(void);
		typedef		void (* pg_int2_cb_pointer)(void);
		typedef		void (* pg_tmr0_cb_pointer)(void);
		typedef		void (* pg_tmr1_cb_pointer)(void);
		typedef		void (* pg_tmr2_cb_pointer)(void);

		extern		pg_int0_cb_pointer pg_int0_callback;
		extern		pg_int1_cb_pointer pg_int1_callback;
		extern		pg_int2_cb_pointer pg_int2_callback;
		extern		pg_tmr0_cb_pointer pg_tmr0_callback;
		extern		pg_tmr1_cb_pointer pg_tmr1_callback;
		extern		pg_tmr2_cb_pointer pg_tmr2_callback;
	
	#endif
#endif /* _PGIM_EVENT_H_ */

/*!

	\page	HWI_interrupt		Interrupts

		\tableofcontents
	
		\image html Interrupts.png

 		\b PicGIM is able to handle interrupts of \b PIC18F easily and fully automatically \n
		We have chosen for this \e milestone, the first, to support interrupts without the management of priority. \n
		To do this pg_event_init() sets to 0 \e IPEN bit of the \e RCON register. <i> IPEN: Interrupt Priority Enable </i>
		
		\warning	If you choose to use the built-in manager \b YOU \b MUST \b NOT modify any register directly related to the hardware interrupt management.
		
		\todo 	In the next milestone [1.0] the interrupts module will support high and low priority.
 
		\htmlonly
		<br> <br>
		\endhtmlonly
		
		\section	iterruptconf	Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled and configured in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref interruptconfen  \n
					\n \n \n

				\arg \b pgim_event_setup_public.h : This is the main file to edit the parameters of this module. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref interdefinesauto  \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref interdefinesintern  \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref interdefinesextern  \n
					\n \n \n
					
				\arg \b pgim_interrupt_callbacks.c : where are collected all the \b callback \b routines. One for each type of event. \n
						In this file there is also the user space to code your own interrupts handler. \n
						This is only necessary if you do not want to use the automatic handler. \n \n						
					&nbsp;&nbsp;&nbsp;&nbsp; \ref interruptcallbackhowto  \n

					\n  &nbsp;&nbsp;&nbsp;&nbsp;
				
			\attention	For software reference, please read the documentation about \b pgim_event.h . \n
						This is \b not a file defined as \b public and therefore it would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing.
			</p>
			\n \n \n
							
			\subsection	interruptconfen	Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_EVENTS					PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Interrupts module enabled.
					\arg \b PG_DISABLE : Interrupts module disabled.
					\endcode
					
				\subsubsection	intmodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_EVENTS \n
					
			\subsection		interdefinesauto		Automatic Interrupts Handler
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_EVENT_AUTO_HANDLER   	PG_ENABLE
				\endcode
				\htmlonly
					These defines enable or disable the Automatic Interrupts Handler.<br>
					They must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Automatic Interrupts Handler enabled.
					\arg \b PG_DISABLE : Automatic Interrupts Handler disabled. So you must code your own handler. In this case, the automatic handler <b>will not be compiled</b>.
					
				By default is set to \b PG_ENABLE.
				
				\subsubsection	intmodautoref	References
					\li \e File : pgim_interrupt_callbacks.c 
					\li \e Reference : \ref PG_EVENT_AUTO_HANDLER 
					
				\note If you disable the automatic handler the interrupts will no longer be managed by PicGIM until you create your own manager in pg_event_user_handler() .
				
				\attention	Please note that in any case \b PicGIM will put my_isr() function in the interrupt vector. \n So upon receipt of an interrupt will be call my_isr() which will call the pg_event_occurred() that deals of calling the correct handler and to clean the bit of the event. \n You can see in the picture below &nbsp;&darr; \n If you want to completely manage the interrupts in autonomy is necessary to disable completely the module. \n \b See \b also \n &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \ref interruptconfen \n \image html callgraph_user_interrupt.png   	
				

				
				\htmlonly <br><br> \endhtmlonly

			\subsection		interdefinesextern	External interupts
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_EVENT_SET_INT0				PG_DISABLE
					#define PG_EVENT_SET_INT1				PG_DISABLE
					#define PG_EVENT_SET_INT2				PG_DISABLE
					#define PG_EVENT_SET_RB0				PG_DISABLE
				\endcode
				\htmlonly
					These defines enable or disable each external interrupts event.<br>
					They must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : enhanced mode enabled.
					\arg \b PG_DISABLE : enhanced mode disabled.
				
				\subsubsection	intmodextref	References
					\li \e File : pgim_event_setup_public.h \n
					\li \e Reference : \ref PG_EVENT_SET_INT0 \n
					\li \e Reference : \ref PG_EVENT_SET_INT1 \n
					\li \e Reference : \ref PG_EVENT_SET_INT2 \n
					\li \e Reference : \ref PG_EVENT_SET_RB0 \n

			\subsection		interdefinesintern		Internal Interrupts
				\htmlonly <hr> \endhtmlonly
				\code
					#define PG_EVENT_SET_TMR0				PG_DISABLE
					#define PG_EVENT_SET_TMR1				PG_DISABLE
					#define PG_EVENT_SET_TMR2				PG_DISABLE
					#define PG_EVENT_SET_AD					PG_DISABLE
					#define PG_EVENT_SET_USARTRC			PG_DISABLE
					#define PG_EVENT_SET_USARTTX			PG_DISABLE
					#define PG_EVENT_SET_SSP				PG_DISABLE
					#define PG_EVENT_SET_CCP1				PG_DISABLE
					#define PG_EVENT_SET_CCP2				PG_DISABLE
					#define PG_EVENT_SET_OSCF				PG_DISABLE
					#define PG_EVENT_SET_CM					PG_DISABLE
					#define PG_EVENT_SET_EE					PG_DISABLE
					#define PG_EVENT_SET_BCL				PG_DISABLE
				\endcode
				\htmlonly
					These defines enable or disable each internal interrupts event.<br>
					They must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : enhanced mode enabled.
					\arg \b PG_DISABLE : enhanced mode disabled.
					
				\subsubsection	intmodintref	References
					\li \e File : pgim_event_setup_public.h \n
					\li \e Reference : \ref PG_EVENT_SET_TMR0 \n
					\li \e Reference : \ref PG_EVENT_SET_TMR1 \n
					\li \e Reference : \ref PG_EVENT_SET_TMR2 \n
					\li \e Reference : \ref PG_EVENT_SET_AD \n
					\li \e Reference : \ref PG_EVENT_SET_USARTRC \n
					\li \e Reference : \ref PG_EVENT_SET_USARTTX \n
					\li \e Reference : \ref PG_EVENT_SET_SSP \n
					\li \e Reference : \ref PG_EVENT_SET_CCP1 \n
					\li \e Reference : \ref PG_EVENT_SET_CCP2 \n
					\li \e Reference : \ref PG_EVENT_SET_OSCF \n
					\li \e Reference : \ref PG_EVENT_SET_CM \n
					\li \e Reference : \ref PG_EVENT_SET_EE \n
					\li \e Reference : \ref PG_EVENT_SET_BCL \n
							
		\section	iterruptcsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n

			\htmlonly <br><br> \endhtmlonly

			\subsection	interruptprivfunc	Private functions
				\note With \b "private" we mean a function that should not be used by the user in its code. \n In this documentation the private functions are marked as \e Deprecate. \n \b PicGIM internally uses these functions to properly manage the module. \n Of course you are always free to use them if you think they are useful.

				\arg \b pg_event_init() : This is the initialization function of interrups handler module.
				\arg \b my_isr() : Interrupt Service Routine : The callback service.
				\arg \b pg_event_occurred() : This is the first and only one function called by my_isr(). Depending on the configuration, it calls pg_event_auto_handler()  or  pg_event_user_handler().
				\arg \b pg_event_clear_bit() : With this function you can clean the bit of the corresponding interrupt.
				\arg \b pg_event_auto_handler() : This is the call for the automatic interrupts handler. 
					
				\note	If you choose the user interrupts handler the private function pg_event_clear_bit() will be considered public.
				
				\htmlonly <br><br> \endhtmlonly
				
			\subsection	interruptpubfunc	Public functions
				\endcode
				
				\arg \b pg_event_set() : This is the function to enable or disable one single interrupt events. 
				\arg \b pg_event_user_handler() : This is the call for the user interrupts handler. The code for this function must be placed in the relative function in pgim_interrupt_callbacks.c  
				
				\endcode
				
				\note The pg_event_user_handler() function is necessary only if you do \b not \b want to use the automatic handler.
				
				\attention	Please note that in any case \b PicGIM will put my_isr() function in the interrupt vector. \n So upon receipt of an interrupt will be call my_isr() which will call the pg_event_occurred() that deals of calling the correct handler and to clean the bit of the event. \n If you want to completely manage the interrupts in autonomy is necessary to disable completely the module. \image html callgraph_user_interrupt.png   	
				\see \ref interruptconfen

			\htmlonly <br><br> \endhtmlonly
			
		\section	interruptcallbackhowto	How to use the interrupts callback routines
			\htmlonly <hr> \endhtmlonly
		
			\subsection	interruptcallbackintro	Introduction
				After set the interrupts you need to write the code to do what you wish for every single interrupt. \n
				The public file to be edited is pgim_interrupt_callbacks.c . \n
				You must identify the callback for the desired event. \n 
				For example if we want to use the Timer_0 interrupt the callback would be pg_interrupts_event_tmr0 () . \n
				We've highlighted the area where you enter the code with two lines of comment : \n \n
				\code 
					//------  T M R 0    -    P U T   Y O U R   C O D E   H E R E -----------------------------------


					//------------------------------------------------------------------------------------------
				\endcode
				
				\n For example, here is a code that will be executed every time there is an interrupt from \b Timer_0 device. \n \n
				
				\code 
					void	pg_interrupts_event_tmr0( void ) {
					//------  T M R 0    -    P U T   Y O U R   C O D E   H E R E -----------------------------------


						LED ^= 1;


					//------------------------------------------------------------------------------------------
					}
				\endcode
				
				\n 

				\htmlonly
					A led will blink. &nbsp;&nbsp; <image src="led.gif" border="0">
					<br>
					<br> 
					<hr> 
				\endhtmlonly
			
			\subsection	interruptcallbackreference		Callback references
				Here are the references for the interrupt callbacks. \n
				\b PicGIM compile only the callbacks of the events previously enabled. \n
				
				\see	\ref	interdefinesintern
				\see	\ref	interdefinesextern
			
				\subsubsection	inthowcbref	References
					\endhtmlonly
					References : 
					\arg \b pg_interrupts_event_int0() : This is the callback for the event \ref PG_EVENT_SET_INT0 . 
					\arg \b pg_interrupts_event_int1() : This is the callback for the event \ref PG_EVENT_SET_INT1 . 
					\arg \b pg_interrupts_event_int2() : This is the callback for the event \ref PG_EVENT_SET_INT2 . 
					\arg \b pg_interrupts_event_rb0() : This is the callback for the event \ref PG_EVENT_SET_RB0 . 
					\arg \b pg_interrupts_event_tmr0() : This is the callback for the event \ref PG_EVENT_SET_TMR0 . 
					\arg \b pg_interrupts_event_tmr1() : This is the callback for the event \ref PG_EVENT_SET_TMR1 . 
					\arg \b pg_interrupts_event_tmr2() : This is the callback for the event \ref PG_EVENT_SET_TMR2 . 
					\arg \b pg_interrupts_event_ad() : This is the callback for the event \ref PG_EVENT_SET_AD . 
					\arg \b pg_interrupts_event_usartrc() : This is the callback for the event \ref PG_EVENT_SET_USARTRC . 
					\arg \b pg_interrupts_event_usarttx() : This is the callback for the event \ref PG_EVENT_SET_USARTTX . 
					\arg \b pg_interrupts_event_ssp() : This is the callback for the event \ref PG_EVENT_SET_SSP . 
					\arg \b pg_interrupts_event_ccp1() : This is the callback for the event \ref PG_EVENT_SET_CCP1 . 
					\arg \b pg_interrupts_event_ccp2() : This is the callback for the event \ref PG_EVENT_SET_CCP2 . 
					\arg \b pg_interrupts_event_oscf() : This is the callback for the event \ref PG_EVENT_SET_OSCF . 
					\arg \b pg_interrupts_event_cm() : This is the callback for the event \ref PG_EVENT_SET_CM . 
					\arg \b pg_interrupts_event_ee() : This is the callback for the event \ref PG_EVENT_SET_CM . 
					\arg \b pg_interrupts_event_bcl() : This is the callback for the event \ref PG_EVENT_SET_BCL . 

			
		\section	intexampleuse	A code example

		\htmlonly
		Here is a simple example of how to use the module in your code. <br>
		\endhtmlonly

		\warning	In order to compile this example, the module must be enabled and properly configured.

		This example is developed on two files: \b main.c and pgim_interrupt_callbacks.c \n

		This is the code for main.c :
		\code
			...

			pg_event_set( PG_EVENT_ANY , PG_ENABLE );
			pg_event_set( PG_EVENT_TMR0 , PG_ENABLE );

			...
		\endcode

		and this is the code for the relative callback for the event tmr0 :
		\code
			...
			void	pg_interrupts_event_tmr0( void ) {
			//------  T M R 0    -    P U T   Y O U R   C O D E   H E R E -----------------------------------


				T_B1 ^= 1;


			//------------------------------------------------------------------------------------------
			}
			...
		\endcode

		In this example the state for the RB0 pin will be toggled.
 
		\htmlonly <br><br> \endhtmlonly

*/


