#include "VL53L0.h"
#include "myiic.h"
#include "delay.h"

uint16_t bswap(u8 b[])
{
	uint16_t val = ((b[0]<< 8) & b[1]);
	return val;
}

uint16_t VL53L0X_decode_vcsel_period(short vcsel_period_reg)
{
	uint16_t vcsel_period_pclks = (vcsel_period_reg + 1) <<1;
	return vcsel_period_pclks;
}

uint16_t makeuint16(int lsb, int msb)
{
    return ((msb & 0xFF) << 8) | (lsb & 0xFF);
}

//IIC����д
//addr:������ַ 
//reg:�Ĵ�����ַ
//len:д�볤��
//buf:������
//����ֵ:0,����
//    ����,�������
u8 VL53L0X_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
    IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte(buf[i]);	//��������
		if(IIC_Wait_Ack())		//�ȴ�ACK
		{
			IIC_Stop();	 
			return 1;		 
		}		
	}    
    IIC_Stop();	 
	return 0;	
} 
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
u8 VL53L0X_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//����������ַ+������	
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1)*buf=IIC_Read_Byte(0);//������,����nACK 
		else *buf=IIC_Read_Byte(1);		//������,����ACK  
		len--;
		buf++; 
	}    
    IIC_Stop();	//����һ��ֹͣ���� 
	return 0;	
}
//IICдһ���ֽ� 
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
u8 VL53L0X_Write_Byte(u8 reg,u8 data) 				 
{ 
  IIC_Start(); 
	IIC_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	
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
u8 VL53L0X_Read_Byte(u8 reg)
{
	u8 res;
    IIC_Start(); 
	IIC_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	0x52
	//IIC_Send_Byte(0x52);//����������ַ+д����	
	IIC_Wait_Ack();		//�ȴ�Ӧ�� 
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte(0x53 );//����������ַ+������	
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	res=IIC_Read_Byte(0);//��ȡ����,����nACK 
    IIC_Stop();			//����һ��ֹͣ���� 
	return res;		
}

//while(1)
//	{ 
//		 VL53L0X_Write_Byte(VL53L0X_REG_SYSRANGE_START, 0x01); 
//		 while(cnt < 100)
//		 {delay_ms(100);
//				val = VL53L0X_Read_Byte(VL53L0X_REG_RESULT_RANGE_STATUS);
//				if( val & 0x01) break;
//				cnt++;
//		 }
//		 VL53L0X_Read_Len(VL53L0X_Add, 0x14 , 12, gbuf);
//		 count[2] = makeuint16(gbuf[11], gbuf[10]);
//		 
//		 OLED_Clear();
//		 OLED_ShowNum(4,2,count[2],3,16);
//		 //if ((count[2]<100)&&(count[2]>90))break;
//	}


  
int VL53L0_Dis(void)
 {	
	    u8 val = 0;
	    u8 gbuf[16];
      uint32_t cnt = 0;
	  int dis,dis_l=1200;
		 VL53L0X_Write_Byte(0x00, 0x31); 
		 while(cnt < 10000)
		 {
				val = VL53L0X_Read_Byte(VL53L0X_REG_RESULT_RANGE_STATUS);
				if( val & 0x01) break;
				cnt++;
		 }
		 VL53L0X_Read_Len(VL53L0X_Add, 0x14 , 12, gbuf);
		 
		 dis=makeuint16(gbuf[11], gbuf[10]);
		 return dis;
		 
		
 }
 
 
 
 
 
int GY26_Angle(void)
 {	
	 	unsigned char H,L,i;
	unsigned int  cmp_data;
	  	                      
	 i=VL53L0X_Write_Byte(0x00, 0x31);       
                       
           delay_ms(50);      
	   if(i==0){
	     H=VL53L0X_Read_Byte(0x01);           
	     L=VL53L0X_Read_Byte(0x02);        
		 cmp_data=H;
		 cmp_data<<=8;
		 cmp_data+=L;  
	 

	  
		 return  cmp_data;
		
		 
		 
	 }
 }


		     

