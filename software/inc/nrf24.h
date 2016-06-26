/*
 * nRF24.h
 *
 *  Created on: 29 jun 2013
 *      Author: osannolik
 */

#ifndef NRF24_H_
#define NRF24_H_

#include "stm32f4xx_hal.h"

#define nRF24_SPI_INSTANCE  SPI2

#define nRF24_MOSI_PIN      GPIO_PIN_15
#define nRF24_MOSI_PORT     GPIOB
#define nRF24_MISO_PIN      GPIO_PIN_14
#define nRF24_MISO_PORT     GPIOB
#define nRF24_SCK_PIN       GPIO_PIN_13
#define nRF24_SCK_PORT      GPIOB
#define nRF24_CSN_PIN       GPIO_PIN_1
#define nRF24_CSN_PORT      GPIOC
#define nRF24_CE_PIN        GPIO_PIN_2
#define nRF24_CE_PORT       GPIOC
#define nRF24_IRQ_PIN       GPIO_PIN_4
#define nRF24_IRQ_PORT      GPIOC

/*
#define nRF24_SPI_INSTANCE  SPI1

#define nRF24_MOSI_PIN      GPIO_PIN_7
#define nRF24_MOSI_PORT     GPIOA
#define nRF24_MISO_PIN      GPIO_PIN_6
#define nRF24_MISO_PORT     GPIOA
#define nRF24_SCK_PIN       GPIO_PIN_5
#define nRF24_SCK_PORT      GPIOA
#define nRF24_CSN_PIN       GPIO_PIN_3
#define nRF24_CSN_PORT      GPIOA
#define nRF24_CE_PIN        GPIO_PIN_2
#define nRF24_CE_PORT       GPIOA
#define nRF24_IRQ_PIN       GPIO_PIN_4
#define nRF24_IRQ_PORT      GPIOC
*/
#define nRF24_SPIWRRD_TIOUT (1000)

#define nRF24_DUMMYDATA     (0x00)

//SPI command defines
#define nRF24_R_REGISTER      0x00
#define nRF24_W_REGISTER      0x20
#define nRF24_R_RX_PAYLOAD    0x61
#define nRF24_W_TX_PAYLOAD    0xA0
#define nRF24_FLUSH_TX        0xE1
#define nRF24_FLUSH_RX        0xE2
#define nRF24_REUSE_TX_PL     0xE3
#define nRF24_NOP             0xFF
#define nRF24_ACTIVATE_CMD    0x50
#define nRF24_ACTIVATE_DATA   0x73
#define nRF24_W_ACK_PAYLOAD   0xA8
 
//SPI command data mask defines
#define nRF24_R_REGISTER_DATA  0x1F
#define nRF24_W_REGISTER_DATA  0x1F

/*
  Register definitions
  Below are the defines for each register's address in the 24L01.
*/
#define nRF24_CONFIG          0x00
#define nRF24_EN_AA           0x01
#define nRF24_EN_RXADDR       0x02
#define nRF24_SETUP_AW        0x03
#define nRF24_SETUP_RETR      0x04
#define nRF24_RF_CH           0x05
#define nRF24_RF_SETUP        0x06
#define nRF24_STATUS          0x07
#define nRF24_OBSERVE_TX      0x08
#define nRF24_CD              0x09
#define nRF24_RX_ADDR_P0      0x0A
#define nRF24_RX_ADDR_P1      0x0B
#define nRF24_RX_ADDR_P2      0x0C
#define nRF24_RX_ADDR_P3      0x0D
#define nRF24_RX_ADDR_P4      0x0E
#define nRF24_RX_ADDR_P5      0x0F
#define nRF24_TX_ADDR         0x10
#define nRF24_RX_PW_P0        0x11
#define nRF24_RX_PW_P1        0x12
#define nRF24_RX_PW_P2        0x13
#define nRF24_RX_PW_P3        0x14
#define nRF24_RX_PW_P4        0x15
#define nRF24_RX_PW_P5        0x16
#define nRF24_FIFO_STATUS     0x17
#define nRF24_FEATURE         0x1D
#define nRF24_DYNPD           0x1C

