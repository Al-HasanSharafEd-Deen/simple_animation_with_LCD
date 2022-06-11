/*
 * main.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Al-Hasan Ameer
 */


#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include "./DIO/DIO_interface.h"
#include "./LCD/LCD_interface.h"

#include  <util/delay.h>

/*************************************Hamoksha arrays*************************************/
/*main head and legs---main character*/
static u8 hamokshaHead[8]=     {   0b00001110, 0b00011111, 0b00011111, 0b00001110,
								   0b00000100, 0b00001110, 0b00010101, 0b00000000};
static u8 hamokshLelegs[8]=    {   0b00010101, 0b00000100, 0b00000100, 0b00000100,
								   0b00001010, 0b00010001, 0b00010001, 0b00000000};

/*when the character kick the ball*/
static u8 hamokshLeleg2[8]=    {   0b00010101, 0b00000100, 0b00000100, 0b00000100,
								   0b00001010, 0b00010001, 0b00000001, 0b00000000};
/*ball and goal*/
static u8 hamokshBall1[8]=     {   0b00000000, 0b00000000, 0b00001100, 0b00011110,
								   0b00011110, 0b00001100, 0b00000011, 0b00000000};
static u8 hamokshBall2[8]=     {   0b00000000, 0b00000000, 0b00001100, 0b00011110,
								   0b00011110, 0b00001100, 0b00000000, 0b00000000};
static u8 hamokshGoal1[8]=     {   0b00011111, 0b00010000, 0b00010000, 0b00010000,
								   0b00010000, 0b00010000, 0b00010000, 0b00000000};
static u8 hamokshGoal2[8]=     {   0b00010000, 0b00010000, 0b00010000, 0b00010000,
								   0b00010000, 0b00010000, 0b00011111, 0b00000000};

/*running part 1*/
static u8 hamokshaHeadR[8]=    {   0b00001100, 0b00011110, 0b00011110, 0b00001101,
								   0b00000101, 0b00000110, 0b00010000, 0b00000000};
static u8 hamokshLelegsR[8]=   {   0b00010100, 0b00010100, 0b00000100, 0b00010100,
								   0b00001100, 0b00000010, 0b00000001, 0b00000000};
/*running part 2*/
static u8 hamokshaHeadR2[8]=   {   0b00000110, 0b00001111, 0b00001111, 0b00010110,
								   0b00010100, 0b00001110, 0b00000001, 0b00000000};
static u8 hamokshLelegsR2[8]=  {   0b00000101, 0b00000101, 0b00000100, 0b00000101,
								   0b00000110, 0b00001000, 0b00010000, 0b00000000};

/*dancing*/
static u8 hamokshaDance1[8]=   {   0b00001110, 0b00011111, 0b00011111, 0b00001110,
								   0b00000101, 0b00010110, 0b00001001, 0b00000001};
static u8 hamokshaDance2[8]=   {   0b00000001, 0b00000001, 0b00000010, 0b00000100,
								   0b00001010, 0b00010001, 0b00010001, 0b00000000};
static u8 hamokshaDance1_0[8]= {   0b00001110, 0b00011111, 0b00011111, 0b00001110,
								   0b00010100, 0b00001101, 0b00001010, 0b00010000};
static u8 hamokshaDance2_0[8]= {   0b00010000, 0b00010000, 0b00001000, 0b00000100,
								   0b00001010, 0b00010001, 0b00010001, 0b00000000};

/*gun and bullet*/
static u8 hamokshaGun1[8]=	   {   0b00000000, 0b00000000, 0b00011111, 0b00011111,
								   0b00000111, 0b00001011, 0b00000011, 0b00000000};
static u8 hamokshaGun2[8]=	   {   0b00000000, 0b00000000, 0b00000011, 0b00000011,
								   0b00000000, 0b00000000, 0b00000000, 0b00000000};
static u8 hamokshaBullet1[8]=  {   0b00000000, 0b00000000, 0b00000110, 0b00000110,
								   0b00000000, 0b00000000, 0b00000000, 0b00000000};

/*character die*/
static u8 hamokshaDie1[8]=	   {   0b00000000, 0b00000110, 0b00001111, 0b00011111,
								   0b00001111, 0b00000110, 0b00000000, 0b00000000};
static u8 hamokshaDie2[8]=	   {   0b00000000, 0b00000010, 0b00011001, 0b00000111,
								   0b00001001, 0b00010010, 0b00000000, 0b00000000};
