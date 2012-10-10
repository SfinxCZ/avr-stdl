#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

int main(void) {
	lcd_init(LCD_DISP_ON); /* initialize display, cursor off */


	while (1) /* loop forever */
	{
		lcd_home();
		lcd_clrscr(); /* clear the screen*/
		lcd_puts("test program 1"); /* displays the string on lcd*/
		lcd_gotoxy(0,1);
		_delay_ms(1000);
		lcd_puts("test program 2"); /* displays the string on lcd*/
		lcd_gotoxy(0,2);
		_delay_ms(1000);
		lcd_puts("test program 3"); /* displays the string on lcd*/
		lcd_gotoxy(0,3);
		_delay_ms(1000);
		lcd_puts("test program 4"); /* displays the string on lcd*/
		_delay_ms(1000);

	}
	return 0;
}

