/*
 * icm20608.h
 *
 *  Created on: 24 jun 2016
 *      Author: osannolik
 */

#ifndef ICM20608_H_
#define ICM20608_H_

#include "stm32f4xx_hal.h"

#define ICM20608_SPI_INSTANCE  SPI3

#define ICM20608_MOSI_PIN      GPIO_PIN_12
#define ICM20608_MOSI_PORT     GPIOC
#define ICM20608_MISO_PIN      GPIO_PIN_11
#define ICM20608_MISO_PORT     GPIOC
#define ICM20608_SCK_PIN       GPIO_PIN_10
#define ICM20608_SCK_PORT      GPIOC
#define ICM20608_CS_PIN        GPIO_PIN_2
#define ICM20608_CS_PORT       GPIOD
#define ICM20608_IRQ_PIN       GPIO_PIN_0
#define ICM20608_IRQ_PORT      GPIOC

#define ICM20608_SPIWRRD_TIOUT (1000)

#define ICM20608_DUMMYDATA (0x00)

// Operations
#define ICM20608_RD_REG (0x80)
#define ICM20608_WR_REG (0x00)

// Registers
#define ICM20608_RM_SELF_TEST_X_GYRO  (0x00)
#define ICM20608_RM_SELF_TEST_Y_GYRO  (0x01)
#define ICM20608_RM_SELF_TEST_Z_GYRO  (0x02)
#define ICM20608_RM_SELF_TEST_X_ACCEL (0x0D)
#define ICM20608_RM_SELF_TEST_Y_ACCEL (0x0E)
#define ICM20608_RM_SELF_TEST_Z_ACCEL (0x0F)
#define ICM20608_RM_XG_OFFS_USRH      (0x13)
#define ICM20608_RM_XG_OFFS_USRL      (0x14)
#define ICM20608_RM_YG_OFFS_USRH      (0x15)
#define ICM20608_RM_YG_OFFS_USRL      (0x16)
#define ICM20608_RM_ZG_OFFS_USRH      (0x17)
#define ICM20608_RM_ZG_OFFS_USRL      (0x18)
#define ICM20608_RM_SMPLRT_DIV        (0x19)
#define ICM20608_RM_CONFIG            (0x1A)
#define ICM20608_RM_GYRO_CONFIG       (0x1B)
#define ICM20608_RM_ACCEL_CONFIG      (0x1C)
#define ICM20608_RM_ACCEL_CONFIG_2    (0x1D)
#define ICM20608_RM_LP_MODE_CFG       (0x1E)
#define ICM20608_RM_ACCEL_WOM_THR     (0x1F)
#define ICM20608_RM_FIFO_EN           (0x23)
#define ICM20608_RM_FSYNC_INT         (0x36)
#define ICM20608_RM_INT_PIN_CFG       (0x37)
#define ICM20608_RM_INT_ENABLE        (0x38)
#define ICM20608_RM_INT_STATUS        (0x3A)
#define ICM20608_RM_ACCEL_XOUT_H      (0x3B)
#define ICM20608_RM_ACCEL_XOUT_L      (0x3C)
#define ICM20608_RM_ACCEL_YOUT_H      (0x3D)
#define ICM20608_RM_ACCEL_YOUT_L      (0x3E)
#define ICM20608_RM_ACCEL_ZOUT_H      (0x3F)
#define ICM20608_RM_ACCEL_ZOUT_L      (0x40)
#define ICM20608_RM_TEMP_OUT_H        (0x41)
#define ICM20608_RM_TEMP_OUT_L        (0x42)
#define ICM20608_RM_GYRO_XOUT_H       (0x43)
#define ICM20608_RM_GYRO_XOUT_L       (0x44)
#define ICM20608_RM_GYRO_YOUT_H       (0x45)
#define ICM20608_RM_GYRO_YOUT_L       (0x46)
#define ICM20608_RM_GYRO_ZOUT_H       (0x47)
#define ICM20608_RM_GYRO_ZOUT_L       (0x48)
#define ICM20608_RM_SIGNAL_PATH_RESET (0x68)
#define ICM20608_RM_ACCEL_INTEL_CTRL  (0x69)
#define ICM20608_RM_USER_CTRL         (0x6A)
#define ICM20608_RM_PWR_MGMT_1        (0x6B)
#define ICM20608_RM_PWR_MGMT_2        (0x6C)
#define ICM20608_RM_FIFO_COUNTH       (0x72)
#define ICM20608_RM_FIFO_COUNTL       (0x73)
#define ICM20608_RM_FIFO_R_W          (0x74)
#define ICM20608_RM_WHO_AM_I          (0x75)
#define ICM20608_RM_XA_OFFSET_H       (0x77)
#define ICM20608_RM_XA_OFFSET_L       (0x78)
#define ICM20608_RM_YA_OFFSET_H       (0x7A)
#define ICM20608_RM_YA_OFFSET_L       (0x7B)
#define ICM20608_RM_ZA_OFFSET_H       (0x7D)
#define ICM20608_RM_ZA_OFFSET_L       (0x7E)