/*
  Default register values
  Below are the defines for each register's default value in the 24L01. Multi-byte
  registers use notation B<X>, where "B" represents "byte" and <X> is the byte number.
*/
#define nRF24_CONFIG_DEFAULT_VAL            0x08
#define nRF24_EN_AA_DEFAULT_VAL             0x3F
#define nRF24_EN_RXADDR_DEFAULT_VAL         0x03
#define nRF24_SETUP_AW_DEFAULT_VAL          0x03
#define nRF24_SETUP_RETR_DEFAULT_VAL        0x03
#define nRF24_RF_CH_DEFAULT_VAL             0x02
#define nRF24_RF_SETUP_DEFAULT_VAL          0x0F
#define nRF24_STATUS_DEFAULT_VAL            0x0E
#define nRF24_OBSERVE_TX_DEFAULT_VAL        0x00
#define nRF24_CD_DEFAULT_VAL                0x00
#define nRF24_RX_ADDR_P0_B0_DEFAULT_VAL     0xE7
#define nRF24_RX_ADDR_P0_B1_DEFAULT_VAL     0xE7
#define nRF24_RX_ADDR_P0_B2_DEFAULT_VAL     0xE7
#define nRF24_RX_ADDR_P0_B3_DEFAULT_VAL     0xE7
#define nRF24_RX_ADDR_P0_B4_DEFAULT_VAL     0xE7
#define nRF24_RX_ADDR_P1_B0_DEFAULT_VAL     0xC2
#define nRF24_RX_ADDR_P1_B1_DEFAULT_VAL     0xC2
#define nRF24_RX_ADDR_P1_B2_DEFAULT_VAL     0xC2
#define nRF24_RX_ADDR_P1_B3_DEFAULT_VAL     0xC2
#define nRF24_RX_ADDR_P1_B4_DEFAULT_VAL     0xC2
#define nRF24_RX_ADDR_P2_DEFAULT_VAL        0xC3
#define nRF24_RX_ADDR_P3_DEFAULT_VAL        0xC4
#define nRF24_RX_ADDR_P4_DEFAULT_VAL        0xC5
#define nRF24_RX_ADDR_P5_DEFAULT_VAL        0xC6
#define nRF24_TX_ADDR_B0_DEFAULT_VAL        0xE7
#define nRF24_TX_ADDR_B1_DEFAULT_VAL        0xE7
#define nRF24_TX_ADDR_B2_DEFAULT_VAL        0xE7
#define nRF24_TX_ADDR_B3_DEFAULT_VAL        0xE7
#define nRF24_TX_ADDR_B4_DEFAULT_VAL        0xE7
#define nRF24_RX_PW_P0_DEFAULT_VAL          0x00
#define nRF24_RX_PW_P1_DEFAULT_VAL          0x00
#define nRF24_RX_PW_P2_DEFAULT_VAL          0x00
#define nRF24_RX_PW_P3_DEFAULT_VAL          0x00
#define nRF24_RX_PW_P4_DEFAULT_VAL          0x00
#define nRF24_RX_PW_P5_DEFAULT_VAL          0x00
#define nRF24_FIFO_STATUS_DEFAULT_VAL       0x11
#define nRF24_FEATURE_DEFAULT_VAL           0x00
#define nRF24_DYNPD_DEFAULT_VAL             0x00

/*
  Register bitwise definitions
  Below are the defines for each register's bitwise fields in the 24L01.
*/
//CONFIG register bitwise definitions
#define nRF24_CONFIG_RESERVED               0x80
#define nRF24_CONFIG_MASK_RX_DR             0x40
#define nRF24_CONFIG_MASK_TX_DS             0x20
#define nRF24_CONFIG_MASK_MAX_RT            0x10
#define nRF24_CONFIG_EN_CRC                 0x08
#define nRF24_CONFIG_CRCO                   0x04
#define nRF24_CONFIG_PWR_UP                 0x02
#define nRF24_CONFIG_PRIM_RX                0x01

//EN_AA register bitwise definitions
#define nRF24_EN_AA_RESERVED   0xC0
#define nRF24_EN_AA_ENAA_ALL   0x3F
#define nRF24_EN_AA_ENAA_P5    0x20
#define nRF24_EN_AA_ENAA_P4    0x10
#define nRF24_EN_AA_ENAA_P3    0x08
#define nRF24_EN_AA_ENAA_P2    0x04
#define nRF24_EN_AA_ENAA_P1    0x02
#define nRF24_EN_AA_ENAA_P0    0x01
#define nRF24_EN_AA_ENAA_NONE  0x00

