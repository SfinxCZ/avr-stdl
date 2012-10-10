/*
 * main.c
 *
 *  Created on: Oct 8, 2012
 *      Author: sfinx
 */

#include <avr/io.h>
#include <util/delay.h>


#include "lcd.h"

int main(){
	lcd_init(LCD_DISP_ON); /* initialize display, cursor off */


	while (1) /* loop forever */
	{
		lcd_home();
		lcd_clrscr(); /* clear the screen*/
		lcd_puts("test program 0"); /* displays the string on lcd*/
		lcd_putc(lcd_getxy());
		lcd_gotoxy(0,1);
		_delay_ms(1000);
		lcd_puts("test program 55"); /* displays the string on lcd*/
		lcd_putc(lcd_getxy());
		lcd_gotoxy(0,2);
		_delay_ms(1000);
		lcd_puts("test program 32"); /* displays the string on lcd*/
		lcd_putc(lcd_getxy());
		lcd_gotoxy(0,3);
		_delay_ms(1000);
		lcd_puts("test program 40"); /* displays the string on lcd*/
		lcd_putc(lcd_getxy());
		_delay_ms(1000);

	}
	return 0;
}
