#ifndef __BUZZ_H
#define __BUZZ_H
#include "sys.h"
#include "system.h"

//LED Port definition
#define BUZZ_TASK_PRIO		3     
#define BUZZ_STK_SIZE 		128   


#define BUZZ_PORT GPIOB
#define BUZZ_PIN GPIO_Pin_10
#define BUZZ PBout(10) 
/*----------------------------------*/

void BUZZ_Init(void);  
void buzz_task(void *pvParameters);
static u32 notes[];
static u8* song;
static uint32_t getNote(uint8_t ch);
static uint32_t getDuration(uint8_t ch);
static uint32_t getPause(uint8_t ch);
static void playNote(uint32_t note, uint32_t durationMs);
static void playSong(uint8_t *song);
#endif
