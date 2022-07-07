/*
 * main.c
 *
 *  Created on: May 19, 2022
 *      Author: Riad
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "util/delay.h"
u08 G_u08Custom0[8] = {0, 1, 1, 1, 3, 6, 28, 0};//
u08 G_u08Custom1[8] = {0, 0, 1, 1, 30, 0, 9, 0};//
u08 G_u08Custom2[8] = {4, 4, 4, 4, 7, 0, 0, 0};//
u08 G_u08Custom3[8] = {0, 18, 23, 9, 14, 16, 16, 0};//
u08 G_u08Custom4[8] = {0, 0, 0, 16, 16, 16, 15, 0};//
u08 G_u08Custom5[8] = {0, 4, 1, 1, 30, 0, 0, 0};//
u08 G_u08Custom6[8] = {0, 12, 18, 1, 31, 0, 2, 0};//
u08 G_u08Custom7[8] = {12, 18, 1, 31, 16, 16, 15, 0};//
u08 G_u08Heart[8] = {10, 21, 17, 27, 14, 4, 0, 0};
void main (void)
{
	HLCD_vInit();
	/*HLCD_vSendChar('R');
	HLCD_vSendChar('I');
	HLCD_vSendChar('A');
	HLCD_vSendChar('D');
	*/
	//DIO_vSetPortDir(DIO_PORTB,0x00);
	//DIO_vSetPortVal(DIO_PORTB,0xff);

	/*HLCD_vSaveCustomCharCGRAM(0,G_u08Custom0);
	HLCD_vSaveCustomCharCGRAM(1,G_u08Custom1);
	HLCD_vSaveCustomCharCGRAM(2,G_u08Custom2);
	HLCD_vSaveCustomCharCGRAM(3,G_u08Custom3);
	HLCD_vSaveCustomCharCGRAM(4,G_u08Custom4);
	HLCD_vSaveCustomCharCGRAM(5,G_u08Custom5);
	HLCD_vSaveCustomCharCGRAM(6,G_u08Custom6);
	HLCD_vSaveCustomCharCGRAM(7,G_u08Custom7);
	*/
	HLCD_vSaveCustomCharCGRAM(7,G_u08Heart);
	HLCD_vSetCursorPosition(0,10);
	HLCD_vSendChar(7);
	/*u08 L_u08LineLoction =1;
	u08 L_u08PatrbLoction = 15;
	HLCD_vPrintMyArabcName(L_u08LineLoction,L_u08PatrbLoction);
*/
while(1)
{
	/*if (DIO_u08GetPinVal(DIO_PORTB,DIO_PIN0)==0)
	{
		HLCD_vSendCommand(1);
		L_u08LineLoction=L_u08LineLoction-1;
		HLCD_vPrintMyArabcName(L_u08LineLoction,L_u08PatrbLoction);


	}
	else if (DIO_u08GetPinVal(DIO_PORTB,DIO_PIN1)==0)
		{
		HLCD_vSendCommand(1);
		L_u08PatrbLoction=L_u08PatrbLoction+1;
			HLCD_vPrintMyArabcName(L_u08LineLoction,L_u08PatrbLoction);


		}
	else if (DIO_u08GetPinVal(DIO_PORTB,DIO_PIN2)==0)
		{
		HLCD_vSendCommand(1);
		L_u08PatrbLoction=L_u08PatrbLoction-1;
			HLCD_vPrintMyArabcName(L_u08LineLoction,L_u08PatrbLoction);


		}
	else if (DIO_u08GetPinVal(DIO_PORTB,DIO_PIN3)==0)
		{
		HLCD_vSendCommand(1);
			L_u08LineLoction=L_u08LineLoction+1;
			HLCD_vPrintMyArabcName(L_u08LineLoction,L_u08PatrbLoction);


		}*/
for(u08 L_u08counter = 0 ;  L_u08counter<15 ;  L_u08counter++)
{

	_delay_ms(1000);
	HLCD_vSendCommand(1);
	_delay_ms(1000);
}







}

}
