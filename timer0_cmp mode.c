
#include "lib.h"
#include "ultrasonic_fun.h" // utrasonic sensor library is included
#include "timer_fun.h" // timer 1 is set up
#include "input_capture.h"

void timer0_init(void)
{
	TCCR0B |= (1<<WGM02) | (1<<CS02) | (1<<CS00); // prescalar is set to 1024 and timer is set in ctc mode
	TCNT0 = 0; // timer count is initialize to 0
	TIMSK0 |= (1<<OCIE0A); //timer interrupt 1A is selected to turn on
	OCR0A = 250; // count compare value is assign to get delay of 1 sec
	sei(); // global interrupt enable
}

void timer0_reset(void)
{
	TCNT0=0; // count is set to 0
}


ISR (TIMER0_COMPA_vect)
{  
	sei();
	timer0_reset();  // count is set to 0
	timer_init();  // timer1 get start
	ultrasonic_trigger(); // trigger function is call
	 input_rising();
	 input_falling();
}