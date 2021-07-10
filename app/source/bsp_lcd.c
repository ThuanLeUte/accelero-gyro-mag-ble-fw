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

#include "font.h"
#include "big_number.h"
#include "small_number.h"
#include "miscellaneous.h"
#include "background.h"

/* Private defines ---------------------------------------------------- */
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define pgm_read_word(addr) (*(const uint16_t *)(addr))

#define LCD_WIDTH            (240)
#define LCD_HEIGHT           (240)

#define LCD_WHITE            (0xFFFF)
#define LCD_BLACK            (0x0000)
#define LCD_BLUE             (0x001F)
#define LCD_BRED             (0XF81F)
#define LCD_GRED             (0XFFE0)
#define LCD_GBLUE            (0X07FF)
#define LCD_RED              (0xF800)
#define LCD_MAGENTA          (0xF81F)
#define LCD_GREEN            (0x07E0)
#define LCD_CYAN             (0x7FFF)
#define LCD_YELLOW           (0xFFE0)
#define LCD_BROWN            (0XBC40)
#define LCD_BRRED            (0XFC07)
#define LCD_GRAY             (0X8430)
#define LCD_DARKBLUE         (0X01CF)
#define LCD_LIGHTBLUE        (0X7D7C)
#define LCD_GRAYBLUE         (0X5458)
#define LCD_LIGHTGREEN       (0X841F)
#define LCD_LGRAY            (0XC618)
#define LCD_LGRAYBLUE        (0XA651)
#define LCD_LBBLUE           (0X2B12)

/* Private enumerate/structure ---------------------------------------- */
typedef struct
{
  uint8_t x_pixcel;
  uint8_t y_pixcel;
}
bsp_px_t;

/* Private macros ----------------------------------------------------- */
#define PX_INFO(item, x_px, y_px) { .x_pixcel = x_px, .x_pixcel = y_px }

#define BIG_NUM(x) (big_number_##x)

/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static gc9a01_t m_gc9a01;

static bsp_px_t BIG_NUM_TABLE[10] = 
{
  //        +=========+==========+==========+
  //        |NUMBER   | X-Pixcel | Y-Pixcel |
  //        +---------+----------+----------+
     PX_INFO( 0        ,  20     ,        40)
    ,PX_INFO( 1        ,  20     ,        41)
    ,PX_INFO( 2        ,  20     ,        42)
    ,PX_INFO( 3        ,  20     ,        43)
    ,PX_INFO( 4        ,  20     ,        44)
    ,PX_INFO( 5        ,  20     ,        45)
    ,PX_INFO( 6        ,  20     ,        46)
    ,PX_INFO( 7        ,  20     ,        47)
    ,PX_INFO( 8        ,  20     ,        48)
    ,PX_INFO( 9        ,  20     ,        49)
  //        +==========+=========+==========+
};

static bsp_px_t SMALL_NUM_TABLE[10] = 
{
  //        +=========+==========+==========+
  //        |NUMBER   | X-Pixcel | Y-Pixcel |
  //        +---------+----------+----------+
     PX_INFO( 0        ,  20     ,        40)
    ,PX_INFO( 1        ,  20     ,        40)
    ,PX_INFO( 2        ,  20     ,        40)
    ,PX_INFO( 3        ,  20     ,        40)
    ,PX_INFO( 4        ,  20     ,        40)
    ,PX_INFO( 5        ,  20     ,        40)
    ,PX_INFO( 6        ,  20     ,        40)
    ,PX_INFO( 7        ,  20     ,        40)
    ,PX_INFO( 8        ,  20     ,        40)
    ,PX_INFO( 9        ,  20     ,        40)
  //        +==========+=========+==========+
};

static bsp_px_t ITEMS_TABLE[LCD_ITEM_CNT] = 
{
  //        +=====================+==========+==========+
  //        |ITEMS                | X-Pixcel | Y-Pixcel |
  //        +---------------------+----------+----------+
     PX_INFO( LCD_BATTERY         ,  20      ,        40)
    ,PX_INFO( LCD_SP02_NUM        ,  20      ,        40)
    ,PX_INFO( LCD_HEART_RATE_NUM  ,  20      ,        40)
  //        +=====================+==========+==========+
};

