// lcd function to be include

#include "lib.h" // all avr library files
#define rs (1<<0)  // rs is set to pin no 0
#define en (1<<1)  //en is set to pin no 1 
#define data_bus PORTD //portd pin 2,3,4,5 as 4 bit is outputed to lcd data bus 4 pins 

void lcd_init(void)
{
DDRD |= (1<<4) | (1<<5) | (1<<6) | (1<<7); // Port d 4 pin (d4,5,6,7)is set as output
PORTD &= ~(1<<4) | ~(1<<5) | ~(1<<6) | ~(1<<7); // port d is set to 0; 
DDRB |= rs; // rs pin is set as ouput 
PORTB &= ~(rs); // rs pin is pull up transistor is on 
DDRB |= en; //en pin is set as ouput
PORTB &= ~(en); //en pin is pull up transistor is on
 }

void lcd_command(unsigned char command)
{
			data_bus=(data_bus & 0x0F) | (command & 0xF0); //higher order nibble command is put on port d to lcd bus
			PORTB &= ~(rs); //command register is selected
			PORTB |= en;  // high to low transition for falling edge triger lcd
			_delay_us(40); //refresh time
			PORTB &= ~(en);
			_delay_us(200);
			data_bus=(data_bus & 0x0F) | (command << 4); //lower order nibble command is put on port d to lcd bus
			PORTB &= ~(rs); //command register is selected
			PORTB |= en;  // high to low transition for falling edge triger lcd
			_delay_us(40); //refresh time
			PORTB &= ~(en);
			_delay_ms(2);
			
}

void lcd_data(unsigned char data)
{
	data_bus=(data_bus & 0x0F) | (data & 0xF0); //higher order nibble data is put on port d to lcd bus
	PORTB |= rs;  // data register is selected
	PORTB |= en; // high to low transition for falling edge triger lcd
	_delay_us(40); //refresh time
	PORTB &= ~(en);
	_delay_us(200);
	data_bus=(data_bus & 0x0F) | (data << 4); //lower order nibble data is put on port d to lcd bus
	PORTB |= rs;  // data register is selected
	PORTB |= en; // high to low transition for falling edge triger lcd
	_delay_us(40); //refresh time
	PORTB &= ~(en);
	_delay_ms(2);
}

void SendString(char *str)
{
	unsigned char i=0; //i is declare as char for pointer
	while(str[i]!='\0') // checking for null char
	{
		lcd_data(str[i]); // print that char on lcd
		i++; //incrementing i to next char 
	}
}