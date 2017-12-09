/*
 * usart.h
 *
 * Created: 12/8/2017 11:56:48 AM
 *  Author: Rajesh Jat
 */ 


#ifndef USART_H_
#define USART_H_

void USART_init(void);

unsigned char USART_receive(void);

void USART_send( unsigned char data);

void USART_putstring(char* StringPtr);

#endif /* USART_H_ */