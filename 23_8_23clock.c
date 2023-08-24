#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led P2
u8 LED[]={0X01,0X02,0X04,0X08,0X10,0X20,0X40,0X80};

void time0_init()
{
	TMOD|=0X01;
	TH0=0XFC;
	TL0=0X66;
	EA=1;
	ET0=1;
	TR0=1;
}
void main()
{
	time0_init();
	while(1)
	{
		;
	}
}
void time0() interrupt 1
{
	static u16 i=0;
	static u8 j=0;
	TH0=0XFC;
	TL0=0X66;
	i++;
	if(i==1000)
	{					
		if(j>7)
		{
			j=0;
		}
		led=~LED[j];
		i=0;
		j++;
	}
}