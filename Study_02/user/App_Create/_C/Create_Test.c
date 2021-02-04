#include "Create_Test.h"
#include "App_LCD.h"
#include <stdio.h>

void Test_Lcd(void)
{
	int y = 1;
	LCD_InitSet();
	
	while(1)
	{
		LCD_ShowString(6,12*y,228,18,12,"Test_Lcd");
		delay_ms(500);
		if(y<=17) y++;
		else y = 1;
	}
}

void Test_KEIL(void)
{
	printf("test\n...");
}






