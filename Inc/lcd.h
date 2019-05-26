#include "stm32f1xx_hal.h"

#define LCD_E_HIGH 		HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, 1)
#define LCD_E_LOW 		HAL_GPIO_WritePin(LCD_E_PORT, LCD_E_PIN, 0)
#define LCD_RS_LOW 		HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, 0)
#define LCD_RS_HIGH 	HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, 1)
#define LCD_CLEAR					0x01
#define LCD_HOME					0x02
#define LCDC_ENTRY_MODE				0x04
	#define LCD_EM_SHIFT_CURSOR		    0x00
	#define LCD_EM_SHIFT_DISPLAY	 	0x01
	#define LCD_EM_LEFT		   			0x00
	#define LCD_EM_RIGHT				0x02
#define LCD_ONOFF					0x08
	#define LCD_DISP_ON				    0x04
	#define LCD_CURSOR_ON				0x02
	#define LCDC_CURSOR_OFF				0x00
	#define LCDC_BLINK_ON				0x01
	#define LCDC_BLINK_OFF				0x00
#define LCD_SHIFT					0x10
	#define LCDC_SHIFT_DISP				0x08
	#define LCDC_SHIFT_CURSOR			0x00
	#define LCDC_SHIFT_RIGHT			0x04
	#define LCDC_SHIFT_LEFT				0x00
#define LCD_FUNC					0x20
	#define LCD_8_BIT					0x10
	#define LCD_4_BIT					0x00
	#define LCDC_TWO_LINE				0x08
	#define LCDC_FONT_5x10				0x04
	#define LCDC_FONT_5x7				0x00
#define LCDC_SET_CGRAM				0x40
#define LCDC_SET_DDRAM				0x80

#define LCD_LINE1 		0x00
#define LCD_LINE2 		0x40

void HAL_Delay2(uint32_t milliseconds);



void lcd_sendHalf(uint8_t data);
void lcd_write_byte(uint8_t data);
void lcd_write_cmd(uint8_t cmd);
void lcd_char(char data);
void LCD_Init(void);
void lcd_locate(uint8_t x, uint8_t y);
void lcd_str(char *text);
void lcd_str_XY(uint8_t x, uint8_t y, char * text);






