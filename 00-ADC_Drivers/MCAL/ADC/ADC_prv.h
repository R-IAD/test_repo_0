/*
 * ADC_prv.h
 *
 *  Created on: Jul 7, 2022
 *      Author: Riad
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define ADMUX    *((volatile u08*)  (0x27))
#define ADCSRA   *((volatile u08*)  (0x26))
#define ADCL     *((volatile u08*)  (0x24))
#define ADCH     *((volatile u08*)  (0x25))

#define ADC      *((volatile u16*)  (0x24))

#define SFIOR    *((volatile u08*)  (0x50))



#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define ADATE 5
#define ADIE  3
#define ADIF  4
#define ADEN  7
#define ADSC  6

#define ENABLE 1
#define DISABLE 0




#endif /* MCAL_ADC_ADC_PRV_H_ */
