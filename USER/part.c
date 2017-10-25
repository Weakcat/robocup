#include "allocation.h"
float pitch,roll,yaw;
float d_k=1;
int  my_angle;
u32 flag;
u8 state_treasure[9]={0};
extern u8 state_door[5];

void Move(u8 state)
{
if (state){
DUOJI_2(1);DUOJI_3(2);
delay_ms(250);
DUOJI_2(0);DUOJI_3(0);}
else {
DUOJI_2(1);delay_ms(250);
DUOJI_2(0);DUOJI_3(2);
delay_ms(300);DUOJI_3(0);}
}



void Action(void)
{
motor_allocation('S');	
	//action
flag=500;
	while(flag)
{
if(ahead_infrared<=15)flag--;else flag=flag+10;
	delay_ms(1);
	if(flag>500)flag=500;
}

while(mpu_dmp_init())	
		{
 		delay_ms(500);
		}
BEEP=1;		
		DUOJI_4(0);
		DUOJI_2(0);
		DUOJI_3(0);
		 		delay_ms(500);
		DUOJI_4(2);
 		delay_ms(500);
		DUOJI_4(1);
flag=100;
while(flag)
{if(ahead_infrared>15)flag--;else flag=flag+10;
	if(flag>100)flag=100;}
BEEP=0;				

}



void Long_Bridge(void)
{
motor_allocation('F');
while(1){
    differ_control('M',700);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>5)  break;}
		}
while(1){
     if(laser_a){
		 TIM4->CCR1=900;
     TIM4->CCR2=500;
	   TIM4->CCR3=900;
	   TIM4->CCR4=500;}
else if(laser_b){
	   TIM4->CCR1=500;
     TIM4->CCR2=900;
	   TIM4->CCR3=900;
	   TIM4->CCR4=500;}
else {TIM4->CCR1=700;
     TIM4->CCR2=700;
	   TIM4->CCR3=700;
	   TIM4->CCR4=700;}
if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>10)  break;}
}
while(1){
        if(laser_a){
		 TIM4->CCR1=1100;
     TIM4->CCR2=900;
	   TIM4->CCR3=900;
	   TIM4->CCR4=1100;}
else if(laser_b){
	   TIM4->CCR1=900;
     TIM4->CCR2=1100;
	   TIM4->CCR3=1100;
	   TIM4->CCR4=900;}
else {TIM4->CCR1=1000;
     TIM4->CCR2=1000;
	   TIM4->CCR3=1000;
	   TIM4->CCR4=1000;}
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<-5)  break;}
}
Go_Stright('F',1200);
while(1){if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>-5)  break;}}
	
	
}


void Feature_Sport(char direction)
{
motor_allocation(direction);
	   flag=100;
	while(flag){
    differ_control('M',1500);
    if(Infr_DisState(2+d_k)<20)flag--;
		else flag+=10;
		if (flag>100)flag=100;
	};
flag=1000;
DUOJI_2(2);		
DUOJI_3(2);
while(flag){
    differ_control('M',1200);
    if(Infr_DisState(2+d_k)<15)flag--;
		else flag+=10;
		if (flag>1000)flag=1000;
	};
state_feature=1;
flag=100;
state_feature=1;
while(flag&&state_feature){
    differ_control('M',700);
    if(Infr_DisState(2+d_k)<5)flag--;
		else flag+=10;
		if (flag>100)flag=100;
	
	};

	Go_Stright(direction,500);
delay_ms(500);
DUOJI_2(0);		
DUOJI_3(0);
//容错机制
}
void Hill(char direction)
{

motor_allocation(direction);
	flag=10;
while(flag)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>10)flag--;
//				else flag+=1;
				}
//		      if(flag>10)flag=10;
  }
	flag=10;
while(flag)
	{differ_control('M',700);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<-5)flag--;
//				else flag+=1;
				}
//		      if(flag>10)flag=10;
  }
		flag=10;
while(flag)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>-5)flag--;
//				else flag+=1;
				}
//		      if(flag>10)flag=10;
  }
}


void Seesaw(void)
	{
motor_allocation('F');
while(1)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>5)break;}
  }
