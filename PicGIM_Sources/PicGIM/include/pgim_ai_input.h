/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ai_input.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers

	\file		pgim_ai_input.h
	\brief		Normalization of heterogeneous sensor inputs into a fixed-width vector for an AI model.
	\attention	Not a public file. Parameters per channel come from the model exported by Gim (SYNC/COMM_CONTRACT.md, section 4).
	            Integer only: no _pg_float is used in this module.

	Conversion for one channel (signed output, OUT_MAX = 2^(OUT_BITS-1) - 1):
	    diff = raw - in_min          (raw is clamped to [in_min, in_max] first)
	    out  = ((diff * scale) >> shift) - OUT_MAX
	    scale = ceil( 2*OUT_MAX * 2^shift / (in_max - in_min) ), computed by Gim with the largest shift in 0..16 that keeps scale <= 65535.
	    (ceil, not floor: otherwise in_max would map to OUT_MAX-1.)
	    Result range: -OUT_MAX .. +OUT_MAX.
*/

#ifndef _PGIM_AI_INPUT_H_
	#define _PGIM_AI_INPUT_H_

	#include "pgim_ai_input_setup_public.h"

	#if ( PGIM_AI_OUT_BITS == 8 )
		typedef signed char		pg_ai_out_t;		//!< explicit signed: C18 plain char is unsigned
		#define PG_AI_OUT_MAX							127
	#elif ( PGIM_AI_OUT_BITS == 16 )
		typedef _pg_int16		pg_ai_out_t;
		#define PG_AI_OUT_MAX							32767
	#else
		#error "PGIM_AI_OUT_BITS must be 8 or 16 (pgim_ai_input_setup_public.h)"
	#endif

	#if ( ( PGIM_AI_MAX_CHANNELS < 1 ) || ( PGIM_AI_MAX_CHANNELS > 16 ) )
		#error "PGIM_AI_MAX_CHANNELS must be between 1 and 16"
	#endif

	//---[ Per-channel configuration (ROM table exported by Gim) ]---
	typedef struct {
		_pg_Uint16		in_min;			//!< Lowest expected raw value (training range).
		_pg_Uint16		in_max;			//!< Highest expected raw value (training range). Must be > in_min.
		_pg_Uint16		scale;			//!< Precomputed multiplier (see file header).
		_pg_Uint8		shift;			//!< Right shift applied after the multiplication.
		pg_ai_out_t		fallback;		//!< Output used when the channel is in fault or disabled.
		_pg_Uint8		enabled;		//!< PG_YES = active, PG_NO = forced to fallback without setting fault bit.
	} pg_ai_channel_cfg;

	//---[ Result flags (one bit per channel) ]---
	typedef struct {
		_pg_Uint16		fault_mask;		//!< Bit i set: channel i reported a sensor fault by the driver.
		_pg_Uint16		sat_mask;		//!< Bit i set: channel i raw value was outside [in_min, in_max] and was saturated.
	} pg_ai_flags;

	#if ( PGIM_AI_INPUT == PG_ENABLE )
		/*!
			\brief			Normalize n channels into the output vector.
			\param cfg		Pointer to the n channel configurations.
			\param raw		Raw values read by the sensor drivers, one per channel.
			\param ok		Driver status per channel: PG_OK = valid, PG_NOK = sensor fault.
			\param out		Output vector, n elements.
			\param flags	Receives fault_mask and sat_mask. Cleared at the beginning of the call.
			\param n		Number of channels (1 .. PGIM_AI_MAX_CHANNELS).
			\return			PG_OK, or PG_NOK on invalid arguments.
		*/
		_pg_Uint8	pg_ai_input_normalize				( const __rom pg_ai_channel_cfg * cfg , const _pg_Uint16 * raw , const _pg_Uint8 * ok , pg_ai_out_t * out , pg_ai_flags * flags , _pg_Uint8 n );
	#endif

#endif
