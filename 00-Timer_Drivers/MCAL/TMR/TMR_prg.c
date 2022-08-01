/*
 * TMR_prg.c
 *
 *  Created on: Jul 27, 2022
 *      Author: Riad
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TMR_int.h"
#include "TMR_prv.h"
#include "TMR_cfg.h"


u32 G_u32IntervalCounts;

static void (*G_TMR0_Callback[2])(void); //array of ptr to func for Timer0

void TMR_vInit(void)
{
	/*
	 * Mode : Normal Overflow
	 * Interrupt : enable Overflow interrupt
	 * PRE scaler : No CLOCK -> Timer stopped
	 */

#if TMR0_ENABLE==ENABLE

	/*1-Wave Generation Mode*/
#if TMR0_MODE==TMR_OVF

	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

#elif TMR0_MODE==TMR_CTC

	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

#elif TMR0_MODE==TMR_FASTPWM

	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

#elif TMR0_MODE==TMR_PASHECORRECT

	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);

#else
#error "Select a valid Timer Mode"
#endif

	/*2-Compare Match Mode*/

#if OC0_MODE==DISCONNECTED

	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);

#elif OC0_MODE==TOGGLE_ON_COMPARE

	CLR_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);

#elif OC0_MODE==CLEAR_ON_COMPARE

	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);

#elif OC0_MODE==SET_ON_COMPARE

	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);

#else
#error "Select Valid Behavior For OC0 Mode"
#endif

	/*3-Interrupt Enable*/

#if OVF_INTERRUPT==ENABLE

	SET_BIT(TIMSK,TOIE0);

#elif CTC_INTERRUPT==ENABLE

	SET_BIT(TIMSK,OCIE0);

#else
	CLR_BIT(TIMSK,TOIE0);
	CLR_BIT(TIMSK,OCIE0);
#endif

#endif

#if TMR1_ENABLE==ENABLE

#endif
	//TCCR0 = 0b01101000;
	//SET_BIT(TIMSK,0); // TOIE0
	 //SET_BIT(TIMSK,1);  // OCIE0
}


void TMR_vSetPreloadValue(/*u08 A_u08TMR_ID ,*/u16 A_u16Preload)
{
	/*switch(A_u08TMR_ID)
	{
	case TMR0 :*/
		TCNT0= A_u16Preload;
		//break;
	/*case TMR0 :
		TCNT0= A_u16Preload;
		break;
	case TMR0 :
		TCNT0= A_u16Preload;
		break;*/
	//}

}

void TMR_vSetCompareValue(/*u08 A_u08TMR_ID ,*/u16 A_u16CompareValue)
{
	OCR0 = A_u16CompareValue ;

}

void TMR_vSetInterval_OVF_Asynch(u16 A_u16Intervalcounts, void(*A_fptr)(void))
{
	G_u32IntervalCounts =A_u16Intervalcounts;


	G_TMR0_Callback[TMR_CB_OVF] = A_fptr ;

	/*
	 * start timer
	 */
	TMR_vStartTMR();
}

void TMR_vSetInterval_CTC_Asynch(u16 A_u16Intervalcounts,u16 A_u16CompareValue, void(*A_fptr)(void))
{
	G_u32IntervalCounts =A_u16Intervalcounts;


	G_TMR0_Callback[TMR_CB_CTC] = A_fptr ;

	TMR_vSetCompareValue(A_u16CompareValue);

	/*
	 * start timer
	 */
	TMR_vStartTMR();
}

void TMR_vStartTMR(/* Timer ID */)
{
	TCCR0 = (TCCR0 & 0xf8) | (TMR0_PRESCALER);

}

void TMR_vStopTMR(/* Timer ID */)
{
	TCCR0 = (TCCR0 & 0xf8) | (TMR_PS_0);


}



/*
 * Timer0 OVF ISR
 */

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u32 LS_u32counter = 0 ;

	LS_u32counter ++;

	if (LS_u32counter ==G_u32IntervalCounts )
	{
		if (G_TMR0_Callback[TMR_CB_OVF] != NULL)
		{
			G_TMR0_Callback[TMR_CB_OVF]();
			LS_u32counter = 0 ;
		}
	}
}


/*
 * Timer0 CTC ISR
 */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 LS_u32counter = 0 ;

	LS_u32counter ++;

	if (LS_u32counter ==G_u32IntervalCounts )
	{
		if (G_TMR0_Callback[TMR_CB_CTC] != NULL)
		{
			G_TMR0_Callback[TMR_CB_CTC]();
			LS_u32counter = 0 ;
		}
	}
}
