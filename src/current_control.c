/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#include "current_control.h"

static double p_tag;
static double i_tag;
static double d_tag;
static int32_t result;
static double eelozo;
static double e_tag;

uint32_t currentControlPID (int16_t Input, int16_t Set, int32_t MaxResult, int32_t MinResult, int16_t k_p, int16_t k_i, int16_t k_d, int32_t MaxP, int32_t MaxI, int32_t MaxD)
{	 
	e_tag = Set - Input;

	/* Proportional */
	p_tag = k_p * e_tag;
	if (p_tag > MaxP){
		p_tag = MaxP;
	}
	else if (p_tag < (-1 * MaxP)){
		p_tag = -1 * MaxP;
	}
	/* ----------- */

	/* Integral */
	i_tag += (k_i * e_tag);
	if (i_tag > MaxI){
		i_tag = MaxI;
	}
	else if (i_tag < (-1 * MaxI)){
		i_tag = -1 * MaxI;
	}
	/* ----------- */

	/* Derivative */
	d_tag = 0;
	/*d_tag = k_d * ( e_tag - eelozo);
	if (d_tag > MaxD){
		d_tag = MaxD;
	}
	else if (d_tag < (-1 * MaxD)){
		d_tag = -1 * MaxD;
	}*/
	/* ----------- */

	/* Result */
	result = (int32_t)(p_tag + i_tag + d_tag);

	if (result > MaxResult){
		result = MaxResult;
	}
	if (result < MinResult){
		result = MinResult;
	}

	eelozo = e_tag;

	return result;
}