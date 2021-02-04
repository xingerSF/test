#include "stm32f10x.h"
#include "Create_Test.h"
#include "App_EXTI.h"
#include "App_USART.h"
#include "App_LCD.h"
#include "App_DMA.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
//DMA学习（未成功）
//	USART1_Receive();
//	LCD_InitSet();
//	DMA_USART_To_FLASH();
	
//USART学习
	USART1_Receive();
	LCD_InitSet();
	
//EXTI学习
//	EXTI0_PA0();
//	Test_Lcd();
	
//定时器学习
	
	while(1)
	{
		
	}
}








