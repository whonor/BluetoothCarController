/********************************************************************

		   IN 1 2 3 4				
前进:		  1 0 0 1	0x09		
后退:		  0 1 1 0	0x06			
停止:		  0 0 0 0	0x00			
左转:		  0 1 0 1	0x05
右转:		  1 0 1 0	0x0a

*********************************************************************/
#ifndef _MOTOR_H_
#define _MOTOR_H_

extern void go();
extern void back();
extern void stop();
extern void left();
extern void right();

#endif