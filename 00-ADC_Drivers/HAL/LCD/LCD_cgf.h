/*
 * LCD_cgf.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Riad
 */

#ifndef HAL_LCD_LCD_CGF_H_
#define HAL_LCD_LCD_CGF_H_

/****** Configration Part ******/
#define LCD_CTRL_PORT  DIO_PORTB
#define LCD_DATA_PORT   DIO_PORTA
#define LCD_RS_PIN     DIO_PIN0
#define LCD_RW_PIN     DIO_PIN1
#define LCD_EN_PIN     DIO_PIN2
#define LCD_VDD_PIN    DIO_PIN3

#define MAX_INDX_OF_ROW 1
#define MAX_INDX_OF_COL 15

#define FIRST_ROW_INDX 0
#define FIRST_ROW_START 0x00
#define SEC_ROW_START 0x40
#define SET_ADRS_CUNTR_MASK 0x80


#endif /* HAL_LCD_LCD_CGF_H_ */
