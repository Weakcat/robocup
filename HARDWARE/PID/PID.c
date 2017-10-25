#include "PID.h"
#include "sys.h"
#include "seek.h"


/******************************************************************************************************/
PID pid_pwm;//pid_pwm_Init(int KP,int KI,int KD);pid_pwm_UsartCtr();pid_pwm_Calc(int NextPoint);
/******************************************************************************************************/

/*******************************************************************************************************
Fuction:pid_pwm_Init(int KP,int KI,int KD)
Dscription:�趨����pwm��pid��ʼ����
Input:
	@KP:�趨����pwm��pid��p�����ĳ�ʼֵ
	@KI:�趨����pwm��pid��i�����ĳ�ʼֵ
	@KI:�趨����pwm��pid��d�����ĳ�ʼֵ
Output:
  @pid_pwm.Kp:����pwm��pid��p��ֵ
  @pid_pwm.Ki:����pwm��pid��i��ֵ
  @pid_pwm.Kd:����pwm��pid��d��ֵ
Return:��
Other:�������ڴ������Ϊ�����͵���������������Ҳģ����pid��ֵ,������Ҫ���
*******************************************************************************************************/
void pid_pwm_Init(int KP,int KI,int KD)
{
  pid_pwm.Kp=KP;
  pid_pwm.Ki=KI;
  pid_pwm.Kd=KD;
	pid_pwm.Ek_1=0;
	pid_pwm.SEk=0;
	
}
/************************************end****************************************************************/



