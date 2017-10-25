#include "seek.h"


int PWM_R;
int PWM_L;
int umax,umin;
int ahead_location;
int back_location;
int location;
int last_alocation,last_blocation;
int art;
int ahead[10]={0,0,0,0,0,0,0,0,0,0};
int back[10]={0,0,0,0,0,0,0,0,0,0};
int location_numble[3][10]={{80,70,60,50,40,30,20,10,0,0},
                            {10,20,30,40,50,60,70,80,0,0},
	                          {50,40,60,30,70,20,80,10,0,0}
};
int mark[10]={0};
double angle;
float Kl,Ka;



/*******************************************************************************************************
Fuction:Measure(char artery)
Dscription:根据所测有效灰度情况计算出车体中心位置和偏移角度，新增干道循迹
Input:无
Output:
	 @location:车体中心位置(范围-70~70整型)--占的比例较小
	 @angle：车身偏移角度(范围-1.57~1.57浮点型)--占的比例较大
Return:无
Other:双排灰度效果优秀，无死区情况下使用，比例估算1:200 
*******************************************************************************************************/
void Measure(char artery)
{	


int x;
mark[0]=mild_L;
mark[1]=mild_R;
mark[2]=ahead_1;
mark[3]=ahead_8;
mark[4]=back_1;
mark[5]=back_8;
mark[6]=laser_a;
mark[7]=laser_b;
mark[8]=laser_A;
mark[9]=laser_B;
switch(artery)
{
case 'R': 
	art=0;
ahead[0]=ahead_8;ahead[1]=ahead_7;ahead[2]=ahead_6;ahead[3]=ahead_5;
ahead[4]=ahead_4;ahead[5]=ahead_3;ahead[6]=ahead_2;ahead[7]=ahead_1;
back[0]=back_8;back[1]=back_7;back[2]=back_6;back[3]=back_5;
back[4]=back_4;back[5]=back_3;back[6]=back_2;back[7]=back_1;
break;
case 'L':
	art=1;
ahead[0]=ahead_1;ahead[1]=ahead_2;ahead[2]=ahead_3;ahead[3]=ahead_4;
ahead[4]=ahead_5;ahead[5]=ahead_6;ahead[6]=ahead_7;ahead[7]=ahead_8;
back[0]=back_1;back[1]=back_2;back[2]=back_3;back[3]=back_4;
back[4]=back_5;back[5]=back_6;back[6]=back_7;back[7]=back_8;
break;
case 'M':
	art=2;
ahead[0]=ahead_5;ahead[1]=ahead_4;ahead[2]=ahead_6;ahead[3]=ahead_3;
ahead[4]=ahead_7;ahead[5]=ahead_2;ahead[6]=ahead_8;ahead[7]=ahead_1;
back[0]=back_5;back[1]=back_4;back[2]=back_6;back[3]=back_3;
back[4]=back_7;back[5]=back_2;back[6]=back_8;back[7]=back_1;
break;
}
for(x=0;x<=8;x++)
{if(ahead[x]){
ahead_location=(ahead[x]*location_numble[art][x]+ahead[x+1]*location_numble[art][x+1])/ 
            (ahead[x]+ahead[x+1]);   break;}if(x==8)ahead_location=last_alocation;
}
for(x=0;x<=8;x++)
{if(back[x]){
back_location=(back[x]*location_numble[art][x]+back[x+1]*location_numble[art][x+1])/ 
                 (back[x]+back[x+1]); break;}if(x==8)back_location=last_blocation;
}
last_alocation=ahead_location;
last_blocation=back_location;
location=(ahead_location+back_location)/2-45;//求得车体中心位置
angle=atan((double)(ahead_location-back_location)/length);//求得车体角度
}
/************************************end****************************************************************/




