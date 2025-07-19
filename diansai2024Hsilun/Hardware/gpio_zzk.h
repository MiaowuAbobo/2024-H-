#ifndef _GPIO_ZZK_H_
#define _GPIO_ZZK_H_
#include "headfile.h"

void gpio_set(GPIO_Regs* gpio, uint32_t pins, uint8_t t);
void uart_send(UART_Regs* uart, unsigned char *Tx_buf, int len);//向某个串口传送数据

#endif
