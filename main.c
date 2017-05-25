#include <reg52.h>
#include "motor.h"

int flag = 0;

char Rec[];
//´®¿Ú³õÊ¼»¯³ÌÐò
void UART_Init(void)
{
	SCON  = 0x40;//´®¿Ú·½Ê½Ò»
	PCON  = 0;//SOMD = 0
	REN  = 1;//ÔÊÐí½ÓÊÕ
	TMOD = 0x20;//¶¨Ê±Æ÷1·½Ê½2
	TH1 = 0xfd;					//²¨ÌØÂÊ9600£¬Êý¾ÝÎ»8£¬Í£Ö¹Î»1
  TL1 = 0xfd;
	TR1  = 1;//¿ªÆô¶¨Ê±Æ÷1
	ES  = 1;//´ò¿ªUARTÖÐ¶Ï
	EA  = 1;//´ò¿ª×ÜÖÐ¶Ï
}

void main(void)
{
	UART_Init();
	P0 = 0;//ÆÁ±Î¸ÉÈÅ
	while(1)
	{
		if(RI)
		{
			switch(Rec[])
		{
			case "00"://Ç°½ø
				Left_moto_go;
				Right_moto_go;
			break;
			case "01"://ºóÍË
				Left_moto_back;
				Right_moto_back;
			break;
			case ""://ÓÒ×ª
				Left_moto_go;
				Right_moto_back;
			break;
			case ""://×ó×ª
				Left_moto_back;
				Right_moto_go;
			break;
			default:
				break;
			
		}
		}
		
	}
}

//´®¿Ú·þÎñÖÐ¶Ï×Ó³ÌÐòñ
void Uart_Timer1(void) interrupt 4
{
	if(RI == 1)
	{
		RI = 0;
		if(flag < 2)
		{
			Rec[flag] = SBUF;
			flag++;
		}
		else
		{
			flag = 0;
		}
	}
}