//
// pgim_doxygen.h
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

/*!		
	\file			pgim_doxygen.h
	\version		0.5-0
	\date			2002 - 2014
	\brief			
	\details		
	\author			Danilo Zannoni (AsYntote)
	\author			Corrado Tumiati (SkyMatrix)
	\copyright		PicGIM is under the terms of the GNU General Public License v3<BR>
						[ \ref LicenseGPLV3 ]
	\note			This file does not contain any line of code. \n It contains only formatted for Doxygen documentation.
	\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

//----------------------------------------------------------------------------
//	This file only serve for the automated documentation from doxygen 
//----------------------------------------------------------------------------

/*!	\mainpage

			\htmlonly
				<BR><BR>
				<table width="100%" border="0" >
					<tr align="center">
						<td><IMG src="WeDOC_documentation.png" align="center" border="0" ></td>
					</tr>
				<table width="100%" border="0" >
					<tr align="center">
						<td width="30%" ><IMG src="18f44tpin_small_ds.png" align="center" border="0" ></td>
						<td width="40%" ><IMG src="Logo_gKript_site_new_medium.png" align="center" border="0" ></td>
						<td width="30%" ><IMG src="18f28pin_small_ds.png" align="center" border="0" ></td>
					</tr>
				</table>
				<br>
				<h1 align="center">PicGIM - Generic Information Manager</h1>
				<h2 align="center">for Microchip<small>&#8482;</small> PIC18<small>&reg;</small> microcontrollers</h2>
				<br>
				<h1 align="center">PicGIM is a part of <a href="http://www.gkript.org/index.php/news/12-wepic" target="_blank"><IMG src="WePIC_documentation_small.png"  border="0" width="105" height="28"></a> project</h1>
				<br>
			\endhtmlonly

			\section	intro_sec 	Introduction
				\htmlonly
					<h3>PicGIM Documentation Milestone 0.5</h3>
					gKript.org &copy; Copyright 2002, 2014<BR>
					Danilo Zannoni (<i>AsYntote</i>) - Corrado Tumiati (<i>SkyMatrix</i>)<BR>
					<i>PicGIM<i> is part of <i>We.PIC</i> project by <i>gKript.org</i>. <BR><BR>
				\endhtmlonly
					
			\section	main_lic		Licenses
				\htmlonly 
					<i>We.PIC</i> project is under the terms of <i> \endhtmlonly \ref WPlicTesto \htmlonly </i><BR><BR>
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<image src="gplv3-127x51.png" border="0" /><BR><BR>
					Reffer to \endhtmlonly \subpage LicenseGPLV3 \htmlonly <br><br>
					<hr>
					<h3>GNU FDL Version 1.3</h3>
	<pre>Copyright (C)  2014  gKript.org
	Permission is granted to copy, distribute and/or modify this document
	under the terms of the GNU Free Documentation License, Version 1.3
	or any later version published by the Free Software Foundation;
	with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
	A copy of the license is included in the section entitled "GNU
	Free Documentation License".
	</pre>
	Here the link  : \endhtmlonly \ref WDlicTesto \htmlonly <BR><BR>
<hr>
<BR>
				\endhtmlonly

			\section	Cosae		What is PicGIM
				<p>
					\b PicGIM is a <i>"modular library from scratch"</i> \n
					\b PicGIM is developed to work with \b PIC18F \b MCU family only and with \b C18 compiler. \n
					\b PicGIM will compile only the modules enabled. \n
					Through a set of public files, you can configure PicGIM molding it to your project having the most help in programming with a minimum amount of program memory and ram. \n
					Compiling \b PicGIM only with compulsory modules only takes about <b>250 bytes of program memory</b>. \n 
					It is compatible with <b>Microchip MPLAB 8</b> and with the new <b>Microchip MPLAB X</b>. \n
					One of the advantages of \b PicGIM is just to work with a <b>MICROCHIP STANDARD ENVIRONMENT.</b> \n
					You are completely free with <b>PicGIM</b>. \n
					You can choose to use <b>totally or partially</b> the support provided by \b <b>PicGIM</b>. \n
					Each module of \b PicGIM can be <b>replaced by personal libraries.</b> \n \n
					&nbsp;&nbsp;&nbsp;&nbsp;<i>Anyone is free to contribute to the development of PicGIM. \n
					&nbsp;&nbsp;&nbsp;&nbsp;For improvements, corrections, or to extend hardware support, please contact us at this email : info@gkript.org </i> \n \n
				</p>

			\section	Cosaserve		What is PicGIM for
				<p>
					<b> PicGIM is essential in a project </b> in order to dedicate <b> all available time </b> only to the main algorithm. \n
					So you no longer have to think about the management of timers, pwm or display, and even interrupts. \n
					Through this clear documentation you will know the <b> full potential of PicGIM. </b> \n
					What remains is to configure \b PicGIM carefully to get the best possible result. \n
				</p>

			\section	achiserve		Whom is PicGIM for
				<p>
					\b PicGIM has been designed and developed <b> for anyone. </b> \n
					A \b beginner or a \b professional can find advantage to use <b>PicGIM</b>. \n
					The beginner will certainly have an huge advantage on the <b> simplicity of the code. </b> \n
					An experienced user instead will enjoy <b> the power of PicGIM </b> saving a lot of time for the development of the project. \n
				</p>

			\section htsmain	How to get started
				<p>
					In this section you can find <b> all the details in easy steps </b> for starting to use <b>PicGIM</b>. \n
					Click here to read the documentation about getting started : \ref htgstarted
				</p>

 			\section	documentation  This documentation
				<p>
					This documentation is made with \b Doxygen [ http://www.doxygen.org/ ]. \n
					The version of this documentation is \b 0.5 . If you find error or you think there is need more precision in some point,
					please write me \b here [ info@gkript.org ]. \n
				</p>

 			\section	Discl			Trademarks

				\htmlonly
					<em>All trademarks in this work are registered by their respective owners.</em><BR>
					<em>All trademarks in this work are property of their respective owners.</em><BR>
					<BR><BR>
				\endhtmlonly
				
*/

/*! 
	\example	HotWater_main.c
	\brief		This is an example of an application made using Gim. It is the code of the Gkdp utility.
*/



