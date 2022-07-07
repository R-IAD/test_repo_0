/*
 * DIO_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include <avr/io.h>

#include "DIO_int.h"

void DIO_vSetPinDir (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Dir)
{
	if (A_u08Dir==DIO_OUTPUT)
	{
		switch(A_u08PortNo)
		{
		case DIO_PORTA :
			SET_BIT(DDRA,A_u08PinNo);
			break;
		case DIO_PORTB :
			SET_BIT(DDRB,A_u08PinNo);
			break;
		case DIO_PORTC :
			SET_BIT(DDRC,A_u08PinNo);
			break;
		case DIO_PORTD :
			SET_BIT(DDRD,A_u08PinNo);
			break;
		}
	}
	else if(A_u08Dir==DIO_INPUT)
	{
		switch(A_u08PortNo)
		{
		case DIO_PORTA :
			   CLR_BIT(DDRA,A_u08PinNo);
			   break;
		case DIO_PORTB :
			   CLR_BIT(DDRB,A_u08PinNo);
			   break;
		case DIO_PORTC :
			   CLR_BIT(DDRC,A_u08PinNo);
			   break;
		case DIO_PORTD :
			   CLR_BIT(DDRD,A_u08PinNo);
			   break;
	}


}}
void DIO_vSetPinVal (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Val)
{
	if (A_u08Val==DIO_HIGH)
	{
		switch(A_u08PortNo)
		{
		case DIO_PORTA :
			SET_BIT(PORTA,A_u08PinNo);
			break;
		case DIO_PORTB :
			SET_BIT(PORTA,A_u08PinNo);
			break;
		case DIO_PORTC :
			SET_BIT(PORTC,A_u08PinNo);
			break;
		case DIO_PORTD :
			SET_BIT(PORTD,A_u08PinNo);
			break;
		}
	}
	else if(A_u08Val==DIO_LOW)
	{
		switch(A_u08PortNo)
		{
		case DIO_PORTA :
			   CLR_BIT(PORTA,A_u08PinNo);
			   break;
		case DIO_PORTB :
			   CLR_BIT(PORTB,A_u08PinNo);
			   break;
		case DIO_PORTC :
			   CLR_BIT(PORTC,A_u08PinNo);
			   break;
		case DIO_PORTD :
			   CLR_BIT(PORTD,A_u08PinNo);
			   break;
	}

}}
u08 DIO_u08GetPinVal(u08 A_u08PortNo , u08 A_u08PinNo)
{

	u08 L_u08PinVal = 0;


	switch(A_u08PortNo)
	{
	case DIO_PORTA :
		L_u08PinVal =GET_BIT(PINA,A_u08PinNo);
		break;
	case DIO_PORTB :
		L_u08PinVal =GET_BIT(PINB,A_u08PinNo);
		break;
	case DIO_PORTC :
		L_u08PinVal =GET_BIT(PINC,A_u08PinNo);
		break;
	case DIO_PORTD :
		L_u08PinVal =GET_BIT(PIND,A_u08PinNo);
		break;
	}

	return L_u08PinVal;
}
void DIO_vSetPortDir(u08 A_u08PortNo , u08 A_u08Dir)
{
	switch(A_u08PortNo)
	{
	case DIO_PORTA :
		DDRA=A_u08Dir;
		break;
	case DIO_PORTB :
		DDRB=A_u08Dir;
		break;
	case DIO_PORTC :
		DDRC=A_u08Dir;
		break;
	case DIO_PORTD :
		DDRD=A_u08Dir;
		break;

}
}
void DIO_vSetPortVal(u08 A_u08PortNo , u08 A_u08Val)
{
	switch(A_u08PortNo)
	{
	case DIO_PORTA :
		PORTA=A_u08Val;
		break;
	case DIO_PORTB :
		PORTB=A_u08Val;
		break;
	case DIO_PORTC :
		PORTC=A_u08Val;
		break;
	case DIO_PORTD :
		PORTD=A_u08Val;
		break;

}
}
/*u08  DIO_u08GetPortVal(u08 A_u08PortNo)
{

}*/

void DIO_vToglPinVal(u08 A_u08PortNo , u08 A_u08PinNo)
{
	switch(A_u08PortNo)
	{
	case DIO_PORTA :
		TOG_BIT(PORTA,A_u08PinNo);
		break;
	case DIO_PORTB :
		TOG_BIT(PORTB,A_u08PinNo);
		break;
	case DIO_PORTC :
		TOG_BIT(PORTC,A_u08PinNo);
		break;
	case DIO_PORTD :
		TOG_BIT(PORTD,A_u08PinNo);
		break;
	}


}

