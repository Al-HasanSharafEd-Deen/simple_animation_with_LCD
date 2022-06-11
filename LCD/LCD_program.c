/*******************************************************************************/
/*******************************************************************************/
/**********************   Author:  Al-Hasan Ameer    ***************************/
/**********************   LAYER:   HAL               ***************************/
/**********************   SWC:     CLCD              ***************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../DIO/DIO_interface.h"
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
	/*8bit mode*/
#if LCD_MODE == LCD_8BitMode
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
	_delay_ms(2);

	/*4bit mode*/
#elif LCD_MODE == LCD_4BitMode
	/*RS==0 (low) for command*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);
	/*RW==0 (low) for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
	/*higher command*/
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN7,GETBIT(Copy_u8Command,7));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN6,GETBIT(Copy_u8Command,6));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN5,GETBIT(Copy_u8Command,5));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN4,GETBIT(Copy_u8Command,4));
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	/*lower command*/
	if(global_u8InitFinished){
		DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN7,GETBIT(Copy_u8Command,3));
		DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN6,GETBIT(Copy_u8Command,2));
		DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN5,GETBIT(Copy_u8Command,1));
		DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN4,GETBIT(Copy_u8Command,0));
		/*enable pulse*/
		DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
		_delay_ms(1);
		DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	}
	_delay_ms(2);
#endif

}

/* send Data Function
 * Brief: this function take a Data that you want to display
 * Parameters: Copy_u8Data== Data that you want to display
 */
void LCD_voidSendData(u8 Copy_u8Data)
{
	/*8bit mode*/
#if LCD_MODE == LCD_8BitMode
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
	_delay_ms(2);

	/*4bit mode*/
#elif LCD_MODE == LCD_4BitMode
	/*RS==1 (high) for data*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);
	/*RW==0 (low) for Write*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);
	/*higher data*/
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN7,GETBIT(Copy_u8Data,7));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN6,GETBIT(Copy_u8Data,6));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN5,GETBIT(Copy_u8Data,5));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN4,GETBIT(Copy_u8Data,4));
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	/*lower data*/
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN7,GETBIT(Copy_u8Data,3));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN6,GETBIT(Copy_u8Data,2));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN5,GETBIT(Copy_u8Data,1));
	DIO_u8SetPinValue(LCD_DATA_PORT, DIO_u8PIN4,GETBIT(Copy_u8Data,0));
	/*enable pulse*/
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(2);
#endif
}

/*LCD initialization 8Bit Mode ,SET PORTS Direction*/
void LCD_voidInit(void)
{
	/*8bit mode*/
#if LCD_MODE == LCD_8BitMode
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

	/*4bit mode*/
#elif LCD_MODE == LCD_4BitMode
	/*set LCD CTRL port and LCD data port to output*/
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_E_PIN,  DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(LCD_DATA_PORT, DIO_u8PIN4, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, DIO_u8PIN5, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, DIO_u8PIN6, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT, DIO_u8PIN7, DIO_u8PIN_OUTPUT);

	/*lcd home*/
	LCD_voidSendCommand(0b00000010);

	/*delay for more than 30ms*/
	_delay_ms(30);
	/*set function, 2line , 5*7font*/
	LCD_voidSendCommand(0b00100000);
	LCD_voidSendCommand(0b00100000);
	LCD_voidSendCommand(0b10000000);
	/*delay for more than 39us*/
	_delay_ms(1);
	/*display ON/OF control*/
	LCD_voidSendCommand(0b00000000);
	LCD_voidSendCommand(0b11000000);
	/*delay for more than 39us*/
	_delay_ms(1);
	/*Display clear*/
	LCD_voidSendCommand(0b00000000);
	LCD_voidSendCommand(0b00010000);
	/*delay for more than 2ms*/
	_delay_ms(3);
	/*Entry mode Set*/
	LCD_voidSendCommand(0b00000000);
	LCD_voidSendCommand(0b01100000);
	/*change initial value of this variable from 0 to 1
	 it's make send data and send command send a lower data*/
	global_u8InitFinished=1;
#endif

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

/* set DDRAM address
 * Brief: this function set a location where you want display on LCD
 * Parameters:
 *  Copy_u8XPos to set line_1 or line_2
    [chose 0--->to line_1,1--->to line_2
 *  Copy_u8YPos to set the location on the line you chose it
    [visible window is 16 location from 0 to 15 but the one line has 40 locations
     so if you chose a location from 16 t0 31
     automatically the function replace it from 0 to 15
     and if you chose a location from 32 t0 40 too.*/
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address=0;
	if((Copy_u8YPos<=15) && Copy_u8YPos>=0){
		if(Copy_u8XPos ==0)
		{
			Local_u8Address = Copy_u8YPos;
		}
		else if (Copy_u8XPos ==1)
		{
			Local_u8Address = Copy_u8YPos + 0x40 ;
		}
	}
	else if((Copy_u8YPos>=16) && Copy_u8YPos<32){
		if(Copy_u8XPos ==0)
		{
			Local_u8Address = Copy_u8YPos-16;
		}
		else if (Copy_u8XPos ==1)
		{
			Local_u8Address = (Copy_u8YPos-16) + 0x40 ;
		}

	}
	else if((Copy_u8YPos>=32) && Copy_u8YPos<40){
		if(Copy_u8XPos ==0)
		{
			Local_u8Address = Copy_u8YPos-32;
		}
		else if (Copy_u8XPos ==1)
		{
			Local_u8Address = (Copy_u8YPos-32) + 0x40 ;
		}
	}
	LCD_voidSendCommand(Local_u8Address + 128);
}

/*print Special Char-set CGRAM*/
void LCD_voidSpecialChar(u8* Copy_u8Pattern, u8 Copy_u8PatternNum, u8 Copy_u8XPos, u8 Copy_u8YPos)
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
