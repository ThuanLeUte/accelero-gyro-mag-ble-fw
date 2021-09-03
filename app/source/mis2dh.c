/**
 * @file       mis2dh.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Hiep Le
 * @brief      Driver support MIS2DH (Accelerometer)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "mis2dh.h"
#include "nrf_log.h"

/* Private defines ---------------------------------------------------- */
// DEFINING GRAVITATIONAL ACCELERATION CONSTANT (IN EUROPE, CROATIA)
#define MIS2DH_VALUE_GRAVITY            (9.806)

// DEFINES MIS2DH REGISTERS
#define MIS2DH_REG_STATUS_REG_AUX       (0X07)
#define MIS2DH_REG_OUT_TEMP_L           (0X0C)
#define MIS2DH_REG_OUT_TEMP_H           (0X0D)
#define MIS2DH_REG_INT_COUNTER_REG      (0X0E)
#define MIS2DH_REG_WHO_AM_I             (0X0F)
#define MIS2DH_REG_TEMP_CFG_REG         (0X1F)
#define MIS2DH_REG_CTRL_REG1            (0X20)
#define MIS2DH_REG_CTRL_REG2            (0X21)
#define MIS2DH_REG_CTRL_REG3            (0X22)
#define MIS2DH_REG_CTRL_REG4            (0X23)
#define MIS2DH_REG_CTRL_REG5            (0X24)
#define MIS2DH_REG_CTRL_REG6            (0X25)
#define MIS2DH_REG_REF_DAT_CAP          (0X26)
#define MIS2DH_REG_STATUS_REG           (0X27)
#define MIS2DH_REG_OUT_X_L              (0X28)
#define MIS2DH_REG_OUT_X_H              (0X29)
#define MIS2DH_REG_OUT_Y_L              (0X2A)
#define MIS2DH_REG_OUT_Y_H              (0X2B)
#define MIS2DH_REG_OUT_Z_L              (0X2C)
#define MIS2DH_REG_OUT_Z_H              (0X2D)
#define MIS2DH_REG_FIFO_CTRL_REG        (0X2E)
#define MIS2DH_REG_FIFO_SCR_REG         (0X2F)
#define MIS2DH_REG_INT1_CFG             (0X30)
#define MIS2DH_REG_INT1_SRC             (0X31)
#define MIS2DH_REG_INT1_THS             (0X32)
#define MIS2DH_REG_INT1_DURATION        (0X33)
#define MIS2DH_REG_INT2_CFG             (0X34)
#define MIS2DH_REG_INT2_SRC             (0X35)
#define MIS2DH_REG_INT2_THS             (0X36)
#define MIS2DH_REG_INT2_DURATION        (0X37)
#define MIS2DH_REG_CLICK_CFG            (0X38)
#define MIS2DH_REG_CLICK_SRC            (0X39)
#define MIS2DH_REG_CLICK_THS            (0X3A)
#define MIS2DH_REG_TIME_LIMIT           (0X3B)
#define MIS2DH_REG_TIME_LATENCY         (0X3C)
#define MIS2DH_REG_TIME_WINDOW          (0X3D)
#define MIS2DH_REG_ACT_THS              (0X3E)
#define MIS2DH_REG_ACT_DUR              (0X3F)

// DEFINES MIS2DH IDENTIFIER VALUE
#define MIS2DH_VALUE_IDENTIFIER         (0X33)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static base_status_t m_mis2dh_read_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);
static base_status_t m_mis2dh_write_reg(mis2dh_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);

static double m_mis2dh_modifed_map(double x, double in_min, double in_max,
                                   double out_min, double out_max);

/* Function definitions ----------------------------------------------- */
base_status_t mis2dh_init(mis2dh_t *me)
{
  uint8_t identifier;

  if ((me == NULL) || (me->i2c_read == NULL) || (me->i2c_write == NULL))
    return BS_ERROR;

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_WHO_AM_I, &identifier, 1));

  CHECK(MIS2DH_VALUE_IDENTIFIER == identifier, BS_ERROR);

  return BS_OK;
}

