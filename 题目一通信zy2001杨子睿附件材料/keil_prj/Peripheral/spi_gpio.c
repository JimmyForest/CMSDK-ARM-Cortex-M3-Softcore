#include "spi_gpio.h"

void SPI_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;			//定义结构体类型的变量

    GPIO_InitStructure.GPIO_Pin  = CS_Pin | CLK_Pin | MOSI_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  //推挽输出
    GPIO_Config(SPI_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin  = MISO_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  //硬核是上拉输入，不浮空输入会有问题吗????
    GPIO_Config(SPI_Port, &GPIO_InitStructure);

    GPIO_SetBits(SPI_Port, CS_Pin);  //CS拉高
    GPIO_ResetBits(SPI_Port, CLK_Pin);  //CLK拉低
    //GPIO_ResetBits(SPI_Port, MISO_Pin);
}

/**
  * @brief :SPI收主机spi同时读写一个字节的时序 MSB
  * @param :
  *			@wdat: 写入的数据
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:spi读一个字节
  */

uint8_t Master_SPI_WR_Byte(uint8_t wdat)
{
    uint8_t i = 0, rdat = 0;
    SPI_CS_LOW;

    for(i = 0; i < 8; i++)
    {
        if(wdat & 0x80)
            SPI_MOSI_HIGH;
        else
            SPI_MOSI_LOW;

        wdat <<= 1;
        delay_us(3);

        SPI_CLK_HIGH;

        delay_us(2);
        rdat <<= 1;

        if(SPI_MISO_READ)
            rdat |= 0x01;

        delay_us(1);

        SPI_CLK_LOW;
    }

    SPI_CS_HIGH;
    return rdat;
}

/**
  * @brief :SPI收发字符串
  * @param :
  *			@ReadBuffer: 接收数据缓冲区地址
  *			@WriteBuffer:发送字节缓冲区地址
  *			@Length:字节长度
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:无
  */

void Master_SPI_WR_String( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length )
{
    SPI_CS_LOW;  //片选拉低

    while( Length-- )
    {
        *ReadBuffer = Master_SPI_WR_Byte( *WriteBuffer );  //收发数据
        ReadBuffer++;
        WriteBuffer++;  //读写地址加1
    }

    SPI_CS_HIGH;  //片选拉高
}

