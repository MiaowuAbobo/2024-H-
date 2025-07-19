#include "headfile.h"

float motor_max_duty = 180;
/******************************************************************
设置AB电机的方向和速度
******************************************************************/
void motorA_dir_speed(uint8_t dir, float speed)//dir：1——正，0——反；
{
    gpio_set(motorin_AIN1_PORT, motorin_AIN1_PIN, dir);
    gpio_set(motorin_AIN2_PORT, motorin_AIN2_PIN, !dir);
    uint32_t CompareValue;
    //CompareValue = 32000 - 32000*speed/motor_max_duty;//32000是PWM Period Count的值  //不知道为什么这一行代码不行，很奇怪
    CompareValue = 32000 * (speed/motor_max_duty);//32000是初始PWM Period Count的值
    DL_Timer_setCaptureCompareValue(motorAB_INST, CompareValue, GPIO_motorAB_C0_IDX);
}
void motorB_dir_speed(uint8_t dir, float speed)//dir：1——正，0——反；
{
    gpio_set(motorin_BIN1_PORT, motorin_BIN1_PIN, dir);
    gpio_set(motorin_BIN2_PORT, motorin_BIN2_PIN, !dir);
    uint32_t CompareValue;
    CompareValue = 32000 * (speed/motor_max_duty);//32000是PWM Period Count的值
    DL_Timer_setCaptureCompareValue(motorAB_INST, CompareValue, GPIO_motorAB_C1_IDX);
}

/******************************************************************
设置AB电机的方向和占空比
******************************************************************/
void motorA_dir_duty(uint8_t dir, float duty)//dir：1——正，0——反；duty：0~100
{
    gpio_set(motorin_AIN1_PORT, motorin_AIN1_PIN, dir);
    gpio_set(motorin_AIN2_PORT, motorin_AIN2_PIN, !dir);
    duty = duty / 100.0;
    uint32_t CompareValue;
    CompareValue = 32000 - 32000*duty;//32000是PWM Period Count的值
    DL_Timer_setCaptureCompareValue(motorAB_INST, CompareValue, GPIO_motorAB_C0_IDX);
}
void motorB_dir_duty(uint8_t dir, float duty)//dir：1——正，0——反；duty：0~100
{
    gpio_set(motorin_BIN1_PORT, motorin_BIN1_PIN, dir);
    gpio_set(motorin_BIN2_PORT, motorin_BIN2_PIN, !dir);
    duty = duty / 100.0;
    uint32_t CompareValue;
    CompareValue = 32000 - 32000*duty;//32000是PWM Period Count的值
    DL_Timer_setCaptureCompareValue(motorAB_INST, CompareValue, GPIO_motorAB_C1_IDX);
}

/******************************************************************
好像没什么用，先放着....
******************************************************************/
void motor_set(float duty_A, float duty_B) //A电机速度,B电机速度
{
    if(duty_A < 0)        
        motorA_dir_speed(0, -duty_A);
    else if(duty_A > 0)
        motorA_dir_speed(1, duty_A);
    else
        DL_Timer_setCaptureCompareValue(motorAB_INST, 1, GPIO_motorAB_C0_IDX);//占空比为0，电机停止
    if(duty_B < 0)
        motorB_dir_speed(1, -duty_B);
    else if(duty_B > 0)
        motorB_dir_speed(0, duty_B);
    else
        DL_Timer_setCaptureCompareValue(motorAB_INST, 1, GPIO_motorAB_C1_IDX);//占空比为0，电机停止
}

void motor_on(void)
{
    DL_GPIO_setPins(motorin_STBY_PORT, motorin_STBY_PIN);
}

void motor_off(void)
{
    DL_GPIO_clearPins(motorin_STBY_PORT, motorin_STBY_PIN);
}

void motor_set_4(float speed_A, float speed_B) //A电机速度,B电机速度
{
    gpio_set(motorin_AIN1_PORT, motorin_AIN1_PIN, 1);
    gpio_set(motorin_AIN2_PORT, motorin_AIN2_PIN, 0);
    gpio_set(motorin_BIN1_PORT, motorin_BIN1_PIN, 0);
    gpio_set(motorin_BIN2_PORT, motorin_BIN2_PIN, 1);

    float SpeedA = 32000 * speed_A;
    float SpeedB = 32000 * speed_B;

    if(SpeedA <= 0) SpeedA = 0;
    if(SpeedB <= 0) SpeedB = 0;

    DL_Timer_setCaptureCompareValue(motorAB_INST, SpeedA, GPIO_motorAB_C0_IDX);
    DL_Timer_setCaptureCompareValue(motorAB_INST, SpeedB, GPIO_motorAB_C1_IDX);
}