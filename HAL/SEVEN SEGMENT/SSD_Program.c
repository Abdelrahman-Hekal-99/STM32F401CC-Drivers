/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 31 Mar ,2023  *****************/
/*****************     SWC : Seven Segment           *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"




void SSD_u8SetNumber(u8 CPY_u8Port , u8 CPY_u8Number , u8 CPY_u8Type)
{
	u8 arr[10] = {	   0b00111111,   /* 0 */
                       0b00000110,   /* 1 */
                       0b01011011,   /* 2 */
                       0b01001111,   /* 3 */
                       0b01100110,   /* 4 */
                       0b01101101,   /* 5 */
                       0b01111101,   /* 6 */
                       0b00000111,   /* 7 */
                       0b01111111,   /* 8 */
                       0b01101111    /* 9 */
				 };
	MGPIO_voidSetPortMode(CPY_u8Port , GPIO_OUTPUT_MODE);
				 
	if ((CPY_u8Number<=9) && (CPY_u8Number>=0))
	{
		if (CPY_u8Type==0)
		{
		MGPIO_voidSetPortValue(CPY_u8Port ,arr[CPY_u8Number]);
		}
		else 
		{
			MGPIO_voidSetPortValue(CPY_u8Port ,~arr[CPY_u8Number]);
		}
	}
}
