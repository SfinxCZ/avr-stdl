//-------------------------------------------------------- Start
#include <avr/io.h>
#include <util/delay.h>

#define DPORT PORTA //Define Data port
#define DPDDR DDRA

#define CPORT PORTC //Define Signals port
#define CPDDR DDRC

#define RS PC5 //Signal Pins, Reset
#define EN PC7 //Signal Pins, Enable
//Pre-defining Commands
#define LCDClear 0x01 //Clears LCD Display
#define LCD8bit 0x38 //Sets up LCD in 8bit mode
#define LCDCursorOn 0x0f //Enables Cursor
#define LCDSeek00 0x80 //Seeks the pointer to the begeining
void LCD(char ch);
void LCDcmd(char ch);
void LCDInitialize(void);

int main() {
	DPDDR = 0xff;
	CPDDR = 0xf0;

	_delay_ms(2000);

	LCDInitialize();
	LCD('C');
	LCD('i');
	LCD('r');
	LCD('c');
	LCD('u');
	LCD('i');
	LCD('t');
	LCD('s');
	LCD(' ');
	LCD('T');
	LCD('o');
	LCD('d');
	LCD('a');
	LCD('y');
	return 0;
}
void LCD(char ch) {
	DPORT = ch; //Put values to ports
	CPORT = (1 << RS) | (1 << EN); //Signaling to send data
	_delay_us(10);
	CPORT = (1 << RS) | (0 << EN);
	_delay_us(45);
}

void LCDcmd(char ch) {
	DPORT = ch;
	CPORT = (0 << RS) | (1 << EN); //Signaling to send commands
	_delay_ms(10);
	CPORT = (0 << RS) | (0 << EN);
	_delay_ms(45);
	if (ch == 0x01 || ch == 0x02) // If commands are LCD Clear or
	// LCDSeek00, delay 2mS
		_delay_ms(2);
}

void LCDInitialize(void) {
	LCDcmd(LCD8bit);
	LCDcmd(LCDCursorOn);
	LCDcmd(LCDClear);
	LCDcmd(LCDSeek00);
}
//-------------------------------------------------------- End

