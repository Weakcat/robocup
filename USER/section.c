#include "allocation.h"
extern u8 state_treasure[9];












void section_1(void)
{
Plot_down('F',-10,-10);
  //下起止区
tracking('F','M',1000,6,1);//第一道斜线
tracking('F','M',1000,4,1);//第二道斜线
Long_Bridge();
	//长桥结束
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);	
Plot_up('F',10,1);  
Treasure(0);
Plot_turn(0);
}












void section_2(void)
{
              Plot_down('F',-10,-10); 
  //二号平台结束	
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',1000,1,1);//第一条斜线
tracking('B','M',700,7,1); //第一条斜线
    Turn_Angle('R','a',1800);
	//二号平台之后第一个45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//二号平台之后第二个45
tracking('F','R',1200,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
	//二号平台之后第三个45
tracking('B','R',1000,6,1);
	            Door(2);
	            //二号门探门
tracking('F','M',1200,6,1);
tracking('F','M',700,3,1);
Go_Stright('F',300);
while(!mild_R);
    Turn_Angle('L','b',1800);
		//二号门之后第一个45
	            Door(1);
							//一号门探门
tracking('F','M',1200,6,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);	
while(!mild_R);
    Turn_Angle('R','a',1400);	
    //一号门之后第一个45
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',700,4,1);//第一条斜线
tracking('B','M',500,1,1);//第一条斜线
		Turn_Angle('L','a',2000);	
		//一号门之后第二个45
tracking('F','L',700,5,1);//过渡		
	            Feature_Sport('F');
              //普陀山							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //普陀山之后第一个45		
                Plot_up('F',10,2); 
					Treasure(0);
                Plot_turn(0);	              
                Plot_down('F',-10,-10);
                //4号平台结束								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //极限加速区
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(0);	              


}
void section_2_9(void)
{
              Plot_down('F',-10,-10); 
  //二号平台结束	
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',1000,1,1);//第一条斜线
tracking('B','M',700,7,1); //第一条斜线
    Turn_Angle('R','a',1800);
	//二号平台之后第一个45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//二号平台之后第二个45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',700,4,1);//第一条斜线
tracking('B','M',500,1,1);//第一条斜线
		Turn_Angle('L','a',2000);	
		//一号门之后第二个45
tracking('F','L',700,5,1);//过渡		
	            Feature_Sport('F');
              //普陀山							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //普陀山之后第一个45		
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4号平台结束								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //极限加速区
                Plot_up('F',10,2);
Treasure(0);								
                Plot_turn(state_treasure[3]);	              
              	Plot_down('F',-10,-10);
	             //3号平台结束
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //三号平台之后第一个45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //龙王山
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
    //龙王山之后第一个45	
							 
tracking('F','M',1000,5,1);
tracking('F','M',1500,6,1);	 
tracking('F','R',700,0,1);
tracking('F','R',500,0,1);
tracking('B','R',500,2,1);					 
							 
}

void section_3(void)
{
             	Plot_down('F',-10,-10);
	             //3号平台结束
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //三号平台之后第一个45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //龙王山
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
//    Turn_Angle('L','b',2000);
//    //龙王山之后第一个45	
    Turn_Angle('L','b',2000);  	
    //龙王山之后第一个90

	
	
}
void section_4(u8 door)
{
	switch (door)
 {
	case 0:
   tracking('B','M',700,6,1);
   tracking('F','M',500,1,1);
		Turn_Angle('L','b',2000);
	            Door(4);
   tracking('B','M',1000,5,1);
   tracking('B','M',300,0,1);
motor_allocation('S');
delay_ms(500);
		 Turn_Angle('R','b',2000);
   tracking('F','L',1000,7,1);
   tracking('F','M',1500,6,1);
	break;
	case 2:
tracking('F','R',1200,6,1);
tracking('F','R',1000,7,1);
tracking('F','M',500,5,1);
    Turn_Angle('L','b',2000);
tracking('B','R',1000,6,1);
tracking('B','M',1500,6,1);
tracking('B','M',1000,4,1);
Go_Stright('B',300);
while(!ahead_8);
    Turn_Angle('R','a',2000);
tracking('F','M',1000,7,1);
tracking('F','M',1500,6,1);
	break;
	default:
	tracking('F','M',1000,5,1);
	tracking('F','R',1500,6,2);
	tracking('F','R',1000,7,1);
	tracking('F','M',700,5,2);
	tracking('B','M',500,1,1);
motor_allocation('S');
delay_ms(500);
	    Turn_Angle('R','a',1800);
	tracking('F','M',1000,7,1);
	tracking('F','M',300,0,1);
motor_allocation('S');
delay_ms(500);
	    Turn_Angle('L','a',1800);
	break;
 }
tracking('F','M',1200,5,1);
	               Plot_up('F',10,2);
 Treasure(0);
                 Plot_turn(state_treasure[5]);	
}



void section_5(void)
{
                 Plot_down('F',-10,-10);
	//5号平台结束
tracking('F','M',1500,6,1);//第一条曲线
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
motor_allocation('S');
delay_ms(500);
Turn_Angle('L','a',1800);
	//5号平台之后第一个90
//tracking('F','M',500,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('R','a',1800);
  //5号平台之后第二个90
tracking('F','M',500,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
Turn_Angle('R','a',1800);
	//5号平台之后第三个90
                Feature_Sport('F');
								//牛首山
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //牛首山之后第一个90
tracking('F','M',1000,6,1);
//                Hill('F');
								//山丘
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //山丘之后第一个类直角
tracking('F','M',700,9,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //山丘之后第一个90
	              Seesaw();
								//跷跷板
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //跷跷板之后第一个90
//tracking('F','M',500,8,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //跷跷板之后第二个90
tracking('F','M',500,1,2);
tracking('F','M',500,0,2);
tracking('F','M',500,1,2);
tracking('F','M',500,0,2);
  //上第二大斜坡连续减震带
                Plot_up('F',10,1);  
Treasure(0);
                Plot_turn(0);	
}



void section_6(void)
{
                Plot_down('F',-10,-10);
tracking('F','M',700,1,2);
//tracking('F','M',700,0,2);
tracking('F','M',700,1,2);
//tracking('F','M',700,0,2);
	//下第二大坡连续减震带
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('L','b',2000);
	//下第二大坡第一个90
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('R','a',2000);
	//下第二大坡第二个90
	Slope(-1,10,-5);
  //斜坡
tracking('F','L',500,3,1);
                Plot_Plus_up('F',15,3);  
Treasure(0);
                Plot_turn(state_treasure[8]);
}




void section_7(void)
{
                Plot_Plus_down('F',-15,-15);
	              //珠峰结束
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//珠峰下来第一个45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//珠峰下来第二个45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//珠峰下来第一个90
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//珠峰下来第二个90
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1700);
	//珠峰下来第三个90
	            Feature_Sport('F');
							//千岛湖
}


void section_8(void)
{ 
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','b',1800);
	//千岛湖之后第一个90
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_L);
  Turn_Angle('L','a',1800);
	//千岛湖之后第二个90
tracking('F','M',500,5,1);
tracking('F','M',700,6,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('L','b',1800);
	//千岛湖之后第三个90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
delay_ms(500);
  Turn_Angle('L','a',1800);
	//千岛湖之后第四个90
	           Feature_Sport('F');
	           //太白湖
tracking('B','M',500,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//太白湖之后第一个90
tracking('F','M',1000,7,1);
//tracking('F','M',500,3,1);
tracking('F','M',500,1,1);
}



void section_9(u8 door)
{ 
	switch (door)
 {
	case 1:
		delay_ms(500);
		  Turn_Angle('L','b',2000);
		tracking('B','L',500,2,1);
		tracking('B','M',1000,6,1);
	  tracking('B','M',1500,2,1);
	  tracking('B','M',1000,5,1);
	  tracking('B','M',300,0,1);
		  Turn_Angle('L','b',2000);
motor_allocation('S');
delay_ms(500);
	  tracking('B','L',700,3,1);
		tracking('B','M',1000,5,1);
		tracking('B','M',500,4,1);
	  Go_Stright('B',300);
    while(!mild_L);
motor_allocation('S');
delay_ms(500);
		  Turn_Angle('L','b',2000);
		tracking('B','L',1000,4,1);
		tracking('B','M',300,2,1);
	break;
	case 2:
		delay_ms(500);
		  Turn_Angle('R','a',1800);
		tracking('F','L',1000,2,1);
		tracking('F','M',1000,6,1);
		tracking('F','M',700,2,1);
	  Go_Stright('F',500);
    while(!mild_L);
	    Turn_Angle('R','b',2000);
		tracking('B','M',1000,4,1);
		tracking('B','M',300,2,1);
	break;
	case 3:break;
	case 4:
		tracking('F','M',1000,6,1);
	  tracking('F','M',500,2,1);
	  Go_Stright('F',300);
    while(!mild_L);
	
      Turn_Angle('R','a',1800);
	
    tracking('F','L',700,5,1);
    tracking('F','M',1000,6,1);
	  tracking('F','R',700,0,1);
    tracking('F','R',500,0,1);
    tracking('B','R',500,2,1);
	break;
 }
}

void section_5_6_7_8(void)
{
                 Plot_down('F',-10,-10);
	//5号平台结束
tracking('F','M',1500,6,1);//第一条曲线
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5号平台之后第一个90
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','b',1800);
  //5号平台之后第二个90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5号平台之后第三个90
                Feature_Sport('F');
								//牛首山
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('L','a',1800);
  //牛首山之后第一个90
tracking('F','M',1000,7,2);
tracking('F','M',700,3,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',1800);
tracking('B','M',700,5,1);
tracking('B','M',300,1,1);
Turn_Angle('R','a',1800);
	           Feature_Sport('F');
	           //太白湖
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//太白湖之后第一个90
tracking('F','M',1000,7,1);
tracking('F','M',700,3,1);	
tracking('F','M',300,1,1);	
}
void section_5_6_7(void)
{
                 Plot_down('F',-10,-10);
	//5号平台结束
tracking('F','M',1500,6,1);//第一条曲线
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5号平台之后第一个90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
	while(!mild_R);
	motor_allocation('S');
  delay_ms(500);
Turn_Angle('R','b',1800);
  //5号平台之后第二个90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5号平台之后第三个90
                Feature_Sport('F');
								//牛首山
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //牛首山之后第一个90
tracking('F','M',1000,6,1);
//                Hill('F');
								//山丘
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',2000);
  //山丘之后第一个类直角
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //山丘之后第一个90
tracking('F','M',500,5,1);
	              Seesaw();
								//跷跷板
tracking('F','M',1000,6,1);
tracking('F','M',1000,0,1);

                Slope(-1,10,5);
  //斜坡
tracking('F','M',1000,3,1);
                Plot_Plus_up('F',15,3); 
Treasure(0);								
                Plot_turn(state_treasure[8]);
                Plot_Plus_down('F',-15,-15);

//珠峰结束
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//珠峰下来第一个45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//珠峰下来第二个45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','b',1800);
	//珠峰下来第一个90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
while(!mild_L);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','a',1800);
	//珠峰下来第二个90
tracking('F','M',500,5,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('R','a',1700);
	//珠峰下来第三个90
	            Feature_Sport('F');
							//千岛湖


}

void section_10(void)
{
    Turn_Angle('L','a',2000);
tracking('F','L',700,5,1);
//tracking('F','M',700,1,2);
tracking('F','M',700,0,2);
tracking('F','M',700,6,1);
tracking('F','M',700,2,1);
	  Go_Stright('F',300);
    while(!back_1);
    Turn_Angle('R','b',1800);
                 Plot_up('F',10,1);                 
motor_allocation('S');
                 Plot_turn(0);	 
}




















void section_1_9_treasure(void)
{
	
	Plot_down('F',-10,-10);
  //下起止区
tracking('F','M',1000,6,1);//第一道斜线
tracking('F','M',1000,4,1);//第二道斜线
Long_Bridge();
	//长桥结束
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);	
	
              Plot_up('F',10,1);  

              Plot_turn(0);
              Plot_down('F',-10,-10); 
  //二号平台结束	
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',1000,1,1);//第一条斜线
tracking('B','M',700,7,1); //第一条斜线
    Turn_Angle('R','a',1800);
	//二号平台之后第一个45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//二号平台之后第二个45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',700,4,1);//第一条斜线
tracking('B','M',500,1,1);//第一条斜线
		Turn_Angle('L','a',2000);	
		//一号门之后第二个45
tracking('F','L',700,5,1);//过渡		
	            Feature_Sport('F');
              //普陀山							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //普陀山之后第一个45		
                Plot_up('F',10,2);
	  							
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4号平台结束								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //极限加速区
                Plot_up('F',10,2); 

                Plot_turn(state_treasure[3]);	              
      	Plot_down('F',-10,-10);
	             //3号平台结束
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //三号平台之后第一个45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //龙王山
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
//    Turn_Angle('L','b',2000);
//    //龙王山之后第一个45	
    Turn_Angle('L','b',2000);  	
    //龙王山之后第一个90
				 
							 
							 
							 

							 
				tracking('B','M',700,6,1);
   tracking('F','M',500,1,1);
		Turn_Angle('L','b',2000);
   tracking('B','M',1000,5,1);
   tracking('B','M',300,0,1);
motor_allocation('S');
delay_ms(500);
		 Turn_Angle('R','b',2000);
   tracking('F','L',1000,7,1);
   tracking('F','M',1500,6,1);
								tracking('F','M',1200,5,2);
	               Plot_up('F',10,2);

                 Plot_turn(state_treasure[5]);		 
							 				



			     Plot_down('F',-10,-10);
	//5号平台结束
tracking('F','M',1500,6,1);//第一条曲线
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5号平台之后第一个90
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','b',1800);
  //5号平台之后第二个90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5号平台之后第三个90
                Feature_Sport('F');
								//牛首山
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //牛首山之后第一个90
tracking('F','M',1000,6,1);
//                Hill('F');
								//山丘
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',2000);
  //山丘之后第一个类直角
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //山丘之后第一个90
	              Seesaw();
								//跷跷板
tracking('F','M',1000,6,1);
tracking('F','M',1000,0,1);

                Slope(-1,10,5);
  //斜坡
tracking('F','M',500,3,1);
                Plot_Plus_up('F',15,3);  
                Plot_turn(state_treasure[8]);
                Plot_Plus_down('F',-15,-15);

//珠峰结束
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//珠峰下来第一个45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//珠峰下来第二个45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','b',1800);
	//珠峰下来第一个90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
while(!mild_L);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','a',1800);
	//珠峰下来第二个90
tracking('F','M',500,5,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('R','a',1700);
	//珠峰下来第三个90
	            Feature_Sport('F');
							//千岛湖

tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','b',1800);
	//千岛湖之后第一个90
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_L);
  Turn_Angle('L','a',1800);
	//千岛湖之后第二个90
tracking('F','M',500,5,1);
tracking('F','M',700,6,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('L','b',1800);
	//千岛湖之后第三个90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
delay_ms(500);
  Turn_Angle('L','a',1800);
	//千岛湖之后第四个90
	           Feature_Sport('F');
	           //太白湖
tracking('B','M',500,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//太白湖之后第一个90
tracking('F','M',1000,7,1);
//tracking('F','M',500,3,1);
tracking('F','M',500,1,1);

		tracking('F','M',1000,6,1);
	  tracking('F','M',500,2,1);
	  Go_Stright('F',300);
    while(!mild_L);
	
      Turn_Angle('R','a',1800);
	
    tracking('F','L',700,5,1);
    tracking('F','M',1000,6,1);
	  tracking('F','R',700,0,1);
    tracking('F','R',500,0,1);
    tracking('B','R',500,2,1);						 
}


void section_23_(void)
{
              Plot_down('F',-10,-10); 
  //二号平台结束	
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',1000,1,1);//第一条斜线
tracking('B','M',700,7,1); //第一条斜线
    Turn_Angle('R','a',1800);
	//二号平台之后第一个45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//二号平台之后第二个45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//第一条斜线
tracking('F','M',700,4,1);//第一条斜线
tracking('B','M',500,1,1);//第一条斜线
		Turn_Angle('L','a',2000);	
		//一号门之后第二个45
tracking('F','L',700,5,1);//过渡		
	            Feature_Sport('F');
              //普陀山							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //普陀山之后第一个45		
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4号平台结束								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //极限加速区
                Plot_up('F',10,2);
Treasure(0);								
                Plot_turn(state_treasure[3]);	              
              	Plot_down('F',-10,-10);
	             //3号平台结束
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //三号平台之后第一个45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //龙王山
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
    //龙王山之后第一个45	
							 
							 		 						 
}



