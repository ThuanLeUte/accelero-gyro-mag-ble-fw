/**
 * @file       mpu9250.c
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support MPU9250 (IMU)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "mpu9250.h"

/* Private defines ---------------------------------------------------- */
//Define Registers
#define MPU9250_REG_WHO_AM_I                  (0x75)
#define MPU9250_REG_PWR_MAGT_1		            (0x6B)
#define MPU9250_REG_CONFIG			              (0x1A)
#define MPU9250_REG_GYRO_CONFIG		            (0x1B)
#define MPU9250_REG_ACCEL_CONFIG	            (0x1C)
#define MPU9250_REG_SMPLRT_DIV		            (0x19)
#define MPU9250_REG_INT_STATUS		            (0x3A)
#define MPU9250_REG_ACCEL_XOUT_H	            (0x3B)
#define MPU9250_REG_TEMP_OUT_H		            (0x41)
#define MPU9250_REG_GYRO_XOUT_H		            (0x43)
#define MPU9250_REG_FIFO_EN 		              (0x23)
#define MPU9250_REG_INT_ENABLE 		            (0x38)
#define MPU9250_REG_I2CMACO 	  	            (0x23)
#define MPU9250_REG_USER_CNT                  (0x6A)
#define MPU9250_REG_FIFO_COUNTH               (0x72)
#define MPU9250_REG_FIFO_R_W                  (0x74)

#define MPU9250_PART_IDENTIFIER               (0X68)

/* Private enumerate/structure ---------------------------------------- */
//1- MPU Configuration 
typedef struct
{
	uint8_t ClockSource;
	uint8_t Gyro_Full_Scale;
	uint8_t Accel_Full_Scale;
	uint8_t CONFIG_DLPF;
	bool 	Sleep_Mode_Bit; 
	
}MPU_ConfigTypeDef;

//2- Clock Source ENUM
enum PM_CLKSEL_ENUM
{
	Internal_8MHz 	= 0x00,
	X_Axis_Ref		  = 0x01,
	Y_Axis_Ref		  = 0x02,
	Z_Axis_Ref		  = 0x03,
	Ext_32_768KHz	  = 0x04,
	Ext_19_2MHz		  = 0x05,
	TIM_GENT_INREST	= 0x07
};

//3- Gyro Full Scale Range ENUM (deg/sec)
enum gyro_FullScale_ENUM
{
	FS_SEL_250 	= 0x00,
	FS_SEL_500 	= 0x01,
	FS_SEL_1000 = 0x02,
	FS_SEL_2000	= 0x03
};

//4- Accelerometer Full Scale Range ENUM (1g = 9.81m/s2)
enum accel_FullScale_ENUM
{
	AFS_SEL_2g	= 0x00,
	AFS_SEL_4g,
	AFS_SEL_8g,
	AFS_SEL_16g
};

//5- Digital Low Pass Filter ENUM
enum DLPF_CFG_ENUM
{
	DLPF_260A_256G_Hz = 0x00,
	DLPF_184A_188G_Hz = 0x01,
	DLPF_94A_98G_Hz 	= 0x02,
	DLPF_44A_42G_Hz 	= 0x03,
	DLPF_21A_20G_Hz 	= 0x04,
	DLPF_10_Hz 			  = 0x05,
	DLPF_5_Hz 		  	= 0x06
};

//6- e external Frame Synchronization ENUM
enum EXT_SYNC_SET_ENUM
{
	input_Disable = 0x00,
	TEMP_OUT_L		= 0x01,
	GYRO_XOUT_L		= 0x02,
	GYRO_YOUT_L		= 0x03,
	GYRO_ZOUT_L		= 0x04,
	ACCEL_XOUT_L	= 0x05,
	ACCEL_YOUT_L	= 0x06,
	ACCEL_ZOUT_L	= 0x07
};

//7. Raw data typedef
typedef struct
{
	int16_t x;
	int16_t y;
	int16_t z;
}RawData_Def;

//8. Scaled data typedef
typedef struct
{
	float x;
	float y;
	float z;
}ScaledData_Def;




/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
//2- Accel & Gyro Scaling Factor
static float accelScalingFactor, gyroScalingFactor;

//3- Bias varaibles
static float A_X_Bias = 0.0f;
static float A_Y_Bias = 0.0f;
static float A_Z_Bias = 0.0f;

static int16_t GyroRW[3];

/* Private function prototypes ---------------------------------------- */
static base_status_t m_mpu9250_read_reg(mpu9250_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);
static base_status_t m_mpu9250_write_reg(mpu9250_t *me, uint8_t reg, uint8_t *p_data, uint32_t len);

