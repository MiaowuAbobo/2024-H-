#include "headfile.h"

uint16_t turn = 0;
uint16_t baisei_time = 0;
uint16_t heisei_time = 0;
uint8_t Line_flag_task2 = 0;
uint16_t baisei_time_task2 = 0;
uint16_t baisetime_high = 10;

void Trace(void)
{
    Get_Light_TTL();
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)//急停
    {
        heisei_time ++;
        if(baisei_time >= 20)
        {
            baisei_time = 0;
            Line_flag = 1;
        }
    }
    else if(L4==1&&L3==1&&L2==1&&L1==1&&R1==1&&R2==1&&R3==1&&R4==1)//全白直走
    {
        baisei_time++;
        if(baisei_time >= 45)
        {
            baisei_time = 0;
            Line_flag = 0;
        }
        baisei_time_task2++;
        if(baisei_time_task2 >= 100)
        {
            baisei_time_task2 = 0;
            Line_flag_task2 = 0;
        }
        //motor_set_4(basespeed, basespeed);
    }
    else
    {
        if(L1==0&&R1==0)
        {
            motor_set_4(basespeed, basespeed);
        }
        
        else if(L4==0&&L3==0)// 0011 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.23);
        }
        else if(R3==0&&R4==0)// 1111 1100
        {
            motor_set_4(basespeed + 0.23, basespeed - 0.17);
        }

        else if(L4==0&&L3==1)//0111 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.28);
        }
        else if(R4==0&&R3==1)//1111 1110
        {
            motor_set_4(basespeed + 0.28, basespeed - 0.17);
        }

        else if(L1==0&&R1==1)// 1110 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.08);
        }
        else if(L1==1&&R1==0)// 1111 0111
        {
            motor_set_4(basespeed + 0.08, basespeed - 0.17);
        }

        else if(L2==0&&L1==0)// 1100 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.18);
        }
        else if(R1==0&&R2==0)// 1111 0011
        {
            motor_set_4(basespeed + 0.18, basespeed - 0.17);
        }

        else if(L3==0&&L2==0)// 1001 1111
        {
            motor_set_4(basespeed - 0.17, basespeed + 0.23);
        }
        else if(R2==0&&R3==0)// 1111 1001
        {
            motor_set_4(basespeed + 0.23, basespeed - 0.17);
        }
    }
    delay_ms(10);
}

void Trace_2(void)
{
    Get_Light_TTL();
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)//急停
    {
        motor_set(0, 0);
        delay_ms(1000);
    }
    else if(L4==1&&L3==1&&L2==1&&L1==1&&R1==1&&R2==1&&R3==1&&R4==1)//全白直走
    {
        motor_set(basespeed, basespeed);
    }
    else
    {
        if(L1==0&&R1==0)
        {
            motor_set(basespeed, basespeed);
        }
        
        else if(L4==0&&L3==0)// 0011 1111
        {
            motor_set(basespeed, basespeed + 25);
        }
        else if(R3==0&&R4==0)// 1111 1100
        {
            motor_set(basespeed + 25, basespeed);
        }

        else if(L4==0&&L3==1)//0111 1111
        {
            motor_set(basespeed, basespeed + 30);
        }
        else if(R4==0&&R3==1)//1111 1110
        {
            motor_set(basespeed + 30, basespeed);
        }

        else if(L1==0&&R1==1)// 1110 1111
        {
            motor_set(basespeed, basespeed + 5);
        }
        else if(L1==1&&R1==0)// 1111 0111
        {
            motor_set(basespeed + 5, basespeed);
        }

        else if(L2==0&&L1==0)// 1100 1111
        {
            motor_set(basespeed, basespeed + 15);
        }
        else if(R1==0&&R2==0)// 1111 0011
        {
            motor_set(basespeed + 15, basespeed);
        }

        else if(L3==0&&L2==0)// 1001 1111
        {
            motor_set(basespeed, basespeed + 25);
        }
        else if(R2==0&&R3==0)// 1111 1001
        {
            motor_set(basespeed + 25, basespeed);
        }
    }
    delay_ms(10);
}

