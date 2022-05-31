/*************************************************************************/
/*************************************************************************/
/**********************   Author:  Al-Hasan Ameer   **********************/
/**********************   LAYER:   MCAL             **********************/
/**********************   SWC:     DIO              **********************/
/**********************   VERSION: 1.00             **********************/
/*************************************************************************/
/*************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*PIN DIRECTIONS*/
#define DIO_u8PIN_OUTPUT             1
#define DIO_u8PIN_INPUT              0

/*PIN VALUE OPTION*/
#define DIO_u8PIN_HIGH               1
#define DIO_u8PIN_LOW                0

/*ALL PORT DIRECTIONS*/
#define DIO_u8PORT_OUTPUT            0XFF
#define DIO_u8PORT_INPUT             0

/* ALL PORT VALUE OPTION*/
#define DIO_u8PORT_HIGH               0XFF
#define DIO_u8PORT_LOW                0

/*PORT DEFINES*/
#define DIO_u8PORTA                  0
#define DIO_u8PORTB                  1
#define DIO_u8PORTC                  2
#define DIO_u8PORTD                  3

/*PIN DEFINES*/
#define DIO_u8PIN0                   0
#define DIO_u8PIN1                   1
#define DIO_u8PIN2                   2
#define DIO_u8PIN3                   3
#define DIO_u8PIN4                   4
#define DIO_u8PIN5                   5
#define DIO_u8PIN6                   6
#define DIO_u8PIN7                   7



/*set Direction*/
u8 DIO_u8SetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Direction);
u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8Direction);

/*set Value*/
u8 DIO_u8SetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value);
u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8Value);

/*get Value*/
u8 DIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_u8Value);
u8 DIO_u8GetPortValue(u8 copy_u8Port, u8* copy_u8Value);

/*TOGGEL*/
u8 DIO_u8TogPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8* copy_pu8Value);




#endif
