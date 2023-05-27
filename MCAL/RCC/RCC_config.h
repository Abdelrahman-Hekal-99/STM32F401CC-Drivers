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

#ifndef 	RCC_CONFIG_H
#define 	RCC_CONFIG_H

/*OPTIONS : */
/*
        HSI
        HSE
        PLL
*/
#define 		HSI					0
#define 		HSE					1
#define 		PLL					2

#define			CLK_SOURCE                       HSI

/*OPTIONS : */
/*            
 HSI
 HSE
 PLL
*/            
#define        SYSTEM_CLK                       HSI

#define        AHB_PRESCALLER              SYSCLOCK_DIVIDE_BY_2

#define        APB1_PRESCALLER                   APB1_2_DIVIDE_BY_2

#define        PLL_SOURCE      HSE




#endif
