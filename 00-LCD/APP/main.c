/*
 * main.c
 *
 *  Created on: May 19, 2022
 *      Author: Riad
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"

void main (void)
{
	HLCD_vInit();
	HLCD_vSendChar('R');
	HLCD_vSendChar('I');
	HLCD_vSendChar('A');
	HLCD_vSendChar('D');

while(1)
{}

}
