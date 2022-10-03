/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2020 Mihai Baneu                                             |
 │                                                                            |
 | Permission is hereby  granted,  free of charge,  to any person obtaining a |
 | copy of this software and associated documentation files (the "Software"), |
 | to deal in the Software without restriction,  including without limitation |
 | the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
 | and/or sell copies  of  the Software, and to permit  persons to  whom  the |
 | Software is furnished to do so, subject to the following conditions:       |
 |                                                                            |
 | The above  copyright notice  and this permission notice  shall be included |
 | in all copies or substantial portions of the Software.                     |
 |                                                                            |
 | THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
 | OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
 | MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
 | IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
 | CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
 | OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
 | THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
 |____________________________________________________________________________|
 |                                                                            |
 |  Author: Mihai Baneu                           Last modified: 08.Dec.2020  |
 |                                                                            |
 |___________________________________________________________________________*/

/* 
  Text drawing is based on the :
  u8x8 original code from https://github.com/olikraus/u8g2/
  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.
*/

#include <stdint.h>
#include "st7735.h"

st7735_hw_control_t hw;

void st7735_init(st7735_hw_control_t hw_control)
{
    hw = hw_control;
}

void st7735_hardware_reset()
{
    hw.res_high();
    hw.delay_us(5000);
    hw.res_low();
    hw.delay_us(5000);
    hw.res_high();
    hw.delay_us(50000);
}

void st7735_nop()
{
    const uint8_t command[] = { ST7735_CMD_NOP };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);
}

void st7735_software_reset()
{

}

uint32_t st7735_read_display_id()
{
    return 0;
}

uint32_t st7735_read_display_status()
{
    return 0;
}

uint8_t st7735_read_display_power()
{
    return 0;
}

uint8_t st7735_read_display_memory_address_control()
{
    return 0;
}

uint8_t st7735_read_display_pixel_format()
{
    return 0;
}

uint8_t st7735_read_display_image()
{
    return 0;
}

uint8_t st7735_read_display_signal()
{
    return 0;
}

void st7735_sleep_in_and_booster_off()
{

}

void st7735_sleep_out_and_booster_on()
{
    const uint8_t command[] = { ST7735_CMD_SLPOUT };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);
}

void st7735_partial_mode_on()
{

}

void st7735_normal_mode()
{
    const uint8_t command[] = { ST7735_CMD_NORON };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);
}

void st7735_display_inversion_off()
{
    const uint8_t command[] = { ST7735_CMD_INVOFF };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);
}

void st7735_display_inversion_on()
{

}

void st7735_gamma_curve_selection(uint8_t gamma_curve)
{

}

void st7735_display_off()
{

}

void st7735_display_on()
{
    const uint8_t command[] = { ST7735_CMD_DISPON };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);
}

void st7735_column_address_set(uint16_t start, uint16_t end)
{
    const uint8_t command[] = { ST7735_CMD_CASET };
    const uint8_t data[] = { (uint8_t)(start >> 8), (uint8_t)start, (uint8_t)(end >> 8), (uint8_t)end };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t), 1);
}

void st7735_row_address_set(uint16_t start, uint16_t end)
{
    const uint8_t command[] = { ST7735_CMD_RASET };
    const uint8_t data[] = { (uint8_t)(start >> 8), (uint8_t)start, (uint8_t)(end >> 8), (uint8_t)end };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t), 1);
}

void st7735_memory_write(uint8_t *data, uint16_t size, uint16_t repeat)
{
    const uint8_t command[] = { ST7735_CMD_RAMWR };
    
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);

    hw.dc_high();
    hw.data_wr(data, size, repeat);
}

uint8_t st7735_memory_read()
{
    return 0;
}

void st7735_partial_start_end_address(uint8_t start, uint8_t end)
{

}

void st7735_tearing_off();
void st7735_tearing_on(uint8_t mode)
{

}

void st7735_memory_data_access_control(uint8_t mx, uint8_t my, uint8_t mv, uint8_t ml, uint8_t mh, uint8_t rgb)
{
    const uint8_t command[] = { ST7735_CMD_MADCTL };
    const uint8_t data[] = { (mx << 7) + (my << 6) + (mv << 5) + (ml << 4) + (rgb << 3) + (mh << 2) };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t), 1);
}

void st7735_idle_mode_off()
{

}

void st7735_idle_mode_on()
{

}

void st7735_interface_pixel_format(uint8_t format)
{
    const uint8_t command[] = { ST7735_CMD_COLMOD };
    const uint8_t data[] = { format };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t), 1);

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t), 1);
}

uint8_t st7735_read_id1()
{
    return 0;
}

uint8_t st7735_read_id2()
{
    return 0;
}

uint8_t st7735_read_id3()
{
    return 0;
}

void st7735_draw_fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color)
{
    st7735_row_address_set(x1, x2);
    st7735_column_address_set(y1, y2);

    st7735_memory_write((uint8_t *)&color, sizeof(st7735_color_16_bit_t), (x2 - x1 + 1)*(y2 - y1 + 1));
}

void st7735_draw_h_line(uint8_t x1, uint8_t x2, uint8_t y, const st7735_color_16_bit_t color)
{
    st7735_row_address_set(x1, x2);
    st7735_column_address_set(y, y);
    st7735_memory_write((uint8_t *)&color, sizeof(st7735_color_16_bit_t), x2 - x1 + 1);
}