/* Function definitions ----------------------------------------------- */
base_status_t mpu9250_init(mpu9250_t *me)
{
  uint8_t identifier = 0x00;

  if ((me == NULL) || (me->i2c_read == NULL) || (me->i2c_write == NULL))
    return BS_ERROR;
  CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_WHO_AM_I, &identifier, 1));

  if (MPU9250_PART_IDENTIFIER != identifier)
  {
    return BS_ERROR;
  }
  return BS_OK;
}

/* Private function definitions ---------------------------------------- */
base_status_t mpu9250_config(mpu9250_t *me, MPU_ConfigTypeDef *config)
{
  uint8_t Buffer = 0;
  
	//Clock Source
	//Reset Device
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_PWR_MAGT_1, &Buffer, 0x80));

	HAL_Delay(100);
	Buffer = config->ClockSource & 0x07;			//change the 7th bits of register
	Buffer |= (config->Sleep_Mode_Bit << 6) & 0x40; // change only the 7th bit in the register
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_PWR_MAGT_1, &Buffer, 1));

  //delay 10ms 

	//Set the Digital Low Pass Filter
	Buffer = 0;
	Buffer = config->CONFIG_DLPF & 0x07;
 	 CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_CONFIG, &Buffer, 1));

	//Select the Gyroscope Full Scale Range
	Buffer = 0;
	Buffer = (config->Gyro_Full_Scale << 3) & 0x18;
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_GYRO_CONFIG, &Buffer, 1));

	//Select the Accelerometer Full Scale Range
	Buffer = 0;
	Buffer = (config->Accel_Full_Scale << 3) & 0x18;
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_ACCEL_CONFIG, &Buffer, 1));

	//Set SRD To Default
	MPU9250_Set_SMPRT_DIV(0x04);

	//Accelerometer Scaling Factor, Set the Accelerometer and Gyroscope Scaling Factor
	switch (config->Accel_Full_Scale)
	{
	case AFS_SEL_2g:
		accelScalingFactor = (2000.0f / 32768.0f);
		break;

	case AFS_SEL_4g:
		accelScalingFactor = (4000.0f / 32768.0f);
		break;

	case AFS_SEL_8g:
		accelScalingFactor = (8000.0f / 32768.0f);
		break;

	case AFS_SEL_16g:
		accelScalingFactor = (16000.0f / 32768.0f);
		break;

	default:
		break;
	}
	//Gyroscope Scaling Factor
	switch (config->Gyro_Full_Scale)
	{
	case FS_SEL_250:
		gyroScalingFactor = 250.0f / 32768.0f;
		break;

	case FS_SEL_500:
		gyroScalingFactor = 500.0f / 32768.0f;
		break;

	case FS_SEL_1000:
		gyroScalingFactor = 1000.0f / 32768.0f;
		break;

	case FS_SEL_2000:
		gyroScalingFactor = 2000.0f / 32768.0f;
		break;

	default:
		break;
	}
   return BS_OK;
}

//Get Sample Rate Divider
base_status_t MPU9250_Get_SMPRT_DIV(mpu9250_t *me,  uint8_t Buffer)
{
	CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_SMPLRT_DIV, &Buffer, 1));

	return BS_OK;
}

//Set Sample Rate Divider
base_status_t MPU9250_Set_SMPRT_DIV(mpu9250_t *me, uint8_t SMPRTvalue)
{
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_SMPLRT_DIV, &SMPRTvalue, 1));

	return BS_OK;
}


base_status_t MPU9250_Get_FSYNC(mpu9250_t *me, uint8_t Buffer)
{
	uint8_t Buffer = 0;

  CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_CONFIG, &Buffer, 1));

	Buffer &= 0x38;
  Buffer >>= 3;

	return BS_OK;
}

base_status_t MPU9250_Set_FSYNC(mpu9250_t *me, enum EXT_SYNC_SET_ENUM ext_Sync)
{
	uint8_t Buffer = 0;

  CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_CONFIG, &Buffer, 1));

	Buffer &= ~0x38;
	Buffer |= (ext_Sync << 3);
	
  CHECK_STATUS(m_mpu9250_write_reg(me, MPU9250_REG_CONFIG, &Buffer, 1));

  return BS_OK;
}

