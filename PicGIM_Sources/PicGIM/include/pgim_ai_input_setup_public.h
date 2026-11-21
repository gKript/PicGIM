/*
	Editor set :	Fixed width fonts - Expandtab OFF - Tabstop 4

	File name :		pgim_ai_input_setup_public.h
	Project :		PicGim - Generic Information Manager for Microchip (C) PIC18F (R) family uControllers

	\file		pgim_ai_input_setup_public.h
	\brief		PUBLIC configuration of the AI input normalization module.
	\attention	This file is defined as public and therefore must be edited for proper configuration.
	            Output width is a compile-time choice per project (see SYNC/COMM_CONTRACT.md, section 4.1).
*/

#ifndef _PGIM_AI_INPUT_SETUP_PUBLIC_H_
	#define _PGIM_AI_INPUT_SETUP_PUBLIC_H_

	//---[ Output width ]---
	//	Must be: 8 || 16
	//	Same value must be used by the model header generated on Gim (SYNC/COMM_CONTRACT.md 4.1).
	#define PGIM_AI_OUT_BITS						8

	//---[ Module enable ]---
	//	Must be: PG_ENABLE || PG_DISABLE. Keep here until the module is added to pgim_module_setup_public.h.
	#define PGIM_AI_INPUT							PG_ENABLE

	//---[ Maximum number of input channels ]---
	//	Must be: 1..16 (masks are 16 bit)
	#define PGIM_AI_MAX_CHANNELS					8

#endif
