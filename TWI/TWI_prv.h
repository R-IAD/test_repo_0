/*
 * I2C_prv.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Riad
 */

#ifndef MCAL_TWI_TWI_PRV_H_
#define MCAL_TWI_TWI_PRV_H_

#define TWBR        *((volatile u08*) (0x20))
#define TWCR        *((volatile u08*) (0x56))
#define TWSR        *((volatile u08*) (0x21))
#define TWDR        *((volatile u08*) (0x23))
#define TWAR        *((volatile u08*) (0x22))

#define TWIE  0
#define TWINT 7
#define TWSTA 5
#define TWEN  2
#define TWSTO 4
#define TWEA  6

#endif /* MCAL_TWI_TWI_PRV_H_ */
