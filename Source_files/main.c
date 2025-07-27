# define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>  

#define DEBOUNCE_DELAY 50

#define EN 6
#define RW 5
#define RS 4

void lcd_init();
void lcdcmd(unsigned char cmd);
void lcddata(unsigned char data);
void lcd_print(char *str);

void lcd_init()
{
	DDRD=0xff;
	PORTD=PORTD & ~(1<<EN);
	lcdcmd(0x33);
	lcdcmd(0x32);
	lcdcmd(0x0E);
	lcdcmd(0x01);
	_delay_ms(1);
}

void lcdcmd(unsigned char cmd)
{
	PORTD &=~(1<<RS);
	PORTD &=~(1<<RW);
	PORTD=(PORTD & 0xf0) | (cmd>>4);
	PORTD |=(1<<EN);
	_delay_ms(1);
	PORTD &=~(1<<EN);
	PORTD=(PORTD & 0xf0) | (cmd & 0x0f );
	PORTD |=(1<<EN);
	_delay_ms(1);
	PORTD &=~(1<<EN);
}

void lcddata(unsigned char data)
{
	PORTD |=(1<<RS);
	PORTD &=~(1<<RW);
	PORTD= (PORTD & 0xf0) | (data>>4);
	PORTD |=(1<<EN);
	_delay_ms(1);
	PORTD &=~(1<<EN);
	PORTD= (PORTD & 0xf0) | (data & 0x0f);
	PORTD |=(1<<EN);
	_delay_ms(1);
	PORTD &=~(1<<EN);
}

void lcd_print(char *str)
{
	unsigned char i = 0;
	while(str[i]!=0)
	{
		lcddata(str[i]);
		i++;
	}
}

void check(unsigned recived)
{
	 unsigned char enc[36] = { 0b101011, 0b011010, 0b110001, 0b000111, 0b100010, 0b111000,
		 0b010110, 0b001011, 0b111101, 0b101000, 0b010001, 0b011111,
		 0b000100, 0b110010, 0b001101, 0b100111, 0b011000, 0b101110,
		 0b111011, 0b000011, 0b110100, 0b001000, 0b010100, 0b101001,
		 0b011100, 0b000101, 0b100000, 0b111110, 0b001111, 0b010011,
		 0b100101, 0b111001, 0b000010, 0b011010, 0b110011, 0b101100};


	
	char dec[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z'};
	unsigned char i=0;
	
	for(i=0; i<36; i++)
	{
		if (recived==enc[i])
		{
			char display_char[2] = {dec[i], '\0'};  
			lcd_print(display_char);  
			break;
		}
	}
	
	
}
int main(void)
{
	unsigned char received_bits = 0;
	unsigned char bit_count = 0;
	DDRA = 0x00;  
	PORTA = 0xFF; 
	DDRB = 0xFF;  
	lcd_init();
	while(1)
	{
		while (bit_count < 6) 
	{
		
		if ((PINA & 0x01) == 0) 
		{
			_delay_ms(DEBOUNCE_DELAY);  
			if ((PINA & 0x01) == 0)
			{
				received_bits = (received_bits << 1);
				bit_count++; 
				while ((PINA & 0x01) == 0);
			}
		}
		else if ((PINA & 0x02) == 0) 
		{
			_delay_ms(DEBOUNCE_DELAY);  
			if ((PINA & 0x02) == 0)
			{
				received_bits = (received_bits << 1) | 1;
				bit_count++;  
				while ((PINA & 0x02) == 0);
			}
		}
	}
	check(received_bits);
	received_bits=0;
	bit_count=0;  
}
}
