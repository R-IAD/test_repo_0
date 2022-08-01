/*
 * KPD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */
#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KPD_int.h"
#include <util/delay.h>

void KPD_vInit(void)
{

	DIO_vSetPortDir(KPD_PORT,0x0f);
	DIO_vSetPortVal(KPD_PORT,0xff);  /* To activate the column we write 0 so we have to deactivate */


}


u08 KPD_u08GetPressedKey (void)
{
	u08 Pressed_key = 0 ;
	for (u08 cols = 0 ; cols < 4 ; cols ++)
	{
DIO_vSetPinVal(KPD_PORT,cols,DIO_LOW);
		for (u08 row = 0 ; row<4;row++)
		{
			if (DIO_u08GetPinVal(KPD_PORT,row+4)==0)
			{
				Pressed_key = row + (cols * 4) + 1 ;/*num value*/
			}
			while (DIO_u08GetPinVal(KPD_PORT,row+4)==0)  //to solve bouncing problem //
			{}
			_delay_ms(10);
		}
		DIO_vSetPinVal(KPD_PORT,cols,DIO_HIGH);
	}
return Pressed_key ;
}
