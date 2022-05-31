/*
 * LCD_program.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Al-Hasan Ameer
 */

/**********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
/**********************************************************************************************************/


/* send command Function
 * Brief: this function take a LCD'S command to the LCD driver
 * Parameters: Copy_u8Command == command number(as it's in the LCD'c Data_sheet)
 */
void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*RS==0 (low) for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);
	/*RW==0 (low) for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
	/*send command to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(1);
}

/* send Data Function
 * Brief: this function take a Data that you want to display
 * Parameters: Copy_u8Data== Data that you want to display
 */
void LCD_voidSendData(u8 Copy_u8Data)
{
	/*RS==1 (high) for data*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);
	/*RW==0 (low) for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
	/*send data to data pins*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(1);
}

/*LCD initialization 8Bit Mode ,SET PORTS Direction*/
void LCD_voidInit(void)
{
	/*set LCD CTRL port and LCD data port to output*/
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_OUTPUT );
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(LCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	/*delay for more than 30ms*/
	_delay_ms(40);
	/*set function, 2line , 5*7font*/
	LCD_voidSendCommand(0b00111000);
	/*delay for more than 39us*/
	_delay_ms(1);
	/*display ON/OF control, display on, cursor off, blink cursor off */
	LCD_voidSendCommand(0b00001100);
	/*delay for more than 39us*/
	_delay_ms(1);
	/*display clear*/
	LCD_voidSendCommand(0b00000001);
	/*delay for more than 2ms*/
	_delay_ms(3);
	/*Entry mode Set*/
	LCD_voidSendCommand(0b00000110);
}

/*print string*/
void LCD_voidPrintStrig(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter] !='\0')
	{
		LCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
//	for(u32 Local_u8Iterator=0; Copy_pcString[Local_u8Iterator] !='\0';Local_u8Iterator++)
//	{
//		LCD_voidSendData(Copy_pcString[Local_u8Iterator]);
//	}
}

/*print number*/
void LCD_voidPrintNumber(s32 num)
{
	u8 digits[11]={0};

	u8 Local_u8Iterator=0;
	while(num>0)
	{
		digits[Local_u8Iterator] =num%10;
		num /=10;
		Local_u8Iterator++;
	}
	for(s8 Local_u8Iterator1=Local_u8Iterator-1;Local_u8Iterator1>=0;Local_u8Iterator1--)
	{
		LCD_voidSendData(digits[Local_u8Iterator1]+'0');
	}
}

/*set DDRAM address*/
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address=0;
	if(Copy_u8XPos ==0)
	{
		Local_u8Address = Copy_u8YPos;
	}
	else if (Copy_u8XPos ==1)
	{
		Local_u8Address = Copy_u8YPos + 0x40 ;
	}
	LCD_voidSendCommand(Local_u8Address + 128);
}

/*print Special Char-set CGRAM*/
void LCD_voidSpecialChar(u8* Copy_u8Pattern, u8 Copy_u8PatternNum, u8 Copy_u8XPos, u8 Copy_u8YPos )
{
	u8 Local_u8CGRAMAddress=0, Local_u8Iterator;
	Local_u8CGRAMAddress= Copy_u8PatternNum*8;

	LCD_voidSendCommand(Local_u8CGRAMAddress+64);
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		LCD_voidSendData(Copy_u8Pattern[Local_u8Iterator]);
	}
	LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);
	LCD_voidSendData(Copy_u8PatternNum);
}
