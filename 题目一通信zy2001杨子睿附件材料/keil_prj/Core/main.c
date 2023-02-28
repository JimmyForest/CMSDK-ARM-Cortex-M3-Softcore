#include "CortexM3.h"
#include "system.h"
#include "uart.h"
#include "gpio.h"
#include "spi_gpio.h"
#include "led.h"
#include "key.h"

extern uint32_t SystemCoreClock;
void SystemInit(void);

int main(void)
{
    SysTick_Config(SystemCoreClock / 1000);  //1ms
    SystemInit();
	
	char *a = "hello\n";
	uint8_t ReadBuffer[20];
//	uart_SendString(a);

	SPI_Init();
	LED_Init();
	KEY_Init();

    while (1)
    {
		LED_ON(LED1_GPIO_PORT, LED1_PIN);
		delay_ms(200);
		Master_SPI_WR_String(ReadBuffer, (uint8_t*)a, strlen(a));
		LED_OFF(LED1_GPIO_PORT, LED1_PIN);
		delay_ms(200);
    }
}
