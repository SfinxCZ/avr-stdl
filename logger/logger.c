/*
 * logger.c
 *
 *  Created on: Nov 23, 2012
 *      Author: sfinx
 */

#include "logger.h"

void _write(char * data){
#if OUTPUT_TYPE == LCD_OUTPUT
	lcd_puts(data);
#elif OUTPUT_TYPE == UART_OUTPUT
	//needs to be implemented
#endif
}

void write(int level, char * data){
	if(level >= OUTPUT_LEVEL){
		_write(OUTPUT_SIGNATURES[level]);
		_write(data);
		_write("\n");
	}
}

char * intToChar(uint8_t number){
	char buf[5];

	// convert 123 to string [buf]
	utoa(number, buf, 10);
	return buf;
}

//Strings
void logError(char * data){
	write(LEVEL_ERROR, data);
}

void logWarn(char * data){
	write(LEVEL_WARN, data);
}

void logInfo(char * data){
	write(LEVEL_INFO, data);
}

void logDebug(char * data){
	write(LEVEL_DEBUG, data);
}

//Integers
void logError_int(uint8_t data){
	write(LEVEL_ERROR, intToChar(data));
}

void logWarn_int(uint8_t data){
	write(LEVEL_WARN, intToChar(data));
}

void logInfo_int(uint8_t data){
	write(LEVEL_INFO, intToChar(data));
}

void logDebug_int(uint8_t data){
	write(LEVEL_DEBUG, intToChar(data));
}
