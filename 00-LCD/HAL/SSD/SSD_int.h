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

#define SSD_1 1
#define SSD_2 2

#include "../../LIB/STD_TYPES.h"
/*write the type of SSD */

#define SSD_TYPE COM_CATHODE

#define SSD1_PORT DIO_PORTA // assign the port of the SSD
#define SSD2_PORT DIO_PORTB


typedef struct //think of a method to use it for using many SSDs
{
	u08 SSD_PORT;
	u08 SSD_Id;

}SSD_t;


void SSD_vInit(void);
void SSD_vDisplayNum(u08 A_u08SSDId ,u08 A_u08Num);
void SSD_vTurnOff(void);

#endif /* HAL_SSD_SSD_INT_H_ */
