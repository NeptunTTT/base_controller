/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#include "pulse.h"

#include "chprintf.h"

#define MEDIUM_RATIO  2
#define LOW_RATIO     3

/*
 *PE9   - U_H
 *PA1   - U_L

 *PE11  - V_H
 *PA2   - V_L

 *PE13  - W_H
 *PA3   - W_L
 */


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

uint32_t u_h;
uint32_t v_h;
uint32_t w_h;

uint32_t u_l;
uint32_t v_l;
uint32_t w_l;

void pulseInit(void) {

  pwmStart(&PWMD4, &high_side);
  pwmStart(&PWMD8, &low_side);
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
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 20 && degree < 40){
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 40 && degree < 60){
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmDisableChannel(&PWMD4, v_h);
      pwmDisableChannel(&PWMD4, w_h);

      pwmDisableChannel(&PWMD8, u_l);
      pwmEnableChannel(&PWMD8, v_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, w_l);
      break;

    case PULSE_AC:
      if (degree >= 60 && degree < 80){
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 80 && degree < 100){
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 100 && degree < 120){
        pwmEnableChannel(&PWMD4, u_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD4, v_h);
      pwmDisableChannel(&PWMD4, w_h);

      pwmDisableChannel(&PWMD8, u_l);
      pwmDisableChannel(&PWMD8, v_l);
      pwmEnableChannel(&PWMD8, w_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      break;

    case PULSE_BC:
      pwmDisableChannel(&PWMD4, u_h);

      if (degree >= 120 && degree < 140){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 140 && degree < 160){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 160 && degree < 180){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmDisableChannel(&PWMD4, w_h);
      
      pwmDisableChannel(&PWMD8, u_l);
      pwmDisableChannel(&PWMD8, v_l);
      pwmEnableChannel(&PWMD8, w_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      break;

    case PULSE_BA:
      pwmDisableChannel(&PWMD4, u_h);

      if (degree >= 180 && degree < 200){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 200 && degree < 220){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 220 && degree < 240){
        pwmEnableChannel(&PWMD4, v_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD4, w_h);

      pwmEnableChannel(&PWMD8, u_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, v_l);
      pwmDisableChannel(&PWMD8, w_l);
      break;

    case PULSE_CA:
      pwmDisableChannel(&PWMD4, u_h);
      pwmDisableChannel(&PWMD4, v_h);

      if (degree >= 240 && degree < 260){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }
      else if (degree >= 260 && degree < 280){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 280 && degree < 300){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }

      pwmEnableChannel(&PWMD8, u_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, v_l);
      pwmDisableChannel(&PWMD8, w_l);
      break;

    case PULSE_CB:
      pwmDisableChannel(&PWMD4, u_h);
      pwmDisableChannel(&PWMD4, v_h);
      
      if (degree >= 300 && degree < 320){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_h));
      }
      else if (degree >= 320 && degree < 340){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_m));
      }
      else if (degree >= 340 && degree < 360){
        pwmEnableChannel(&PWMD4, w_h, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, level_l));
      }

      pwmDisableChannel(&PWMD8, u_l);
      pwmEnableChannel(&PWMD8, v_l, PWM_PERCENTAGE_TO_WIDTH(&PWMD8, 10000));
      pwmDisableChannel(&PWMD8, w_l);
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

void pulseDirection(uint16_t direction){
  if(direction == 1){
    u_h = 0;
    v_h = 1;
    w_h = 2;

    u_l = 0;
    v_l = 1;
    w_l = 2;
  }

  else if(direction == 2){
    u_h = 1;
    v_h = 0;
    w_h = 2;

    u_l = 1;
    v_l = 0;
    w_l = 2;
  }
}

int16_t pulseGetValue(){
}