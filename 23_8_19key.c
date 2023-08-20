#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led P2

sbit key1=P3^1;

void delay(u16 i)
{
	while(i--)
	{
		;
	}
}
u8 key_scan()
{
	u16 count=0;
	 if(key1==1)
	 {
		 count++;
	 	delay(1000);
		if(key1==0)
		{
			return 1;
		}
		
		if(count>3000)
		{
			if(key1==0)
			{
				return 2;
			}
		}

	 }
	
}
void main()
{
   u8 i;
   u16 j,k;
	i=key_scan();
	if(i==1)
	{
		for(j=0;j<65524;j++)
		{ 	
			for(k=0;k<10;k++)
			{
				i=key_scan();
				led=0xfe;
			}
		}
		led=0xff;																			  
	}
	else if(i==2)
	{
		for(j=0;j<65524;j++)
		{ 	
			for(k=0;k<10;k++)
			{
				i=key_scan();
				led=0xfe;
			}
		}
		led=0xfd;
	}
}