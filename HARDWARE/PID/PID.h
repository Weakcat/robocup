#ifndef _PID_H
#define _PID_H
#include "sys.h"
#include "usart.h"
#include "allocation.h"
typedef struct
{
 float Sv;//�û��趨ֵ
 float Pv;//��ǰ����ֵ
 float Kp;//pid��p�Ĳ���
 float Ki;//pid��i�Ĳ���
 float Kd;//pid��d�Ĳ���
 float Ka;//pid�����������õ��Ĳ���
 float Ek;  //����ƫ��
 float Ek_1;//�ϴ�ƫ��
 float SEk; //��ʷƫ��֮��
 float Iout;//�������
 float Pout;//�������
 float Dout;//΢�����
 float OUT0;//�������Ե����
 float OUT;	//�����
 float OUT_l;	//�ϴ����
 u16 C10ms;
 u16 pwmcycle;//pwm����
}PID;

void pid_pwm_Init(int KP,int KI,int KD);
void pid_pwm_UsartCtr(void);
int  pid_pwm_Calc(int NextPoint);



void pd_imcompD_Init(int KP,int KA,int KD);
void pd_imcompD_UsartCtr(void);
int  pd_imcompD_Calc(int NextPoint);

extern int umax,umin;
extern u16 SPEED;//��������
#endif
