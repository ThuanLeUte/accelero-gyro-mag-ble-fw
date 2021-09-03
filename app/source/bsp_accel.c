/**
 * @file       bsp_accelero.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-24
 * @author     Thuan Le
 * @brief      Board support package for Accelerometer (MIS2DH)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_accel.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static mis2dh_t m_mis2dh;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
base_status_t bsp_accel_init(void)
{
  m_mis2dh.device_address = MIS2DH_I2C_ADDR;
  m_mis2dh.i2c_read       = bsp_i2c_read;
  m_mis2dh.i2c_write      = bsp_i2c_write;

  CHECK_STATUS(mis2dh_init(&m_mis2dh));
  CHECK_STATUS(mis2dh_enable_axis(&m_mis2dh, MIS2DH_AXIS_XYZ_ENABLE));
  CHECK_STATUS(mis2dh_set_resolution(&m_mis2dh, MIS2DH_RES_VALUE_8_BIT));
  CHECK_STATUS(mis2dh_set_refresh_rate(&m_mis2dh, MIS2DH_RF_RATE_400HZ));
  CHECK_STATUS(mis2dh_set_scale(&m_mis2dh, MIS2DH_SCALE_2G));

  return BS_OK;
}

base_status_t bsp_accel_get_raw_axis(mis2dh_data_t *raw_axis)
{
  CHECK_STATUS(mis2dh_get_raw_axis(&m_mis2dh, raw_axis));

  return BS_OK;
}

base_status_t bsp_accel_get_g_axis(mis2dh_data_t *g_axis)
{
  CHECK_STATUS(mis2dh_get_g_axis(&m_mis2dh, g_axis));

  return BS_OK;
}

base_status_t bsp_accel_get_ms2_axis(mis2dh_data_ms2_t *ms2_axis)
{
  CHECK_STATUS(mis2dh_get_ms2_axis(&m_mis2dh, ms2_axis));

  return BS_OK;
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
