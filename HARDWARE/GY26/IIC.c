/**
  ******************************************************************************
  * @file    IIC.c
  * @author  ChenQi
  * @version V1.0
  * @date    2016-03-02
  * @brief   IIC����
  ******************************************************************************
  * @attention
  *
  * ƽ̨STM32F103C8T6
	* �������ţ�
	* PB6/I2C1_SCL PB7/I2C1_SDA
	* PB10/I2C2_SCL PB11/I2C2_SDA
  *
  ******************************************************************************
  */ 
	
#include "IIC.h"

/* STM32 I2C ����ģʽ */
#define IIC_Speed              200000
/* �����ַֻҪ�������I2C������ַ��һ������ */
#define IIC1_OWN_ADDRESS7      0X0A
/* д���Ŀ���ַ */
//#define TARGET_ADDRESS         \

/**
  * @brief  IIC1 I/O����
  * @param  ��
  * @retval ��
  */

void IIC_GPIO_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure; 

	/* ʹ���� I2C1 �йص�ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);  
    
  /* PB6-I2C1_SCL��PB7-I2C1_SDA*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;	       //��©���
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}
	
/**
  * @brief  IIC ����ģʽ����
  * @param  ��
  * @retval ��
  */

void IIC_Mode_Config(void)
{
  I2C_InitTypeDef  I2C_InitStructure;

  /* I2Cģʽ����ΪI2Cģʽ */
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	/* �ߵ�ƽ�����ȶ����͵�ƽ���ݱ仯 SCL ʱ���ߵ�ռ�ձ� */
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	/* ���õ�һ���豸�����ַ��7λ��ַ0x0A */
  I2C_InitStructure.I2C_OwnAddress1 =IIC1_OWN_ADDRESS7; 
	/* ʹ��Ӧ�� */
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable ;
	/* I2CӦ��7λ��ַ */
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	/* ͨ�����ʣ�400000 */
  I2C_InitStructure.I2C_ClockSpeed = IIC_Speed;
  
	/* I2C1 ��ʼ�� */
  I2C_Init(I2C2, &I2C_InitStructure);
  
	/* ʹ�� I2C1 */
  I2C_Cmd(I2C2, ENABLE);   
}

/**
  * @brief   ��ʼ��IIC
  * @param   ��
  * @retval  ��
  */

void IIC_Init(void)
{
  IIC_GPIO_Config(); 
  IIC_Mode_Config();
}

/**
  * @brief   ��IICĿ��Ĵ�������/д������
* @param   pBuffer:������ָ��,WriteAddr:д��ַ,NumByteToWrite:д���ֽ���,TARGET_ADDRESS:Ŀ���ַ
  * @retval  ��
  */

void IIC_Write(u8* pBuffer, u8 WriteAddr, u8 NumByteToWrite, u8 TARGET_ADDRESS)
{
	/* ���IIC ֱ����busyΪֹ */
  while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
    
  /* ������ʼλ */
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* ���EV5�����EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT)); 
  
  /* ����д���������ַ */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
  
  /* ���EV6�����EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));  

  /* ����д���ַ */    
  I2C_SendData(I2C2, WriteAddr);  

  /* ���EV8�����EV8 */
  while(! I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  /* ѭ����������ֱ��NumByteToWrite=0 */
  while(NumByteToWrite--)  
  {
    /* ���͵�ǰ���� */
    I2C_SendData(I2C2, *pBuffer); 

    /* ��ַλ+1 */
    pBuffer++; 
  
    /* ���EV8�����EV8 */
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  }

  /* ����ֹͣλ */
  I2C_GenerateSTOP(I2C2, ENABLE);
}

/**
  * @brief   ��IICд��һ�ֽ�
  * @param   TARGET_ADDRESS:Ŀ���ַ,write_address:д��ַ,byte:д���ֽ�
  * @retval  ��
  */

void I2C_WriteByte(u8 TARGET_ADDRESS,u8 write_address,u8 byte)
{
	/* ������ʼλ */
	I2C_GenerateSTART(I2C2,ENABLE);
	/* ���EV5�����EV5 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
	/* ����д���������ַ */
	I2C_Send7bitAddress(I2C2,TARGET_ADDRESS,I2C_Direction_Transmitter);
	/* ���EV6�����EV6 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	/* ����д���ַ */   
	I2C_SendData(I2C2, write_address);
	/* ���EV8�����EV8 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	/* �������� */
	I2C_SendData(I2C2, byte);
	/* ���EV8�����EV8 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	/* ����ֹͣλ */
	I2C_GenerateSTOP(I2C2, ENABLE);
}

