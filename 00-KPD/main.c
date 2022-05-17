/*
 * main.c
 *
 *  Created on: May 12, 2022
 *      Author: Riad
 */
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

void KPD_INIT(void)
{
	DDRA= 0x0f;
	PORTA=0xff;  /* To activate the column we write 0 so we have to deactivate */

}

u08 GetPressedKey (void)
{
	u08 Pressed_key = 0 ;
	for (u08 cols = 0 ; cols < 4 ; cols ++)
	{
		CLR_BIT(PORTB,cols);

		for (u08 row = 0 ; row<4;row++)
		{
			if (GET_BIT(PINB,row+4)==0)
			{
				Pressed_key = row + (cols * 4) + 1 ;/*num value*/
			}
			while (GET_BIT(PINB,row+4)==0)  //to solve bouncing problem //
			{}
			_delay_ms(10);
		}
		SET_BIT(PORTB,cols);
	}
return Pressed_key ;
}






int main (void)
{
	KPD_INIT();
	u08 key = 0;
	while (1)
	{
		key = GetPressedKey();
		if (key!=0)
		{
			//show the nub at the 7  segments
		}



	}
}


