/*
 * main.c
 *
 *  Created on: May 12, 2022
 *      Author: Riad
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
int main (void)
{

	DDRA= 0x0f;
	PORTA=0xf0;
	while (1)
	{
		for (int i = 0; i<4;i++)
		{
			TOG_BIT
			for (int j = 0 ; j<4;j++)
			{

			}
		}
	}
}


