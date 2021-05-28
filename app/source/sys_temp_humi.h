/**
 * @file       sys_temp_humi.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Sytem module to handle temperature and humidity sensor
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYS_TEMP_HUMI_H
#define __SYS_TEMP_HUMI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>
#include "cht8305.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         System temperature and humidity sensor init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return
 * - CHT8305_OK
 * - CHT8305_ERR_PARAM
 * - CHT8305_ERR_I2C
 */
cht8305_status_t sys_temp_humi_init(void);

/**
 * @brief         System temperature sensor get
 *
 * @param[in]     temp      Pointer to handler temperature data
 * @param[in]     humi      Pointer to handler humidity data
 *
 * @attention     None
 *
 * @return
 * - CHT8305_OK
 * - CHT8305_ERR_I2C
 */
cht8305_status_t sys_temp_humi_get(float *temp, float *humi);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __SYS_TEMP_HUMI_H

/* End of file -------------------------------------------------------- */
