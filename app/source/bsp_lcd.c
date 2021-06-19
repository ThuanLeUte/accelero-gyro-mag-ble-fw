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

/* Private defines ---------------------------------------------------- */
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))

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

static const uint16_t COLOR_TABLE[] =
{
  LCD_WHITE,
  LCD_BLACK,
  LCD_BLUE,
  LCD_BRED,
  LCD_GRED,
  LCD_GBLUE,
  LCD_RED,
  LCD_MAGENTA,
  LCD_GREEN,
  LCD_CYAN,
  LCD_YELLOW,
  LCD_BROWN,
  LCD_BRRED,
  LCD_GRAY,
  LCD_DARKBLUE,
  LCD_LIGHTBLUE,
  LCD_GRAYBLUE,
  LCD_LIGHTGREEN,
  LCD_LGRAY,
  LCD_LGRAYBLUE ,
  LCD_LBBLUE
};
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
gc9a01_t m_gc9a01;

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

  bsp_lcd_draw_circle(120, 120, 110, 1, LCD_RED);

   for (uint8_t i = 0; i < sizeof(COLOR_TABLE) / sizeof(COLOR_TABLE[0]); i++)
    {
      bsp_lcd_fill(COLOR_TABLE[i]);
      bsp_lcd_write_string(30, 50, "Temperature:", LCD_RED, COLOR_TABLE[i], 2);
      bsp_lcd_write_string(30, 100, "SPO2:", LCD_RED, COLOR_TABLE[i], 2);
      bsp_lcd_write_string(30, 150, "Heart Rate:", LCD_RED, COLOR_TABLE[i], 2);
      bsp_lcd_write_string(50, 200, "Step:", LCD_RED, COLOR_TABLE[i], 2);
      bsp_delay_ms(1000);
    }
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
  if ((x >= LCD_WIDTH) ||         // Clip right
      (y >= LCD_HEIGHT) ||        // Clip bottom
      ((x + 6 * size - 1) < 0) || // Clip left
      ((y + 8 * size - 1) < 0))   // Clip top
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
