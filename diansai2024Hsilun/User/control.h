#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "headfile.h"

#define Self_stop  motor_set_4(0, 0);
#define qibu    motor_set(basespeed+22, basespeed);
#define Kp  1.5

extern uint8_t shengguang_flag;
extern uint8_t shengguang_time;
extern uint8_t Line_flag_task2;
extern uint16_t baisetime_high;

extern uint8_t TASK; 
extern uint8_t First_flag;
extern uint8_t pid_mode;//0是无，1是速度闭环，2是角度闭环
extern uint16_t turn;
extern float basespeed;

void Trace(void);
void shengguang(void);
void duanlu(void);
void Trace_task_3(void);

void Trace_pid_test(void);
#endif
