/*
 * pwm.c
 *
 * Created: 12/6/2017 2:54:39 PM
 *  Author: Rajesh Jat
 */ 

// Timer 0 is used as 8 bit mode

#include "lib.h"

void pwm_int()
{
  TCCR0A |= (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);
  TCCR0B |= (1<<CS00);
}