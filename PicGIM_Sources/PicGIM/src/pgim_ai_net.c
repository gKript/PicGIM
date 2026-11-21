/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ai_net.c
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers

	\file		pgim_ai_net.c
	\brief		Integer MLP inference. See pgim_ai_net.h for the layer formula.
	\attention	Not compiled with C18 and not tested on hardware yet.
	            Multiplications are done with explicit casts: C18 would truncate an int*int product to 16 bit.
*/

#include "picgim.h"
#include "pgim_ai_model.h"

#if ( PGIM_AI_INPUT == PG_ENABLE )

	#if ( PG_AI_NUM_INPUTS > PGIM_AI_MAX_CHANNELS )
		#error "The model needs more inputs than PGIM_AI_MAX_CHANNELS (pgim_ai_input_setup_public.h)"
	#endif

	//---[ Ping-pong activation buffers ]---
	static pg_ai_out_t	pg_ai_buf_a[ PG_AI_MAX_WIDTH ];
	static pg_ai_out_t	pg_ai_buf_b[ PG_AI_MAX_WIDTH ];

	//---[ One layer: x (in elements) -> y (out elements) ]---
	static void pg_ai_net_layer		( const __rom pg_ai_layer * L , const pg_ai_out_t * x , pg_ai_out_t * y );

	static void pg_ai_net_layer( const __rom pg_ai_layer * L , const pg_ai_out_t * x , pg_ai_out_t * y ) {
		_pg_Uint8		o;
		_pg_Uint8		i;
		_pg_int32		acc;
		_pg_int32		half;
		_pg_Uint16		base;

		for( o = 0; o < L->out; o++ ) {
			acc = L->b[ o ];
			base = (_pg_Uint16) o * (_pg_Uint16) L->in;
			for( i = 0; i < L->in; i++ ) {
				#if ( PGIM_AI_OUT_BITS == 8 )
					//|x|,|w| <= 127: the product fits in 16 bit, so the 8x8 hardware multiply is enough.
					acc += (_pg_int16) x[ i ] * (_pg_int16) L->w[ base + i ];
				#else
					acc += (_pg_int32) x[ i ] * (_pg_int32) L->w[ base + i ];
				#endif
			}
			if( L->shift > 0 ) {
				half = (_pg_int32) 1 << ( L->shift - 1 );
				acc += half;
			}
			acc >>= L->shift;						//arithmetic shift
			if( ( L->relu == PG_YES ) && ( acc < 0 ) ) {
				acc = 0;
			}
			if( acc > PG_AI_OUT_MAX ) {
				acc = PG_AI_OUT_MAX;
			}
			if( acc < -PG_AI_OUT_MAX ) {
				acc = -PG_AI_OUT_MAX;
			}
			y[ o ] = (pg_ai_out_t) acc;
		}
	}

	//---[ Whole network ]---
	_pg_Uint8 pg_ai_net_infer( const pg_ai_out_t * in , pg_ai_out_t * scores ) {
		_pg_Uint8				l;
		_pg_Uint8				o;
		_pg_Uint8				best;
		const pg_ai_out_t *		src;
		pg_ai_out_t *			dst;
		const __rom pg_ai_layer *	L;

		src = in;
		for( l = 0; l < PG_AI_NUM_LAYERS; l++ ) {
			L = &PG_AI_LAYERS[ l ];
			dst = ( ( l & 1 ) == 0 ) ? pg_ai_buf_a : pg_ai_buf_b;
			pg_ai_net_layer( L , src , dst );
			src = dst;
		}

		//src now points to the last layer output (PG_AI_NUM_CLASSES elements)
		best = 0;
		for( o = 1; o < PG_AI_NUM_CLASSES; o++ ) {
			if( src[ o ] > src[ best ] ) {
				best = o;
			}
		}
		if( scores != 0 ) {
			for( o = 0; o < PG_AI_NUM_CLASSES; o++ ) {
				scores[ o ] = src[ o ];
			}
		}
		return( best );
	}

#endif
