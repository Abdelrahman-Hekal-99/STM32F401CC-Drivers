/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 22 may ,2023   *****************/
/*****************     SWC : EXTI                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#ifndef 	EXTI_INTERFACE_H
#define 	EXTI_INTERFACE_H

#define MEXTI_RISING_EDGE               0
#define MEXTI_FALLING_EDGE              1
#define MEXTI_ON_CHANGE                 2
#define	MEXTI_LINE0			0

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTIline);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTIline);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTIline , u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTIline , void(*pvNotificationFunction)(void));

#endif
