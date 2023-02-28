#ifndef KEY_H
#define KEY_H

#include <stdint.h>
#include <stdio.h>
#include "system.h"

typedef enum {
	KEY_NONE = 0,	//û�а���������
	KEY1,		//���KEY1����
	KEY2		//�ұ�KEY2����
} KEYS;

#define	KEY_WAIT_ALWAYS	0	//��Ϊ����ScanKeys()��һ�ֲ�������ʾһֱ�ȴ���������
//��ѯ��ʽɨ�谴����timeout = KEY_WAIT_ALWAYSʱһֱɨ�裬����ȴ�ʱ��timeout����λms

#define KEY1_GPIO_Port GPIOA

#define KEY1_Pin GPIO_Pin_1 

KEYS ScanPressedKey(uint32_t timeout);
void KEY_Init(void);

#endif

