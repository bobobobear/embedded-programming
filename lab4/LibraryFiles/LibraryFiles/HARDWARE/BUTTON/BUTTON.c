#include "BUTTON.h"
#include "BUZZ.h"

//BUTTON initialization
void BUTTON_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); //Enable APB Clock
	
	GPIO_InitStructure.GPIO_Pin = BUTTON_PIN;				//BUTTON Pin
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//Push pull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M
	GPIO_Init(BUTTON_PORT, &GPIO_InitStructure);			//Initialize BUTTON GPIO
	//GPIO_SetBits(BUTTON_PORT,BUTTON_PIN);
}

void BUTTON_task(void *pvParameters)
{
		TimerHandle_t Timer = (TimerHandle_t) pvParameters;
		BUZZ = 0;
    while(1)
    {
      if (!(GPIO_ReadInputData(BUTTON_PORT) & BUTTON_PIN)) 
			{
				xTimerChangePeriod(Timer, pdMS_TO_TICKS(300),0);
				buzz_task(pvParameters);
			}
			else{
				BUZZ = 0;
			}
			delay_ms(100);
    }
}  

