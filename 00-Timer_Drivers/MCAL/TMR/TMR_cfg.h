/*
 * TMR_cfg.h
 *
 *  Created on: Jul 27, 2022
 *      Author: Riad
 */

#ifndef MCAL_TMR_TMR_CFG_H_
#define MCAL_TMR_TMR_CFG_H_




/*========== Timer 0 configuration=========*/

#define TMR0_ENABLE  ENABLE

/*
 * Options :
 *  1-   TMR_OVF
 *  2-   TMR_CTC
 *  3-   TMR_FASTPWM
 *  4-   TMR_PASHECORRECT
 */

#define TMR0_MODE TMR_OVF


/*
 * OC0 Behavior On CTC Mode :
 *
 *   1- DISCONNECTED
 *   2- TOGGLE_ON_COMPARE
 *   3- CLEAR_ON_COMPARE
 *   4- SET_ON_COMPARE
 *
 *  OC0 On FASTPWM Mode:
 *
 *   1- DISCONNECTED
 *   2- CLEAR_ON_COMPARE--> Non-Inverting DC Ton while compare value
 *   3- SET_ON_COMPARE  --> Inverting DC  T off while compare value
 *
 *  OC0 On PHASECORRECT Mode:
 *
 *   1- DISCONNECTED
 *   2- CLEAR_ON_COMPARE -->Ton while compare value
 *   3- SET_ON_COMPARE   -->T off while compare value
 *
 */

#define OC0_MODE DISCONNECTED


/*
 * PRE Scaler Options :
 *
 *   1- TMR_PS_0 -->No Clock Source
 *   2- TMR_PS_1 -->No PRE Scaling
 *   3- TMR_PS_8
 *   4- TMR_PS_64
 *   5- TMR_PS_256
 *   6- TMR_PS_1024
 *   7-  EXT_CLCK_SOURCE_FALLING
 *   8-  EXT_CLCK_SOURCE_RISING
 *
 */


#define TMR0_PRESCALER TMR_PS_8


/*
 * Interrupt Enable Options:
 *   1- OVF_INTERRUPT ENABLE/DISABLE
 *   2- CTC_INTERRUPT ENABLE/DISABLE
 */

#define OVF_INTERRUPT ENABLE
#define CTC_INTERRUPT DISABLE

/*========== Timer1 configuration=========*/

#define TMR1_ENABLE  DISABLE




#endif /* MCAL_TMR_TMR_CFG_H_ */
