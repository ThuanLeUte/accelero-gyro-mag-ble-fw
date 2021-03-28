/**
 * @file       gc9a01_defs.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-03-22
 * @author     Thuan Le
 * @brief      Driver support GC9A01 (LCD driver)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __GC9A01_DEFS_H
#define __GC9A01_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
#define GC9A01_I2C_ADDR                  (0x90 >> 1)
#define GC9A01_DISFNCTRL                 (0xB6)
#define GC9A01_COLMOD                    (0x3A)
#define GC9A01_MADCTL                    (0x36)
#define GC9A01_DISPON                    (0x29)

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief GC9A01 init function struct
 */
typedef struct
{
  uint8_t cmd;
  uint8_t data;
}
gc9a01_function_t;

/**
 * @brief GC9A01 init commands struct
 */
enum GC9A01_CMD
{
  GC9A01_START,
  GC9A01_END,
  GC9A01_CMD,
  GC9A01_DATA,
  GC9A01_DELAY
};

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
const gc9a01_function_t GC9A01_CFG_SCRIPT[] =
{
    {GC9A01_START, GC9A01_START},
    {GC9A01_CMD, 0xEF},

    {GC9A01_CMD, 0xEB},
    {GC9A01_DATA, 0x14},

    {GC9A01_CMD, 0xFE},
    {GC9A01_CMD, 0xEF},

    {GC9A01_CMD, 0xEB},
    {GC9A01_DATA, 0x14},

    {GC9A01_CMD, 0x84},
    {GC9A01_DATA, 0x40},

    {GC9A01_CMD, 0x85},
    {GC9A01_DATA, 0xFF},

    {GC9A01_CMD, 0x86},
    {GC9A01_DATA, 0xFF},

    {GC9A01_CMD, 0x87},
    {GC9A01_DATA, 0xFF},

    {GC9A01_CMD, 0x88},
    {GC9A01_DATA, 0x0A},

    {GC9A01_CMD, 0x89},
    {GC9A01_DATA, 0x21},

    {GC9A01_CMD, 0x8A},
    {GC9A01_DATA, 0x00},

    {GC9A01_CMD, 0x8B},
    {GC9A01_DATA, 0x80},

    {GC9A01_CMD, 0x8C},
    {GC9A01_DATA, 0x01},

    {GC9A01_CMD, 0x8D},
    {GC9A01_DATA, 0x01},

    {GC9A01_CMD, 0x8E},
    {GC9A01_DATA, 0xFF},

    {GC9A01_CMD, 0x8F},
    {GC9A01_DATA, 0xFF},

    {GC9A01_CMD, GC9A01_DISFNCTRL},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},

    {GC9A01_CMD, GC9A01_MADCTL},
    {GC9A01_DATA, 0x48},

    {GC9A01_CMD, GC9A01_COLMOD},
    {GC9A01_DATA, 0x05},

    {GC9A01_CMD, 0x90},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x08},

    {GC9A01_CMD, 0xBD},
    {GC9A01_DATA, 0x06},

    {GC9A01_CMD, 0xBC},
    {GC9A01_DATA, 0x00},

    {GC9A01_CMD, 0xFF},
    {GC9A01_DATA, 0x60},
    {GC9A01_DATA, 0x01},
    {GC9A01_DATA, 0x04},

    {GC9A01_CMD, 0xC3},
    {GC9A01_DATA, 0x13},
    {GC9A01_CMD, 0xC4},
    {GC9A01_DATA, 0x13},

    {GC9A01_CMD, 0xC9},
    {GC9A01_DATA, 0x22},

    {GC9A01_CMD, 0xBE},
    {GC9A01_DATA, 0x11},

    {GC9A01_CMD, 0xE1},
    {GC9A01_DATA, 0x10},
    {GC9A01_DATA, 0x0E},

    {GC9A01_CMD, 0xDF},
    {GC9A01_DATA, 0x21},
    {GC9A01_DATA, 0x0C},
    {GC9A01_DATA, 0x02},

    {GC9A01_CMD, 0xF0},
    {GC9A01_DATA, 0x45},
    {GC9A01_DATA, 0x09},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x26},
    {GC9A01_DATA, 0x2A},

    {GC9A01_CMD, 0xF1},
    {GC9A01_DATA, 0x43},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x72},
    {GC9A01_DATA, 0x36},
    {GC9A01_DATA, 0x37},
    {GC9A01_DATA, 0x6F},

    {GC9A01_CMD, 0xF2},
    {GC9A01_DATA, 0x45},
    {GC9A01_DATA, 0x09},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x26},
    {GC9A01_DATA, 0x2A},

    {GC9A01_CMD, 0xF3},
    {GC9A01_DATA, 0x43},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x72},
    {GC9A01_DATA, 0x36},
    {GC9A01_DATA, 0x37},
    {GC9A01_DATA, 0x6F},

    {GC9A01_CMD, 0xED},
    {GC9A01_DATA, 0x1B},
    {GC9A01_DATA, 0x0B},

    {GC9A01_CMD, 0xAE},
    {GC9A01_DATA, 0x77},

    {GC9A01_CMD, 0xCD},
    {GC9A01_DATA, 0x63},

    {GC9A01_CMD, 0x70},
    {GC9A01_DATA, 0x07},
    {GC9A01_DATA, 0x07},
    {GC9A01_DATA, 0x04},
    {GC9A01_DATA, 0x0E},
    {GC9A01_DATA, 0x0F},
    {GC9A01_DATA, 0x09},
    {GC9A01_DATA, 0x07},
    {GC9A01_DATA, 0x08},
    {GC9A01_DATA, 0x03},

    {GC9A01_CMD, 0xE8},
    {GC9A01_DATA, 0x34},

    {GC9A01_CMD, 0x62},
    {GC9A01_DATA, 0x18},
    {GC9A01_DATA, 0x0D},
    {GC9A01_DATA, 0x71},
    {GC9A01_DATA, 0xED},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x18},
    {GC9A01_DATA, 0x0F},
    {GC9A01_DATA, 0x71},
    {GC9A01_DATA, 0xEF},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x70},

    {GC9A01_CMD, 0x63},
    {GC9A01_DATA, 0x18},
    {GC9A01_DATA, 0x11},
    {GC9A01_DATA, 0x71},
    {GC9A01_DATA, 0xF1},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x18},
    {GC9A01_DATA, 0x13},
    {GC9A01_DATA, 0x71},
    {GC9A01_DATA, 0xF3},
    {GC9A01_DATA, 0x70},
    {GC9A01_DATA, 0x70},

    {GC9A01_CMD, 0x64},
    {GC9A01_DATA, 0x28},
    {GC9A01_DATA, 0x29},
    {GC9A01_DATA, 0xF1},
    {GC9A01_DATA, 0x01},
    {GC9A01_DATA, 0xF1},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x07},

    {GC9A01_CMD, 0x66},
    {GC9A01_DATA, 0x3C},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0xCD},
    {GC9A01_DATA, 0x67},
    {GC9A01_DATA, 0x45},
    {GC9A01_DATA, 0x45},
    {GC9A01_DATA, 0x10},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},

    {GC9A01_CMD, 0x67},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x3C},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x01},
    {GC9A01_DATA, 0x54},
    {GC9A01_DATA, 0x10},
    {GC9A01_DATA, 0x32},
    {GC9A01_DATA, 0x98},

    {GC9A01_CMD, 0x74},
    {GC9A01_DATA, 0x10},
    {GC9A01_DATA, 0x85},
    {GC9A01_DATA, 0x80},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x00},
    {GC9A01_DATA, 0x4E},
    {GC9A01_DATA, 0x00},

    {GC9A01_CMD, 0x98},
    {GC9A01_DATA, 0x3E},
    {GC9A01_DATA, 0x07},

    {GC9A01_CMD, 0x35},
    {GC9A01_CMD, 0x21},

    {GC9A01_CMD, 0x11},
    {GC9A01_DELAY, 120},
    {GC9A01_CMD, GC9A01_DISPON},
    {GC9A01_DELAY, 255},
    {GC9A01_END, GC9A01_END},
};

/* Public function prototypes ----------------------------------------- */
/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __GC9A01_DEFS_H

/* End of file -------------------------------------------------------- */