void Trace_task_3(void) //速度0.25
{
    
    Get_Light_TTL();
    if(L4==0&&L3==0&&L2==0&&L1==0&&R1==0&&R2==0&&R3==0&&R4==0)//急停
    {
        heisei_time ++;
        if(baisei_time >= 20)
        {
            baisei_time = 0;
            Line_flag = 1;
        }
    }
    else if(L4==1&&L3==1&&L2==1&&L1==1&&R1==1&&R2==1&&R3==1&&R4==1)//全白直走
    {
        baisei_time++;
        if(baisei_time >= 45)
        {
            baisei_time = 0;
            Line_flag = 0;
        }
        baisei_time_task2++;
        if(baisei_time_task2 >= 10)
        {
            baisei_time_task2 = 0;
            Line_flag_task2 = 0;
        }
        //motor_set_4(basespeed, basespeed);
    }
    else
    {
        if(L1==0&&R1==0)
        {
            motor_set_4(basespeed, basespeed);
        }
        
        else if(L4==0&&L3==0)// 0011 1111
        {
            motor_set_4(basespeed - 0.18, basespeed + 0.36);
        }
        else if(R3==0&&R4==0)// 1111 1100
        {
            motor_set_4(basespeed + 0.36, basespeed - 0.18);
        }

        else if(L4==0&&L3==1)//0111 1111
        {
            motor_set_4(basespeed - 0.27, basespeed + 0.55);
        }
        else if(R4==0&&R3==1)//1111 1110
        {
            motor_set_4(basespeed + 0.55, basespeed - 0.27);
        }

        else if(L1==0&&R1==1)// 1110 1111
        {
            motor_set_4(basespeed - 0.15, basespeed + 0.08);
        }
        else if(L1==1&&R1==0)// 1111 0111
        {
            motor_set_4(basespeed + 0.08, basespeed - 0.15);
        }

        else if(L2==0&&L1==0)// 1100 1111
        {
            motor_set_4(basespeed - 0.15, basespeed + 0.18);
        }
        else if(R1==0&&R2==0)// 1111 0011
        {
            motor_set_4(basespeed + 0.18, basespeed - 0.15);
        }

        else if(L3==0&&L2==0)// 1001 1111
        {
            motor_set_4(basespeed - 0.20, basespeed + 0.26);
        }
        else if(R2==0&&R3==0)// 1111 1001
        {
            motor_set_4(basespeed + 0.26, basespeed - 0.20);
        }
    }
    delay_ms(10);
}

void shengguang(void)
{
    if(shengguang_flag == 0)
    {
        BUZZER_ON
        LED_BLUE_ON
        LED_zzk_ON
        shengguang_flag = 1;
    }
}


void duanlu(void)
{
    //获取当前角度
    //atk_ms901m_get_attitude(&attitude_dat, 5);
    atk_ms901m_get_attitude(&attitude_dat, 5);
    angle.now = attitude_dat.yaw;
    float offset = angle.now - angle.target;
    //计算当前角度
    pid_cal(&angle);

    //方案1
    if(offset <= 0 ) offset = -offset;
    if(offset < 1.0)
    {
        motor_set_4(basespeed, basespeed);
    }
    else
    {
        float SpeedL = basespeed - angle.out * 0.001825;
        float SpeedR = basespeed + angle.out * 0.001825;
        if(SpeedL <= 0)         SpeedL = 0;
        else if(SpeedL >= 1)  SpeedL = 1;
        if(SpeedR <= 0)         SpeedR = 0;
        else if(SpeedR >= 1)  SpeedR = 1;
        motor_set_4(SpeedL, SpeedR);
    Get_Light_TTL();
    delay_ms(10);
    }
}

void Trace_pid_test(void)
{
    Get_Light_TTL_trace();

    float bianhua = (-12.0)*L4 + (-7.0)*L3 + (-4.0)*L2 + (-1.0)*L1 + (1.0)*R1 + (4.0)*R2 + (7.0)*R3 + (12.0)*R4;  //0.3适用
    trace_pid.now = bianhua;
    trace_pid.target = 0;
    pid_cal_trace(&trace_pid);

    float SpeedL = basespeed - trace_pid.out * 0.0021825;
    float SpeedR = basespeed + trace_pid.out * 0.0021825;
    if(SpeedL <= 0)         SpeedL = 0;
    else if(SpeedL >= 1)  SpeedL = 1;
    if(SpeedR <= 0)         SpeedR = 0;
    else if(SpeedR >= 1)  SpeedR = 1;

    if(L4==0 && L3==0 && L2==0 && L1==0 && R1==0 && R2==0 && R3==0 && R4==0)//全是白色
    {
        baisei_time ++;
        if(baisei_time >= 5)
        {
            baisei_time = 0;
            Line_flag = 0;
        }
        baisei_time_task2 ++;
        if(baisei_time_task2 >= 8)
        {
            baisei_time_task2 = 0;
            Line_flag_task2 = 0;
        }
    }
    else if(L4==1 || L3==1 || L2==1 || L1==1 || R1==1 || R2==1 || R3==1 || R4==1)
    {
        heisei_time ++;
        if(heisei_time >= 15)
        {
            Line_flag = 1;
            heisei_time = 0;
        }
    }
    
    motor_set_4(SpeedL, SpeedR);
    delay_ms(10);
}