//EN_RXADDR register bitwise definitions
#define nRF24_EN_RXADDR_RESERVED 0xC0
#define nRF24_EN_RXADDR_ERX_ALL  0x3F
#define nRF24_EN_RXADDR_ERX_P5 0x20
#define nRF24_EN_RXADDR_ERX_P4 0x10
#define nRF24_EN_RXADDR_ERX_P3 0x08
#define nRF24_EN_RXADDR_ERX_P2 0x04
#define nRF24_EN_RXADDR_ERX_P1 0x02
#define nRF24_EN_RXADDR_ERX_P0 0x01
#define nRF24_EN_RXADDR_ERX_NONE 0x00

//SETUP_AW register bitwise definitions
#define nRF24_SETUP_AW_RESERVED  0xFC
#define nRF24_SETUP_AW     0x03
#define nRF24_SETUP_AW_5BYTES  0x03
#define nRF24_SETUP_AW_4BYTES  0x02
#define nRF24_SETUP_AW_3BYTES  0x01
#define nRF24_SETUP_AW_ILLEGAL 0x00

//SETUP_RETR register bitwise definitions
#define nRF24_SETUP_RETR_ARD     0xF0
#define nRF24_SETUP_RETR_ARD_4000  0xF0
#define nRF24_SETUP_RETR_ARD_3750  0xE0
#define nRF24_SETUP_RETR_ARD_3500  0xD0
#define nRF24_SETUP_RETR_ARD_3250  0xC0
#define nRF24_SETUP_RETR_ARD_3000  0xB0
#define nRF24_SETUP_RETR_ARD_2750  0xA0
#define nRF24_SETUP_RETR_ARD_2500  0x90
#define nRF24_SETUP_RETR_ARD_2250  0x80
#define nRF24_SETUP_RETR_ARD_2000  0x70
#define nRF24_SETUP_RETR_ARD_1750  0x60
#define nRF24_SETUP_RETR_ARD_1500  0x50
#define nRF24_SETUP_RETR_ARD_1250  0x40
#define nRF24_SETUP_RETR_ARD_1000  0x30
#define nRF24_SETUP_RETR_ARD_750   0x20
#define nRF24_SETUP_RETR_ARD_500   0x10
#define nRF24_SETUP_RETR_ARD_250   0x00
#define nRF24_SETUP_RETR_ARC     0x0F
#define nRF24_SETUP_RETR_ARC_15    0x0F
#define nRF24_SETUP_RETR_ARC_14    0x0E
#define nRF24_SETUP_RETR_ARC_13    0x0D
#define nRF24_SETUP_RETR_ARC_12    0x0C
#define nRF24_SETUP_RETR_ARC_11    0x0B
#define nRF24_SETUP_RETR_ARC_10    0x0A
#define nRF24_SETUP_RETR_ARC_9   0x09
#define nRF24_SETUP_RETR_ARC_8   0x08
#define nRF24_SETUP_RETR_ARC_7   0x07
#define nRF24_SETUP_RETR_ARC_6   0x06
#define nRF24_SETUP_RETR_ARC_5   0x05
#define nRF24_SETUP_RETR_ARC_4   0x04
#define nRF24_SETUP_RETR_ARC_3   0x03
#define nRF24_SETUP_RETR_ARC_2   0x02
#define nRF24_SETUP_RETR_ARC_1   0x01
#define nRF24_SETUP_RETR_ARC_0   0x00

//RF_CH register bitwise definitions
#define nRF24_RF_CH_RESERVED 0x80

//RF_SETUP register bitwise definitions
#define nRF24_RF_SETUP_RESERVED  0xE0
#define nRF24_RF_SETUP_PLL_LOCK  0x10
#define nRF24_RF_SETUP_RF_DR   0x08
#define nRF24_RF_SETUP_RF_PWR  0x06
#define nRF24_RF_SETUP_RF_PWR_0  0x06
#define nRF24_RF_SETUP_RF_PWR_6  0x04
#define nRF24_RF_SETUP_RF_PWR_12 0x02
#define nRF24_RF_SETUP_RF_PWR_18 0x00
#define nRF24_RF_SETUP_LNA_HCURR 0x01

