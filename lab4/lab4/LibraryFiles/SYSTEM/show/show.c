#include "show.h"
#include "system.h"

void show_task(void *pvParameters)
{
  // u32 lastWakeTime = getSysTickCnt();
  // while(1)
  //  {	

	//		vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
  //  }
}  

void oled_show(void)
{  
    //To DO
	 //call some function in oled to display something
   int i=1;
	 while (1)
	 {
		 OLED_ShowNumber(0,0,i,5,15);
		 OLED_ShowString(0,20, "Ping Ju");
		 i++;
		 delay_ms(1000);
		 if (i == 60) i= 1;
		 OLED_Refresh_Gram(); //refresh the OLED RAM 
	 
	 }	  		
}