base_status_t mis2dh_set_resolution(mis2dh_t *me, mis2dh_resolution_t resolution)
{
  uint8_t tmp;

  me->config.resolution     = (resolution % 3) * 2;
  me->config.resolution_max = (1 << me->config.resolution + 7);

  switch (resolution)
  {
    case MIS2DH_RES_VALUE_8_BIT:
      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
      tmp |= (1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      tmp &= ~(1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      break;

    case MIS2DH_RES_VALUE_10_BIT:
      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
      tmp &= ~(1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      tmp &= ~(1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      break;

    case MIS2DH_RES_VALUE_12_BIT:
      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
      tmp |= ~(1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

      CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      tmp |= (1 << 3);
      CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
      break;

    default:
      break;
  }

  return BS_OK;
}

base_status_t mis2dh_set_scale(mis2dh_t *me, mis2dh_scale_t scale)
{
  uint8_t tmp;

  me->config.scale     = scale % 4;
  me->config.scale_max = 2;
  me->config.scale_max = me->config.scale_max << me->config.scale;

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));
  tmp &= 0xCF;
  tmp |= (scale << 4);
  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG4, &tmp, 1));

  return BS_OK;
}

base_status_t mis2dh_set_refresh_rate(mis2dh_t *me, mis2dh_refresh_rate_t rf_rate)
{
  uint8_t tmp;

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
  tmp &= 0x0F;
  tmp |= (rf_rate << 4);
  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

  return BS_OK;
}

base_status_t mis2dh_get_raw_axis(mis2dh_t *me, mis2dh_data_t *raw_axis)
{
  uint8_t status, sub;
  uint8_t data[6];

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_STATUS_REG, &status, 1));

  status &= 0x04;
  if (status)
  {
    // In order to read multiple bytes, it is necessary to assert the most significant bit of the sub-address field.
    // In other words, SUB(7) must be equal to 1 while SUB(6-0) represents the address of the first register to be read.
    sub = MIS2DH_REG_OUT_X_L | 0x80;
    CHECK_STATUS(m_mis2dh_read_reg(me, sub, data, sizeof(data)));

    raw_axis->x = ((data[1] << 8) | data[0]) >> (8 - me->config.resolution);
    raw_axis->y = ((data[3] << 8) | data[2]) >> (8 - me->config.resolution);
    raw_axis->z = ((data[5] << 8) | data[4]) >> (8 - me->config.resolution);
  }
  else
  {
    return BS_ERROR;
  }

  return BS_OK;
}

base_status_t mis2dh_get_g_axis(mis2dh_t *me, mis2dh_data_t *g_axis)
{
  mis2dh_data_t raw_axis;

  CHECK_STATUS(mis2dh_get_raw_axis(me, &raw_axis));

  g_axis->x = m_mis2dh_modifed_map((double)raw_axis.x, -1 * me->config.resolution_max,
               me->config.resolution_max - 1, -1 * me->config.scale_max, me->config.scale_max);

  g_axis->x = m_mis2dh_modifed_map((double)raw_axis.y, -1 * me->config.resolution_max,
               me->config.resolution_max - 1, -1 * me->config.scale_max, me->config.scale_max);

  g_axis->x = m_mis2dh_modifed_map((double)raw_axis.z, -1 * me->config.resolution_max,
               me->config.resolution_max - 1, -1 * me->config.scale_max, me->config.scale_max);

  return BS_OK;
}

base_status_t mis2dh_get_ms2_axis(mis2dh_t *me, mis2dh_data_ms2_t *ms2_axis)
{
  mis2dh_data_t g_axis;

  CHECK_STATUS(mis2dh_get_g_axis(me, &g_axis));

  ms2_axis->x = g_axis.x * 9.806;
  ms2_axis->y = g_axis.y * 9.806;
  ms2_axis->z = g_axis.z * 9.806;

  return BS_OK;
}

base_status_t mis2dh_enable_axis(mis2dh_t *me, mis2dh_axis_enable_t axis)
{
  uint8_t tmp;

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
  tmp |= axis;
  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

  return BS_OK;
}

base_status_t mis2dh_disable_axis(mis2dh_t *me, mis2dh_axis_enable_t axis)
{
  uint8_t tmp;

  CHECK_STATUS(m_mis2dh_read_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));
  tmp &= ~(axis);
  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG1, &tmp, 1));

  return BS_OK;
}

base_status_t mis2dh_reboot_memory(mis2dh_t *me)
{
  uint8_t tmp = 0x80;

  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG5, &tmp, 1));

  return BS_OK;
}

base_status_t mis2dh_enter_normal_mode(mis2dh_t *me)
{
  uint8_t tmp = 0x00;

  CHECK_STATUS(m_mis2dh_write_reg(me, MIS2DH_REG_CTRL_REG5, &tmp, 1));

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

static double m_mis2dh_modifed_map(double x, double in_min, double in_max,
                                   double out_min, double out_max)

{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* End of file -------------------------------------------------------- */
