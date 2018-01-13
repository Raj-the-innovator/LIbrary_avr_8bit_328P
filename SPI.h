/*
 * SPI.h
 *
 * Created: 1/12/2018 11:29:16 AM
 *  Author: Rajesh jat
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_init(void);

void SPI_transmit(uint8_t *data);

uint8_t  SPI_receiver(void);

#endif /* SPI_H_ */