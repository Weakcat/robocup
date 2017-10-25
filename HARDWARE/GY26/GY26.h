
#ifndef __GY26_H
#define __GY26_H

#include "stm32f10x.h"
#include "math.h"

#define	GY26_SlaveAddress   			0xfe	  						//������I2C���ߵĴӵ�ַ(д���ַ)
#define	GY26_WriteAddress   			GY26_SlaveAddress		//д���ַ
#define	GY26_ReadAddress   				GY26_SlaveAddress+1	//����ַ

#define GY26_CMD									0x00
#define GY26_Angle								0x31
#define GY26_Temperature					0x35
#define GY26_StartCalibration			0xC0
#define GY26_StopCalibration			0xC1

void Write_GY26_CMD(u8 Address);//дGY26 CMD(1byte)ָ��
uint8_t Read_GY26(u8 Address);//��GY26(1byte)
void Read_GY26_Angle(void);//��GY26�Ƕ�
uint16_t Read_GY26_Temperature(void);//��GY26�¶�
void GY26_Cal_On(void);//GY26����У׼
void GY26_Cal_Off(void);//GY26�ر�У׼
void GY26_Recovery_Factory(void);//GY26�ָ���������
void Set_GY26_CMP_OFFS(uint16_t CMP);//GY26���ô�ƫ��

int Filter1( int filter_new,float filter_const);//filter_const�˲�ϵ��0~256   128 �˲�ϵ��Խ��ƽ�������Ȳ�
int Averagevalue(void);//ȡ20��ֵǰ��β�Ҫ

#endif
/********************************END OF FILE***********************************/
