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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


void MNVIC_voidInit(void)
{
    /*Set The Group And Sub Priorities Distrubtion*/
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (MNVIC_GRP_SUB_DISTRUBTION << 8);
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISER[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ICER[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
    
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISPR[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ICPR[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{

}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    MNVIC -> IPR[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}