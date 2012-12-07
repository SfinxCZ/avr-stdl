/*
 * logger.h
 *
 *  Created on: Nov 23, 2012
 *      Author: sfinx
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdlib.h>

#define LEVEL_ALL 0
#define LEVEL_DEBUG 1
#define LEVEL_INFO 2
#define LEVEL_WARN 3
#define LEVEL_ERROR 4

static char* OUTPUT_SIGNATURES[] = {"", "D:", "I:", "W:", "E:"};

#define LCD_OUTPUT 1
#define UART_OUTPUT 2


#define OUTPUT_TYPE LCD_OUTPUT
#define OUTPUT_LEVEL LEVEL_ALL

#if OUTPUT_TYPE == LCD_OUTPUT
#include "lcd.h"

#elif OUTPUT_TYPE == UART_OUTPUT

#endif

extern void logDebug(char * data);
extern void logInfo(char * data);
extern void logWarn(char * data);
extern void logError(char * data);

extern void logDebug_int(uint8_t data);
extern void logInfo_int(uint8_t data);
extern void logWarn_int(uint8_t data);
extern void logError_int(uint8_t data);



#endif /* LOGGER_H_ */
