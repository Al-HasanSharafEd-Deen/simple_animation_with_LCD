/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     CLCD              ***************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define DISPLAY_CLR         0b00000001


void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidPrintStrig(const char* Copy_pcString);
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void LCD_voidPrintNumber(s32 num);
void LCD_voidSpecialChar(u8* Copy_u8Pattern, u8 Copy_u8PatternNum, u8 Copy_u8XPos, u8 Copy_u8YPos );


#endif /* LCD_INTERFACE_H_ */
