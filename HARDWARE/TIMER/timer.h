#include "sys.h"
#ifndef __TIMER_H
#define __TIMER_H
#define Trig PBout(4)
/************************************************
float ultrasonic(void)
��λ����
Echo PB5
 int main(void)
{
	u32 temp;
	u8 t=1;
	Ultrasonic_Init();   
//delay_init();	    	 //��ʱ������ʼ��	  
//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
  OLED_Init();			//��ʼ��OLED 
//TIM3_PWM_Init(899,0); 		//����Ƶ��PWMƵ��=72000/(899+1)=80Khz
//TIM5_Cap_Init(0XFFFF,72-1);	//��1Mhz��Ƶ�ʼ��
  OLED_ShowString(0,24,"DEST:",12);
	OLED_ShowString(64,24,"cm",12); 
 	OLED_Refresh_Gram();		//������ʾ��OLED  
	 while(1)
	{
	Ultrasonic(&t);
	OLED_ShowNum(20,24,t,5,16);//��ʾASCII�ַ�����ֵ
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

