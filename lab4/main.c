#include "system.h"

#define START_TASK_PRIO   4
#define START_STK_SIZE    256
TaskHandle_t StartTask_Handler;
TimerHandle_t SoftwareTimer;
void start_task(void *pvParameters);

int main(void)
{
	systemInit();
	BUZZ_Init();
	uart_init(115200);
	BUTTON_Init();
	
	SoftwareTimer = xTimerCreate("LedTimer",
							pdMS_TO_TICKS(1000),
							pdTRUE,
							(void*)0,
							led_task);
	
	xTaskCreate((TaskFunction_t )start_task,
							(const char*		)"start_task",
							(uint16_t				)START_STK_SIZE,
							(void*					)SoftwareTimer,
							(UBaseType_t		)START_TASK_PRIO,
							(TaskHandle_t*	)&StartTask_Handler);
	
	vTaskStartScheduler();
	
}

void start_task(void *pvParameters)
{
	xTimerStart(SoftwareTimer, 0);
		
	taskENTER_CRITICAL();
	
	/*xTaskCreate(led_task, "led_task", LED_STK_SIZE, NULL, LED_TASK_PRIO, NULL);
	
	xTaskCreate(show_task, "show_task", SHOW_STK_SIZE, NULL, SHOW_TASK_PRIO, NULL);
	
	xTaskCreate(buzz_task, "buzz_task", BUZZ_STK_SIZE, NULL, BUZZ_TASK_PRIO, NULL);*/
	
	xTaskCreate(uart_task, "uart_task", UART_STK_SIZE, NULL, UART_TASK_PRIO, NULL);
	
	xTaskCreate(BUTTON_task, "BUTTON_task", BUTTON_STK_SIZE, pvParameters, BUTTON_TASK_PRIO, NULL);
	
	vTaskDelete(StartTask_Handler);
	
	taskEXIT_CRITICAL();
}