/* Private function prototypes ---------------------------------------- */
static void bsp_lcd_write_pixel(uint16_t x, uint16_t y, uint16_t thin, uint16_t color);
static void bsp_lcd_address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/* Function definitions ----------------------------------------------- */
void bsp_lcd_init(void)
{
  m_gc9a01.delay_ms   = bsp_delay_ms;
  m_gc9a01.gpio_write = bsp_gpio_write;
  m_gc9a01.spi_send   = bsp_spi_write;

  gc9a01_init(&m_gc9a01);

  bsp_lcd_fill(LCD_WHITE);

  // bsp_lcd_draw_image(50, 50, 50 + 50, 50 + 77, image_data_9);
  // bsp_lcd_draw_image(100, 50, 100 + 54, 50 + 77, image_data_8);

  // bsp_lcd_draw_image(50, 100, 50 + 27, 100 + 40, image_data_7_small);
  // bsp_lcd_draw_image(100, 100, 100 + 27, 100 + 40, image_data_0_small);

}

void bsp_lcd_draw_spo2_number(uint8_t num)
{
  ASSERT(num <= 100);

  uint8_t units, dozens, hundreds;
  uint16_t x_current_position, y_current_position, x_pixcel, y_pixcel;

  hundreds = num / 100;
  dozens   = num / 10;
  units    = num % 10;

  x_current_position = ITEMS_TABLE[LCD_SP02_NUM].x_pixcel;
  y_current_position = ITEMS_TABLE[LCD_SP02_NUM].y_pixcel;

  x_pixcel = x_current_position + BIG_NUM_TABLE[hundreds].x_pixcel;
  y_pixcel = y_current_position + BIG_NUM_TABLE[hundreds].y_pixcel;

  bsp_lcd_draw_image(x_current_position, y_current_position,
                     x_pixcel, y_pixcel, BIG_NUM(8));

  x_current_position = x_pixcel;
  y_current_position = y_pixcel;

  x_pixcel = x_current_position + BIG_NUM_TABLE[dozens].x_pixcel;
  y_pixcel = y_current_position + BIG_NUM_TABLE[dozens].y_pixcel;

  bsp_lcd_draw_image(x_current_position, y_current_position,
                     x_pixcel, y_pixcel, BIG_NUM(8));

  x_current_position = x_pixcel;
  y_current_position = y_pixcel;

  x_pixcel = x_current_position + BIG_NUM_TABLE[units].x_pixcel;
  y_pixcel = y_current_position + BIG_NUM_TABLE[units].y_pixcel;

  bsp_lcd_draw_image(x_current_position, y_current_position,
                     x_pixcel, y_pixcel, BIG_NUM(8));
}

