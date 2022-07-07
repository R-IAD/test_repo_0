/*
 * GIE_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Riad
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_int.h"
#include <avr/io.h>

void GIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG,7);


}



void GIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG,7);

}
