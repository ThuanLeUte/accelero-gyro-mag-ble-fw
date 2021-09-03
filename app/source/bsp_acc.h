/**
 * @file       bsp_accelero.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-24
 * @author     Thuan Le
 * @brief      Board support package for Accelerometer (MIS2DH)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_ACC_H
#define __BSP_ACC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "mis2dh.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         BSP Accelerometer sensor init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t bsp_acc_init(void);

/**
 * @brief         BSP Accelerometer get raw axis
 *
 * @param[in]     raw_axis  Accelerometer raw axis
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t bsp_acc_get_raw_axis(mis2dh_data_t *raw_axis);

/**
 * @brief         BSP Accelerometer get g axis
 *
 * @param[in]     g_axis   Accelerometer g axis
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t bsp_acc_get_g_axis(mis2dh_data_t *g_axis);

/**
 * @brief         BSP Accelerometer get ms2 axis
 *
 * @param[in]     ms2_axis  Accelerometer ms2 axis
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t bsp_acc_get_ms2_axis(mis2dh_data_ms2_t *ms2_axis);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_ACC_H

/* End of file -------------------------------------------------------- */