// Register bit definitions
#define _BIT(x) (0x01<<(x))

#define ICM20608_CONFIG_FIFO_MODE (_BIT(6))
#define ICM20608_CONFIG_EXT_SYNC  (_BIT(5) | _BIT(4) | _BIT(3))
#define ICM20608_CONFIG_DLPF_CFG  (_BIT(2) | _BIT(1) | _BIT(0))

#define ICM20608_CONFIG_EXT_SYNC_SET(X) (ICM20608_CONFIG_EXT_SYNC & (X<<3))
#define ICM20608_CONFIG_DLPF_CFG_SET(X) (ICM20608_CONFIG_DLPF_CFG & X)

#define ICM20608_GYRO_CONFIG_XG_ST     (_BIT(7))
#define ICM20608_GYRO_CONFIG_YG_ST     (_BIT(6))
#define ICM20608_GYRO_CONFIG_ZG_ST     (_BIT(5))
#define ICM20608_GYRO_CONFIG_FS_SEL    (_BIT(4) | _BIT(3))
#define ICM20608_GYRO_CONFIG_FCHOICE_B (_BIT(1) | _BIT(0))

#define ICM20608_GYRO_CONFIG_FCHOICE_B_SET(X) (ICM20608_GYRO_CONFIG_FCHOICE_B & X)
#define ICM20608_GYRO_CONFIG_FS_SEL_SET(X)    (ICM20608_GYRO_CONFIG_FS_SEL & ((X) << 3))
#define ICM20608_GYRO_CONFIG_FS_SEL_250DPS    ICM20608_GYRO_CONFIG_FS_SEL_SET(0)
#define ICM20608_GYRO_CONFIG_FS_SEL_500DPS    ICM20608_GYRO_CONFIG_FS_SEL_SET(1)
#define ICM20608_GYRO_CONFIG_FS_SEL_1000DPS   ICM20608_GYRO_CONFIG_FS_SEL_SET(2)
#define ICM20608_GYRO_CONFIG_FS_SEL_2000DPS   ICM20608_GYRO_CONFIG_FS_SEL_SET(3)

#define ICM20608_GYRO_LSB_PER_DEGPERSEC(FS_SEL) ((float)(1<<15))/((float)(250<<FS_SEL))

#define ICM20608_GYRO_DEGPERSEC_PER_LSB(FS_SEL) (0.007633587786 * ((float) (1<<FS_SEL)))

#define ICM20608_ACCEL_CONFIG_XA_ST  (_BIT(7))
#define ICM20608_ACCEL_CONFIG_YA_ST  (_BIT(6))
#define ICM20608_ACCEL_CONFIG_ZA_ST  (_BIT(5))
#define ICM20608_ACCEL_CONFIG_FS_SEL (_BIT(4) | _BIT(3))

#define ICM20608_ACCEL_CONFIG_FS_SEL_SET(X) (ICM20608_ACCEL_CONFIG_FS_SEL & ((X) << 3))
#define ICM20608_ACCEL_CONFIG_FS_SEL_2G     ICM20608_ACCEL_CONFIG_FS_SEL_SET(0)
#define ICM20608_ACCEL_CONFIG_FS_SEL_4G     ICM20608_ACCEL_CONFIG_FS_SEL_SET(1)
#define ICM20608_ACCEL_CONFIG_FS_SEL_8G     ICM20608_ACCEL_CONFIG_FS_SEL_SET(2)
#define ICM20608_ACCEL_CONFIG_FS_SEL_16G    ICM20608_ACCEL_CONFIG_FS_SEL_SET(3)