/*******************************************************************************************************
Fuction:Turn(char direction,u16 speed)
Dscription:通过改变电机驱动，改变转弯
Input:
  @direction:配置驱动，控制电机方向
  @speed:控制转弯速度
Output:
Return:无
Other:双排灰度效果未知，无死区情况下使用，比例估算1:200
*******************************************************************************************************/
void Turn(char direction,u16 speed)
{
	motor_allocation(direction);
	PWM_L=speed;
	PWM_R=speed;
  motor_control();
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:Go_Stright(char direction,u16 speed)
Dscription:直走程序，亦可以用来测电机静差
Input:
    @direction:前进方向 F(oward) or B(ackward)
    @speed:电机速度
Output:
Return:
Other:
*******************************************************************************************************/
void Go_Stright(char direction,u16 speed)
{
	motor_allocation(direction);
  PWM_L=speed;
	PWM_R=speed;
  motor_control();
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:tracking()
Dscription:根据前进方向、车体中心位置、车体角度计算偏移量
Input:
	@direction:前进方向 F(oward) or B(ackward)
  @speed:速度
  @mark_bit:哪个标志位
	@flag:第几个标志位停止
Output:
Return:
Other:干道循迹代替滤波
*******************************************************************************************************/
void tracking(char direction,char artery,u16 speed,u8 mark_bit,u8 flag)
{
	u8 last_mark=0;
	u8 count=0;
	u8 safe=0;
//	umax=3999-speed;
	umax=speed;
  umin=-speed;		
motor_allocation(direction);
		while(flag){
    Measure(artery);
	if (mark[mark_bit])		
{    if(last_mark){safe=1;last_mark=0;} //上升沿触发
      count=safe*(count+1);
     if(count==200){flag=flag-1;count=0;safe=0;}
}else {safe=0;last_mark=1;count=0;}
//if(speed<pd_imcompD_Calc(Kl*location+Ka*angle))PWM_R=0;
		PWM_L=speed+pd_imcompD_Calc(Kl*location+Ka*angle);//
		PWM_R=speed-pd_imcompD_Calc(Kl*location+Ka*angle);//
		motor_control();
		}
motor_allocation('S');

}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:Turn_Angle(char artery,char ward)
Dscription:根据车体转动方向和判断位置进行配置
Input:
	@artery:转动方向L or R
  @ward:判断位置  a or b
Output:
Return:
Other:1800~
*******************************************************************************************************/
void Turn_Angle(char artery,char ward,u16 speed)
{
	motor_allocation(artery);
	Measure(artery);
	if(ward=='a')
{while(speed){
	Measure(artery);
 Turn(artery,speed);
 if(ahead[0])break;
 }
 while(speed>=1000){
	 Measure(artery);
 Turn(artery,speed-500);
 if(ahead[1])break;
 }
 while(speed>=1500){
	 Measure(artery);
 Turn(artery,speed-1000);
 if(ahead[2])break;
 }
 while(speed>=1800){
	 Measure(artery);
 Turn(artery,speed-1300);
 if(ahead[3])break;
 }
}else
{while(speed){
	Measure(artery);
 Turn(artery,speed);
 if(back[7])break;
 }
 while(speed>=1000){
	 Measure(artery);
 Turn(artery,speed-500);
 if(back[6])break;
 }
 while(speed==1500){
	 Measure(artery);
 Turn(artery,speed-1000);
 if(back[5])break;
 }
 while(speed>=1800){
	 Measure(artery);
 Turn(artery,speed-1300);
 if(back[4])break;
 }
}
}
/************************************end****************************************************************/



/*******************************************************************************************************
Fuction:differ_control(char artery,u16 speed)
Dscription:差速控制函数
Input:
	@artery:干道方向  R or L
  @speed:速度
Output:
Return:
Other:基本单元之一
*******************************************************************************************************/
void differ_control(char artery,u16 speed)
{
		Measure(artery);
//	umax=3999-speed;
	umax=speed;
  umin=-speed;		
		PWM_L=speed+pd_imcompD_Calc(Kl*location+Ka*angle);//
		PWM_R=speed-pd_imcompD_Calc(Kl*location+Ka*angle);//
    motor_control();
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:motor_control(void)
Dscription:简单的电机控制为了让程序好看
Input:
Output:
Return:
Other:
*******************************************************************************************************/
void motor_control(void)
{
    motor_a;     
	  motor_b;
    motor_c;     
	  motor_d;
}
/************************************end****************************************************************/
