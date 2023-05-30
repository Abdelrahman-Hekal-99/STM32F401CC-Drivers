/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 2 may ,2023   *****************/
/*****************     SWC : GPIO                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#ifndef 	GPIO_INTERFACE_H
#define 	GPIO_INTERFACE_H

/********************************/
/*          GPIO PORTS          */
/********************************/
#define MGPIO_PORTA			0
#define MGPIO_PORTB			1
#define MGPIO_PORTC			2


/********************************/
/*          GPIO PINS          */
/********************************/
#define PIN0                    0
#define PIN1                    1
#define PIN2                    2
#define PIN3                    3
#define PIN4                    4
#define PIN5                    5
#define PIN6                    6
#define PIN7                    7
#define PIN8                    8
#define PIN9                    9
#define PIN10                   10
#define PIN11                   11
#define PIN12                   12
#define PIN13                   13
#define PIN14                   14
#define PIN15                   15


/********************************/
/*          GPIO MODES          */
/********************************/

#define GPIO_INPUT_MODE             0b00
#define GPIO_OUTPUT_MODE			0b01
#define GPIO_AF_MODE                0b10
#define GPIO_ANALOG_MODE            0b11

/****************************************/
/*          GPIO OUTPUT OPTIONS         */
/****************************************/

#define GPIO_OUTPUT_PUSH_PULL       0
#define GPIO_OUTPUT_OPEN_DRAIN      1

/**********************************************/
/*          GPIO OUTPUT PUPD OPTIONS          */
/**********************************************/

#define GPIO_OUTPUT_NO_PUPD                 0b00
#define GPIO_OUTPUT_PULL_UP                 0b01
#define GPIO_OUTPUT_PULL_DOWN               0b10

/**********************************************/
/*          GPIO OUTPUT SPEED OPTIONS         */
/**********************************************/

#define GPIO_OUTPUT_LOW_SPEED               0b00
#define GPIO_OUTPUT_MEDIUM_SPEED            0b01
#define GPIO_OUTPUT_HIGH_SPEED              0b10
#define GPIO_OUTPUT_VERY_HIGH_SPEED         0b11






#define HIGH                    1
#define LOW                     0


void MGPIO_voidSetPinMode (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8Mode );

void MGPIO_voidSetPinOutputType (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8Mode );

void MGPIO_voidSetPinOutputPUPD (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8OutputPUPD );

void MGPIO_voidSetPinOutputSpeed (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8Speed );

void MGPIO_voidSetPinValue (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber ,u8 Copy_u8PinValue );

u8 MGPIO_voidGetPinValue (u8 Copy_u8PortName ,u8 Copy_u8PPinNumber);


#endif
