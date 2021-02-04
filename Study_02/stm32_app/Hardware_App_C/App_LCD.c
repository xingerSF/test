#include "App_LCD.h"

void LCD_InitSet(void)
{
	delay_init();
//	uart_init(115200);
	LCD_Init();
	
	LCD_ShowString(6,6,228,18,12,"LCD_InitSet");
}
