/**
 * @file       mis2dh.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support MIS2DH (Accelerometer)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "mis2dh.h"

/* Private defines ---------------------------------------------------- */
// Registers
#define MIS2DH_REG_                   (0x00)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static base_status_t m_mis2dh_read_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);
static base_status_t m_mis2dh_write_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);

/* Function definitions ----------------------------------------------- */
base_status_t mis2dh_init(mis2dh_t *me)
{
  uint8_t identifier = 0x00;

  if ((me == NULL) || (me->i2c_read == NULL) || (me->i2c_write == NULL))
    return BS_ERROR;
  
  // TODO: Add init code 

  return BS_OK;
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief         MIS2DH read register
 *
 * @param[in]     me      Pointer to handle of MIS2DH module.
 * @param[in]     reg     Register
 * @param[in]     p_data  Pointer to handle of data
 * @param[in]     len     Data length
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
static base_status_t m_mis2dh_read_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len)
{
  CHECK(0 == me->i2c_read(me->device_address, reg, p_data, len), BS_ERROR);

  return BS_OK;
}

/**
 * @brief         MIS2DH read register
 *
 * @param[in]     me      Pointer to handle of MIS2DH module.
 * @param[in]     reg     Register
 * @param[in]     p_data  Pointer to handle of data
 * @param[in]     len     Data length
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
static base_status_t m_mis2dh_write_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len)
{
  CHECK(0 == me->i2c_write(me->device_address, reg, p_data, len), BS_ERROR);

  return BS_OK;
}

/* End of file -------------------------------------------------------- */
