#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define smg  P0

u8 smg_g[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(u16 i)
{
	while(i--)
	{
		;
	}
}

void main()
{
	u16 i=0;
	while(1)
	{
		for(i=0;i<16;i++)
		{
			smg=smg_g[i];
			delay(65534);
		}	
	}
}