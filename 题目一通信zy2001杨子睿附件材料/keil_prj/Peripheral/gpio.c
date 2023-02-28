#include "gpio.h"

void GPIO_Config(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint8_t mode = GPIO_InitStruct->GPIO_Mode;
    uint32_t pin = (uint32_t)GPIO_InitStruct->GPIO_Pin;

    switch(mode)
    {
        case GPIO_Mode_IN:
            GPIOx->OUTENCLR = pin;  //不能直接|=，因为寄存器读出来的与写进去的逻辑是反的
            break;

        case GPIO_Mode_OUT:
            GPIOx->OUTENSET |= pin;
            break;

        case GPIO_Mode_AF:
            GPIOx->ALTFUNCSET |= pin;
            break;
    }
}

void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->DATAOUT |= (uint32_t)GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->DATAOUT &= ~((uint32_t)GPIO_Pin);
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */

BitAction GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BitAction bitstatus = (BitAction)0;

    if ((GPIOx->DATA & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = Bit_SET;
    }
    else
    {
        bitstatus = Bit_RESET;
    }

    return bitstatus;
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */

uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{

    return ((uint16_t)GPIOx->DATA);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The output port pin value.
  */

BitAction GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BitAction bitstatus = (BitAction)0;

    if ((GPIOx->DATAOUT & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = Bit_SET;
    }
    else
    {
        bitstatus = Bit_RESET;
    }

    return bitstatus;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO output data port value.
  */

uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{

    return ((uint16_t)GPIOx->DATAOUT);
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */

void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{

    if (BitVal != Bit_RESET)
    {
        GPIOx->DATAOUT |= (uint32_t)GPIO_Pin;
    }
    else
    {
        GPIOx->DATAOUT &= ~((uint32_t)GPIO_Pin);
    }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */

void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
    GPIOx->DATAOUT = PortVal;
}

void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	//推挽输出
    GPIO_Config(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_Config(GPIOA, &GPIO_InitStructure);

    GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

