/*
 * lcd.h
 *
 *  Created on: Oct 7, 2012
 *      Author: stiborek
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

#define DPORT PORTA //Define Data port
#define DPDDR DDRA

#define CPORT PORTC //Define Signals port
#define CPDDR DDRC

#define RS PD5 //Signal Pins, Reset
#define EN PD7 //Signal Pins, Enable

#define LCDClear   0x01 //Clears LCD Display
#define LCD8bit   0x38 //Sets up LCD in 8bit mode
#define LCDCursorOn 0x0f //Enables Cursor
#define LCDSeek00   0x80 //Seeks the pointer to the begeining

void LCD(char ch);
void LCD_cmd(char ch);
void LCD_init(void);
void LCD_printStr(char *str);
int  LCD_printInt(unsigned int i);




#endif /* LCD_H_ */
