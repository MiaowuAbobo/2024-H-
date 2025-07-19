#ifndef _ISR_H_
#define _ISR_H_
#include "headfile.h"

extern uint32_t Left_Count;//两轮编码器
extern uint32_t Right_Count;
extern uint32_t Speed_Left_now;
extern uint32_t Speed_Right_now;
extern uint8_t duanlu_jishu_flag;

void ISR_Enable(void);//中断和定时器之类的初始化，比如使能之类的

void UART_0_INST_IRQHandler(void);//发送给电脑的串口
void TIM_EncoderA_INST_IRQHandler(void);//编码器，对Left_Count和Right_Count进行速度闭环处理
void IMU_RECEIVE_DATA_INST_IRQHandler(void);//处理IMU
void GROUP1_IRQHandler(void);//处理普通IO口的中断

#endif
