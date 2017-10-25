#include "infrared.h"

__IO u16 ADC_Conval[4]={0};

 void ADC1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);				
}

 void ADC1_Mode_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&(ADC1->DR));
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_Conval;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = 4;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; 
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1 , ENABLE);
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 4;	
	ADC_Init(ADC1, &ADC_InitStructure);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 2, ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 3, ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 4, ADC_SampleTime_239Cycles5);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

void Infrared_Init(void)
{
	ADC1_GPIO_Config();
	ADC1_Mode_Config();
}

//u32 Get_Distance(void)
//{
//	u32 ADC_AverageDis[4]={0};	
//	static u32 filter_Distace;
//	static u32 Last_AverageDis;
//	u16 neighbh = 10;//邻域限幅	
//  float ratio = 0.1;
//		ADC_AverageDis[0] = 100*(2547.8/((float)ADC_Conval[0]*0.49-10.41)-0.42);
////		ADC_AverageDis[0] = ratio*Last_AverageDis+(1-ratio)*ADC_AverageDis[0];
//		if((int)(ADC_AverageDis[0]-Last_AverageDis)>neighbh||(int)(Last_AverageDis-ADC_AverageDis[0])>neighbh)
//		{
//			Last_AverageDis = ADC_AverageDis[0];
//			return filter_Distace;
//		}
//		else 
//		{
//			filter_Distace = ADC_AverageDis[0];
//			return ADC_AverageDis[0];			
//		}

//}
/*******************************************************************************************************
Fuction:Infr_DisState(u8 Infr_num)
Dscription:通过对AD采集得到的数据进行平均值滤波
Input:
	@Infr_num:第几个红外PF0~3
Output:
Return:红外滤波得到的值
Other:偏角大，稳定，快速的测距方法
*******************************************************************************************************/
u32 Infr_DisState(u8 Infr_num)
{
	u32 AverageDis;
	u32 SumDistance=0;
	u8 i;
	for(i=0; i<5; i++)
	{
		AverageDis = Get_Distance(Infr_num);
		SumDistance += AverageDis;
	}
	return SumDistance/500;
}


/*******************************************************************************************************
Fuction:Get_Distance(u8 Infr_num)
Dscription:通过AD采集得到距离5~40or10~80mm
Input:
	@Infr_num:第几个红外PC0~3
Output:
Return:红外所测得的值
Other:单纯的获得距离，需要滤波？
*******************************************************************************************************/
u32 Get_Distance(u8 Infr_num)
{
	u32 ADC_AverageDis[4]={0};	
  float ratio = 0;
	static u32 Last_AverageDis[4];
	ADC_AverageDis[Infr_num] = 100*(2547.8/((float)ADC_Conval[Infr_num]*0.49-10.41)-0.42);
  ADC_AverageDis[Infr_num] = ratio*Last_AverageDis[Infr_num]+(1-ratio)*ADC_AverageDis[Infr_num];
	Last_AverageDis[Infr_num] = ADC_AverageDis[Infr_num];
	return ADC_AverageDis[Infr_num];
}

