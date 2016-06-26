/*
 * pwr.c
 *
 *  Created on: 22 aug 2015
 *      Author: osannolik
 */

#include "pwr.h"

void pwr_init(void)
{
  GPIO_InitTypeDef GPIOinitstruct;

  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_NOPULL;

  GPIOinitstruct.Mode = GPIO_MODE_OUTPUT_PP;

  GPIOinitstruct.Pin = PWR_HPWR_PIN;
  HAL_GPIO_Init(PWR_HPWR_PORT, &GPIOinitstruct);
  pwr_setHighPowerCharge(1);

  GPIOinitstruct.Pin = PWR_LDOON_PIN;
  HAL_GPIO_Init(PWR_LDOON_PORT, &GPIOinitstruct);
  HAL_GPIO_WritePin(PWR_LDOON_PORT, PWR_LDOON_PIN, GPIO_PIN_SET);

  GPIOinitstruct.Mode = GPIO_MODE_INPUT;

  GPIOinitstruct.Pin = PWR_ON_PIN;
  HAL_GPIO_Init(PWR_ON_PORT, &GPIOinitstruct);

  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Pin = PWR_PWREN_PIN;
  HAL_GPIO_Init(PWR_PWREN_PORT, &GPIOinitstruct);
}

void pwr_startup(void)
{
  if (pwr_getOnSts())
    pwr_standby();
}

void pwr_standby(void)
{
  while (pwr_getOnSts()) {
    pwr_setHighPowerCharge(1);
    //pwr_setHighPowerCharge(pwr_getPwrEnSts());
  }
}

void pwr_setHighPowerCharge(uint8_t onOff)
{
  if (onOff)
    HAL_GPIO_WritePin(PWR_HPWR_PORT, PWR_HPWR_PIN, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(PWR_HPWR_PORT, PWR_HPWR_PIN, GPIO_PIN_RESET);
}

uint8_t pwr_getPwrEnSts(void)
{
  return (HAL_GPIO_ReadPin(PWR_PWREN_PORT, PWR_PWREN_PIN) == GPIO_PIN_SET);
}

uint8_t pwr_getOnSts(void)
{
  GPIO_InitTypeDef GPIOinitstruct;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_INPUT;
  GPIOinitstruct.Pin = PWR_ON_PIN;
  HAL_GPIO_Init(PWR_ON_PORT, &GPIOinitstruct);

  return (HAL_GPIO_ReadPin(PWR_ON_PORT, PWR_ON_PIN) == GPIO_PIN_SET);
}

void pwr_turnOffHard(void)
{
  /* TODO: Save system state or whatever... */

  /* It takes about 5 s from setting ON low until power is lost */
  GPIO_InitTypeDef GPIOinitstruct;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_NOPULL;
  GPIOinitstruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIOinitstruct.Pin = PWR_ON_PIN;
  HAL_GPIO_Init(PWR_ON_PORT, &GPIOinitstruct);

  HAL_GPIO_WritePin(PWR_ON_PORT, PWR_ON_PIN, GPIO_PIN_RESET);

  /* Wait for death */
  while(1);

}
