#include "key.h"

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = KEY1_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	//浮空输入
    GPIO_Config(GPIOA, &GPIO_InitStructure);
}

//轮询方式扫描两个按键，返回按键值
//timeout的单位为ms，若timeout = 0表示一直扫描，直到有键按下
KEYS ScanPressedKey(uint32_t timeout) {
	uint32_t tickstart = Read_SysTick_VALUE();	//当前计数值
	const uint32_t btnDelay = 20;	//按键按下阶段的抖动，延时再采样时间
	BitAction keyState;	//引脚输入状态

	while (1) {
#ifdef	KEY1_Pin	//如果定义了宏KEY1_Pin,就可以检测KEY1键输入，高输入有效
		keyState = GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin);
		if (keyState == Bit_SET) {
			delay_ms(btnDelay);	//延时跳过前抖动期
			keyState = GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin);	//再采样
			while (GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin))
				;	//等待按键弹起
			delay_ms(btnDelay);	//延时跳过后抖动期
			if (keyState == Bit_SET)
				return KEY1;
		}
#endif

#ifdef	KEY2_Pin	//如果定义了宏KEY2_Pin,就可以检测KEY2键输入，高输入有效
		keyState = GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin);
		if (keyState == Bit_SET) {
			delay_ms(btnDelay);	//延时跳过前抖动期
			keyState = GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin);	//再采样
			while (GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin))
				;	//等待按键弹起
			delay_ms(btnDelay);	//延时跳过后抖动期
			if (keyState == Bit_SET)
				return KEY2;
		}

		if (timeout != KEY_WAIT_ALWAYS)	//没有按键按下时会计算超时，timeout时退出
		{
			if ((Read_SysTick_VALUE() - tickstart) > timeout)
				break;
		}
	}
#endif

	return KEY_NONE;
	}
}
