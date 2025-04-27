#ifndef _DRIVER_BASE_
#define _DRIVER_BASE_

#include <cstdint>

#pragma pack(push, 1)

#define RCC_BASE   (0x40021000U)

#define GPIO_BASE (0x40010800U)

#define GPIOA_BASE (0x40010800U)
#define GPIOB_BASE (GPIOA_BASE+0x400U)
#define GPIOC_BASE (GPIOB_BASE+0x400U)
#define GPIOD_BASE (GPIOC_BASE+0x400U)
#define GPIOE_BASE (GPIOD_BASE+0x400U)
#define GPIOF_BASE (GPIOE_BASE+0x400U)
#define GPIOG_BASE (GPIOF_BASE+0x400U)

#define UART_BASE (0x40004400U)
#define UART_1_BASE (0x40013800U)
#define UART_2_BASE (UART_BASE)
#define UART_3_BASE (UART_2_BASE+0x400U)
#define UART_4_BASE (UART_3_BASE+0x400U)
#define UART_5_BASE (UART_4_BASE+0x400U)



#define APB2 (RCC_BASE+0x18U)

	typedef struct{
		volatile uint32_t CRL;
		volatile uint32_t CRH;
		volatile uint32_t IDR;
		volatile uint32_t ODR;
		volatile uint32_t BSRR;
		volatile uint32_t BRR;
		volatile uint32_t LCKR;
	}GPIO_t;

	typedef struct{
		volatile uint32_t CR;
		volatile uint32_t CFGR;
		volatile uint32_t CIR;
		volatile uint32_t APB2RSTR;
		volatile uint32_t APB1RSTR;
		volatile uint32_t AHBENR;
		volatile uint32_t APB2ENR;
		volatile uint32_t APB1ENR;
		volatile uint32_t BCDCR;
		volatile uint32_t CSR;
		volatile uint32_t AHBRSTR;
		volatile uint32_t CFGR2;

	}RCC_t;

	typedef struct{
		volatile uint32_t SR;
		volatile uint32_t DR;
		volatile uint32_t BRR;
		volatile uint32_t CR1;
		volatile uint32_t CR2;
		volatile uint32_t CR3;
		volatile uint32_t GTPR;
	}UART_t;

	typedef enum{
		PORTA,
		PORTB,
		PORTC,
		PORTD,
		PORTE,
		PORTF,
		PORTG
	}GPIO_PORT_E;


/***GPIO***/
#define GPIOA ((GPIO_t*)GPIOA_BASE)
#define GPIOB ((GPIO_t*)GPIOB_BASE)
#define GPIOC ((GPIO_t*)GPIOC_BASE)
#define GPIOD ((GPIO_t*)GPIOD_BASE)
#define GPIOE ((GPIO_t*)GPIOE_BASE)
#define GPIOF ((GPIO_t*)GPIOF_BASE)
#define GPIOG ((GPIO_t*)GPIOG_BASE)
/** RCC **/
#define RCC  ((RCC_t*)RCC_BASE)

/**UART**/
#define UART1 ((UART_t *)UART_1_BASE) //exclusive case , not aligned
#define UART2 ((UART_t *)UART_2_BASE)
#define UART3 ((UART_t *)UART_3_BASE)
#define UART4 ((UART_t *)UART_4_BASE)
#define UART5 ((UART_t *)UART_5_BASE)


#endif
