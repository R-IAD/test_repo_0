/*
 * EXTI_cfg.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_


/**
 * Define the required INT :
 * INT0_ENABLE
 * INT1_ENABLE
 * INT2_ENABLE
 */

#define INT1_ENABLE





/**
 * Options for sense control INT1 :  at PD3
 * LOW_LEVEL
 * LOGICAL_CHANGE
 * FALLING_EDGE
 * RISING_EDGE
 */

#define SENSE_CONTROL_INT1 FALLING_EDGE


/**
 * Options for sense control INT0 :   at PD2
 * LOW_LEVEL
 * LOGICAL_CHANGE
 * FALLING_EDGE
 * RISING_EDGE
 */

#define SENSE_CONTROL_INT0 FALLING_EDGE

/**
 * Options for sense control INT2 :   at PB2
 * FALLING_EDGE
 * RISING_EDGE
 */

#define SENSE_CONTROL_INT0 FALLING_EDGE


#endif /* MCAL_EXTI_EXTI_CFG_H_ */
