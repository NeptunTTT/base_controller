/*
    Motor Controller - Copyright (C) 2016
    Neptun TTT Kft.              
*/

#include <stdio.h>
#include <math.h>

#include "resolver.h"
#include "pulse.h"

#include "chprintf.h"


#define SCK           13  //GPIOB_13
#define MISO          14  //GPIOB_14
#define MOSI          15  //GPIOB_15
#define CS            12  //GPIOB_12
#define SAMPLE        10  //GPIOE_10

#define MAX_RESOLVER  4095
#define MIN_RESOLVER  0

#define MAP_MAX       359
#define MAP_MIN       0

#define AVG_SIZE      100
#define AVG_SIZE_10   10

uint16_t pos;
uint16_t rdvel;
uint16_t dos;
uint16_t lot;
uint16_t par;

uint8_t rxbuf[2];

uint8_t bits[16];
int rd = 0;
int db = 0;
uint16_t assis;

uint16_t calc_pos;
uint16_t control_pos;
uint16_t ori_different;
uint16_t pos_different;
uint16_t adc_cycle;
uint16_t cycle;

int32_t motor_control;

/* AVG values */
double avg;
uint16_t avg_index;
uint16_t avg_diff[AVG_SIZE];

/* AVG values */
double avg;
uint16_t avg_pos_index, i;
uint16_t avg_pos_diff[AVG_SIZE_10];

/*
 * Maximum speed SPI configuration (21MHz, CPHA=0, CPOL=0, MSb first).
 */
static const SPIConfig hs_spicfg = {
  NULL,
  GPIOB,
  12,
  SPI_CR1_BR_1
};

/* ----- Resolver read ---- */
int32_t resolverRead(){

    palClearPad(GPIOE, SAMPLE);
    //chThdSleepMilliseconds(1);
    spiAcquireBus(&SPID2);              /* Acquire ownership of the bus.    */
    spiStart(&SPID2, &hs_spicfg);       /* Setup transfer parameters.       */
    spiSelect(&SPID2);                  /* Slave Select assertion.          */

    spiReceive (&SPID2, 2, rxbuf);
    
    spiUnselect(&SPID2);                /* Slave Select de-assertion.       */
    spiReleaseBus(&SPID2);              /* Ownership release.               */

    palSetPad(GPIOE, SAMPLE);

    chSysLock();

  /* ---- Data bit separate ---- */
    pos = rxbuf[0] << 8;
    pos += rxbuf[1];

    assis = pos;
    db = 16;
    while (assis!=0)
    {
        db--;
        rd = assis%2;
        assis /= 2;
        bits[db] = rd;

        if(db == 0){
          break;
        }
    }
    db = 16;
    pos = pos >> 4;

    par = bits[15];
    lot = bits[14];
    dos = bits[13];
    rdvel = bits[12];
  /* ----------------------------*/
    chSysUnlock();

    return pos;
}
/* ----------------------------*/

/* --- Degree calculation -- */
uint32_t resolverCalcDeg(uint16_t position, uint16_t phase_pair){

    adc_cycle = MAX_RESOLVER / phase_pair;

    calc_pos = position % adc_cycle;
    cycle = position /adc_cycle;

    calc_pos = map(calc_pos, 0, adc_cycle, MAP_MAX, MAP_MIN);

    return calc_pos;
}

/* ----- Different calc ---- */
    /*control_pos = pulseGetValue();
    
    if (calc_pos > control_pos)
    {
      pos_different = calc_pos - control_pos;
    }

    ori_different = pos_different;

    pos_different = pos_different < 0 ? 0 : pos_different; 
    pos_different = pos_different > 359 ? 359 : pos_different;*/
/* ---------------------------*/

/* --- Different buffer --- */
/*    avg_index++;
    if(avg_index > (AVG_SIZE - 1)){
      avg_index = 0;
    }
    avg_diff[avg_index] = pos_different;
    avg = 0;
    for (i = 0; i < AVG_SIZE; i++){
      avg += avg_diff[i];
    }
    pos_different = avg / AVG_SIZE;

    pos_different = pos_different < 0 ? 0 : pos_different; 
    pos_different = pos_different > 359 ? 359 : pos_different;*/
/* -------------------------*/

uint32_t resolverDegOffset(uint16_t position, int16_t offset){
    motor_control = position + (359 - offset);
    motor_control = motor_control % 360;

    return motor_control;
}

void resolverInit(void) {
  palSetPad(GPIOE, 10);
  palSetPad(GPIOB, 12);
}

long map(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t rsValues(uint32_t num){
  return num == 1 ? rdvel : \
         num == 2 ? dos :   \
         num == 3 ? lot :   \
         num == 4 ? par : 0;
}

void cmd_resolverValues(BaseSequentialStream *chp, int argc, char *argv[]) {

  int i;

  (void)argc;
  (void)argv;
  chprintf(chp, "\x1B\x63");
  chprintf(chp, "\x1B[2J");
  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
      chprintf(chp, "\x1B[%d;%dH", 0, 0);

      chprintf(chp, "rxbuf[0]: %15d\r\n", rxbuf[0]);
      chprintf(chp, "rxbuf[1]: %15d\r\n", rxbuf[1]);
      chprintf(chp, "\r\n\r\n");
      chprintf(chp, "pos: %15d\r\n", pos);
      chprintf(chp, "calc_pos: %15d\r\n", calc_pos);
      chprintf(chp, "cycle: %15d\r\n", cycle);
      chprintf(chp, "\r\n");
      chprintf(chp, "rdvel: %15d\r\n", rdvel);
      chprintf(chp, "dos: %15d\r\n", dos);
      chprintf(chp, "lot: %15d\r\n", lot);
      chprintf(chp, "par: %15d\r\n", par);
      chprintf(chp, "\r\n");
      for (i = 0; i < 16; ++i)
      {
        chprintf(chp, "%d", bits[i]);
      }
      chprintf(chp, "\r\n");
      chprintf(chp, "control_pos: %15d\r\n", control_pos);
      chprintf(chp, "resolver_deg: %15d\r\n", calc_pos);
      chprintf(chp, "difference: %15d\r\n", pos_different);
      chprintf(chp, "ori_difference: %15d\r\n", ori_different);
      chprintf(chp, "motor_control: %15d\r\n", motor_control);

      chThdSleepMilliseconds(10);
  }
}