/*
 * LCD_prg.c
 *
 *  Created on: May 19, 2022
 *      Author: Riad
 */
#include "../../LIB/STD_TYPES.h"
#include "LCD_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_cgf.h"

/*
u08 G_u08Custom1[8] = {1, 1, 2, 2, 2, 28, 0, 0};
u08 G_u08Custom2[8] = {0, 0, 1, 1, 30, 0, 9, 0};
u08 G_u08Custom3[8] = {4, 4, 4, 4, 7, 0, 0, 0};
u08 G_u08Custom4[8] = {0, 18, 23, 9, 14, 16, 16, 0};
u08 G_u08Custom5[8] = {0, 0, 0, 16, 16, 16, 15, 0};
u08 G_u08Custom6[8] = {0, 4, 1, 1, 30, 0, 0, 0};
u08 G_u08Custom7[8] = {0, 12, 18, 1, 31, 0, 2, 0};
u08 G_u08Custom8[8] = {12, 18, 1, 31, 16, 16, 15, 0};
*/

void HLCD_vSendCommand (u08 A_u08Command)
{
	//RS -> low to command
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN, DIO_LOW);

	//RW  -> Low t write
	DIO_vSetPinVal(LCD_CTRL_PORT ,LCD_RW_PIN, DIO_LOW);

	//Write the data
	DIO_vSetPortVal(LCD_DATA_PORT ,A_u08Command );

	/* Pulse to Enable */
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}



void HLCD_vSendChar (u08 A_u08Char)
{
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN, DIO_HIGH);
	DIO_vSetPinVal(LCD_CTRL_PORT ,LCD_RW_PIN, DIO_LOW);
	DIO_vSetPortVal(LCD_DATA_PORT , A_u08Char);

	/* Pulse to Enable */
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}






void HLCD_vInit (void)
{
	/*set pin direction */
	DIO_vSetPortDir(LCD_DATA_PORT, 0xff);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	/* start initialize sequence from data sheet */

	_delay_ms(50);


	HLCD_vSendCommand (0b00111000);

	_delay_ms(1);

	HLCD_vSendCommand (0b00001100);

	_delay_ms(1);

	HLCD_vSendCommand (0b00000001);

	_delay_ms(3);

	HLCD_vSendCommand(0b00000110);

	_delay_ms(1);





}





void HLCD_vPrintString (char A_s08String[])
{
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN, DIO_HIGH);
	DIO_vSetPinVal(LCD_CTRL_PORT ,LCD_RW_PIN, DIO_LOW);

	u08 L_u08Counter = 0;

	while(A_s08String[L_u08Counter] != '\0')
		{
			DIO_vSetPortVal(LCD_DATA_PORT , A_s08String[L_u08Counter]);
			L_u08Counter ++;
		}


	/* Pulse to Enable */

	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}










void HLCD_vPrintNumber (s32 A_s32Number)
{
	u08 L_u08Digits[10] = {0};
	u08 L_u08Counter = 0;

	//TODO: Implement negative numbers
	//TODO: Handle the corner zero at the first unite

	while (A_s32Number > 0)
	{
		L_u08Digits[L_u08Counter] = A_s32Number%10;
		L_u08Counter++;
		A_s32Number/= A_s32Number;
	}

	for (s08 L_s08PrntIndx = 0 ; L_s08PrntIndx >= 0 ; L_s08PrntIndx--)
	{
		HLCD_vSendChar('0' + L_u08Digits[L_s08PrntIndx]);


	}


}







void HLCD_vSetCursorPosition (u08 A_u08Row,u08 A_u08Col)
{

	u08 L_u08DdRamAdress ;
	u08 L_u08Command ;

	if ((A_u08Row <= MAX_INDX_OF_ROW) && (A_u08Col <= MAX_INDX_OF_COL))
	{
		if (A_u08Row==FIRST_ROW_INDX)
		{
			L_u08DdRamAdress = FIRST_ROW_START + A_u08Col ;
		}
		else
		{
			L_u08DdRamAdress = SEC_ROW_START + A_u08Col ;

		}


		/** summing 0b10000000 to the equation to set the 7th bit the same operation if you did or-> | **/
		L_u08Command = L_u08DdRamAdress + SET_ADRS_CUNTR_MASK ;

		HLCD_vSendCommand (L_u08Command);
	}

	else
	{
		//do nothing
	}
}








void HLCD_vSaveCustomCharCGRAM (u08 A_u08PatternIndx , u08 *A_u08PatternVal)
{
	u08 L_u08LoopIterator =0;
	/*Step 1 : set address counter on CGRAM 0b01******  first 2 bits must be 01*/
	switch(A_u08PatternIndx)
	{
	case 0 : HLCD_vSendCommand(0x40); break ;
	case 1 : HLCD_vSendCommand(0x48); break ;
	case 2 : HLCD_vSendCommand(0x50); break ;
	case 3 : HLCD_vSendCommand(0x58); break ;
	case 4 : HLCD_vSendCommand(0x60); break ;
	case 5 : HLCD_vSendCommand(0x68); break ;
	case 6 : HLCD_vSendCommand(0x70); break ;
	case 7 : HLCD_vSendCommand(0x78); break ;
	/* default : Report Error ; break; */

	}


	/*Step 2 : Write custom pattern */
	for (L_u08LoopIterator =0; L_u08LoopIterator < 8 ; L_u08LoopIterator ++)
	{
	HLCD_vSendChar(A_u08PatternVal[L_u08LoopIterator]);
	}

	/*Step 3 : to call the address counter to DDRAM again call GoTo function*/
	HLCD_vSendCommand(0x80);


}



void HLCD_vPrintMyArabcName(u08 A_u08Line ,u08 A_u08FirstLocation )
{
	HLCD_vSetCursorPosition(0,A_u08FirstLocation);
	HLCD_vSendChar(0);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-1);
	HLCD_vSendChar(1);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-2);
	HLCD_vSendChar(2);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-3);
	HLCD_vSendChar(3);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-4);
	HLCD_vSendChar(4);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-5);
	HLCD_vSendChar(0b00010000);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-6);
	HLCD_vSendChar(5);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-7);
	HLCD_vSendChar(2);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-8);
	HLCD_vSendChar(6);
	HLCD_vSetCursorPosition(0,A_u08FirstLocation-9);
	HLCD_vSendChar(7);
}

//void HLCD_vDisplayCustomChar (u08 A_u08CGRamIndx )
//{

//}







