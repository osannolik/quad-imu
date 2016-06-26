/*
 * radio.h
 *
 *  Created on: 15 nov 2015
 *      Author: osannolik
 */

#ifndef RADIO_H_
#define RADIO_H_

#include "com.h"

#define RADIO_TX_FIFO_FULL_CNTR_MAX  (10)
#define RADIO_BUF_RX_LEN             (3*nRF24_RX_DATA_LEN_MAX)

typedef struct
{
  uint8_t tx_fifo_full_cntr;
  uint8_t is_init;
} radio_DataTypeDef;

#define RADIO_DATA_INIT {0, 0}

uint32_t radio_receive_data(uint8_t **data);
uint32_t radio_send_data(uint8_t* pData, uint16_t len);
int radio_init();
int radio_init_peripheral();
int radio_init_io();

#endif /* RADIO_H_ */
