/*
 * main.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */


#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "util/delay.h"
#include "../MCAL/GIE/GIE_int.h"

volatile u16 adc_data;

void ADC_Isr(void)
{
	adc_data = ADC_u16GetADCData();



}



int main(void)
{
	ADC_vSetCallback(ADC_Isr);
	ADC_vInit();
	GIE_vEnableGlobalInterrupt();
	DIO_vSetPortDir(DIO_PORTC,DIO_OUTPUT);

	u16 L_ADC_Val = 0 ;
	u08 L_ValAftrScal =0;

	while (1)
	{
	L_ADC_Val = ADC_u16AnalogRead(0);
	L_ValAftrScal = L_ADC_Val * (0.249) ;

	switch(L_ValAftrScal)
	{
	case 0:
		DIO_vSetPortVal(DIO_PORTC,0);break;
	case 0b00000001:
		DIO_vSetPortVal(DIO_PORTC,0b00000001);break;
	case 0b00000011:
		DIO_vSetPortVal(DIO_PORTC,0b00000011);break;
	case 0b00000111:
		DIO_vSetPortVal(DIO_PORTC,0b00000111);break;
	case 0b00001111:
		DIO_vSetPortVal(DIO_PORTC,0b00001111);break;
	case 0b00011111:
		DIO_vSetPortVal(DIO_PORTC,0b00011111);break;
	case 0b00111111:
		DIO_vSetPortVal(DIO_PORTC,0b00111111);break;
	case 0b01111111:
		DIO_vSetPortVal(DIO_PORTC,0b01111111);break;
	case 0b11111111:
		DIO_vSetPortVal(DIO_PORTC,0b11111111);break;

	}





	}
}

/*	if ((L_ValAftrScal>=0)&&(L_ValAftrScal<0.625))
	{
		DIO_vSetPortVal(DIO_PORTC,0);
	}
	else if((L_ValAftrScal>=0.625)&&(L_ValAftrScal<1.25))
	{
		DIO_vSetPortVal(DIO_PORTC,0b00000001);
	}

	else if((L_ValAftrScal>=1.25)&&(L_ValAftrScal<1.875))
		{
		DIO_vSetPortVal(DIO_PORTC,0b00000011);
		}
	else if((L_ValAftrScal>=1.875)&&(L_ValAftrScal<2.5))
		{
		DIO_vSetPortVal(DIO_PORTC,0b00000111);
		}
	else if((L_ValAftrScal>=2.5)&&(L_ValAftrScal<3.125))
		{
		DIO_vSetPortVal(DIO_PORTC,0b00001111);
		}
	else if((L_ValAftrScal>=3.125)&&(L_ValAftrScal<3.75))
		{
		DIO_vSetPortVal(DIO_PORTC,0b00011111);
		}
	else if((L_ValAftrScal>=3.75)&&(L_ValAftrScal<4.375))
		{
		DIO_vSetPortVal(DIO_PORTC,0b00111111);
		}
	else
	{
		DIO_vSetPortVal(DIO_PORTC,0xff);
	}
 * */





