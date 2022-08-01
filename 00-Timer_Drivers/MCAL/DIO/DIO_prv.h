/*
 * DIO_prv.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Riad
 */

#ifndef MCAL_DIO_DIO_PRV_H_
#define MCAL_DIO_DIO_PRV_H_

/**
 * Port registers
 */
#define PORTA   *((volatile u08*) (0x3b) )
#define PORTB   *((volatile u08*) (0x38) )
#define PORTC   *((volatile u08*) (0x35) )
#define PORTD   *((volatile u08*) (0x32) )

/**
 * Direction Registers
 */
#define DDRA   *((volatile u08*) (0x3a) )
#define DDRB   *((volatile u08*) (0x37) )
#define DDRC   *((volatile u08*) (0x34) )
#define DDRD   *((volatile u08*) (0x31) )

/**
 * Pin Registers
 */
#define PINA   *((volatile u08*) (0x39) )
#define PINB   *((volatile u08*) (0x36) )
#define PINC   *((volatile u08*) (0x33) )
#define PIND   *((volatile u08*) (0x30) )

/**
 * Bits NOs
 */
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



#endif /* MCAL_DIO_DIO_PRV_H_ */
