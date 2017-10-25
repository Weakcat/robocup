#ifndef _SEEK_H
#define _SEEK_H	 
#include "sys.h"
#include "PID.h"
#include "allocation.h"
#include "timer.h"
#include "delay.h"
#include "math.h"


void tracking(char direction,char artery,u16 speed,u8 mark_bit,u8 flag);
void Turn(char direction,u16 speed);
void differ_control(char artery,u16 speed);
void Stop(void);
void Go_Stright(char direction,u16 speed);
void motor_control(void);
void Measure(char artery);
void Turn_Angle(char artery,char ward,u16 speed);
void pid_UsartCtrl(void);


extern int pd_imcompD_Calc(int NextPoint);
#endif
