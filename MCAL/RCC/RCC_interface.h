/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 1 may ,2023   *****************/
/*****************     SWC : RCC                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#ifndef 	RCC_INTERFACE_H
#define 	RCC_INTERFACE_H


#define RCC_AHB1                 0
#define RCC_AHB2                 1
#define RCC_APB1                 2
#define RCC_APB2                 3

#define RCC_GPIOA                0
#define RCC_GPIOB                1
#define RCC_GPIOC                2


void MRCC_voidInit (void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralID);

#endif