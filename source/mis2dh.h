/**
 * @file       mis2dh.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support MIS2DH (Accelerometer)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __MIS2DH_H
#define __MIS2DH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
#define MIS2DH_I2C_ADDR                  (0xC0 >> 1)

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief MIS2DH sensor struct
 */
typedef struct 
{
  uint8_t  device_address;  // I2C device address

  struct
  {
    float x;
    float y;
    float z;
  }
  rawdata;

  // Read n-bytes from device's internal address <reg_addr> via I2C bus
  base_status_t (*i2c_read) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);

  // Write n-bytes from device's internal address <reg_addr> via I2C bus
  base_status_t (*i2c_write) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);
}
mis2dh_t;

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __MIS2DH_H

/* End of file -------------------------------------------------------- */
