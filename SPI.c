/*
 * SPI.c
 *
 * Created: 1/12/2018 11:29:00 AM
 *  Author: Rajesh Jat
 */ 

#include "lib.h"

//pins used for spi
#define MOSI   PORTB3
#define MISO   PINB4
#define SCK    PORTB5
#define SS     PORTB2   // ss pin not used because single slave

void SPI_master_init(void)
{
  DDRB |= (1<<MOSI) | (1<<SCK);
  DDRB &= (~(1<<MISO));
  SPCR |= (1<<SPE) | (1<<MSTR);
}

void SPI_slave_init(void)
{
	DDRB &= (~(1<<MOSI)) | (~(1<<SCK));
	DDRB |= (1<<MISO);
	SPCR |= (1<<SPE);
}

void SPI_transmit(uint8_t *data)
{
   SPDR = *data;
   while(!(SPSR & (1<<SPIF)));
}

uint8_t SPI_receiver(void)
{
  while(!(SPSR & (1<<SPIF)));
  return (SPDR);
}