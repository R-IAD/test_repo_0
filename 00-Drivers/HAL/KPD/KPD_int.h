/*
 * KPD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#define KPD_PORT DIO_PORTA


void KPD_vInit(void);
u08 KPD_u08GetPressedKey (void);


#endif /* HAL_KPD_KPD_INT_H_ */
