#include "headfile.h"

uint8_t str_test[100];
uint8_t TASK = 0;//1!!!!!!!!!!!!!!!!!!!!1111
uint8_t workstep = 0;
uint8_t First_flag = 0;
uint8_t pid_mode = 0;
float basespeed = 0;
float angle_record = 0;
float angle_record_1 = 0, angle_record_2 = 0;
uint8_t task4_jishu = 0;
float angle_record_3 = 0;
uint8_t MODE_flag = 0;

uint32_t Left_Count_high_1 = 1250;
uint32_t Left_Count_high_2 = 1270;
uint32_t KP_trace = 30;
uint32_t KP_angle = 18;
int main(void)
{
    SYSCFG_DL_init();
    atk_ms901m_uart_init();
    ISR_Enable();

    //pid_init(&motorA, DELTA_PID, 0.005, 18.9, 0.001);//增量式速度闭环PID
    //pid_init(&motorB, DELTA_PID, 0.005, 18.9, 0.001);//增量式速度闭环PID
    
    motor_on();

    //motor_target_set(30, 30);
    while(1)
    {   
        if(First_flag == 0 && angle.target == 0.0)
        {
            delay_ms(1500);
            LED_GREEN_ON
            atk_ms901m_get_attitude(&attitude_dat, 5);
            atk_ms901m_get_attitude(&attitude_dat, 5);
            float ang1 = attitude_dat.yaw;
            delay_ms(200);
            atk_ms901m_get_attitude(&attitude_dat, 5);
            atk_ms901m_get_attitude(&attitude_dat, 5);
            float ang2 = attitude_dat.yaw;
            delay_ms(200);
            atk_ms901m_get_attitude(&attitude_dat, 5);
            atk_ms901m_get_attitude(&attitude_dat, 5);
            float ang3 = attitude_dat.yaw;
            angle.target = (ang1 + ang2 + ang3)/3.0;
            First_flag = 1;
            LED_GREEN_OFF
            /* pid_init(&angle, POSITION_PID, 0.855, 0, 0.1);///////
            basespeed = 50;////// */
        }
        /* if(First_flag == 1)
        {
            pid_init(&angle, POSITION_PID, 10, 0, 0.001);
            basespeed = 0.2;
            angle.now = attitude_dat.yaw;
            pid_cal(&angle);
            motor_set_4(basespeed - angle.out * 0.001825, basespeed + angle.out * 0.001825);
            delay_ms(10);
        } */
        //printf("%f\n", attitude_dat.yaw);

        //test
        //Trace();
        /* switch(workstep)
        {
            case 0:
                Line_flag = 0;
                while(Line_flag == 0)   duanlu();
                motor_off();
                workstep ++;
                break;
        } */

        
        //mission
        if(MODE_flag == 0)
        {
            if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY5_PIN))
            {
                MODE_flag = 1;
                LED_RED_ON
                delay_ms(200);
                LED_RED_OFF
            }                
        }
        else if(MODE_flag == 1)
        {
            if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY5_PIN))
            {
                MODE_flag = 2;
                LED_BLUE_ON
                delay_ms(200);
                LED_BLUE_OFF
            }          
        }
        else if(MODE_flag == 2)
        {
            if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY5_PIN))
            {
                MODE_flag = 3;
                LED_GREEN_ON
                LED_RED_ON
                delay_ms(200);
                LED_GREEN_OFF
                LED_RED_OFF
            }          
        }
        else if(MODE_flag == 3)
        {
            if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY5_PIN))
            {
                MODE_flag = 0;
                LED_GREEN_ON
                delay_ms(200);
                LED_GREEN_OFF
            }          
        }
        if(TASK == 0) //等待指令
        {
            if(MODE_flag == 0)
            {
                if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY1_PIN))
                {
                    TASK = 1;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY2_PIN))
                {
                    TASK = 2;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY3_PIN))
                {
                    TASK = 3;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY4_PIN))
                {
                    TASK = 4;
                    delay_ms(1000);
                }
            }
            else if(MODE_flag == 1)
            {
                if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY1_PIN))
                {
                    TASK = 5;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY2_PIN))
                {
                    TASK = 6;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY3_PIN))
                {
                    TASK = 7;
                    delay_ms(1000);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY4_PIN))
                {
                    TASK = 8;
                    delay_ms(1000);
                }
            }
            else if(MODE_flag == 2)
            {
                if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY1_PIN))
                {
                    Left_Count_high_1 += 10;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY2_PIN))
                {
                    Left_Count_high_1 -= 10;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY3_PIN))
                {
                    Left_Count_high_2 += 10;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY4_PIN))
                {
                    Left_Count_high_2 -= 10;
                    delay_ms(300);
                }
            }
            else if(MODE_flag == 3)
            {
                if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY1_PIN))
                {
                    KP_angle += 1;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY2_PIN))
                {
                    KP_angle -= 1;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY3_PIN))
                {
                    KP_trace += 1;
                    delay_ms(300);
                }
                else if(!DL_GPIO_readPins(KEYS_PORT, KEYS_KEY4_PIN))
                {
                    KP_trace -= 1;
                    delay_ms(300);
                }
            }
        }
















        else if(TASK == 1)
        {
            //角度
            switch(workstep)
            {
                case 0://初始化
                    basespeed = 0.3;
                    pid_init(&angle, POSITION_PID, 25, 0, 0);
                    Line_flag = 0;
                    while(Line_flag == 0)   duanlu();
                    workstep++;
                break;

                case 1://第一个断路
                    if(Line_flag == 1)
                    {
                        motor_set_4(0, 0);
                        motor_off();
                    }
                    shengguang();
                    workstep ++;
                break;
            }
        }




         else if(TASK == 2)
        {
            switch(workstep)
            {
                case 0://初始化
                    basespeed = 0.3;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                    trace_pid.target = 0;
                    angle_record = angle.target-180;
                    workstep++;
                break;

                case 1://第一个断路
                    Line_flag = 0;
                    while(Line_flag == 0)   duanlu();
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    workstep ++;
                break;

                case 3://第二个断路
                    shengguang();
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                    trace_pid.target = 0;
                    angle.target = angle_record;
                    Line_flag = 0;
                    while(Line_flag == 0)   duanlu();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    shengguang();
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    workstep ++;
                break;

                case 5:
                    shengguang();
                    Self_stop
                    motor_off();
                    workstep++;
                break;
            }
        }



















        else if(TASK == 3)//任务3------方案1
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.35;
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01); //0.35适用
                    //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
                    //pid_init(&angle, POSITION_PID, 15, 0, 0.01); //0.35适用
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    trace_pid.target = 0;
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
/*                     pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 60;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_1 || Right_Count >= Left_Count_high_1)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    basespeed = 0.35;
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    /* pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */
                    basespeed = 0.35;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 120;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);



                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    if(task4_jishu != 3)
                    {
                        basespeed = 0.35;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    else
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID,KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    
                break;

                case 5:
                    Self_stop
                    motor_off();
                    workstep++;
                break;
            }
        }




















        else if(TASK == 5)//任务4第一个方案
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.25;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle.target - 140;
                        angle.target = angle.target - 40;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 140;
                        angle.target = angle_record_3 - 42;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
                    /* qibu
                    delay_ms(50); */
                    Line_flag = 0;
                    while(Line_flag == 0)   duanlu();
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_task_3();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record;
                    Line_flag = 0;
                    while(Line_flag == 0)   duanlu();
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_task_3();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 5:
                    if(task4_jishu == 3)
                    {
                        motor_off();
                        workstep++;
                    }
                    else
                    {
                        workstep = 0;
                        task4_jishu ++;
                    }
                break;
            }
        }















        else if(TASK == 6)//任务四第二个方案，慢
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.3;
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01); //0.35适用
                    //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
                    //pid_init(&angle, POSITION_PID, 15, 0, 0.01); //0.35适用
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    trace_pid.target = 0;
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
/*                     pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 60;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_1 || Right_Count >= Left_Count_high_1)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    basespeed = 0.3;
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    /* pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */
                    basespeed = 0.3;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 120;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);



                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    if(task4_jishu != 3)
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    else
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    
                break;

                case 5:
                    if(task4_jishu == 3)
                    {
                        Self_stop
                        motor_off();
                        workstep++;
                    }
                    else
                    {
                        workstep = 0;
                        task4_jishu ++;
                    }
                break;
            }
        }









        else if(TASK == 7)//任务4第三个方案
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.35;
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01); //0.35适用
                    //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
                    //pid_init(&angle, POSITION_PID, 15, 0, 0.01); //0.35适用
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    trace_pid.target = 0;
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
/*                     pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 60;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_1 || Right_Count >= Left_Count_high_1)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    basespeed = 0.35;
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    /* pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */
                    basespeed = 0.35;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);


                    angle.target = angle_record_3 - 120;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);



                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    if(task4_jishu != 3)
                    {
                        basespeed = 0.35;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    else
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    
                break;

                case 5:
                    if(task4_jishu == 3)
                    {
                        Self_stop
                        motor_off();
                        workstep++;
                    }
                    else
                    {
                        workstep = 0;
                        task4_jishu ++;
                    }
                break;
            }
        }

        








        else if(TASK == 8)//任务四第四个方案，快
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.4;
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01); //0.35适用
                    //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
                    //pid_init(&angle, POSITION_PID, 15, 0, 0.01); //0.35适用
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    trace_pid.target = 0;
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
/*                     pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0.);
                    angle.target = angle_record_3 - 60;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_1 || Right_Count >= Left_Count_high_1)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    basespeed = 0.45;
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    /* pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */
                    basespeed = 0.4;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3 - 120;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= Left_Count_high_2 || Right_Count >= Left_Count_high_2)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    if(task4_jishu != 3)
                    {
                        basespeed = 0.45;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    else
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    
                break;

                case 5:
                    if(task4_jishu == 3)
                    {
                        Self_stop
                        motor_off();
                        workstep++;
                    }
                    else
                    {
                        workstep = 0;
                        task4_jishu ++;
                    }
                break;
            }
        }
























        else if(TASK == 19)
        {
            switch(workstep)
            {
                case 0://初始化
                    //basespeed = 0.25;
                    basespeed = 0.45;
                    pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01); //0.35适用
                    //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
                    //pid_init(&angle, POSITION_PID, 15, 0, 0.01); //0.35适用
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    trace_pid.target = 0;
                    if(task4_jishu == 0)
                    {
                        angle_record_3 = angle.target;
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                    }
                    else
                    {
                        angle_record = angle_record_3 - 120;
                        angle.target = angle_record_3 - 60;
                        //angle.target = angle_record_3 - 43;
                    }
                    workstep++;
                break;

                case 1://第一个断路
/*                     pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3 - 60;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= 1280 || Right_Count >= 1280)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= 1300 || Right_Count >= 1300)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;
                
                case 2://第一个圆弧
                    basespeed = 0.45;
                    Line_flag_task2 = 1;
                    while(Line_flag_task2 == 1)   Trace_pid_test();
                    shengguang();
                    Self_stop//第一个圆弧出去停一下
                    workstep ++;
                break;

                case 3://第二个断路
                    /* pid_init(&angle, POSITION_PID, 15, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                        delay_ms(1000);
                        break;
                    } */
                    basespeed = 0.45;
                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3 - 120;
                    Line_flag = 0;
                    while(Line_flag == 0)
                    {
                        duanlu();
                        if(fabs(angle.target - angle.now) <= 5)
                        {
                            duanlu_jishu_flag = 1;
                        }
                        if(task4_jishu == 0)
                        {
                            if(Left_Count >= 1280 || Right_Count >= 1280)
                            {
                                break;
                            }
                        }
                        else if(task4_jishu > 0)
                        {
                            if(Left_Count >= 1300 || Right_Count >= 1300)
                            {
                                break;
                            }
                        }
                    }

                    pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
                    angle.target = angle_record_3 - 180;
                    while(Line_flag == 0)
                    {
                        duanlu_jishu_flag = 0;
                        duanlu();
                    }
                    shengguang();
                    workstep ++;
                break;

                case 4://第二个圆弧
                    if(task4_jishu != 3)
                    {
                        basespeed = 0.45;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    else
                    {
                        basespeed = 0.3;
                        pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0.01);
                        trace_pid.target = 0;
                        Line_flag_task2 = 1;
                        while(Line_flag_task2 == 1)   Trace_pid_test();
                        shengguang();
                        Self_stop//第一个圆弧出去停一下
                        workstep ++;
                    }
                    
                break;

                case 5:
                    if(task4_jishu == 3)
                    {
                        Self_stop
                        motor_off();
                        workstep++;
                    }
                    else
                    {
                        workstep = 0;
                        task4_jishu ++;
                    }
                break;
            }
        }





















       






        else if(TASK == 11)//循迹测试
        {
            basespeed = 0.35;
            pid_init(&trace_pid, POSITION_PID, KP_trace, 0, 0); //0.35适用
            //pid_init(&trace_pid, POSITION_PID, 60, 0, 0);
            pid_init(&angle, POSITION_PID, KP_angle, 0, 0);
            trace_pid.target = 0;
            while(1) Trace_pid_test();
        }
        else if(TASK == 12)//角度测试
        {
            duanlu_jishu_flag = 1;
        }
        else if(TASK == 10)//角度测试
        {
            basespeed = 0.25;
            pid_init(&angle, POSITION_PID, KP_angle, 0, 0.0001);
            angle.target = 180;
            //断路测试
            //Line_flag = 0;
            while(1)   duanlu();
            //循迹测试
            /* Line_flag = 1;
            while(Line_flag == 1)   Trace(); */
        }
    }

}
