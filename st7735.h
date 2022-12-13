/*_____________________________________________________________________________
 │                                                                            |
 │ COPYRIGHT (C) 2022 Mihai Baneu                                             |
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
 |  Author: Mihai Baneu                           Last modified: 08.Oct.2022  |
 |                                                                            |
 |___________________________________________________________________________*/
 
#pragma once

#ifdef __cplusplus
    extern "C" {
#endif

/* System Function Command */
#define ST7735_CMD_NOP           0x00
#define ST7735_CMD_SWRESET       0x01 /* software reset */
#define ST7735_CMD_RDDID         0x04 /* read display id */
#define ST7735_CMD_RDDST         0x09 /* read display status */
#define ST7735_CMD_RDDPM         0x0A /* read display power */
#define ST7735_CMD_RDDMADCTL     0x0B /* read display memory address control*/
#define ST7735_CMD_RDDCOLMOD     0x0C /* read display pixel format */
#define ST7735_CMD_RDDIM         0x0D /* read display image */
#define ST7735_CMD_RDDSM         0x0E /* read display signal */
#define ST7735_CMD_SLPIN         0x10 /* sleep in and booster off */
#define ST7735_CMD_SLPOUT        0x11 /* sleep out and booster on */
#define ST7735_CMD_PTLON         0x12 /* partial mode on */
#define ST7735_CMD_NORON         0x13 /* normal mode */
#define ST7735_CMD_INVOFF        0x20 /* display inversion off */
#define ST7735_CMD_INVON         0x21 /* display inversion on */
#define ST7735_CMD_GAMSET        0x26 /* gamma curve selection */
#define ST7735_CMD_DISPOFF       0x28 /* display off */
#define ST7735_CMD_DISPON        0x29 /* display on */
#define ST7735_CMD_CASET         0x2A /* column address set */
#define ST7735_CMD_RASET         0x2B /* row address set */
#define ST7735_CMD_RAMWR         0x2C /* memory write */
#define ST7735_CMD_RAMRD         0x2E /* memory read */
#define ST7735_CMD_PTLAR         0x30 /* partial start end address */
#define ST7735_CMD_TEOFF         0x34 /* tearing off */
#define ST7735_CMD_TEON          0x35 /* tearing on */
#define ST7735_CMD_MADCTL        0x36 /* memory data access control */
#define ST7735_CMD_IDMOFF        0x38 /* idle mode off */
#define ST7735_CMD_IDMON         0x39 /* idle mode on */
#define ST7735_CMD_COLMOD        0x3A /* interface pixel format */
#define ST7735_CMD_RDID1         0xDA /* read id1 */
#define ST7735_CMD_RDID2         0xDB /* read id2 */
#define ST7735_CMD_RDID3         0xDC /* read id3 */

/* Panel Function Commands */
#define ST7732_CMD_FRMCTR1       0xB1 /* frame rate control 1 */
#define ST7732_CMD_FRMCTR2       0xB2 /* frame rate control 2 */
#define ST7732_CMD_FRMCTR3       0xB3 /* frame rate control 3 */
#define ST7732_CMD_INVCTR        0xB4 /* display inversion control */
#define ST7732_CMD_DISSET5       0xB6 /* display function setting */
#define ST7732_CMD_PWCTR1        0xC0 /* power control 1 */
#define ST7732_CMD_PWCTR2        0xC1 /* power control 2 */
#define ST7732_CMD_PWCTR3        0xC2 /* power control 3 */
#define ST7732_CMD_PWCTR4        0xC3 /* power control 4 */
#define ST7732_CMD_PWCTR5        0xC4 /* power control 5 */
#define ST7732_CMD_PWCTR6        0xFC /* power control 6 */
#define ST7732_CMD_VMCTR1        0xC5 /* vcom control */
#define ST7732_CMD_VMOFCTR       0xC7 /* set vcom offset */
#define ST7732_CMD_WRID2         0xD1 /* set lcm version code */
#define ST7732_CMD_WRID3         0xD2 /* set customer project code */
#define ST7732_CMD_NVCTR1        0xD9 /* eeprom control status */
#define ST7732_CMD_NVCTR2        0xDE /* eeprom read command */
#define ST7732_CMD_NVCTR3        0xDF /* eeprom write command */
#define ST7732_CMD_GAMCTRP1      0xE0 /* gamma adjustment positive */
#define ST7732_CMD_GAMCTRN1      0xE1 /* gamma adjustment negative */
#define ST7732_CMD_EXTCTRL       0xF0 /* extension command control */
#define ST7732_CMD_VCOM4L        0xFF /* vcom 4 level control */

// display resolution
#define ST7735_MAX_COLS          132
#define ST7735_MAX_RWOS          162
#define ST7735_128_COLS          128
#define ST7735_160_RWOS          160

// well defined parameters
#define ST7735_12_PIXEL 3
#define ST7735_16_PIXEL 5
#define ST7735_18_PIXEL 6
#define ST7735_TELOM_V  0
#define ST7735_TELOM_HV 1

/* definition of the 16bit color */
typedef struct st7735_color_16_bit_t {
    union
    {
        struct {
            uint16_t g_msb:3;
            uint16_t r:5;
            uint16_t b:5;
            uint16_t g_lsb:3;
        };

        struct {
            uint8_t byte_1;
            uint8_t byte_2;
        };

        struct {
            uint16_t word_1;
        };
    };
} st7735_color_16_bit_t;

#define ST7735_RGB(R,G,B) .r = (uint8_t)(R >> 3) & 0x1F, .b = (uint8_t)(B >> 3) & 0x1F, .g_lsb = (uint8_t)(G >> 2) & 0x07, .g_msb = (uint8_t)(G >> 5) & 0x07
#define ST7735_RGB_18bit(R,G,B) .r = (uint8_t)(R >> 2) & 0x1F, .b = (uint8_t)(B >> 2) & 0x1F, .g_lsb = (uint8_t)(G >> 1) & 0x07, .g_msb = (uint8_t)(G >> 4) & 0x07

extern const st7735_color_16_bit_t st7735_rgb_black;
extern const st7735_color_16_bit_t st7735_rgb_white;
extern const st7735_color_16_bit_t st7735_rgb_red;
extern const st7735_color_16_bit_t st7735_rgb_lime;
extern const st7735_color_16_bit_t st7735_rgb_blue;
extern const st7735_color_16_bit_t st7735_rgb_yellow;
extern const st7735_color_16_bit_t st7735_rgb_cyan;
extern const st7735_color_16_bit_t st7735_rgb_magenta;
extern const st7735_color_16_bit_t st7735_rgb_sylver;
extern const st7735_color_16_bit_t st7735_rgb_gray;
extern const st7735_color_16_bit_t st7735_rgb_maroon;
extern const st7735_color_16_bit_t st7735_rgb_olive;
extern const st7735_color_16_bit_t st7735_rgb_green;
extern const st7735_color_16_bit_t st7735_rgb_purple;
extern const st7735_color_16_bit_t st7735_rgb_teal;
extern const st7735_color_16_bit_t st7735_rgb_navy;

typedef void     (*st7735_set_func_t)();
typedef uint16_t (*st7735_write_func_t)(const uint8_t *buffer, uint16_t size, uint16_t repeat);
typedef uint16_t (*st7735_read_func_t)(uint8_t *buffer, uint16_t size);
typedef void     (*st7735_delay_us)(const uint32_t);

typedef struct st7735_hw_control_t {
    st7735_set_func_t res_high;
    st7735_set_func_t res_low;
    st7735_set_func_t dc_high;
    st7735_set_func_t dc_low;
    st7735_write_func_t data_wr;
    st7735_read_func_t data_rd;
    st7735_delay_us delay_us;
} st7735_hw_control_t;

typedef struct st7735_action_t {
    uint8_t command;
    uint8_t in_count;
    uint8_t out_count;
    uint8_t delay;
    uint8_t *in;
    uint8_t *out;
} st7735_action_t;

/* initialization */
void st7735_init(st7735_hw_control_t hw_control);

/* hw commands */
void st7735_hardware_reset();

/* system commands */
void st7735_nop();
void st7735_software_reset();
void st7735_read_display_id(uint32_t *id);
void st7735_read_display_status(uint8_t *status);
void st7735_read_display_power(uint8_t *power);
void st7735_read_display_memory_address_control(uint8_t *mode);
void st7735_read_display_pixel_format(uint8_t *mode);
void st7735_read_display_image(uint8_t *image);
void st7735_read_display_signal(uint8_t *signal);
void st7735_sleep_in_and_booster_off();
void st7735_sleep_out_and_booster_on();
void st7735_partial_mode_on();
void st7735_normal_mode();
void st7735_display_inversion_off();
void st7735_display_inversion_on();
void st7735_gamma_curve_selection(uint8_t gamma_curve);
void st7735_display_off();
void st7735_display_on();
void st7735_column_address_set(uint16_t start, uint16_t end);
void st7735_row_address_set(uint16_t start, uint16_t end);
void st7735_memory_write(uint8_t *data, uint16_t size, uint16_t repeat);
void st7735_memory_read(uint8_t *data, uint16_t size);
void st7735_partial_start_end_address(uint8_t start, uint8_t end);
void st7735_tearing_off();
void st7735_tearing_on(uint8_t mode);
void st7735_memory_data_access_control(uint8_t my, uint8_t mx, uint8_t mv, uint8_t ml, uint8_t rgb, uint8_t mh);
void st7735_idle_mode_off();
void st7735_idle_mode_on();
void st7735_interface_pixel_format(uint8_t format);
void st7735_read_id1(uint8_t *id);
void st7735_read_id2(uint8_t *id);
void st7735_read_id3(uint8_t *id);

/* panel commands */
// void st7735_frame_rate_control_1(uint8_t rtna, uint8_t fpa, uint8_t bpa);
// void st7735_frame_rate_control_2(uint8_t rtnb, uint8_t fpb, uint8_t bpb);
// void st7735_frame_rate_control_3(uint8_t rtnc, uint8_t fpc, uint8_t bpc, uint8_t rtnd, uint8_t fpd, uint8_t bpd);
// void st7735_display_inversion_control(uint8_t nla, uint8_t nlb, uint8_t nlc);
// void st7735_display_function_setting(uint8_t no, uint8_t sdt, uint8_t eq, uint8_t ptg, uint8_t pt);
// void st7735_power_control_1(uint8_t vrh, uint8_t ib_sel);
// void st7735_power_control_2(uint8_t bt);
// void st7735_power_control_3(uint8_t apa, uint8_t dca);
// void st7735_power_control_4(uint8_t apb, uint8_t dcb);
// void st7735_power_control_5(uint8_t apc, uint8_t dcc);
// void st7735_power_control_6(uint8_t apa, uint8_t apb, uint8_t apc, uint8_t dcd);
// void st7735_vcom_control(uint8_t vmh, uint8_t vml);
// void st7735_set_vcom_offset(uint8_t vmf);
// void st7735_set_lcm_version_code(uint8_t id2);
// void st7735_set_customer_project_code(uint8_t id3);
// void st7735_eeprom_control_status(uint8_t vmf_en, uint8_t id2_en);
// void st7735_eeprom_read_command();
// void st7735_eeprom_write_command(uint8_t ee_ib, uint8_t ee_cmd);
// void st7735_gamma_adjustment_positive(uint8_t high, uint8_t mid[14], uint8_t low);
// void st7735_gamma_adjustment_negative(uint8_t high, uint8_t mid[14], uint8_t low);
// void st7735_extension_command_control();
// void st7735_vcom_4_level_control(uint8_t tc1, uint8_t tc2, uint8_t tc3);

/* drawing primitives */
void st7735_draw_pixel(uint8_t x, uint8_t y, const st7735_color_16_bit_t color);
void st7735_draw_fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color);
void st7735_draw_h_line(uint8_t x1, uint8_t x2, uint8_t y, const st7735_color_16_bit_t color);
void st7735_draw_v_line(uint8_t y1, uint8_t y2, uint8_t x, const st7735_color_16_bit_t color);
void st7735_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color);
void st7735_draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, const st7735_color_16_bit_t color, const st7735_color_16_bit_t fill);
void st7735_draw_fill_circle(uint8_t x, uint8_t y, uint8_t r, const st7735_color_16_bit_t color);
void st7735_draw_circle(uint8_t x, uint8_t y, uint8_t r, const st7735_color_16_bit_t color);
void st7735_draw_image(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t *pixel_data);
void st7735_draw_char(const uint8_t *font, uint8_t x, uint8_t y, st7735_color_16_bit_t color, st7735_color_16_bit_t background, const char c);
void st7735_draw_string(const uint8_t *font, uint8_t x, uint8_t y, st7735_color_16_bit_t color, st7735_color_16_bit_t background, const char *s);

#ifdef __cplusplus
    }
#endif
