/*
 * quadsys.c
 *
 *  Created on: 26 jun 2016
 *      Author: osannolik
 */

#include "debug.h"
#include "quadsys.h"
#include "orientation.h"
#include "calmeas.h"

static quadsys_DataTypeDef quadsys_data = QUADSYS_DATA_INIT;

static TIM_HandleTypeDef time_timer;
static TIM_HandleTypeDef handler_timer;

void quadsys_handler_1ms()
{
  static float t = 0;
  float dt;

  DBG_PAD1_SET;

  dt = quadsys_time_s() - t;
  t = t + dt;

  orient_update(dt);

  DBG_PAD1_RESET;
}

int quadsys_init()
{
  if (quadsys_init_peripheral())
    return -1;

  if (orient_init())
    return -1;

  quadsys_data.is_init = 1;

  quadsys_time_start();
  quadsys_handler_start();
  orient_update_enabled(1);

  return 0;
}

int quadsys_init_peripheral()
{
  __TIM2_CLK_ENABLE();

  time_timer.Channel = HAL_TIM_ACTIVE_CHANNEL_1;
  time_timer.Instance = TIM2;
  time_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
  time_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  time_timer.Init.Prescaler = 83;
  time_timer.Init.Period = 0xFFFFFFFF;
  HAL_TIM_Base_Init(&time_timer);

  TIM_ClockConfigTypeDef sClockSourceConfig;
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
  HAL_TIM_ConfigClockSource(&time_timer, &sClockSourceConfig);

  __HAL_TIM_SET_COUNTER(&time_timer, 0);


  __TIM3_CLK_ENABLE();

  handler_timer.Channel = HAL_TIM_ACTIVE_CHANNEL_1;
  handler_timer.Instance = TIM3;
  handler_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
  handler_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  handler_timer.Init.Prescaler = 31;
  handler_timer.Init.Period = 2625;
  HAL_TIM_Base_Init(&handler_timer);

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
  HAL_TIM_ConfigClockSource(&handler_timer, &sClockSourceConfig);

  __HAL_TIM_SET_COUNTER(&handler_timer, 0);

  HAL_NVIC_SetPriority(TIM3_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);

  return 0;
}

void TIM3_IRQHandler()
{
  if (__HAL_TIM_GET_ITSTATUS(&handler_timer, TIM_IT_UPDATE) != RESET) {
      __HAL_TIM_CLEAR_FLAG(&handler_timer, TIM_FLAG_UPDATE);
      quadsys_handler_1ms();
  }
}

uint8_t quadsys_is_init()
{
  return quadsys_data.is_init;
}

void quadsys_handler_start()
{
  HAL_TIM_Base_Start_IT(&handler_timer);
}

void quadsys_time_start()
{
  HAL_TIM_Base_Start(&time_timer);
}

uint32_t quadsys_time_us()
{
  // Will overflow after 2^32 us = 71.58 min...
  return __HAL_TIM_GET_COUNTER(&time_timer);
}

float quadsys_time_s()
{
  // Will overflow after 2^32 us = 71.58 min...
  return ((float) __HAL_TIM_GET_COUNTER(&time_timer)) * 0.000001;
}
