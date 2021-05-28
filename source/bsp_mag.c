/**
 * @file       bsp_mag.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-24
 * @author     Thuan Le
 * @brief      Board support package for Magnetometer (HMC5883L)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_mag.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static hmc5883l_t m_hmc5883l;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
base_status_t bsp_mag_init(void)
{
  m_hmc5883l.device_address = HMC5883L_I2C_ADDR;
  m_hmc5883l.i2c_read       = bsp_i2c_read;
  m_hmc5883l.i2c_write      = bsp_i2c_write;

  hmc5883l_init(&m_hmc5883l);
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
