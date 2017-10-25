#include "timer.h"
#include "usart.h"
#include "delay.h"

//////////////////////////////////////////////////////////////////////////////////	 
//±¾³ÌĞòÖ»¹©Ñ§Ï°Ê¹ÓÃ£¬Î´¾­×÷ÕßĞí¿É£¬²»µÃÓÃÓÚÆäËüÈÎºÎÓÃÍ¾
//ALIENTEK Mini STM32¿ª·¢°å
//PWM  Çı¶¯´úÂë			   
//ÕıµãÔ­×Ó@ALIENTEK
//¼¼ÊõÂÛÌ³:www.openedv.com
//ĞŞ¸ÄÈÕÆÚ:2010/12/03
//°æ±¾£ºV1.0
//°æÈ¨ËùÓĞ£¬µÁ°æ±Ø¾¿¡£
//Copyright(C) ÕıµãÔ­×Ó 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  


void Timer2_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //Ê±ÖÓÊ¹ÄÜ

	TIM_TimeBaseStructure.TIM_Period = 5000; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	 ¼ÆÊıµ½5000Îª500ms
	TIM_TimeBaseStructure.TIM_Prescaler =(7200-1); //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ  10KhzµÄ¼ÆÊıÆµÂÊ  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //¸ù¾İTIM_TimeBaseInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
 
	TIM_ITConfig(  //Ê¹ÄÜ»òÕßÊ§ÄÜÖ¸¶¨µÄTIMÖĞ¶Ï
		TIM2, //TIM2
		TIM_IT_Update  |  //TIM ÖĞ¶ÏÔ´
		TIM_IT_Trigger,   //TIM ´¥·¢ÖĞ¶ÏÔ´ 
		ENABLE  //Ê¹ÄÜ
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3ÖĞ¶Ï
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //ÏÈÕ¼ÓÅÏÈ¼¶0¼¶
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //´ÓÓÅÏÈ¼¶3¼¶
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQÍ¨µÀ±»Ê¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);  //¸ù¾İNVIC_InitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷

//	TIM_Cmd(TIM2, ENABLE);  //Ê¹ÄÜTIMxÍâÉè
							 
}

void TIM2_IRQHandler(void)   //TIM2ÖĞ¶Ï
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) //¼ì²éÖ¸¶¨µÄTIMÖĞ¶Ï·¢ÉúÓë·ñ:TIM ÖĞ¶ÏÔ´ 
		{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update  );  //Çå³ıTIMxµÄÖĞ¶Ï´ı´¦ÀíÎ»:TIM ÖĞ¶ÏÔ´ 
		}
}







void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //Ê±ÖÓÊ¹ÄÜ

	TIM_TimeBaseStructure.TIM_Period = arr; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	 ¼ÆÊıµ½5000Îª500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ  10KhzµÄ¼ÆÊıÆµÂÊ  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //¸ù¾İTIM_TimeBaseInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
 
	TIM_ITConfig(  //Ê¹ÄÜ»òÕßÊ§ÄÜÖ¸¶¨µÄTIMÖĞ¶Ï
		TIM3, //TIM2
		TIM_IT_Update  |  //TIM ÖĞ¶ÏÔ´
		TIM_IT_Trigger,   //TIM ´¥·¢ÖĞ¶ÏÔ´ 
		ENABLE  //Ê¹ÄÜ
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3ÖĞ¶Ï
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //ÏÈÕ¼ÓÅÏÈ¼¶0¼¶
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //´ÓÓÅÏÈ¼¶3¼¶
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQÍ¨µÀ±»Ê¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);  //¸ù¾İNVIC_InitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷

	TIM_Cmd(TIM3, ENABLE);  //Ê¹ÄÜTIMxÍâÉè
							 
}

void TIM3_IRQHandler(void)   //TIM3ÖĞ¶Ï
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //¼ì²éÖ¸¶¨µÄTIMÖĞ¶Ï·¢ÉúÓë·ñ:TIM ÖĞ¶ÏÔ´ 
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //Çå³ıTIMxµÄÖĞ¶Ï´ı´¦ÀíÎ»:TIM ÖĞ¶ÏÔ´ 
		}
}




