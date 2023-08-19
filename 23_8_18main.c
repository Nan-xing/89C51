#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit beep=P2^5;

void delay_10us(u16 dat)
{
 	while(dat--)
	{
		;
	}
}

void Beep(int dat ,int HZ)
{
	u16 i=0;
	beep=0;
	while(i<dat)
	{
		beep=~beep;
		delay_10us(HZ);
		i++;
	}
}

void main()
{
	while(1)
	{
		Beep(1000,10);
	}
}