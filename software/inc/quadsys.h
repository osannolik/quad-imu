/*
 * quadsys.h
 *
 *  Created on: 26 jun 2016
 *      Author: osannolik
 */

#ifndef QUADSYS_H_
#define QUADSYS_H_

#include "stm32f4xx_hal.h"

typedef struct
{
  uint8_t is_init;
} quadsys_DataTypeDef;

#define QUADSYS_DATA_INIT {0}

void quadsys_handler_1ms();
int quadsys_init();
int quadsys_init_peripheral();
uint8_t quadsys_is_init();
void quadsys_handler_start();
void quadsys_time_start();
uint32_t quadsys_time_us();
float quadsys_time_s();

#endif /* QUADSYS_H_ */
