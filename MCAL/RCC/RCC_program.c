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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"

void MRCC_voidInit (void)
{
    #if CLK_SOURCE == HSI
    /*Enable  HSI*/

    SET_BIT( RCC->CR , HSI_ON);

    /*CHOSE HSI AS A SYSTEM CLK (CPU CLK SOURCE) */

    CLR_BIT (RCC->CFGR , 0);
    CLR_BIT (RCC->CFGR , 1);

    #elif   CLK_SOURCE == HSE

    /*Enable  HSE*/
    SET_BIT( RCC-> CR , HSE_ON);

    /*CHOSE HSE AS A SYSTEM CLK (CPU CLK SOURCE) */
    SET_BIT (RCC -> CFGR , 0);
    CLR_BIT (RCC -> CFGR , 1);


    #elif   CLK_SOURCE == PLL
        #if PLL_SOURCE == HSI
        /*ENABLE HSI*/
        SET_BIT( RCC-> CR , HSI_ON);
        /*CHOSE HSI AS A PLL Source */
        CLR_BIT( RCC-> PLLCFGGR , 22);
        /*ENABLE PLL*/
        SET_BIT( RCC-> CR , PLL_ON);
        /*CHOSE PLL AS A SYSTEM CLK (CPU CLK SOURCE) */
        SET_BIT(RCC -> CFGR , 1)
        CLR_BIT (RCC -> CFGR , 0);


        #elif PLL_SOURCE == HSE
         /*Enable  HSE*/
        SET_BIT( RCC-> CR , HSE_ON);
        /*CHOSE HSE AS A PLL Source */
        SET_BIT( RCC-> PLLCFGR , 22);
        /*ENABLE PLL*/
        SET_BIT( RCC-> CR , PLL_ON);
        /*CHOSE PLL AS A SYSTEM CLK (CPU CLK SOURCE) */
        SET_BIT(RCC -> CFGR , 1)
        CLR_BIT (RCC -> CFGR , 0);

        #else
            #error " RCC_PLL_CLK_SOURCE CONFIGURATION ERROR"

        #endif


    #else
        #error " RCC_CPU_CLK_SOURCE CONFIGURATION ERROR"

    #endif

    #if AHB_PRESCALLER == SYSCLOCK_DIVIDE_BY_2
        (RCC -> CFGR) &= 0xFFFFFF0F ;
        (RCC -> CFGR) |= (AHB_PRESCALLER<<4);

    
    #endif



}

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
        SET_BIT(RCC -> AHB1ENR , Copy_u8PeripheralID) ;
        break;
    case RCC_AHB2:
        SET_BIT(RCC -> AHB2ENR , Copy_u8PeripheralID) ;
        break;

    case RCC_APB1:
        SET_BIT(RCC -> APB1ENR , Copy_u8PeripheralID) ;
        break;
    case RCC_APB2:
        SET_BIT(RCC -> APB2ENR , Copy_u8PeripheralID) ;
        break;
    
    default:
        break;
    }
}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
        CLR_BIT(RCC->AHB1ENR , Copy_u8PeripheralID) ;
        break;
    case RCC_AHB2:
        CLR_BIT(RCC->AHB2ENR , Copy_u8PeripheralID) ;
        break;

    case RCC_APB1:
        CLR_BIT(RCC->APB1ENR , Copy_u8PeripheralID) ;
        break;
    case RCC_APB2:
        CLR_BIT(RCC->APB2ENR , Copy_u8PeripheralID) ;
        break;
    
    default:
        break;
    }
}
