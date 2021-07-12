/**
 * @file       miscellaneous.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Miscellanenos picture bit map
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __MISCELLANEOUS_H
#define __MISCELLANEOUS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
const unsigned short batt_full[360] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0880, 0x2ac3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2283, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x08a0, 0x6668, 0x6f09, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x5e48, 0x6668, 0x7749, 0x5566, 0x0020, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2ae3, 0x6f08, 0x0060, 0x2283, 0x2ae3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ae3, 0x2222, 0x08c1, 0x77a9, 0x1161, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5de7, 0x2283, 0x87ea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x19c2, 0x6ee8, 0x19c2, 0x0060, 0x0000, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x2283, 0x6688, 0x3ba4, 0x7749, 0x2282, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x2263, 0x6688, 0x3bc4, 0x87ea, 0x66a7, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x2263, 0x6688, 0x3ba4, 0x7fea, 0x6708, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x2263, 0x6688, 0x3be5, 0x87eb, 0x44a5, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x2283, 0x66c8, 0x2aa3, 0x3324, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5e07, 0x19c2, 0x7fca, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f49, 0x1141, 0x6f29, 0x1982, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2aa3, 0x6ee8, 0x08a0, 0x08c1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x0880, 0x1121, 0x7769, 0x1141, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x4ce6, 0x6668, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x6ea8, 0x3bc4, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1181, 0x1141, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const unsigned short batt_75[360] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0880, 0x2ac3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2283, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x08a0, 0x6668, 0x6f09, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x5e48, 0x6668, 0x66a8, 0x66a8, 0x66a8, 0x7749, 0x5566, 0x0020, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2ae3, 0x6f08, 0x0060, 0x2283, 0x2ae3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ae3, 0x1a02, 0x0000, 0x0000, 0x0000, 0x08a0, 0x77a9, 0x1161, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5de7, 0x2283, 0x87ea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x87ea, 0x5de7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f49, 0x19c2, 0x0060, 0x0000, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7749, 0x2282, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3bc4, 0x87ea, 0x66a7, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7fea, 0x6708, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3be5, 0x87eb, 0x44a5, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f29, 0x2aa3, 0x3324, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5e07, 0x19c2, 0x7fca, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x5dc7, 0x0000, 0x0000, 0x0000, 0x0000, 0x7749, 0x1982, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2aa3, 0x6ee8, 0x08a0, 0x08c1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x0880, 0x0000, 0x0000, 0x0000, 0x1141, 0x7769, 0x1141, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x4ce6, 0x6668, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5566, 0x5587, 0x5587, 0x5587, 0x6ea8, 0x3bc4, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1181, 0x1141, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const unsigned short batt_50[360] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0880, 0x2ac3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2283, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x08a0, 0x6668, 0x6f09, 0x6648, 0x6648, 0x6648, 0x6648, 0x6648, 0x5e48, 0x6648, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x7749, 0x5566, 0x0020, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2ae3, 0x6f08, 0x0060, 0x2283, 0x2ae3, 0x2ac3, 0x2ac3, 0x2ac3, 0x2ae3, 0x2263, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x08a0, 0x77a9, 0x1161, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5de7, 0x2283, 0x87ea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f49, 0x19c2, 0x0060, 0x0000, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7749, 0x2282, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3bc4, 0x87ea, 0x66a7, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7fea, 0x6708, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3be5, 0x87eb, 0x44a5, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f29, 0x2aa3, 0x3324, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5e07, 0x19c2, 0x7fca, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x7fea, 0x6f08, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7749, 0x1982, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2aa3, 0x6ee8, 0x08a0, 0x08c1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08e1, 0x08c1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1141, 0x7769, 0x1141, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x4ce6, 0x6668, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5546, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x6ea8, 0x3bc4, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1181, 0x1141, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const unsigned short batt_25[360] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0880, 0x2ac3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2283, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x08a0, 0x6668, 0x6f09, 0x6648, 0x6648, 0x5e48, 0x6688, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x7749, 0x5566, 0x0020, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2ae3, 0x6f08, 0x0060, 0x2283, 0x2ae3, 0x2ae3, 0x08c1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x08a0, 0x77a9, 0x1161, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5de7, 0x2283, 0x87ea, 0x7fea, 0x7fea, 0x2b23, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f49, 0x19c2, 0x0060, 0x0000, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7749, 0x2282, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3bc4, 0x87ea, 0x66a7, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7fea, 0x6708, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3324, 0x7fea, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3be5, 0x87eb, 0x44a5, 0x0000, 
    0x0000, 0x3324, 0x5e07, 0x3344, 0x7fea, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f29, 0x2aa3, 0x3324, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x5e07, 0x19c2, 0x7fca, 0x7fea, 0x7fea, 0x2b03, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7749, 0x1982, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2aa3, 0x6ee8, 0x08a0, 0x08c1, 0x08e1, 0x08e1, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1141, 0x7769, 0x1141, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x4ce6, 0x6668, 0x5546, 0x5546, 0x5546, 0x5566, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x6ea8, 0x3bc4, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1181, 0x1141, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const unsigned short batt_0[360] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0880, 0x2ac3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2ae3, 0x2283, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x08a0, 0x6668, 0x6f09, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x66a8, 0x7749, 0x5566, 0x0020, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2ae3, 0x6f09, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x08a0, 0x77a9, 0x1161, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x6648, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f49, 0x19c2, 0x0060, 0x0000, 0x0000, 
    0x0000, 0x3324, 0x6668, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7749, 0x2282, 0x0000, 
    0x0000, 0x3324, 0x6668, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3bc4, 0x87ea, 0x66a7, 0x0000, 
    0x0000, 0x3324, 0x6668, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3ba4, 0x7fea, 0x6708, 0x0000, 
    0x0000, 0x3324, 0x6668, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6ee8, 0x3be5, 0x87eb, 0x44a5, 0x0000, 
    0x0000, 0x3324, 0x6668, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6f29, 0x2aa3, 0x3324, 0x0000, 0x0000, 
    0x0000, 0x3344, 0x6648, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7749, 0x1982, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x2aa3, 0x6ee8, 0x08c1, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1141, 0x7769, 0x1141, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x4ce6, 0x6668, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x5587, 0x6ea8, 0x3bc4, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1161, 0x1181, 0x1141, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

const unsigned short arrow[180] = {
    0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0xad75, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 
    0x0020, 0x0020, 0x0020, 0x0020, 0x0000, 0x10a2, 0xad75, 0xffff, 0xad75, 0x10a2, 0x0000, 0x0020, 0x0020, 0x0020, 0x0020, 
    0x0020, 0x0020, 0x0020, 0x0000, 0x0041, 0x8430, 0xffff, 0xffff, 0xffff, 0x8430, 0x0041, 0x0000, 0x0020, 0x0020, 0x0020, 
    0x0020, 0x0020, 0x0020, 0x0000, 0x5acb, 0xf7be, 0xffff, 0xffdf, 0xffff, 0xf7be, 0x5acb, 0x0000, 0x0020, 0x0020, 0x0020, 
    0x0020, 0x0020, 0x0000, 0x31c7, 0xdedb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xdedb, 0x31c7, 0x0000, 0x0020, 0x0020, 
    0x0020, 0x0000, 0x18c3, 0xbdd7, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xbdd7, 0x18c3, 0x0000, 0x0020, 
    0x0020, 0x0841, 0x8c71, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x8c71, 0x0841, 0x0020, 
    0x18c3, 0x5b0c, 0xffdf, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffdf, 0x634d, 0x18c3, 
    0x5b0c, 0xef5d, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xef7d, 0x5b0c, 
    0x8c71, 0xffff, 0xffdf, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffdf, 0xffff, 0x8c71, 
    0x8c71, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x8c71, 
    0x31c7, 0x8c71, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0xef7d, 0x8c71, 0x31c7
};

const unsigned short dot[81] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0020, 0x6b4d, 0xd6ba, 0xef5d, 0xbdd7, 0x31a6, 0x0000, 0x0000, 
    0x0000, 0x4208, 0xdefb, 0xffff, 0xffff, 0xf7be, 0xb596, 0x10a2, 0x0000, 
    0x0000, 0xb596, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x6b4d, 0x0000, 
    0x0000, 0xf79e, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xad75, 0x0000, 
    0x0000, 0xdefb, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x9cd3, 0x0000, 
    0x0000, 0x8410, 0xffdf, 0xffff, 0xffff, 0xffff, 0xef5d, 0x4228, 0x0000, 
    0x0000, 0x2124, 0xce79, 0xf7be, 0xf7be, 0xffdf, 0x9492, 0x0841, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

const unsigned short dot_n[81] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __MISCELLANEOUS_H

/* End of file -------------------------------------------------------- */