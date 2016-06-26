/*
 * icm20608.c
 *
 *  Created on: 24 jun 2016
 *      Author: osannolik
 */

#include "icm20608.h"

static icm20608_DataTypeDef icm20608_data = ICM20608_DATA_INIT;

void EXTI0_IRQHandler()
{
  __HAL_GPIO_EXTI_CLEAR_IT(ICM20608_IRQ_PIN);

  if (icm20608_data.settings.InterruptCallback != NULL)
    icm20608_data.settings.InterruptCallback();
}

int icm20608_init(icm20608_SettingsTypeDef *settings)
{
  icm20608_setCS();

  icm20608_data.settings = *settings;

  icm20608_data.gyro_bias_x = 0;
  icm20608_data.gyro_bias_y = 0;
  icm20608_data.gyro_bias_z = 0;

  uint8_t regData;

  // Reset device
  regData = ICM20608_PWR_MGMT_1_DEVICE_RESET;
  icm20608_write_reg(ICM20608_RM_PWR_MGMT_1, 1, &regData);

  // Wait until reset
  HAL_Delay(2);
  //regData = 0;
  //do {
  //  icm20608_read_reg(ICM20608_RM_PWR_MGMT_1, 1, &regData);
  //} while (regData & ICM20608_PWR_MGMT_1_DEVICE_RESET);

  // Auto selects the best available clock source, disable sleep
  regData = ICM20608_PWR_MGMT_1_CLKSEL_SET(1);
  icm20608_write_reg(ICM20608_RM_PWR_MGMT_1, 1, &regData);

  // Disable i2c, reset all signal paths and registers
  regData = ICM20608_USER_CTRL_SIG_COND_RST | ICM20608_USER_CTRL_I2C_IF_DIS;
  icm20608_write_reg(ICM20608_RM_USER_CTRL, 1, &regData);

  // Reset digital signal paths
  regData = ICM20608_SIGNAL_PATH_RESET_ACCEL_RST | ICM20608_SIGNAL_PATH_RESET_TEMP_RST;
  icm20608_write_reg(ICM20608_RM_SIGNAL_PATH_RESET, 1, &regData);

  // Disable interrupts
  regData = 0;
  icm20608_write_reg(ICM20608_RM_INT_ENABLE, 1, &regData);

  // Disable low power mode
  regData = 0;
  icm20608_write_reg(ICM20608_RM_LP_MODE_CFG, 1, &regData);

  // Disable FIFO, use output directly
  regData = 0;
  icm20608_write_reg(ICM20608_RM_FIFO_EN, 1, &regData);

  // Don't set accelerometer and gyro to standby
  regData = 0;
  icm20608_write_reg(ICM20608_RM_PWR_MGMT_2, 1, &regData);

  // Disable intelligence control
  regData = 0;
  icm20608_write_reg(ICM20608_RM_ACCEL_INTEL_CTRL, 1, &regData);

  // Set initial value of gyro offset to 0
  regData = 0;
  icm20608_write_reg(ICM20608_RM_XG_OFFS_USRH, 1, &regData);
  icm20608_write_reg(ICM20608_RM_XG_OFFS_USRL, 1, &regData);
  icm20608_write_reg(ICM20608_RM_YG_OFFS_USRH, 1, &regData);
  icm20608_write_reg(ICM20608_RM_YG_OFFS_USRL, 1, &regData);
  icm20608_write_reg(ICM20608_RM_ZG_OFFS_USRH, 1, &regData);
  icm20608_write_reg(ICM20608_RM_ZG_OFFS_USRL, 1, &regData);


  // Set SAMPLE_RATE = 1 kHz
  regData = 0;
  icm20608_write_reg(ICM20608_RM_SMPLRT_DIV, 1, &regData);

  // Bypass DLPF
  //regData = ICM20608_GYRO_CONFIG_FCHOICE_B_SET(1);
  //icm20608_write_reg(ICM20608_RM_GYRO_CONFIG, 1, &regData);

  // Disable FSYNC
  regData = ICM20608_CONFIG_EXT_SYNC_SET(0);
  icm20608_write_reg(ICM20608_RM_CONFIG, 1, &regData);

  // Setup gyro full scale
  icm20608_set_gyro_sca_fac(1);

  // Set gyro DLPF
  icm20608_set_gyro_dlpf(0, 1);

  // Disable FSYNC and set DLPF bandwidth
  //regData = ICM20608_CONFIG_EXT_SYNC_SET(0) | ICM20608_CONFIG_DLPF_CFG_SET(0);
  //icm20608_write_reg(ICM20608_RM_CONFIG, 1, &regData);

  // Setup accelerometer full scale
  icm20608_set_accel_sca_fac(1);

  // Setup accelerometer DLPF
  icm20608_set_accel_dlpf(0, 1);
  //regData = ICM20608_ACCEL_CONFIG_2_FCHOICE_B | ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG_SET(0);
  //icm20608_write_reg(ICM20608_RM_ACCEL_CONFIG_2, 1, &regData);

  icm20608_read_reg(ICM20608_RM_WHO_AM_I, 1, &icm20608_data.whoAmI);

  icm20608_data.isInit = 1;

  return 0;
}

