#include "allocation.h"
#include "servo_ctrl.h"
int speed=1000;
u8 state=1,state_begin=1,
state_motor=1,state_foward=1,
state_feature=1,state_door[5]={0};
extern float pitch,roll,yaw;
int main(void)
 {	
	 ALLOCATION_Init();
//	 APP_debug_Init();//比赛时注意！！！！注释掉
	 pd_imcompD_Init(kp,ki,kd);
	 TIM3_PWM_Init(8999,159);
		 uart_init(115200);	 

while(1){
	Action();
//	
////	Cycle();
////Treasure();

////section_1();
////section_2_9();
////section_10();


////section_5_6_7();//等等再调试




	
//////////	if(key_2){BEEP=1;delay_ms(500);BEEP=0;}
section_1();
section_23_();
//section_2();
//section_3();//debug(3);
state_door[0]=state_door[1]+2*state_door[2];
section_4(state_door[0]);//debug(4);
//////section_5();debug(5);
//////section_6();debug(6);
//////section_7();debug(7);
section_5_6_7();//debug(56);
//////////section_5_6_7_8();//debug(5678);
section_8();//debug(8);
	if (state_door[1])state_door[0]=1;
	if (state_door[2])state_door[0]=2;
	if (state_door[4])state_door[0]=4;
section_9(state_door[0]);//debug(9);
	section_10();
} 
}
 










