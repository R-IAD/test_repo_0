/*
 * EXTI_prv.h
 *
 *  Created on: Jul 18, 2022
 *      Author: Riad
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_


#define MCUCR  *((volatile u08*) (0x55))
#define MCUCSR *((volatile u08*) (0x54))
#define GICR   *((volatile u08*) (0x5b))

/**
 * Bits in MCUCR register
 */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/**
 * Bits in MCUCSR register
 */
#define ISC2 6

/**
 * Bits in GICR register
 */
#define INT0 6
#define INT1 7
#define INT2 5


/**
 * Macros for INT mode
 */
#define LOW_LEVEL       1
#define LOGICAL_CHANGE  2
#define FALLING_EDGE    3
#define RISING_EDGE     4


#endif /* MCAL_EXTI_EXTI_PRV_H_ */
