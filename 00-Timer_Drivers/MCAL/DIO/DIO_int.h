/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_



#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_HIGH 1
#define DIO_LOW 0

#include "DIO_prv.h"

void DIO_vSetPinDir (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Dir);
void DIO_vSetPinVal (u08 A_u08PortNo , u08 A_u08PinNo , u08 A_u08Val);
u08  DIO_u08GetPinVal(u08 A_u08PortNo , u08 A_u08PinNo);
void DIO_vSetPortDir(u08 A_u08PortNo , u08 A_u08Dir);
void DIO_vSetPortVal(u08 A_u08PortNo , u08 A_u08Val);
u08  DIO_u08GetPortVal(u08 A_u08PortNo);
void DIO_vToglPinVal(u08 A_u08PortNo , u08 A_u08PinNo);


#endif /* MCAL_DIO_DIO_INT_H_ */
