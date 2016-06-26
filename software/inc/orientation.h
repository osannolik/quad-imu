/*
 * orientation.h
 *
 *  Created on: 24 jun 2016
 *      Author: osannolik
 */

#ifndef ORIENTATION_H_
#define ORIENTATION_H_

#include "stm32f4xx_hal.h"

typedef struct
{
  uint8_t is_init;
  uint8_t run_updater;
} orient_DataTypeDef;

#define ORIENT_DATA_INIT {0, 0}

void orient_param_update(uint32_t period);
int orient_init();
void orient_update_enabled(uint8_t en);
void orient_update(float dt);
int orient_init_peripheral();
int orient_init_io();
uint8_t orient_is_init();

#endif /* ORIENTATION_H_ */
