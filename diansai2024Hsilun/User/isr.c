#include "headfile.h"

uint32_t Left_Count = 0;//两轮编码器
uint32_t Right_Count = 0;
uint32_t Speed_Left_now = 0;
uint32_t Speed_Right_now = 0;
uint8_t shengguang_flag = 0;
uint8_t shengguang_time = 0;
uint8_t duanlu_jishu_flag = 0;
void ISR_Enable(void)
{
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);//电脑调试串口启动！
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);

    NVIC_EnableIRQ(encoder_INT_IRQN);//GPIO中断启动！
    
    NVIC_EnableIRQ(TIM_EncoderA_INST_INT_IRQN);//测速器启动！！
    DL_Timer_startCounter(TIM_EncoderA_INST);

    DL_Timer_startCounter(motorAB_INST);//电机PWM启动！

    NVIC_EnableIRQ(IMU_RECEIVE_DATA_INST_INT_IRQN);
    DL_Timer_startCounter(IMU_RECEIVE_DATA_INST);
}

void UART_0_INST_IRQHandler(void) //电脑串口
{
    
}

void TIM_EncoderA_INST_IRQHandler(void)//编码器，对Left_Count和Right_Count进行速度闭环处理
{
    switch(DL_Timer_getPendingInterrupt(TIM_EncoderA_INST))//
    {
        case DL_TIMER_IIDX_ZERO:
        {
            Speed_Left_now = Left_Count;
            Speed_Right_now = Right_Count;
            //PID
        }
        default:
            break;
    }
}
void IMU_RECEIVE_DATA_INST_IRQHandler(void)//中断函数处理部分
{
    switch(DL_TimerG_getPendingInterrupt(IMU_RECEIVE_DATA_INST))
    {
        case DL_TIMER_IIDX_ZERO:
        {
            //atk_ms901m_get_attitude(&attitude_dat, 5);
            if(shengguang_flag == 1)
            {
                shengguang_time ++;
                if(shengguang_time >= 10)
                {
                    BUZZER_OFF
                    LED_BLUE_OFF
                    LED_zzk_OFF
                    shengguang_flag = 0;
                    shengguang_time = 0;
                }
            }
        }
        default:
            break;
    }
}
void GROUP1_IRQHandler(void)
{
    //和GPIOA相关的中断写在这里
    //uint32_t gpioA = DL_GPIO_getEnabledInterruptStatus(GPIOA, );
    //和GPIOB相关的中断写在这里
    //uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, encoder_BE1_PIN | encoder_AE1_PIN);
    uint32_t gpioB = DL_GPIO_getEnabledInterruptStatus(GPIOB, encoder_AE1_PIN);
    //编码器A
    if(duanlu_jishu_flag == 1)
    {
        if (gpioB & encoder_AE1_PIN) //如果中断是AE1
        {
            if(!DL_GPIO_readPins(encoder_PORT, encoder_AE2_PIN)) 
                Left_Count--;
            else //AE2为低电平
                Left_Count++;
            DL_GPIO_clearInterruptStatus(encoder_PORT, encoder_AE2_PIN);//清除标志位
        }
        
        //编码器B
        /* if (gpioB & encoder_BE1_PIN) //如果中断是BE1
        {
            if(!DL_GPIO_readPins(encoder_PORT, encoder_BE2_PIN)) 
                Right_Count++;
            else //BE2为低电平
                Right_Count--;
            DL_GPIO_clearInterruptStatus(encoder_PORT, encoder_BE2_PIN);//清除标志位
        } */
    }
    else
    {
        Left_Count = 0;
        Right_Count = 0;
    }
}
