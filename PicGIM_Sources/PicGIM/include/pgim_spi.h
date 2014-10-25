//
// pgim_spi.h
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

/*!		\file			pgim_spi.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			The SPI module for PicGIM
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_SPI_H_
	#define _PGIM_SPI_H_

	#if	( PGIM_SPI == PG_ENABLE )
	
		#define	PG_SPI_ALREADY_OPEN				10					//!<	The return value indicates that the SPI port is already open.
		#define	PG_SPI_ALREADY_CLOSE			11					//!<	The return value indicates that the SPI port is already closed.
		#define	PG_SPI_ERROR					-1					//!<	The return value indicates a general ERROR.
	
		#define	PG_SPI_0						0					//!<	Port SPI 0 selection
		#define	PG_SPI_1						1					//!<	Port SPI 1 selection
		#define	PG_SPI_2						2					//!<	Port SPI 2 selection
		
		#define	PG_SPI_MASTER_FOSC_4			SPI_FOSC_4			//!<	System clock divided by 4.
		#define	PG_SPI_MASTER_FOSC_16			SPI_FOSC_16			//!<	System clock divided by 16.
		#define	PG_SPI_MASTER_FOSC_64			SPI_FOSC_64			//!<	System clock divided by 64.
		#define	PG_SPI_MASTER_FOSC_TMR2			SPI_FOSC_TMR2		//!<	System clock from TMR2.
		#define	PG_SPI_SLAVE_SS_ENABLE			SLV_SSON			//!<	Slave select pin enable.
		#define	PG_SPI_SLAVE_SS_DISABLE			SLV_SSOFF			//!<	Slave select pin disable
		
		/*!
			\brief	This function opens an SPI port.
			\param	portnumber		Indicates which SPI port you want to open. \n Possible values : \n
						\b PG_SPI_0 : Port SPI 0 selection \n
						\b PG_SPI_1 : Port SPI 1 selection \n 
			\param	sync_mode		Indicates if the SPI port must be configured as MASTER or SLAVE. \n
						If MASTER indicates which FOSC. \n
						If SLAVE indicates whether the SS pin enabled or not. \n 
						Possible values : \n
						\b PG_SPI_MASTER_FOSC_4 : System clock divided by 4. \n
						\b PG_SPI_MASTER_FOSC_16 : System clock divided by 16. \n
						\b PG_SPI_MASTER_FOSC_64 : System clock divided by 64. \n
						\b PG_SPI_MASTER_FOSC_TMR2 : System clock from TMR2. \n
						\b PG_SPI_SLAVE_SS_ENABLE : Slave select pin enable. \n
						\b PG_SPI_SLAVE_SS_DISABLE : Slave select pin disable \n
			\param	bus_mode		Settings for SPI bus mode. This function use the DEFINE of the standard C18 library. \n Possible values : \n
						\b MODE_00 : Setting for SPI bus mode 0,0 ( idle low , shift on rising edge ) \n
						\b MODE_01 : Setting for SPI bus mode 0,1 ( idle low , shift on falling edge ) \n
						\b MODE_10 : Setting for SPI bus mode 1,0 ( idle HIGH , shift on falling edge ) \n
						\b MODE_11 : Setting for SPI bus mode 1,1 ( idle HIGH , shift on rising edge ) \n
			\param	smp_phase		Settings for SPI smp phase. This function use the DEFINE of the standard C18 library. \n Possible values : \n
						\b SMPEND : Input data sample at the end of data out. \n
						\b SMPMID : Input data sample at the middle of data out. \n
                        \warning  As \e portnumber \b PG_SPI_1 is available only for \b P18F97J60
			\test	This function set the error status if the \ref SWG_error is enabled . \n \n
						\b PG_OK : Everything is ok. \n
						\b PG_SPI_ALREADY_OPEN : The return value indicates that the SPI port is already open. \n
						\b PG_SPI_ERROR : The return value indicates an ERROR in configuration. \n
		*/
		void	pg_spi_open					( _pg_Uint8 portnumber , _pg_Uint8 sync_mode, _pg_Uint8 bus_mode, _pg_Uint8 smp_phase );

		/*!
			\brief	This function is useful for changing settings on the fly for an SPI port already open.
			\param	portnumber		Indicates which SPI port you want to open. \n Possible values : \n
						\b PG_SPI_0 : Port SPI 0 selection \n
						\b PG_SPI_1 : Port SPI 1 selection \n
						\b PG_SPI_2 : Port SPI 2 selection \n
			\param	sync_mode		Indicates if the SPI port must be configured as MASTER or SLAVE. \n
						If MASTER indicates which FOSC. \n
						If SLAVE indicates whether the SS pin enabled or not. \n 
						Possible values : \n
						\b PG_SPI_MASTER_FOSC_4 : System clock divided by 4. \n
						\b PG_SPI_MASTER_FOSC_16 : System clock divided by 16. \n
						\b PG_SPI_MASTER_FOSC_64 : System clock divided by 64. \n
						\b PG_SPI_MASTER_FOSC_TMR2 : System clock from TMR2. \n
						\b PG_SPI_SLAVE_SS_ENABLE : Slave select pin enable. \n
						\b PG_SPI_SLAVE_SS_DISABLE : Slave select pin disable \n
			\param	bus_mode		Settings for SPI bus mode. This function use the DEFINE of the standard C18 library. \n Possible values : \n
						\b MODE_00 : Setting for SPI bus mode 0,0 ( idle low , shift on rising edge ) \n
						\b MODE_01 : Setting for SPI bus mode 0,1 ( idle low , shift on falling edge ) \n
						\b MODE_10 : Setting for SPI bus mode 1,0 ( idle HIGH , shift on falling edge ) \n
						\b MODE_11 : Setting for SPI bus mode 1,1 ( idle HIGH , shift on rising edge ) \n
			\param	smp_phase		Settings for SPI smp phase. This function use the DEFINE of the standard C18 library. \n Possible values : \n
						\b SMPEND : Input data sample at the end of data out. \n
						\b SMPMID : Input data sample at the middle of data out. \n
			\test	This function set the error status if the \ref SWG_error is enabled . \n \n
						\b PG_OK : Everything is ok. \n
						\b PG_SPI_ERROR : The return value indicates a general ERROR. \n
		*/
		void	pg_spi_reopen				( _pg_Uint8 portnumber , _pg_Uint8 sync_mode, _pg_Uint8 bus_mode, _pg_Uint8 smp_phase );
		
		/*!
			\brief	This function closes a previously opened SPI port.
			\param	portnumber		Indicates which SPI port you want to open. \n Possible values : \n
						\b PG_SPI_0 : Port SPI 0 selection \n
						\b PG_SPI_1 : Port SPI 1 selection \n
						\b PG_SPI_2 : Port SPI 2 selection \n
			\test	This function set the error status if the \ref SWG_error is enabled . \n \n
						\b PG_OK : Everything is ok. \n
						\b PG_SPI_ALREADY_CLOSE : The return value indicates that the SPI port is already close. \n
						\b PG_SPI_ERROR : The return value indicates a general ERROR. \n
		*/
		void	pg_spi_close				( _pg_Uint8 portnumber );

	#endif