// Get Accel Raw Data
base_status_t MPU9250_Get_Accel_RawData(mpu9250_t *me, RawData_Def *rawDef)
{
	uint8_t i2cBuf[2];
	uint8_t AcceArr[6], GyroArr[6];

  CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_INT_STATUS, &i2cBuf[1], 1));
	if ((i2cBuf[1] && 0x01))
	{
    CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_ACCEL_XOUT_H, AcceArr, 6));
		//Accel Raw Data
		rawDef->x = ((AcceArr[0] << 8) + AcceArr[1]); // x-Axis
		rawDef->y = ((AcceArr[2] << 8) + AcceArr[3]); // y-Axis
		rawDef->z = ((AcceArr[4] << 8) + AcceArr[5]); // z-Axis

    CHECK_STATUS(m_mpu9250_read_reg(me, MPU9250_REG_GYRO_XOUT_H, AcceArr, 6));
		//Gyro Raw Data
		GyroRW[0] = ((GyroArr[0] << 8) + GyroArr[1]);
		GyroRW[1] = ((GyroArr[2] << 8) + GyroArr[3]);
		GyroRW[2] = ((GyroArr[4] << 8) + GyroArr[5]);
	}
  return BS_OK;
}

// Get Accel scaled data (g unit of gravity, 1g = 9.81m/s2)
base_status_t MPU9250_Get_Accel_Scale(mpu9250_t *me, ScaledData_Def *scaledDef)
{
	RawData_Def AccelRData;
	MPU9250_Get_Accel_RawData(me,&AccelRData);

	//Accel Scale data
	scaledDef->x = ((AccelRData.x + 0.0f) * accelScalingFactor);
	scaledDef->y = ((AccelRData.y + 0.0f) * accelScalingFactor);
	scaledDef->z = ((AccelRData.z + 0.0f) * accelScalingFactor);

  return BS_OK;
}

//11- Get Accel calibrated data
base_status_t MPU9250_Get_Accel_Cali(mpu9250_t *me,ScaledData_Def *CaliDef)
{
	ScaledData_Def AccelScaled;
	MPU9250_Get_Accel_Scale(me,&AccelScaled);

	//Accel Scale data
	CaliDef->x = (AccelScaled.x) - A_X_Bias; // x-Axis
	CaliDef->y = (AccelScaled.y) - A_Y_Bias; // y-Axis
	CaliDef->z = (AccelScaled.z) - A_Z_Bias; // z-Axis

  return BS_OK;
}
//12- Get Gyro Raw Data
base_status_t MPU9250_Get_Gyro_RawData(mpu9250_t *me, RawData_Def *rawDef)
{
	//Accel Raw Data
	rawDef->x = GyroRW[0];
	rawDef->y = GyroRW[1];
	rawDef->z = GyroRW[2];

  return BS_OK;
}

//13- Get Gyro scaled data
base_status_t MPU9250_Get_Gyro_Scale(mpu9250_t *me, ScaledData_Def *scaledDef)
{
	RawData_Def myGyroRaw;
	MPU9250_Get_Gyro_RawData(me,&myGyroRaw);

	//Gyro Scale data
	scaledDef->x = (myGyroRaw.x) * gyroScalingFactor; // x-Axis
	scaledDef->y = (myGyroRaw.y) * gyroScalingFactor; // y-Axis
	scaledDef->z = (myGyroRaw.z) * gyroScalingFactor; // z-Axis

  return BS_OK;
}

//14- Accel Calibration
base_status_t MPU9250_Accel_Cali(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max)
{
	//1* X-Axis calibrate
	A_X_Bias = (x_max + x_min) / 2.0f;

	//2* Y-Axis calibrate
	A_Y_Bias = (y_max + y_min) / 2.0f;

	//3* Z-Axis calibrate
	A_Z_Bias = (z_max + z_min) / 2.0f;
}

/**
 * @brief         MPU9250 read register
 *
 * @param[in]     me      Pointer to handle of MPU9250 module.
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
static base_status_t m_mpu9250_read_reg(mpu9250_t *me, uint8_t reg, uint8_t *p_data, uint32_t len)
{
  CHECK(0 == me->i2c_read(me->device_address, reg, p_data, len), BS_ERROR);

  return BS_OK;
}

/**
 * @brief         MPU9250 read register
 *
 * @param[in]     me      Pointer to handle of MPU9250 module.
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
static base_status_t m_mpu9250_write_reg(mpu9250_t *me, uint8_t reg, uint8_t *p_data, uint32_t len)
{
  CHECK(0 == me->i2c_write(me->device_address, reg, p_data, len), BS_ERROR);

  return BS_OK;
}


/* End of file -------------------------------------------------------- */
