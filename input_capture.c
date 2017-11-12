
#include "lib.h"

extern volatile unsigned int distance,sort_count;

void input_rising(void)
{
	while ((TIFR1&(1<<ICF1)) == 0);  /* monitor for capture*/
	TCNT1=0;
	TCCR1B=0x81;
	TIFR1 |= (1<<ICF1);
}

void input_falling(void)
{
	while((TIFR1&(1<<ICF1)) == 0);
	distance = ICR1;
	distance /= 26;
	sort_count++;  // count count is incremented
	TCCR1B=0xC1;
	TIFR1 |= (1<<ICF1);
	TCNT1 = 0;
}