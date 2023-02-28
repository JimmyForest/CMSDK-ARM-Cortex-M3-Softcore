#ifndef SPI_GPIO_H
#define SPI_GPIO_H

#include "gpio.h"  //GPIO驱动的头文件
#include "system.h"

#define SELECT 0  //0表示主机  其它表示从机

#if SELECT == 0

    //主机
	
    #define CS_Pin GPIO_Pin_4
    #define CLK_Pin GPIO_Pin_5
    #define MISO_Pin GPIO_Pin_6
    #define MOSI_Pin GPIO_Pin_7

    #define SPI_Port GPIOA

    //CS引脚 PA_4
    #define      SPI_CS_HIGH        GPIO_SetBits(SPI_Port, CS_Pin)
    #define      SPI_CS_LOW         GPIO_ResetBits(SPI_Port, CS_Pin)

    //CLK引脚 PA_5
    #define      SPI_CLK_HIGH       GPIO_SetBits(SPI_Port, CLK_Pin)
    #define      SPI_CLK_LOW        GPIO_ResetBits(SPI_Port, CLK_Pin)

    //MISO引脚 PA_6
    #define      SPI_MISO_READ      GPIO_ReadInputDataBit(SPI_Port, MISO_Pin)

    //MOSI引脚 PA_7
    #define      SPI_MOSI_HIGH      GPIO_SetBits(SPI_Port, MOSI_Pin)
    #define      SPI_MOSI_LOW       GPIO_ResetBits(SPI_Port, MOSI_Pin)

    void SPI_Init(void);
    uint8_t Master_SPI_WR_Byte(uint8_t wdat);
    void Master_SPI_WR_String( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length );

#else
    //从机
	
    //CS引脚
    #define      SPI_CS_READ        PCin(8)

    //CLK引脚
    #define      SPI_CLK_READ       PCin(10)

    //MISO引脚
    #define      SPI_MISO_HIGH      PCout(11) = 1
    #define      SPI_MISO_LOW       PCout(11) = 0

    //MOSI引脚
    #define      SPI_MOSI_READ      PCin(12)
	
    void SPI_Init(void);
    u8 Slave_SPI_RWByte(u8 wdat);

#endif

#endif
