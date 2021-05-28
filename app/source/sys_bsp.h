/**
 * @file       sys_bsp.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>
#include "nrf_drv_twi.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"
#include "app_timer.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
//#define TEMPERATURE_BOARD

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Board support package init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
void sys_bsp_init(void);

/**
 * @brief         I2C read
 *
 * @param[in]     slave_addr    Slave address
 * @param[in]     reg_addr      Register address
 * @param[in]     p_data        Pointer to handle of data
 * @param[in]     len           Data length
 *
 * @attention     None
 *
 * @return
 * - 0      Succes
 * - 1      Error
 */
int sys_bsp_i2c_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len);

/**
 * @brief         I2C write
 *
 * @param[in]     slave_addr    Slave address
 * @param[in]     reg_addr      Register address
 * @param[in]     p_data        Pointer to handle of data
 * @param[in]     len           Data length
 *
 * @attention     None
 *
 * @return
 * - 0      Succes
 * - 1      Error
 */
int sys_bsp_i2c_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len);

uint32_t sys_bsp_time_now(void);

void sys_bsp_intr_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_H

/* End of file -------------------------------------------------------- */
