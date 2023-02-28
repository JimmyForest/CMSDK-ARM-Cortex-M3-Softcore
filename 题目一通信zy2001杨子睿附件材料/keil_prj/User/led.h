#ifndef LED_H
#define LED_H

#include "gpio.h"

#define LED1_GPIO_PORT GPIOA

#define LED1_PIN GPIO_Pin_0

#define LED_ON(GPIO_PORT, LED_PIN) GPIO_ResetBits(GPIO_PORT, LED_PIN)
#define LED_OFF(GPIO_PORT, LED_PIN) GPIO_SetBits(GPIO_PORT, LED_PIN)

void LED_Init(void);

#endif

