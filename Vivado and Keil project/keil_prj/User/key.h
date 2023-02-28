#ifndef KEY_H
#define KEY_H

#include <stdint.h>
#include <stdio.h>
#include "system.h"

typedef enum {
	KEY_NONE = 0,	//没有按键被按下
	KEY1,		//左边KEY1按键
	KEY2		//右边KEY2按键
} KEYS;

#define	KEY_WAIT_ALWAYS	0	//作为函数ScanKeys()的一种参数，表示一直等待按键输入
//轮询方式扫描按键，timeout = KEY_WAIT_ALWAYS时一直扫描，否则等待时间timeout，单位ms

#define KEY1_GPIO_Port GPIOA

#define KEY1_Pin GPIO_Pin_1 

KEYS ScanPressedKey(uint32_t timeout);
void KEY_Init(void);

#endif

