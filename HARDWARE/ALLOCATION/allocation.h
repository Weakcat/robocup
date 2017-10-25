#ifndef __ALLOCATION_H
#define __ALLOCATION_H	 
#include "sys.h"
#include "timer.h"
#include "delay.h"
#include "myiic.h"
#include "infrared.h"
#include "exti.h"
#include "usart.h"
#include "usart2.h"
#include "oled.h"
#include "seek.h"
#include "PID.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
//电机驱动控制
#define A1  PDout(12)//G15
#define A2 	PDout(10)//G13
#define B1  PDout(11) //E1
#define B2  PDout(13)//G14
#define C1    PGout(15)//
#define C2    PGout(13)//
#define D1    PGout(14)//
#define D2     PEout(1) //
//循迹接口由左至右
#define ahead_1   PGin(12)
#define ahead_2  PGin(11)
#define ahead_3  PDin(7)
#define ahead_4  PGin(10)
#define ahead_5  PDin(3)
#define ahead_6  PDin(4)
#define ahead_7  PCin(12)
#define ahead_8  PDin(2)
#define mild_L   (!PGin(9)) //读取
#define mild_R   (!PDin(14)) //读取
#define back_1    PEin(8)
#define back_2    PEin(9)
#define back_3   PFin(11)
#define back_4   PFin(12)
#define back_5   PFin(13)
#define back_6  PFin(14)
#define back_7  PFin(15)
#define back_8  PGin(0)
//微触开关
#define key_a     PFin(0)
#define key_b     PFin(1)
#define key_c     PFin(2)
#define key_d     PFin(3)
#define laser_a   (!PEin(11))
#define laser_b   (!PBin(14))
#define laser_A   (!PEin(14))
#define laser_B   (!PBin(12))
//PWM输出的定义
#define motor_a   TIM_SetCompare4(TIM4,PWM_L)
#define motor_b   TIM_SetCompare3(TIM4,PWM_R) 
#define motor_c   TIM_SetCompare1(TIM4,PWM_L)    
#define motor_d   TIM_SetCompare2(TIM4,PWM_R)
//红外测距定义
#define ahead_infrared  Infr_DisState(1)
#define back_infrared  Infr_DisState(3)
//蜂鸣器定义
#define BEEP  PFout(5)
//按键定义
#define key_1     (!PGin(1))
#define key_2     (!PEin(7))
//基本系数的定义
#define kp        15
#define ki        0
#define kd        0
#define ka        100.0
#define kl        1.0
#define length    120
#define PWM_max   3999
#define PWM_min   0
#define SET_VALUE 0
#define base_speed 999
#define Umax umax    //要和speed建立联系
#define Umin umin    //要和speed建立联系
//6  2?

//mark[0]=mild_L;
//mark[1]=mild_R;
//mark[2]=ahead_1;
//mark[3]=ahead_8;
//mark[4]=back_1;
//mark[5]=back_8;
//mark[6]=laser_a;
//mark[7]=laser_b;
//mark[8]=laser_A;
//mark[9]=laser_B;
//#define  速度1000时   kp=13   
//速度1500时   kp=20  
//速度2000时   kp=25   
//  TIM_SetCompare1(TIM4,speed);      //PB6 右motora   d
//	TIM_SetCompare2(TIM4,speed);      //PB7 左motorb   c
//  TIM_SetCompare3(TIM4,speed);      //PB8 左motorc   a
//	TIM_SetCompare4(TIM4,speed);      //PB9 右motord   b
//基本单元:		
// motor_allocation('');
// while(1){motor_control('',speed);if()break;}; 
//红外测距AD值:Infr_DisState(u8 Infr_num);
void ALLOCATION_Init(void);
extern void Go_Stright(char direction,u16 speed);
void motor_allocation(char direction);		 
void differ_control(char artery,u16 speed);
void motor_control(void);

void  compasstest(void);
void Bredge_test(void);
void Slop_test(void);
void Plot_test(void);
void debug(u8 crossing);
void DUOJI_1(int w);
void DUOJI_2(int w);
void DUOJI_3(int w);
void DUOJI_4(int w);

void Action(void);
void Long_Bridge(void);
void Seesaw(void);
void Plot_up(char direction,float angle_1,float angle_2);
void Plot_Plus_up(char direction,float angle_1,float angle_2);
void Plot_turn(u8 state);
void Plot_down(char direction,float angle_1,float angle_2);
void Plot_Plus_down(char direction,float angle_1,float angle_2);
void Feature_Sport(char direction);
void Hill(char direction);
void Seesaw(void);
void Door(u8 door);
void Slope(float k,float angle_1,float angle_2);
void Cycle(void);
void APP_debug_Init(void);
void Treasure(u8 state);//0是平台，1是寻宝平台，2是梯形


void section_1_9_treasure(void);
void section_2_9(void);
void section_23_(void);
void section_5_6_7(void);
void section_5_6_7_8(void);
void section_1(void);
void section_2(void);
void section_3(void);
void section_4(u8 door);
void section_5(void);
void section_6(void);
void section_7(void);
void section_8(void);
void section_9(u8 door);
void section_10(void);
extern float Kl,Ka,d_k;
extern u8 state_motor;
#endif
