// pin change interrupt

#include "lib.h"
#include "timer1_ovr mode.h"
#include "timer0_cmp mode.h"

#define max_array 5
#define max_distance 500

volatile unsigned long int distance;
extern volatile unsigned char timer_overflow,sort_count;
extern unsigned long int sorting[max_array]; // sorting array is set up


void pinchange_int(void)
{
	PCICR = (1<<PCIE2); //pin change interrupt is initialze at 6 pin
	PCMSK2 = (1<<PCINT6); // pin 6 pin change interrupt is enable 
	sei(); // global interrupt enable
}

ISR (PCINT2_vect) // isr for pin change interrupt for echo pin
{ 
 if(PIND & (1<<6))// echo get high 
 {
    timer1_init();
 }

   if(!(PIND & (1<<6)))// echo get low for calculation
  {
	 timer1_off();
	 distance = (TCNT1 + (timer_overflow * 65536)) * 0.0021437; // http://www.electronicwings.com/avr-atmega/ultrasonic-module-hc-sr04-interfacing-with-atmega1632
	 timer_overflow=0;
	 if(distance <= max_distance)  // for setting 500 meter as max distance
	 {
	 sorting[sort_count]=distance;   //putting distance value in array
	 sort_count++;  // count count is incremented 
	 }
     if(sort_count>max_array)       // 6 no of array values for sorting
	    {
		timer0_off();
		}
     }
}