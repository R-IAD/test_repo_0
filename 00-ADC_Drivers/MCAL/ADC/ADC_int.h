/*
 * ADC_int.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

void ADC_vInit(void);
u16 ADC_u16AnalogRead(u08 A_u08ChannelNo);


/**
 * interrupt based APIs
 */
void ADC_vStartConversion(u08 A_u08ChannelNo);
u16 ADC_u16GetADCData (void);
void ADC_vSetCallback (void (*A_fptr)(void));


#endif /* MCAL_ADC_ADC_INT_H_ */
