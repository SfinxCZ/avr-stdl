/*
 * main.c
 *
 *  Created on: Oct 5, 2012
 *      Author: stiborek
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRA = 0xFF;
	while(1){
		PORTA = 0xff;
		_delay_ms(1000);
		PORTA = 0;
		_delay_ms(1000);
	}
	return 0;
}
