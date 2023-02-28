#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdio.h>
#include "core_cm3.h"

#pragma anon_unions

/*-------------------- GPIO Pins Definitions --------------------*/

#define GPIO_Pin_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

/*-------------------- GPIO Structs Definitions --------------------*/

typedef struct
{
    __IO   uint32_t  DATA;                     /* Offset: 0x000 (R/W) DATA Register */
    __IO   uint32_t  DATAOUT;                  /* Offset: 0x004 (R/W) Data Output Latch Register */
    uint32_t  RESERVED0[2];
    __IO   uint32_t  OUTENSET;             	   /* Offset: 0x010 (R/W) Output Enable Set Register */
    __IO   uint32_t  OUTENCLR;            	   /* Offset: 0x014 (R/W) Output Enable Clear Register */
    __IO   uint32_t  ALTFUNCSET;               /* Offset: 0x018 (R/W) Alternate Function Set Register */
    __IO   uint32_t  ALTFUNCCLR;               /* Offset: 0x01C (R/W) Alternate Function Clear Register */
    __IO   uint32_t  INTENSET;                 /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
    __IO   uint32_t  INTENCLR;                 /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
    __IO   uint32_t  INTTYPESET;               /* Offset: 0x028 (R/W) Interrupt Type Set Register */
    __IO   uint32_t  INTTYPECLR;               /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
    __IO   uint32_t  INTPOLSET;                /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
    __IO   uint32_t  INTPOLCLR;                /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
    union
    {
        __I    uint32_t  INTSTATUS;            /* Offset: 0x038 (R/ ) Interrupt Status Register */
        __O    uint32_t  INTCLEAR;             /* Offset: 0x038 ( /W) Interrupt Clear Register */
    };
    uint32_t RESERVED1[241];
    __IO   uint32_t LB_MASKED[256];            /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
    __IO   uint32_t UB_MASKED[256];            /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
} GPIO_TypeDef;

typedef enum
{
    GPIO_Mode_IN = 0x01,
    GPIO_Mode_OUT = 0x02,
    GPIO_Mode_AF = 0x04
} GPIOMode_TypeDef;

typedef enum
{
    Bit_RESET = 0,
    Bit_SET
} BitAction;


typedef struct
{
    uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.This parameter can be any value of @ref GPIO_pins_define */

    GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
} GPIO_InitTypeDef;

/*-------------------- GPIO Function Declaratins --------------------*/

extern void GPIO_Config( GPIO_TypeDef *GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
extern BitAction GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
extern uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
extern BitAction GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
extern uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
extern void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
extern void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
extern void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
extern void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
extern void GPIO_Init(void);

#endif
