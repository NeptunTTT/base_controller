#include "pulse.h"

#include "chprintf.h"

#define U_H           0
#define V_H           1
#define W_H           2

#define U_L           0
#define V_L           1
#define W_L           2

#define MEDIUM_RATIO  2
#define LOW_RATIO     10

/*
 *PE9   - U_H
 *PA1   - U_L

 *PE11  - V_H
 *PA2   - V_L

 *PE13  - W_H
 *PA3   - W_L
 */

#define PWM_WIDTH     2000

static PWMConfig high_side = {
  28e6,                                   /* 10kHz PWM clock frequency.   */
  28e6/20000,                             /* Initial PWM period 1S.       */
  NULL,
  {
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PD12 - U_H */
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PD13 - V_H */
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PD14 - W_H */
   {PWM_OUTPUT_DISABLED, NULL}
  },
  0,
  0
};

static PWMConfig low_side = {
  28e6,                                   /* 10kHz PWM clock frequency.   */
  28e6/20000,                             /* Initial PWM period 1S.       */
  NULL,
  {
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PC6  - U_L */
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PC7  - V_L */
   {PWM_OUTPUT_ACTIVE_HIGH, NULL},        /* PC8  - W_L */
   {PWM_OUTPUT_DISABLED, NULL}
  },
  0,
  0
};

uint32_t level_l; //low    - full / 10
uint32_t level_m; //medium - full / 2
uint32_t level_h; //height - full

uint32_t section;
uint32_t calc_deg;
uint32_t width;

void pulseInit(void) {

  pwmStart(&PWMD4, &high_side);
  pwmStart(&PWMD8, &low_side);

  width = PWM_WIDTH;
  calc_deg = 0;
}

void pulseCalc(void) {
  calc_deg+=10;
  calc_deg = calc_deg > 359 ? 0 : calc_deg;
  
  pulseWidth(width);
  pulseControl(calc_deg);
}

void pulseControl(uint32_t degree){

  degree = degree > 359 ? 359 : degree;
  degree = degree < 0 ? 0 : degree;

  if(degree >= 0 && degree < 60){
    section = PULSE_AB;
  }

  else if(degree >= 60 && degree < 120){
    section = PULSE_AC;
  }

  else if(degree >= 120 && degree < 180){
    section = PULSE_BC;
  }

  else if(degree >= 180 && degree < 240){
    section = PULSE_BA;
  }

  else if(degree >= 240 && degree < 300){
    section = PULSE_CA;
  }

  else if(degree >= 300 && degree < 360){
    section = PULSE_CB;
  }

  switch(section){
    case PULSE_AB:

      if (degree >= 0 && degree < 20){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 20 && degree < 40){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 40 && degree < 60){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmDisableChannel(&PWMD4, V_H);
      pwmDisableChannel(&PWMD4, W_H);

      pwmDisableChannel(&PWMD8, U_L);
      pwmEnableChannel(&PWMD8, V_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, W_L);
      break;

    case PULSE_AC:
      if (degree >= 60 && degree < 80){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 80 && degree < 100){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 100 && degree < 120){
        pwmEnableChannel(&PWMD4, U_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD4, V_H);
      pwmDisableChannel(&PWMD4, W_H);

      pwmDisableChannel(&PWMD8, U_L);
      pwmDisableChannel(&PWMD8, V_L);
      pwmEnableChannel(&PWMD8, W_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      break;

    case PULSE_BC:
      pwmDisableChannel(&PWMD4, U_H);

      if (degree >= 120 && degree < 140){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 140 && degree < 160){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 160 && degree < 180){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmDisableChannel(&PWMD4, W_H);
      
      pwmDisableChannel(&PWMD8, U_L);
      pwmDisableChannel(&PWMD8, V_L);
      pwmEnableChannel(&PWMD8, W_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      break;

    case PULSE_BA:
      pwmDisableChannel(&PWMD4, U_H);

      if (degree >= 180 && degree < 200){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 200 && degree < 220){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 220 && degree < 240){
        pwmEnableChannel(&PWMD4, V_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD4, W_H);

      pwmEnableChannel(&PWMD8, U_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, V_L);
      pwmDisableChannel(&PWMD8, W_L);
      break;

    case PULSE_CA:
      pwmDisableChannel(&PWMD4, U_H);
      pwmDisableChannel(&PWMD4, V_H);

      if (degree >= 240 && degree < 260){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 260 && degree < 280){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 280 && degree < 300){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmEnableChannel(&PWMD8, U_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, V_L);
      pwmDisableChannel(&PWMD8, W_L);
      break;

    case PULSE_CB:
      pwmDisableChannel(&PWMD4, U_H);
      pwmDisableChannel(&PWMD4, V_H);
      
      if (degree >= 300 && degree < 320){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 320 && degree < 340){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 340 && degree < 360){
        pwmEnableChannel(&PWMD4, W_H, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD8, U_L);
      pwmEnableChannel(&PWMD8, V_L, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, W_L);
      break;

    default:
      break;
    }
}

void pulseWidth(uint32_t in){
  in = in > 10000 ? 10000 : in;
  in = in < 0 ? 0 : in;

  chSysLock();
  level_h = (uint32_t)in;
  level_m = (uint32_t)(in / MEDIUM_RATIO);
  level_l = (uint32_t)(in / LOW_RATIO);
  chSysUnlock();
}

int16_t pulseGetValue(){
    return calc_deg;
}

void cmd_pulseValues(BaseSequentialStream *chp, int argc, char *argv[]) {
 
  (void)argc;
  (void)argv;

  uint32_t in;
      
  if ((argc == 2) && (strcmp(argv[0], "width") == 0)){
    in = atol(argv[1]);

    if (in < 0 || in > 10000)
    {
      goto ERROR;
    }
    else
    {
      width = (uint32_t)in;
      chprintf(chp,"Set pulse width: %d\r\n", width);
      return;
    }
  }

  if ((argc == 2) && (strcmp(argv[0], "deg") == 0)){
    in = atol(argv[1]);

    if (in < 0 || in > 359)
    {
      goto ERROR;
    }
    else
    {
      pulseControl(in);
      chprintf(chp,"Set motor degree: %d\r\n", in);
      return;
    }
  }

  else{
  goto ERROR;
  }

ERROR:
  chprintf(chp, "Usage: pulse width (0 - 10000)\r\n");
  chprintf(chp, "       pulse deg   (0 - 359)\r\n");
  return;
}

void cmd_get_data(BaseSequentialStream *chp, int argc, char *argv[]){
  
  (void)argc;
  (void)argv;
  chprintf(chp, "\x1B\x63");
  chprintf(chp, "\x1B[2J");
  
  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
    chprintf(chp, "\x1B[%d;%dH", 0, 0);
    chprintf(chp,"Values\r\n");
    chThdSleepMilliseconds(500);
  }
}