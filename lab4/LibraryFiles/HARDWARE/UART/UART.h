#ifndef __UART_H
#define __UART_H
#include "stdio.h"	
#include "sys.h" 
#include "oled.h"

//LED Port definition
#define UART_TASK_PRIO		4     
#define UART_STK_SIZE 		128   

#define UART_PORT GPIOC
#define UART_PIN GPIO_Pin_10
#define UART_POUT GPIO_Pin_11
#define UART_IN PCin(10) 
#define UART_OUT PCOUT(11) 
/*----------------------------------*/

void uart_init(u32 baudRate);
void usart3_send(u8 data);
int USART3_IRQHandler(void);
void uart_task(void *pvParameters);

#endif


