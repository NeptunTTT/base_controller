/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#ifndef RESOLVER_H_INCLUDED
#define RESOLVER_H_INCLUDED

#include "ch.h"
#include "hal.h"

int32_t resolverRead();
uint32_t resolverCalcDeg(uint16_t position, uint16_t phase_pair);
uint32_t resolverDegOffset(uint16_t position, int16_t offset);

void resolverInit(void);
long map(long x, long in_min, long in_max, long out_min, long out_max);
uint16_t rsValues(uint32_t num);

void cmd_resolverValues(BaseSequentialStream *chp, int argc, char *argv[]);

#endif