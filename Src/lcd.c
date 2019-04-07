#include "main.h"
#include "lcd.h"

void HAL_Delay2(uint32_t milliseconds) {

   /* Initially clear flag */

   (void) SysTick->CTRL;

   while (milliseconds != 0) {

      /* COUNTFLAG returns 1 if timer counted to 0 since the last flag read */

      milliseconds -= (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) >> SysTick_CTRL_COUNTFLAG_Pos;

   }

}
void lcd_sendHalf(uint8_t data)
{
	LCD_E_HIGH;
	HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, (data & 0x01));
	HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, (data & 0x02));
	HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, (data & 0x04));
	HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, (data & 0x08));
	LCD_E_LOW;
}
void lcd_write_byte(uint8_t data)
{
	lcd_sendHalf(data >> 4);
	lcd_sendHalf(data);
	HAL_Delay2(60);

	//delay_us(60);
}
void lcd_write_cmd(uint8_t cmd)
{
	LCD_RS_LOW;
	lcd_write_byte(cmd);
}
void lcd_char(char data)
{
	LCD_RS_HIGH;
	lcd_write_byte(data);
}

void LCD_Init(void)
{
	
	HAL_Delay2(15);
	//delay_ms(15);

	LCD_E_LOW;
	LCD_RS_LOW;

	lcd_sendHalf(0x03);
	HAL_Delay2(100);
	lcd_sendHalf(0x03);
	HAL_Delay2(100);
	lcd_sendHalf(0x03);
	HAL_Delay2(100);
	lcd_sendHalf(0x02);
	HAL_Delay2(100);


	lcd_write_cmd( LCD_FUNC | LCD_4_BIT | LCDC_TWO_LINE | LCDC_FONT_5x7);
	lcd_write_cmd( LCD_ONOFF | LCD_DISP_ON );
	lcd_write_cmd( LCD_CLEAR );
	HAL_Delay2(15);
	lcd_write_cmd( LCDC_ENTRY_MODE | LCD_EM_SHIFT_CURSOR | LCD_EM_RIGHT );


}
void lcd_locate(uint8_t x, uint8_t y)
{

	switch(y)
	{
		case 0:
			lcd_write_cmd( LCDC_SET_DDRAM | (LCD_LINE1 + x) );
			break;

		case 1:
			lcd_write_cmd( LCDC_SET_DDRAM | (LCD_LINE2 + x) );
			break;
	}

}

void lcd_str(char *text)
{
	while(*text)
		lcd_char(*text++);
}

void lcd_str_XY(uint8_t x, uint8_t y, char * text)
{
	lcd_locate(x,y);

	while(*text)
		lcd_char(*text++);

}
