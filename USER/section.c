#include "allocation.h"
extern u8 state_treasure[9];












void section_1(void)
{
Plot_down('F',-10,-10);
  //����ֹ��
tracking('F','M',1000,6,1);//��һ��б��
tracking('F','M',1000,4,1);//�ڶ���б��
Long_Bridge();
	//���Ž���
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);	
Plot_up('F',10,1);  
Treasure(0);
Plot_turn(0);
}












void section_2(void)
{
              Plot_down('F',-10,-10); 
  //����ƽ̨����	
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',1000,1,1);//��һ��б��
tracking('B','M',700,7,1); //��һ��б��
    Turn_Angle('R','a',1800);
	//����ƽ̨֮���һ��45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//����ƽ̨֮��ڶ���45
tracking('F','R',1200,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
	//����ƽ̨֮�������45
tracking('B','R',1000,6,1);
	            Door(2);
	            //������̽��
tracking('F','M',1200,6,1);
tracking('F','M',700,3,1);
Go_Stright('F',300);
while(!mild_R);
    Turn_Angle('L','b',1800);
		//������֮���һ��45
	            Door(1);
							//һ����̽��
tracking('F','M',1200,6,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);	
while(!mild_R);
    Turn_Angle('R','a',1400);	
    //һ����֮���һ��45
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',700,4,1);//��һ��б��
tracking('B','M',500,1,1);//��һ��б��
		Turn_Angle('L','a',2000);	
		//һ����֮��ڶ���45
tracking('F','L',700,5,1);//����		
	            Feature_Sport('F');
              //����ɽ							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //����ɽ֮���һ��45		
                Plot_up('F',10,2); 
					Treasure(0);
                Plot_turn(0);	              
                Plot_down('F',-10,-10);
                //4��ƽ̨����								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //���޼�����
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(0);	              


}
void section_2_9(void)
{
              Plot_down('F',-10,-10); 
  //����ƽ̨����	
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',1000,1,1);//��һ��б��
tracking('B','M',700,7,1); //��һ��б��
    Turn_Angle('R','a',1800);
	//����ƽ̨֮���һ��45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//����ƽ̨֮��ڶ���45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',700,4,1);//��һ��б��
tracking('B','M',500,1,1);//��һ��б��
		Turn_Angle('L','a',2000);	
		//һ����֮��ڶ���45
tracking('F','L',700,5,1);//����		
	            Feature_Sport('F');
              //����ɽ							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //����ɽ֮���һ��45		
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4��ƽ̨����								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //���޼�����
                Plot_up('F',10,2);
Treasure(0);								
                Plot_turn(state_treasure[3]);	              
              	Plot_down('F',-10,-10);
	             //3��ƽ̨����
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //����ƽ̨֮���һ��45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //����ɽ
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
    //����ɽ֮���һ��45	
							 
tracking('F','M',1000,5,1);
tracking('F','M',1500,6,1);	 
tracking('F','R',700,0,1);
tracking('F','R',500,0,1);
tracking('B','R',500,2,1);					 
							 
}

void section_3(void)
{
             	Plot_down('F',-10,-10);
	             //3��ƽ̨����
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //����ƽ̨֮���һ��45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //����ɽ
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
//    Turn_Angle('L','b',2000);
//    //����ɽ֮���һ��45	
    Turn_Angle('L','b',2000);  	
    //����ɽ֮���һ��90

	
	
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
	//5��ƽ̨����
tracking('F','M',1500,6,1);//��һ������
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
motor_allocation('S');
delay_ms(500);
Turn_Angle('L','a',1800);
	//5��ƽ̨֮���һ��90
//tracking('F','M',500,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('R','a',1800);
  //5��ƽ̨֮��ڶ���90
tracking('F','M',500,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
Turn_Angle('R','a',1800);
	//5��ƽ̨֮�������90
                Feature_Sport('F');
								//ţ��ɽ
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //ţ��ɽ֮���һ��90
tracking('F','M',1000,6,1);
//                Hill('F');
								//ɽ��
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //ɽ��֮���һ����ֱ��
tracking('F','M',700,9,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //ɽ��֮���һ��90
	              Seesaw();
								//���ΰ�
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //���ΰ�֮���һ��90
//tracking('F','M',500,8,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //���ΰ�֮��ڶ���90
tracking('F','M',500,1,2);
tracking('F','M',500,0,2);
tracking('F','M',500,1,2);
tracking('F','M',500,0,2);
  //�ϵڶ���б�����������
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
	//�µڶ��������������
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('L','b',2000);
	//�µڶ����µ�һ��90
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('R','a',2000);
	//�µڶ����µڶ���90
	Slope(-1,10,-5);
  //б��
tracking('F','L',500,3,1);
                Plot_Plus_up('F',15,3);  
Treasure(0);
                Plot_turn(state_treasure[8]);
}




void section_7(void)
{
                Plot_Plus_down('F',-15,-15);
	              //������
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//���������һ��45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//��������ڶ���45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//���������һ��90
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//��������ڶ���90
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
  Turn_Angle('R','a',1700);
	//�������������90
	            Feature_Sport('F');
							//ǧ����
}


void section_8(void)
{ 
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','b',1800);
	//ǧ����֮���һ��90
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_L);
  Turn_Angle('L','a',1800);
	//ǧ����֮��ڶ���90
tracking('F','M',500,5,1);
tracking('F','M',700,6,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('L','b',1800);
	//ǧ����֮�������90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
delay_ms(500);
  Turn_Angle('L','a',1800);
	//ǧ����֮����ĸ�90
	           Feature_Sport('F');
	           //̫�׺�
tracking('B','M',500,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//̫�׺�֮���һ��90
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
	//5��ƽ̨����
tracking('F','M',1500,6,1);//��һ������
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5��ƽ̨֮���һ��90
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','b',1800);
  //5��ƽ̨֮��ڶ���90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5��ƽ̨֮�������90
                Feature_Sport('F');
								//ţ��ɽ
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('L','a',1800);
  //ţ��ɽ֮���һ��90
tracking('F','M',1000,7,2);
tracking('F','M',700,3,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',1800);
tracking('B','M',700,5,1);
tracking('B','M',300,1,1);
Turn_Angle('R','a',1800);
	           Feature_Sport('F');
	           //̫�׺�
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//̫�׺�֮���һ��90
tracking('F','M',1000,7,1);
tracking('F','M',700,3,1);	
tracking('F','M',300,1,1);	
}
void section_5_6_7(void)
{
                 Plot_down('F',-10,-10);
	//5��ƽ̨����
tracking('F','M',1500,6,1);//��һ������
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5��ƽ̨֮���һ��90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
	while(!mild_R);
	motor_allocation('S');
  delay_ms(500);
Turn_Angle('R','b',1800);
  //5��ƽ̨֮��ڶ���90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5��ƽ̨֮�������90
                Feature_Sport('F');
								//ţ��ɽ
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //ţ��ɽ֮���һ��90
tracking('F','M',1000,6,1);
//                Hill('F');
								//ɽ��
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',2000);
  //ɽ��֮���һ����ֱ��
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //ɽ��֮���һ��90
tracking('F','M',500,5,1);
	              Seesaw();
								//���ΰ�
tracking('F','M',1000,6,1);
tracking('F','M',1000,0,1);

                Slope(-1,10,5);
  //б��
tracking('F','M',1000,3,1);
                Plot_Plus_up('F',15,3); 
Treasure(0);								
                Plot_turn(state_treasure[8]);
                Plot_Plus_down('F',-15,-15);

//������
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//���������һ��45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//��������ڶ���45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','b',1800);
	//���������һ��90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
while(!mild_L);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','a',1800);
	//��������ڶ���90
tracking('F','M',500,5,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('R','a',1700);
	//�������������90
	            Feature_Sport('F');
							//ǧ����


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
  //����ֹ��
tracking('F','M',1000,6,1);//��һ��б��
tracking('F','M',1000,4,1);//�ڶ���б��
Long_Bridge();
	//���Ž���
tracking('F','M',1000,6,1);
tracking('F','M',1000,4,1);	
	
              Plot_up('F',10,1);  

              Plot_turn(0);
              Plot_down('F',-10,-10); 
  //����ƽ̨����	
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',1000,1,1);//��һ��б��
tracking('B','M',700,7,1); //��һ��б��
    Turn_Angle('R','a',1800);
	//����ƽ̨֮���һ��45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//����ƽ̨֮��ڶ���45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',700,4,1);//��һ��б��
tracking('B','M',500,1,1);//��һ��б��
		Turn_Angle('L','a',2000);	
		//һ����֮��ڶ���45
tracking('F','L',700,5,1);//����		
	            Feature_Sport('F');
              //����ɽ							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //����ɽ֮���һ��45		
                Plot_up('F',10,2);
	  							
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4��ƽ̨����								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //���޼�����
                Plot_up('F',10,2); 

                Plot_turn(state_treasure[3]);	              
      	Plot_down('F',-10,-10);
	             //3��ƽ̨����
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //����ƽ̨֮���һ��45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //����ɽ
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
//    Turn_Angle('L','b',2000);
//    //����ɽ֮���һ��45	
    Turn_Angle('L','b',2000);  	
    //����ɽ֮���һ��90
				 
							 
							 
							 

							 
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
	//5��ƽ̨����
tracking('F','M',1500,6,1);//��һ������
tracking('F','M',1000,2,1);//
tracking('F','M',700,6,1);
tracking('F','M',500,2,1);//
tracking('F','M',300,0,1);
Turn_Angle('R','b',1800);
	//5��ƽ̨֮���һ��90
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','b',1800);
  //5��ƽ̨֮��ڶ���90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
Turn_Angle('L','a',1800);
	//5��ƽ̨֮�������90
                Feature_Sport('F');
								//ţ��ɽ
tracking('B','M',500,4,1);
Go_Stright('B',300);
	while(!mild_R);
Turn_Angle('R','a',1800);
  //ţ��ɽ֮���һ��90
tracking('F','M',1000,6,1);
//                Hill('F');
								//ɽ��
tracking('F','M',1000,6,1);
tracking('F','M',500,2,1);
Go_Stright('F',300);
	while(!mild_R);
Turn_Angle('L','b',2000);
  //ɽ��֮���һ����ֱ��
tracking('B','M',700,4,1);
Go_Stright('B',300);
	while(!mild_L);
Turn_Angle('L','a',2000);
  //ɽ��֮���һ��90
	              Seesaw();
								//���ΰ�
tracking('F','M',1000,6,1);
tracking('F','M',1000,0,1);

                Slope(-1,10,5);
  //б��
tracking('F','M',500,3,1);
                Plot_Plus_up('F',15,3);  
                Plot_turn(state_treasure[8]);
                Plot_Plus_down('F',-15,-15);

//������
tracking('F','M',700,6,1);
tracking('F','M',500,4,1);
  Turn_Angle('R','b',2000);
	//���������һ��45
tracking('B','L',500,3,1);
tracking('B','M',1000,5,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',2000);
	//��������ڶ���45
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
Go_Stright('F',300);
while(!mild_R);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','b',1800);
	//���������һ��90
tracking('B','M',1000,4,1);
Go_Stright('B',300);
while(!mild_L);
motor_allocation('S');
  delay_ms(500);
	Turn_Angle('L','a',1800);
	//��������ڶ���90
tracking('F','M',500,5,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('R','a',1700);
	//�������������90
	            Feature_Sport('F');
							//ǧ����

tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','b',1800);
	//ǧ����֮���һ��90
tracking('B','M',700,4,1);
Go_Stright('B',300);
while(!mild_L);
  Turn_Angle('L','a',1800);
	//ǧ����֮��ڶ���90
tracking('F','M',500,5,1);
tracking('F','M',700,6,1);
tracking('F','M',1000,7,1);
tracking('F','M',500,3,1);	
tracking('F','M',300,1,1);
delay_ms(500);
  Turn_Angle('L','b',1800);
	//ǧ����֮�������90
tracking('B','M',700,4,1);
tracking('B','M',300,0,1);
delay_ms(500);
  Turn_Angle('L','a',1800);
	//ǧ����֮����ĸ�90
	           Feature_Sport('F');
	           //̫�׺�
tracking('B','M',500,4,1);
Go_Stright('B',300);
while(!mild_R);
  Turn_Angle('R','a',1800);
	//̫�׺�֮���һ��90
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
  //����ƽ̨����	
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',1000,1,1);//��һ��б��
tracking('B','M',700,7,1); //��һ��б��
    Turn_Angle('R','a',1800);
	//����ƽ̨֮���һ��45
	//Hill();
tracking('F','R',700,7,1);
tracking('F','M',700,1,1);
    Turn_Angle('L','b',1400);
	//����ƽ̨֮��ڶ���45
tracking('F','R',1200,7,2);
tracking('F','M',1000,7,1);//��һ��б��
tracking('F','M',700,4,1);//��һ��б��
tracking('B','M',500,1,1);//��һ��б��
		Turn_Angle('L','a',2000);	
		//һ����֮��ڶ���45
tracking('F','L',700,5,1);//����		
	            Feature_Sport('F');
              //����ɽ							
tracking('B','L',1000,5,1);       
Go_Stright('B',300);
while(!ahead_8);
		Turn_Angle('R','a',2000);
    //����ɽ֮���һ��45		
                Plot_up('F',10,2); 
Treasure(0);								
                Plot_turn(state_treasure[4]);	              
                Plot_down('F',-10,-10);
                //4��ƽ̨����								
tracking('F','M',900,7,1);
tracking('F','M',1000,6,1);
tracking('F','M',1200,7,1);
tracking('F','M',1500,6,1);
tracking('F','M',1200,7,1);
  //���޼�����
                Plot_up('F',10,2);
Treasure(0);								
                Plot_turn(state_treasure[3]);	              
              	Plot_down('F',-10,-10);
	             //3��ƽ̨����
tracking('F','M',1200,6,1); 
tracking('F','M',700,2,1); 
tracking('F','M',300,4,1);
    Turn_Angle('R','b',2000);
    //����ƽ̨֮���һ��45  
tracking('B','L',700,7,1);
                Feature_Sport('B');
	              //����ɽ
tracking('F','M',1500,7,1);
tracking('F','M',300,5,1);
    Turn_Angle('L','b',2000);
    //����ɽ֮���һ��45	
							 
							 		 						 
}



