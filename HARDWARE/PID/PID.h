#ifndef _PID_H
#define _PID_H
#include "sys.h"
#include "usart.h"
#include "allocation.h"
typedef struct
{
 float Sv;//用户设定值
 float Pv;//当前所在值
 float Kp;//pid中p的参数
 float Ki;//pid中i的参数
 float Kd;//pid中d的参数
 float Ka;//pid中其他可能用到的参数
 float Ek;  //本次偏差
 float Ek_1;//上次偏差
 float SEk; //历史偏差之和
 float Iout;//积分输出
 float Pout;//比例输出
 float Dout;//微分输出
 float OUT0;//不明所以的输出
 float OUT;	//总输出
 float OUT_l;	//上次输出
 u16 C10ms;
 u16 pwmcycle;//pwm周期
}PID;

void pid_pwm_Init(int KP,int KI,int KD);
void pid_pwm_UsartCtr(void);
int  pid_pwm_Calc(int NextPoint);



void pd_imcompD_Init(int KP,int KA,int KD);
void pd_imcompD_UsartCtr(void);
int  pd_imcompD_Calc(int NextPoint);

extern int umax,umin;
extern u16 SPEED;//不明所以
#endif
