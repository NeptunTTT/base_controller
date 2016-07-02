#ifndef RESOLVER_H_INCLUDED
#define RESOLVER_H_INCLUDED

#include "ch.h"
#include "hal.h"

void resolverInit(void);
void resolverCalc(void);
long map(long x, long in_min, long in_max, long out_min, long out_max);

void cmd_resolverValues(BaseSequentialStream *chp, int argc, char *argv[]);

#endif