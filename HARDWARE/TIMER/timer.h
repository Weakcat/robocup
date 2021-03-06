#include "sys.h"
#ifndef __TIMER_H
#define __TIMER_H
#define Trig PBout(4)
/************************************************
float ultrasonic(void)
单位厘米
Echo PB5
 int main(void)
{
	u32 temp;
	u8 t=1;
	Ultrasonic_Init();   
//delay_init();	    	 //延时函数初始化	  
//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
  OLED_Init();			//初始化OLED 
//TIM3_PWM_Init(899,0); 		//不分频。PWM频率=72000/(899+1)=80Khz
//TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计�
  OLED_ShowString(0,24,"DEST:",12);
	OLED_ShowString(64,24,"cm",12); 
 	OLED_Refresh_Gram();		//更新显示到OLED  
	 while(1)
	{
	Ultrasonic(&t);
	OLED_ShowNum(20,24,t,5,16);//显示ASCII字符的码值
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

