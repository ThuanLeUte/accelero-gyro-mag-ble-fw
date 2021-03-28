/**
 * @file       gc9a01.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support GC9A01 (LCD driver)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __GC9A01_H
#define __GC9A01_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "gc9a01_defs.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief GC9A01 sensor struct
 */
typedef struct 
{
  uint8_t  device_address;  // I2C device address

  // Send one byte via SPI bus
  base_status_t (*spi_send) (uint8_t tx_data);

  // Delay ms
  void (*delay_ms) (uint32_t ms);

  // Gpio set
  void (*gpio_write) (uint8_t pin, uint8_t state);
}
gc9a01_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Initialize GC9A01
 *
 * @param[in]     me            Pointer to handle of GC9A01 module.
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t gc9a01_init(gc9a01_t *me);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __GC9A01_H

/* End of file -------------------------------------------------------- */
