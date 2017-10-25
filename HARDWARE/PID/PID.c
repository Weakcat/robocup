#include "PID.h"
#include "sys.h"
#include "seek.h"


/******************************************************************************************************/
PID pid_pwm;//pid_pwm_Init(int KP,int KI,int KD);pid_pwm_UsartCtr();pid_pwm_Calc(int NextPoint);
/******************************************************************************************************/

/*******************************************************************************************************
Fuction:pid_pwm_Init(int KP,int KI,int KD)
Dscription:设定控制pwm的pid初始参数
Input:
	@KP:设定控制pwm的pid中p参数的初始值
	@KI:设定控制pwm的pid中i参数的初始值
	@KI:设定控制pwm的pid中d参数的初始值
Output:
  @pid_pwm.Kp:控制pwm的pid中p的值
  @pid_pwm.Ki:控制pwm的pid中i的值
  @pid_pwm.Kd:控制pwm的pid中d的值
Return:无
Other:蓝牙串口传输回来为浮点型的整数，所以这里也模糊了pid的值,可能需要大改
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
Dscription:通过蓝牙串口接收滑条传输的数据改变pid参数
Input:
	@USART_RX_BUF[1]:第几条滑条
	@USART_RX_BUF[2]:传输回来数据的值(默认0~255整型，可在APP工作站设置中调)
Output:
  @pid_pwm.Kp:第一个pid中p的值
  @pid_pwm.Ki:第一个pid中i的值
  @pid_pwm.Kd:第一个pid中d的值
Return:无
Other:比较方便调参，如果要调多个pid参数可以加个入口标志
*******************************************************************************************************/
void pid_pwm_UsartCtr()
{
	if(USART_RX_BUF[1]==0xf1)//第一调滑条状态
	{
		printf("%lf", pid_pwm.Kp);
		pid_pwm.Kp = USART_RX_BUF[2];//改变Kp的值
		return;
	}
  if(USART_RX_BUF[1]==0xf2)//第二调滑条状态
	{
		printf("%lf", pid_pwm.Ki);
		pid_pwm.Ki = USART_RX_BUF[2];//改变Ki的值
		return;
	}
	if(USART_RX_BUF[1]==0xf3)//第三调滑条状态
	{
	  printf("%lf", pid_pwm.Kd);
		pid_pwm.Kd = USART_RX_BUF[2];//改变Kd的值
		return;
	}
}
/************************************end****************************************************************/


