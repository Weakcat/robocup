#include "allocation.h"

void ALLOCATION_Init(void)
{ 
GPIO_InitTypeDef  GPIO_InitStructure;	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOG, ENABLE);	 
	

	 /****************����������������********************/
//PE1
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOE, &GPIO_InitStructure);	
GPIO_ResetBits(GPIOE,GPIO_Pin_1);
//PG13
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
GPIO_Init(GPIOG, &GPIO_InitStructure);	
GPIO_ResetBits(GPIOG,GPIO_Pin_13);
//PG14
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOG, &GPIO_InitStructure);	 
GPIO_ResetBits(GPIOG,GPIO_Pin_14);
//PG15
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;			
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOG, &GPIO_InitStructure);	 
GPIO_ResetBits(GPIOG,GPIO_Pin_15);
//PD10
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
GPIO_Init(GPIOD, &GPIO_InitStructure);	
GPIO_ResetBits(GPIOD,GPIO_Pin_10);
//PD11
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOD, &GPIO_InitStructure);	 
GPIO_ResetBits(GPIOD,GPIO_Pin_11);
//PD12
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
GPIO_Init(GPIOD, &GPIO_InitStructure);	
GPIO_ResetBits(GPIOD,GPIO_Pin_12);
//PD13
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOD, &GPIO_InitStructure);	 
GPIO_ResetBits(GPIOD,GPIO_Pin_13);
//PD14
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
GPIO_Init(GPIOD, &GPIO_InitStructure);	 
GPIO_ResetBits(GPIOD,GPIO_Pin_14);
  /****************���ûҶ�����********************/
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
//PC12
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;  
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOC, &GPIO_InitStructure);       
//PD2
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOD, &GPIO_InitStructure);       
//PD4
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;    
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOD, &GPIO_InitStructure);      
//PD3
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;    
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOD, &GPIO_InitStructure);       
//PD7
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;  
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
GPIO_Init(GPIOD, &GPIO_InitStructure); 
//PD14
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;  
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
GPIO_Init(GPIOD, &GPIO_InitStructure);  
//PE8
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOE, &GPIO_InitStructure);       
//PE9
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOE, &GPIO_InitStructure); 
//PF11
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOF, &GPIO_InitStructure);       
//PF12
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOF, &GPIO_InitStructure); 
//PF13
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOF, &GPIO_InitStructure); 	
//PF14
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOF, &GPIO_InitStructure); 
//PF15
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOF, &GPIO_InitStructure);
//PG0
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOG, &GPIO_InitStructure);
//PG9
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOG, &GPIO_InitStructure);
//PG10
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOG, &GPIO_InitStructure);
//PG11
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOG, &GPIO_InitStructure);
//PG12
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOG, &GPIO_InitStructure);




  /****************�����ᴥ��������********************/
//PF0
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOF, &GPIO_InitStructure);
//PF1
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOF, &GPIO_InitStructure);
//PF2
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOF, &GPIO_InitStructure);
//PF3
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOF, &GPIO_InitStructure);
 /****************���ü�������********************/
//PB14
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOB, &GPIO_InitStructure);
//PB12
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOB, &GPIO_InitStructure);
//PE14
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOE, &GPIO_InitStructure);
//PE12->11
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
GPIO_Init(GPIOE, &GPIO_InitStructure);
  /****************���õ��PWM���********************/
TIM4_PWM_Init(3999,0);
  /****************������ʱ��ʼ��********************/	
delay_init();	
  /****************����IIC��ʼ��********************/
IIC_Init();//SCL:PA6,SDA:PA7
/****************����MPU6050��ʼ��********************/
MPU_Init();
  /****************����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�********************/
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	
  /****************�����ⲿ�жϳ�ʼ��********************/
	EXTIX_Init();//key_a:PF0,key_b:PF1,key_c:PF2,key_d:PF3
	/****************����ADC�����ʼ��********************/
	ADC1_GPIO_Config();//PC0,PC1,PC2,PC3
	ADC1_Mode_Config();
	/****************����GY26��ʼ��********************/
	uart2_init(9600);
	/****************���÷�������ʼ��********************/
//PF5
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
GPIO_Init(GPIOF, &GPIO_InitStructure);	
GPIO_ResetBits(GPIOE,GPIO_Pin_5);
	/****************����LED��ʼ��********************/
//PE7
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOE, &GPIO_InitStructure);
//PG1
GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;   
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_Init(GPIOG, &GPIO_InitStructure);


}





/*******************************************************************************************************
Fuction:motor_allocation(char direction)
Dscription:����ǰ�����������������ƽ�
Input:
	@direction:ǰ������ F(oward) or B(ackward) or R(ight) or L(eft) or S(top) or P(ause)
Output:
  @Kl:����ƫ��ϵ��
  @Ka:����Ƕ�ƫ��ϵ��
  @state_motor:�������״̬��־λ
Return:
Other:kl,kaΪϵ����ֵ���ɳ�����
*******************************************************************************************************/

void motor_allocation(char direction)
{
switch(direction)
{
case 'F': 
    
			A1=1;A2=0;
			B1=1;B2=0;
			C1=1;C2=0;
			D1=1;D2=0;  
			Kl=kl;
			Ka=ka;
      state_motor=1;
      d_k=-1;
      break;
case 'B': 
			A1=0;A2=1;
			B1=0;B2=1;
			C1=0;C2=1;
			D1=0;D2=1;  
			Kl=kl;
			Ka=-ka;
      d_k=1;
			state_motor=2;
      break;
case 'R': 
				A1=1;A2=0;
			B1=0;B2=1;
			C1=1;C2=0;
			D1=0;D2=1;  
			state_motor=3;
      break;
case 'L': 
    A1=0;A2=1;
			B1=1;B2=0;
			C1=0;C2=1;
			D1=1;D2=0;  
			
			state_motor=4;
      break;
case 'S': 
			A1=0;A2=0;
			B1=0;B2=0;
			C1=0;C2=0;
			D1=0;D2=0;  
			state_motor=5;
      break;
case 'P': 
			A1=0;A2=0;
			B1=0;B2=0;
			C1=0;C2=0;
			D1=0;D2=0;  
      break;
}
}
/************************************end****************************************************************/









