
#include "GY26.h"
#include "myiic.h"

extern u32 angle;
/**
  * @brief  дGY26 CMD(1byte)
	* @param  Address:��ַ
  * @retval ��
  */
void Write_GY26_CMD(u8 Address)
{
	I2C_WriteByte(GY26_WriteAddress,GY26_CMD,Address);
}

/**
  * @brief  ��GY26(1byte)
	* @param  Address:��ַ
  * @retval ����
  */
uint8_t Read_GY26(u8 Address)
{
	return I2C_ReadByte(GY26_ReadAddress,Address);
}

/**
  * @brief  ��GY26�Ƕ�
	* @param  ��
  * @retval ֵ
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
//  * @brief  GY26���ô�ƫ��
//	* @param  CMP:��ƫ��
//  * @retval ��
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


//IICдһ���ֽ� 
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
u8 GY26_Write_Byte(u8 reg,u8 data) 				 
{ 
  IIC_Start(); 
	IIC_Send_Byte((GY26_SlaveAddress<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	IIC_Send_Byte(data);//��������
	if(IIC_Wait_Ack())	//�ȴ�ACK
	{
		IIC_Stop();	 
		return 1;		 
	}		 
    IIC_Stop();	 
	return 0;
}
//IIC��һ���ֽ� 
//reg:�Ĵ�����ַ 
//����ֵ:����������
u8 GY26_Read_Byte(u8 reg)
{
	u8 res;
    IIC_Start(); 
	IIC_Send_Byte((GY26_SlaveAddress<<1)|0);//����������ַ+д����	0x52
	IIC_Wait_Ack();		//�ȴ�Ӧ�� 
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte(GY26_SlaveAddress );//����������ַ+������	
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	res=IIC_Read_Byte(0);//��ȡ����,����nACK 
    IIC_Stop();			//����һ��ֹͣ���� 
	return res;		
}


//һ������˲�
//�˲�ϵ��Խ��ƽ�������Ȳ�
int Filter1( int filter_new,float K)//K 0~1
{
static int filter_old;
	filter_new=(int)filter_new*(1-K)+filter_old*K;
	filter_old=filter_new;
	return filter_old;
}

//ƽ��ֵ����
int Averagevalue(void)//ȡ20��ֵǰ��β�Ҫ
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


