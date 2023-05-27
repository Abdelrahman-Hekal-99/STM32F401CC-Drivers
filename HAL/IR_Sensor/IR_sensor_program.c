/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 26 May  ,2023*****************/
/*****************     SWC : IR_Sensor              *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "IR_sensor_interface.h"

/*First Edge*/
static u8 APP_u8StartEadgeFlag = 0;

/*Time between every two falling edges*/
static u32 APP_u32ReceviedFrame[50] = {0};

/*Carry Decimal Number*/
static u8 ButtonData = 0;

/*Edge Number*/
static u8 APP_u8EdgeCounter = 0;

void IR_Sensor_Init(void)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOA);

	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN0 , GPIO_INPUT_MODE);
	MGPIO_voidSetPinOutputPUPD(MGPIO_PORTA , PIN0 ,GPIO_OUTPUT_PULL_UP);

	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN1 , GPIO_OUTPUT_MODE);
	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN2 , GPIO_OUTPUT_MODE);
	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN3 , GPIO_OUTPUT_MODE);

	MEXTI_voidEnableInterrupt(MEXTI_LINE0);

	MEXTI_voidChangeSenseMode(MEXTI_LINE0 , MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE0 , &Get_APPFRAME);

	MEXTI_voidEnableInterrupt(MEXTI_LINE0);

	MSTK_voidInit();
	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
}

void Get_APPFRAME (void)
{

	if (APP_u8StartEadgeFlag == 0)
	{
		MSTK_voidSetIntervalSingle(60000 , &App_TakeAction);
		APP_u8StartEadgeFlag = 1;
	}
	else
	{
		APP_u32ReceviedFrame[APP_u8EdgeCounter]=MSTK_u32GetElapsedTime();
		MSTK_voidResetSysTick();
		MSTK_voidSetIntervalSingle(60000 , &App_TakeAction);
		APP_u8EdgeCounter++;
	}
}
void App_TakeAction (void)
{
	u8 LoopCounter =0 ;
	for (LoopCounter=0 ; LoopCounter < 8 ; LoopCounter++)
	{
		if((APP_u32ReceviedFrame[17+LoopCounter]>=1000) && (APP_u32ReceviedFrame[17+LoopCounter]<=1500))
		{
			CLR_BIT(ButtonData ,LoopCounter );
		}
		else
		{
			SET_BIT(ButtonData ,LoopCounter );
		}
	}
	APP_u8EdgeCounter =0;
	APP_u8StartEadgeFlag = 0 ;

}
void IR_Sensor_Program(void)
{
    		switch(ButtonData)
		{
		// OFF Button
		case 69:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , LOW);
			break;
			//Button Number (1) For Led Light
		case 12:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , LOW);
			break;
			//Button Number (2) For GREEN Light
		case 24:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , LOW);
			break;
			//Button Number (3) For BLUE Light
		case 94:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , HIGH);
			break;
			//Button Number (4) For BLUE Light
		case 8:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , LOW);
			break;
			//Button Number (5) For BLUE Light
		case 28:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , HIGH);
			break;
			//Button Number (6) For BLUE Light
		case 90:
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN1 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN2 , HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA , PIN3 , HIGH);
			break;

		}
}
