/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 29 may ,2023  *****************/
/*****************     SWC : Serial To Parallel      *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_VoidInit (void)
{

    MGPIO_voidSetPinMode(STP_DATA_PORT, STP_DATA_PIN , GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(STP_BIT_LATCH_PORT  , STP_BIT_LATCH_PIN , GPIO_OUTPUT_MODE);
    MGPIO_voidSetPinMode(STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN, GPIO_OUTPUT_MODE);

    MGPIO_voidSetPinOutputSpeed(STP_DATA_PORT, STP_DATA_PIN , GPIO_OUTPUT_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(STP_BIT_LATCH_PORT  , STP_BIT_LATCH_PIN , GPIO_OUTPUT_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN, GPIO_OUTPUT_LOW_SPEED);

}
void STP_VoidByteOutput     ( u8  Copy_u8Data )
{
    u8 Local_u8Iterator ;

	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW );

	for( Local_u8Iterator = 8 ; Local_u8Iterator > 0 ; Local_u8Iterator-- ){

		MGPIO_voidSetPinValue( STP_DATA_PORT , STP_DATA_PIN , ( GET_BIT( Copy_u8Data , ( Local_u8Iterator - 1 ) ) ) );

		MGPIO_voidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , HIGH  );
		MSTK_voidSetBusyWait(50);
		MGPIO_voidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , LOW	 );

	}

	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH );
	MSTK_voidSetBusyWait(50);
	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW  );
}
void STP_VoidHalfWordOutput ( u16 Copy_u8Data )
{
    u8 Local_u8Iterator ;

	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW );

	for( Local_u8Iterator = 16 ; Local_u8Iterator > 0 ; Local_u8Iterator-- ){

		MGPIO_voidSetPinValue( STP_DATA_PORT , STP_DATA_PIN , ( GET_BIT( Copy_u8Data , ( Local_u8Iterator - 1 ) ) ) );

		MGPIO_voidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , HIGH  );
		MSTK_voidSetBusyWait(50);
		MGPIO_voidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , LOW	 );

	}

	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH );
	MSTK_voidSetBusyWait(50);
	MGPIO_voidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW  );
}