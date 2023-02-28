#include "CortexM3.h"
#include "system.h"
#include "uart.h"
#include "gpio.h"
#include "led.h"
#include "key.h"

void NMIHandler(void)
{
    ;
}

void HardFaultHandler(void)
{
    ;
}

void MemManageHandler(void)
{
    ;
}

void BusFaultHandler(void)
{
    ;
}

void UsageFaultHandler(void)
{
    ;
}

void SVCHandler(void)
{
    ;
}

void DebugMonHandler(void)
{
    ;
}

void PendSVHandler(void)
{
    ;
}

void SysTickHandler(void)
{
    Set_SysTick_CTRL(0);
    SCB->ICSR = SCB->ICSR | (1 << 25);
}

void UARTTXHandler(void)
{
    ;
}

void UARTRXHandler(void)
{
    int data;
    data = uart_ReceiveChar(UART);
    uart_SendString("M3:");
    uart_SendChar(UART, data);
    uart_SendChar(UART, '\n');
}

void UARTOVRHandler(void)
{
    ;
}

void GPIOHandler(void)
{
	LED_OFF(LED1_GPIO_PORT, LED1_PIN);
	delay_ms(200);
}

