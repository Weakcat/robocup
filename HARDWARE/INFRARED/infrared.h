#ifndef __INFRARED_H
#define	__INFRARED_H
#include "stm32f10x.h"


void ADC1_GPIO_Config(void);
void ADC1_Mode_Config(void);
void Infrared_Init(void);
u32 Infr_DisState(u8 Infr_num);
u32 Get_Distance(u8 Infr_num);


#endif 

