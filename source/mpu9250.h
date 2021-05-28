/**
 * @file       mpu9250.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support MPU9250 (IMU)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __MPU9250_H
#define __MPU9250_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
#define MPU9250_I2C_ADDR                  (0x90 >> 1)

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief MPU9250 sensor struct
 */
typedef struct 
{
  uint8_t  device_address;  // I2C device address

  // Read n-bytes from device's internal address <reg_addr> via I2C bus
  base_status_t (*i2c_read) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);

  // Write n-bytes from device's internal address <reg_addr> via I2C bus
  base_status_t (*i2c_write) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);
}
mpu9250_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Initialize MPU9250
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t mpu9250_init(mpu9250_t *me);

/**
 * @brief         MPU9250 Initialaztion Configuration
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     config        Pointer to config
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t mpu9250_config(mpu9250_t *me, MPU_ConfigTypeDef *config);

/**
 * @brief         MPU9250 Get Sample Rate Divider
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     Buffer        Variable config
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_SMPRT_DIV(mpu9250_t *me,  uint8_t Buffer);

/**
 * @brief         MPU9250 Set Sample Rate Divider
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     SMPRTvalue    Variable SMPRTvalue
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Set_SMPRT_DIV(mpu9250_t *me, uint8_t SMPRTvalue);

/**
 * @brief         MPU9250 Get External Frame Sync
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     Buffer        Variable Buffer
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_FSYNC(mpu9250_t *me, uint8_t Buffer);

/**
 * @brief         MPU9250 Set External Frame Sync
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     ext_Sync      enum to ext_Sync
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Set_FSYNC(mpu9250_t *me, enum EXT_SYNC_SET_ENUM ext_Sync);

/**
 * @brief         MPU9250 Get Accel Raw Data
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     rawDef        Pointer to ext_Sync
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_Accel_RawData(mpu9250_t *me, RawData_Def *rawDef);

/**
 * @brief         MPU9250 Get Accel scaled data (g unit of gravity, 1g = 9.81m/s2)
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     scaledDef     Pointer to scaledDef
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_Accel_Scale(mpu9250_t *me, ScaledData_Def *scaledDef);

/**
 * @brief         MPU9250 Get Accel calibrated data
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     CaliDef       Pointer to CaliDef
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_Accel_Cali(mpu9250_t *me,ScaledData_Def *CaliDef);

/**
 * @brief         MPU9250 Get Gyro Raw Data
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     rawDef        Pointer to rawDef
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_Gyro_RawData(mpu9250_t *me, RawData_Def *rawDef);

/**
 * @brief         MPU9250 Get Gyro scaled data
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     scaledDef     Pointer to scaledDef
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Get_Gyro_Scale(mpu9250_t *me, ScaledData_Def *scaledDef);

/**
 * @brief         MPU9250 Get Gyro scaled data
 *
 * @param[in]     me            Pointer to handle of MPU9250 module.
 * @param[in]     x_min         Variable x_min
 * @param[in]     x_max         Variable x_max
 * @param[in]     y_min         Variable y_min
 * @param[in]     y_max         Variable y_max
 * @param[in]     z_min         Variable z_min
 * @param[in]     z_max         Variable z_max
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t MPU9250_Accel_Cali(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __MPU9250_H

/* End of file -------------------------------------------------------- */
