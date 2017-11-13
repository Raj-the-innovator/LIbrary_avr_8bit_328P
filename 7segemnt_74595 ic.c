// 7 segment function

#include "lib.h"
#define serial (1<<2)
#define shift_clock (1<<3)
#define latch_clock (1<<4)

void segment_init()
{
 DDRD |= serial | shift_clock | latch_clock;
 PORTD |= serial | shift_clock | latch_clock;
 PORTD = 0;
}

void data_send(unsigned int data)
{
	signed char i;
	for(i=15;i>=0;i--)
	{
		if((data >> i) & 1)
		{
			PORTD |=serial;
		}
		else
		{
			PORTD &= ~(serial);
		}
		PORTD &=~(shift_clock);
		PORTD |=shift_clock;
	}
	PORTD &=~(latch_clock);
	PORTD |= latch_clock;
}


void segment_display(unsigned char ten,unsigned char unit)
{

 unsigned int data;
 data = (ten << 8) | unit;
 data_send(data);
}

