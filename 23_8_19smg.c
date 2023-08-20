#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

u8 smg[8]={0x6d,0x5b,0x3f,0x40,0x06,0x4f,0x06,0x66}; 
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

#define  pos P0

void delay(u16 i)
{
	while(i--)
	{
		;
	}
}
void Din_smg()
{
	u16 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case 0:
				LSA=1,LSB=1,LSC=1;
				break;
			case 1:
				LSA=0,LSB=1,LSC=1;
				break;
			case 2:
				LSA=1,LSB=0,LSC=1;
				break;
			case 3:
				LSA=0,LSB=0,LSC=1;
				break;
			case 4:
				LSA=1,LSB=1,LSC=0;
				break;
			case 5:
				LSA=0,LSB=1,LSC=0;
				break;
			case 6:
				LSA=1,LSB=0,LSC=0;
				break;
			case 7:
				LSA=0,LSB=0,LSC=0;
				break;
			default :
				break;
		}
		pos=smg[i];
		delay(10);
		pos=0x00;
	}
}
void main()
{
	while(1)
	{
		Din_smg();
	}
}
