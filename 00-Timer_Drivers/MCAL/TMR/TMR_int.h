/*
 * TMR_int.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Riad
 */

#ifndef MCAL_TMR_TMR_INT_H_
#define MCAL_TMR_TMR_INT_H_

#define TMR_CB_OVF  0//for callback function
#define TMR_CB_CTC  1


void TMR_vInit(void);
void TMR_vSetPreloadValue(/* Timer ID */u16 A_u16Preload);
void TMR_vSetInterval_OVF_Asynch(u16 A_u16Intervalcounts, void(*A_fptr)(void));
void TMR_vStartTMR(/* Timer ID */);
void TMR_vStopTMR(/* Timer ID */);
void TMR_vSetCompareValue(u16 A_u16CompareValue);
void TMR_vSetInterval_CTC_Asynch(u16 A_u16Intervalcounts,u16 A_u16CompareValue, void(*A_fptr)(void));




#endif /* MCAL_TMR_TMR_INT_H_ */