void st7735_draw_v_line(uint8_t y1, uint8_t y2, uint8_t x, const st7735_color_16_bit_t color)
{
    st7735_row_address_set(x, x);
    st7735_column_address_set(y1, y2);
    st7735_memory_write((uint8_t *)&color, sizeof(st7735_color_16_bit_t), y2 - y1 + 1);
}

static void draw_line_low(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, st7735_color_16_bit_t color)
{
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    int32_t yi = 1;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int32_t D = (2 * dy) - dx;
    int32_t y = y1;

    for (uint8_t x = x1; x <= x2; x++) {
        st7735_row_address_set(x, x);
        st7735_column_address_set(y, y);
        st7735_memory_write((uint8_t *)&color, sizeof(st7735_color_16_bit_t), 1);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else
        {
            D = D + 2*dy;
        }
    }
}

static void draw_line_high(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color)
{
    int32_t dx = x2 - x1;
    int32_t dy = y2 - y1;
    int32_t xi = 1;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int32_t D = (2 * dx) - dy;
    int32_t x = x1;

    for (uint8_t y = y1; y <= y2; y++) {
        st7735_row_address_set(x, x);
        st7735_column_address_set(y, y);
        st7735_memory_write((uint8_t *)&color, sizeof(st7735_color_16_bit_t), 1);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
        {
            D = D + 2*dx;
        }
    }
}

void st7735_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color)
{
    if (abs(y2 - y1) < abs(x2 - x1)) {
        if (x1 > x2)
            draw_line_low(x2, y2, x1, y1, color);
        else
            draw_line_low(x1, y1, x2, y2, color);
    } 
    else {
        if (y1 > y2)
            draw_line_high(x2, y2, x1, y1, color);
        else
            draw_line_high(x1, y1, x2, y2, color);
    }
}

void st7735_draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color, const st7735_color_16_bit_t fill)
{
    st7735_draw_h_line(x1, x2, y1, color);
    st7735_draw_h_line(x1, x2, y2, color);
    st7735_draw_v_line(y1, y2, x1, color);
    st7735_draw_v_line(y1, y2, x2, color);

    st7735_row_address_set(x1+1, x2-1);
    st7735_column_address_set(y1+1, y2-1);
    st7735_memory_write((uint8_t *)&fill, sizeof(st7735_color_16_bit_t), (x2-x1-1)*(y2-y1-1)*sizeof(st7735_color_16_bit_t));
}

void st7735_draw_image(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t *pixel_data)
{
    st7735_row_address_set(x, x + width - 1);
    st7735_column_address_set(y, y + height - 1);
    st7735_memory_write((uint8_t *)pixel_data, width*height*sizeof(st7735_color_16_bit_t), 1);
}

static uint8_t get_font_data(const uint8_t *adr)
{
    return (*(const uint8_t *)(adr));
}

static void get_glyph_data(const uint8_t *font, uint8_t th, uint8_t tv, uint8_t encoding, uint8_t *buf, uint8_t tile_offset)
{
    uint8_t first, last;
    uint16_t offset;

    first = get_font_data(font + 0);
    last = get_font_data(font + 1);
    if (first <= encoding && encoding <= last) {
        offset = encoding;
        offset -= first;
        offset *= th * tv;
        offset += tile_offset;
        offset *= 8;
        offset += 4;
        for (uint8_t i = 0; i < 8; i++) {
            buf[i] = get_font_data(font + offset);
            offset++;
        }
    } else {
        for (uint8_t i = 0; i < 8; i++) {
            buf[i] = 0;
        }
    }
}

static void draw_tile(const uint8_t *buffer, uint8_t x, uint8_t y, st7735_color_16_bit_t color, st7735_color_16_bit_t background)
{
    const uint8_t colormask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    st7735_color_16_bit_t ram[8*8];

    for (uint8_t i = 0; i < 8; i++) {
        for (uint8_t j = 0; j < 8; j++) {
            ram[i*8+j] = (buffer[i] & colormask[j]) ? color : background;
        }
    }

    st7735_row_address_set(x, x + 8 - 1);
    st7735_column_address_set(y, y + 8 - 1);
    st7735_memory_write((uint8_t *)ram, 8*8*sizeof(st7735_color_16_bit_t), 1);
}

static void draw_glyph(const uint8_t *font, uint8_t x, uint8_t y, uint8_t th, uint8_t tv, st7735_color_16_bit_t color, st7735_color_16_bit_t background, uint8_t encoding)
{
    uint8_t buffer[8];

    for (uint8_t xx = 0; xx < th; xx++) {
        for (uint8_t yy = 0; yy < tv; yy++) {
            get_glyph_data(font, th, tv, encoding, buffer, xx*tv+yy);
            draw_tile(buffer, xx * 8 + x, yy * 8 + y, color, background);
        }
    }
}

void st7735_draw_char(const uint8_t *font, uint8_t x, uint8_t y, st7735_color_16_bit_t color, st7735_color_16_bit_t background, const char c)
{
    uint8_t th = get_font_data(font + 2);
    uint8_t tv = get_font_data(font + 3);

    draw_glyph(font, x, y, th, tv, color, background, c);
}

void st7735_draw_string(const uint8_t *font, uint8_t x, uint8_t y, st7735_color_16_bit_t color, st7735_color_16_bit_t background, const char *s)
{
    uint8_t th = get_font_data(font + 2);
    uint8_t tv = get_font_data(font + 3);

    while (*s != 0) {
        draw_glyph(font, x, y, th, tv, color, background, *s);
        x += th * 8;
        s++;
    }
}
