#ifndef SYSTEM_H
#define SYSTEM_H

#include "CortexM3.h"
#include "uart.h"
#include "gpio.h"

/*-------------------- SYSTICK --------------------*/

extern void delay(uint32_t time);
extern void Set_SysTick_CTRL(uint32_t ctrl);
extern void Set_SysTick_LOAD(uint32_t load);
extern uint32_t Read_SysTick_VALUE(void);
extern void Set_SysTick_VALUE(uint32_t value);
extern void Set_SysTick_CALIB(uint32_t calib);
extern uint32_t Timer_Ini(void);
extern uint8_t Timer_Stop(uint32_t *duration_t, uint32_t start_t);
extern void delay_us(uint16_t time);
extern void delay_ms(uint16_t time);

#endif








