#ifndef _SERVOCTRL_H_
#define _SERVOCTRL_H_
#include "stm32f10x.h"
#include "time.h"



#define ACT_RISE_1 1
#define ACT_TRIST_1 2
#define ACT_GRAB_1 3
#define ACT_RISE_2 4
#define ACT_TRIST_2 5
#define ACT_GRAB_2 6
#define ACT_RISE_3 7
#define ACT_TRIST_3 8
#define ACT_GRAB_3 9
#define ACT_RISE_4 10
#define ACT_TRIST_4 11
#define ACT_GRAB_4 12

u16 Angle_Calc(float angle);
void Servo_UsartCtrl(void);
void Servo_Action(u8 Action_num);
void ACT_Change(u8 Act_CCRx, u16 Target_vaule);
#endif