//STATUS register bitwise definitions
#define nRF24_STATUS_RESERVED          0x80
#define nRF24_STATUS_RX_DR           0x40
#define nRF24_STATUS_TX_DS           0x20
#define nRF24_STATUS_MAX_RT            0x10
#define nRF24_STATUS_RX_P_NO           0x0E
#define nRF24_STATUS_RX_P_NO_RX_FIFO_NOT_EMPTY 0x0E
#define nRF24_STATUS_RX_P_NO_UNUSED        0x0C
#define nRF24_STATUS_RX_P_NO_5         0x0A
#define nRF24_STATUS_RX_P_NO_4         0x08
#define nRF24_STATUS_RX_P_NO_3         0x06
#define nRF24_STATUS_RX_P_NO_2         0x04
#define nRF24_STATUS_RX_P_NO_1         0x02
#define nRF24_STATUS_RX_P_NO_0         0x00
#define nRF24_STATUS_TX_FULL           0x01

//OBSERVE_TX register bitwise definitions
#define nRF24_OBSERVE_TX_PLOS_CNT  0xF0
#define nRF24_OBSERVE_TX_ARC_CNT   0x0F

//CD register bitwise definitions
#define nRF24_CD_RESERVED  0xFE
#define nRF24_CD_CD      0x01

//RX_PW_P0 register bitwise definitions
#define nRF24_RX_PW_P0_RESERVED  0xC0

//RX_PW_P0 register bitwise definitions
#define nRF24_RX_PW_P0_RESERVED  0xC0

//RX_PW_P1 register bitwise definitions
#define nRF24_RX_PW_P1_RESERVED  0xC0

//RX_PW_P2 register bitwise definitions
#define nRF24_RX_PW_P2_RESERVED  0xC0

//RX_PW_P3 register bitwise definitions
#define nRF24_RX_PW_P3_RESERVED  0xC0

//RX_PW_P4 register bitwise definitions
#define nRF24_RX_PW_P4_RESERVED  0xC0

//RX_PW_P5 register bitwise definitions
#define nRF24_RX_PW_P5_RESERVED  0xC0

//FIFO_STATUS register bitwise definitions
#define nRF24_FIFO_STATUS_RESERVED 0x8C
#define nRF24_FIFO_STATUS_TX_REUSE 0x40
#define nRF24_FIFO_STATUS_TX_FULL  0x20
#define nRF24_FIFO_STATUS_TX_EMPTY 0x10
#define nRF24_FIFO_STATUS_RX_FULL  0x02
#define nRF24_FIFO_STATUS_RX_EMPTY 0x01

//FEATURE register bitwise definitions
#define nRF24_FEATURE_EN_DPL        0x04
#define nRF24_FEATURE_EN_ACK_PAY    0x02
#define nRF24_FEATURE_EN_DYN_ACK    0x01

//DYNPD register bitwise definitions
#define nRF24_DYNPD_DPL_P5        0x20
#define nRF24_DYNPD_DPL_P4        0x10
#define nRF24_DYNPD_DPL_P3        0x08
#define nRF24_DYNPD_DPL_P2        0x04
#define nRF24_DYNPD_DPL_P1        0x02
#define nRF24_DYNPD_DPL_P0        0x01

#define nRF24_R_RX_PL_WID         0x60

#define nRF24_W_ACK_PAYLOAD_P0  (nRF24_W_ACK_PAYLOAD)
#define nRF24_W_ACK_PAYLOAD_P1  (nRF24_W_ACK_PAYLOAD | 0x01)
#define nRF24_W_ACK_PAYLOAD_P2  (nRF24_W_ACK_PAYLOAD | 0x02)
#define nRF24_W_ACK_PAYLOAD_P3  (nRF24_W_ACK_PAYLOAD | 0x03)
#define nRF24_W_ACK_PAYLOAD_P4  (nRF24_W_ACK_PAYLOAD | 0x04)
#define nRF24_W_ACK_PAYLOAD_P5  (nRF24_W_ACK_PAYLOAD | 0x05)
#define nRF24_ADR_LEN         (5)
#define nRF24_RX_ADR_P0_DFT   {0xE7, 0xE7, 0xE7, 0xE7, 0xE7}
#define nRF24_RX_ADR_P1_DFT   {0xC2, 0xC2, 0xC2, 0xC2, 0xC2}
#define nRF24_RX_ADR_P2_DFT   {0xC3, 0xC2, 0xC2, 0xC2, 0xC2}
#define nRF24_RX_ADR_P3_DFT   {0xC4, 0xC2, 0xC2, 0xC2, 0xC2}
#define nRF24_RX_ADR_P4_DFT   {0xC5, 0xC2, 0xC2, 0xC2, 0xC2}
#define nRF24_RX_ADR_P5_DFT   {0xC6, 0xC2, 0xC2, 0xC2, 0xC2}
#define nRF24_TX_ADR_DFT      {0xE7, 0xE7, 0xE7, 0xE7, 0xE7}
#define nRF24_TX_DATA_LEN_MAX (32)
#define nRF24_RX_DATA_LEN_MAX (32)
#define nRF24_TX_DATA_LEN_DFT (nRF24_TX_DATA_LEN_MAX)
#define nRF24_RX_DATA_LEN_DFT (nRF24_RX_DATA_LEN_MAX)

