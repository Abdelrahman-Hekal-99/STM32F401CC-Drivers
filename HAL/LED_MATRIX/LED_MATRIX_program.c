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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_MATRIX_interface.h"
#include "LED_MATRIX_private.h"
#include "LED_MATRIX_config.h"

void HLEDMAT_voidInit(void)
{
    /*Initialize Row Pins To Be Output Pins*/
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R0_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R1_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R2_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R3_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R4_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R5_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R6_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_ROWS_PORT, LEDMAT_R7_PIN, GPIO_OUTPUT_MODE);
    
    /*Initialize Column Pins To Be Output Pins*/
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C0_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C1_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C2_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C3_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C4_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C5_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C6_PIN, GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMAT_COLS_PORT, LEDMAT_C7_PIN, GPIO_OUTPUT_MODE);
    /*Disbale All Columns*/
    voidDisableAllColumns();
}


void HLEDMAT_voidDisplay(u8 * Copy_pu8Data)
{
    u8 Local_u8ColumnIndex = 0;
    u8 Local_u8RowIndex = 0;
    u8 Local_u8Bit = 0;
    static u8 RowsArray[8] =  { LEDMAT_R0_PIN,
                                LEDMAT_R1_PIN, 
                                LEDMAT_R2_PIN, 
                                LEDMAT_R3_PIN, 
                                LEDMAT_R4_PIN, 
                                LEDMAT_R5_PIN, 
                                LEDMAT_R6_PIN, 
                                LEDMAT_R7_PIN};

    static u8 ColumnsArray[8] =  {  LEDMAT_C0_PIN,
                                    LEDMAT_C1_PIN, 
                                    LEDMAT_C2_PIN, 
                                    LEDMAT_C3_PIN, 
                                    LEDMAT_C4_PIN, 
                                    LEDMAT_C5_PIN, 
                                    LEDMAT_C6_PIN, 
                                    LEDMAT_C7_PIN};

    for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex < 8; Local_u8ColumnIndex++)
    {
        voidDisableAllColumns();
        for(Local_u8RowIndex = 0; Local_u8RowIndex < 8; Local_u8RowIndex++)
        {
            Local_u8Bit = GET_BIT(Copy_pu8Data[Local_u8ColumnIndex], Local_u8RowIndex);
            MGPIO_voidSetPinValue(LEDMAT_ROWS_PORT, RowsArray[Local_u8RowIndex], Local_u8Bit);
        }
        MGPIO_voidSetPinValue(LEDMAT_COLS_PORT, ColumnsArray[Local_u8ColumnIndex], LOW);
        MSTK_voidSetBusyWait(2500);
    }
}



static void voidDisableAllColumns(void)
{
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C0_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C1_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C2_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C3_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C4_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C5_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C6_PIN, HIGH);
    MGPIO_voidSetPinValue(LEDMAT_COLS_PORT ,LEDMAT_C7_PIN, HIGH);
    
}