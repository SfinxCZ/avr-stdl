//-------------------------------------------------------- Start
#include "lcd.h"

void LCD(char ch) {
	DPORT = ch; //Put values to ports
	CPORT = (1 << RS) | (1 << EN); //Signaling to send data
	_delay_us(10);
	CPORT = (1 << RS) | (0 << EN);
	_delay_us(45);
}

void LCD_cmd(char ch) {
	DPORT = ch;
	CPORT = (0 << RS) | (1 << EN); //Signaling to send commands
	_delay_us(10);
	CPORT = (0 << RS) | (0 << EN);
	_delay_us(45);
	if (ch == 0x01 || ch == 0x02)
		_delay_ms(2);

}

void LCD_init(void) {

	DPDDR = 0xff;
	CPDDR = 0xf0;

	LCD_cmd(LCD8bit);
	LCD_cmd(LCDCursorOn);
	LCD_cmd(LCDClear);
	LCD_cmd(LCDSeek00);
}

void LCD_printStr(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		DPORT = str[i]; //Put values to ports
		LCD(str[i]);
		i++;
	}
}
int LCD_printInt(unsigned int i) {
	static int a;
	a = 0;
	if (i != 0) {
		LCD_printInt(i / 10);
		LCD('0' +i % 10);
		a++;
	}
	return a;
}
//-------------------------------------------------------- End
