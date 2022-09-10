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
 |  Author: Mihai Baneu                           Last modified: 26.Dec.2020  |
 |                                                                            |
 |___________________________________________________________________________*/
 
#pragma once

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

// standard RGB15 colors
#define ST7735_RGB(R,G,B)        ((((uint16_t)B >> 3) << 11) + (((uint16_t)G >> 2) << 5) + ((uint16_t)R >> 3))
#define ST7735_BLACK             ST7735_RGB(0,0,0)
#define ST7735_WHITE             ST7735_RGB(255,255,255)
#define ST7735_RED	             ST7735_RGB(255,0,0)
#define ST7735_LIME              ST7735_RGB(0,255,0)
#define ST7735_BLUE              ST7735_RGB(0,0,255)
#define ST7735_YELLOW            ST7735_RGB(255,255,0)
#define ST7735_CYAN              ST7735_RGB(0,255,255)
#define ST7735_MAGENTA           ST7735_RGB(255,0,255)
#define ST7735_SILVER            ST7735_RGB(192,192,192)
#define ST7735_GRAY              ST7735_RGB(128,128,128)
#define ST7735_MAROON            ST7735_RGB(128,0,0)
#define ST7735_OLIVE             ST7735_RGB(128,128,0)
#define ST7735_GREEN             ST7735_RGB(0,128,0)
#define ST7735_PURPLE            ST7735_RGB(128,0,128)
#define ST7735_TEAL              ST7735_RGB(0,128,128)
#define ST7735_NAVY              ST7735_RGB(0,0,128)

typedef void (*st7735_set_func_t)();
typedef void (*st7735_write_func_t)(const uint8_t );
typedef uint8_t (*st7735_read_func_t)();
typedef void (*st7066u_delay_us)(const uint32_t);

typedef struct st7735_hw_control_t {
    st7735_set_func_t cs_high;
    st7735_set_func_t cs_low;
    st7735_set_func_t res_high;
    st7735_set_func_t res_low;
    st7735_set_func_t dc_high;
    st7735_set_func_t dc_low;
    st7735_set_func_t dc_cs_high;
    st7735_set_func_t dc_cs_low;
    st7735_write_func_t data_wr;
    st7735_read_func_t data_rd;
    st7066u_delay_us delay_us;
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
void st7735_software_reset();
uint32_t st7735_read_display_id();
uint32_t st7735_read_display_status();
uint8_t st7735_read_display_power();
uint8_t st7735_read_display_memory_address_control();
uint8_t st7735_read_display_pixel_format();
uint8_t st7735_read_display_image();
uint8_t st7735_read_display_signal();
void st7735_sleep_in_and_booster_off();
void st7735_sleep_out_and_booster_on();
void st7735_partial_mode_on();
void st7735_normal_mode();
void st7735_display_inversion_off();
void st7735_display_inversion_on();
void st7735_gamma_curve_selection(uint8_t gamma_curve);
void st7735_display_off();
void st7735_display_on();
void st7735_column_address_set(uint8_t start, uint8_t end);
void st7735_row_address_set(uint8_t start, uint8_t end);
void st7735_memory_write(uint8_t value);
uint8_t st7735_memory_read();
void st7735_partial_start_end_address(uint8_t start, uint8_t end);
void st7735_tearing_off();
void st7735_tearing_on(uint8_t mode);
void st7735_memory_data_access_control();
void st7735_idle_mode_off();
void st7735_idle_mode_on();
void st7735_interface_pixel_format();
uint8_t st7735_read_id1();
uint8_t st7735_read_id2();
uint8_t st7735_read_id3();

/* panel commands */
void frame_rate_control_1(uint8_t rtna, uint8_t fpa, uint8_t bpa);
void frame_rate_control_2(uint8_t rtnb, uint8_t fpb, uint8_t bpb);
void frame_rate_control_3(uint8_t rtnc, uint8_t fpc, uint8_t bpc, uint8_t rtnd, uint8_t fpd, uint8_t bpd);
void display_inversion_control(uint8_t nla, uint8_t nlb, uint8_t nlc);
void display_function_setting(uint8_t no, uint8_t sdt, uint8_t eq, uint8_t ptg, uint8_t pt);
void power_control_1(uint8_t vrh, uint8_t ib_sel);
void power_control_2(uint8_t bt);
void power_control_3(uint8_t apa, uint8_t dca);
void power_control_4(uint8_t apb, uint8_t dcb);
void power_control_5(uint8_t apc, uint8_t dcc);
void power_control_6(uint8_t apa, uint8_t apb, uint8_t apc, uint8_t dcd);
void vcom_control(uint8_t vmh, uint8_t vml);
void set_vcom_offset(uint8_t vmf);
void set_lcm_version_code(uint8_t id2);
void set_customer_project_code(uint8_t id3);
void eeprom_control_status(uint8_t vmf_en, uint8_t id2_en);
void eeprom_read_command();
void eeprom_write_command(uint8_t ee_ib, uint8_t ee_cmd);
void gamma_adjustment_positive(uint8_t high, uint8_t mid[14], uint8_t low);
void gamma_adjustment_negative(uint8_t high, uint8_t mid[14], uint8_t low);
void extension_command_control();
void vcom_4_level_control(uint8_t tc1, uint8_t tc2, uint8_t tc3);

