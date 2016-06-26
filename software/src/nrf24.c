

#include "nrf24.h"


static nRF24_DataTypeDef nRF24_data = nRF24_DATA_INIT;

void EXTI4_IRQHandler(void)
{
  __HAL_GPIO_EXTI_CLEAR_IT(nRF24_IRQ_PIN);

  if (nRF24_data.settings.InterruptCallback != NULL)
      nRF24_data.settings.InterruptCallback();

  nRF24_setRxDataNew(1);
}

int nRF24_init(nRF24_SettingsTypeDef *settings)
{
  nRF24_data.settings = *settings;

  nRF24_setCSN();

  uint8_t regData;

  // Default -> power down
  regData = nRF24_CONFIG_DEFAULT_VAL;
  nRF24_wrReg(nRF24_CONFIG, &regData, 1);

  // Enable "Feature" register
  regData = nRF24_ACTIVATE_DATA;
  nRF24_wrReg(nRF24_ACTIVATE_CMD, &regData, 1);

  // Activate dynamic payload length and Payload with ACK
  regData = nRF24_FEATURE_EN_ACK_PAY | nRF24_FEATURE_EN_DPL;
  nRF24_wrReg(nRF24_FEATURE, &regData, 1);

  // Activate dynamic payload length
  regData = nRF24_DYNPD_DPL_P0 | nRF24_DYNPD_DPL_P1;
  nRF24_wrReg(nRF24_DYNPD, &regData, 1);

  // ARD > 500 us
  regData = nRF24_SETUP_RETR_DEFAULT_VAL;//nRF24_SETUP_RETR_ARD_500 | nRF24_SETUP_RETR_ARC_3;
  nRF24_wrReg(nRF24_SETUP_RETR, &regData, 1);

  // # CONFIG
  regData = nRF24_CONFIG_PWR_UP | nRF24_CONFIG_CRCO | nRF24_CONFIG_EN_CRC;
  // Disable all interrupts except data-ready
  regData |= nRF24_CONFIG_MASK_TX_DS | nRF24_CONFIG_MASK_MAX_RT; 
  if (nRF24_data.settings.TxRxMode == PRIMARY_RX)
    regData |= nRF24_CONFIG_PRIM_RX;
  nRF24_wrReg(nRF24_CONFIG, &regData, 1);

  // # SETUP_AW
  regData = nRF24_SETUP_AW_5BYTES;
  nRF24_wrReg(nRF24_SETUP_AW, &regData, 1);

  // # RF_CH
  regData = 50;
  nRF24_wrReg(nRF24_RF_CH, &regData, 1);

  // # RF_SETUP = default
  regData = nRF24_RF_SETUP_DEFAULT_VAL;
  nRF24_wrReg(nRF24_RF_SETUP, &regData, 1);


  // # EN_AA
  regData = nRF24_EN_AA_ENAA_P0 | nRF24_EN_AA_ENAA_P1;
  nRF24_wrReg(nRF24_EN_AA, &regData, 1);

  // # EN_RXADDR
  regData = nRF24_EN_RXADDR_ERX_P0 | nRF24_EN_RXADDR_ERX_P1;
  nRF24_wrReg(nRF24_EN_RXADDR, &regData, 1);

  if (nRF24_data.settings.TxRxMode == PRIMARY_TX) {
    // # TX_ADDR
    nRF24_wrReg(nRF24_TX_ADDR, settings->TX_ADR, nRF24_ADR_LEN);
    // # RX_ADDR_P0 must be == TX_ADDR for PTX
    nRF24_wrReg(nRF24_RX_ADDR_P0, settings->TX_ADR, nRF24_ADR_LEN);
  } else {
    // # RX_ADDR_P1
    nRF24_wrReg(nRF24_RX_ADDR_P1, settings->RX_ADR_P1, nRF24_ADR_LEN);
  }

  // Flush TX FIFO
  nRF24_TxFifoFlush();
  // Flush RX FIFO
  nRF24_RxFifoFlush();
  // # STATUS clear any it-flags
  regData = nRF24_STATUS_RX_DR | nRF24_STATUS_TX_DS | nRF24_STATUS_MAX_RT | nRF24_STATUS_DEFAULT_VAL;
  nRF24_wrReg(nRF24_STATUS, &regData, 1);

  nRF24_data.isInit = 1;

  nRF24_setCE();

  return 0;
}

