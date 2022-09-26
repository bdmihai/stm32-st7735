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
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));
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
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));
}

void st7735_partial_mode_on()
{

}

void st7735_normal_mode()
{
    const uint8_t command[] = { ST7735_CMD_NORON };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));
}

void st7735_display_inversion_off()
{
    const uint8_t command[] = { ST7735_CMD_INVOFF };
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));
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
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));
}

void st7735_column_address_set(uint16_t start, uint16_t end)
{
    const uint8_t command[] = { ST7735_CMD_CASET };
    const uint8_t data[] = { (uint8_t)(start >> 8), (uint8_t)start, (uint8_t)(end >> 8), (uint8_t)end };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t));
}

void st7735_row_address_set(uint16_t start, uint16_t end)
{
    const uint8_t command[] = { ST7735_CMD_RASET };
    const uint8_t data[] = { (uint8_t)(start >> 8), (uint8_t)start, (uint8_t)(end >> 8), (uint8_t)end };

    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t));
}

void st7735_memory_write(uint8_t *data, uint16_t size)
{
    const uint8_t command[] = { ST7735_CMD_RAMWR };
    
    hw.dc_low();
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));

    hw.dc_high();
    hw.data_wr(data, size);
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
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t));
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
    hw.data_wr(command, sizeof(command)/sizeof(uint8_t));

    hw.dc_high();
    hw.data_wr(data, sizeof(data)/sizeof(uint8_t));
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