/*********************************************************************************************/

void main(void)
{
	/*LCD initialization, SET PORTS Direction*/
	LCD_voidInit();
	static u8 Local_u8Counter1;
	static u8 Local_u8Counter2;
	static u8 Local_u8Counter3;
	static u8 Local_u8Counter4;

	/*Hamoksha Story*/
	LCD_voidGoToXY(0, 4);
	LCD_voidPrintStrig("Hamoksha");
	LCD_voidGoToXY(1, 5);
	LCD_voidPrintStrig("Story");
	_delay_ms(1500);
	LCD_voidSendCommand(DISPLAY_CLR);

	/* 1- welcome Hamoksha */
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 14);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 14);
	LCD_voidGoToXY(0, 1);
	LCD_voidPrintStrig("Hello!");
	LCD_voidGoToXY(1, 0);
	LCD_voidPrintStrig("I'm Hamoksha");
	_delay_ms(2000);
	LCD_voidSendCommand(DISPLAY_CLR);

	/*Hamoksha is playing football*/
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 14);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 14);
	LCD_voidGoToXY(0, 0);
	LCD_voidPrintStrig("I Can");
	LCD_voidGoToXY(1, 0);
	LCD_voidPrintStrig("Play Football");
	_delay_ms(1500);
	LCD_voidSendCommand(DISPLAY_CLR);
	LCD_voidSpecialChar(hamokshaHead,     0, 0,14);
	LCD_voidSpecialChar(hamokshLeleg2,    1, 1,14);
	LCD_voidSpecialChar(hamokshBall1,     2, 1,13);
	LCD_voidSpecialChar(hamokshGoal1,     3, 0, 3);
	LCD_voidSpecialChar(hamokshGoal2,     4, 1, 3);
	_delay_ms(200);
	LCD_voidSendCommand(DISPLAY_CLR);
	for(Local_u8Counter1=12;Local_u8Counter1>3;Local_u8Counter1--){
		LCD_voidSpecialChar(hamokshaHead,0,0, 14);
		LCD_voidSpecialChar(hamokshLelegs,1,1,14);
		LCD_voidSpecialChar(hamokshGoal1,3, 0, 3);
		LCD_voidSpecialChar(hamokshGoal2,4, 1, 3);
		LCD_voidSpecialChar(hamokshBall2, 5, 0, Local_u8Counter1);
		_delay_ms(200);
		LCD_voidSendCommand(DISPLAY_CLR);
		LCD_voidSpecialChar(hamokshaHead,  0, 0, 14);
		LCD_voidSpecialChar(hamokshLelegs, 1, 1, 14);
		LCD_voidSpecialChar(hamokshGoal1,   3, 0, 3);
		LCD_voidSpecialChar(hamokshGoal2,   4, 1, 3);
		LCD_voidSpecialChar(hamokshBall2, 5, 1, Local_u8Counter1-1);
		_delay_ms(200);
		LCD_voidSendCommand(DISPLAY_CLR);
		Local_u8Counter1--;
	}
	LCD_voidGoToXY(0, 4);
	LCD_voidPrintStrig("Gooal!");
	_delay_ms(1000);
	LCD_voidSendCommand(DISPLAY_CLR);

	/*Hamoksha is running*/
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 14);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 14);
	LCD_voidGoToXY(0, 3);
	LCD_voidPrintStrig("I Can Run");
	_delay_ms(1000);
	LCD_voidSendCommand(DISPLAY_CLR);
	for(Local_u8Counter2=13;Local_u8Counter2>1;Local_u8Counter2--){
		LCD_voidSpecialChar(hamokshaHeadR,  0, 0, Local_u8Counter2);
		LCD_voidSpecialChar(hamokshLelegsR, 1, 1, Local_u8Counter2);
		_delay_ms(250);
		LCD_voidSendCommand(DISPLAY_CLR);
		LCD_voidSpecialChar(hamokshaHeadR2,  0, 0, Local_u8Counter2-1);
		LCD_voidSpecialChar(hamokshLelegsR2, 1, 1, Local_u8Counter2-1);
		_delay_ms(250);
		LCD_voidSendCommand(DISPLAY_CLR);
		Local_u8Counter2--;
	}
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
	_delay_ms(1000);
	LCD_voidSendCommand(DISPLAY_CLR);

	/*Hamoksha dance*/
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
	LCD_voidGoToXY(0, 4);
	LCD_voidPrintStrig("And I Can");
	LCD_voidGoToXY(1, 4);
	LCD_voidPrintStrig("Dance Hhhh");
	_delay_ms(1500);
	LCD_voidSendCommand(DISPLAY_CLR);
	for(Local_u8Counter3=0;Local_u8Counter3<=6;Local_u8Counter3++){
		LCD_voidSpecialChar(hamokshaDance1, 0, 0, 1);
		LCD_voidSpecialChar(hamokshaDance2, 1, 1, 1);
		_delay_ms(350);
		LCD_voidSendCommand(DISPLAY_CLR);
		LCD_voidSpecialChar(hamokshaDance1_0, 0, 0, 1);
		LCD_voidSpecialChar(hamokshaDance2_0, 1, 1, 1);
		_delay_ms(350);
		LCD_voidSendCommand(DISPLAY_CLR);
	}
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
	LCD_voidGoToXY(0, 4);
	LCD_voidPrintStrig("Can We Be ");
	LCD_voidGoToXY(1, 4);
	LCD_voidPrintStrig("Friends");
	_delay_ms(1000);
	LCD_voidSpecialChar(hamokshaGun1, 2, 0, 15);
	LCD_voidSpecialChar(hamokshaGun2, 3, 0, 14);
	_delay_ms(1000);
	LCD_voidSendCommand(DISPLAY_CLR);

	/*hamoksha die*/
	LCD_voidSpecialChar(hamokshaGun1, 2, 0, 15);
	LCD_voidSpecialChar(hamokshaGun2, 3, 0, 14);
	LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
	LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
	LCD_voidGoToXY(0, 3);
	LCD_voidPrintStrig("Noooo! ");
	LCD_voidGoToXY(1, 3);
	LCD_voidPrintStrig("dont kill me");
	_delay_ms(1000);
	for(Local_u8Counter4=13;Local_u8Counter4>=2;Local_u8Counter4--){
		LCD_voidSpecialChar(hamokshaGun1, 2, 0, 15);
		LCD_voidSpecialChar(hamokshaGun2, 3, 0, 14);
		LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
		LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
		LCD_voidSpecialChar(hamokshaBullet1, 4, 0, Local_u8Counter4);
		_delay_ms(100);
		LCD_voidSendCommand(DISPLAY_CLR);
	}
	LCD_voidSpecialChar(hamokshaDie1, 0, 1, 2);
	LCD_voidSpecialChar(hamokshaDie2, 1, 1, 1);
	_delay_ms(500);
	LCD_voidGoToXY(0, 7);
	LCD_voidPrintStrig("RIP");
	LCD_voidGoToXY(1, 5);
	LCD_voidPrintStrig("Hamoksha");
	_delay_ms(1000);
	LCD_voidSendCommand(DISPLAY_CLR);

	while(1)
	{
		/*hamoksha die*/
		LCD_voidSpecialChar(hamokshaGun1, 2, 0, 15);
		LCD_voidSpecialChar(hamokshaGun2, 3, 0, 14);
		LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
		LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
		LCD_voidGoToXY(0, 3);
		LCD_voidPrintStrig("Noooo! ");
		LCD_voidGoToXY(1, 3);
		LCD_voidPrintStrig("dont kill me");
		_delay_ms(1000);
		for(Local_u8Counter4=13;Local_u8Counter4>=2;Local_u8Counter4--){
			LCD_voidSpecialChar(hamokshaGun1, 2, 0, 15);
			LCD_voidSpecialChar(hamokshaGun2, 3, 0, 14);
			LCD_voidSpecialChar(hamokshaHead,  0, 0, 1);
			LCD_voidSpecialChar(hamokshLelegs, 1, 1, 1);
			LCD_voidSpecialChar(hamokshaBullet1, 4, 0, Local_u8Counter4);
			_delay_ms(100);
			LCD_voidSendCommand(DISPLAY_CLR);
		}
		LCD_voidSpecialChar(hamokshaDie1, 0, 1, 2);
		LCD_voidSpecialChar(hamokshaDie2, 1, 1, 1);
		_delay_ms(500);
		LCD_voidGoToXY(0, 7);
		LCD_voidPrintStrig("RIP");
		LCD_voidGoToXY(1, 5);
		LCD_voidPrintStrig("Hamoksha");
		_delay_ms(1000);
		LCD_voidSendCommand(DISPLAY_CLR);
	}

}
