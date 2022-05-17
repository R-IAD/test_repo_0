/*
 * SSD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Riad
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define COM_CATHODE 0
#define COM_ANODE   1

/*write the type of SSD */
#define SSD_TYPE COM_CATHODE
#define SSD_PORT DIO_PORTA

void SSD_vInit(void);
void SSD_vDisplayNum(u08 A_u08Num);
void SSD_vTurnOff(void);

#endif /* HAL_SSD_SSD_INT_H_ */