//PWMÊä³ö³õÊ¼»¯
//arr£º×Ô¶¯ÖØ×°Öµ
//psc£ºÊ±ÖÓÔ¤·ÖÆµÊı

void TIM3_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC  | RCC_APB2Periph_AFIO, ENABLE);  
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //Ê¹ÄÜGPIOÍâÉèºÍAFIO¸´ÓÃ¹¦ÄÜÄ£¿éÊ±ÖÓÊ¹ÄÜ
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE); //Timer3²¿·ÖÖØÓ³Éä  TIM3_CH2->PB5                                                                       	 //ÓÃÓÚTIM3µÄCH2Êä³öµÄPWMÍ¨¹ı¸ÃLEDÏÔÊ¾
 //GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3²¿·ÖÖØÓ³Éä  TIM3_CH2->PB5       
   //ÉèÖÃ¸ÃÒı½ÅÎª¸´ÓÃÊä³ö¹¦ÄÜ,Êä³öTIM3 CH2µÄPWMÂö³å²¨ĞÎ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; //TIM_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //¸´ÓÃÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //TIM_CH2
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //¸´ÓÃÍÆÍìÊä³ö
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_7,Bit_SET); // PA7ÉÏÀ­	

	TIM_TimeBaseStructure.TIM_Period = arr; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ  ²»·ÖÆµ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //¸ù¾İTIM_TimeBaseInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
	
	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //Ñ¡Ôñ¶¨Ê±Æ÷Ä£Ê½:TIMÂö³å¿í¶Èµ÷ÖÆÄ£Ê½2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //±È½ÏÊä³öÊ¹ÄÜ
	TIM_OCInitStructure.TIM_Pulse = 0; //ÉèÖÃ´ı×°Èë²¶»ñ±È½Ï¼Ä´æÆ÷µÄÂö³åÖµ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //Êä³ö¼«ĞÔ:TIMÊä³ö±È½Ï¼«ĞÔ¸ß
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //¸ù¾İTIM_OCInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèTIMx
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //Ê¹ÄÜTIMxÔÚCCR2ÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
		TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //¸ù¾İTIM_OCInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèTIMx
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //Ê¹ÄÜTIMxÔÚCCR2ÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
		TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //¸ù¾İTIM_OCInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèTIMx
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //Ê¹ÄÜTIMxÔÚCCR2ÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
		TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //¸ù¾İTIM_OCInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèTIMx
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //Ê¹ÄÜTIMxÔÚCCR2ÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //Ê¹ÄÜTIMxÔÚARRÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
	
 
	TIM_Cmd(TIM3, ENABLE);  //Ê¹ÄÜTIMxÍâÉè
 

}
void TIM4_PWM_Init(u16 arr,u16 psc)
{  
	 GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// 
 	RCC_APB1PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  //Ê¹ÄÜGPIOÍâÉèÊ±ÖÓÊ¹ÄÜ
		
	//ÉèÖÃ¸ÃÒı½ÅÎª¸´ÓÃÊä³ö¹¦ÄÜ,Êä³öTIM1 CH1µÄPWMÂö³å²¨ĞÎ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; //TIM_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //¸´ÓÃÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	
	TIM_TimeBaseStructure.TIM_Period = arr; //ÉèÖÃÔÚÏÂÒ»¸ö¸üĞÂÊÂ¼ş×°Èë»î¶¯µÄ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÖÜÆÚµÄÖµ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //ÉèÖÃÓÃÀ´×÷ÎªTIMxÊ±ÖÓÆµÂÊ³ıÊıµÄÔ¤·ÖÆµÖµ  ²»·ÖÆµ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //¸ù¾İTIM_TimeBaseInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //Ñ¡Ôñ¶¨Ê±Æ÷Ä£Ê½:TIMÂö³å¿í¶Èµ÷ÖÆÄ£Ê½1£¨Ô­±¾ÊÇ2£©
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //±È½ÏÊä³öÊ¹ÄÜ
	TIM_OCInitStructure.TIM_Pulse = 0; //ÉèÖÃ´ı×°Èë²¶»ñ±È½Ï¼Ä´æÆ÷µÄÂö³åÖµ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //Êä³ö¼«ĞÔ:TIMÊä³ö±È½Ï¼«ĞÔ¸ß
	
TIM_OC1Init(TIM4, &TIM_OCInitStructure);
TIM_OC2Init(TIM4, &TIM_OCInitStructure);
TIM_OC3Init(TIM4, &TIM_OCInitStructure);
 TIM_OC4Init(TIM4, &TIM_OCInitStructure);
 TIM_CtrlPWMOutputs(TIM4,ENABLE);	//MOE Ö÷Êä³öÊ¹ÄÜ	
	 
  
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable); //PB6
		TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable); //PB7
			TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable); //PB8
				TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable); //PB9
				
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //Ê¹ÄÜTIMxÔÚARRÉÏµÄÔ¤×°ÔØ¼Ä´æÆ÷
	
	TIM_Cmd(TIM4, ENABLE);  //Ê¹ÄÜTIM1
	
}



