/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#include "control.h"
#include "pulse.h"
#include "resolver.h"

#include "chprintf.h"

#define PHASE_PAIR	10

int32_t cl_degree;
int32_t cl_degree_ass;
int32_t cl_width;

int32_t cl_rdvel;
int32_t cl_dos;
int32_t cl_lot;
int32_t cl_par;
int32_t cl_different;
int32_t cl_direction;
int32_t cl_cycle;

/* Auto calib values */
bool auto_calib;
uint32_t task_cycle = 0;
uint32_t calib_degree = 0;

static THD_WORKING_AREA(control_wa, 128);
static THD_FUNCTION(control, p) {
  systime_t time; 

  (void)p;
  chRegSetThreadName("blinker");
  time = chVTGetSystemTime();
  while (TRUE) {
  	time += US2ST(100);

  	palTogglePad(GPIOD, GPIOD_LED6);
/* -------- Resolver read -------- */
  	cl_degree = resolverRead();

  	cl_rdvel = rsValues(1);
  	cl_dos = rsValues(2);
  	cl_lot = rsValues(3);
  	cl_par = rsValues(4);
  	cl_different = 58;

	cl_degree_ass = resolverCalcDeg(cl_degree, PHASE_PAIR);
	cl_degree = resolverDegOffset(cl_degree_ass, cl_different);
  	
/* ------------------------------- */
	if (auto_calib == FALSE)
	{
		task_cycle = 0;
		calib_degree = 0;

		/* -----Limit & block section----- */

		/* ------------------------------- */

		/* -----Motor control section----- */

		pulseWidth(cl_width);
		pulseDirection(cl_direction);
		pulseControl(cl_degree);
	}

	else{
		task_cycle++;
		if (task_cycle > 100)
		{
			task_cycle = 0;
			calib_degree++;
			calib_degree = calib_degree > 359 ? 0 : calib_degree;
		}
		pulseWidth(5000);
		pulseDirection(1);
		pulseControl(calib_degree);
	}

/* ------------------------------- */
	chThdSleepMicroseconds(10);
  	//chThdSleepUntil(time);
  }
  return 0;
}

void controlInit(void) {
	cl_width = 5000;
	cl_direction = 1;
	auto_calib = FALSE;
	chThdCreateStatic(control_wa, sizeof(control_wa), NORMALPRIO, control, NULL);
}

void degreeCalib(void) {
	auto_calib = TRUE;
}

void cmd_controlSet(BaseSequentialStream *chp, int argc, char *argv[]) {
 
  (void)argc;
  (void)argv;

  uint32_t in;
 
  if ((argc == 2) && (strcmp(argv[0], "direction") == 0)){
    in = atol(argv[1]);

    if (in < 1 || in > 2)
    {
      goto ERROR;
    }
    else
    {
      cl_direction = (uint32_t)in;
      chprintf(chp,"Set direction: %d\r\n", cl_direction);
      return;
    }
  }

  else{
  goto ERROR;
  }

ERROR:
  chprintf(chp, "Usage: direction (1 - 2)\r\n");
  return;
}

void cmd_autoCalib(BaseSequentialStream *chp, int argc, char *argv[]) {
 
  (void)argc;
  (void)argv;

  chprintf(chp,"Automatic calibration!\r\n");
}

void cmd_controlValues(BaseSequentialStream *chp, int argc, char *argv[]) {

  int i;

  (void)argc;
  (void)argv;
  chprintf(chp, "\x1B\x63");
  chprintf(chp, "\x1B[2J");
  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
      chprintf(chp, "\x1B[%d;%dH", 0, 0);

      chprintf(chp, "cl_degree: %15d\r\n", cl_degree);
      chprintf(chp, "cl_rdvel: %15d\r\n", cl_rdvel);
      chprintf(chp, "cl_dos: %15d\r\n", cl_dos);
      chprintf(chp, "cl_lot: %15d\r\n", cl_lot);
      chprintf(chp, "cl_par: %15d\r\n", cl_par);
      chprintf(chp, "cl_different: %15d\r\n", cl_different);
      chprintf(chp, "\r\n\r\n");
      chprintf(chp, "auto_calib: %15d\r\n", auto_calib);
      chprintf(chp, "calib_degree: %15d\r\n", calib_degree);

      chThdSleepMilliseconds(10);
  }
}