typedef enum {
  PRIMARY_TX,
  PRIMARY_RX
} nRF24_TxRx_Mode;

typedef struct
{
  nRF24_TxRx_Mode TxRxMode;
  uint8_t RX_ADR_P0[nRF24_ADR_LEN];
  uint8_t RX_ADR_P1[nRF24_ADR_LEN];
  uint8_t RX_ADR_P2[nRF24_ADR_LEN];
  uint8_t RX_ADR_P3[nRF24_ADR_LEN];
  uint8_t RX_ADR_P4[nRF24_ADR_LEN];
  uint8_t RX_ADR_P5[nRF24_ADR_LEN];
  uint8_t TX_ADR[nRF24_ADR_LEN];
  void (*InterruptCallback)();
} nRF24_SettingsTypeDef;

typedef struct
{
  nRF24_SettingsTypeDef settings;
  uint8_t isInit;
  uint8_t lastStatus;
  uint8_t RxDataNew;
} nRF24_DataTypeDef;

#define nRF24_DATA_INIT {\
  {PRIMARY_RX,\
  nRF24_RX_ADR_P0_DFT,\
  nRF24_RX_ADR_P1_DFT,\
  nRF24_RX_ADR_P2_DFT,\
  nRF24_RX_ADR_P3_DFT,\
  nRF24_RX_ADR_P4_DFT,\
  nRF24_RX_ADR_P5_DFT,\
  nRF24_TX_ADR_DFT,\
  NULL}, 0, 0, 0}


uint8_t nRF24_isInit(void);
int nRF24_init(nRF24_SettingsTypeDef *settings);
uint8_t nRF24_wrReg(uint8_t adr, uint8_t* data, uint16_t len);
uint32_t nRF24_RxData(uint8_t *rxData);
uint8_t nRF24_RxDataWidth();
uint8_t nRF24_Status();
uint8_t nRF24_FIFOStatus();
uint8_t nRF24_FlagClear(uint8_t mask);
uint8_t nRF24_TxData(uint8_t* data, uint8_t len);
uint8_t nRF24_TxFifoFlush();
uint8_t nRF24_RxFifoFlush();
uint8_t nRF24_RxDataNew();
void nRF24_setRxDataNew(uint8_t RxDataNew);
uint8_t nRF24_spiWrRd_blocking(uint8_t data);


__STATIC_INLINE void nRF24_setCSN(void)
{
  nRF24_CSN_PORT->BSRR = nRF24_CSN_PIN;
}

__STATIC_INLINE void nRF24_setCE(void)
{
  nRF24_CE_PORT->BSRR = nRF24_CE_PIN;
}

__STATIC_INLINE void nRF24_resetCSN(void)
{
  nRF24_CSN_PORT->BSRR = (nRF24_CSN_PIN<<16);
}

__STATIC_INLINE void nRF24_resetCE(void)
{
  nRF24_CE_PORT->BSRR = (nRF24_CE_PIN<<16);
}

__STATIC_INLINE uint8_t nRF24_TxFifoFull()
{
  return (nRF24_FIFOStatus() & nRF24_FIFO_STATUS_TX_FULL);
}

__STATIC_INLINE uint8_t nRF24_RxFifoEmpty()
{
  return (nRF24_FIFOStatus() & nRF24_FIFO_STATUS_RX_EMPTY);
}


#endif /* NRF24_H_ */