//¶¨Ê±Æ÷5Í¨µÀ1ÊäÈë²¶»ñÅäÖÃ

TIM_ICInitTypeDef  TIM5_ICInitStructure;

void TIM5_Cap_Init(u16 arr,u16 psc)
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
   	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);	//Ê¹ÄÜTIM5Ê±ÖÓ
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //Ê¹ÄÜGPIOAÊ±ÖÓ
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;  //PA0 Çå³ıÖ®Ç°ÉèÖÃ  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 ÊäÈë  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);						 //PA0 ÏÂÀ­
	
	//³õÊ¼»¯¶¨Ê±Æ÷5 TIM5	 
	TIM_TimeBaseStructure.TIM_Period = arr; //Éè¶¨¼ÆÊıÆ÷×Ô¶¯ÖØ×°Öµ 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//Ô¤·ÖÆµÆ÷   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure); //¸ù¾İTIM_TimeBaseInitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯TIMxµÄÊ±¼ä»ùÊıµ¥Î»
  
	//³õÊ¼»¯TIM5ÊäÈë²¶»ñ²ÎÊı
	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	Ñ¡ÔñÊäÈë¶Ë IC1Ó³Éäµ½TI1ÉÏ
  	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//ÉÏÉıÑØ²¶»ñ
  	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //Ó³Éäµ½TI1ÉÏ
  	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //ÅäÖÃÊäÈë·ÖÆµ,²»·ÖÆµ 
  	TIM5_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ÅäÖÃÊäÈëÂË²¨Æ÷ ²»ÂË²¨
  	TIM_ICInit(TIM5, &TIM5_ICInitStructure);
	
	//ÖĞ¶Ï·Ö×é³õÊ¼»¯
	//NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;  //TIM3ÖĞ¶Ï
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //ÏÈÕ¼ÓÅÏÈ¼¶2¼¶
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //´ÓÓÅÏÈ¼¶0¼¶
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQÍ¨µÀ±»Ê¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);  //¸ù¾İNVIC_InitStructÖĞÖ¸¶¨µÄ²ÎÊı³õÊ¼»¯ÍâÉèNVIC¼Ä´æÆ÷ 
	
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC1,ENABLE);//ÔÊĞí¸üĞÂÖĞ¶Ï ,ÔÊĞíCC1IE²¶»ñÖĞ¶Ï	
	
   	TIM_Cmd(TIM5,ENABLE ); 	//Ê¹ÄÜ¶¨Ê±Æ÷5
   


}

u8  TIM5CH1_CAPTURE_STA=0;	//ÊäÈë²¶»ñ×´Ì¬		    				
u16	TIM5CH1_CAPTURE_VAL;	//ÊäÈë²¶»ñÖµ
 
