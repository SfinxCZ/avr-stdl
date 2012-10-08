#include <avr/io.h>
#include "lcd.h"

int main() {
	DDRA = 0xff;
	DDRC = 0xff;

	_delay_ms(500);
	LCD_init();

	LCD('A');
	LCD('H');
	LCD('O');
	LCD('J');

	while(1){

	}
/*
	LCD_printStr("Circuits Today");
	_delay_ms(5000);
	LCD_cmd(0x01);
	LCD_printStr("Print an Integer");
	LCD_cmd(0xc0);
	LCD_printInt(990);
*/
	return 0;
}