/*!
	\page	htgstarted		How to get started

	 	\tableofcontents

		\n
		\image html getting-started.png
		\n

		<p>
			In this section you can find all the details in easy steps for starting to use PicGIM. \n
			PicGIM is compatible with the two standard environments MicroChip: MPLAB 8 and MPLAB X. \n \n

			\htmlonly
			&nbsp;&nbsp;&nbsp;&nbsp;<img src="ides.png" alt="ides.png">
			\endhtmlonly

			There are substantial differences between the two environments that we can not create a single common guideline. \n
			So you need to follow the guide of the environment used. \n
		</p>

		\section	getstartmp8 		PicGIM with MPLAB 8

		\htmlonly <hr> \endhtmlonly
		\endcode

			\subsection	getstartmp8howto 		How to create a project step by step

				\htmlonly <hr> \endhtmlonly
				\endcode

					<b>Download</b> the latest version of PicGim : \htmlonly <A target="_blank" href="http://gkript.org/index.php/projects/3-picgim#download">PicGIM download</A> <BR> \endhtmlonly
					<b>Select</b> the type of micro-controller used (see: \ref SWC_EzFuse ). \n
					<b>Select</b> the correct tool-compiler suite. \n \n
					\image	html	mplab8-toolsuite.png
					<b>Set</b> the include directory in the Option-Build. \n \n
 					\image	html	mplab8-includedir.png
 					\b Enable, if required in the project, the extended instruction set. In Mplab 8 PicGim automatically detects it. \n \n
					\image	html	xinst.jpg
					\b Configure PicGIM according to the requirements of the project by editing the file PUBLIC relating to the modules. \n Here is list of public files within the project MPLAB 8: \n \n
					\image	html	mplab8-project-public.png
					It is possible to add your own files to the project even though we do not recommend it. \n \n
					\image	html	mplab8-project-myfile.png

					\attention	Each file ".c" added to the project must include the following line as the first line of code: \n
						\code
							#include "picgim.h"

							...
						\endcode
					
			\subsection		getstartmp8fullcontrol	 	Easy PicGIM configuration

			\htmlonly <hr> \endhtmlonly
			\endcode

			\htmlonly
				To get easily the complete control of your project you need to know which files are editable by user.<br>
				So here is a list of the public files PicGIM's<br><br>
				<table width="80%" border="0" >
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_event_setup_public.h \htmlonly </td>
						<td>With this file you can enable the global management of interruptions.<br>PicGIM automatically will include all the setting for interrupt vector.<br>
						PicGIM implements management of interrupts without priority levels for maximum compatibility between the various MCU supported.<br>
						With this file you can also enable or disable each event handled by the Microchip<small>&#8482;</small> MCU.</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_hardware_setup_public.h \htmlonly </td>
						<td>Through this file you set the hardware pinout for your project.<BR>Each module, when enabled, will follow the settings declared in this file.</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_module_setup_public.h \htmlonly </td>
						<td>This public file makes it easy to to include in your project all the code needed for different hardware supported by PicGIM.<br>For more details see: \endhtmlonly \ref WPC_module \htmlonly </td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_project_setup_public.h \htmlonly </td>
						<td>With this file you can set the basic parameters of the project and the parameters of PicGIM behavior as verbosity.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_pwm_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the PWM channels.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_serial_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the Serial.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_timer_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the Timers.</td>
					</tr>
					<tr align="left" valign="center" >
						<td width="20%"> \endhtmlonly pgim_18f2320_public.h \htmlonly </td>
						<td>The public file for the 18F2320 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f2550_public.h \htmlonly </td>
						<td>The public file for the 18F2550 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f2553_public.h \htmlonly</td>
						<td>The public file for the 18F2553 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4520_public.h \htmlonly</td>
						<td>The public file for the 18F4520 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4550_public.h \htmlonly</td>
						<td>The public file for the 18F4550 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4553_public.h \htmlonly</td>
						<td>The public file for the 18F4553 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4620_public.h \htmlonly</td>
						<td>The public file for the 18F4620 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f97j60_public.h \htmlonly</td>
						<td>The public file for the 18F97j60 MCU</td>
					</tr>
				</table>
				<br>
				Every public file can be edited to adjust easily PicGIM to your project.<br><br>

			\endhtmlonly


		\section	getstartmpx 		PicGIM with MPLAB X

			\subsection	getstartmpxhowto 		How to create a project step by step

				\htmlonly <hr> \endhtmlonly
				\endcode

					<b>Download</b> the latest version of PicGim : \htmlonly <A target="_blank" href="http://gkript.org/index.php/projects/3-picgim#download">PicGIM download</A> <BR> \endhtmlonly
					<b>Select</b> the type of micro-controller used (see: \ref SWC_EzFuse )and the C18 toolchain. \n
					\image	html	mplabx-project-properities.png
					<b>Set</b> the include directory in the Option-Build. \n \n
 					\image	html	mplabx-includedir.png
 					\b Enable, if required in the project, the extended instruction set. Even if it is properly flagged check for Extended instruction code, MPLAB X will ignore it. \n
					It will be necessary, as well as to flag, the extended instruction code, manually force the definition of "__EXTENDED18__" in Compiler and Linker. \n
					Here is the guide: \n \n
					\image	html	mplabx-extended-flag.png
					\image	html	mplabx-extended-compilatore.png
					\image	html	mplabx-extended-linker.png
					\b Configure PicGIM according to the requirements of the project by editing the file PUBLIC relating to the modules. \n Here is list of public files within the project MPLAB X: \n \n
					\image	html	mplabx-project-public.png
					It is possible to add your own files to the project even though we do not recommend it. \n \n
					\image	html	mplabx-project-myfile.png

					\attention	Each file ".c" added to the project must include the following line as the first line of code: \n
						\code
							#include "picgim.h"

							...
						\endcode

			\subsection		getstartmpxfullcontrol	 	How to have the full control easily

			\htmlonly <hr> \endhtmlonly
			\endcode

			\htmlonly
				To get easily the complete control of your project you need to know which files are editable by user.<br>
				So here is a list of the public files PicGIM's<br><br>
				<table width="80%" border="0" >
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_event_setup_public.h \htmlonly </td>
						<td>With this file you can enable the global management of interruptions.<br>PicGIM automatically will include all the setting for interrupt vector.<br>
						PicGIM implements management of interrupts without priority levels for maximum compatibility between the various MCU supported.<br>
						With this file you can also enable or disable each event handled by the Microchip<small>&#8482;</small> MCU.</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_hardware_setup_public.h \htmlonly </td>
						<td>Through this file you set the hardware pinout for your project.<BR>Each module, when enabled, will follow the settings declared in this file.</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_module_setup_public.h \htmlonly </td>
						<td>This public file makes it easy to to include in your project all the code needed for different hardware supported by PicGIM.<br>For more details see: \endhtmlonly \ref WPC_module \htmlonly </td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_project_setup_public.h \htmlonly </td>
						<td>With this file you can set the basic parameters of the project and the parameters of PicGIM behavior as verbosity.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_pwm_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the PWM channels.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_serial_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the Serial.</td>
					</tr>
					<tr align="left" >
						<td width="20%"> \endhtmlonly pgim_timer_setup_public.h \htmlonly </td>
						<td>With this file it is possible to specify in detail the operating mode of the Timers.</td>
					</tr>
					<tr align="left" valign="center" >
						<td width="20%"> \endhtmlonly pgim_18f2320_public.h \htmlonly </td>
						<td>The public file for the 18F2320 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f2550_public.h \htmlonly </td>
						<td>The public file for the 18F2550 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f2553_public.h \htmlonly</td>
						<td>The public file for the 18F2553 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4520_public.h \htmlonly</td>
						<td>The public file for the 18F4520 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4550_public.h \htmlonly</td>
						<td>The public file for the 18F4550 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4553_public.h \htmlonly</td>
						<td>The public file for the 18F4553 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f4620_public.h \htmlonly</td>
						<td>The public file for the 18F4620 MCU</td>
					</tr>
					<tr align="left">
						<td width="20%"> \endhtmlonly pgim_18f97j60_public.h \htmlonly</td>
						<td>The public file for the 18F97j60 MCU</td>
					</tr>
				</table>
				<br>
				Every public file can be edited to adjust easily PicGIM to your project.<br><br>

			\endhtmlonly



 */

//		\section	Example A simple example use PicGIM
//			\code
//				#include "picgim_main.h"
//
//				void main( void ) {
//					// main initialization of PicGIM : this is compulsory !!!
//					pg_initialize();
//
//					//	Provided by PGIM_BUZZER module
//					pg_beep( PG_BEEP_LOW , PG_BEEP_SHORT );
//					pg_beep( PG_BEEP_MID , PG_BEEP_SHORT );
//					pg_beep( PG_BEEP_HIGH , PG_BEEP_LONG );
//
//					//	Provided by PGIM_DELAY module
//					pg_delay( 2 , PG_SEC );
//
//					//	Provided by PGIM_LCD_HD44780 module
//					pg_lcd_hd44780_write_p_string_rom ( PG_CONTROLLER_0 , 0 , 3, "gKript.org" );
//					pg_lcd_hd44780_write_p_char( PG_CONTROLLER_0 , 1 , 1 , "PicGIM  %s" , PG_VERSION );
//
//					PG_HALT;
//				}
//
//			\endcode

/*!
	\page	NM_nextmilestone		Current milestone

		\tableofcontents

		\image	html milestone.png

		\section	cm1		Current Milestone : 0.5

			\htmlonly
				The current Milstone for PicGIM is the 0.5. <br>
				You can find the ChangeLog here : \endhtmlonly \ref PGIMCH \htmlonly <br>
				After this release will begin development of the next Milestone. <br>
			\endhtmlonly

		\section	nm1		Next Milestone will be 1.0

			\htmlonly
				<p>
					&nbsp;&nbsp;&nbsp;The <b>PicGIM</b> Milestone move by <b>0.5</b> at a time. <br>
					&nbsp;&nbsp;&nbsp;This Milestone just ended has been for sure the most dificult as development.<br>
					&nbsp;&nbsp;&nbsp;We studied the whole structure of the <b>PicGIM</b> library. It has been a complicated thing.<br>
					&nbsp;&nbsp;&nbsp;The peculiarity of <b>PicGIM</b> is that <b>only the enabled modules</b> are compiled.<br>
					&nbsp;&nbsp;&nbsp;In the next Milestone we'll only support the new hardware.<br>
				</p>
			\endhtmlonly

		\section	nmT1		Tickets opened for the next Milestone

			\htmlonly
				<p>
					Here lists the most important open tickets for the next milestone : <br>
					<p>
						<table class="cl_table" width="60%" border="0" >
							<thead>
								<tr>
									<th width="10%" align="center" >Ticket</th>
									<th width="90%" >Summary</th>
								</tr>
							<thead>	
							<tbody>
								<tr align="center">
									<td width="10%" align="center">#38</td>
									<td width="90%" align="left">Reduction and optimization of the use of Ram and Program.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#14</td>
									<td width="90%" align="left">Integrated watchdog manager.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#22</td>
									<td width="90%" align="left">Sermon - Programmable Serial Monitor.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#43</td>
									<td width="90%" align="left">AN914 - Dynamic Memory Allocation.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#13</td>
									<td width="90%" align="left">Reset manager.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#8</td>
									<td width="90%" align="left">Develop ILI9340 LCD module.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#48</td>
									<td width="90%" align="left">Develop 5110 LCD module.</td>
								</tr>
								<tr align="center">
									<td width="10%" align="center">#55</td>
									<td width="90%" align="left">Simple encryption algorithm.</td>
								</tr>
							<tbody>
						</table>
					</p>
				</p>
			\endhtmlonly
 */

