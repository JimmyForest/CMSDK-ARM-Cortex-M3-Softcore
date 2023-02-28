#ifndef CORTEXM3_H
#define CORTEXM3_H

#include <stdint.h>
#include <stdio.h>

#pragma anon_unions

/*-------------------- Interrupt Number Definition --------------------*/

typedef enum IRQn
{
    /*-------------------- Cortex-M3 Processor Exceptions Numbers --------------------*/

    NonMaskableInt_IRQn = -14,   /*!<  2 Cortex-M3 Non Maskable Interrupt       */
    HardFault_IRQn = -13,        /*!<  3 Cortex-M3 Hard Fault Interrupt         */
    MemoryManagement_IRQn = -12, /*!<  4 Cortex-M3 Memory Management Interrupt  */
    BusFault_IRQn = -11,         /*!<  5 Cortex-M3 Bus Fault Interrupt          */
    UsageFault_IRQn = -10,       /*!<  6 Cortex-M3 Usage Fault Interrupt        */
    SVCall_IRQn = -5,            /*!< 11 Cortex-M3 SV Call Interrupt            */
    DebugMonitor_IRQn = -4,      /*!< 12 Cortex-M3 Debug Monitor Interrupt      */
    PendSV_IRQn = -2,            /*!< 14 Cortex-M3 Pend SV Interrupt            */
    SysTick_IRQn = -1,           /*!< 15 Cortex-M3 System Tick Interrupt        */

    /*-------------------- CM3DS_MPS2 Specific Interrupt Numbers --------------------*/

    UARTTX_IRQn = 0,  /* 发送中断 */
    UARTRX_IRQn = 1,  /* 接收中断 */
    UARTOVR_IRQn = 2, /* 发送或接收超限中断 */
	GPIO_IRQn = 3,    /* GPIO中断 */
}	IRQn_Type;


/* -------------------- Processor and Core Peripheral Section --------------------*/
/* Configuration of the Cortex-M3 Processor and Core Peripherals */

#define __CM3_REV 0x0201         /*!< Core Revision r2p1                             */
#define __NVIC_PRIO_BITS 3       /*!< Number of Bits used for Priority Levels        */
#define __Vendor_SysTickConfig 0 /*!< Set to 1 if different SysTick Config is used   */
#define __MPU_PRESENT 1          /*!< MPU present or not                             */

#include "core_cm3.h"

/*-------------------- Peripheral memory map --------------------*/
/* Peripheral and SRAM base address */

#define APB_BASE (0x40000000UL)
#define APB_UART_BASE (APB_BASE)

#define AHB_BASE (0x50000000UL)
#define GPIOA_BASE (AHB_BASE + 0x0000UL)

/*-------------------- Peripheral declaration --------------------*/

#define UART ((UART_TypeDef *)APB_UART_BASE)
#define APB_LED ((APB_LED_TypeDef *)APB_LED_BASE)
#define APB_KEY ((APB_KEY_TypeDef *)APB_KEY_BASE)

#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)

#endif
