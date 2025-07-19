#ifndef _MOTOR_H
#define _MOTOR_H
#include "headfile.h"

void motorA_dir_speed(uint8_t dir, float speed);
void motorB_dir_speed(uint8_t dir, float speed);
void motorA_dir_duty(uint8_t dir, float duty);
void motorB_dir_duty(uint8_t dir, float duty);
void motor_set(float duty_A, float duty_B);
void motor_on(void);
void motor_off(void);
void motor_set_4(float speed_A, float speed_B);
#endif
