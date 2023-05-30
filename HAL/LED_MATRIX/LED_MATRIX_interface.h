/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 15 may ,2023   *****************/
/*****************     SWC : LED_MATRIX              *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#ifndef 	LED_MATRIX_INTERFACE_H
#define 	LED_MATRIX_INTERFACE_H

void HLEDMAT_voidInit(void);
void HLEDMAT_voidDisplay(u8 * Copy_pu8Data);
static void voidDisableAllColumns(void);

#endif