//¶¨Ê±Æ÷5ÖĞ¶Ï·şÎñ³ÌĞò	 
void TIM5_IRQHandler(void)
{ 

 	if((TIM5CH1_CAPTURE_STA&0X80)==0)//»¹Î´³É¹¦²¶»ñ	
	{	  
		if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
		 
		{	    
			if(TIM5CH1_CAPTURE_STA&0X40)//ÒÑ¾­²¶»ñµ½¸ßµçÆ½ÁË
			{
				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)//¸ßµçÆ½Ì«³¤ÁË
				{
					TIM5CH1_CAPTURE_STA|=0X80;//±ê¼Ç³É¹¦²¶»ñÁËÒ»´Î
					TIM5CH1_CAPTURE_VAL=0XFFFF;
				}else TIM5CH1_CAPTURE_STA++;
			}	 
		}
	if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)//²¶»ñ1·¢Éú²¶»ñÊÂ¼ş
		{	
			if(TIM5CH1_CAPTURE_STA&0X40)		//²¶»ñµ½Ò»¸öÏÂ½µÑØ 		
			{	  			
				TIM5CH1_CAPTURE_STA|=0X80;		//±ê¼Ç³É¹¦²¶»ñµ½Ò»´Î¸ßµçÆ½Âö¿í
				TIM5CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5);
		   		TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising); //CC1P=0 ÉèÖÃÎªÉÏÉıÑØ²¶»ñ
			}else  								//»¹Î´¿ªÊ¼,µÚÒ»´Î²¶»ñÉÏÉıÑØ
			{
				TIM5CH1_CAPTURE_STA=0;			//Çå¿Õ
				TIM5CH1_CAPTURE_VAL=0;
	 			TIM_SetCounter(TIM5,0);
				TIM5CH1_CAPTURE_STA|=0X40;		//±ê¼Ç²¶»ñµ½ÁËÉÏÉıÑØ
		   		TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);		//CC1P=1 ÉèÖÃÎªÏÂ½µÑØ²¶»ñ
			}		    
		}			     	    					   
 	}
 
    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1|TIM_IT_Update); //Çå³ıÖĞ¶Ï±êÖ¾Î»
 
}



////////////////////////////////////////
//¶æ»úºÍ»úĞµ±Û¿Éµ÷·¶Î§7400-8600£¨0-180¶È£©,¿É²»ÓÃÍ£Ö¹¡
//90¶È=8324
//Æµ¿í=ÖÜÆÚ*CRR/ARR
////////////////////////////////////////

void DUOJI_1(int w)    //¶æ»úº¯Êı, PB0	
{ 
	if(w==0)
		{
     	TIM_SetCompare1(TIM3,8325);  // ¿Éµ÷
		}
	
	if(w==1)
		{
     	TIM_SetCompare1(TIM3,8600);  // ¿Éµ÷
		}
     if(w==2)
	 { 
     	TIM_SetCompare1(TIM3,7300);  // ¿Éµ÷
	}	 
 }

void DUOJI_2(int w)   //»úĞµ±Ûº¯Êı, PB1
{
	if(w==0)
		{
     	TIM_SetCompare2(TIM3,8325);  // ¿Éµ÷
		}
	
	if(w==1)
		{
     	TIM_SetCompare2(TIM3,8700);  // ¿Éµ÷
		}
     if(w==2)
	 { 
     	TIM_SetCompare2(TIM3,7300);  // ¿Éµ÷
	}	 
}
 void DUOJI_3(int w)   //»úĞµ±Ûº¯Êı, PB1
{
	if(w==0)
		{
     	TIM_SetCompare3(TIM3,8325);  // ¿Éµ÷
		}
	
	if(w==1)
		{
     	TIM_SetCompare3(TIM3,8700);  // ¿Éµ÷
		}
     if(w==2)
	 { 
     	TIM_SetCompare3(TIM3,7300);  // ¿Éµ÷
	}	 
}
void DUOJI_4(int w)   //»úĞµ±Ûº¯Êı, PB1
{
	if(w==0)
		{
     	TIM_SetCompare4(TIM3,8325);  // ¿Éµ÷
		}
	
	if(w==1)
		{
     	TIM_SetCompare4(TIM3,8600);  // ¿Éµ÷
		}
     if(w==2)
	 { 
     	TIM_SetCompare4(TIM3,7300);  // ¿Éµ÷
	}	 
}
 void DUOJI_Init()
 {		
  TIM3_PWM_Init(8999,159);	 //160·ÖÆµ¡£PWMÆµÂÊ=72000000/(9000*160)=50hz  20ms

}	 
