#include "headfile.h"

void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t t)
{
    if(t==1)
        DL_GPIO_setPins(gpio, pins);
    else if(t==0)
        DL_GPIO_clearPins(gpio, pins);
}

void uart_send(UART_Regs* uart, unsigned char *Tx_buf, int len)//向某个串口传送数据
{
    while(len--)
    {
        DL_UART_transmitDataBlocking(uart, *Tx_buf);
        Tx_buf ++;
    }
}