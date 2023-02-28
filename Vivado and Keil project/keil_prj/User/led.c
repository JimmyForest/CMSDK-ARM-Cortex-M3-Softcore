#include "led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = LED1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	//ÍÆÍìÊä³ö
    GPIO_Config(GPIOA, &GPIO_InitStructure);
}

