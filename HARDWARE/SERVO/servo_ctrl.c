/* Includes ------------------------------------------------------------------*/
#include "servo_ctrl.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
//C7C8C9

/* 描述  ：舵机控制
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 */
u16 Rise_Moto = 0;
u16 Wrist_Moto = 0;
u16 Grab_Moto = 0;
void Servo_Action(u8 Action_num)
{
	switch(Action_num)
	{
		case ACT_RISE_1:
			ACT_Change(1, 2080);
			ACT_Change(2, 1490);
			ACT_Change(3, 1300);	
			break;
		case ACT_GRAB_1:
			ACT_Change(1, 2080);
			ACT_Change(2, 1490);
			ACT_Change(3, 930);	
			break;
		case ACT_RISE_2:
			ACT_Change(1, 1190);
			ACT_Change(2, 1490);
			ACT_Change(3, 930);	
			break;
		case ACT_GRAB_2:
			ACT_Change(1, 1000);
			ACT_Change(2, 1490);
			ACT_Change(3, 1300);	
			break;
			case ACT_RISE_3:
			ACT_Change(1, 1910);
			ACT_Change(2, 1640);
			ACT_Change(3, 930);	
			break;
		case ACT_GRAB_3:
			ACT_Change(1, 2000);
			ACT_Change(2, 1640);
			ACT_Change(3, 1340);	

//			break;
	}
}

void ACT_Change(u8 Act_CCRx, u16 Target_vaule)
{
	u16 i;
	int Abs_Ek;//绝对偏差
	u16 Temp_CCRVal;

	switch(Act_CCRx)
	{
		case 1:	
		Temp_CCRVal = TIM3->CCR1;
		if(Target_vaule-TIM3->CCR1 > 0)Abs_Ek = Target_vaule-TIM3->CCR1;
		else Abs_Ek = TIM3->CCR1 - Target_vaule;
			for(i = 0; i<(Abs_Ek/2); i++)
		{
			TIM3->CCR1 += 2*(Target_vaule-Temp_CCRVal)/Abs_Ek;
			delay_ms(1);
		}
			break;
		case 2:
		Temp_CCRVal = TIM3->CCR2;
		if(Target_vaule-TIM3->CCR2 > 0)Abs_Ek = Target_vaule-TIM3->CCR2;
		else Abs_Ek = TIM3->CCR2 - Target_vaule;
			for(i = 0; i<(Abs_Ek/2); i++)
		{
			TIM3->CCR2 += 2*(Target_vaule-Temp_CCRVal)/Abs_Ek;
			delay_ms(2);
		}
			break;
		case 3:
		Temp_CCRVal = TIM3->CCR3;			
		if(Target_vaule-TIM3->CCR3 > 0)Abs_Ek = Target_vaule-TIM3->CCR3;
		else Abs_Ek = TIM3->CCR3 - Target_vaule;
			for(i = 0; i<(Abs_Ek/2); i++)
		{
			TIM3->CCR3 += 2*(Target_vaule-Temp_CCRVal)/Abs_Ek;
			delay_ms(1);
		}			
			break;
	}
}
/*******将角度转化为舵机占空比***********************/

void Servo_UsartCtrl()
{
	if(USART_RX_BUF[1]==0xb1)//1号舵机+
		{
			TIM3->CCR1 += 10;
			My_send_data(TIM3->CCR1, 1);
			return;
		}

  if(USART_RX_BUF[1]==0xb2)//1号舵机-
	{
				TIM3->CCR1 -= 10;
			My_send_data(TIM3->CCR1, 1);
		return;
	}

	if(USART_RX_BUF[1]==0xb3)//2号舵机+
	{
			TIM3->CCR2 += 10;
			My_send_data(TIM3->CCR2, 2);
		return;
	}
	if(USART_RX_BUF[1]==0xb4)//2号舵机-
	{
			TIM3->CCR2 -= 10;
			My_send_data(TIM3->CCR2, 2);
		return;
	}
  if(USART_RX_BUF[1]==0xb5)//3号舵机+
	{
			TIM3->CCR3 += 10;
			My_send_data(TIM3->CCR3, 3);
		return;
	}
	
	if(USART_RX_BUF[1]==0xb6)//3号舵机-
	{	
			TIM3->CCR3 -= 10;
			My_send_data(TIM3->CCR3, 3);
		return;
	}
}
