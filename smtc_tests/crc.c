/**
  ******************************************************************************
  * @file    crc.c
  * @brief   This file provides code for the configuration
  *          of the CRC instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "crc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* USER CODE BEGIN 1 */
uint32_t crc32(const void * data, size_t len, uint32_t init)
{
  const uint32_t polynomial = 0x04C11DB7; /* divisor is 32bit */
  static uint32_t crc = 0xFFFFFFFF; /* CRC value is 32bit */
  uint8_t *p8 = (uint8_t *) data;

  if(init)
    crc = 0xFFFFFFFF;

  while(len--)
    {
      crc ^= (uint32_t)(*p8 << 24u); /* move byte into MSB of 32bit CRC */

      for(int i = 0; i < 8; i++)
        {
          if((crc & 0x80000000) != 0) /* test for MSB = bit 31 */
            {
              crc = (crc << 1u) ^ polynomial;
            }
          else
            {
              crc <<= 1u;
            }
        }

      ++p8;
    }

  return crc;
}

#define CRC8_POLY_      0x7u
#define CRC8_INIT_      0x00u
#define CRC8_FINAL_XOR_ 0x00u

uint8_t crc8(const void * data, size_t len)
{
  uint8_t     crc  = CRC8_INIT_;
  for (size_t byte = 0; byte < len; ++byte)
    {
      crc ^= (((uint8_t *) data)[byte]);
      for (uint8_t bit = 8; bit > 0; --bit)
        {
          if (crc & 0x80u)
            {
              crc = (uint8_t) (((unsigned) crc << 1u) ^ CRC8_POLY_);
            }
          else
            {
              crc = (crc << 1u);
            }
        }
    }
  return (uint8_t) (crc ^ CRC8_FINAL_XOR_);
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
