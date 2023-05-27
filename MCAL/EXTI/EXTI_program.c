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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*pvCallBack[16])(void)={{NULL}};


void MEXTI_voidInit(void)
{

}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTIline)
{
    if(Copy_u8EXTIline >15)
    {
        return ;
    }

    SET_BIT(MEXTI -> IMR , Copy_u8EXTIline);

}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTIline)
{
    if(Copy_u8EXTIline >15)
    {
        return ;
    }
    CLR_BIT(MEXTI -> IMR , Copy_u8EXTIline);
}
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTIline , u8 Copy_u8SenseSignal)
{
    switch (Copy_u8SenseSignal)
    {
    case MEXTI_RISING_EDGE:
        CLR_BIT(MEXTI ->FTSR , Copy_u8EXTIline);//Clear The Falling Edge Sense Enable
        SET_BIT(MEXTI ->RTSR , Copy_u8EXTIline);//Set The Rising Edge Sense Enable
        break;
    case MEXTI_FALLING_EDGE:
        CLR_BIT(MEXTI ->RTSR , Copy_u8EXTIline);
        SET_BIT(MEXTI ->FTSR , Copy_u8EXTIline);
        break;
    case MEXTI_ON_CHANGE:
        SET_BIT(MEXTI ->RTSR , Copy_u8EXTIline);
        SET_BIT(MEXTI ->FTSR , Copy_u8EXTIline);
        break;
    }
}
void MEXTI_voidSetCallBack(u8 Copy_u8EXTIline , void(*pvNotificationFunction)(void))
{
    pvCallBack[Copy_u8EXTIline] = pvNotificationFunction;
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[0] != NULL)
    {
        pvCallBack[0]();
    }
    SET_BIT(MEXTI -> PR , 0);
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[1] != NULL)
    {
        pvCallBack[1]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[2] != NULL)
    {
        pvCallBack[2]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[3] != NULL)
    {
        pvCallBack[3]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[4] != NULL)
    {
        pvCallBack[4]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[5] != NULL)
    {
        pvCallBack[5]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[6] != NULL)
    {
        pvCallBack[6]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[7] != NULL)
    {
        pvCallBack[7]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[8] != NULL)
    {
        pvCallBack[8]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[9] != NULL)
    {
        pvCallBack[9]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[10] != NULL)
    {
        pvCallBack[10]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[11] != NULL)
    {
        pvCallBack[11]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[12] != NULL)
    {
        pvCallBack[12]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[13] != NULL)
    {
        pvCallBack[13]();
    }
}
void EXTI0_IRQHandler(void)
{
    if(pvCallBack[14] != NULL)
    {
        pvCallBack[14]();
    }
}

void EXTI0_IRQHandler(void)
{
    if(pvCallBack[15] != NULL)
    {
        pvCallBack[15]();
    }
}
