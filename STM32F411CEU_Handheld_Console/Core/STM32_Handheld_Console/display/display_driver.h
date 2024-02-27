#ifndef __display_driver_h
#define __display_driver_h

#include <stdint.h>
#include "./gfxfont.h"

#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 160

#define rgb888_to_rgb332(r, g, b)    ((((r) >> 5) << 5) | (((g) >> 5) << 2) | ((b) >> 6))

#define TR_C         "\x80"
#define TR_O         "\x81"
#define TR_I         "\x82"
#define TR_S         "\x83"
#define TR_U         "\x84"
#define TR_G         "\x85"
#define TR_c         "\x86"
#define TR_o         "\x87"
#define TR_i         "\x88"
#define TR_s         "\x89"
#define TR_u         "\x8a"
#define TR_g         "\x8b"
#define GP_UP        "\x8c"
#define GP_RIGHT     "\x8d"
#define GP_DOWN      "\x8e"
#define GP_LEFT      "\x8f"
#define GP_X         "\x90"
#define GP_Y         "\x91"
#define GP_A         "\x92"
#define GP_B         "\x93"
#define GP_HOME      "\x94"
#define GP_SELECT    "\x95"
#define GP_START     "\x96"
#define GP_L1        "\x97"
#define GP_L2        "\x98"
#define GP_R1        "\x99"
#define GP_R2        "\x9a"

extern const uint16_t rgb332_to_rgb565[256];
//extern uint8_t vram[DISPLAY_WIDTH][DISPLAY_HEIGHT];
extern uint8_t vram[DISPLAY_HEIGHT][DISPLAY_WIDTH];
extern GFXfont *gfx_font;

extern int16_t cursor_x;
extern int16_t cursor_y;

extern uint8_t text_size_x;
extern uint8_t text_size_y;

typedef struct
{
	uint8_t start_x;
	uint8_t start_y;
	uint8_t end_x;
	uint8_t end_y;
} TextArea;

extern TextArea text_area;
extern uint8_t wrap_text;

extern uint8_t text_bg_color;
extern uint8_t text_fg_color;

extern GFXglyph *glyph;
extern uint16_t glyph_bo;
extern uint8_t glyph_w;
extern uint8_t glyph_h;
extern int8_t glyph_xo;
extern int8_t glyph_yo;

uint8_t init_display(void);
void update_display(void);

void draw_raw_pixel(int16_t _x, int16_t _y, uint8_t color);
void draw_raw_v_line(int16_t x, int16_t y, int16_t h, uint8_t color);
void draw_raw_h_line(int16_t x, int16_t y, int16_t w, uint8_t color);
void draw_raw_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
void fill_raw_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
void draw_pixel(int16_t _x, int16_t _y, uint8_t color);
void draw_v_line(int16_t x, int16_t y, int16_t h, uint8_t color);
void draw_h_line(int16_t x, int16_t y, int16_t w, uint8_t color);
void draw_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
void fill_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
void fill_display(uint8_t color);
void clear_display(void);
void draw_image(int16_t x, int16_t y, uint16_t w, uint16_t h, const uint8_t *image, uint8_t tint);

void set_cursor(int16_t x, int16_t y);
void set_text_size(uint8_t x, uint8_t y);
void set_text_color(uint8_t fg, uint8_t bg);
void set_text_wrap(uint8_t wrap);
void set_text_area(uint8_t sx, uint8_t sy, uint8_t ex, uint8_t ey);
void set_font(const GFXfont *font);
uint8_t get_font_height(void);
void char_bounds(unsigned char c, int16_t *x, int16_t *y, int16_t *min_x, int16_t *min_y, int16_t *max_x, int16_t *max_y);
void text_bounds(const char *str, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);
void draw_char(int16_t x, int16_t y, uint8_t c, uint8_t text_color, uint8_t bg_color, uint8_t size_x, uint8_t size_y);
void print_chr(uint8_t c);
void print_str(const char* str);
void print_int(long num);
void printf_str(const char *text, ...);

#endif // __display_driver_h