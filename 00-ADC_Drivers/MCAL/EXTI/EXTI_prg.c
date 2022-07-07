/*
 * EXTI_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "avr/io.h"
#include"EXTI_cfg.h"
#include"EXTI_int.h"

void MEXTI_vInit(void)
{

/*1- sense control */
	SET_BIT(MCUCR, 3);
	CLR_BIT(MCUCR, 2);


/*2- Enable Interrupt*/
SET_BIT(GICR ,6);

}


