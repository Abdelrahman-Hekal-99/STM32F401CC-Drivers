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

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/***********************************/
/*   REGISTERS ADDRESS FOR SYSTICK */
/***********************************/

#define STK_BASE_ADDRESS				0xE000E010

#define		STK_CTRL 			*((volatile u32 *)(STK_BASE_ADDRESS + 0X00))	
#define		STK_LOAD 		    *((volatile u32 *)(STK_BASE_ADDRESS + 0X04))	
#define		STK_VAL		        *((volatile u32 *)(STK_BASE_ADDRESS + 0X08))
#define		STK_CALIB 		    *((volatile u32 *)(STK_BASE_ADDRESS + 0X0C))


/**********************************/
/*   REGISTERS PINS FOR STK_CTRL  */
/**********************************/

#define     COUNTFLAG           16
#define     CLKSOURCE           2
#define     TICKINT             1
#define     ENABLE              0

/**********************************/
/*   REGISTERS PINS FOR STK_CALIB */
/**********************************/

#define     NOREF               31
#define     SKEW                30



#endif