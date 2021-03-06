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

#define MAX_INDX_OF_ROW 1
#define MAX_INDX_OF_COL 15

#define FIRST_ROW_INDX 0
#define FIRST_ROW_START 0x00
#define SEC_ROW_START 0x40
#define SET_ADRS_CUNTR_MASK 0x80


/* personal use */
void HLCD_vPrintMyArabcName(u08 A_u08Line ,u08 A_u08FirstLocation );
void HLCD_vSendCommand (u08 A_u08Command);
void HLCD_vSendChar (u08 A_u08Char);
void HLCD_vInit (void);
void HLCD_vPrintString (char A_s08String[]);
void HLCD_vPrintNumber (s32 A_s32Number);
void HLCD_vSetCursorPosition (u08 A_u08Row,u08 A_u08Col);
void HLCD_vSaveCustomCharCGRAM(u08 A_u08PatternIndx , u08 *A_u08PatternVal);
void HLCD_vDisplayCustomChar(/*TODO: input atguments to be provided*/);


#endif /* HAL_LCD_LCD_INT_H_ */