#define ICM20608_ACCEL_LSB_PER_G(FS_SEL) (1<<15)/(2<<FS_SEL)

#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG   (_BIT(5) | _BIT(4))
#define ICM20608_ACCEL_CONFIG_2_FCHOICE_B  (_BIT(3))
#define ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG (_BIT(2) | _BIT(1) | _BIT(0))

#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG_SET(X)   (ICM20608_ACCEL_CONFIG_2_DEC2_CFG & ((X) << 4))
#define ICM20608_ACCEL_CONFIG_2_FCHOICE_B_SET(X)  (ICM20608_ACCEL_CONFIG_2_FCHOICE_B & ((X) << 3))
#define ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG_SET(X) (ICM20608_ACCEL_CONFIG_2_A_DLPF_CFG & X)

#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG_AVG4  (0x00)
#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG_AVG8  (_BIT(4))
#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG_AVG16 (_BIT(5))
#define ICM20608_ACCEL_CONFIG_2_DEC2_CFG_AVG32 (_BIT(5) | _BIT(4))

#define ICM20608_LP_MODE_CFG_GYRO_CYCLE   (_BIT(7))
#define ICM20608_LP_MODE_CFG_G_AVGCFG     (_BIT(6) | _BIT(5) | _BIT(4))
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL (_BIT(3) | _BIT(2) | _BIT(1) | _BIT(0))

#define ICM20608_LP_MODE_CFG_G_AVGCFG_SET(X) (ICM20608_LP_MODE_CFG_G_AVGCFG & ((X) << 4))
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_SET(X) (ICM20608_LP_MODE_CFG_LPOSC_CLKSEL & X)

#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_0HZ24  (0)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_0HZ49  (1)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_0HZ98  (2)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_1HZ95  (3)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_3HZ91  (4)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_7HZ81  (5)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_15HZ63 (6)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_31HZ25 (7)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_62HZ50 (8)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_125HZ  (9)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_250HZ  (10)
#define ICM20608_LP_MODE_CFG_LPOSC_CLKSEL_500HZ  (11)

#define ICM20608_FIFO_EN_TEMP  (_BIT(7))
#define ICM20608_FIFO_EN_XG    (_BIT(6))
#define ICM20608_FIFO_EN_YG    (_BIT(5))
#define ICM20608_FIFO_EN_ZG    (_BIT(4))
#define ICM20608_FIFO_EN_ACCEL (_BIT(3))

#define ICM20608_FSYNC_INT_FSYNC_INT (_BIT(7))

#define ICM20608_INT_PIN_CFG_INT_LEVEL         (_BIT(7))
#define ICM20608_INT_PIN_CFG_INT_OPEN          (_BIT(6))
#define ICM20608_INT_PIN_CFG_LATCH_INT_EN      (_BIT(5))
#define ICM20608_INT_PIN_CFG_INT_RD_CLEAR      (_BIT(4))
#define ICM20608_INT_PIN_CFG_FSYNC_INT_LEVEL   (_BIT(3))
#define ICM20608_INT_PIN_CFG_FSYNC_INT_MODE_EN (_BIT(2))

#define ICM20608_INT_ENABLE_WOM_INT_EN      (_BIT(7) | _BIT(6) | _BIT(5))
#define ICM20608_INT_ENABLE_FIFO_OFLOW_EN   (_BIT(4))
#define ICM20608_INT_ENABLE_GDRIVE_INT_EN   (_BIT(2))
#define ICM20608_INT_ENABLE_DATA_RDY_INT_EN (_BIT(0))

#define ICM20608_INT_ENABLE_WOM_INT_EN_SET(X) (ICM20608_INT_ENABLE_WOM_INT_EN & ((X) << 5))

#define ICM20608_INT_STATUS_WOM_INT        (_BIT(7) | _BIT(6) | _BIT(5))
#define ICM20608_INT_STATUS_FIFO_OFLOW_INT (_BIT(4))
#define ICM20608_INT_STATUS_GDRIVE_INT     (_BIT(2))
#define ICM20608_INT_STATUS_DATA_RDY_INT   (_BIT(0))

#define ICM20608_SIGNAL_PATH_RESET_ACCEL_RST (_BIT(1))
#define ICM20608_SIGNAL_PATH_RESET_TEMP_RST  (_BIT(0))

