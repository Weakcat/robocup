///////////////////////////////////
          tip：
参加比赛时候还不知道有github可以保存代码
现在就随便贴上去可以给大家做一下参考
路径规划没有什么好说的
主要是模块的使用和一些不入流的算法
希望能给大家一点帮助

////////////////////////////////


需要测试的参数:
kp(不同速度不同场地循迹中比例系数)ka(angle所占比重)speed
灰度阈值每到一个新场地要调整一次
上坡速度可能要慢一点
激光的角度和电位器可能要调整
红外测距会不会受板子材质的影响
油门保护容易搞事情，数字型的不统一也可能导致值变得很奇怪
子函数不要放循环


景点和上台也许有必要加上轻触开关的容错机制
指南针不能全信


板子激光E12有问题
油门保护！！！！

游历初赛：
ALLOCATION_Init();
pd_imcompD_Init(kp,ki,kd);
TIM3_PWM_Init(8999,159);
Action();
section_1();
section_2_9();
section_10();
420分
section_1();
section_2();
section_3();
state_door[0]=state_door[1]+2*state_door[2];
section_4(state_door[0]);
section_5_6_7();
section_8();
	if (state_door[1])state_door[0]=1;
	if (state_door[2])state_door[0]=2;
	if (state_door[4])state_door[0]=4;
section_9(state_door[0]);
319分
section_1();
section_2();
section_3();
state_door[0]=state_door[1]+2*state_door[2];
section_4(state_door[0]);
section_5_6_7_8();
if (state_door[1])state_door[0]=1;
if (state_door[2])state_door[0]=2;
if (state_door[4])state_door[0]=4;
section_9(state_door[0]);


寻宝路线
section_1_9_treasure();
section_10();
DUOJI_2(1);
delay_ms(500);
DUOJI_2(0);
delay_ms(500);
DUOJI_2(2);
delay_ms(500);
DUOJI_2(0);
	 
	 
DUOJI_3(2);
delay_ms(500);
DUOJI_3(0);
delay_ms(500);
DUOJI_3(1);
delay_ms(500);
DUOJI_3(0);

使用MPU6050前校准非常重要，并且颠簸也很难受
上台可以增加容错机制
平台转弯要慢
为了防止阳光对灰度的干扰，也许可以前面加个激光保护
如果岔道小，可以用干道循航，岔道大用转弯

要不要惯性滤波？0.6->>0
记得测静差
指南针转弯值会受到影响？没有校准
不能同时使用两个红外测距?王捷用惯性滤波，导致混乱
开始按键可以和暂停键合并
循迹标志位可以消抖，测距也可以消抖
ADC采集C0C1C2C3  vef引脚接3.3v作为比较电压，采集到的数据单位换算成cm要除以100
