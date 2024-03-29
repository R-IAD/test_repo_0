/*
 * EXTI_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"EXTI_int.h"
#include"EXTI_prv.h"
#include"EXTI_cfg.h"

void MEXTI_vInit(void)
{

/*
 * 1- Sense Control For INT1
 */

#if SENSE_CONTROL_INT1==LOW_LEVEL
	CLR_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);

#elif SENSE_CONTROL_INT1==LOGICAL_CHANGE
	CLR_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);

#elif SENSE_CONTROL_INT1==FALLING_EDGE
	SET_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);

#elif SENSE_CONTROL_INT1==RISING_EDGE
	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);

#endif

/**
 * Sense control for INT0
 */
#if SENSE_CONTROL_INT0==LOW_LEVEL
	CLR_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);

#elif SENSE_CONTROL_INT0==LOGICAL_CHANGE
	CLR_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);

#elif SENSE_CONTROL_INT0==FALLING_EDGE
	SET_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);

#elif SENSE_CONTROL_INT0==RISING_EDGE
	SET_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);

#endif



/**
 * Sense control for INT2
 */
#if SENSE_CONTROL_INT2==FALLING_EDGE
	CLR_BIT(MCUCSR, ISC2);

#elif SENSE_CONTROL_INT2==RISING_EDGE
	SET_BIT(MCUCSR, ISC2);

#endif

/*
 * 2- Enable Interrupt
 */

#ifdef INT0_ENABLE
	SET_BIT(GICR ,INT0);
#endif

#ifdef INT1_ENABLE
	SET_BIT(GICR ,INT1);
#endif

#ifdef INT2_ENABLE
	SET_BIT(GICR ,INT2);
#endif
}


