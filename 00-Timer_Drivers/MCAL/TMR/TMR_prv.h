/*
 * TMR_prv.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Riad
 */

#ifndef MCAL_TMR_TMR_PRV_H_
#define MCAL_TMR_TMR_PRV_H_


#define TMR_OVF               0
#define TMR_CTC               1
#define TMR_FASTPWM           2
#define TMR_PASHECORRECT      3


#define DISCONNECTED          0
#define TOGGLE_ON_COMPARE     1
#define CLEAR_ON_COMPARE      2
#define SET_ON_COMPARE        3

#define TMR_PS_0			  0b000
#define TMR_PS_1			  0b001
#define TMR_PS_8 			  0b010
#define TMR_PS_64			  0b011
#define TMR_PS_256            0b100
#define TMR_PS_1024           0b101
#define EXT_CLCK_SOURCE_FALLING         0b110
#define EXT_CLCK_SOURCE_RISING          0b111




#define ENABLE  1
#define DISABLE 0



/*=======Timer0 registers=======*/

#define TCCR0 *((volatile u08*) (0x53))
#define TCNT0 *((volatile u08*) (0x52)) //Counting Register
#define OCR0  *((volatile u08*) (0x5c)) //Compare Timer Register CTC
#define TIMSK *((volatile u08*) (0x59))
#define TIFR  *((volatile u08*) (0x58))

/*===========Timer 0 Bits========*/
#define CS00  0 //PRE Scaler
#define CS01  1 //PRE Scaler
#define CS02  2 //PRE Scaler
#define WGM01 3 //Waveform Generation Mode
#define COM00 4 //OC0 Behavior
#define COM01 5 //OC0 Behavior
#define WGM00 6 //Waveform Generation Mode
#define FOC0  7 //Check Data sheet
#define TOIE0 0 //CTC Interrupt Enable
#define OCIE0 1 //OVF Interrupt Enable
#define TOV0  0 //Flag When Overflow Occurs
#define OCF0  1 //Flag When Compare Match Occurs

/*=======Timer1 registers=======*/

#define TCCR1A *((volatile u08*) (0x))
#define TCCR1B *((volatile u08*) (0x))

#define TCNT1  *((volatile u16*) (0x4c))
#define OCR1A  *((volatile u08*) (0x))
#define OCR1B  *((volatile u08*) (0x))

#define ICR1 *((volatile u08*) (0x))


#endif /* MCAL_TMR_TMR_PRV_H_ */
