/*
 * adc.c
 *
 * Created: 12/7/2017 1:01:33 PM
 *  Author: Rajesh Jat
 */ 

#include "lib.h"
#include "usart.h"
#include "thermistor.h"
#define Max 50

const int temptable[Max][2];
extern volatile unsigned int analog_value;
char a[5],R;
volatile double Thermister;

void adc_int()
{
 	ADMUX |= (1<<REFS0);                 // 5V internal reference volatge for adc
	ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);       //128 as prescalar for 125khz, interrupt eanble,adc is enable
    sei();   // global inetrrupt is enable
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
   analog_value=Fclose(temptable,analog_value);
   itoa(analog_value,a,10);    // integer is converted into asci string
   //R=((10230000/analog_value) - 10000);/* calculate the resistance */
  // Thermister = log(R);	/* calculate natural log of resistance */
   /* Steinhart-Hart Thermistor Equation: */
   /*  Temperature in Kelvin = 1 / (A + B[ln(R)] + C[ln(R)]^3)		*/
   /*  where A = 0.001129148, B = 0.000234125 and C = 8.76741*10^-8  */
   //Thermister = 1 / (0.001129148 + (0.000234125 * Thermister) + (0.0000000876741 * Thermister * Thermister * Thermister));
  // Thermister = Thermister - 273.15;/* convert kelvin to °C */
  //dtostrf(Thermister,3,2,a);
   USART_putstring(a);    //Pass the string to the USART_putstring function and sends it over the serial
   USART_putstring("  ");  //next line in usb tterminal
   _delay_ms(1000);        //Delay for 5 seconds so it will re-send the string every 5 seconds
    adc_start(0);         // adc start is called for next value
}