//
// pgim_constants.h
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

/*!		\file			pgim_constants.h
		\version		0.5-0
		\date			2002 - 2014
		\brief			Mathematical, physical and chemistry constants.
		\details		
		\author			Danilo Zannoni (AsYntote)
		\author			Corrado Tumiati (SkyMatrix)
		\copyright		Released under the terms of the GNU General Public License v2<BR>
						[ http://gkript.org/gk_gpl_v2.php ]
		\attention		This is not a file defined as public and therefore would not be edited. \n
						We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_CONSTANTS_H_
	#define _PGIM_CONSTANTS_H_

	#if ( PGIM_CONSTANTS == PG_ENABLE )

		////////////////////////////////////////////////////////////////////////////////
		//
		//		M A T H E M A T I C A L   C O N S T A N T S
		//
		////////////////////////////////////////////////////////////////////////////////
		#define	PG_CONSTANTS_PI							3.1415926535897						//!< Pi-Greek
		#define	PG_CONSTANTS_EULER						2.7182818284590						//!< Euler's number. Base of the natural logarithm

		
		////////////////////////////////////////////////////////////////////////////////
		//
		//		P H Y S I C A L   C O N S T A N T S
		//
		////////////////////////////////////////////////////////////////////////////////
		#define	PG_CONSTANTS_LIGHT_VELOCITY				299792458							//!< Speed of light. Unit of measure: [m/s]
		#define	PG_CONSTANTS_BOLTZMANN					1.3806488 * 10^-23					//!< Boltzmann's constant. Unit of measure: [J/K]
		#define	PG_CONSTANTS_PLANK_JS					6.62606957 * 10^-34					//!< Planck's constant. Unit of measure: [J*s]
		#define	PG_CONSTANTS_PLANK_EV					4.13562852 * 10^-15					//!< Planck's constant. Unit of measure: [eV*s]
		#define	PG_CONSTANTS_ELEMENTARY_CHARGE			1.602176565 * 10^-19				//!< Elementary charge. Unit of measure: [C]
		#define	PG_CONSTANTS_GRAVITY_ACCELERATION		9.80665								//!< Gravitational acceleration. Unit of measure: [m/(s^2)]		
		
		
		////////////////////////////////////////////////////////////////////////////////
		//
		//		C H E M I S T R Y   C O N S T A N T S
		//
		////////////////////////////////////////////////////////////////////////////////
		#define	PG_CONSTANTS_AVOGADRO					6.02214129 * 10^23					//!< Avogadro's number

		
	#endif
#endif /* _PGIM_CONSTANTS_H_ */

/*!
	\page	SWG_constants		Various constants

		\htmlonly
			<IMG src="constants.png" align="center" border="0" ><br><br>
		\endhtmlonly
		
		The \b CONSTANTS module it is a collection of mathematical, physical and chemical constants. \n
		Allows their rapid use, without the necessity of having to know or search them.

		\htmlonly
				<br><br><br><br>
		\endhtmlonly

 	\attention	Here a link to the file : \ref pgim_constants.h \n
				This is not a file defined as public and therefore would not be edited. \n
				We suggest that you edit this file only if necessary and only if you know what you are doing. \n
 */

