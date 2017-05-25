#ifndef _PWM_RUN_H_
#define _PWM_RUN_H_
		/*************************************************
		本程序中存在错误，错误在于C51中不能直接定义P1^1类型的变量，因为它只是个变量名，还要结合端口号P1_1与其重新定义，
		而C52中不需再定义
		******************************************************/

    //定义小车驱动模块输入IO口 
	sbit IN1=P1^0;	   
	sbit IN2=P1^1;
	sbit IN3=P1^2;
	sbit IN4=P1^3;
	
	sbit INA=P1^4;	   //左使能端
	sbit INB=P1^5;		   //右使能端
	
//	sbit IN7=P1^6;
//	sbit IN8=P1^7;	

	  //蜂鸣器接线定义
   // sbit BUZZ=P3^2;

	
	//小车4路红外传感器接线定义
    //#define Left_1_led        P3_7	 //P3_7接四路寻迹模块接口第一路输出信号即中控板上面标记为OUT1
	//#define Left_2_led        P3_6	 //P3_6接四路寻迹模块接口第二路输出信号即中控板上面标记为OUT2	
    //#define Right_1_led       P3_5	 //P3_5接四路寻迹模块接口第三路输出信号即中控板上面标记为OUT3
	//#define Right_2_led       P3_4	 //P3_4接四路寻迹模块接口第四路输出信号即中控板上面标记为OUT4

	//小车驱动接线定义
  #define Left_moto_go      {IN1=1,IN2=0;}            //左边电机向前走	   ********
	#define Left_moto_back    {IN1=0,IN2=1;}    //左边电机向后转					   *******
	#define Left_moto_Stop    {IN1=0,IN2=0;}    //左边电机停转                     		  *********
	#define Right_moto_go     {IN3=0,IN4=1;}	   //右边电机向前走									   **********
	#define Right_moto_back   {IN3=1,IN4=0;}	//右边电机向后走												 *********
	#define Right_moto_Stop   {IN3=0,IN4=0;}	//右边电机停转  														  ******
	
  bit Right_moto_stop = 1;
	bit Left_moto_stop = 1;
	 unsigned int Left_time;
	 unsigned int Right_time;

	 unsigned char Left_N;					   //自定义变量
	 unsigned char Right_N;
//	 unsigned int time=0;				   //溢出次数

	 
	


/************************************************************************/
//全速前进函数
     void  run(void)
{    
   	   Left_N=50;			 //制定左右电机占空比
	   Right_N=50;
	   Left_moto_go;
	    Right_moto_go;


}
/*********************************************************************/		 
/************************************************************************/
//全速后退函数
     void  back(void)
{
   	    Left_N=50;			 //制定左右电机占空比
	   Right_N=50;
	   Left_moto_back;
	    Right_moto_back;

}
/*********************************************************************/	
/***********************************************************************/
    //全速左转函数
     void  left(void)
{
      Left_N=50;			 //制定左右电机占空比
	   Right_N=50;
	    Left_moto_back;
	    Right_moto_go;

}
/*********************************************************************/	
/************************************************************************/
//全速右转函数 
     void  right(void)
{ 
		Left_N=50;			 //制定左右电机占空比
	   Right_N=50;
	    Left_moto_go;
	    Right_moto_back;

}
/*********************************************************************/	
/************************************************************************/
   //电机停止转动函数 
     void  stop(void)
{
	  
	   Left_moto_stop;
	    Right_moto_stop;


    
}
/*********************************************************************/	
/************************************************************************/
   //左电机调速函数

   void PWM_Left_time(void)
   {
   		if(Left_moto_stop )
		{
			if(Left_time<=Left_N)
			INA =1;

			else INA =0;

			if(Left_time>=100)
			Left_time=0;
			else 
			INA=0;
		}

   }

/******************************************************************************/
/**********************************************************************************/
    //右电机调速函数

	void PMW_Right_time(void)
	{
		   	if(Right_moto_stop )
		{
			if(Right_time<=Right_N)
			INB =1;

			else 
			INB = 0;

			if(Right_time>=100)
			Right_time=0;				 //清零
			else 
			INB = 0;
			
			}
	}
/************************************************************************/
//T0中断子函数产生PMW信号

void Time0() interrupt 1
{
	TH0=0xfc;					  //1MS定时				 T=0.01  D=100  D*T=1MS
	TL0=0x18;
//	time++;						//溢出次数 定义变量
	Left_time++;
	Right_time++;
	PMW_Right_time();
	PMW_Left_time();

}


#endif