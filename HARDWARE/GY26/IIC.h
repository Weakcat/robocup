
	
#ifndef __IIC_H
#define __IIC_H

#include "stm32f10x.h"


void IIC_GPIO_Config(void);
void IIC_Mode_Config(void);
void IIC_Init(void);
void IIC_Write(u8*,u8,u8,u8);
void I2C_WriteByte(u8,u8,u8);
void IIC_Read(u8*,u8,u16,u8);
u8 I2C_ReadByte(u8, u8);
void IIC_WaitStandbyState(u8);

#endif

/*********************************************END OF FILE**********************/
