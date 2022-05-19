/*
 * LCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: Riad
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/****** Configration Part ******/
#define LCD_CTRL_PORT  DIO_PORTA
#define LCD_DATA_PORT   DIO_PORTD
#define LCD_RS_PIN     DIO_PIN0
#define LCD_RW_PIN     DIO_PIN1
#define LCD_EN_PIN     DIO_PIN2
#define LCD_VDD_PIN    DIO_PIN3


void HLCD_vSendCommand (u08 A_u08Command);
void HLCD_vSendChar (u08 A_u08Char);
void HLCD_vInit (void);
void HLCD_vPrintString (char A_s08String[]);
void HLCD_vPrintNumber (s32 A_s32Number);
void HLCD_vSetCursorPosition (u08 A_u08LinePosition , u08 A_u08LineNumber);
void HLCD_vSaveCustomChar(/*TODO: input atguments to be provided*/);
void HLCD_vDisplayCustomChar(/*TODO: input atguments to be provided*/);


#endif /* HAL_LCD_LCD_INT_H_ */