/*******************************************************************************************************
Fuction:pid_pwm_UsartCtr()
Dscription:ͨ���������ڽ��ջ�����������ݸı�pid����
Input:
	@USART_RX_BUF[1]:�ڼ�������
	@USART_RX_BUF[2]:����������ݵ�ֵ(Ĭ��0~255���ͣ�����APP����վ�����е�)
Output:
  @pid_pwm.Kp:��һ��pid��p��ֵ
  @pid_pwm.Ki:��һ��pid��i��ֵ
  @pid_pwm.Kd:��һ��pid��d��ֵ
Return:��
Other:�ȽϷ�����Σ����Ҫ�����pid�������ԼӸ���ڱ�־
*******************************************************************************************************/
void pid_pwm_UsartCtr()
{
	if(USART_RX_BUF[1]==0xf1)//��һ������״̬
	{
		printf("%lf", pid_pwm.Kp);
		pid_pwm.Kp = USART_RX_BUF[2];//�ı�Kp��ֵ
		return;
	}
  if(USART_RX_BUF[1]==0xf2)//�ڶ�������״̬
	{
		printf("%lf", pid_pwm.Ki);
		pid_pwm.Ki = USART_RX_BUF[2];//�ı�Ki��ֵ
		return;
	}
	if(USART_RX_BUF[1]==0xf3)//����������״̬
	{
	  printf("%lf", pid_pwm.Kd);
		pid_pwm.Kd = USART_RX_BUF[2];//�ı�Kd��ֵ
		return;
	}
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:pid_pwm_Calc(int NextPoint)
Dscription:λ��ʽPID�㷨
Input:
	@NextPoint:Ŀǰ����λ��
Output:
  @pid_pwm.OUT:pid������������ֵ
Return:pid_pwm.OUT
Other:����������������Ǹ�������̫���
*******************************************************************************************************/
int pid_pwm_Calc(int NextPoint)
{
		pid_pwm.Pv=NextPoint;
		pid_pwm.Ek=pid_pwm.Pv-pid_pwm.Sv;
		pid_pwm.SEk+=pid_pwm.Ek;            //��ʷƫ���ܺ�
		pid_pwm.Pout=pid_pwm.Kp*pid_pwm.Ek;      //�������
		pid_pwm.Iout=pid_pwm.Ki*pid_pwm.SEk;           //�������
		pid_pwm.Dout=pid_pwm.Kd*(pid_pwm.Ek-pid_pwm.Ek_1);    //΢�����
    pid_pwm.OUT=pid_pwm.Pout+ pid_pwm.Iout+ pid_pwm.Dout;
	  pid_pwm.Ek_1=pid_pwm.Ek;
	if(pid_pwm.OUT>=Umax)pid_pwm.OUT=Umax;
	if(pid_pwm.OUT<=Umin)pid_pwm.OUT=Umin;
	return pid_pwm.OUT;
}
/************************************end****************************************************************/



/*******************************************************************************************************/
PID pd_imcompD;//pd_imcompD_Init(int KP,int KA,int KD);pd_imcompD_UsartCtr();pd_imcompD_Calc(int NextPoint);
/*******************************************************************************************************/


/*******************************************************************************************************
Fuction:pd_imcompD_Init(int KP,int KA,int KD)
Dscription:�趨����pwm��pid��ʼ����
Input:
	@KP:�趨����pwm��pid��p�����ĳ�ʼֵ
	@KA:�趨����pwm��pid��a�����ĳ�ʼֵ(0~1)
	@KI:�趨����pwm��pid��d�����ĳ�ʼֵ
Output:
  @pid_pwm.Kp:����pwm��pid��p��ֵ
  @pid_pwm.Ka:����pwm��pid��a��ֵ
  @pid_pwm.Kd:����pwm��pid��d��ֵ
Return:��
Other:�������ڴ������Ϊ�����͵���������������Ҳģ����pid��ֵ,������Ҫ���
*******************************************************************************************************/
void pd_imcompD_Init(int KP,int KA,int KD)
{
  pd_imcompD.Kp=KP;
  pd_imcompD.Ka=KA;
  pd_imcompD.Kd=KD;
  pd_imcompD.OUT_l=0;
	pd_imcompD.Sv=SET_VALUE;
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:pd_imcompD_UsartCtr()
Dscription:ͨ���������ڽ��ջ�����������ݸı�pid����
Input:
	@USART_RX_BUF[1]:�ڼ�������
	@USART_RX_BUF[2]:����������ݵ�ֵ(Ĭ��0~255���ͣ�����APP����վ�����е�)
Output:
  @pd_imcompD.Kp:��һ��pid��p��ֵ
  @pd_imcompD.Ka:��һ��pid��a��ֵ���㵽��Χ��
  @pd_imcompD.Kd:��һ��pid��d��ֵ
Return:��
Other:�ȽϷ�����Σ����Ҫ�����pid�������ԼӸ���ڱ�־
*******************************************************************************************************/
void pd_imcompD_UsartCtr()
{
	if(USART_RX_BUF[1]==0xf1)//��һ������״̬
	{
		pd_imcompD.Kp = USART_RX_BUF[2]/10;//�ı�Kp��ֵ
		printf("%lf", pd_imcompD.Kp);
		return;
	}
  if(USART_RX_BUF[1]==0xf2)//�ڶ�������״̬
	{
		pd_imcompD.Ka = USART_RX_BUF[2]/2;//�ı�Ka��ֵ
		printf("%lf", pd_imcompD.Ka);
		return;
	}
	if(USART_RX_BUF[1]==0xf3)//����������״̬
	{
		pd_imcompD.Kd = USART_RX_BUF[2]/10;//�ı�Kd��ֵ
	  printf("%lf", pd_imcompD.Kd);
		return;
	}

}
/************************************end****************************************************************/



/*******************************************************************************************************
Fuction:pd_imcompD_Calc(int NextPoint)
Dscription:λ��ʽ����ȫ΢���㷨
Input:
	@NextPoint:Ŀǰ����λ��
Output:
  @pd_imcompD.OUT:����ȫpd������������ֵ
Return:pd_imcompD.OUT
Other:����ȫ΢�ֵ�PD�����������ɢ��PID���Ʒ�����
			�ڸ�������Ҫ��ϸߵ�С��ϵͳ�л��ֵ��ڲ��ʺ�ʹ�á�
			������λ����ɢ������£�����һ��PD���ڲ���õ��õ�Ч����
			����ģ�����������PD�������������һ�׹��Ի��ڣ���Ϊ����ȫ΢�ֵĿ��Ƶ�������
                                                              --��ѧ�����ܳ���P229
*******************************************************************************************************/
int pd_imcompD_Calc(int NextPoint)
{
//		pd_imcompD.Pv=NextPoint;
		pd_imcompD.Ek=NextPoint-pd_imcompD.Sv;
		pd_imcompD.Pout=pd_imcompD.Kp*pd_imcompD.Ek;      //�������
//pd_imcompD.Dout=pd_imcompD.Kd*(pd_imcompD.Ek-pd_imcompD.Ek_1);    //΢�����
	pd_imcompD.OUT=pd_imcompD.Pout;
	
//pd_imcompD.OUT=pd_imcompD.Ka*pd_imcompD.OUT_l-(1-pd_imcompD.Ka)*(pd_imcompD.Pout+ pd_imcompD.Dout);//��out-Ka*(out-out_l)�����
//pd_imcompD.OUT_l=pd_imcompD.OUT;

	if(pd_imcompD.OUT>=Umax)pd_imcompD.OUT=Umax;    //���ű���
	if(pd_imcompD.OUT<=Umin)pd_imcompD.OUT=Umin;  //���ű���
	return pd_imcompD.OUT;
}
/************************************end****************************************************************/














///*******************************************************************************************************/
//PID pd_imcompD;//pd_imcompD_Init(int KP,int KA,int KD);pd_imcompD_UsartCtr();pd_imcompD_Calc(int NextPoint);
///*******************************************************************************************************/


///*******************************************************************************************************
//Fuction:pd_imcompD_Init(int KP,int KA,int KD)
//Dscription:�趨����pwm��pid��ʼ����
//Input:
//	@KP:�趨����pwm��pid��p�����ĳ�ʼֵ
//	@KA:�趨����pwm��pid��a�����ĳ�ʼֵ(0~1)
//	@KI:�趨����pwm��pid��d�����ĳ�ʼֵ
//Output:
//  @pid_pwm.Kp:����pwm��pid��p��ֵ
//  @pid_pwm.Ka:����pwm��pid��a��ֵ
//  @pid_pwm.Kd:����pwm��pid��d��ֵ
//Return:��
//Other:�������ڴ������Ϊ�����͵���������������Ҳģ����pid��ֵ,������Ҫ���
//*******************************************************************************************************/
//void pd_imcompD_Init(int KP,int KA,int KD)
//{
//  pd_imcompD.Kp=KP;
//  pd_imcompD.Ka=KA;
//  pd_imcompD.Kd=KD;
//  pd_imcompD.OUT_l=0;
//}


///*******************************************************************************************************
//Fuction:pd_imcompD_UsartCtr()
//Dscription:ͨ���������ڽ��ջ�����������ݸı�pid����
//Input:
//	@USART_RX_BUF[1]:�ڼ�������
//	@USART_RX_BUF[2]:����������ݵ�ֵ(Ĭ��0~255���ͣ�����APP����վ�����е�)
//Output:
//  @pd_imcompD.Kp:��һ��pid��p��ֵ
//  @pd_imcompD.Ka:��һ��pid��a��ֵ���㵽��Χ��
//  @pd_imcompD.Kd:��һ��pid��d��ֵ
//Return:��
//Other:�ȽϷ�����Σ����Ҫ�����pid�������ԼӸ���ڱ�־
//*******************************************************************************************************/
//void pd_imcompD_UsartCtr()
//{
//	if(USART_RX_BUF[1]==0xf1)//��һ������״̬
//	{
//		printf("%lf", pd_imcompD.Kp);
//		pd_imcompD.Kp = USART_RX_BUF[2];//�ı�Kp��ֵ
//		return;
//	}
//  if(USART_RX_BUF[1]==0xf2)//�ڶ�������״̬
//	{
//		printf("%lf", pd_imcompD.Ka);
//		pd_imcompD.Ka = USART_RX_BUF[2]/255;//�ı�Ka��ֵ
//		return;
//	}
//	if(USART_RX_BUF[1]==0xf3)//����������״̬
//	{
//	  printf("%lf", pd_imcompD.Kd);
//		pd_imcompD.Kd = USART_RX_BUF[2];//�ı�Kd��ֵ
//		return;
//	}

//}


///*******************************************************************************************************
//Fuction:pd_imcompD_Calc(int NextPoint)
//Dscription:λ��ʽ����ȫ΢���㷨
//Input:
//	@NextPoint:Ŀǰ����λ��
//Output:
//  @pd_imcompD.OUT:����ȫpd������������ֵ
//Return:pd_imcompD.OUT
//Other:����ȫ΢�ֵ�PD�����������ɢ��PID���Ʒ�����
//			�ڸ�������Ҫ��ϸߵ�С��ϵͳ�л��ֵ��ڲ��ʺ�ʹ�á�
//			������λ����ɢ������£�����һ��PD���ڲ���õ��õ�Ч����
//			����ģ�����������PD�������������һ�׹��Ի��ڣ���Ϊ����ȫ΢�ֵĿ��Ƶ�������
//                                                              --��ѧ�����ܳ���P229
//*******************************************************************************************************/
//int pd_imcompD_Calc(int NextPoint)
//{
//		pd_imcompD.Pv=NextPoint;
//		pd_imcompD.Ek=pd_imcompD.Pv-pd_imcompD.Sv;
//		pd_imcompD.Pout=pd_imcompD.Kp*pd_imcompD.Ek;      //�������
//		pd_imcompD.Dout=pd_imcompD.Kd*(pd_imcompD.Ek-pd_imcompD.Ek_1);    //΢�����
//    pd_imcompD.OUT=pd_imcompD.Ka*pd_imcompD.OUT_l-(1-pd_imcompD.Ka)*(pd_imcompD.Pout+ pd_imcompD.Dout);//��out-Ka*(out-out_l)�����
//	  pd_imcompD.OUT_l=pd_imcompD.OUT;
//	if(pd_imcompD.OUT>=Umax)pd_imcompD.OUT=Umax;
//	if(pd_imcompD.OUT<=Umin)pd_imcompD.OUT=Umin;
//	return pd_imcompD.OUT;
//}
