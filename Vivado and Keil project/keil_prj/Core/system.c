#include "CortexM3.h"
#include "system.h"
#include <string.h>

/*-------------------- Define clocks --------------------*/

#define __XTAL            (50000000UL)	//Oscillator frequency

#define __SYSTEM_CLOCK    (__XTAL)

/*-------------------- Clock Variable definitions --------------------*/

uint32_t SystemCoreClock = __SYSTEM_CLOCK;	//!< System Clock Frequency (Core Clock)

/*-------------------- Clock functions --------------------*/
/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */

volatile uint32_t SystemTicks = 0;

void SystemCoreClockUpdate (void)
{
    SystemCoreClock = __SYSTEM_CLOCK;
}

void SysTick_Handler(void)
{
    SystemTicks++;
}

void Set_SysTick_CTRL(uint32_t ctrl)
{
    SysTick->CTRL = ctrl;
}

void Set_SysTick_LOAD(uint32_t load)
{
    SysTick->LOAD = load;
}

uint32_t Read_SysTick_VALUE(void)
{
    return (SysTick->VAL);
}

void Set_SysTick_VALUE(uint32_t value)
{
    SysTick->VAL = value;
}

uint32_t Timer_Ini(void)
{
    SysTick->CTRL = 0;
    SysTick->LOAD = 0xffffff;
    SysTick->VAL = 0;
    SysTick->CTRL = 0x5;

    while (SysTick->VAL == 0);

    return (SysTick->VAL);
}

uint8_t Timer_Stop(uint32_t *duration_t, uint32_t start_t)
{
    uint32_t stop_t;
    stop_t = SysTick->VAL;

    if ((SysTick->CTRL & 0x10000) == 0)
    {
        *duration_t = start_t - stop_t;
        return (1);
    }
    else
    {
        return (0);
    }
}

void delay(uint32_t time)
{
    Set_SysTick_CTRL(0);
    Set_SysTick_LOAD(time);
    Set_SysTick_VALUE(0);
    Set_SysTick_CTRL(0x7);
    __wfi();
}

void delay_us(uint16_t time)  // —” ±1us
{
	for(uint16_t i = 0; i < time; i++)
	{
		delay(50);
	}
}

void delay_ms(uint16_t time)  // —” ±1ms
{
	for(uint16_t j = 0; j < time; j++)
	{
		delay_us(1000);
	}
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */

void SystemInit (void)
{
    SystemCoreClock = __SYSTEM_CLOCK;
    NVIC_EnableIRQ(SysTick_IRQn);
    uart_init(UART, (SystemCoreClock / 115200), 1, 1, 0, 0, 0, 0);
}
