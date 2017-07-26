/*
*±¾³ÌĞòÓÃ¶¨Ê±Æ÷2×÷Îª²¨ÌØÂÊ·¢ÉúÆ÷£¬ÓÉÄ£¿é½ÓÊÕÊı¾İ´«µ½µ¥Æ¬»ú£¬Í¬Ê±¿É»Ø´«Êı¾İµ½¿ØÖÆÖ÷»ú£¬ÊµÏÖĞ¡³µµÄ¿ØÖÆ¹¦ÄÜ
*Í¨ĞÅĞ­Òé£º1	Ç°½ø 1
					 2	ºóÍË 2
					 3	ÓÒ×ª 3
					 4	×ó×ª 4
					 ÆäËü Í£Ö¹ stop
*Æ½Ì¨£ºSTC89C52RC
*×÷Õß£ºW_Honor
*ÈÕÆÚ£º2017/7/24
*/
#include <stc89xx.h>
#include "motor.h"

#define FOSC 12000000L      //System frequency
#define BAUD 9600   //ÉèÖÃ²¨ÌØÂÊ

bit flag = 0;

bit rec_flag = 0;//Êı¾İ½ÓÊÜ±êÖ¾Î»

unsigned char RecData = 0;

char code str[] = "stop"; 


//´®¿Ú³õÊ¼»¯³ÌĞò	`
void UART_Init(void)
{
 //PCON = 0x80;//²¨ÌØÂÊ¼Ó±¶£¬SOMD = 1
 SCON = 0x50; //SM0 SM1 SM2 REN TB8 RB8 TI RI ´®ĞĞ¿Ú¹¤×÷·½Ê½1£¬10Î»Òì²½ÊÕ·¢
 RCAP2H = (65536-(FOSC/32/BAUD)) >> 8;
 RCAP2L = (65536-(FOSC/32/BAUD));
 TH2 = RCAP2H;
 TL2 = RCAP2L;
 T2CON = 0x34; //TF2 EXF2 RCLK TCLK EXEN2 TR2 C/T2 CP/RL2//¶¨Ê±Æ÷2ÓÃ×÷²¨ÌØÂÊ·¢ÉúÆ÷
 T2MOD = 0;
 ES = 1;
 EA = 1;
	
/*	PCON = 0x80;
    SCON = 0x50;   // 
    TMOD = 0x20;   //T1
    TH1 = 0xF3;    //[
    TL1 = 0xF3;  
    TR1 = 1;                 	
    ES  = 1;       //
    EA  = 1;
	*/
}

//ÏòÉÏÎ»»ú·¢ËÍÒ»¸ö×Ö½ÚÊİĞÅÏ¢
void senddata(char dat)
{
		if(rec_flag == 1)
		{
			ES=0;//
			SBUF=dat;
			while(!TI);
			TI=0;
			ES=1;//
		}
		rec_flag = 0;
}

//ÏòÉÏÎ»»ú·¢ËÍÒ»¸ö×Ö·û´®
void sendstr(void)
{
	unsigned int i = 0;
	if(flag == 1)
	{
		flag = 0;
		while(str[i] != '\0')
	{
		ES = 0;
		SBUF = str[i];
		while(!TI);
		TI = 0;
		i++;
		ES = 1;
	}
	i = 0;
	}
}

//Ö÷º¯Êı
void main(void)
{
	UART_Init();
	P0 = 0;//ÆÁ±Î¸ÉÈÅ
	while(1);
	}

//´®¿Ú·şÎñÖĞ¶Ï×Ó³ÌĞòñ
void Uart_Timer2(void) interrupt 4//ÖĞ¶Ï½ÓÊÕÒ»¸ö×Ö½ÚÊı¾İ,´®¿ÚÖĞ¶ÏºÎª4Å
{
	unsigned char i = 0;
	if(RI == 1)//½ÓÊÕ±êÖ¾Î»//µ±Ó²¼ş½ÓÊÕµ½Êı¾İÊ±»áÖÃÎ»
	{
		RI = 0;//¹Ø±Õ½ÓÊÕÊ	
		RecData = SBUF;
		rec_flag = 1;//½ÓÊÜÍêÒ»¸ö×Ö·ûÖÃ1
		switch(RecData)
		{
			case '1'://Ç°½ø
			  go();
				senddata('1');
			break;
			case '2'://ºóÍË
				back();
				senddata('2');
			break;
			case '3'://ÓÒ×ª
				right();
			  senddata('3');
			break;
			case '4'://×ó×ª
				left();
				senddata('4');
			break;
			default:
				stop();
			  flag = 1;
				sendstr();
				break;
		}
	}
	else
	{
		TI = 0;
	}
}