uint8_t nRF24_TxData(uint8_t* data, uint8_t len)
{
  if (nRF24_data.settings.TxRxMode == PRIMARY_TX)
    nRF24_wrReg(nRF24_W_TX_PAYLOAD, data, len);
  else
    nRF24_wrReg(nRF24_W_ACK_PAYLOAD_P1, data, len);

  return nRF24_Status();
}

uint32_t nRF24_RxData(uint8_t *rxData)
{
  uint8_t dataWidth = nRF24_RxDataWidth();

  if (dataWidth > nRF24_RX_DATA_LEN_MAX) {
    nRF24_RxFifoFlush();
    return 0;
  }

  nRF24_resetCSN();

  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_R_RX_PAYLOAD);

  uint8_t i;
  for (i=0; i<dataWidth; i++)
    rxData[i] = nRF24_spiWrRd_blocking(nRF24_NOP);

  nRF24_setCSN();

  return dataWidth;
}

uint8_t nRF24_RxDataWidth()
{
  uint8_t tmp;

  nRF24_resetCSN();

  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_R_RX_PL_WID);
  tmp = nRF24_spiWrRd_blocking(nRF24_NOP);

  nRF24_setCSN();

  return tmp;
}

uint8_t nRF24_wrReg(uint8_t adr, uint8_t* data, uint16_t len)
{
  uint16_t i;

  nRF24_resetCSN();
  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(adr | nRF24_W_REGISTER);

  for (i=0; i<len; i++) {
    nRF24_spiWrRd_blocking(data[i]);
  }

  nRF24_setCSN();

  return nRF24_data.lastStatus;
}

uint8_t nRF24_spiWrRd_blocking(uint8_t data)
{
  uint32_t timeOutCnt = 0;

  while(!(nRF24_SPI_INSTANCE->SR & SPI_FLAG_TXE) && (timeOutCnt++ < nRF24_SPIWRRD_TIOUT));

  nRF24_SPI_INSTANCE->DR = data;

  timeOutCnt = 0;

  while(!(nRF24_SPI_INSTANCE->SR & SPI_FLAG_RXNE) && (timeOutCnt++ < nRF24_SPIWRRD_TIOUT));

  return (uint8_t) (nRF24_SPI_INSTANCE->DR);
}

uint8_t nRF24_isInit(void)
{
  return nRF24_data.isInit;
}

uint8_t nRF24_FlagClear(uint8_t mask)
{
  return nRF24_wrReg(nRF24_STATUS, &mask, 1);
}

uint8_t nRF24_Status()
{
  nRF24_resetCSN();

  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_NOP);

  nRF24_setCSN();

  return nRF24_data.lastStatus;
}

uint8_t nRF24_FIFOStatus()
{
  uint8_t sts;

  nRF24_resetCSN();

  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_R_REGISTER | nRF24_FIFO_STATUS);
  sts = nRF24_spiWrRd_blocking(nRF24_NOP);

  nRF24_setCSN();

  return sts;
}

uint8_t nRF24_RxDataNew()
{
  return (nRF24_data.RxDataNew);
}

void nRF24_setRxDataNew(uint8_t RxDataNew)
{
  nRF24_data.RxDataNew = RxDataNew;
}

uint8_t nRF24_TxFifoFlush()
{
  nRF24_resetCSN();
  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_FLUSH_TX);
  nRF24_setCSN();

  return nRF24_data.lastStatus;
}

uint8_t nRF24_RxFifoFlush()
{
  nRF24_resetCSN();
  nRF24_data.lastStatus = nRF24_spiWrRd_blocking(nRF24_FLUSH_RX);
  nRF24_setCSN();

  return nRF24_data.lastStatus;
}
