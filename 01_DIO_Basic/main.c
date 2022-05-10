/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Riad
 */
#include <avr/io.h>
#include <util/delay.h>
int main (void)
{


DDRA = 0b00001111;

while(1)
{
	PORTA=0b00000001;

	for(int i=0;i<4;i++){
	_delay_ms(1000);
	PORTA<<=PORTA;
	}

}

return 0;

}

