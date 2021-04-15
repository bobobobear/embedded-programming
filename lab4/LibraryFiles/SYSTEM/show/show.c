#include "show.h"

void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
   while(1)
    {	

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
			oled_timer();
    }
}  

void oled_show(void)
{  
     //To DO
	u8 *name = "Ang Kai Siang";
	u8 *mod = "CE3103";
	u8 *group = "SEP3";
	OLED_ShowString(0, 0, name);
	OLED_ShowString(0, 20, mod);
	OLED_ShowString(0, 40, group);
	 
	 
	 //call some function in oled to display something

	 OLED_Refresh_Gram(); //refresh the OLED RAM

	  		
	}


void oled_timer(void)
{
	int i;
	for(i = 60; i > 0; i--)
	{
		OLED_ShowNumber(60, 40, i, 2, 12);
		delay_ms(1000);
		OLED_Refresh_Gram();
	}
}
