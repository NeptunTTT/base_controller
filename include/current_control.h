/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#ifndef CURRENT_CONTROL_H_INCLUDED
#define CURRENT_CONTROL_H_INCLUDED

#include "ch.h"
#include "hal.h"

uint32_t currentControlPID (int16_t Input, int16_t Set, int32_t MaxResult, int32_t MinResult, int16_t k_p, int16_t k_i, int16_t k_d, int32_t MaxP, int32_t MaxI, int32_t MaxD);

#endif