while(1){
        if(laser_a){
		 TIM4->CCR1=800;
     TIM4->CCR2=600;
	   TIM4->CCR3=600;
	   TIM4->CCR4=800;}
else if(laser_b){
	   TIM4->CCR1=600;
     TIM4->CCR2=800;
	   TIM4->CCR3=800;
	   TIM4->CCR4=600;}
else {TIM4->CCR1=700;
     TIM4->CCR2=700;
	   TIM4->CCR3=700;
	   TIM4->CCR4=700;}
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<-5) break;}
}
while(1){
        if(laser_a){
		 TIM4->CCR1=600;
     TIM4->CCR2=400;
	   TIM4->CCR3=400;
	   TIM4->CCR4=600;}
else if(laser_b){
	   TIM4->CCR1=400;
     TIM4->CCR2=600;
	   TIM4->CCR3=600;
	   TIM4->CCR4=400;}
else {TIM4->CCR1=500;
     TIM4->CCR2=500;
	   TIM4->CCR3=500;
	   TIM4->CCR4=500;}
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>-2) break;}
}
  }


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

void Slope(float k,float angle_1,float angle_2)
{
		motor_allocation('F');
	while(1)
{
	differ_control('M',700);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(k*roll>5)  break;}
};


    Go_Stright('F',500);

		while(1)
{
//if(laser_a||laser_A||laser_b||laser_B){
TIM4->CCR1=700+laser_a*200+laser_A*500-laser_b*200-laser_B*500;
TIM4->CCR2=700-laser_a*200-laser_A*500+laser_b*200+laser_B*500;
TIM4->CCR3=700-laser_a*200-laser_A*500+laser_b*200+laser_B*500;
TIM4->CCR4=700+laser_a*200+laser_A*500-laser_b*200-laser_B*500;

//}

	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(k*pitch>17) 			break;}
};
		while(1)
{
//if(laser_a||laser_A||laser_b||laser_B){
TIM4->CCR1=700+laser_a*200+laser_A*500-laser_b*200-laser_B*500;
TIM4->CCR2=700-laser_a*200-laser_A*500+laser_b*200+laser_B*500;
TIM4->CCR3=700-laser_a*200-laser_A*500+laser_b*200+laser_B*500;
TIM4->CCR4=700+laser_a*200+laser_A*500-laser_b*200-laser_B*500;

//}

	
	
	
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(k*roll<-5) 			break;}
};







BEEP=1;
	while(1)
{
    Go_Stright('F',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(k*roll>-2) 			break;}
};
BEEP=0;
}

void Door(u8 door)
{
	
	
	motor_allocation('B');
		state_feature=1;

while(state_feature){
    differ_control('M',1000);
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if((d_k*roll>5))break;}


	};
//while(state_feature){
//    differ_control('M',1000);
//			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
//		    {if((d_k*roll<-5))break;}

//	};
//	motor_allocation('B');
//	   flag=100;
//	while(flag){
//    differ_control('M',1200);
//    if(Infr_DisState(2+d_k)<20)flag--;
//		else flag+=10;
//		if (flag>100)flag=100;
//	};
//state_feature=1;
//flag=1000;
//DUOJI_2(2);		
//DUOJI_3(2);
//while(flag){
//    differ_control('M',1000);
//    if(Infr_DisState(2+d_k)<15)flag--;
//		else flag+=10;
//		if (flag>1000)flag=1000;
//	};

//flag=100;
//state_feature=1;
//while(flag&&state_feature){
//    differ_control('M',700);
//    if(Infr_DisState(2+d_k)<5)flag--;
//		else flag+=10;
//		if (flag>100)flag=100;
//	};

//DUOJI_2(0);		
//DUOJI_3(0);
//	while(state_feature){
//    differ_control('M',500);
//	};
	
	
	
	motor_allocation('S');

	flag=300;
while(flag%200)
{if(back_infrared>15)flag--;else flag++;}
	if(flag==200)	{state_door[door]=1;		BEEP=1;}
else if(flag==400)	state_door[door]=0;
delay_ms(1000);
BEEP=0;
}

	
	


void Plot_up(char direction,float angle_1,float angle_2)
{
motor_allocation(direction);
while(1){
    differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>angle_1)  break;}
		}
Go_Stright(direction,700);
while(1){if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_2)  break;}}
while(1){if(mild_L||mild_R)break;}
motor_allocation('S');
}

