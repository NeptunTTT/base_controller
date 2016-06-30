#ifndef PULSE_H_INCLUDED
#define PULSE_H_INCLUDED

#include "ch.h"
#include "hal.h"

enum logStates
{
  PULSE_AB,
  PULSE_AC,
  PULSE_BC,
  PULSE_BA,
  PULSE_CA,
  PULSE_CB,
};

void pulseInit(void);
void pulseCalc(void);
void pulseControl(uint32_t degree);
void pulseWidth(uint32_t in);

void cmd_pulseValues(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_get_data(BaseSequentialStream *chp, int argc, char *argv[]);

#endif