/*!
	\page	LicenseGPLV3		Gnu license
	
		\tableofcontents

		\htmlonly
			<p>The open source is a lifestyle. A choice of very personal character and <strong>gKript.org</strong> made his own. All the software or the hardware generated by us is completely opensource.</p>
			<p>This means that we feel the need to share our passion and what we think can be useful solutions for many other people.</p>
			<p>Fortunately, there are many other organizations like ours that provide open source free software.</p>
			<br><br>
		\endhtmlonly

		\section	WPlic		We.PIC projects license
			\htmlonly
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<image src="WePIC_documentation_small.png" border="0" />
				<p>All projects that are released by <b>gKript.org</b> refers to <b>We.PIC</b> logo are under the terms of the <b>Gnu Public License V3</b>.</p>
				<br><br>
			\endhtmlonly

		\section	WPlicTesto		GNU General Public License v3
			\htmlonly
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<image src="gplv3-127x51.png" border="0" />
				<hr>
 				<h3 style="text-align: center;">GNU GENERAL PUBLIC LICENSE</h3>
				<p style="text-align: center;">Version 3, 29 June 2007</p>

				<p>Copyright &copy; 2007 Free Software Foundation, Inc.
				 &lt;<a href="http://fsf.org/">http://fsf.org/</a>&gt;</p><p>
				 Everyone is permitted to copy and distribute verbatim copies
				 of this license document, but changing it is not allowed.</p>

				<h3><a name="preamble"></a>Preamble</h3>

				<p>The GNU General Public License is a free, copyleft license for
				software and other kinds of works.</p>

				<p>The licenses for most software and other practical works are designed
				to take away your freedom to share and change the works.  By contrast,
				the GNU General Public License is intended to guarantee your freedom to
				share and change all versions of a program--to make sure it remains free
				software for all its users.  We, the Free Software Foundation, use the
				GNU General Public License for most of our software; it applies also to
				any other work released this way by its authors.  You can apply it to
				your programs, too.</p>

				<p>When we speak of free software, we are referring to freedom, not
				price.  Our General Public Licenses are designed to make sure that you
				have the freedom to distribute copies of free software (and charge for
				them if you wish), that you receive source code or can get it if you
				want it, that you can change the software or use pieces of it in new
				free programs, and that you know you can do these things.</p>

				<p>To protect your rights, we need to prevent others from denying you
				these rights or asking you to surrender the rights.  Therefore, you have
				certain responsibilities if you distribute copies of the software, or if
				you modify it: responsibilities to respect the freedom of others.</p>

				<p>For example, if you distribute copies of such a program, whether
				gratis or for a fee, you must pass on to the recipients the same
				freedoms that you received.  You must make sure that they, too, receive
				or can get the source code.  And you must show them these terms so they
				know their rights.</p>

				<p>Developers that use the GNU GPL protect your rights with two steps:
				(1) assert copyright on the software, and (2) offer you this License
				giving you legal permission to copy, distribute and/or modify it.</p>

				<p>For the developers' and authors' protection, the GPL clearly explains
				that there is no warranty for this free software.  For both users' and
				authors' sake, the GPL requires that modified versions be marked as
				changed, so that their problems will not be attributed erroneously to
				authors of previous versions.</p>

				<p>Some devices are designed to deny users access to install or run
				modified versions of the software inside them, although the manufacturer
				can do so.  This is fundamentally incompatible with the aim of
				protecting users' freedom to change the software.  The systematic
				pattern of such abuse occurs in the area of products for individuals to
				use, which is precisely where it is most unacceptable.  Therefore, we
				have designed this version of the GPL to prohibit the practice for those
				products.  If such problems arise substantially in other domains, we
				stand ready to extend this provision to those domains in future versions
				of the GPL, as needed to protect the freedom of users.</p>

				<p>Finally, every program is threatened constantly by software patents.
				States should not allow patents to restrict development and use of
				software on general-purpose computers, but in those that do, we wish to
				avoid the special danger that patents applied to a free program could
				make it effectively proprietary.  To prevent this, the GPL assures that
				patents cannot be used to render the program non-free.</p>

				<p>The precise terms and conditions for copying, distribution and
				modification follow.</p>

				<h3><a name="terms"></a>TERMS AND CONDITIONS</h3>

				<h4><a name="section0"></a>0. Definitions.</h4>

				<p>&ldquo;This License&rdquo; refers to version 3 of the GNU General Public License.</p>

				<p>&ldquo;Copyright&rdquo; also means copyright-like laws that apply to other kinds of
				works, such as semiconductor masks.</p>

				<p>&ldquo;The Program&rdquo; refers to any copyrightable work licensed under this
				License.  Each licensee is addressed as &ldquo;you&rdquo;.  &ldquo;Licensees&rdquo; and
				&ldquo;recipients&rdquo; may be individuals or organizations.</p>

				<p>To &ldquo;modify&rdquo; a work means to copy from or adapt all or part of the work
				in a fashion requiring copyright permission, other than the making of an
				exact copy.  The resulting work is called a &ldquo;modified version&rdquo; of the
				earlier work or a work &ldquo;based on&rdquo; the earlier work.</p>

				<p>A &ldquo;covered work&rdquo; means either the unmodified Program or a work based
				on the Program.</p>

				<p>To &ldquo;propagate&rdquo; a work means to do anything with it that, without
				permission, would make you directly or secondarily liable for
				infringement under applicable copyright law, except executing it on a
				computer or modifying a private copy.  Propagation includes copying,
				distribution (with or without modification), making available to the
				public, and in some countries other activities as well.</p>

				<p>To &ldquo;convey&rdquo; a work means any kind of propagation that enables other
				parties to make or receive copies.  Mere interaction with a user through
				a computer network, with no transfer of a copy, is not conveying.</p>

				<p>An interactive user interface displays &ldquo;Appropriate Legal Notices&rdquo;
				to the extent that it includes a convenient and prominently visible
				feature that (1) displays an appropriate copyright notice, and (2)
				tells the user that there is no warranty for the work (except to the
				extent that warranties are provided), that licensees may convey the
				work under this License, and how to view a copy of this License.  If
				the interface presents a list of user commands or options, such as a
				menu, a prominent item in the list meets this criterion.</p>

				<h4><a name="section1"></a>1. Source Code.</h4>

				<p>The &ldquo;source code&rdquo; for a work means the preferred form of the work
				for making modifications to it.  &ldquo;Object code&rdquo; means any non-source
				form of a work.</p>

				<p>A &ldquo;Standard Interface&rdquo; means an interface that either is an official
				standard defined by a recognized standards body, or, in the case of
				interfaces specified for a particular programming language, one that
				is widely used among developers working in that language.</p>

				<p>The &ldquo;System Libraries&rdquo; of an executable work include anything, other
				than the work as a whole, that (a) is included in the normal form of
				packaging a Major Component, but which is not part of that Major
				Component, and (b) serves only to enable use of the work with that
				Major Component, or to implement a Standard Interface for which an
				implementation is available to the public in source code form.  A
				&ldquo;Major Component&rdquo;, in this context, means a major essential component
				(kernel, window system, and so on) of the specific operating system
				(if any) on which the executable work runs, or a compiler used to
				produce the work, or an object code interpreter used to run it.</p>

				<p>The &ldquo;Corresponding Source&rdquo; for a work in object code form means all
				the source code needed to generate, install, and (for an executable
				work) run the object code and to modify the work, including scripts to
				control those activities.  However, it does not include the work's
				System Libraries, or general-purpose tools or generally available free
				programs which are used unmodified in performing those activities but
				which are not part of the work.  For example, Corresponding Source
				includes interface definition files associated with source files for
				the work, and the source code for shared libraries and dynamically
				linked subprograms that the work is specifically designed to require,
				such as by intimate data communication or control flow between those
				subprograms and other parts of the work.</p>

				<p>The Corresponding Source need not include anything that users
				can regenerate automatically from other parts of the Corresponding
				Source.</p>

				<p>The Corresponding Source for a work in source code form is that
				same work.</p>

				<h4><a name="section2"></a>2. Basic Permissions.</h4>

				<p>All rights granted under this License are granted for the term of
				copyright on the Program, and are irrevocable provided the stated
				conditions are met.  This License explicitly affirms your unlimited
				permission to run the unmodified Program.  The output from running a
				covered work is covered by this License only if the output, given its
				content, constitutes a covered work.  This License acknowledges your
				rights of fair use or other equivalent, as provided by copyright law.</p>

				<p>You may make, run and propagate covered works that you do not
				convey, without conditions so long as your license otherwise remains
				in force.  You may convey covered works to others for the sole purpose
				of having them make modifications exclusively for you, or provide you
				with facilities for running those works, provided that you comply with
				the terms of this License in conveying all material for which you do
				not control copyright.  Those thus making or running the covered works
				for you must do so exclusively on your behalf, under your direction
				and control, on terms that prohibit them from making any copies of
				your copyrighted material outside their relationship with you.</p>

				<p>Conveying under any other circumstances is permitted solely under
				the conditions stated below.  Sublicensing is not allowed; section 10
				makes it unnecessary.</p>

				<h4><a name="section3"></a>3. Protecting Users' Legal Rights From Anti-Circumvention Law.</h4>

				<p>No covered work shall be deemed part of an effective technological
				measure under any applicable law fulfilling obligations under article
				11 of the WIPO copyright treaty adopted on 20 December 1996, or
				similar laws prohibiting or restricting circumvention of such
				measures.</p>

				<p>When you convey a covered work, you waive any legal power to forbid
				circumvention of technological measures to the extent such circumvention
				is effected by exercising rights under this License with respect to
				the covered work, and you disclaim any intention to limit operation or
				modification of the work as a means of enforcing, against the work's
				users, your or third parties' legal rights to forbid circumvention of
				technological measures.</p>

				<h4><a name="section4"></a>4. Conveying Verbatim Copies.</h4>

				<p>You may convey verbatim copies of the Program's source code as you
				receive it, in any medium, provided that you conspicuously and
				appropriately publish on each copy an appropriate copyright notice;
				keep intact all notices stating that this License and any
				non-permissive terms added in accord with section 7 apply to the code;
				keep intact all notices of the absence of any warranty; and give all
				recipients a copy of this License along with the Program.</p>

				<p>You may charge any price or no price for each copy that you convey,
				and you may offer support or warranty protection for a fee.</p>

				<h4><a name="section5"></a>5. Conveying Modified Source Versions.</h4>

				<p>You may convey a work based on the Program, or the modifications to
				produce it from the Program, in the form of source code under the
				terms of section 4, provided that you also meet all of these conditions:</p>

				<ul>
				<li>a) The work must carry prominent notices stating that you modified
					it, and giving a relevant date.</li>

				<li>b) The work must carry prominent notices stating that it is
					released under this License and any conditions added under section
					7.  This requirement modifies the requirement in section 4 to
					&ldquo;keep intact all notices&rdquo;.</li>

				<li>c) You must license the entire work, as a whole, under this
					License to anyone who comes into possession of a copy.  This
					License will therefore apply, along with any applicable section 7
					additional terms, to the whole of the work, and all its parts,
					regardless of how they are packaged.  This License gives no
					permission to license the work in any other way, but it does not
					invalidate such permission if you have separately received it.</li>

				<li>d) If the work has interactive user interfaces, each must display
					Appropriate Legal Notices; however, if the Program has interactive
					interfaces that do not display Appropriate Legal Notices, your
					work need not make them do so.</li>
				</ul>

				<p>A compilation of a covered work with other separate and independent
				works, which are not by their nature extensions of the covered work,
				and which are not combined with it such as to form a larger program,
				in or on a volume of a storage or distribution medium, is called an
				&ldquo;aggregate&rdquo; if the compilation and its resulting copyright are not
				used to limit the access or legal rights of the compilation's users
				beyond what the individual works permit.  Inclusion of a covered work
				in an aggregate does not cause this License to apply to the other
				parts of the aggregate.</p>

				<h4><a name="section6"></a>6. Conveying Non-Source Forms.</h4>

				<p>You may convey a covered work in object code form under the terms
				of sections 4 and 5, provided that you also convey the
				machine-readable Corresponding Source under the terms of this License,
				in one of these ways:</p>

				<ul>
				<li>a) Convey the object code in, or embodied in, a physical product
					(including a physical distribution medium), accompanied by the
					Corresponding Source fixed on a durable physical medium
					customarily used for software interchange.</li>

				<li>b) Convey the object code in, or embodied in, a physical product
					(including a physical distribution medium), accompanied by a
					written offer, valid for at least three years and valid for as
					long as you offer spare parts or customer support for that product
					model, to give anyone who possesses the object code either (1) a
					copy of the Corresponding Source for all the software in the
					product that is covered by this License, on a durable physical
					medium customarily used for software interchange, for a price no
					more than your reasonable cost of physically performing this
					conveying of source, or (2) access to copy the
					Corresponding Source from a network server at no charge.</li>

				<li>c) Convey individual copies of the object code with a copy of the
					written offer to provide the Corresponding Source.  This
					alternative is allowed only occasionally and noncommercially, and
					only if you received the object code with such an offer, in accord
					with subsection 6b.</li>

				<li>d) Convey the object code by offering access from a designated
					place (gratis or for a charge), and offer equivalent access to the
					Corresponding Source in the same way through the same place at no
					further charge.  You need not require recipients to copy the
					Corresponding Source along with the object code.  If the place to
					copy the object code is a network server, the Corresponding Source
					may be on a different server (operated by you or a third party)
					that supports equivalent copying facilities, provided you maintain
					clear directions next to the object code saying where to find the
					Corresponding Source.  Regardless of what server hosts the
					Corresponding Source, you remain obligated to ensure that it is
					available for as long as needed to satisfy these requirements.</li>

				<li>e) Convey the object code using peer-to-peer transmission, provided
					you inform other peers where the object code and Corresponding
					Source of the work are being offered to the general public at no
					charge under subsection 6d.</li>
				</ul>

				<p>A separable portion of the object code, whose source code is excluded
				from the Corresponding Source as a System Library, need not be
				included in conveying the object code work.</p>

				<p>A &ldquo;User Product&rdquo; is either (1) a &ldquo;consumer product&rdquo;, which means any
				tangible personal property which is normally used for personal, family,
				or household purposes, or (2) anything designed or sold for incorporation
				into a dwelling.  In determining whether a product is a consumer product,
				doubtful cases shall be resolved in favor of coverage.  For a particular
				product received by a particular user, &ldquo;normally used&rdquo; refers to a
				typical or common use of that class of product, regardless of the status
				of the particular user or of the way in which the particular user
				actually uses, or expects or is expected to use, the product.  A product
				is a consumer product regardless of whether the product has substantial
				commercial, industrial or non-consumer uses, unless such uses represent
				the only significant mode of use of the product.</p>

				<p>&ldquo;Installation Information&rdquo; for a User Product means any methods,
				procedures, authorization keys, or other information required to install
				and execute modified versions of a covered work in that User Product from
				a modified version of its Corresponding Source.  The information must
				suffice to ensure that the continued functioning of the modified object
				code is in no case prevented or interfered with solely because
				modification has been made.</p>

				<p>If you convey an object code work under this section in, or with, or
				specifically for use in, a User Product, and the conveying occurs as
				part of a transaction in which the right of possession and use of the
				User Product is transferred to the recipient in perpetuity or for a
				fixed term (regardless of how the transaction is characterized), the
				Corresponding Source conveyed under this section must be accompanied
				by the Installation Information.  But this requirement does not apply
				if neither you nor any third party retains the ability to install
				modified object code on the User Product (for example, the work has
				been installed in ROM).</p>

				<p>The requirement to provide Installation Information does not include a
				requirement to continue to provide support service, warranty, or updates
				for a work that has been modified or installed by the recipient, or for
				the User Product in which it has been modified or installed.  Access to a
				network may be denied when the modification itself materially and
				adversely affects the operation of the network or violates the rules and
				protocols for communication across the network.</p>

				<p>Corresponding Source conveyed, and Installation Information provided,
				in accord with this section must be in a format that is publicly
				documented (and with an implementation available to the public in
				source code form), and must require no special password or key for
				unpacking, reading or copying.</p>

				<h4><a name="section7"></a>7. Additional Terms.</h4>

				<p>&ldquo;Additional permissions&rdquo; are terms that supplement the terms of this
				License by making exceptions from one or more of its conditions.
				Additional permissions that are applicable to the entire Program shall
				be treated as though they were included in this License, to the extent
				that they are valid under applicable law.  If additional permissions
				apply only to part of the Program, that part may be used separately
				under those permissions, but the entire Program remains governed by
				this License without regard to the additional permissions.</p>

				<p>When you convey a copy of a covered work, you may at your option
				remove any additional permissions from that copy, or from any part of
				it.  (Additional permissions may be written to require their own
				removal in certain cases when you modify the work.)  You may place
				additional permissions on material, added by you to a covered work,
				for which you have or can give appropriate copyright permission.</p>

				<p>Notwithstanding any other provision of this License, for material you
				add to a covered work, you may (if authorized by the copyright holders of
				that material) supplement the terms of this License with terms:</p>

				<ul>
				<li>a) Disclaiming warranty or limiting liability differently from the
					terms of sections 15 and 16 of this License; or</li>

				<li>b) Requiring preservation of specified reasonable legal notices or
					author attributions in that material or in the Appropriate Legal
					Notices displayed by works containing it; or</li>

				<li>c) Prohibiting misrepresentation of the origin of that material, or
					requiring that modified versions of such material be marked in
					reasonable ways as different from the original version; or</li>

				<li>d) Limiting the use for publicity purposes of names of licensors or
					authors of the material; or</li>

				<li>e) Declining to grant rights under trademark law for use of some
					trade names, trademarks, or service marks; or</li>

				<li>f) Requiring indemnification of licensors and authors of that
					material by anyone who conveys the material (or modified versions of
					it) with contractual assumptions of liability to the recipient, for
					any liability that these contractual assumptions directly impose on
					those licensors and authors.</li>
				</ul>

				<p>All other non-permissive additional terms are considered &ldquo;further
				restrictions&rdquo; within the meaning of section 10.  If the Program as you
				received it, or any part of it, contains a notice stating that it is
				governed by this License along with a term that is a further
				restriction, you may remove that term.  If a license document contains
				a further restriction but permits relicensing or conveying under this
				License, you may add to a covered work material governed by the terms
				of that license document, provided that the further restriction does
				not survive such relicensing or conveying.</p>

				<p>If you add terms to a covered work in accord with this section, you
				must place, in the relevant source files, a statement of the
				additional terms that apply to those files, or a notice indicating
				where to find the applicable terms.</p>

				<p>Additional terms, permissive or non-permissive, may be stated in the
				form of a separately written license, or stated as exceptions;
				the above requirements apply either way.</p>

				<h4><a name="section8"></a>8. Termination.</h4>

				<p>You may not propagate or modify a covered work except as expressly
				provided under this License.  Any attempt otherwise to propagate or
				modify it is void, and will automatically terminate your rights under
				this License (including any patent licenses granted under the third
				paragraph of section 11).</p>

				<p>However, if you cease all violation of this License, then your
				license from a particular copyright holder is reinstated (a)
				provisionally, unless and until the copyright holder explicitly and
				finally terminates your license, and (b) permanently, if the copyright
				holder fails to notify you of the violation by some reasonable means
				prior to 60 days after the cessation.</p>

				<p>Moreover, your license from a particular copyright holder is
				reinstated permanently if the copyright holder notifies you of the
				violation by some reasonable means, this is the first time you have
				received notice of violation of this License (for any work) from that
				copyright holder, and you cure the violation prior to 30 days after
				your receipt of the notice.</p>

				<p>Termination of your rights under this section does not terminate the
				licenses of parties who have received copies or rights from you under
				this License.  If your rights have been terminated and not permanently
				reinstated, you do not qualify to receive new licenses for the same
				material under section 10.</p>

				<h4><a name="section9"></a>9. Acceptance Not Required for Having Copies.</h4>

				<p>You are not required to accept this License in order to receive or
				run a copy of the Program.  Ancillary propagation of a covered work
				occurring solely as a consequence of using peer-to-peer transmission
				to receive a copy likewise does not require acceptance.  However,
				nothing other than this License grants you permission to propagate or
				modify any covered work.  These actions infringe copyright if you do
				not accept this License.  Therefore, by modifying or propagating a
				covered work, you indicate your acceptance of this License to do so.</p>

				<h4><a name="section10"></a>10. Automatic Licensing of Downstream Recipients.</h4>

				<p>Each time you convey a covered work, the recipient automatically
				receives a license from the original licensors, to run, modify and
				propagate that work, subject to this License.  You are not responsible
				for enforcing compliance by third parties with this License.</p>

				<p>An &ldquo;entity transaction&rdquo; is a transaction transferring control of an
				organization, or substantially all assets of one, or subdividing an
				organization, or merging organizations.  If propagation of a covered
				work results from an entity transaction, each party to that
				transaction who receives a copy of the work also receives whatever
				licenses to the work the party's predecessor in interest had or could
				give under the previous paragraph, plus a right to possession of the
				Corresponding Source of the work from the predecessor in interest, if
				the predecessor has it or can get it with reasonable efforts.</p>

				<p>You may not impose any further restrictions on the exercise of the
				rights granted or affirmed under this License.  For example, you may
				not impose a license fee, royalty, or other charge for exercise of
				rights granted under this License, and you may not initiate litigation
				(including a cross-claim or counterclaim in a lawsuit) alleging that
				any patent claim is infringed by making, using, selling, offering for
				sale, or importing the Program or any portion of it.</p>

				<h4><a name="section11"></a>11. Patents.</h4>

				<p>A &ldquo;contributor&rdquo; is a copyright holder who authorizes use under this
				License of the Program or a work on which the Program is based.  The
				work thus licensed is called the contributor's &ldquo;contributor version&rdquo;.</p>

				<p>A contributor's &ldquo;essential patent claims&rdquo; are all patent claims
				owned or controlled by the contributor, whether already acquired or
				hereafter acquired, that would be infringed by some manner, permitted
				by this License, of making, using, or selling its contributor version,
				but do not include claims that would be infringed only as a
				consequence of further modification of the contributor version.  For
				purposes of this definition, &ldquo;control&rdquo; includes the right to grant
				patent sublicenses in a manner consistent with the requirements of
				this License.</p>

				<p>Each contributor grants you a non-exclusive, worldwide, royalty-free
				patent license under the contributor's essential patent claims, to
				make, use, sell, offer for sale, import and otherwise run, modify and
				propagate the contents of its contributor version.</p>

				<p>In the following three paragraphs, a &ldquo;patent license&rdquo; is any express
				agreement or commitment, however denominated, not to enforce a patent
				(such as an express permission to practice a patent or covenant not to
				sue for patent infringement).  To &ldquo;grant&rdquo; such a patent license to a
				party means to make such an agreement or commitment not to enforce a
				patent against the party.</p>

				<p>If you convey a covered work, knowingly relying on a patent license,
				and the Corresponding Source of the work is not available for anyone
				to copy, free of charge and under the terms of this License, through a
				publicly available network server or other readily accessible means,
				then you must either (1) cause the Corresponding Source to be so
				available, or (2) arrange to deprive yourself of the benefit of the
				patent license for this particular work, or (3) arrange, in a manner
				consistent with the requirements of this License, to extend the patent
				license to downstream recipients.  &ldquo;Knowingly relying&rdquo; means you have
				actual knowledge that, but for the patent license, your conveying the
				covered work in a country, or your recipient's use of the covered work
				in a country, would infringe one or more identifiable patents in that
				country that you have reason to believe are valid.</p>

				<p>If, pursuant to or in connection with a single transaction or
				arrangement, you convey, or propagate by procuring conveyance of, a
				covered work, and grant a patent license to some of the parties
				receiving the covered work authorizing them to use, propagate, modify
				or convey a specific copy of the covered work, then the patent license
				you grant is automatically extended to all recipients of the covered
				work and works based on it.</p>

				<p>A patent license is &ldquo;discriminatory&rdquo; if it does not include within
				the scope of its coverage, prohibits the exercise of, or is
				conditioned on the non-exercise of one or more of the rights that are
				specifically granted under this License.  You may not convey a covered
				work if you are a party to an arrangement with a third party that is
				in the business of distributing software, under which you make payment
				to the third party based on the extent of your activity of conveying
				the work, and under which the third party grants, to any of the
				parties who would receive the covered work from you, a discriminatory
				patent license (a) in connection with copies of the covered work
				conveyed by you (or copies made from those copies), or (b) primarily
				for and in connection with specific products or compilations that
				contain the covered work, unless you entered into that arrangement,
				or that patent license was granted, prior to 28 March 2007.</p>

				<p>Nothing in this License shall be construed as excluding or limiting
				any implied license or other defenses to infringement that may
				otherwise be available to you under applicable patent law.</p>

				<h4><a name="section12"></a>12. No Surrender of Others' Freedom.</h4>

				<p>If conditions are imposed on you (whether by court order, agreement or
				otherwise) that contradict the conditions of this License, they do not
				excuse you from the conditions of this License.  If you cannot convey a
				covered work so as to satisfy simultaneously your obligations under this
				License and any other pertinent obligations, then as a consequence you may
				not convey it at all.  For example, if you agree to terms that obligate you
				to collect a royalty for further conveying from those to whom you convey
				the Program, the only way you could satisfy both those terms and this
				License would be to refrain entirely from conveying the Program.</p>

				<h4><a name="section13"></a>13. Use with the GNU Affero General Public License.</h4>

				<p>Notwithstanding any other provision of this License, you have
				permission to link or combine any covered work with a work licensed
				under version 3 of the GNU Affero General Public License into a single
				combined work, and to convey the resulting work.  The terms of this
				License will continue to apply to the part which is the covered work,
				but the special requirements of the GNU Affero General Public License,
				section 13, concerning interaction through a network will apply to the
				combination as such.</p>

				<h4><a name="section14"></a>14. Revised Versions of this License.</h4>

				<p>The Free Software Foundation may publish revised and/or new versions of
				the GNU General Public License from time to time.  Such new versions will
				be similar in spirit to the present version, but may differ in detail to
				address new problems or concerns.</p>

				<p>Each version is given a distinguishing version number.  If the
				Program specifies that a certain numbered version of the GNU General
				Public License &ldquo;or any later version&rdquo; applies to it, you have the
				option of following the terms and conditions either of that numbered
				version or of any later version published by the Free Software
				Foundation.  If the Program does not specify a version number of the
				GNU General Public License, you may choose any version ever published
				by the Free Software Foundation.</p>

				<p>If the Program specifies that a proxy can decide which future
				versions of the GNU General Public License can be used, that proxy's
				public statement of acceptance of a version permanently authorizes you
				to choose that version for the Program.</p>

				<p>Later license versions may give you additional or different
				permissions.  However, no additional obligations are imposed on any
				author or copyright holder as a result of your choosing to follow a
				later version.</p>

				<h4><a name="section15"></a>15. Disclaimer of Warranty.</h4>

				<p>THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
				APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
				HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM &ldquo;AS IS&rdquo; WITHOUT WARRANTY
				OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
				THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
				IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
				ALL NECESSARY SERVICING, REPAIR OR CORRECTION.</p>

				<h4><a name="section16"></a>16. Limitation of Liability.</h4>

				<p>IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
				WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
				THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
				GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
				USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
				DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
				PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
				EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
				SUCH DAMAGES.</p>

				<h4><a name="section17"></a>17. Interpretation of Sections 15 and 16.</h4>

				<p>If the disclaimer of warranty and limitation of liability provided
				above cannot be given local legal effect according to their terms,
				reviewing courts shall apply local law that most closely approximates
				an absolute waiver of all civil liability in connection with the
				Program, unless a warranty or assumption of liability accompanies a
				copy of the Program in return for a fee.</p>

				<p>END OF TERMS AND CONDITIONS</p>

			\endhtmlonly

		\section	WDlic		We.DOC documentation license
			\htmlonly
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<image src="WeDOC_documentation_small.png" border="0" />
				<p>All documentation released by <b>gKript.org</b> refers to <b>We.DOC</b> logo is under the terms of the <b>GNU Free Documentation License</b>.</p>
				<br><br>
			\endhtmlonly

		\section	WDlicTesto		GNU Free Documentation License
			\htmlonly
			<br>
			<hr>
			<br>
			<h3 style="text-align: center;">GNU Free Documentation License</h3>
			<p style="text-align: center;">Version 1.3, 3 November 2008</p>
			<p> Copyright &copy; 2000, 2001, 2002, 2007, 2008 Free Software Foundation, Inc.
							 &lt;<a href="http://fsf.org/">http://fsf.org/</a>&gt;
						 </p><p>Everyone is permitted to copy and distribute verbatim copies
						 of this license document, but changing it is not allowed.</p>
			<h4><a name="section0"></a>0. PREAMBLE</h4>

			<p>The purpose of this License is to make a manual, textbook, or other
			functional and useful document "free" in the sense of freedom: to
			assure everyone the effective freedom to copy and redistribute it,
			with or without modifying it, either commercially or noncommercially.
			Secondarily, this License preserves for the author and publisher a way
			to get credit for their work, while not being considered responsible
			for modifications made by others.</p>

			<p>This License is a kind of "copyleft", which means that derivative
			works of the document must themselves be free in the same sense.  It
			complements the GNU General Public License, which is a copyleft
			license designed for free software.</p>

			<p>We have designed this License in order to use it for manuals for free
			software, because free software needs free documentation: a free
			program should come with manuals providing the same freedoms that the
			software does.  But this License is not limited to software manuals;
			it can be used for any textual work, regardless of subject matter or
			whether it is published as a printed book.  We recommend this License
			principally for works whose purpose is instruction or reference.</p>

			<h4><a name="section1"></a>1. APPLICABILITY AND DEFINITIONS</h4>

			<p>This License applies to any manual or other work, in any medium, that
			contains a notice placed by the copyright holder saying it can be
			distributed under the terms of this License.  Such a notice grants a
			world-wide, royalty-free license, unlimited in duration, to use that
			work under the conditions stated herein.  The "Document", below,
			refers to any such manual or work.  Any member of the public is a
			licensee, and is addressed as "you".  You accept the license if you
			copy, modify or distribute the work in a way requiring permission
			under copyright law.</p>

			<p>A "Modified Version" of the Document means any work containing the
			Document or a portion of it, either copied verbatim, or with
			modifications and/or translated into another language.</p>

			<p>A "Secondary Section" is a named appendix or a front-matter section of
			the Document that deals exclusively with the relationship of the
			publishers or authors of the Document to the Document's overall
			subject (or to related matters) and contains nothing that could fall
			directly within that overall subject.  (Thus, if the Document is in
			part a textbook of mathematics, a Secondary Section may not explain
			any mathematics.)  The relationship could be a matter of historical
			connection with the subject or with related matters, or of legal,
			commercial, philosophical, ethical or political position regarding
			them.</p>

			<p>The "Invariant Sections" are certain Secondary Sections whose titles
			are designated, as being those of Invariant Sections, in the notice
			that says that the Document is released under this License.  If a
			section does not fit the above definition of Secondary then it is not
			allowed to be designated as Invariant.  The Document may contain zero
			Invariant Sections.  If the Document does not identify any Invariant
			Sections then there are none.</p>

			<p>The "Cover Texts" are certain short passages of text that are listed,
			as Front-Cover Texts or Back-Cover Texts, in the notice that says that
			the Document is released under this License.  A Front-Cover Text may
			be at most 5 words, and a Back-Cover Text may be at most 25 words.</p>

			<p>A "Transparent" copy of the Document means a machine-readable copy,
			represented in a format whose specification is available to the
			general public, that is suitable for revising the document
			straightforwardly with generic text editors or (for images composed of
			pixels) generic paint programs or (for drawings) some widely available
			drawing editor, and that is suitable for input to text formatters or
			for automatic translation to a variety of formats suitable for input
			to text formatters.  A copy made in an otherwise Transparent file
			format whose markup, or absence of markup, has been arranged to thwart
			or discourage subsequent modification by readers is not Transparent.
			An image format is not Transparent if used for any substantial amount
			of text.  A copy that is not "Transparent" is called "Opaque".</p>

			<p>Examples of suitable formats for Transparent copies include plain
			ASCII without markup, Texinfo input format, LaTeX input format, SGML
			or XML using a publicly available DTD, and standard-conforming simple
			HTML, PostScript or PDF designed for human modification.  Examples of
			transparent image formats include PNG, XCF and JPG.  Opaque formats
			include proprietary formats that can be read and edited only by
			proprietary word processors, SGML or XML for which the DTD and/or
			processing tools are not generally available, and the
			machine-generated HTML, PostScript or PDF produced by some word
			processors for output purposes only.</p>

			<p>The "Title Page" means, for a printed book, the title page itself,
			plus such following pages as are needed to hold, legibly, the material
			this License requires to appear in the title page.  For works in
			formats which do not have any title page as such, "Title Page" means
			the text near the most prominent appearance of the work's title,
			preceding the beginning of the body of the text.</p>

			<p>The "publisher" means any person or entity that distributes copies of
			the Document to the public.</p>

			<p>A section "Entitled XYZ" means a named subunit of the Document whose
			title either is precisely XYZ or contains XYZ in parentheses following
			text that translates XYZ in another language.  (Here XYZ stands for a
			specific section name mentioned below, such as "Acknowledgements",
			"Dedications", "Endorsements", or "History".)  To "Preserve the Title"
			of such a section when you modify the Document means that it remains a
			section "Entitled XYZ" according to this definition.</p>

			<p>The Document may include Warranty Disclaimers next to the notice which
			states that this License applies to the Document.  These Warranty
			Disclaimers are considered to be included by reference in this
			License, but only as regards disclaiming warranties: any other
			implication that these Warranty Disclaimers may have is void and has
			no effect on the meaning of this License.</p>

			<h4><a name="section2"></a>2. VERBATIM COPYING</h4>

			<p>You may copy and distribute the Document in any medium, either
			commercially or noncommercially, provided that this License, the
			copyright notices, and the license notice saying this License applies
			to the Document are reproduced in all copies, and that you add no
			other conditions whatsoever to those of this License.  You may not use
			technical measures to obstruct or control the reading or further
			copying of the copies you make or distribute.  However, you may accept
			compensation in exchange for copies.  If you distribute a large enough
			number of copies you must also follow the conditions in section 3.</p>

			<p>You may also lend copies, under the same conditions stated above, and
			you may publicly display copies.</p>

			<h4><a name="section3"></a>3. COPYING IN QUANTITY</h4>

			<p>If you publish printed copies (or copies in media that commonly have
			printed covers) of the Document, numbering more than 100, and the
			Document's license notice requires Cover Texts, you must enclose the
			copies in covers that carry, clearly and legibly, all these Cover
			Texts: Front-Cover Texts on the front cover, and Back-Cover Texts on
			the back cover.  Both covers must also clearly and legibly identify
			you as the publisher of these copies.  The front cover must present
			the full title with all words of the title equally prominent and
			visible.  You may add other material on the covers in addition.
			Copying with changes limited to the covers, as long as they preserve
			the title of the Document and satisfy these conditions, can be treated
			as verbatim copying in other respects.</p>

			<p>If the required texts for either cover are too voluminous to fit
			legibly, you should put the first ones listed (as many as fit
			reasonably) on the actual cover, and continue the rest onto adjacent
			pages.</p>

			<p>If you publish or distribute Opaque copies of the Document numbering
			more than 100, you must either include a machine-readable Transparent
			copy along with each Opaque copy, or state in or with each Opaque copy
			a computer-network location from which the general network-using
			public has access to download using public-standard network protocols
			a complete Transparent copy of the Document, free of added material.
			If you use the latter option, you must take reasonably prudent steps,
			when you begin distribution of Opaque copies in quantity, to ensure
			that this Transparent copy will remain thus accessible at the stated
			location until at least one year after the last time you distribute an
			Opaque copy (directly or through your agents or retailers) of that
			edition to the public.</p>

			<p>It is requested, but not required, that you contact the authors of the
			Document well before redistributing any large number of copies, to
			give them a chance to provide you with an updated version of the
			Document.</p>

			<h4><a name="section4"></a>4. MODIFICATIONS</h4>

			<p>You may copy and distribute a Modified Version of the Document under
			the conditions of sections 2 and 3 above, provided that you release
			the Modified Version under precisely this License, with the Modified
			Version filling the role of the Document, thus licensing distribution
			and modification of the Modified Version to whoever possesses a copy
			of it.  In addition, you must do these things in the Modified Version:</p>

			<ul>


			<li>A. Use in the Title Page (and on the covers, if any) a title distinct
						   from that of the Document, and from those of previous versions
						   (which should, if there were any, be listed in the History section
						   of the Document).  You may use the same title as a previous version
						   if the original publisher of that version gives permission.
			</li>

			<li>B. List on the Title Page, as authors, one or more persons or entities
						   responsible for authorship of the modifications in the Modified
						   Version, together with at least five of the principal authors of the
						   Document (all of its principal authors, if it has fewer than five),
						   unless they release you from this requirement.
			</li>

			<li>C. State on the Title page the name of the publisher of the
						   Modified Version, as the publisher.
			</li>

			<li>D. Preserve all the copyright notices of the Document.
			</li>

			<li>E. Add an appropriate copyright notice for your modifications
						   adjacent to the other copyright notices.
			</li>

			<li>F. Include, immediately after the copyright notices, a license notice
						   giving the public permission to use the Modified Version under the
						   terms of this License, in the form shown in the Addendum below.
			</li>

			<li>G. Preserve in that license notice the full lists of Invariant Sections
						   and required Cover Texts given in the Document's license notice.
			</li>

			<li>H. Include an unaltered copy of this License.
			</li>

			<li>I. Preserve the section Entitled "History", Preserve its Title, and add
						   to it an item stating at least the title, year, new authors, and
						   publisher of the Modified Version as given on the Title Page.  If
						   there is no section Entitled "History" in the Document, create one
						   stating the title, year, authors, and publisher of the Document as
						   given on its Title Page, then add an item describing the Modified
						   Version as stated in the previous sentence.
			</li>

			<li>J. Preserve the network location, if any, given in the Document for
						   public access to a Transparent copy of the Document, and likewise
						   the network locations given in the Document for previous versions
						   it was based on.  These may be placed in the "History" section.
						   You may omit a network location for a work that was published at
						   least four years before the Document itself, or if the original
						   publisher of the version it refers to gives permission.
			</li>

			<li>K. For any section Entitled "Acknowledgements" or "Dedications",
						   Preserve the Title of the section, and preserve in the section all
						   the substance and tone of each of the contributor acknowledgements
						   and/or dedications given therein.
			</li>

			<li>L. Preserve all the Invariant Sections of the Document,
						   unaltered in their text and in their titles.  Section numbers
						   or the equivalent are not considered part of the section titles.
			</li>

			<li>M. Delete any section Entitled "Endorsements".  Such a section
						   may not be included in the Modified Version.
			</li>

			<li>N. Do not retitle any existing section to be Entitled "Endorsements"
						   or to conflict in title with any Invariant Section.
			</li>

			<li>O. Preserve any Warranty Disclaimers.</li>

			</ul>

			<p>If the Modified Version includes new front-matter sections or
			appendices that qualify as Secondary Sections and contain no material
			copied from the Document, you may at your option designate some or all
			of these sections as invariant.  To do this, add their titles to the
			list of Invariant Sections in the Modified Version's license notice.
			These titles must be distinct from any other section titles.</p>

			<p>You may add a section Entitled "Endorsements", provided it contains
			nothing but endorsements of your Modified Version by various
			parties�for example, statements of peer review or that the text has
			been approved by an organization as the authoritative definition of a
			standard.</p>

			<p>You may add a passage of up to five words as a Front-Cover Text, and a
			passage of up to 25 words as a Back-Cover Text, to the end of the list
			of Cover Texts in the Modified Version.  Only one passage of
			Front-Cover Text and one of Back-Cover Text may be added by (or
			through arrangements made by) any one entity.  If the Document already
			includes a cover text for the same cover, previously added by you or
			by arrangement made by the same entity you are acting on behalf of,
			you may not add another; but you may replace the old one, on explicit
			permission from the previous publisher that added the old one.</p>

			<p>The author(s) and publisher(s) of the Document do not by this License
			give permission to use their names for publicity for or to assert or
			imply endorsement of any Modified Version.</p>

			<h4><a name="section5"></a>5. COMBINING DOCUMENTS</h4>

			<p>You may combine the Document with other documents released under this
			License, under the terms defined in section 4 above for modified
			versions, provided that you include in the combination all of the
			Invariant Sections of all of the original documents, unmodified, and
			list them all as Invariant Sections of your combined work in its
			license notice, and that you preserve all their Warranty Disclaimers.</p>

			<p>The combined work need only contain one copy of this License, and
			multiple identical Invariant Sections may be replaced with a single
			copy.  If there are multiple Invariant Sections with the same name but
			different contents, make the title of each such section unique by
			adding at the end of it, in parentheses, the name of the original
			author or publisher of that section if known, or else a unique number.
			Make the same adjustment to the section titles in the list of
			Invariant Sections in the license notice of the combined work.</p>

			<p>In the combination, you must combine any sections Entitled "History"
			in the various original documents, forming one section Entitled
			"History"; likewise combine any sections Entitled "Acknowledgements",
			and any sections Entitled "Dedications".  You must delete all sections
			Entitled "Endorsements".</p>

			<h4><a name="section6"></a>6. COLLECTIONS OF DOCUMENTS</h4>

			<p>You may make a collection consisting of the Document and other
			documents released under this License, and replace the individual
			copies of this License in the various documents with a single copy
			that is included in the collection, provided that you follow the rules
			of this License for verbatim copying of each of the documents in all
			other respects.</p>

			<p>You may extract a single document from such a collection, and
			distribute it individually under this License, provided you insert a
			copy of this License into the extracted document, and follow this
			License in all other respects regarding verbatim copying of that
			document.</p>

			<h4><a name="section7"></a>7. AGGREGATION WITH INDEPENDENT WORKS</h4>

			<p>A compilation of the Document or its derivatives with other separate
			and independent documents or works, in or on a volume of a storage or
			distribution medium, is called an "aggregate" if the copyright
			resulting from the compilation is not used to limit the legal rights
			of the compilation's users beyond what the individual works permit.
			When the Document is included in an aggregate, this License does not
			apply to the other works in the aggregate which are not themselves
			derivative works of the Document.</p>

			<p>If the Cover Text requirement of section 3 is applicable to these
			copies of the Document, then if the Document is less than one half of
			the entire aggregate, the Document's Cover Texts may be placed on
			covers that bracket the Document within the aggregate, or the
			electronic equivalent of covers if the Document is in electronic form.
			Otherwise they must appear on printed covers that bracket the whole
			aggregate.</p>

			<h4><a name="section8"></a>8. TRANSLATION</h4>

			<p>Translation is considered a kind of modification, so you may
			distribute translations of the Document under the terms of section 4.
			Replacing Invariant Sections with translations requires special
			permission from their copyright holders, but you may include
			translations of some or all Invariant Sections in addition to the
			original versions of these Invariant Sections.  You may include a
			translation of this License, and all the license notices in the
			Document, and any Warranty Disclaimers, provided that you also include
			the original English version of this License and the original versions
			of those notices and disclaimers.  In case of a disagreement between
			the translation and the original version of this License or a notice
			or disclaimer, the original version will prevail.</p>

			<p>If a section in the Document is Entitled "Acknowledgements",
			"Dedications", or "History", the requirement (section 4) to Preserve
			its Title (section 1) will typically require changing the actual
			title.</p>

			<h4><a name="section9"></a>9. TERMINATION</h4>

			<p>You may not copy, modify, sublicense, or distribute the Document
			except as expressly provided under this License.  Any attempt
			otherwise to copy, modify, sublicense, or distribute it is void, and
			will automatically terminate your rights under this License.</p>

			<p>However, if you cease all violation of this License, then your license
			from a particular copyright holder is reinstated (a) provisionally,
			unless and until the copyright holder explicitly and finally
			terminates your license, and (b) permanently, if the copyright holder
			fails to notify you of the violation by some reasonable means prior to
			60 days after the cessation.</p>

			<p>Moreover, your license from a particular copyright holder is
			reinstated permanently if the copyright holder notifies you of the
			violation by some reasonable means, this is the first time you have
			received notice of violation of this License (for any work) from that
			copyright holder, and you cure the violation prior to 30 days after
			your receipt of the notice.</p>

			<p>Termination of your rights under this section does not terminate the
			licenses of parties who have received copies or rights from you under
			this License.  If your rights have been terminated and not permanently
			reinstated, receipt of a copy of some or all of the same material does
			not give you any rights to use it.</p>

			<h4><a name="section10"></a>10. FUTURE REVISIONS OF THIS LICENSE</h4>

			<p>The Free Software Foundation may publish new, revised versions of the
			GNU Free Documentation License from time to time.  Such new versions
			will be similar in spirit to the present version, but may differ in
			detail to address new problems or concerns.  See
			<a href="http://www.gnu.org/copyleft/">http://www.gnu.org/copyleft/</a>.</p>

			<p>Each version of the License is given a distinguishing version number.
			If the Document specifies that a particular numbered version of this
			License "or any later version" applies to it, you have the option of
			following the terms and conditions either of that specified version or
			of any later version that has been published (not as a draft) by the
			Free Software Foundation.  If the Document does not specify a version
			number of this License, you may choose any version ever published (not
			as a draft) by the Free Software Foundation.  If the Document
			specifies that a proxy can decide which future versions of this
			License can be used, that proxy's public statement of acceptance of a
			version permanently authorizes you to choose that version for the
			Document.</p>

			<h4><a name="section11"></a>11. RELICENSING</h4>

			<p>"Massive Multiauthor Collaboration Site" (or "MMC Site") means any
			World Wide Web server that publishes copyrightable works and also
			provides prominent facilities for anybody to edit those works.  A
			public wiki that anybody can edit is an example of such a server.  A
			"Massive Multiauthor Collaboration" (or "MMC") contained in the site
			means any set of copyrightable works thus published on the MMC site.</p>

			<p>"CC-BY-SA" means the Creative Commons Attribution-Share Alike 3.0 
			license published by Creative Commons Corporation, a not-for-profit 
			corporation with a principal place of business in San Francisco, 
			California, as well as future copyleft versions of that license 
			published by that same organization.</p>

			<p>"Incorporate" means to publish or republish a Document, in whole or in 
			part, as part of another Document.</p>

			<p>An MMC is "eligible for relicensing" if it is licensed under this 
			License, and if all works that were first published under this License 
			somewhere other than this MMC, and subsequently incorporated in whole or 
			in part into the MMC, (1) had no cover texts or invariant sections, and 
			(2) were thus incorporated prior to November 1, 2008.</p>

			<p>The operator of an MMC Site may republish an MMC contained in the site
			under CC-BY-SA on the same site at any time before August 1, 2009,
			provided the MMC is eligible for relicensing.</p>

			<h3><a name="addendum"></a>ADDENDUM: How to use this License for your documents</h3>

			<p>To use this License in a document you have written, include a copy of
			the License in the document and put the following copyright and
			license notices just after the title page:</p>

			<pre>    Copyright (C)  YEAR  YOUR NAME.
							Permission is granted to copy, distribute and/or modify this document
							under the terms of the GNU Free Documentation License, Version 1.3
							or any later version published by the Free Software Foundation;
							with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
							A copy of the license is included in the section entitled "GNU
							Free Documentation License".
			</pre>

			<p>If you have Invariant Sections, Front-Cover Texts and Back-Cover Texts,
			replace the "with � Texts." line with this:</p>

			<pre>    with the Invariant Sections being LIST THEIR TITLES, with the
							Front-Cover Texts being LIST, and with the Back-Cover Texts being LIST.
			</pre>

			<p>If you have Invariant Sections without Cover Texts, or some other
			combination of the three, merge those two alternatives to suit the
			situation.</p>

			<p>If your document contains nontrivial examples of program code, we
			recommend releasing these examples in parallel under your choice of
			free software license, such as the GNU General Public License,
			to permit their use in free software.
			</p>
		\endhtmlonly

 */

