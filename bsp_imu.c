/**
 * @file       bsp_imu.C
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-24
 * @author     Thuan Le
 * @brief      Board support package for IMU (MPU9250)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_imu.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static mpu9250_t m_mpu9250;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
base_status_t bsp_imu_init(void)
{
  m_mpu9250.device_address = MPU9250_I2C_ADDR;
  m_mpu9250.i2c_read       = bsp_i2c_read;
  m_mpu9250.i2c_write      = bsp_i2c_write;

  mpu9250_init(&m_mpu9250);
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
