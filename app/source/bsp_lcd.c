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

#include "lvgl.h"

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

static void bsp_lgvl_init(void);

/* Function definitions ----------------------------------------------- */
static void disp_driver_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
  bsp_lcd_address_set(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
  gc9a01_write_cmd(&m_gc9a01, GC9A01_MEMORY_WRITE);

  int32_t len = LCD_WIDTH * LCD_HEIGHT * 2;

  gc9a01_write_data(&m_gc9a01, (uint8_t *)color_p, len);

  lv_disp_flush_ready(disp_drv);
}

/**
 * Create a button with a label and react on click event.
 */
void lv_example_get_started_1(void)
{
  lv_obj_t *btn = lv_btn_create(lv_scr_act()); /*Add a button the current screen*/
  lv_obj_set_pos(btn, 10, 10);                 /*Set its position*/
  lv_obj_set_size(btn, 120, 50);               /*Set its size*/

  lv_obj_t *label = lv_label_create(btn); /*Add a label to the button*/
  lv_label_set_text(label, "Button");     /*Set the labels text*/
  lv_obj_center(label);
}

static void bsp_lgvl_init(void)
{
  lv_init();

  static lv_color_t buf_1[200];
  static lv_color_t buf_2[200];

  static lv_disp_draw_buf_t disp_buf;
  lv_disp_drv_t disp_drv;

  lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, LV_HOR_RES * LV_VER_RES);

  lv_disp_drv_init(&disp_drv);

  disp_drv.flush_cb = disp_driver_flush;
  disp_drv.draw_buf = &disp_buf;

  lv_disp_drv_register(&disp_drv);

  lv_example_get_started_1();

  /* use a pretty small demo for monochrome displays */
  /* Get the current screen  */
  lv_obj_t *scr = lv_disp_get_scr_act(NULL);

  /*Create a Label on the currently active screen*/
  lv_obj_t *label1 = lv_label_create(scr);
  lv_obj_set_pos(label1, 50, 100);   /*Set its position*/
  lv_obj_set_size(label1, 120, 100); /*Set its size*/

  /*Modify the Label's text*/
  lv_label_set_text(label1, "Hello\nworld");

  /* Align the Label to the center
     * NULL means align on parent (which is the screen now)
     * 0, 0 at the end means an x, y offset after alignment*/
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);

  while (1)
  {
    lv_tick_inc(1);
    lv_timer_handler();
    nrf_delay_ms(10);
  }
  
}

void bsp_lcd_init(void)
{
  m_gc9a01.delay_ms   = bsp_delay_ms;
  m_gc9a01.gpio_write = bsp_gpio_write;
  m_gc9a01.spi_send   = bsp_spi_write;

  gc9a01_init(&m_gc9a01);

  bsp_lcd_fill(LCD_WHITE);

  // bsp_lgvl_init();

  // bsp_lcd_draw_circle(120, 120, 110, 1, LCD_RED);

  bsp_lcd_write_string(80, 70, "98%", LCD_RED, LCD_WHITE, 5);
  bsp_lcd_write_string(13, 125, "BLOOD OXIGEN LEVEL", LCD_RED, LCD_WHITE, 2);
  bsp_lcd_write_string(100, 200, "78 BPM", LCD_RED, LCD_WHITE, 2);

  bsp_lcd_draw_image(0, 0, LCD_WIDTH, LCD_HEIGHT, image3);

  // for (uint8_t i = 0; i < sizeof(COLOR_TABLE) / sizeof(COLOR_TABLE[0]); i++)
  // {
  //   bsp_lcd_fill(COLOR_TABLE[i]);
  //   bsp_lcd_write_string(30, 50, "Temperature:", LCD_RED, COLOR_TABLE[i], 2);
  //   bsp_lcd_write_string(30, 100, "SPO2:", LCD_RED, COLOR_TABLE[i], 2);
  //   bsp_lcd_write_string(30, 150, "Heart Rate:", LCD_RED, COLOR_TABLE[i], 2);
  //   bsp_lcd_write_string(50, 200, "Step:", LCD_RED, COLOR_TABLE[i], 2);
  //   bsp_delay_ms(1000);
  // }
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

      gc9a01_write_data(&m_gc9a01,(uint8_t *)&data , 2);
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