void Plot_turn(u8 state)
{
	int set;
 USART_SendData(USART2,0x31);

Move(state);

	
DUOJI_2(0);
 set=(180+my_angle)%360;
	flag=100;
while(flag)
{	USART_SendData(USART2,0x31);
	if(((set-my_angle)>0)&&((set-my_angle)<180))
		motor_allocation('R');
	else motor_allocation('L');
	if(abs(set-my_angle)<=180)
{    
	   TIM4->CCR1=500+9*abs(set-my_angle);
     TIM4->CCR2=500+9*abs(set-my_angle);
	   TIM4->CCR3=500+9*abs(set-my_angle);
	   TIM4->CCR4=500+9*abs(set-my_angle);
}else 
{    
	   TIM4->CCR1=500+9*(360-abs(set-my_angle));
     TIM4->CCR2=500+9*(360-abs(set-my_angle));
	   TIM4->CCR3=500+9*(360-abs(set-my_angle));
	   TIM4->CCR4=500+9*(360-abs(set-my_angle));
}
if(my_angle==set){flag--;motor_allocation('S');}
else flag=flag+10;
if(flag>1000)flag=1000;
};
BEEP=0;
DUOJI_3(0);
}


void Plot_down(char direction,float angle_1,float angle_2)
{
	motor_allocation(direction);
Go_Stright(direction,700); 	   
while(1){if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_1)  break;}}
while(1){
    differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>angle_2)  break;}
		} 	  
}


void Plot_Plus_up(char direction,float angle_1,float angle_2)
{
motor_allocation(direction);
while(1)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>angle_1)break;}
  }
while(1)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_2)break;}
  }
Go_Stright(direction,500);

while(1)
	{if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		 {if(d_k*roll>angle_1)break;}
}


while(1)
	{differ_control('M',1000);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_2)break;}
  }

Go_Stright(direction,500);

	while(1){if(mild_L||mild_R)break;}//方案一
motor_allocation('S');
}

void Plot_Plus_down(char direction,float angle_1,float angle_2)
{
motor_allocation(direction);
Go_Stright(direction,500); 
flag=1;
while(flag){if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_1)  flag--;}
         
}
while(1){
    differ_control('M',500);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>angle_2)  break;}
		} 	  

motor_allocation(direction);
Go_Stright(direction,500); 

while(1){if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<angle_1)  break;}
         
}
while(1){
    differ_control('M',500);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>angle_2)  break;}
		} 	  

}


void Treasure(u8 state)
{
	u8 state_1,state_2;
	if (state==0)
{
	Go_Stright('F',500);
delay_ms(1000);
flag=100;
while(flag)
{
if(ahead_infrared>4)Go_Stright('F',500);	
if(ahead_infrared<4)Go_Stright('B',500);
if(ahead_infrared==4) {motor_allocation('S'); flag--;}
}
motor_allocation('S');
}
	
if (state==1)	
{
flag=10;
	while(flag)
{
if(ahead_infrared<1){Go_Stright('B',500);state_1=1;state_2=0;}
if(ahead_infrared>4){Go_Stright('F',500);state_2=1;if(state_1&&state_2)flag--;state_1=0;}

}
//其中一种方案
//还有一种震荡
flag=1000;
while(flag)
{
if(ahead_infrared>4)Go_Stright('F',500);	
if(ahead_infrared<4)Go_Stright('B',500);
if(ahead_infrared==4) {motor_allocation('F'); flag--;}
}
motor_allocation('S');
}
if (state==2)	
{
Go_Stright('F',500);
delay_ms(1000);
motor_allocation('S');
}
}


void Cycle(void)
{

	motor_allocation('F');
while(1)
	{differ_control('L',700);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>5)break;}
  }
while(1){
        if(laser_a){
		 TIM4->CCR1=800;
     TIM4->CCR2=600;
	   TIM4->CCR3=600;
	   TIM4->CCR4=800;}
else if(laser_b){
	   TIM4->CCR1=600;
     TIM4->CCR2=800;
	   TIM4->CCR3=800;
	   TIM4->CCR4=600;}
else {TIM4->CCR1=700;
     TIM4->CCR2=700;
	   TIM4->CCR3=700;
	   TIM4->CCR4=700;}
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll<-5) break;}
}
while(1){
        if(laser_a){
		 TIM4->CCR1=400;
     TIM4->CCR2=200;
	   TIM4->CCR3=200;
	   TIM4->CCR4=400;}
else if(laser_b){
	   TIM4->CCR1=200;
     TIM4->CCR2=400;
	   TIM4->CCR3=400;
	   TIM4->CCR4=200;}
else {TIM4->CCR1=300;
     TIM4->CCR2=300;
	   TIM4->CCR3=300;
	   TIM4->CCR4=300;}
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		    {if(d_k*roll>-2) break;}
}
	
	
tracking('F','R',700,0,1);
	Go_Stright('F',500);
while(!ahead_1);
    Turn_Angle('L','a',1800);
    Turn_Angle('L','a',1800);
                Plot_up('F',10,2);  
                Plot_turn(0);	              
                Plot_down('F',-10,-10);




}

