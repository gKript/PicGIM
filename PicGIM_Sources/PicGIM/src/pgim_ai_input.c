/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ai_input.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers

	\file		pgim_ai_input.c
	\brief		Integer normalization of sensor inputs. See pgim_ai_input.h for the formula.
	\attention	Not compiled with C18 and not tested on hardware yet.
*/

#include "picgim.h"

#if ( PGIM_AI_INPUT == PG_ENABLE )

	static _pg_Uint16	pg_ai_input_clamp_raw	( const __rom pg_ai_channel_cfg * c , _pg_Uint16 raw , _pg_Uint8 * saturated );
	static pg_ai_out_t	pg_ai_input_convert		( const __rom pg_ai_channel_cfg * c , _pg_Uint16 raw );

	//---[ Clamp raw into [in_min, in_max] ]---
	static _pg_Uint16	pg_ai_input_clamp_raw( const __rom pg_ai_channel_cfg * c , _pg_Uint16 raw , _pg_Uint8 * saturated ) {
		*saturated = PG_NO;
		if( raw < c->in_min ) {
			*saturated = PG_YES;
			return( c->in_min );
		}
		if( raw > c->in_max ) {
			*saturated = PG_YES;
			return( c->in_max );
		}
		return( raw );
	}

	//---[ Linear map of an already clamped raw value ]---
	static pg_ai_out_t	pg_ai_input_convert( const __rom pg_ai_channel_cfg * c , _pg_Uint16 raw ) {
		_pg_Uint32	prod;
		_pg_Uint16	diff;
		_pg_Uint32	value;

		diff = raw - c->in_min;							//0 .. (in_max - in_min) <= 65535
		prod = (_pg_Uint32) diff * (_pg_Uint32) c->scale;	//max 65535 * 65535 < 2^32
		value = prod >> c->shift;						//0 .. 2*OUT_MAX (+ rounding)
		if( value > ( 2UL * PG_AI_OUT_MAX ) ) {
			value = 2UL * PG_AI_OUT_MAX;				//guard against rounding overflow
		}
		return( (pg_ai_out_t) ( (_pg_int32) value - PG_AI_OUT_MAX ) );
	}

	//---[ Normalize n channels ]---
	_pg_Uint8 pg_ai_input_normalize( const __rom pg_ai_channel_cfg * cfg , const _pg_Uint16 * raw , const _pg_Uint8 * ok , pg_ai_out_t * out , pg_ai_flags * flags , _pg_Uint8 n ) {
		_pg_Uint8	i;
		_pg_Uint8	sat;
		_pg_Uint16	clamped;

		if( ( cfg == 0 ) || ( raw == 0 ) || ( ok == 0 ) || ( out == 0 ) || ( flags == 0 ) ) {
			return( PG_NOK );
		}
		if( ( n < 1 ) || ( n > PGIM_AI_MAX_CHANNELS ) ) {
			return( PG_NOK );
		}

		flags->fault_mask = 0;
		flags->sat_mask = 0;

		for( i = 0; i < n; i++ ) {
			if( cfg[ i ].enabled != PG_YES ) {
				out[ i ] = cfg[ i ].fallback;		//disabled: fallback, no bit set
				continue;
			}
			if( ok[ i ] != PG_OK ) {
				out[ i ] = cfg[ i ].fallback;		//sensor fault
				flags->fault_mask |= (_pg_Uint16) ( (_pg_Uint16) 1 << i );
				continue;
			}
			clamped = pg_ai_input_clamp_raw( &cfg[ i ] , raw[ i ] , &sat );
			if( sat == PG_YES ) {
				flags->sat_mask |= (_pg_Uint16) ( (_pg_Uint16) 1 << i );
			}
			out[ i ] = pg_ai_input_convert( &cfg[ i ] , clamped );
		}
		return( PG_OK );
	}

#endif
