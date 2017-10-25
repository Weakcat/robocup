#include "sys.h"
#ifndef __TIMER_H
#define __TIMER_H
#define Trig PBout(4)
/************************************************
float ultrasonic(void)
µ¥Î»ÀåÃ×
Echo PB5
 int main(void)
{
	u32 temp;
	u8 t=1;
	Ultrasonic_Init();   
//delay_init();	    	 //ÑÓÊ±º¯Êý³õÊ¼»¯	  
//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //ÉèÖÃNVICÖÐ¶Ï·Ö×é2:2Î»ÇÀÕ¼ÓÅÏÈ¼¶£¬2Î»ÏìÓ¦ÓÅÏÈ¼¶
//uart_init(115200);	 //´®¿Ú³õÊ¼»¯Îª115200
 	LED_Init();			     //LED¶Ë¿Ú³õÊ¼»¯
  OLED_Init();			//³õÊ¼»¯OLED 
//TIM3_PWM_Init(899,0); 		//²»·ÖÆµ¡£PWMÆµÂÊ=72000/(899+1)=80Khz
//TIM5_Cap_Init(0XFFFF,72-1);	//ÒÔ1MhzµÄÆµÂÊ¼ÆÊ
  OLED_ShowString(0,24,"DEST:",12);
	OLED_ShowString(64,24,"cm",12); 
 	OLED_Refresh_Gram();		//¸üÐÂÏÔÊ¾µ½OLED  
	 while(1)
	{
	Ultrasonic(&t);
	OLED_ShowNum(20,24,t,5,16);//ÏÔÊ¾ASCII×Ö·ûµÄÂëÖµ
  OLED_Refresh_Gram();
	delay_ms(90);	
		}
}
************************************************/
void Timer2_Init(u16 arr,u16 psc);
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM4_PWM_Init(u16 arr,u16 psc);
void TIM2_PWM_Init(u16 arr,u16 psc);
void TIM5_Cap_Init(u16 arr,u16 psc);
#endif