void icm20608_set_accel_dlpf(uint8_t cfg, uint8_t bypass)
{
  uint8_t accel_config2;

  icm20608_read_reg(ICM20608_RM_ACCEL_CONFIG_2, 1, &accel_config2);

  accel_config2 &= ~ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG;
  accel_config2 &= ~ICM20608_ACCEL_CONFIG_2_FCHOICE_B;

  accel_config2 |= ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG_SET(cfg);
  accel_config2 |= ICM20608_ACCEL_CONFIG_2_FCHOICE_B_SET(bypass);

  icm20608_write_reg(ICM20608_RM_ACCEL_CONFIG_2, 1, &accel_config2);
}

void icm20608_set_gyro_dlpf(uint8_t cfg, uint8_t bypass)
{
  uint8_t gyro_config, config;

  icm20608_read_reg(ICM20608_RM_GYRO_CONFIG, 1, &gyro_config);
  icm20608_read_reg(ICM20608_RM_CONFIG, 1, &config);

  gyro_config &= ~ICM20608_GYRO_CONFIG_FCHOICE_B;
  gyro_config |= ICM20608_GYRO_CONFIG_FCHOICE_B_SET(bypass);

  config &= ~ICM20608_CONFIG_DLPF_CFG;
  config |= ICM20608_CONFIG_DLPF_CFG_SET(cfg);

  icm20608_write_reg(ICM20608_RM_GYRO_CONFIG, 1, &gyro_config);
  icm20608_write_reg(ICM20608_RM_CONFIG, 1, &config);
}

void icm20608_set_accel_sca_fac(uint8_t fs_sel)
{
  uint8_t accel_config = ICM20608_ACCEL_CONFIG_FS_SEL_SET(fs_sel);

  icm20608_write_reg(ICM20608_RM_ACCEL_CONFIG, 1, &accel_config);

  icm20608_data.accel_sca_fac = 1.0/((float) ICM20608_ACCEL_LSB_PER_G(fs_sel));
}

void icm20608_set_gyro_sca_fac(uint8_t fs_sel)
{
  uint8_t gyro_config;

  icm20608_read_reg(ICM20608_RM_GYRO_CONFIG, 1, &gyro_config);

  gyro_config &= ~ICM20608_GYRO_CONFIG_FS_SEL;
  gyro_config |= ICM20608_GYRO_CONFIG_FS_SEL_SET(fs_sel);

  icm20608_write_reg(ICM20608_RM_GYRO_CONFIG, 1, &gyro_config);

  icm20608_data.gyro_sca_fac = (float) ICM20608_GYRO_DEGPERSEC_PER_LSB(fs_sel);
}

void icm20608_get_accel(float_vec_t *acc)
{
  int16_vec_t acc_raw;

  icm20608_get_accel_out(&acc_raw);

  acc->x = icm20608_data.accel_sca_fac * ((float) acc_raw.x);
  acc->y = icm20608_data.accel_sca_fac * ((float) acc_raw.y);
  acc->z = icm20608_data.accel_sca_fac * ((float) acc_raw.z);
}

void icm20608_get_accel_out(int16_vec_t *acc)
{
  uint8_t accel_h=0, accel_l=0;

  icm20608_read_reg(ICM20608_RM_ACCEL_XOUT_H, 1, (uint8_t *) &accel_h);
  icm20608_read_reg(ICM20608_RM_ACCEL_XOUT_L, 1, (uint8_t *) &accel_l);
  icm20608_data.accel_out_x = (((int16_t) accel_h) << 8) | accel_l;
  acc->x = icm20608_data.accel_out_x;

  icm20608_read_reg(ICM20608_RM_ACCEL_YOUT_H, 1, (uint8_t *) &accel_h);
  icm20608_read_reg(ICM20608_RM_ACCEL_YOUT_L, 1, (uint8_t *) &accel_l);
  icm20608_data.accel_out_y = (((int16_t) accel_h) << 8) | accel_l;
  acc->y = icm20608_data.accel_out_y;

  icm20608_read_reg(ICM20608_RM_ACCEL_ZOUT_H, 1, (uint8_t *) &accel_h);
  icm20608_read_reg(ICM20608_RM_ACCEL_ZOUT_L, 1, (uint8_t *) &accel_l);
  icm20608_data.accel_out_z = (((int16_t) accel_h) << 8) | accel_l;
  acc->z = icm20608_data.accel_out_z;
}

void icm20608_get_gyro(float_vec_t *gyro)
{
  int16_vec_t gyro_raw;

  icm20608_get_gyro_out(&gyro_raw);

  gyro->x = icm20608_data.gyro_sca_fac * ((float) (gyro_raw.x - icm20608_data.gyro_bias_x));
  gyro->y = icm20608_data.gyro_sca_fac * ((float) (gyro_raw.y - icm20608_data.gyro_bias_y));
  gyro->z = icm20608_data.gyro_sca_fac * ((float) (gyro_raw.z - icm20608_data.gyro_bias_z));
}

