/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "test.h"
#include "console.h"
#include "pulse.h"
#include "resolver_SPI.h"
#include "resolver_ICU.h"
#include "control.h"


/*===========================================================================*/
/* Generic code.                                                             */
/*===========================================================================*/

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(thread1_wa, 128);
static THD_FUNCTION(thread1, p) {

  (void)p;
  chRegSetThreadName("blinker");
  while (TRUE) {
    systime_t time;
    time = 500;
    //palSetPad(GPIOD, GPIOD_LED6);
    chThdSleepMilliseconds(time/10);
    //palClearPad(GPIOD, GPIOD_LED6);
    chThdSleepMilliseconds(time);
  }
  return 0; /* Never executed.*/
}
/*
 * 1ms Task
 */
static THD_WORKING_AREA(task1ms_wa, 256);
static THD_FUNCTION(task1ms, p) {
  systime_t time; 

  (void)p;
  chRegSetThreadName("task1ms");
  time = chVTGetSystemTime();  
  while (TRUE) {
    time += MS2ST(10);

    //Analog measurement

    
    controlCalc();

    rsSPICalc();
    chThdSleepUntil(time);
  }
  return 0; /* Never executed.*/
}
/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Shell manager initialization.
   */
  consoleInit();

  /*
   * Pulse control initialization.
   */
  pulseInit();

  /*
   * Resolver control initialization.
   */
  rsSPIInit();

  /*
   * Resolver control initialization.
   */
  rsICUInit();

  /*
   * Control initialization.
   */
  controlInit();

  /*
   * Creates the 1ms Task.
   */
  chThdCreateStatic(task1ms_wa, sizeof(task1ms_wa), NORMALPRIO, task1ms, NULL);
  
  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(thread1_wa, sizeof(thread1_wa), NORMALPRIO, thread1, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (TRUE) {
    consoleStart();
    chThdSleepMilliseconds(1000);
  }
}