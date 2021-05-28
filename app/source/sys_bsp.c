/**
 * @file       bsp.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "sys_bsp.h"

/* Private defines ---------------------------------------------------- */
#ifdef  TEMPERATURE_BOARD

#define NRF_SCL_PIN             16    // SCL signal pin
#define NRF_SDA_PIN             15    // SDA signal pin

#else

#define NRF_SCL_PIN             15    // SCL signal pin
#define NRF_SDA_PIN             16    // SDA signal pin
#define OB1203_INTR_PIN         12    // OB1203 interrupt pin

#endif

#define TWI_INSTANCE_ID         0

/* Private enumerate/structure ---------------------------------------- */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static void m_i2c_init(void);

#ifndef TEMPERATURE_BOARD
static void m_gpio_init(void);
#endif

/* Function definitions ----------------------------------------------- */
void sys_bsp_init(void)
{
  m_i2c_init();

#ifndef TEMPERATURE_BOARD
  m_gpio_init();
#endif
}

int sys_bsp_i2c_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len)
{
  uint8_t buffer[10];

  memcpy(buffer, &reg_addr, 1);
  memcpy(buffer + 1, p_data, len);

  return nrf_drv_twi_tx(&m_twi, slave_addr, buffer, len + 1, false);
}

int sys_bsp_i2c_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len)
{
  nrf_drv_twi_tx(&m_twi, slave_addr, (uint8_t *)&reg_addr, 1, true);

  return nrf_drv_twi_rx(&m_twi, slave_addr, p_data, len);
}

uint32_t sys_bsp_time_now(void)
{
  return app_timer_cnt_get();
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
static void m_i2c_init(void)
{
  ret_code_t err_code;

  const nrf_drv_twi_config_t twi_config =
  {
    .scl                = NRF_SCL_PIN,
    .sda                = NRF_SDA_PIN,
    .frequency          = NRF_DRV_TWI_FREQ_400K,
    .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
    .clear_bus_init     = false
  };

  err_code = nrf_drv_twi_init(&m_twi, &twi_config, NULL, NULL);
  APP_ERROR_CHECK(err_code);

  nrf_drv_twi_enable(&m_twi);
}

#ifndef TEMPERATURE_BOARD
/**
 * @brief         Gpio init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
static void m_gpio_init(void)
{
 ret_code_t err_code;

 err_code = nrf_drv_gpiote_init();
 APP_ERROR_CHECK(err_code);

 nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
 in_config.pull = NRF_GPIO_PIN_PULLUP;

 err_code = nrf_drv_gpiote_in_init(OB1203_INTR_PIN, &in_config, sys_bsp_intr_pin_handler);
 APP_ERROR_CHECK(err_code);

 nrf_drv_gpiote_in_event_enable(OB1203_INTR_PIN, true);
}
#endif

/* End of file -------------------------------------------------------- */
