// lcd function to be include

#include "lib.h" // all avr library files
#define rs (1<<0)  // rs is set to pin no 0
#define en (1<<1)  //en is set to pin no 1 
#define data_bus PORTD //portd is outputed to lcd data bus

void lcd_init(void)
{
DDRD = 0xFF; // Port d is set as input
PORTD = 0; // port d is set to 0; 
DDRB |= rs; // rs pin is set as ouput 
PORTB &= ~(rs); // rs pin is pull up transistor is on 
DDRB |= en; //en pin is set as ouput
PORTB &= ~(en); //en pin is pull up transistor is on
 }

void lcd_command(unsigned char command)
{
			data_bus=command; //command is put on port d to lcd bus
			PORTB &= ~(rs); //command register is selected
			PORTB |= en;  // high to low transition for falling edge triger lcd
			_delay_us(40); //refresh time
			PORTB &= ~(en);
}

void lcd_data(unsigned char data)
{
	data_bus=data;  // data isput on portd to lcd bus
	PORTB |= rs;  // data register is selected
	PORTB |= en; // high to low transition for falling edge triger lcd
	_delay_us(40); //refresh time
	PORTB &= ~(en);
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