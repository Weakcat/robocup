#include "allocation.h"
u8 count;
extern int speed;
extern  void feature_sport(void);//100%
extern u8  GY26_state;

/*******************************************************************************************************
Fuction:APP_debug_Init()
Dscription:对串口1进行配置，并为程序开始做准备，开关控制
Input:
Output:
Return:
Other:正式比赛可以注释掉，不影响主要程序
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
Dscription:蓝牙的主控程序，六个按键有六个不同的功能
Input:
Output:
Return:
Other:正式比赛可以注释掉，不影响主要程序
*******************************************************************************************************/
void State_UsartCtr()
{
		if(USART_RX_BUF[1]==0xb1)//跳出循环，程序开始,暂停
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

  if(USART_RX_BUF[1]==0xb2)//反向
	{
		if(state_motor==1)motor_allocation('B');
		else if(state_motor==2)motor_allocation('F');
			

		return;
	}

	if(USART_RX_BUF[1]==0xb3)//复位
	{
		__set_FAULTMASK(1);
		NVIC_SystemReset();

		return;
	}
	if(USART_RX_BUF[1]==0xb4)//加速按键，每次加某个值
	{speed=speed+500;
		if(speed>PWM_max)speed=PWM_max;
		My_send_data(TIM4->CCR1,5);
		My_send_data(TIM4->CCR2,6);
		return;
	}
  if(USART_RX_BUF[1]==0xb5)//减速按键，每次减某个值
	{
	 speed=speed-500;
		if(speed<PWM_min)speed=PWM_min;
		My_send_data(TIM4->CCR1,5);
		My_send_data(TIM4->CCR2,6);
		
		return;
	}
	
	if(USART_RX_BUF[1]==0xb6)//更新状态键，防止平时收发的资源占用
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


/****来回撞墙检测成功几率****/
void Feature_test(void)
{
	while(1)
{ 
		 Feature_Sport('F');
		 Feature_Sport('B');
}
}
/***********end****************/


/****上下坡成功率测试****/
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
/****长桥成功率测试****/
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



/****指南针校准****/


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
Dscription:路口观察
Input:
Output:
Return:
Other:正式比赛可以注释掉，不影响主要程序
*******************************************************************************************************/
void debug(u8 crossing)
{
	motor_allocation('P');
My_send_data(crossing,2);
state_begin=1;
while(state_begin);
}
		
		
/******************斜坡测试区**********************
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

/******************圆圈测试区**********************
                         //未来可以通过摄像头算圆或者曲线的曲率或半径
void cycle_tracking(char diraction,shunshizhen,banjin,speed)
{
Measure();
PWM_R=SPEED*(半径-半车宽-弧长差)/(半径-弧长差)+(值比较小的系数)(Kl*location+Ka*angle);
PWM_L=SPEED*(半径+半车宽-弧长差)/(半径-弧长差)+(值比较小的系数)(Kl*location+Ka*angle);
	  motor_control();
}
                        //转弯程序
void turn()
{
motor_allocation();
}
***************************************************/
