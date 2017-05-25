#include <reg52.h>

sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
sbit INA = P1^4;//左使能端
sbit INB = P1^5;

//前进函数
void go(void)
{
	INA = 1;
	INB = 1;
	
	IN1 = 1;
	IN2 = 0;
	IN3 = 1;
	IN4 = 0;
}

//后退函数
void back(void)
{
	INA = 1;
	INB = 1;
	
	IN1 = 0;
	IN2 = 1;
	IN3 = 0;
	IN4 = 1;
	
}

//左转
void left(void)
{
	INA = 1;
	INB = 1;
	
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
}
//右转
void right(void)
{
	INA = 1;
	INB = 1;
	
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
}