/*
 * utils.c
 *
 *  Created on: 30 aug 2015
 *      Author: osannolik
 */

#include "utils.h"

unsigned char utils_crc(char *pch)
{
  unsigned char bit, crc=0;

  while (*pch) {
    crc ^= *pch++;
    for (bit = 8; bit > 0; --bit) {
      if (crc & 0x80)
        crc = (crc << 1) ^ 0x18;
      else
        crc = (crc << 1);
    }
  }

  return crc;
}
