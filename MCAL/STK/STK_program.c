/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 8 may ,2023   *****************/
/*****************     SWC : STK                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void ( * MSTK_CallBack ) ( void );

void SysTick_Handler(void){

	MSTK_CallBack();

}


void MSTK_voidInit (void)
{

    //Intializing The Clock Source

    #if CLK_SOURCE_SELECTION ==  (AHB/8)

    CLR_BIT(STK_CTRL , CLKSOURCE);

    //processor clock is AHB devided by 1
    #elif CLK_SOURCE_SELECTION == PROCESSOR_CLOCK

    SET_BIT(STK_CTRL , CLKSOURCE);

    #endif

    //INTERUPT ENABLE / DISABLE

    #if CLK_INTERUPT_SELECTION ==  DISABLE

    CLR_BIT(STK_CTRL , TICKINT);

    #elif CLK_INTERUPT_SELECTION == ENABLE

    SET_BIT(STK_CTRL , TICKINT);

    #endif


    //Counter Enable

    SET_BIT(STK_CTRL , ENABLE) ;


}

void MSTK_voidStart( u32 Copy_PreloadValue )
{
    //Load Reload Value
	STK_LOAD = Copy_PreloadValue - 1;
	//Enable Systick
	SET_BIT(STK_CTRL , ENABLE) ;
}

void MSTK_voidSetBusyWait (u32 Copy_u32WatingTime)
{


	MSTK_voidStart( Copy_u32WatingTime * 1000 );
	/* Wiat Flag Polling */
	while( GET_BIT(STK_CTRL , COUNTFLAG) == 0 );
    //Clear Val Register
	STK_VAL  = 0 ;
}


void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*ptr)(void))
{

	CLR_BIT(STK_CTRL , ENABLE) ;

	STK_VAL = 0;

    STK_LOAD = Copy_u32Ticks;

    MSTK_CallBack = ptr;


    SET_BIT(STK_CTRL , TICKINT);

    SET_BIT(STK_CTRL , ENABLE) ;
}

u32 MSTK_u32GetElapsedTime (void)
{
    u32 Local_u32Elapsed ;
    Local_u32Elapsed = (STK_LOAD) - (STK_VAL) ;
    return  Local_u32Elapsed ;
}

u32 MSTK_u32GetRemainingTime (void)
{
    return STK_VAL ;
}
void MSTK_voidResetSysTick(void)
{
	STK_VAL = 0;
}
