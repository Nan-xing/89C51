#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit key3=P3^2;
sbit led1=P2^0;
sbit led2=P2^1;
void delay(u16 i)//Ïàµ±ÓÚ1ms
{
	u16 j=0;
	for(j=0;j<=100;j++)
	{
		i--;
	}
}

void exit0_init()
{
	EA=1;
	EX0=1;
	IT0=1;
}
void main()
{
	exit0_init();
	while(1)
	{
		led2=0;
		delay(100);
		led2=1;
		delay(100);
	}
}
void exit() interrupt 0
{
	delay(10);
	if(key3==0)
	{
		led1=~led1;
		led2=0;
	}
}