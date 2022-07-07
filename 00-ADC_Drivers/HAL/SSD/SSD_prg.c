/*
 * SSD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */
#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_int.h"

static const u08 CGS_u08SSD_Nums[10]={0b00111111,
						       	   0b00000110,
						       	   0b01011011,
						       	   0b01001111,
						       	   0b01100110,
						       	   0b01101101,
						       	   0b01111101,
						       	   0b00000111,
						       	   0b01111111,
						       	   0b01101111
						       		};


void SSD_vInit(void)
{
	DIO_vSetPortDir(SSD1_PORT,0xff);

}



void SSD_vDisplayNum(u08 A_u08Num)
{
	/* input validation */
	if (A_u08Num < 10)
	{
#if SSD_TYPE==COM_CATHODE
		DIO_vSetPortVal(SSD1_PORT,  CGS_u08SSD_Nums[A_u08Num]);
#elif SSD_TYPE==COM_ANODE
		DIO_vSetPortVal(SSD1_PORT, ~CGS_u08SSD_Nums[A_u08Num]);
#endif
	}
}


void SSD_vTurnOff(void)
{
#if SSD_TYPE==COM_CATHODE
	DIO_vSetPortVal(SSD1_PORT,0);
#elif SSD_TYPE==COM_ANODE
	DIO_vSetPortVal()(SSD1_PORT,0xff);
#endif
}


