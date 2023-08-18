#include "reg51.h"
sbit led=P2^0;
typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned long u32;

void delay(u32 i)
{
	while(i--)
	{
		;
	}
}
void main()
{
	while(1)
	{
		led=0;
		delay(10000);
		led=1;
		delay(10000);
	}
}
