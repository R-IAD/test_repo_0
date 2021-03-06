/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_HIGH 1
#define DIO_LOW 0

void DIO_vSetPinDir (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Dir);
void DIO_vSetPinVal (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Val);
u08 DIO_u08GetPinVal(u08 A_u08PortNo , u08 A_u08PinNo);
void DIO_vSetPortDir(u08 A_u08PortNo , u08 A_u08Dir);
void DIO_vSetPortVal(u08 A_u08PortNo , u08 A_u08Val);
u08  DIO_u08GetPortVal(u08 A_u08PortNo);

#endif /* MCAL_DIO_DIO_INT_H_ */
