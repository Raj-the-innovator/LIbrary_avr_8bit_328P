/*
 * IncFile1.h
 *
 * Created: 10/14/2017 1:57:44 PM
 *  Author: Administrator
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
 
 //function proto type
 
void SendString(char *);

void lcd_init(void);

void lcd_command(unsigned char);

void lcd_data(unsigned char);

#endif /* INCFILE1_H_ */