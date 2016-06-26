/*
 * orientation.c
 *
 *  Created on: 24 jun 2016
 *      Author: osannolik
 */

#include "orientation.h"
#include "icm20608.h"
#include "calmeas.h"

static orient_DataTypeDef orient_data = ORIENT_DATA_INIT;

CALMEAS_SYMBOL(float, a_x, 0.0, "");
CALMEAS_SYMBOL(float, a_y, 0.0, "");
CALMEAS_SYMBOL(float, a_z, 0.0, "");
CALMEAS_SYMBOL(float, g_x, 0.0, "");
CALMEAS_SYMBOL(float, g_y, 0.0, "");
CALMEAS_SYMBOL(float, g_z, 0.0, "");

CALMEAS_SYMBOL(float, orient_dt, 0.0, "");

CALMEAS_SYMBOL(float, alfa, 0.0, "");
CALMEAS_SYMBOL(uint8_t, ALFA_EN, 0, "");

CALMEAS_SYMBOL(uint8_t, GYRO_CAL_EN, 0, "");
CALMEAS_SYMBOL(int16_t, g_b_x, 0, "");
CALMEAS_SYMBOL(int16_t, g_b_y, 0, "");
CALMEAS_SYMBOL(int16_t, g_b_z, 0, "");

CALMEAS_SYMBOL(uint8_t, GYRO_FS_SEL, 1, "");
CALMEAS_SYMBOL(uint8_t, ACCEL_FS_SEL, 1, "");

CALMEAS_SYMBOL(uint8_t, A_DLPF_CFG, 0, "");
CALMEAS_SYMBOL(uint8_t, A_FCHOICE_B, 1, "");
CALMEAS_SYMBOL(uint8_t, G_DLPF_CFG, 0, "");
CALMEAS_SYMBOL(uint8_t, G_FCHOICE_B, 1, "");

void orient_param_update(uint32_t period)
{
  static uint8_t _GYRO_FS_SEL_Z = 1;
  static uint8_t _ACCEL_FS_SEL_Z = 1;
  static uint8_t _GYRO_CAL_EN_Z = 0;

  static uint8_t _A_DLPF_CFG_Z = 0;
  static uint8_t _A_FCHOICE_B_Z = 1;
  static uint8_t _G_DLPF_CFG_Z = 0;
  static uint8_t _G_FCHOICE_B_Z = 1;

  static uint32_t cnt = 0;

  if (++cnt >= period && period>0) {
    cnt = 0;
    if (GYRO_FS_SEL != _GYRO_FS_SEL_Z)
      icm20608_set_gyro_sca_fac(GYRO_FS_SEL);

    if (ACCEL_FS_SEL != _ACCEL_FS_SEL_Z)
      icm20608_set_accel_sca_fac(ACCEL_FS_SEL);

    if (A_DLPF_CFG != _A_DLPF_CFG_Z || A_FCHOICE_B != _A_FCHOICE_B_Z)
      icm20608_set_accel_dlpf(A_DLPF_CFG, A_FCHOICE_B);

    if (G_DLPF_CFG != _G_DLPF_CFG_Z || G_FCHOICE_B != _G_FCHOICE_B_Z)
      icm20608_set_gyro_dlpf(G_DLPF_CFG, G_FCHOICE_B);

    if (GYRO_CAL_EN>0 && _GYRO_CAL_EN_Z==0) {
      orient_update_enabled(0);
      icm20608_cal_gyro_bias_2(100, 2);
      int16_vec_t g_b;
      icm20608_get_gyro_bias(&g_b);
      g_b_x = g_b.x;
      g_b_y = g_b.y;
      g_b_z = g_b.z;
      orient_update_enabled(1);
    }

    _GYRO_FS_SEL_Z = GYRO_FS_SEL;
    _ACCEL_FS_SEL_Z = ACCEL_FS_SEL;
    _GYRO_CAL_EN_Z = GYRO_CAL_EN;
    _A_DLPF_CFG_Z = A_DLPF_CFG;
    _A_FCHOICE_B_Z = A_FCHOICE_B;
    _G_DLPF_CFG_Z = G_DLPF_CFG;
    _G_FCHOICE_B_Z = G_FCHOICE_B;
  }
}

void orient_update_enabled(uint8_t en)
{
  orient_data.run_updater = en;
}

void orient_update(float dt)
{
  float_vec_t a, g;

  if (orient_data.run_updater) {
    icm20608_get_accel(&a);
    icm20608_get_gyro(&g);

    a_x = a.x;
    a_y = a.y;
    a_z = a.z;
    g_x = g.x;
    g_y = g.y;
    g_z = g.z;

    orient_dt = dt;

    if (ALFA_EN)
      alfa = alfa + g.y * dt;
    else
      alfa = 0.0;
  }
}

int orient_init()
{
  int err = 0;

  err |= orient_init_io();
  err |= orient_init_peripheral();

  if (err)
    return -1;

  icm20608_SettingsTypeDef icm20608_settings;

  icm20608_settings.InterruptCallback = NULL;

  orient_data.is_init = 1;

  return icm20608_init(&icm20608_settings);
}

int orient_init_peripheral()
{
  __HAL_RCC_SPI3_CLK_ENABLE();

  // SPI
  SPI_HandleTypeDef SPIhandle;
  //SPIhandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  SPIhandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  SPIhandle.Init.CLKPhase = SPI_PHASE_1EDGE;
  SPIhandle.Init.CLKPolarity = SPI_POLARITY_LOW;
  SPIhandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
  SPIhandle.Init.DataSize = SPI_DATASIZE_8BIT;
  SPIhandle.Init.Direction = SPI_DIRECTION_2LINES;
  SPIhandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
  SPIhandle.Init.Mode = SPI_MODE_MASTER;
  SPIhandle.Init.NSS = SPI_NSS_SOFT;
  SPIhandle.Init.TIMode = SPI_TIMODE_DISABLED;
  SPIhandle.Instance = ICM20608_SPI_INSTANCE;

  HAL_SPI_Init(&SPIhandle);
  __HAL_SPI_ENABLE(&SPIhandle);

  return 0;
}

int orient_init_io()
{
  GPIO_InitTypeDef GPIOinitstruct;

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  // MOSI
  GPIOinitstruct.Pin = ICM20608_MOSI_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  GPIOinitstruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(ICM20608_MOSI_PORT, &GPIOinitstruct);

  // MISO
  GPIOinitstruct.Pin = ICM20608_MISO_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  GPIOinitstruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(ICM20608_MISO_PORT, &GPIOinitstruct);

  // SCK
  GPIOinitstruct.Pin = ICM20608_SCK_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_NOPULL;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  GPIOinitstruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(ICM20608_SCK_PORT, &GPIOinitstruct);

  // CS
  GPIOinitstruct.Pin = ICM20608_CS_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_OUTPUT_PP;
  HAL_GPIO_Init(ICM20608_CS_PORT, &GPIOinitstruct);

  // IRQ
  GPIOinitstruct.Pin = ICM20608_IRQ_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_IT_RISING;
  HAL_GPIO_Init(ICM20608_IRQ_PORT, &GPIOinitstruct);
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0x0F, 0x0F);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  return 0;
}

uint8_t orient_is_init()
{
  return orient_data.is_init;
}
