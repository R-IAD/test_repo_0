/*
 * LCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: Riad
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_




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
