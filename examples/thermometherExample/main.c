/*
 * main.c
 *
 *  Created on: Oct 8, 2012
 *      Author: sfinx
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "lcd.h"
#include "ds18x20.h"
#include "onewire.h"
#include "logger.h"

#define MAXSENSORS 5

#define NEWLINESTR "\r\n"


uint8_t gSensorIDs[MAXSENSORS][OW_ROMCODE_SIZE];


static uint8_t search_sensors(void)
{
	uint8_t i;
	uint8_t id[OW_ROMCODE_SIZE];
	uint8_t diff, nSensors;

	logInfo("Scanning Bus");

	ow_reset();

	nSensors = 0;

	diff = OW_SEARCH_FIRST;
	while ( diff != OW_LAST_DEVICE && nSensors < MAXSENSORS ) {
		DS18X20_find_sensor( &diff, &id[0] );

		if( diff == OW_PRESENCE_ERR ) {
			logError( "No Sensor found"  );
			break;
		}

		if( diff == OW_DATA_ERR ) {
			logError( "Bus Error"  );
			break;
		}

		for ( i=0; i < OW_ROMCODE_SIZE; i++ )
			gSensorIDs[nSensors][i] = id[i];

		nSensors++;
	}

	return nSensors;
}

static void uart_put_temp(int16_t decicelsius)
{
	char s[10];

	logInfo_int( decicelsius );
	logInfo(" deci°C, ");
	DS18X20_format_from_decicelsius( decicelsius, s, 10 );
	logInfo( s );
	logInfo(" °C");
}

int main( void )
{
	uint8_t nSensors, i;
	int16_t decicelsius;
	uint8_t error;

	lcd_init(LCD_DISP_ON);

#ifndef OW_ONE_BUS
	ow_set_bus(&PIND,&PORTD,&DDRD,PD6);
#endif

	sei();

	logDebug("DS18X20 1-Wire-Reader Demo by Martin Thomas");
	logDebug("-------------------------------------------");

	nSensors = search_sensors();
	logInfo_int( (int)nSensors );
	logInfo( " DS18X20 Sensor(s) available:");

	for ( i = 0; i < nSensors; i++ ) {
		logInfo( "Sensor# " );
		logInfo_int( (int)i+1 );
		logInfo( " is a " );
		if ( gSensorIDs[i][0] == DS18S20_FAMILY_CODE ) {
			logInfo( "DS18S20/DS1820" );
		} else if ( gSensorIDs[i][0] == DS1822_FAMILY_CODE ) {
			logInfo( "DS1822" );
		}
		else {
			logInfo( "DS18B20" );
		}
		logInfo( " which is " );
		if ( DS18X20_get_power_status( &gSensorIDs[i][0] ) == DS18X20_POWER_PARASITE ) {
			logInfo( "parasite" );
		} else {
			logInfo( "externally" );
		}
		logInfo( " powered" );
	}

	if ( nSensors == 1 ) {
		logWarn( "There is only one sensor -> Demo of \"DS18X20_read_decicelsius_single\":"  );
		i = gSensorIDs[0][0]; // family-code for conversion-routine
		DS18X20_start_meas( DS18X20_POWER_PARASITE, NULL );
		_delay_ms( DS18B20_TCONV_12BIT );
		DS18X20_read_decicelsius_single( i, &decicelsius );
		uart_put_temp( decicelsius );
	}




	for(;;) {   // main loop

		lcd_clrscr();
		error = 0;

		if ( nSensors == 0 ) {
			error++;
		}

		//logInfo("Convert_T and Read Sensor by Sensor (reverse order)");
		for ( i = nSensors; i > 0; i-- ) {
			if ( DS18X20_start_meas( DS18X20_POWER_PARASITE,
				&gSensorIDs[i-1][0] ) == DS18X20_OK ) {
				_delay_ms( DS18B20_TCONV_12BIT );
				logInfo( "Sensor# " );
				logInfo_int( (int) i );
				logInfo(" = ");
				if ( DS18X20_read_decicelsius( &gSensorIDs[i-1][0], &decicelsius)
				     == DS18X20_OK ) {
					uart_put_temp( decicelsius );
				} else {
					logError( "CRC Error" );
					error++;
				}
			}
			else {
				logError( "Start meas. failed" );
				error++;
			}
		}

		//logError("Convert_T for all Sensors and Read Sensor by Sensor");
		if ( DS18X20_start_meas( DS18X20_POWER_PARASITE, NULL )
			== DS18X20_OK) {
			_delay_ms( DS18B20_TCONV_12BIT );
			for ( i = 0; i < nSensors; i++ ) {
				logInfo( "Sensor# " );
				logInfo_int( (int)i + 1 );
				logInfo(" = ");
				if ( DS18X20_read_decicelsius( &gSensorIDs[i][0], &decicelsius )
				     == DS18X20_OK ) {
					uart_put_temp( decicelsius );
				}
				else {
					logError( "CRC Error" );
					error++;
				}
			}
		}
		else {
			logError( "Start meas. failed" );
			error++;
		}

		if ( error ) {
			//logError( "*** problems - rescanning bus ..." );
			nSensors = search_sensors();
			//logError_int( (int) nSensors );
			logError_int( 5 );
			logError( " DS18X20 Sens. av");
			error = 0;
		}

		_delay_ms(3000);
	}
}

