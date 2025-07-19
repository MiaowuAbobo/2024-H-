#ifndef _PID_H_
#define _PID_H_
#include "headfile.h"

enum
{
  POSITION_PID = 0,  // 位置式
  DELTA_PID,         // 增量式
};

typedef struct
{
	float target;	
	float now;
	float error[3];		
	float p,i,d;
	float pout, dout, iout;
	float out;   
	uint32_t pid_mode;
}pid_t;

void pid_cal(pid_t *pid);
void pid_control(void);
void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d);
void motor_target_set(float spe1, float spe2);
void pidout_limit(pid_t *pid);
void datavision_send();
int Position_PID (int Encoder,int Target);
float Yaw_error_zzk(float Target, float Now);
float fabs_zzk(float value);
void pid_cal_trace(pid_t *pid);

extern pid_t motorA;
extern pid_t motorB;
extern pid_t angle;
extern pid_t trace_pid;
extern atk_ms901m_attitude_data_t attitude_dat;

#endif
