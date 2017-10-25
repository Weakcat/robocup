#include "sys.h"
#include "usart2.h"
#include "timer.h"
#include "string.h"

 u8 GY26_Flag = 0,GY26_state=1;
 float GY26_angle;
 extern int    my_angle;
u16 GY26_receiveCount=0;       //����״̬���
     
 
#if EN_USART2_RX     	
u8 USART2_RX_BUF[200];     //���ջ���,���USART_REC_LEN���ֽ�.
u16 USART2_RX_STA=0;       //����״̬���	  
  

/******************************************/
void usart2_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)==RESET); //????,??????   
	USART_SendData(USART2,c);  
} 
//void My_send_data(u16 show_data, u8 para)
//{
//	u8 tbuf[8]; 
//	u8 i;
//	para |= 0xC0;//
//	
//	tbuf[0] = 0XA5;
//	tbuf[1] = 0X5A;
//	tbuf[2] = 0X06;
//	tbuf[3] = para;
//	tbuf[4] = (show_data>>8)&0XFF;
//	tbuf[5] = show_data&0XFF; 
//	tbuf[6] = tbuf[2] + tbuf[3] + tbuf[4];
//	tbuf[7] = 0XAA;

//	for(i = 0; i < 8; i++)
//	{
//		usart1_send_char(tbuf[i]);
//	}
//}
//	void My_send_state(u16 show_state, u8 para)
//{
//	u8 tbuf[7]; 
//	u8 i;
//	para |= 0xE0;//??x
//	
//	tbuf[0] = 0XA5;
//	tbuf[1] = 0X5A;
//	tbuf[2] = 0X05;
//	tbuf[3] = para;
//	tbuf[4] = show_state;
//	tbuf[5] = tbuf[2] + tbuf[3] + tbuf[4];
//	tbuf[6] = 0XAA;

//	for(i = 0; i < 8; i++)
//	{
//		usart2_send_char(tbuf[i]);
//	}
//}
	
void uart2_init(u32 bound){
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);	//ʹ��USART1��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_USART2,ENABLE);
	//USART1_TX   GPIOD.5
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //PD.2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOA.9
   
  //USART1_RX	  GPIOD.6��ʼ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//PD6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIOA.3  

  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
   //USART ��ʼ������

	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

  USART_Init(USART2, &USART_InitStructure); //��ʼ������2
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
  USART_Cmd(USART2, ENABLE);                    //ʹ�ܴ���2

}


void USART2_IRQHandler(void)                	//����1�жϷ������
	{
	u8 Res;	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) 
		{
		Res =USART_ReceiveData(USART2);	//��ȡ���յ�������
  if (Res == 0x0D && GY26_Flag == 0)
			{
				GY26_Flag = 1;
				return;
			}
			if(GY26_Flag != 2)
			{
				if(GY26_Flag == 1 && Res == 0x0A)
				{
					GY26_Flag = 2;
					return;
				}
				else
				{
					GY26_Flag = 0;
					return;
				}
			}
			if(GY26_Flag == 2)
			{
				USART_RX_BUF[GY26_receiveCount]=Res;
				GY26_receiveCount++;
			}
			if(GY26_receiveCount == 6)
			{
				GY26_angle=(USART_RX_BUF[0]-30)*100+
				(USART_RX_BUF[1]-30)*10+
				(USART_RX_BUF[2]-30)*1+
				(USART_RX_BUF[4]-30)*0.1-2000;
				my_angle=(USART_RX_BUF[0]-30)*100+
				(USART_RX_BUF[1]-30)*10
				+(USART_RX_BUF[2]-30)*1
				-2000;
				if ((USART_RX_BUF[0]==0x30)
					&&(USART_RX_BUF[1]==0x30)
				  &&(USART_RX_BUF[2]==0x30)
				  &&(USART_RX_BUF[4]==0x30)
				  &&(USART_RX_BUF[5]==0x05))GY26_state=0;
				GY26_receiveCount = 0;
				GY26_Flag = 0;

			}
	 }
} 
#endif	