/**
  * @brief   ��IIC��ȡ����
  * @param   pBuffer:��Ŵ�IIC��ȡ�����ݵĻ�����ָ��,ReadAddr:�������ݵ�Ŀ�������ĵ�ַ,NumByteToWrite:Ҫ��IIC��ȡ���ֽ���
  * @retval  ��
  */

void IIC_Read(u8* pBuffer, u8 ReadAddr, u16 NumByteToRead, u8 TARGET_ADDRESS)
{  
  /* ���IIC ֱ����busyΪֹ */
  while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
    
  /* ������ʼλ */
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* ���EV5�����EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));

  /* ����������ַ */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);

  /* ���EV6�����EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  
  /* Clear EV6 by setting again the PE bit */
  I2C_Cmd(I2C2, ENABLE);

  /* ���Ͷ���ַ */
  I2C_SendData(I2C2, ReadAddr);  

  /* ���EV8�����EV8 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  
  /* �����ź� */  
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* ���EV5�����EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  
  /* Ϊ��ȡ������������ַ */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Receiver);
  
  /* ���EV6�����EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
  
  /* ѭ����������ֱ��NumByteToRead=0 */
  while(NumByteToRead)  
  {
		/* ��ʣ���һλ���ݵ�ʱ�� */
    if(NumByteToRead == 1)
    {
      /* �ر�Ӧ�� */
      I2C_AcknowledgeConfig(I2C2, DISABLE);
      
      /* ����ֹͣλ */
      I2C_GenerateSTOP(I2C2, ENABLE);
    }

    /* ���EV7�����EV7 */
    if(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))  
    {      
      /* ��ȡ���� */
      *pBuffer = I2C_ReceiveData(I2C2);

      /* ��ַλ+1 */
      pBuffer++; 
      
      /* ����ȡ�ֽ�����һ */
      NumByteToRead--;        
    }   
  }

  /* ����Ӧ�� */
  I2C_AcknowledgeConfig(I2C2, ENABLE);
}

/**
  * @brief   ��IIC��ȡһ���ֽ�
  * @param   TARGET_ADDRESS:Ŀ���ַ;read_address:�������ݵ�Ŀ�������ĵ�ַ
  * @retval  ��
  */

u8 I2C_ReadByte(u8 TARGET_ADDRESS, u8 read_address)
{  
	u8 temp; 	

	/* ���IIC ֱ����busyΪֹ */
	while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
  /* ������ʼλ */
  I2C_GenerateSTART(I2C2, ENABLE);
  /* ���EV5�����EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  /* ����������ַ */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
	/* ���EV6�����EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  /* �����������EV6 */
  I2C_Cmd(I2C2, ENABLE);
 	/* ���Ͷ���ַ */
  I2C_SendData(I2C2, read_address);  
	/* ���EV8�����EV8 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  /* �����ź� */  
  I2C_GenerateSTART(I2C2, ENABLE);
	/* ���EV5�����EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  /* Ϊ��ȡ������������ַ */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Receiver);
  /* ���EV6�����EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
  /* �ر�Ӧ�� */ 
  I2C_AcknowledgeConfig(I2C2, DISABLE);
	/* ����ֹͣλ */
  I2C_GenerateSTOP(I2C2, ENABLE);
	/* ���EV7�����EV7 */
  while(!(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED)));
	/* �������� */    
  temp = I2C_ReceiveData(I2C2);
  /* ����Ӧ�� */
	I2C_AcknowledgeConfig(I2C2, ENABLE);
	/* ���ض�ȡֵ */
	return temp;
}

/**
  * @brief  �ȴ�����������ڲ�����
  * @param  ��
  * @retval ��
  */

void IIC_WaitStandbyState(u8 TARGET_ADDRESS)
{
  vu16 SR1_Tmp = 0;

  do
  {
    /* ������ʼ�ź� */
    I2C_GenerateSTART(I2C2, ENABLE);
    /* ��ȡI2C SR1�Ĵ��� */
    SR1_Tmp = I2C_ReadRegister(I2C2, I2C_Register_SR1);
    /* �������������ַ�¼� */
    I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
  }
	while(!(I2C_ReadRegister(I2C2, I2C_Register_SR1) & 0x0002));//�ȴ���ɲ�������
  
  /* ���AF��־λ */
  I2C_ClearFlag(I2C2, I2C_FLAG_AF);
  /* ����ֹͣλ */    
  I2C_GenerateSTOP(I2C2, ENABLE); 
}


/*********************************************END OF FILE**********************/
