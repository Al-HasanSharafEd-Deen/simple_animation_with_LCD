/**************************************************************************/
/**************************************************************************/
/**********************   Author:  Al-Hasan Ameer   ***********************/
/**********************   LAYER:   MCAL                     ***********************/
/**********************   SWC:     DIO                          ***********************/
/**********************   VERSION: 1.00                      ***********************/
/**************************************************************************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*set  PIN Direction*/
u8 DIO_u8SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	if(copy_u8Pin<=DIO_u8PIN7)
	{
		if(copy_u8Direction==DIO_u8PIN_INPUT)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: CLRBIT(DDRA,copy_u8Pin); break;
			case DIO_u8PORTB: CLRBIT(DDRB,copy_u8Pin); break;
			case DIO_u8PORTC: CLRBIT(DDRC,copy_u8Pin); break;
			case DIO_u8PORTD: CLRBIT(DDRD,copy_u8Pin); break;
			default: Local_u8ErrorState=1; break;
			}
		}
		else if (copy_u8Direction==DIO_u8PIN_OUTPUT)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: SETBIT(DDRA,copy_u8Pin); break;
			case DIO_u8PORTB: SETBIT(DDRB,copy_u8Pin); break;
			case DIO_u8PORTC: SETBIT(DDRC,copy_u8Pin); break;
			case DIO_u8PORTD: SETBIT(DDRD,copy_u8Pin); break;
			default: Local_u8ErrorState=1; break;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
/*set  PORT Direction*/
u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction)
{
	u8 Local_u8ErrorState=0;
	switch(copy_u8Port)
	{
	case  DIO_u8PORTA : DDRA = copy_u8Direction; break;
	case  DIO_u8PORTB : DDRB = copy_u8Direction; break;
	case  DIO_u8PORTC : DDRC = copy_u8Direction; break;
	case  DIO_u8PORTD : DDRD = copy_u8Direction; break;
	default: Local_u8ErrorState=1; break;
	}
	return Local_u8ErrorState;
}


/*set  PIN Value*/
u8 DIO_u8SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	if(copy_u8Pin<=DIO_u8PIN7)
	{
		if(copy_u8Value==DIO_u8PIN_LOW)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA:  CLRBIT(PORTA,copy_u8Pin); break;
			case DIO_u8PORTB:  CLRBIT(PORTB,copy_u8Pin); break;
			case DIO_u8PORTC:  CLRBIT(PORTC,copy_u8Pin); break;
			case DIO_u8PORTD:  CLRBIT(PORTD,copy_u8Pin); break;
			default: Local_u8ErrorState=1; break;
			}
		}
		else if (copy_u8Value==DIO_u8PIN_HIGH)
		{
			switch(copy_u8Port)
			{
			case DIO_u8PORTA: SETBIT(PORTA,copy_u8Pin); break;
			case DIO_u8PORTB: SETBIT(PORTB,copy_u8Pin); break;
			case DIO_u8PORTC: SETBIT(PORTC,copy_u8Pin); break;
			case DIO_u8PORTD: SETBIT(PORTD,copy_u8Pin); break;
			default: Local_u8ErrorState=1; break;
			}
		}
		else
		{
			Local_u8ErrorState=1;
		}

	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
/*set  PORT Value*/
u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8Value)
{
	u8 Local_u8ErrorState=0;
	switch(copy_u8Port)
	{
	case  DIO_u8PORTA :  PORTA = copy_u8Value; break;
	case  DIO_u8PORTB :  PORTB = copy_u8Value; break;
	case  DIO_u8PORTC :  PORTC = copy_u8Value; break;
	case  DIO_u8PORTD : PORTD = copy_u8Value; break;
	default: Local_u8ErrorState=1; break;
	}
	return Local_u8ErrorState;
}


/*get  PIN  Value*/
u8 DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_pu8Value)
{
	u8 Local_u8ErrorState=0;
	if((copy_pu8Value != NULL  ) && (copy_u8Pin <= DIO_u8PIN7))
	{
		switch(copy_u8Port)
		{
		case DIO_u8PORTA: *copy_pu8Value= GETBIT(PINA , copy_u8Pin); break;
		case DIO_u8PORTB: *copy_pu8Value= GETBIT(PINB , copy_u8Pin); break;
		case DIO_u8PORTC: *copy_pu8Value= GETBIT(PINC , copy_u8Pin); break;
		case DIO_u8PORTD: *copy_pu8Value= GETBIT(PIND , copy_u8Pin); break;
		default: Local_u8ErrorState=1; break;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

/*get  PORT  Value*/
//u8 DIO_u8GetPortValue(u8 copy_u8Port, u8* copy_u8Value)
//{
//	u8 Local_u8ErrorState=0;
//	switch(copy_u8Port)
//	{
//	case  DIO_u8PORTA : DDRA = *copy_u8Value; break;
//	case  DIO_u8PORTB : DDRB = *copy_u8Value; break;
//	case  DIO_u8PORTC : DDRC = *copy_u8Value; break;
//	case  DIO_u8PORTD : DDRD = *copy_u8Value; break;
//	default: Local_u8ErrorState=1; break;
//	}
//	return Local_u8ErrorState;
//}
