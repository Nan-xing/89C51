#include <reg51.h>
typedef unsigned char u8;
typedef unsigned int u16;

void uart_init(u8 baud)
{
	TMOD|=0X20;
	SCON=0X50;
	PCON=0X80;
	TH1=baud;
	TL1=baud;
	ES=1;
	EA=1;
	TR1=1;	
}
void main()
{
	uart_init(0xfa);
}
void uart() interrupt 4
{
	u8 i=0;
	RI=0;
	i=SBUF;
	SBUF=i;
	while(~TI);
	TI=0;
}