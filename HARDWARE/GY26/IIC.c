/**
  ******************************************************************************
  * @file    IIC.c
  * @author  ChenQi
  * @version V1.0
  * @date    2016-03-02
  * @brief   IIC配置
  ******************************************************************************
  * @attention
  *
  * 平台STM32F103C8T6
	* 复用引脚：
	* PB6/I2C1_SCL PB7/I2C1_SDA
	* PB10/I2C2_SCL PB11/I2C2_SDA
  *
  ******************************************************************************
  */ 
	
#include "IIC.h"

/* STM32 I2C 快速模式 */
#define IIC_Speed              200000
/* 这个地址只要与外设的I2C器件地址不一样即可 */
#define IIC1_OWN_ADDRESS7      0X0A
/* 写入的目标地址 */
//#define TARGET_ADDRESS         \

/**
  * @brief  IIC1 I/O配置
  * @param  无
  * @retval 无
  */

void IIC_GPIO_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure; 

	/* 使能与 I2C1 有关的时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);  
    
  /* PB6-I2C1_SCL、PB7-I2C1_SDA*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;	       //开漏输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}
	
/**
  * @brief  IIC 工作模式配置
  * @param  无
  * @retval 无
  */

void IIC_Mode_Config(void)
{
  I2C_InitTypeDef  I2C_InitStructure;

  /* I2C模式设置为I2C模式 */
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	/* 高电平数据稳定，低电平数据变化 SCL 时钟线的占空比 */
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	/* 设置第一个设备自身地址：7位地址0x0A */
  I2C_InitStructure.I2C_OwnAddress1 =IIC1_OWN_ADDRESS7; 
	/* 使能应答 */
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable ;
	/* I2C应答7位地址 */
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	/* 通信速率：400000 */
  I2C_InitStructure.I2C_ClockSpeed = IIC_Speed;
  
	/* I2C1 初始化 */
  I2C_Init(I2C2, &I2C_InitStructure);
  
	/* 使能 I2C1 */
  I2C_Cmd(I2C2, ENABLE);   
}

/**
  * @brief   初始化IIC
  * @param   无
  * @retval  无
  */

void IIC_Init(void)
{
  IIC_GPIO_Config(); 
  IIC_Mode_Config();
}

/**
  * @brief   向IIC目标寄存器发送/写入数据
* @param   pBuffer:缓冲区指针,WriteAddr:写地址,NumByteToWrite:写的字节数,TARGET_ADDRESS:目标地址
  * @retval  无
  */

void IIC_Write(u8* pBuffer, u8 WriteAddr, u8 NumByteToWrite, u8 TARGET_ADDRESS)
{
	/* 检查IIC 直到不busy为止 */
  while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
    
  /* 产生起始位 */
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* 检查EV5并清除EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT)); 
  
  /* 发送写入的器件地址 */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
  
  /* 检查EV6并清除EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));  

  /* 发送写入地址 */    
  I2C_SendData(I2C2, WriteAddr);  

  /* 检查EV8并清除EV8 */
  while(! I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

  /* 循环发送数据直到NumByteToWrite=0 */
  while(NumByteToWrite--)  
  {
    /* 发送当前数据 */
    I2C_SendData(I2C2, *pBuffer); 

    /* 地址位+1 */
    pBuffer++; 
  
    /* 检查EV8并清除EV8 */
    while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  }

  /* 产生停止位 */
  I2C_GenerateSTOP(I2C2, ENABLE);
}

/**
  * @brief   向IIC写入一字节
  * @param   TARGET_ADDRESS:目标地址,write_address:写地址,byte:写的字节
  * @retval  无
  */

void I2C_WriteByte(u8 TARGET_ADDRESS,u8 write_address,u8 byte)
{
	/* 产生起始位 */
	I2C_GenerateSTART(I2C2,ENABLE);
	/* 检查EV5并清除EV5 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
	/* 发送写入的器件地址 */
	I2C_Send7bitAddress(I2C2,TARGET_ADDRESS,I2C_Direction_Transmitter);
	/* 检查EV6并清除EV6 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	/* 发送写入地址 */   
	I2C_SendData(I2C2, write_address);
	/* 检查EV8并清除EV8 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	/* 发送数据 */
	I2C_SendData(I2C2, byte);
	/* 检查EV8并清除EV8 */
	while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	/* 产生停止位 */
	I2C_GenerateSTOP(I2C2, ENABLE);
}

