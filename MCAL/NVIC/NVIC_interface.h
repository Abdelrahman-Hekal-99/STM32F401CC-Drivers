/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 21 may ,2023   *****************/
/*****************     SWC : NVIC                    *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define     MNVIC_EXTI0     6
#define     MNVIC_EXTI1     7

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif