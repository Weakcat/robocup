
#include "GY26.h"
#include "myiic.h"

extern u32 angle;
/**
  * @brief  写GY26 CMD(1byte)
	* @param  Address:地址
  * @retval 无
  */
void Write_GY26_CMD(u8 Address)
{
	I2C_WriteByte(GY26_WriteAddress,GY26_CMD,Address);
}

/**
  * @brief  读GY26(1byte)
	* @param  Address:地址
  * @retval 数据
  */
uint8_t Read_GY26(u8 Address)
{
	return I2C_ReadByte(GY26_ReadAddress,Address);
}

/**
  * @brief  读GY26角度
	* @param  无
  * @retval 值
  */
void Read_GY26_Angle(void)
{
//	uint8_t buf[2];
//	Write_GY26_CMD(GY26_Angle);
//Delay_us(55);
//	IIC_Read(buf, 0x01, 2, GY26_ReadAddress);
//	return (buf[0] << 8 | buf[1]);
	
	I2C_WriteByte(0xfe,0x00,0x31);
		
	Delay_us(55);
angle=I2C_ReadByte(GY26_ReadAddress ,0x01);

	
angle<<=8;
angle|=I2C_ReadByte(0xfe+1,0x02);
	angle=Filter1(angle,0.1);

}


///**
//  * @brief  GY26设置磁偏角
//	* @param  CMP:磁偏角
//  * @retval 无
//  */
//void Set_GY26_CMP_OFFS(uint16_t CMP)
//{
//	I2C_WriteByte(GY26_WriteAddress,0x03,(uint8_t)(CMP>>8));
//	I2C_WriteByte(GY26_WriteAddress,0x04,(uint8_t)CMP);
//	
//	
//	
//	
//}


//IIC写一个字节 
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
u8 GY26_Write_Byte(u8 reg,u8 data) 				 
{ 
  IIC_Start(); 
	IIC_Send_Byte((GY26_SlaveAddress<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack())	//等待应答
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答 
	IIC_Send_Byte(data);//发送数据
	if(IIC_Wait_Ack())	//等待ACK
	{
		IIC_Stop();	 
		return 1;		 
	}		 
    IIC_Stop();	 
	return 0;
}
//IIC读一个字节 
//reg:寄存器地址 
//返回值:读到的数据
u8 GY26_Read_Byte(u8 reg)
{
	u8 res;
    IIC_Start(); 
	IIC_Send_Byte((GY26_SlaveAddress<<1)|0);//发送器件地址+写命令	0x52
	IIC_Wait_Ack();		//等待应答 
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答
    IIC_Start();
	IIC_Send_Byte(GY26_SlaveAddress );//发送器件地址+读命令	
    IIC_Wait_Ack();		//等待应答 
	res=IIC_Read_Byte(0);//读取数据,发送nACK 
    IIC_Stop();			//产生一个停止条件 
	return res;		
}


//一介惯性滤波
//滤波系数越大平稳灵敏度差
int Filter1( int filter_new,float K)//K 0~1
{
static int filter_old;
	filter_new=(int)filter_new*(1-K)+filter_old*K;
	filter_old=filter_new;
	return filter_old;
}

//平均值函数
int Averagevalue(void)//取20次值前五次不要
{
int times=0,averagevalue=0;
	for(;times<300;times++)
	{
		Read_GY26_Angle();
		Delay_us(20);
		if(times>50)
			averagevalue+=angle;
	}
	averagevalue=(float)averagevalue/250 +0.5;
	return averagevalue;
}	


