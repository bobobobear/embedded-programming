#include "system.h"
#include "buzzer.h"


void BUZZER_Init(void)
{   
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);    // Enable A port clock
    GPIO_InitStructure.GPIO_Pin = BUZZER_PIN;    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;         // Push-pull output
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;// Speed ??50MHz
    GPIO_Init(BUZZER_PORT, &GPIO_InitStructure);    // Initialize GPIOD3,6
    GPIO_SetBits(BUZZER_PORT,BUZZER_PIN); 
}

void buzzer_task(void *pvParameters)
{
    while(1)
    {
      BUZZER=~BUZZER;        //0 on, 1 off   
      delay_ms(7000);			
     // vTaskDelay(Buzzer_Count); //Delay 
    }
}  
