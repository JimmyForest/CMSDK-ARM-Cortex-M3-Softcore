#include "key.h"

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = KEY1_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	//��������
    GPIO_Config(GPIOA, &GPIO_InitStructure);
}

//��ѯ��ʽɨ���������������ذ���ֵ
//timeout�ĵ�λΪms����timeout = 0��ʾһֱɨ�裬ֱ���м�����
KEYS ScanPressedKey(uint32_t timeout) {
	uint32_t tickstart = Read_SysTick_VALUE();	//��ǰ����ֵ
	const uint32_t btnDelay = 20;	//�������½׶εĶ�������ʱ�ٲ���ʱ��
	BitAction keyState;	//��������״̬

	while (1) {
#ifdef	KEY1_Pin	//��������˺�KEY1_Pin,�Ϳ��Լ��KEY1�����룬��������Ч
		keyState = GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin);
		if (keyState == Bit_SET) {
			delay_ms(btnDelay);	//��ʱ����ǰ������
			keyState = GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin);	//�ٲ���
			while (GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin))
				;	//�ȴ���������
			delay_ms(btnDelay);	//��ʱ�����󶶶���
			if (keyState == Bit_SET)
				return KEY1;
		}
#endif

#ifdef	KEY2_Pin	//��������˺�KEY2_Pin,�Ϳ��Լ��KEY2�����룬��������Ч
		keyState = GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin);
		if (keyState == Bit_SET) {
			delay_ms(btnDelay);	//��ʱ����ǰ������
			keyState = GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin);	//�ٲ���
			while (GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin))
				;	//�ȴ���������
			delay_ms(btnDelay);	//��ʱ�����󶶶���
			if (keyState == Bit_SET)
				return KEY2;
		}

		if (timeout != KEY_WAIT_ALWAYS)	//û�а�������ʱ����㳬ʱ��timeoutʱ�˳�
		{
			if ((Read_SysTick_VALUE() - tickstart) > timeout)
				break;
		}
	}
#endif

	return KEY_NONE;
	}
}