/*!
	\page	PGIMCH		ChangeLog
	
	\tableofcontents

	\section	ms05	Milestone : 0.5
	
		\subsection		V049		Version: 0.4-9

			\htmlonly
			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#17</td>
						<td>Documentazione per release</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V048	Version: 0.4-8
		
			\htmlonly
			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#61</td>
						<td>Costanti universali</td>
						<td>&nbsp;</td>
						<td>improvement</td>
					</tr>
					<tr>
						<td align="center" >#18</td>
						<td>Test pre release</td>
						<td>&nbsp;</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#46</td>
						<td>Assegnare il parametro "Frequenza" ai Timer.</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#52</td>
						<td>settaggio di default ( safe )...</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#54</td>
						<td>Sistemare le variabili di "ambiente" e "globali"(calcolate dalle funzioni)</td>
						<td>skymatrix</td>
						<td>Defect</td>
					</tr>
					<tr>
						<td align="center" >#58</td>
						<td>FTOA</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#62</td>
						<td>Non compila con tutti i moduli abilitati</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V045	Version: 0.4-5

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#29</td>
						<td>Seriale TTL manca getione debug su HD44780</td>
						<td>skymatrix</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#50</td>
						<td>ENHANCED mode for PWM module</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#51</td>
						<td>Controllo preproc non funzionante</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
					<tr>
						<td align="center" >#53</td>
						<td>Modulo PWM</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V043		Version: 0.4-3

			\htmlonly
						<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#49</td>
						<td>modulo Seriale rs232</td>
						<td>skymatrix</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#64</td>
						<td>Collocare meglio il file pgim_consants.h</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#66</td>
						<td>Controllo define</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
				</tbody>
			</table>
		\endhtmlonly

		\subsection		V042	Version: 0.4-2

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#2</td>
						<td>Modulo Interrupt </td>
						<td>asyntote</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#41</td>
						<td>Modulo di gestione del canale PWM</td>
						<td>skymatrix</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#59</td>
						<td>Separare gli header delle MCU</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#67</td>
						<td>Inserire controlli di inclusione ai file pubblici</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V041	Version: 0.4-1

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#39</td>
						<td>Compensazione del tempo di interrupt nella Delay</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#47</td>
						<td>razionalizzare il flusso di inclusione degli header</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V040	Version: 0.4-0

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#10</td>
						<td>Fix font SGU with right codes</td>
						<td>skymatrix</td>
						<td>Defect</td>
					</tr>
					<tr>
						<td align="center" >#35</td>
						<td>Gestione dei TIMER</td>
						<td>skymatrix</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#42</td>
						<td>Modulo ADC</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#44</td>
						<td>Grave baco sulla gestione dell'HW public...</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
					<tr>
						<td align="center" >#45</td>
						<td>Supporto MPlabX</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

 		\subsection		V039	Version: 0.3-9

			\htmlonly
			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#25</td>
						<td>Minimal management of hw SPI</td>
						<td>asyntote</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#32</td>
						<td>Migiore gestione dei FONTS</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#33</td>
						<td>gestione della EEPROM interna/td>
						<td>asyntote</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#34</td>
						<td>Uniformare le anomalie presenti in PicGIM</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#37</td>
						<td>Slegare il modulo Timer dala dipendenza dell'interrupt</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#40</td>
						<td>chiamata unica alla Delay passando l'unit� di misura</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>

				</tbody>
			</table>
			\endhtmlonly

		\subsection		V038	Version: 0.3-8

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#16</td>
						<td>Quick internal clock</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#23</td>
						<td>Modalita' di output di PicGim</td>
						<td>asyntote</td>
						<td>Development</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V042	Version: 0.4-2

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#2</td>
						<td>Modulo Interrupt </td>
						<td>asyntote</td>
						<td>Development</td>
					</tr>
					<tr>
						<td align="center" >#41</td>
						<td>Modulo di gestione del canale PWM</td>
						<td>skymatrix</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#59</td>
						<td>Separare gli header delle MCU</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#67</td>
						<td>Inserire controlli di inclusione ai file pubblici</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V037	Version: 0.3-7

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#7</td>
						<td>Check hardware parameters accuracy in all mcu private .h</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#12</td>
						<td>Define per la memoria e2prom</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#20</td>
						<td>Miglioramento gestione ailitazione/disabilitazione modulir</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V036	Version: 0.3-6

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#3</td>
						<td>Improve documentation to get started</td>
						<td>skymatrix</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#4</td>
						<td>Header private and public</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
					<tr>
						<td align="center" >#11</td>
						<td>Miglioramento gestione settaggio alimentazione</td>
						<td>asyntote</td>
						<td>Improvement</td>
					</tr>
					<tr>
						<td align="center" >#19</td>
						<td>Correct "pgim_hardware_setup.h" and his public one.</td>
						<td>asyntote</td>
						<td>Defect</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

		\subsection		V010	Version: 0.1-0

			\htmlonly

			<table class="cl_table" width="60%" border="0" >
				<thead>
					<tr>
						<th width="10%" align="center" >Ticket</th>
						<th width="60%" >Summary</th>
						<th width="15%" align="center" >Owner</th>
						<th width="15%" align="center" >Type</th>
					</tr>
				</thead>
				<tbody>
					<tr>
						<td align="center" >#1</td>
						<td>gK_ezsetup</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#6</td>
						<td>Test e-mail report</td>
						<td>asyntote</td>
						<td>Task</td>
					</tr>
					<tr>
						<td align="center" >#15</td>
						<td>Ricerca del nome definitivo per il progetto</td>
						<td>skymatrix</td>
						<td>Task</td>
					</tr>
				</tbody>
			</table>
			\endhtmlonly

*/



