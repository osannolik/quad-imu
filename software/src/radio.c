/*
 * radio.c
 *
 *  Created on: 15 nov 2015
 *      Author: osannolik
 */


#include "radio.h"
#include "com.h"
#include "queue.h"
#include "stm32f4xx_hal.h"
#include "nrf24.h"

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

static radio_DataTypeDef radio_data = RADIO_DATA_INIT;

static uint8_t radio_ByteBufRx[RADIO_BUF_RX_LEN];

uint32_t radio_receive_data(uint8_t **data)
{
  uint8_t *buf_ptr = radio_ByteBufRx;

  while (!nRF24_RxFifoEmpty())
    buf_ptr += nRF24_RxData(buf_ptr);

  *data = radio_ByteBufRx;

  return (buf_ptr - radio_ByteBufRx);
}

uint32_t radio_send_data(uint8_t* data, uint16_t len)
{
  uint16_t len_to_send;
  uint8_t *from_address, *next_address = data;

  if (nRF24_TxFifoFull()) {
    if (++radio_data.tx_fifo_full_cntr < RADIO_TX_FIFO_FULL_CNTR_MAX) {
      return 0;
    } else {
      nRF24_TxFifoFlush();
      radio_data.tx_fifo_full_cntr = 0;
    }
  }

  do {
    len_to_send = MIN(len, nRF24_TX_DATA_LEN_MAX);
    from_address = next_address;
    len -= len_to_send;
    next_address += len_to_send;
  } while (len_to_send && !(nRF24_TxData(from_address, len_to_send) & nRF24_FIFO_STATUS_TX_FULL));

  return (uint32_t) (next_address - data);
}

int radio_init()
{
  int err = 0;

  err |= radio_init_io();
  err |= radio_init_peripheral();

  if (err)
    return -1;

  nRF24_SettingsTypeDef nRF24_settings;

  nRF24_settings.TxRxMode = PRIMARY_TX;
  uint8_t a;
  for (a=0; a<nRF24_ADR_LEN; a++)
    nRF24_settings.TX_ADR[a] = 0xE7;
  nRF24_settings.InterruptCallback = NULL;

  radio_data.is_init = 1;

  return nRF24_init(&nRF24_settings);
}

int radio_init_peripheral()
{
  // Enable oscillator output
  HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO2SOURCE_HSE, RCC_MCODIV_1);
  //__HAL_RCC_SPI1_CLK_ENABLE();
  __HAL_RCC_SPI2_CLK_ENABLE();

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
  SPIhandle.Instance = nRF24_SPI_INSTANCE;

  HAL_SPI_Init(&SPIhandle);
  __HAL_SPI_ENABLE(&SPIhandle);

  return 0;
}

int radio_init_io()
{
  GPIO_InitTypeDef GPIOinitstruct;

  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  //__HAL_RCC_GPIOA_CLK_ENABLE();

  // MOSI
  GPIOinitstruct.Pin = nRF24_MOSI_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  //GPIOinitstruct.Alternate = GPIO_AF5_SPI1;
  GPIOinitstruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(nRF24_MOSI_PORT, &GPIOinitstruct);

  // MISO
  GPIOinitstruct.Pin = nRF24_MISO_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  //GPIOinitstruct.Alternate = GPIO_AF5_SPI1;
  GPIOinitstruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(nRF24_MISO_PORT, &GPIOinitstruct);

  // SCK
  GPIOinitstruct.Pin = nRF24_SCK_PIN;
  GPIOinitstruct.Pull = GPIO_NOPULL;
  GPIOinitstruct.Mode = GPIO_MODE_AF_PP;
  //GPIOinitstruct.Alternate = GPIO_AF5_SPI1;
  GPIOinitstruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(nRF24_SCK_PORT, &GPIOinitstruct);

  // CSN
  GPIOinitstruct.Pin = nRF24_CSN_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_OUTPUT_PP;
  HAL_GPIO_Init(nRF24_CSN_PORT, &GPIOinitstruct);

  // CE
  GPIOinitstruct.Pin = nRF24_CE_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_NOPULL;
  GPIOinitstruct.Mode = GPIO_MODE_OUTPUT_PP;
  HAL_GPIO_Init(nRF24_CE_PORT, &GPIOinitstruct);

  // IRQ
  GPIOinitstruct.Pin = nRF24_IRQ_PIN;
  GPIOinitstruct.Speed = GPIO_SPEED_HIGH;
  GPIOinitstruct.Pull = GPIO_PULLUP;
  GPIOinitstruct.Mode = GPIO_MODE_IT_FALLING;
  HAL_GPIO_Init(nRF24_IRQ_PORT, &GPIOinitstruct);
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0x0F, 0x0F);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  return 0;
}
