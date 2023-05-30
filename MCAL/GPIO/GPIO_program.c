/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 2 may ,2023   *****************/
/*****************     SWC : GPIO                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinMode (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8Mode )
{
	switch ((Copy_u8PortName))
	{
	case MGPIO_PORTA:

		switch (Copy_u8Mode)
		{
		case GPIO_INPUT_MODE:
			GPIOA_MODER |= GPIO_INPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_OUTPUT_MODE:
			GPIOA_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_AF_MODE:
			GPIOA_MODER |= GPIO_AF_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_ANALOG_MODE:
			GPIOA_MODER |= GPIO_ANALOG_MODE << (Copy_u8PPinNumber * 2);
			break;
		
		}
		break;
	case MGPIO_PORTB:
		switch (Copy_u8Mode)
		{
		case GPIO_INPUT_MODE:
			GPIOB_MODER |= GPIO_INPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_OUTPUT_MODE:
			GPIOB_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_AF_MODE:
			GPIOB_MODER |= GPIO_AF_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_ANALOG_MODE:
			GPIOB_MODER |= GPIO_ANALOG_MODE << (Copy_u8PPinNumber * 2);
			break;
		
		}
		break;
	case MGPIO_PORTC:
		switch (Copy_u8Mode)
		{
		case GPIO_INPUT_MODE:
			GPIOC_MODER |= GPIO_INPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_OUTPUT_MODE:
			GPIOC_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_AF_MODE:
			GPIOC_MODER |= GPIO_AF_MODE << (Copy_u8PPinNumber * 2);
			break;
		case GPIO_ANALOG_MODE:
			GPIOC_MODER |= GPIO_ANALOG_MODE << (Copy_u8PPinNumber * 2);
			break;
		
		}
		break;
	}
}



void MGPIO_voidSetPinOutputType (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8OutputMode )
{
	switch ((Copy_u8PortName))
	{
	case MGPIO_PORTA:
		
		switch (Copy_u8OutputMode)
		{
		case GPIO_OUTPUT_PUSH_PULL:
			CLR_BIT(GPIOA_OTYPER , Copy_u8PPinNumber );
			break;
		case GPIO_OUTPUT_OPEN_DRAIN :
			SET_BIT(GPIOA_OTYPER , Copy_u8PPinNumber );
			break;

		}
		break;

	case MGPIO_PORTB:
		
		switch (Copy_u8OutputMode)
		{
		case GPIO_OUTPUT_PUSH_PULL:
			CLR_BIT(GPIOB_OTYPER , Copy_u8PPinNumber );
			break;
		case GPIO_OUTPUT_OPEN_DRAIN :
			SET_BIT(GPIOB_OTYPER , Copy_u8PPinNumber );
			break;

		}
		break;
	
	case MGPIO_PORTC:
		
		switch (Copy_u8OutputMode)
		{
		case GPIO_OUTPUT_PUSH_PULL:
			CLR_BIT(GPIOC_OTYPER , Copy_u8PPinNumber );
			break;
		case GPIO_OUTPUT_OPEN_DRAIN :
			SET_BIT(GPIOC_OTYPER , Copy_u8PPinNumber );
			break;

		}
		break;

	}
}

void MGPIO_voidSetPinOutputPUPD (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8OutputPUPD )
{
	switch ((Copy_u8PortName))
	{
	case MGPIO_PORTA:
		
		switch (Copy_u8OutputPUPD)
		{
		case GPIO_OUTPUT_NO_PUPD:
			GPIOA_PUPDR |= GPIO_OUTPUT_NO_PUPD << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_UP:
			GPIOA_PUPDR |= GPIO_OUTPUT_PULL_UP << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_DOWN:
			GPIOA_PUPDR |= GPIO_OUTPUT_PULL_DOWN << (Copy_u8PPinNumber * 2 );
			break;

		}
		break;
		case MGPIO_PORTB:
		
		switch (Copy_u8OutputPUPD)
		{
		case GPIO_OUTPUT_NO_PUPD:
			GPIOB_PUPDR |= GPIO_OUTPUT_NO_PUPD << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_UP:
			GPIOB_PUPDR |= GPIO_OUTPUT_PULL_UP << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_DOWN:
			GPIOB_PUPDR |= GPIO_OUTPUT_PULL_DOWN << (Copy_u8PPinNumber * 2 );
			break;

		}
		break;
	
		case MGPIO_PORTC:
		
		switch (Copy_u8OutputPUPD)
		{
		case GPIO_OUTPUT_NO_PUPD:
			GPIOC_PUPDR |= GPIO_OUTPUT_NO_PUPD << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_UP:
			GPIOC_PUPDR |= GPIO_OUTPUT_PULL_UP << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_PULL_DOWN:
			GPIOC_PUPDR |= GPIO_OUTPUT_PULL_DOWN << (Copy_u8PPinNumber * 2 );
			break;

		}
		break;
	}
}
void MGPIO_voidSetPinOutputSpeed (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8OutputSpeed )
{
	switch ((Copy_u8PortName))
	{
	case MGPIO_PORTA:
		switch (Copy_u8OutputSpeed)
		{
		case GPIO_OUTPUT_LOW_SPEED:
			GPIOA_OSPEEDR |= GPIO_OUTPUT_LOW_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_MEDIUM_SPEED:
			GPIOA_OSPEEDR |= GPIO_OUTPUT_MEDIUM_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_HIGH_SPEED:
			GPIOA_OSPEEDR |= GPIO_OUTPUT_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_VERY_HIGH_SPEED:
			GPIOA_OSPEEDR |= GPIO_OUTPUT_VERY_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
	
		}
		break;
	case MGPIO_PORTB:
		switch (Copy_u8OutputSpeed)
		{
		case GPIO_OUTPUT_LOW_SPEED:
			GPIOB_OSPEEDR |= GPIO_OUTPUT_LOW_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_MEDIUM_SPEED:
			GPIOB_OSPEEDR |= GPIO_OUTPUT_MEDIUM_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_HIGH_SPEED:
			GPIOB_OSPEEDR |= GPIO_OUTPUT_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_VERY_HIGH_SPEED:
			GPIOB_OSPEEDR |= GPIO_OUTPUT_VERY_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
	
		}
		break;
	case MGPIO_PORTC:
		switch (Copy_u8OutputSpeed)
		{
		case GPIO_OUTPUT_LOW_SPEED:
			GPIOC_OSPEEDR |= GPIO_OUTPUT_LOW_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_MEDIUM_SPEED:
			GPIOC_OSPEEDR |= GPIO_OUTPUT_MEDIUM_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_HIGH_SPEED:
			GPIOC_OSPEEDR |= GPIO_OUTPUT_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
		case GPIO_OUTPUT_VERY_HIGH_SPEED:
			GPIOC_OSPEEDR |= GPIO_OUTPUT_VERY_HIGH_SPEED << (Copy_u8PPinNumber * 2 );
			break;
	
		}
		break;

	}
}

void MGPIO_voidSetPinValue (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8PinValue )
{
	switch ((Copy_u8PortName))
	{
	case MGPIO_PORTA:
		
		switch ((Copy_u8PinValue))
		{
		case  HIGH :
			SET_BIT(GPIOA_ODR , Copy_u8PPinNumber);
			break;
		case  LOW :
			CLR_BIT(GPIOA_ODR , Copy_u8PPinNumber);
			break;
		}
		break;

	case MGPIO_PORTB:
		
		switch ((Copy_u8PinValue))
		{
		case  HIGH :
			SET_BIT(GPIOB_ODR , Copy_u8PPinNumber);
			break;
		case  LOW :
			CLR_BIT(GPIOB_ODR , Copy_u8PPinNumber);
			break;
		}
		break;
	case MGPIO_PORTC:
		
		switch ((Copy_u8PinValue))
		{
		case  HIGH :
			SET_BIT(GPIOC_ODR , Copy_u8PPinNumber);
			break;
		case  LOW :
			CLR_BIT(GPIOC_ODR , Copy_u8PPinNumber);
			break;
		}
		break;
	}
}


