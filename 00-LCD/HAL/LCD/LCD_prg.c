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





}

void HLCD_vSetCursorPosition (u08 A_u08LinePosition , u08 A_u08LineNumber)
{}
















