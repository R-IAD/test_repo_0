/*
 * main.c
 *
 *  Created on: Jul 27, 2022
 *      Author: Riad
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/TMR/TMR_int.h"

static u08 G_u08Flag=0;

void toggle(void)
{
	G_u08Flag ++;
	DIO_vToglPinVal(DIO_PORTC,DIO_PIN3);
	if (G_u08Flag%2 ==0)
	{
		DIO_vToglPinVal(DIO_PORTC,DIO_PIN7);
	}
}

int main (void)
{
	GIE_vEnableGlobalInterrupt();
	DIO_vSetPinDir(DIO_PORTC,DIO_PIN3,DIO_OUTPUT);
	DIO_vSetPinDir(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	TMR_vInit();
	TMR_vSetPreloadValue(192);
	TMR_vSetInterval_OVF_Asynch(3906,toggle);
	//TMR_vSetInterval_CTC_Asynch(20000,150,toggle);
	TMR_vStartTMR();


	while(1)
	{

	}




}


/*
 * LED Intensity
 *
 * 		for (u08 i=0 ; i<254; i++)
		{
			TMR_vSetCompareValue(i);
			_delay_ms(100);
		}
		for (u08 i=0 ; i<254; i++)
		{
			TMR_vSetCompareValue(255-i);
			_delay_ms(100);
		}
 */
