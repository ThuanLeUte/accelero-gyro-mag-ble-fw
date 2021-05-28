/**
 * @file       cht8305.h
 * @copyright  Copyright (C) 2020 Thuan Le. All rights reserved.
 * @license    This project is released under the Thuan Le License.
 * @version    1.0.0
 * @date       2020-06-02
 * @author     Thuan Le
 * @brief      Driver for CHT8305 Sensor.
 * @note       Note
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __CHT8305_H
#define __CHT8305_H

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Public defines ----------------------------------------------------- */
#define CHT8305_MAN_ID    (0x5959)

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief CHT8305 errors
 */
typedef enum
{
  CHT8305_OK = 0x00,
  CHT8305_ERR_PARAM,
  CHT8305_ERR_I2C
}
cht8305_status_t;

/**
 * @brief CHT8305 sensor struct
 */
typedef struct 
{
  uint8_t  device_address;  // I2C device address
  float    temp;            // SHT8305 temperature
  float    humi;            // SHT8305 humidity

  // Return:
  //   0: Success
  //  -1: I2C error
  // Read n-bytes from device's internal address <reg_addr> via I2C bus
  int  (*i2c_read) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);
}
cht8305_t;

/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Initialize ch80305
 *
 * @param[in]     <me>  Pointer to handle of CHT8305 module.
 *
 * @attention     None
 *
 * @return        CHT8305_OK or CHT8305_ERR_PARAM or CHT8305_ERR_I2C 
 */
 cht8305_status_t cht8305_init(cht8305_t *me);

/**
 * @brief         Read ch80305 temperature and humidity to me->temp, me->hum
 *
 * @param[in]     <me>  Pointer to handle of CHT8305 module.
 *
 * @attention     None
 * 
 * @return        CHT8305_OK or CHT8305_ERR_PARAM or CHT8305_ERR_I2C 
 */
 cht8305_status_t cht8305_get_data(cht8305_t *me);

/**
 * @brief         Read out Manufacture ID
 *
 * @param[in]     <me>  Pointer to handle of CHT8305 module.
 *
 * @attention     None
 * 
 * @return        CHT8305_OK or CHT8305_ERR_PARAM or CHT8305_ERR_I2C 
 */
 cht8305_status_t cht8305_get_manufacture_id(cht8305_t *me, uint16_t *man_id);

/**
 * @brief         Read out Sensor Version ID
 *
 * @param[in]     <me>  Pointer to handle of CHT8305 module.
 *
 * @attention     None
 *
 * @return        CHT8305_OK or CHT8305_ERR_PARAM or CHT8305_ERR_I2C 
 */
 cht8305_status_t cht8305_get_version_id(cht8305_t *me, uint16_t *version_id);

/**
 * @brief         Check CHT8305 is connected of not.
 * 
 * @param[in]     <me>  Pointer to handle of CHT8305 module.
 *
 * @attention     None
 *
 * @return        CHT8305_OK or CHT8305_ERR_PARAM or CHT8305_ERR_I2C 
 */
 bool cht8305_is_connected(cht8305_t *me);
  
#endif // __CHT8305_H

/* End of file -------------------------------------------------------- */