/**
  * @brief   从IIC读取数据
  * @param   pBuffer:存放从IIC读取的数据的缓冲区指针,ReadAddr:接收数据的目标器件的地址,NumByteToWrite:要从IIC读取的字节数
  * @retval  无
  */

void IIC_Read(u8* pBuffer, u8 ReadAddr, u16 NumByteToRead, u8 TARGET_ADDRESS)
{  
  /* 检查IIC 直到不busy为止 */
  while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
    
  /* 产生起始位 */
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* 检查EV5并清除EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));

  /* 发送器件地址 */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);

  /* 检查EV6并清除EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  
  /* Clear EV6 by setting again the PE bit */
  I2C_Cmd(I2C2, ENABLE);

  /* 发送读地址 */
  I2C_SendData(I2C2, ReadAddr);  

  /* 检查EV8并清除EV8 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  
  /* 开启信号 */  
  I2C_GenerateSTART(I2C2, ENABLE);
  
  /* 检查EV5并清除EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  
  /* 为读取而发送器件地址 */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Receiver);
  
  /* 检查EV6并清除EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
  
  /* 循环接收数据直到NumByteToRead=0 */
  while(NumByteToRead)  
  {
		/* 仅剩最后一位数据的时候 */
    if(NumByteToRead == 1)
    {
      /* 关闭应答 */
      I2C_AcknowledgeConfig(I2C2, DISABLE);
      
      /* 产生停止位 */
      I2C_GenerateSTOP(I2C2, ENABLE);
    }

    /* 检查EV7并清除EV7 */
    if(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))  
    {      
      /* 读取数据 */
      *pBuffer = I2C_ReceiveData(I2C2);

      /* 地址位+1 */
      pBuffer++; 
      
      /* 待读取字节数减一 */
      NumByteToRead--;        
    }   
  }

  /* 开启应答 */
  I2C_AcknowledgeConfig(I2C2, ENABLE);
}

/**
  * @brief   从IIC读取一个字节
  * @param   TARGET_ADDRESS:目标地址;read_address:接收数据的目标器件的地址
  * @retval  无
  */

u8 I2C_ReadByte(u8 TARGET_ADDRESS, u8 read_address)
{  
	u8 temp; 	

	/* 检查IIC 直到不busy为止 */
	while(I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY));
  /* 产生起始位 */
  I2C_GenerateSTART(I2C2, ENABLE);
  /* 检查EV5并清除EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  /* 发送器件地址 */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
	/* 检查EV6并清除EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
  /* 重新设置清除EV6 */
  I2C_Cmd(I2C2, ENABLE);
 	/* 发送读地址 */
  I2C_SendData(I2C2, read_address);  
	/* 检查EV8并清除EV8 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
  /* 开启信号 */  
  I2C_GenerateSTART(I2C2, ENABLE);
	/* 检查EV5并清除EV5 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT));
  /* 为读取而发送器件地址 */
  I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Receiver);
  /* 检查EV6并清除EV6 */
  while(!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
  /* 关闭应答 */ 
  I2C_AcknowledgeConfig(I2C2, DISABLE);
	/* 产生停止位 */
  I2C_GenerateSTOP(I2C2, ENABLE);
	/* 检查EV7并清除EV7 */
  while(!(I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED)));
	/* 接收数据 */    
  temp = I2C_ReceiveData(I2C2);
  /* 开启应答 */
	I2C_AcknowledgeConfig(I2C2, ENABLE);
	/* 返回读取值 */
	return temp;
}

/**
  * @brief  等待器件完成其内部操作
  * @param  无
  * @retval 无
  */

void IIC_WaitStandbyState(u8 TARGET_ADDRESS)
{
  vu16 SR1_Tmp = 0;

  do
  {
    /* 产生起始信号 */
    I2C_GenerateSTART(I2C2, ENABLE);
    /* 读取I2C SR1寄存器 */
    SR1_Tmp = I2C_ReadRegister(I2C2, I2C_Register_SR1);
    /* 发送器件清除地址事件 */
    I2C_Send7bitAddress(I2C2, TARGET_ADDRESS, I2C_Direction_Transmitter);
  }
	while(!(I2C_ReadRegister(I2C2, I2C_Register_SR1) & 0x0002));//等待完成操作跳出
  
  /* 清除AF标志位 */
  I2C_ClearFlag(I2C2, I2C_FLAG_AF);
  /* 产生停止位 */    
  I2C_GenerateSTOP(I2C2, ENABLE); 
}


/*********************************************END OF FILE**********************/