void bsp_lcd_fill(uint16_t color)
{
  bsp_lcd_address_set(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
  gc9a01_write_cmd(&m_gc9a01, GC9A01_MEMORY_WRITE);

  for (uint16_t i = 0; i < LCD_HEIGHT; i++)
  {
    for (uint16_t j = 0; j < LCD_WIDTH; j++)
    {
      gc9a01_write_data(&m_gc9a01, (uint8_t *)&color, 2);
    }
  }
}

void bsp_lcd_write_char(uint16_t x, uint16_t y, unsigned c,
                        uint16_t color, uint16_t bg, uint8_t size)
{
  if ((x >= LCD_WIDTH)          || // Clip right
      (y >= LCD_HEIGHT)         || // Clip bottom
      ((x + 6 * size - 1) < 0)  || // Clip left
      ((y + 8 * size - 1) < 0))    // Clip top
    return;

  for (int8_t i = 0; i < 6; i++)
  {
    uint8_t line;

    if (i == 5)
      line = 0x00;
    else
      line = pgm_read_byte(font_5x7 + (c * 5) + i);

    for (int8_t j = 0; j < 8; j++)
    {
      if (line & 0x1)
        bsp_lcd_write_pixel(x + i * size, y + j * size, size, color);
      else if (bg != color)
        bsp_lcd_write_pixel(x + i * size, y + j * size, size, bg);

      line >>= 1;
    }
  }
}

void bsp_lcd_write_string(uint16_t x, uint16_t y, const char c[],
                          uint16_t color, uint16_t bgcolor, uint8_t size)
{
  int i = 0;

  while (c[i] != '\0')
  {
    if (c[i] == '\n')
    {
      y += size * 8;
      x = 0;
    }
    else
    {
      bsp_lcd_write_char(x, y, c[i], color, bgcolor, size);

      x += 6 * size;
      i++;

      if (x > (LCD_WIDTH - size * 6))
      {
        y += size * 8;
        x = 0;
      }
    }
  }
}

void bsp_lcd_draw_circle(uint16_t x0, uint16_t y0, uint16_t r,
                        uint16_t thin, uint16_t color)
{
  bsp_lcd_write_pixel(x0, y0 - r, thin, color);
  bsp_lcd_write_pixel(x0, y0 + r, thin, color);
  bsp_lcd_write_pixel(x0 - r, y0, thin, color);
  bsp_lcd_write_pixel(x0 + r, y0, thin, color);
  bsp_lcd_draw_circle_helper(x0, y0, r, 15, color);
}

void bsp_lcd_draw_circle_helper(uint16_t x0, uint16_t y0, uint16_t r,
                                uint8_t cornername, uint16_t color)
{
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x     = 0;
  int16_t y     = r;

  while (x < y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    if (cornername & 0x4)
    {
      bsp_lcd_write_pixel(x0 + x, y0 + y, 1, color);
      bsp_lcd_write_pixel(x0 + y, y0 + x, 1, color);
    }
    if (cornername & 0x2)
    {
      bsp_lcd_write_pixel(x0 + x, y0 - y, 1, color);
      bsp_lcd_write_pixel(x0 + y, y0 - x, 1, color);
    }
    if (cornername & 0x8)
    {
      bsp_lcd_write_pixel(x0 - y, y0 + x, 1, color);
      bsp_lcd_write_pixel(x0 - x, y0 + y, 1, color);
    }
    if (cornername & 0x1)
    {
      bsp_lcd_write_pixel(x0 - y, y0 - x, 1, color);
      bsp_lcd_write_pixel(x0 - x, y0 - y, 1, color);
    }
  }
}

void bsp_lcd_draw_image(uint16_t x0, uint16_t y0, uint16_t x1,
                        uint16_t y1, const short unsigned A[])
{
  int k = 0;
  uint16_t data;

  bsp_lcd_address_set(x0, y0, x1 - 1, y1 - 1);
  gc9a01_write_cmd(&m_gc9a01, GC9A01_MEMORY_WRITE);

  for (uint16_t i = x0; i < x1; i++)
  {
    for (uint16_t j = y0; j < y1; j++)
    {
      data = (uint16_t)pgm_read_word(A + k);

      gc9a01_write_data_byte(&m_gc9a01, data >> 8);
      gc9a01_write_data_byte(&m_gc9a01, data);
      k++;
    }
  }
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief         LCD write pixel
 *
 * @param[in]     x       X position
 * @param[in]     y       Y position
 * @param[in]     thin    Thin
 * @param[in]     color   Color
 *
 * @attention     None
 *
 * @return        None
 */
static void bsp_lcd_write_pixel(uint16_t x, uint16_t y, uint16_t thin, uint16_t color)
{
  if ((x >= LCD_WIDTH) || (y >= LCD_HEIGHT))
    return;

  bsp_lcd_address_set(x, y, x + thin - 1, y + thin - 1);

  gc9a01_write_cmd(&m_gc9a01, GC9A01_MEMORY_WRITE);

  for (int i = 0; i < (thin * thin); i++)
  {
    gc9a01_write_data(&m_gc9a01, (uint8_t *)&color, 2);
  }
}

/**
 * @brief         LCD write pixel
 *
 * @param[in]     x1       X start
 * @param[in]     y1       Y start
 * @param[in]     x2       X end
 * @param[in]     y2       Y end
 *
 * @attention     None
 *
 * @return        None
 */
static void bsp_lcd_address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
  gc9a01_write_cmd(&m_gc9a01, GC9A01_COLUMN_ADDR_SET);
  gc9a01_write_data_byte(&m_gc9a01, x1 >> 8);
  gc9a01_write_data_byte(&m_gc9a01, x1);        // XSTART
  gc9a01_write_data_byte(&m_gc9a01, x2 >> 8);
  gc9a01_write_data_byte(&m_gc9a01, x2);        // XEND

  gc9a01_write_cmd(&m_gc9a01, GC9A01_ROW_ADDR_SET);
  gc9a01_write_data_byte(&m_gc9a01, y1 >> 8);
  gc9a01_write_data_byte(&m_gc9a01, y1);        // YSTART
  gc9a01_write_data_byte(&m_gc9a01, y2 >> 8);
  gc9a01_write_data_byte(&m_gc9a01, y2);        // YEND
}

/* End of file -------------------------------------------------------- */
