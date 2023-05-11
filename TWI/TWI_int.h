/*
 * I2C_int.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Riad
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

#define TWI_WRITE  0
#define TWI_READ   1

#define TWI_ACK  1
#define TWI_NACK 0


void TWI_vInit(void);

u08 TWI_u08SendStartCondition(void);
u08 TWI_u08SendRepeatedStartCondition(void);

u08 TWI_u08SendSlaveAddressRW(u08 A_u08SLA , u08 A_u08RW);
u08 TWI_u08SendByte(u08 A_u08Byte);
u08 TWI_u08ReceiveByte(u08* A_pu08Byte ,u08 A_u08ACK);
u08 TWI_u08SendStopCondition(void);
u08 TWI_u08GetStatus(void);

void TWI_vSetSlaveAddress (u08 OwnSla);

void TWI_vSetBitRate(u32 A_u32BitRate);


#endif /* MCAL_TWI_TWI_INT_H_ */
