/*
 * pwr.h
 *
 *  Created on: 22 aug 2015
 *      Author: osannolik
 */

#ifndef PWR_H_
#define PWR_H_

#include "stm32f4xx_hal.h"

#define PWR_ON_PIN     GPIO_PIN_5    // Active low
#define PWR_ON_PORT    GPIOB
#define PWR_LDOON_PIN  GPIO_PIN_13   // Active high
#define PWR_LDOON_PORT GPIOC
#define PWR_HPWR_PIN   GPIO_PIN_9    // Active high
#define PWR_HPWR_PORT  GPIOB
#define PWR_PWREN_PIN  GPIO_PIN_15   // Active low
#define PWR_PWREN_PORT GPIOC

void pwr_init(void);
void pwr_startup(void);
void pwr_standby(void);
void pwr_setHighPowerCharge(uint8_t onOff);
uint8_t pwr_getPwrEnSts(void);
uint8_t pwr_getOnSts(void);
void pwr_turnOffHard(void);

#endif /* PWR_H_ */
