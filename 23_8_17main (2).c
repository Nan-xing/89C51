#include <reg52.h>
#include <intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led  P2
sbit beep=P2^5;

void delay(u16 i)
{
while(i--)
{
	;
}
}		 
void main()
{
	u16 i;
	while(1)
	{
//		led=0xfe;
//		for(i=0;i<7;i++)
//		{
//			led=_cror_(led,1);
//			beep(25000);
//		}
//		for(i=0;i<7;i++)
//		{
//			led=_crol_(led,1);
//			beep(25000);
//		}
		beep=~beep;
		delay(10);
	}
}