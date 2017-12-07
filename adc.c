/*
 * adc.c
 *
 * Created: 12/7/2017 1:01:33 PM
 *  Author: Rajesh Jat
 */ 

#include "lib.h"

extern volatile unsigned int analog_value;

void adc_int()
{
 	ADMUX |= (1<<REFS0);                 // 5V internal reference volatge for adc
	ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);       //128 as prescalar for 125khz, interrupt eanble,adc is enable
}

void adc_start(unsigned char channel)
{
	channel &= 0x07;   // channel is and with channel selection
	ADMUX = (ADMUX & 0xF8) | channel;  //channel is selected
	ADCSRA |=(1<<ADSC);   // start conversion
}

ISR(ADC_vect)            // adc interrupt routine after conversion
{
   analog_value = ADC; 	 // adc is store analog_value
}