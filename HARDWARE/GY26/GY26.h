
#ifndef __GY26_H
#define __GY26_H

#include "stm32f10x.h"
#include "math.h"

#define	GY26_SlaveAddress   			0xfe	  						//器件在I2C总线的从地址(写入地址)
#define	GY26_WriteAddress   			GY26_SlaveAddress		//写入地址
#define	GY26_ReadAddress   				GY26_SlaveAddress+1	//读地址

#define GY26_CMD									0x00
#define GY26_Angle								0x31
#define GY26_Temperature					0x35
#define GY26_StartCalibration			0xC0
#define GY26_StopCalibration			0xC1

void Write_GY26_CMD(u8 Address);//写GY26 CMD(1byte)指令
uint8_t Read_GY26(u8 Address);//读GY26(1byte)
void Read_GY26_Angle(void);//读GY26角度
uint16_t Read_GY26_Temperature(void);//读GY26温度
void GY26_Cal_On(void);//GY26启动校准
void GY26_Cal_Off(void);//GY26关闭校准
void GY26_Recovery_Factory(void);//GY26恢复出厂设置
void Set_GY26_CMP_OFFS(uint16_t CMP);//GY26设置磁偏角

int Filter1( int filter_new,float filter_const);//filter_const滤波系数0~256   128 滤波系数越大平稳灵敏度差
int Averagevalue(void);//取20次值前五次不要

#endif
/********************************END OF FILE***********************************/
