//timer function

#include "lib.h"

void timer_init(void)
{
	TCCR1B |= 0xC1;
	TCNT1=0;
}

void timer_off(void)
{
	TCCR1B =0; // turn off the timer1
	TCNT1=0; // count is set to 0
}
