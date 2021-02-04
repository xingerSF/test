#include "App_USART.h"
#include "lcd.h"

//设置USART1接收数据
void USART1_Receive(void)
{
	GPIO_InitTypeDef GPIO_InitTypeStruct;
	USART_InitTypeDef USART_InitTypeStruct;
	NVIC_InitTypeDef NVIC_InitTypeStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitTypeStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeStruct);
	
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitTypeStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeStruct);
	
	USART_InitTypeStruct.USART_BaudRate = 115200;
	USART_InitTypeStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitTypeStruct.USART_Mode = USART_Mode_Rx;
	USART_InitTypeStruct.USART_Parity = USART_Parity_Even;
	USART_InitTypeStruct.USART_StopBits = USART_StopBits_1;
	USART_InitTypeStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitTypeStruct);
	
	NVIC_InitTypeStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTypeStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeStruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
}

	u8 usart1_rdat[200];
	u16 usart1_rdat_flag = 0;
	u8 row = 1;

void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
	{
		usart1_rdat[usart1_rdat_flag] = USART_ReceiveData(USART1);
		usart1_rdat_flag++;
		if(usart1_rdat[usart1_rdat_flag-2] == 0x0d && usart1_rdat[usart1_rdat_flag-1] == 0x0A)
		{
			if(row > 25)
			{
				row = 0;
				LCD_Clear(WHITE);
			}
			LCD_ShowString(6,6+12*row,228,18,12,usart1_rdat);
			row += (usart1_rdat_flag-1)/40;
			row += 1;
			usart1_rdat_flag = 0;
		}
	}
}




