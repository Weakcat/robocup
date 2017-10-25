#include "allocation.h"
u8 count;
extern int speed;
extern  void feature_sport(void);//100%
extern u8  GY26_state;

/*******************************************************************************************************
Fuction:APP_debug_Init()
Dscription:�Դ���1�������ã���Ϊ����ʼ��׼�������ؿ���
Input:
Output:
Return:
Other:��ʽ��������ע�͵�����Ӱ����Ҫ����
*******************************************************************************************************/
void APP_debug_Init()
{
	 uart_init(9600);	 
	 printf("READY\n");
	 My_send_state(0x00,1);
	 My_send_state(0x00,2);
	 My_send_state(0x00,3);
	 My_send_state(0x00,4);
	 while(state_begin);
}
/*******************************************************************************************************
Fuction:State_UsartCtr()
Dscription:���������س�������������������ͬ�Ĺ���
Input:
Output:
Return:
Other:��ʽ��������ע�͵�����Ӱ����Ҫ����
*******************************************************************************************************/
void State_UsartCtr()
{
		if(USART_RX_BUF[1]==0xb1)//����ѭ��������ʼ,��ͣ
		{if(state_begin==1){	
			state_begin=0;
      My_send_state(0x01, 1);
		}else if(state)
		{ 
			motor_allocation('P');
			state=0;
			My_send_state(0x01, 2);
		
		}else {
			switch (state_motor)
{
				case 1:
			motor_allocation('F');
				break;
			case 2:
			motor_allocation('B');
				break;
			case 3:
			motor_allocation('R');
				break;
			case 4:
			motor_allocation('L');
				break;
			case 5:
			motor_allocation('S');
				break;
}
      state=1;
			My_send_state(0x00, 2);
			
};
			return;
		}

  if(USART_RX_BUF[1]==0xb2)//����
	{
		if(state_motor==1)motor_allocation('B');
		else if(state_motor==2)motor_allocation('F');
			

		return;
	}

	if(USART_RX_BUF[1]==0xb3)//��λ
	{
		__set_FAULTMASK(1);
		NVIC_SystemReset();

		return;
	}
	if(USART_RX_BUF[1]==0xb4)//���ٰ�����ÿ�μ�ĳ��ֵ
	{speed=speed+500;
		if(speed>PWM_max)speed=PWM_max;
		My_send_data(TIM4->CCR1,5);
		My_send_data(TIM4->CCR2,6);
		return;
	}
  if(USART_RX_BUF[1]==0xb5)//���ٰ�����ÿ�μ�ĳ��ֵ
	{
	 speed=speed-500;
		if(speed<PWM_min)speed=PWM_min;
		My_send_data(TIM4->CCR1,5);
		My_send_data(TIM4->CCR2,6);
		
		return;
	}
	
	if(USART_RX_BUF[1]==0xb6)//����״̬������ֹƽʱ�շ�����Դռ��
	{
		while(1){
				break;}

    My_send_data(ahead_infrared,3);
		My_send_data(back_infrared,4);	
		My_send_data(TIM4->CCR1,5);
		My_send_data(TIM4->CCR2,6);
		return;
	}
}


/****����ײǽ���ɹ�����****/
void Feature_test(void)
{
	while(1)
{ 
		 Feature_Sport('F');
		 Feature_Sport('B');
}
}
/***********end****************/


/****�����³ɹ��ʲ���****/
void Plot_test(void)
{
Action();
while(1){
Plot_up('F',10,2);		
Plot_turn(0);	              
Plot_down('F',-10,-10); 
tracking('F','M',1000,3,1);	
motor_allocation('S');
delay_ms(1000);
Plot_up('B',10,2);                  
Plot_turn(0);	              
Plot_down('B',-10,-10); 		
tracking('B','M',1000,4,1);	
motor_allocation('S');
delay_ms(1000);			
};
}
/***********end****************/
/****���ųɹ��ʲ���****/
void Bredge_test(void)
{
Action();
while(1){          
Plot_down('F',-10,-10); 	           
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);
Long_Bridge();
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);	
Plot_up('F',10,1);  
Plot_turn(0);	              
Plot_down('F',-10,-10);   
tracking('F','M',1000,7,1);
tracking('F','M',1000,5,1);
Long_Bridge();
tracking('F','M',1000,7,1);
tracking('F','M',1000,5,1);	
Plot_up('F',10,1);  
Plot_turn(0);	                   	
};
}
/***********end****************/



/****ָ����У׼****/


void  compasstest(void){
	u8 flag=60;
		USART_SendData(USART2,0xC0);
		while(flag)
		{flag--;
		delay_ms(1000);
		My_send_data(flag,1);
		}
		USART_SendData(USART2,0xC1);
}
/***********end****************/
//		while(1){
////if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
//delay_ms(500);delay_ms(500);
////USART_SendData(USART2,0x31);printf("%d,%d\n",
////my_angle,back_infrared);
////printf("%f,%f,%f\n",
////pitch,roll,yaw);
////printf("%d,%d,%d,%d\n",
////laser_a,laser_b,laser_A,key_d);

//}
void Slop_test(void){
	while(1){
	Plot_up('F',10,1);  
  Plot_turn(0);	              
  Plot_down('F',-10,-10);
	Slope(1,15,15);
		Plot_up('F',10,1);  
  Plot_turn(0);	              
  Plot_down('F',-10,-10);
	Slope(-1,15,15);

}
}
		
 
/*******************************************************************************************************
Fuction:debug(u8 crossing)
Dscription:·�ڹ۲�
Input:
Output:
Return:
Other:��ʽ��������ע�͵�����Ӱ����Ҫ����
*******************************************************************************************************/
void debug(u8 crossing)
{
	motor_allocation('P');
My_send_data(crossing,2);
state_begin=1;
while(state_begin);
}
		
		
/******************б�²�����**********************
void slope(void)
{
     motor_allocation('F');
while(1){
    differ_control('M',speed);
		if(!laser_a||!laser_b)break;
		}
while(1){
     PWM_L=500;PWM_R=0;
		motor_control();
     if(laser_a)break;
}
while(1){
     if(!laser_a)break;
}
while(1){
     if(laser_a)break;
}


while(1){
     if(!laser_a){PWM_L=400;PWM_R=600;}
else if(!laser_b){PWM_L=600;PWM_R=400;}
else {PWM_L=500;PWM_R=500;}
		motor_control();
	if(Infr_DisState(1)<400)break;//if(Infr_DisState(2)<10)break;
}


}
  
***************************************************/

/******************ԲȦ������**********************
                         //δ������ͨ������ͷ��Բ�������ߵ����ʻ�뾶
void cycle_tracking(char diraction,shunshizhen,banjin,speed)
{
Measure();
PWM_R=SPEED*(�뾶-�복��-������)/(�뾶-������)+(ֵ�Ƚ�С��ϵ��)(Kl*location+Ka*angle);
PWM_L=SPEED*(�뾶+�복��-������)/(�뾶-������)+(ֵ�Ƚ�С��ϵ��)(Kl*location+Ka*angle);
	  motor_control();
}
                        //ת�����
void turn()
{
motor_allocation();
}
***************************************************/