#define ICM20608_ACCEL_INTEL_CTRL_EN   (_BIT(7))
#define ICM20608_ACCEL_INTEL_CTRL_MODE (_BIT(6))

#define ICM20608_USER_CTRL_FIFO_EN      (_BIT(6))
#define ICM20608_USER_CTRL_I2C_IF_DIS   (_BIT(4))
#define ICM20608_USER_CTRL_FIFO_RST     (_BIT(2))
#define ICM20608_USER_CTRL_SIG_COND_RST (_BIT(0))

#define ICM20608_PWR_MGMT_1_DEVICE_RESET (_BIT(7))
#define ICM20608_PWR_MGMT_1_SLEEP        (_BIT(6))
#define ICM20608_PWR_MGMT_1_ACCEL_CYCLE  (_BIT(5))
#define ICM20608_PWR_MGMT_1_GYRO_STANDBY (_BIT(4))
#define ICM20608_PWR_MGMT_1_TEMP_DIS     (_BIT(3))
#define ICM20608_PWR_MGMT_1_CLKSEL       (_BIT(2) | _BIT(1) | _BIT(0))

#define ICM20608_PWR_MGMT_1_CLKSEL_SET(X) (ICM20608_PWR_MGMT_1_CLKSEL & X)

#define ICM20608_PWR_MGMT_2_FIFO_LP_EN (_BIT(7))
#define ICM20608_PWR_MGMT_2_STBY_XA    (_BIT(5))
#define ICM20608_PWR_MGMT_2_STBY_YA    (_BIT(4))
#define ICM20608_PWR_MGMT_2_STBY_ZA    (_BIT(3))
#define ICM20608_PWR_MGMT_2_STBY_XG    (_BIT(2))
#define ICM20608_PWR_MGMT_2_STBY_YG    (_BIT(1))
#define ICM20608_PWR_MGMT_2_STBY_ZG    (_BIT(0))

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} int16_vec_t;

typedef struct
{
  float x;
  float y;
  float z;
} float_vec_t;

typedef struct
{
  void (*InterruptCallback)();
} icm20608_SettingsTypeDef;


typedef struct
{
  icm20608_SettingsTypeDef settings;
  uint8_t isInit;
  uint8_t whoAmI;
  float   accel_sca_fac;
  float   gyro_sca_fac;
  int16_t gyro_out_x;
  int16_t gyro_out_y;
  int16_t gyro_out_z;
  int16_t   gyro_bias_x;
  int16_t   gyro_bias_y;
  int16_t   gyro_bias_z;
  int16_t accel_out_x;
  int16_t accel_out_y;
  int16_t accel_out_z;
  float   temp_degC;
} icm20608_DataTypeDef;

#define ICM20608_DATA_INIT {{(void *) 0}, 0, 0, 0.0, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0}

int icm20608_init(icm20608_SettingsTypeDef *settings);
void icm20608_set_accel_dlpf(uint8_t cfg, uint8_t bypass);
void icm20608_set_gyro_dlpf(uint8_t cfg, uint8_t bypass);
void icm20608_set_accel_sca_fac(uint8_t fs_sel);
void icm20608_set_gyro_sca_fac(uint8_t fs_sel);
void icm20608_get_accel(float_vec_t *acc);
void icm20608_get_accel_out(int16_vec_t *acc);
void icm20608_get_gyro(float_vec_t *gyro);
void icm20608_get_gyro_out(int16_vec_t *gyro);
float icm20608_get_temperature_out();
void icm20608_get_gyro_bias(int16_vec_t *g_b);
void icm20608_cal_gyro_bias_2(int32_t samples_per_axis, uint32_t sample_interval);
void icm20608_cal_gyro_bias(uint32_t samples_per_axis, uint32_t sample_interval);
void icm20608_read_reg(uint8_t addr, uint8_t len, uint8_t *buf);
void icm20608_write_reg(uint8_t addr, uint8_t len, uint8_t *buf);
uint8_t icm20608_spiWrRd_blocking(uint8_t data);

__STATIC_INLINE void icm20608_setCS(void)
{
  ICM20608_CS_PORT->BSRR = ICM20608_CS_PIN;
}

__STATIC_INLINE void icm20608_resetCS(void)
{
  ICM20608_CS_PORT->BSRR = (ICM20608_CS_PIN<<16);
}

#endif /* ICM20608_H_ */
