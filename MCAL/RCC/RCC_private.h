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

#ifndef 	RCC_PRIVATE_H
#define 	RCC_PRIVATE_H

//0x4002 3800

//#define RCC_BASE_ADDRESS            0x4002 3800      
//#define RCC_CR                      *((volatile u32 *)(RCC_BASE_ADDRESS+0x00))

//some needed macros refers to the bit number
#define HSI_ON		0
#define HSI_RDY		1
#define HSE_ON		16
#define HSE_RDY		17
#define PLL_ON		24
#define PLL_RDY		25


typedef struct 
{
    volatile u32 CR ;
    volatile u32 PLLCFGR ;
    volatile u32 CFGR ;
    volatile u32 CIR ;
    volatile u32 AHB1RSTR ;
    volatile u32 AHB2RSTR ;
    volatile u32 Reserved1[2] ;
    volatile u32 APB1RSTR ;
    volatile u32 APB2RSTR ;
    volatile u32 Reserved2[2] ;
    volatile u32 AHB1ENR ;
    volatile u32 AHB2ENR ;
    volatile u32 Reserved3[2] ;
    volatile u32 APB1ENR ;
    volatile u32 APB2ENR ;
    volatile u32 Reserved4[2] ;
    volatile u32 AHB1LPENR ;
    volatile u32 AHB2LPENR ;
    volatile u32 Reserved5[2] ;
    volatile u32 APB1LPENR ;
    volatile u32 APB2LPENR ;
    volatile u32 Reserved6[2] ;
    volatile u32 BDCR ;
    volatile u32 CSR ;
    volatile u32 Reserved7[2] ;
    volatile u32 SSCGR ;
    volatile u32 PLLI2SCFGR ;
    volatile u32 Reserved8 ;
    volatile u32 DCKCFGR ;

}RCC_t ;


#define RCC   ((volatile RCC_t *)0x40023800)


/*Prescaller for APB1 and APB2*/

#define APB1_2_DIVIDE_BY_2      0
#define APB1_2_DIVIDE_BY_4      1
#define APB1_2_DIVIDE_BY_8      2

/*Prescaller foe AHB
SYSCLOCK Options : HSI - HSE - PLL*/

#define SYSCLOCK_DIVIDE_BY_1     0
#define SYSCLOCK_DIVIDE_BY_2     8
#define SYSCLOCK_DIVIDE_BY_4     9
#define SYSCLOCK_DIVIDE_BY_8     10
#define SYSCLOCK_DIVIDE_BY_16    11


#define AHB1RSTR_GPIOARST        0
#define AHB1RSTR_GPIOBRST        1
#define AHB1RSTR_GPIOCRST        2
#define AHB1RSTR_GPIODRST        3
#define AHB1RSTR_GPIOERST        4
#define AHB1RSTR_GPIOHRST        7

#define AHB1ENR_GPIOAEN         0       
#define AHB1ENR_GPIOBEN         1
#define AHB1ENR_GPIOCEN         2
#define AHB1ENR_GPIODEN         3
#define AHB1ENR_GPIOEEN         4
#define AHB1ENR_GPIOHEN         7

#define AHB1LPENR_GPIOALPEN     0
#define AHB1LPENR_GPIOBLPEN     1
#define AHB1LPENR_GPIOCLPEN     2
#define AHB1LPENR_GPIODLPEN     3
#define AHB1LPENR_GPIOELPEN     4
#define AHB1LPENR_GPIOHLPEN     7



#endif