#endif /* _PGIM_SPI_H_ */



/*!	\page 		HWI_spi			SPI [Serial Protocol Interface]
	
		\tableofcontents

		\image html	spi.png
	
		\b PicGIM with the \b SPI module means a wrapping to the \b C18 \b standard \b library. \n
		\b PicGIM only provides a more simple and intuitive function of \b OpenSPI the standard library. \n
		The \b CloseSPI was added only for consistency in controls. \n
		
		\note	This module has no initialization function and therefore does not set any default.
	
		\n \n

		\section	spiconf		Module configuration

			\htmlonly <hr> \endhtmlonly
			\endcode
			<p>
			In order to use this module, it must be enabled in: \n
				\arg \b pgim_module_setup_public.h : the main management file for the modules that must be edited to enable only the required modules for your project. \n In this file there are these configurations  : \n \n
					&nbsp;&nbsp;&nbsp;&nbsp; \ref spiconfen  
					
					&nbsp; \n 

				\attention	Here a link to the file : \ref pgim_spi.h \n
							This is not a file defined as public and therefore would not be edited. \n
							We suggest that you edit this file only if necessary and only if you know what you are doing. \n
			</p>
			\n \n \n

			\subsection	spiconfen		Module enabling
				\htmlonly <hr> \endhtmlonly
				\code
					#define PGIM_SPI							PG_DISABLE
				\endcode
					This define enables or disables the module.<br>
				\htmlonly
					It must be:<br>
				\endhtmlonly
					\arg \b PG_ENABLE : Interrupts module enabled.
					\arg \b PG_DISABLE : Interrupts module disabled.
					\endcode
					
				\subsubsection	spimodenref		References
					\li \e File : pgim_module_setup_public.h \n
					\li \e Reference : \ref PGIM_SPI \n
				
		\section	spicsdwun		Functions
			\htmlonly <hr> \endhtmlonly
			After it has been enabled and configured the module you can refer to this set of functions to use it. \n \n

			\subsection	spiprivfunc	Private functions
				\endhtmlcode

				This module has not any private function.

			\htmlonly <br> \endhtmlonly

			\subsection	spipubfunc	Public functions
				\endcode
				
				\arg \b pg_spi_open() : This function opens an SPI port.
				\arg \b pg_spi_reopen() : This function is useful for changing settings on the fly for an SPI port already open.
				\arg \b pg_spi_close() : This function closes a previously opened SPI port.

				\endcode
				
			\htmlonly <br> \endhtmlonly
			


	\section	spiexampleuse	A code example
	
	Here is a simple example of how to use the module in your code. 
	\warning	In order to compile this example, the module must be enabled and properly configured.
	
	\code
		...
		
		if ( pg_spi_open( PG_SPI_0 , PG_SPI_MASTER_FOSC_64 , MODE_00 , SMPEND ) == PG_OK ) {
			putsSPI( data );
			pg_spi_reopen( PG_SPI_0 , PG_SPI_MASTER_FOSC_4 , MODE_00 , SMPEND );	//Changed FOSC to 4
			putsSPI( data );
		}
		pg_spi_close( PG_SPI_0 );		// the control on SSPCON1bits.SSPEN is inside this function.
		
		...
	\endcode

	\htmlonly <br><br> \endhtmlonly

*/


