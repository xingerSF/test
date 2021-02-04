#ifndef _APP_USART_H
#define _APP_USART_H

#include "stm32f10x.h"

extern u8 usart1_rdat[200];

void USART1_Receive(void);

#endif
