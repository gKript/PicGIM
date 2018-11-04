/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_dds_ad9851.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers
	Author :		Danilo Zannoni (asyntote) - Corrado Tumiati (skymatrix)

	Current Milestone :		0.5
	Current version :		0.5-0
	Since version :			0.1-0
	Deprecated version :	This file is not deprecated.

	See also related :		pgim_dds_ad9851.c

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
		\file		pgim_dds_ad9851.h
		\version	0.5-0
		\date		2002 - 2015
		\brief		To easily use the DDS AD9851 device.
		\author		Danilo Zannoni (asyntote)
		\author		Corrado Tumiati (skymatrix)
		\copyright	PicGIM is part of the We.PIC project. \n
					PicGIM is released under the terms of the GNU General Public License V3. \n
					Each part of <b>We.PIC project</b> is released under the GNU General Public License V3. \n
					[ http://www.gnu.org/licenses/gpl-3.0.html ]
		\attention	This is not a file defined as public and therefore would not be edited. \n We suggest that you edit this file only if necessary and only if you know what you are doing. \n
*/

#ifndef _PGIM_DDS_AD9851_H_
	#define _PGIM_DDS_AD9851_H_

	#if ( PGIM_DDS_AD9851 == PG_ENABLE )
		void pg_dds_ad9851_set_freq			( float dds_fout );
		void pg_dds_ad9851_sweep_ss			( float f_start, float f_stop, float f_step, _pg_Uint16 step_delay );
		void pg_dds_ad9851_sweep_cs			( float f_center, float f_span, float f_step, _pg_Uint8 direction , _pg_Uint16 step_delay ); //!< Must be PG_FORWARD || PG_REVERSE
		void pg_dds_ad9851_reset			( void ); //!< It does NOT overwrite frequency word input register (that is undefined at startup and unchanged after reset)
		void pg_dds_ad9851_word_clock		( void );
		void pg_dds_ad9851_freq_update		( void ); //!< Never do a "frequency update" before writing programming word
	#endif
	
#endif /*_PGIM_DDS_AD9851_H_ */


