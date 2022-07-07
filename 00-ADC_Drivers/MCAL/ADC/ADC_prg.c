/*
 * ADC_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_prv.h"

#include "ADC_cfg.h"


void (*ADC_Callback)(void);

void ADC_vInit(void)
{
	/*1- Reference voltage selection */
//#if ADC_REF_VOLT==AVCC
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
//#elif ADC_REF_VOLT==INTERNAL_REF_VOLTAGE
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
//#elif ADC_REF_VOLT==AVCC
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
//#else
//#error "select correct voltage"
//#endif
	/*2- Data adjustment direction*/

	CLR_BIT(ADMUX,ADLAR);

	/*3- pre scaler Bits selection*/

	ADCSRA =(ADCSRA & 0xf8) | (ADC_PRESCALER) ;

	/*4- auto trigger enable*/
	 /*4a- Auto trigger source*/

	CLR_BIT(ADCSRA,ADATE);

	/*5- Interrupt Enable/Disable*/
#if ADC_INTERRUPT_ENABLE==DISABLE
	CLR_BIT(ADCSRA,ADIE);
#elif ADC_INTERRUPT_ENABLE==ENABLE
	SET_BIT(ADCSRA,ADIE);
#endif

	/*6- Enable ADC peripheral*/

	SET_BIT(ADCSRA,ADEN);


}


u16 ADC_u16AnalogRead(u08 A_u08ChannelNo)
{
	/*Select Channel*/

	ADMUX = (ADMUX & 0xE0) | (A_u08ChannelNo & 0x07);

	/*Start conversion*/

	SET_BIT(ADCSRA ,ADSC);

	/*Poll on flag*/

	while(GET_BIT(ADCSRA,ADIF) != 1)
	{

	}

	/*Clear flag*/

	SET_BIT(ADCSRA,ADIF);

	/*return ADC data*/

	return ADC ;

}




/**
 * ADC interrupt based
 */




void ADC_vStartConversion(u08 A_u08ChannelNo)
{
	/*Select Channel*/

	ADMUX = (ADMUX & 0xE0) | (A_u08ChannelNo & 0x07);

	/*Start conversion*/

	SET_BIT(ADCSRA ,ADSC);

}


u16 ADC_u16GetADCData (void)
{
	/*return ADC data*/

	return ADC ;
}

void ADC_vSetCallback (void (*A_fptr)(void))
{

ADC_Callback = A_fptr ;


}


/**
 * ADC_ISR
 */

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	ADC_Callback();


}

