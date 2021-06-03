/**
 * @file       bsp_lcd.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support LCD
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_lcd.h"

/* Private defines ---------------------------------------------------- */
gc9a01_t m_gc9a01;

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_lcd_init(void)
{
  m_gc9a01.delay_ms   = bsp_delay_ms;
  m_gc9a01.gpio_write = bsp_gpio_write;
  m_gc9a01.spi_send   = bsp_spi_write;

  gc9a01_init(&m_gc9a01);
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief         I2C init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */


/* End of file -------------------------------------------------------- */