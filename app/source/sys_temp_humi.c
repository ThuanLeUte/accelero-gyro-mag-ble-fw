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

/* Includes ----------------------------------------------------------- */
#include "sys_temp_humi.h"
#include "sys_bsp.h"
#include "nrf_log.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static cht8305_t m_cht8305;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
cht8305_status_t sys_temp_humi_init(void)
{
  m_cht8305.i2c_read = sys_bsp_i2c_read;

  if (cht8305_init(&m_cht8305) == CHT8305_OK)
    return CHT8305_OK;

  return CHT8305_ERR_I2C;
}

cht8305_status_t sys_temp_humi_get(float *temp, float *humi)
{
  cht8305_status_t ret = CHT8305_OK;

  ret = cht8305_get_data(&m_cht8305);

  NRF_LOG_INFO("Return: %d", ret);


  NRF_LOG_INFO("Enviroment temperature: %d", m_cht8305.temp);
  NRF_LOG_INFO("Enviroment humidity: %d", m_cht8305.humi);

  *temp = m_cht8305.temp;
  *humi = m_cht8305.humi;

  return ret;
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
