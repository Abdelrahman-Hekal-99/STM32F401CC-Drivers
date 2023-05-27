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

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void MSTK_voidInit (void);

void MSTK_voidStart( u32 Copy_PreloadValue );

void MSTK_voidSetBusyWait (u32 Copy_u32WatingTime);

void MSTK_voidSetIntervalSingle (u32 Copy_u32WatingTime , void (*ptr)(void));

u32 MSTK_u32GetElapsedTime (void) ;

u32 MSTK_u32GetRemainingTime (void) ;



#endif
