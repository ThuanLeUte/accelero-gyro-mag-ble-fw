/**
 * @file       cht8305.c
 * @copyright  Copyright (C) 2020 Thuan Le. All rights reserved.
 * @license    This project is released under the Thuan Le License.
 * @version    1.0.0
 * @date       2020-06-02
 * @author     Thuan Le
 * @brief      Driver for CHT8305 Sensor. 
 * @note       None
 */

/* Includes ----------------------------------------------------------- */
#include "cht8305.h"
#include "nrf_log.h"

/* Private defines ---------------------------------------------------- */
#define CHT8305_REG_TEMP    (0x00)  /*! cht8305 temperature address     */
#define CHT8305_REG_HUMI    (0x01)  /*! cht8305 humidity address        */
#define CHT8305_REG_CONF    (0x02)  /*! cht8305 config address          */
#define CHT8305_REG_ALERT   (0x03)  /*! cht8305 alert setup address     */
#define CHT8305_REG_MANU    (0xFE)  /*! cht8305 manufacture ID address  */
#define CHT8305_REG_VER     (0xFF)  /*! cht8305 version ID address      */

const uint8_t CHT8305_I2C_ADDR[] = 
{
  0x80 >> 1,  // AD0 - GND
  0x88 >> 1,  // AD0 - VCC
  0x90 >> 1,  // AD0 - SDA
  0x98 >> 1   // AD0 - SCL
};

/* Function definitions ----------------------------------------------- */
cht8305_status_t cht8305_init(cht8305_t *me)
{
  if ((me == NULL) || (me->i2c_read == NULL))
    return CHT8305_ERR_PARAM;

  for (int i = 0; i < 4; i++)
  {
    me->device_address = CHT8305_I2C_ADDR[i];

    if (cht8305_is_connected(me) == true)
    {
      NRF_LOG_INFO("cht8305 init ok \n");
      return CHT8305_OK;
    }
  }

  NRF_LOG_INFO("cht8305 init failed \n");
  return CHT8305_ERR_I2C;
}

cht8305_status_t cht8305_get_data(cht8305_t *me)
{
  uint8_t buf[4];
  
  if (me->i2c_read(me->device_address, CHT8305_REG_TEMP, buf, 4) != 0)
    return CHT8305_ERR_I2C; 
  
  me->temp = (buf[0] << 8 | buf[1]) * 165.0 / 65535.0 - 40.0;
  me->humi = (buf[2] << 8 | buf[3]) * 100.0 / 65535.0;

  return CHT8305_OK;
}

cht8305_status_t cht8305_get_manufacture_id(cht8305_t *me, uint16_t *man_id)
{
  uint8_t buf[2];

  if (me->i2c_read(me->device_address, CHT8305_REG_MANU, buf, 2) != 0)
    return CHT8305_ERR_I2C;

  *man_id = buf[0] << 8 | buf[1];

  return CHT8305_OK;
}

cht8305_status_t cht8305_get_version_id(cht8305_t *me, uint16_t *version_id)
{
  uint8_t buf[2];

  if (me->i2c_read(me->device_address, CHT8305_REG_VER, buf, 2) != 0)
    return CHT8305_ERR_I2C;

  *version_id = buf[0] << 8 | buf[1];

  return CHT8305_OK;
}

bool cht8305_is_connected(cht8305_t *me)
{
  uint16_t man_id = 0;

  cht8305_get_manufacture_id(me, &man_id);

  return (man_id == CHT8305_MAN_ID) ? true : false;
}

/* End of file -------------------------------------------------------- */