void icm20608_get_gyro_out(int16_vec_t *gyro)
{
  uint8_t gyro_h=0, gyro_l=0;

  icm20608_read_reg(ICM20608_RM_GYRO_XOUT_H, 1, (uint8_t *) &gyro_h);
  icm20608_read_reg(ICM20608_RM_GYRO_XOUT_L, 1, (uint8_t *) &gyro_l);
  icm20608_data.gyro_out_x = (((int16_t) gyro_h) << 8) | gyro_l;
  gyro->x = icm20608_data.gyro_out_x;

  icm20608_read_reg(ICM20608_RM_GYRO_YOUT_H, 1, (uint8_t *) &gyro_h);
  icm20608_read_reg(ICM20608_RM_GYRO_YOUT_L, 1, (uint8_t *) &gyro_l);
  icm20608_data.gyro_out_y = (((int16_t) gyro_h) << 8) | gyro_l;
  gyro->y = icm20608_data.gyro_out_y;

  icm20608_read_reg(ICM20608_RM_GYRO_ZOUT_H, 1, (uint8_t *) &gyro_h);
  icm20608_read_reg(ICM20608_RM_GYRO_ZOUT_L, 1, (uint8_t *) &gyro_l);
  icm20608_data.gyro_out_z = (((int16_t) gyro_h) << 8) | gyro_l;
  gyro->z = icm20608_data.gyro_out_z;
}

float icm20608_get_temperature_out()
{
  uint16_t temp_h=0, temp_l=0;

  icm20608_read_reg(ICM20608_RM_TEMP_OUT_H, 1, (uint8_t *) &temp_h);
  icm20608_read_reg(ICM20608_RM_TEMP_OUT_L, 1, (uint8_t *) &temp_l);

  int16_t temp_raw = (int16_t) ((temp_h<<8) | temp_l);

  icm20608_data.temp_degC = ((float) (temp_raw-25))/326.8 + 25.0;

  return icm20608_data.temp_degC;
}

void icm20608_get_gyro_bias(int16_vec_t *g_b)
{
  g_b->x = icm20608_data.gyro_bias_x;
  g_b->y = icm20608_data.gyro_bias_y;
  g_b->z = icm20608_data.gyro_bias_z;
}


void icm20608_cal_gyro_bias_2(int32_t samples_per_axis, uint32_t sample_interval)
{
  int32_t n = samples_per_axis;
  int32_t sum_x = 0, sum_y = 0, sum_z = 0;
  int16_vec_t g;

  while (n-- > 0) {
    icm20608_get_gyro_out(&g);
    sum_x += g.x;
    sum_y += g.y;
    sum_z += g.z;
    HAL_Delay(sample_interval);
  }

  icm20608_data.gyro_bias_x = sum_x/samples_per_axis;
  icm20608_data.gyro_bias_y = sum_y/samples_per_axis;
  icm20608_data.gyro_bias_z = sum_z/samples_per_axis;
}

void icm20608_cal_gyro_bias(uint32_t samples_per_axis, uint32_t sample_interval)
{
  uint32_t n = samples_per_axis;
  float sum_x = 0, sum_y = 0, sum_z = 0;
  float_vec_t g;

  icm20608_data.gyro_bias_x = 0.0;
  icm20608_data.gyro_bias_y = 0.0;
  icm20608_data.gyro_bias_z = 0.0;

  while (n--) {
    icm20608_get_gyro(&g);
    sum_x += g.x;
    sum_y += g.y;
    sum_z += g.z;
    HAL_Delay(sample_interval);
  }

  icm20608_data.gyro_bias_x = sum_x/((float) samples_per_axis);
  icm20608_data.gyro_bias_y = sum_y/((float) samples_per_axis);
  icm20608_data.gyro_bias_z = sum_z/((float) samples_per_axis);
}


void icm20608_read_reg(uint8_t addr, uint8_t len, uint8_t *buf)
{
  icm20608_resetCS();

  (void) icm20608_spiWrRd_blocking(ICM20608_RD_REG | addr);

  while (len--)
    *buf++ = icm20608_spiWrRd_blocking(ICM20608_DUMMYDATA);

  icm20608_setCS();
}

void icm20608_write_reg(uint8_t addr, uint8_t len, uint8_t *buf)
{
  icm20608_resetCS();

  (void) icm20608_spiWrRd_blocking(ICM20608_WR_REG | addr);

  while (len--)
    (void) icm20608_spiWrRd_blocking(*buf++);

  icm20608_setCS();
}

uint8_t icm20608_spiWrRd_blocking(uint8_t data)
{
  uint32_t timeOutCnt = 0;

  while(!(ICM20608_SPI_INSTANCE->SR & SPI_FLAG_TXE) && (timeOutCnt++ < ICM20608_SPIWRRD_TIOUT));

  ICM20608_SPI_INSTANCE->DR = data;

  timeOutCnt = 0;

  while(!(ICM20608_SPI_INSTANCE->SR & SPI_FLAG_RXNE) && (timeOutCnt++ < ICM20608_SPIWRRD_TIOUT));

  return (uint8_t) (ICM20608_SPI_INSTANCE->DR);
}