/*******************************************************************************************************
Fuction:pid_pwm_Calc(int NextPoint)
Dscription:位置式PID算法
Input:
	@NextPoint:目前所在位置
Output:
  @pid_pwm.OUT:pid计算完后输出的值
Return:pid_pwm.OUT
Other:输出的是正反馈还是负反馈不太清楚
*******************************************************************************************************/
int pid_pwm_Calc(int NextPoint)
{
		pid_pwm.Pv=NextPoint;
		pid_pwm.Ek=pid_pwm.Pv-pid_pwm.Sv;
		pid_pwm.SEk+=pid_pwm.Ek;            //历史偏差总和
		pid_pwm.Pout=pid_pwm.Kp*pid_pwm.Ek;      //比例输出
		pid_pwm.Iout=pid_pwm.Ki*pid_pwm.SEk;           //积分输出
		pid_pwm.Dout=pid_pwm.Kd*(pid_pwm.Ek-pid_pwm.Ek_1);    //微分输出
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
Dscription:设定控制pwm的pid初始参数
Input:
	@KP:设定控制pwm的pid中p参数的初始值
	@KA:设定控制pwm的pid中a参数的初始值(0~1)
	@KI:设定控制pwm的pid中d参数的初始值
Output:
  @pid_pwm.Kp:控制pwm的pid中p的值
  @pid_pwm.Ka:控制pwm的pid中a的值
  @pid_pwm.Kd:控制pwm的pid中d的值
Return:无
Other:蓝牙串口传输回来为浮点型的整数，所以这里也模糊了pid的值,可能需要大改
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
Dscription:通过蓝牙串口接收滑条传输的数据改变pid参数
Input:
	@USART_RX_BUF[1]:第几条滑条
	@USART_RX_BUF[2]:传输回来数据的值(默认0~255整型，可在APP工作站设置中调)
Output:
  @pd_imcompD.Kp:第一个pid中p的值
  @pd_imcompD.Ka:第一个pid中a的值换算到范围内
  @pd_imcompD.Kd:第一个pid中d的值
Return:无
Other:比较方便调参，如果要调多个pid参数可以加个入口标志
*******************************************************************************************************/
void pd_imcompD_UsartCtr()
{
	if(USART_RX_BUF[1]==0xf1)//第一调滑条状态
	{
		pd_imcompD.Kp = USART_RX_BUF[2]/10;//改变Kp的值
		printf("%lf", pd_imcompD.Kp);
		return;
	}
  if(USART_RX_BUF[1]==0xf2)//第二调滑条状态
	{
		pd_imcompD.Ka = USART_RX_BUF[2]/2;//改变Ka的值
		printf("%lf", pd_imcompD.Ka);
		return;
	}
	if(USART_RX_BUF[1]==0xf3)//第三调滑条状态
	{
		pd_imcompD.Kd = USART_RX_BUF[2]/10;//改变Kd的值
	  printf("%lf", pd_imcompD.Kd);
		return;
	}

}
/************************************end****************************************************************/



/*******************************************************************************************************
Fuction:pd_imcompD_Calc(int NextPoint)
Dscription:位置式不完全微分算法
Input:
	@NextPoint:目前所在位置
Output:
  @pd_imcompD.OUT:不完全pd计算完后输出的值
Return:pd_imcompD.OUT
Other:不完全微分的PD控制是最佳离散的PID控制方案。
			在跟随特性要求较高的小车系统中积分调节不适合使用。
			在输入位置离散的情况下，采用一般PD调节不会得到好的效果。
			参照模拟调节器，在PD调节器输出串联一阶惯性环节，即为不完全微分的控制调节器。
                                                              --《学做智能车》P229
*******************************************************************************************************/
int pd_imcompD_Calc(int NextPoint)
{
//		pd_imcompD.Pv=NextPoint;
		pd_imcompD.Ek=NextPoint-pd_imcompD.Sv;
		pd_imcompD.Pout=pd_imcompD.Kp*pd_imcompD.Ek;      //比例输出
//pd_imcompD.Dout=pd_imcompD.Kd*(pd_imcompD.Ek-pd_imcompD.Ek_1);    //微分输出
	pd_imcompD.OUT=pd_imcompD.Pout;
	
//pd_imcompD.OUT=pd_imcompD.Ka*pd_imcompD.OUT_l-(1-pd_imcompD.Ka)*(pd_imcompD.Pout+ pd_imcompD.Dout);//由out-Ka*(out-out_l)化简得
//pd_imcompD.OUT_l=pd_imcompD.OUT;

	if(pd_imcompD.OUT>=Umax)pd_imcompD.OUT=Umax;    //油门保护
	if(pd_imcompD.OUT<=Umin)pd_imcompD.OUT=Umin;  //油门保护
	return pd_imcompD.OUT;
}
/************************************end****************************************************************/














///*******************************************************************************************************/
//PID pd_imcompD;//pd_imcompD_Init(int KP,int KA,int KD);pd_imcompD_UsartCtr();pd_imcompD_Calc(int NextPoint);
///*******************************************************************************************************/


///*******************************************************************************************************
//Fuction:pd_imcompD_Init(int KP,int KA,int KD)
//Dscription:设定控制pwm的pid初始参数
//Input:
//	@KP:设定控制pwm的pid中p参数的初始值
//	@KA:设定控制pwm的pid中a参数的初始值(0~1)
//	@KI:设定控制pwm的pid中d参数的初始值
//Output:
//  @pid_pwm.Kp:控制pwm的pid中p的值
//  @pid_pwm.Ka:控制pwm的pid中a的值
//  @pid_pwm.Kd:控制pwm的pid中d的值
//Return:无
//Other:蓝牙串口传输回来为浮点型的整数，所以这里也模糊了pid的值,可能需要大改
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
//Dscription:通过蓝牙串口接收滑条传输的数据改变pid参数
//Input:
//	@USART_RX_BUF[1]:第几条滑条
//	@USART_RX_BUF[2]:传输回来数据的值(默认0~255整型，可在APP工作站设置中调)
//Output:
//  @pd_imcompD.Kp:第一个pid中p的值
//  @pd_imcompD.Ka:第一个pid中a的值换算到范围内
//  @pd_imcompD.Kd:第一个pid中d的值
//Return:无
//Other:比较方便调参，如果要调多个pid参数可以加个入口标志
//*******************************************************************************************************/
//void pd_imcompD_UsartCtr()
//{
//	if(USART_RX_BUF[1]==0xf1)//第一调滑条状态
//	{
//		printf("%lf", pd_imcompD.Kp);
//		pd_imcompD.Kp = USART_RX_BUF[2];//改变Kp的值
//		return;
//	}
//  if(USART_RX_BUF[1]==0xf2)//第二调滑条状态
//	{
//		printf("%lf", pd_imcompD.Ka);
//		pd_imcompD.Ka = USART_RX_BUF[2]/255;//改变Ka的值
//		return;
//	}
//	if(USART_RX_BUF[1]==0xf3)//第三调滑条状态
//	{
//	  printf("%lf", pd_imcompD.Kd);
//		pd_imcompD.Kd = USART_RX_BUF[2];//改变Kd的值
//		return;
//	}

//}


///*******************************************************************************************************
//Fuction:pd_imcompD_Calc(int NextPoint)
//Dscription:位置式不完全微分算法
//Input:
//	@NextPoint:目前所在位置
//Output:
//  @pd_imcompD.OUT:不完全pd计算完后输出的值
//Return:pd_imcompD.OUT
//Other:不完全微分的PD控制是最佳离散的PID控制方案。
//			在跟随特性要求较高的小车系统中积分调节不适合使用。
//			在输入位置离散的情况下，采用一般PD调节不会得到好的效果。
//			参照模拟调节器，在PD调节器输出串联一阶惯性环节，即为不完全微分的控制调节器。
//                                                              --《学做智能车》P229
//*******************************************************************************************************/
//int pd_imcompD_Calc(int NextPoint)
//{
//		pd_imcompD.Pv=NextPoint;
//		pd_imcompD.Ek=pd_imcompD.Pv-pd_imcompD.Sv;
//		pd_imcompD.Pout=pd_imcompD.Kp*pd_imcompD.Ek;      //比例输出
//		pd_imcompD.Dout=pd_imcompD.Kd*(pd_imcompD.Ek-pd_imcompD.Ek_1);    //微分输出
//    pd_imcompD.OUT=pd_imcompD.Ka*pd_imcompD.OUT_l-(1-pd_imcompD.Ka)*(pd_imcompD.Pout+ pd_imcompD.Dout);//由out-Ka*(out-out_l)化简得
//	  pd_imcompD.OUT_l=pd_imcompD.OUT;
//	if(pd_imcompD.OUT>=Umax)pd_imcompD.OUT=Umax;
//	if(pd_imcompD.OUT<=Umin)pd_imcompD.OUT=Umin;
//	return pd_imcompD.OUT;
//}
