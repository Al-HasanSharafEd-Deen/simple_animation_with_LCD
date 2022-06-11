/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     CLCD              ***************************/
/*******************************************************************************/
/*******************************************************************************/
 
/*Preprocessor file guard*/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_CTRL_PORT                  DIO_u8PORTD
#define LCD_DATA_PORT                  DIO_u8PORTC

#define LCD_RS_PIN                     DIO_u8PIN0
#define LCD_RW_PIN                     DIO_u8PIN1
#define LCD_E_PIN                      DIO_u8PIN2


/*edit this macro to set LCD 4Bit mode or 8Bit mode
 * to 4Bit: write LCD_4BitMode
 * to 8bit: write LCD-8BitMode
                                */
#define LCD_MODE				       LCD_4BitMode

#endif /* LCD_CONFIG_H_ */
