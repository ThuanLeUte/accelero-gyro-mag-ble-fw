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
MPU_ConfigTypeDef myMpuConfig;



/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
base_status_t bsp_imu_init(void)
{
  m_mpu9250.device_address = MPU9250_I2C_ADDR;
  m_mpu9250.i2c_read       = bsp_i2c_read;
  m_mpu9250.i2c_write      = bsp_i2c_write;

  mpu9250_init(&m_mpu9250);

	myMpuConfig.Accel_Full_Scale = AFS_SEL_4g;
	myMpuConfig.ClockSource      = Internal_8MHz;
	myMpuConfig.CONFIG_DLPF      = DLPF_184A_188G_Hz;
	myMpuConfig.Gyro_Full_Scale  = FS_SEL_500;
	myMpuConfig.Sleep_Mode_Bit   = 0;  //1: sleep mode, 0: normal mode
	return MPU9250_Config(&myMpuConfig);
}

base_status_t bsp_gyro_accel_get(ScaledData_Def myAccelScaled, ScaledData_Def myGyroScaled)
{
  MPU9250_Get_Accel_Scale(&myAccelScaled);
	MPU9250_Get_Gyro_Scale(&myGyroScaled);
}


/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
