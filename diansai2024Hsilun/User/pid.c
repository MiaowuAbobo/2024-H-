#include "headfile.h"
#define motor_max_duty 180

pid_t motorA;
pid_t motorB;
pid_t angle;
pid_t trace_pid;
uint8_t motorA_dir = 1,motorB_dir = 1;
atk_ms901m_attitude_data_t attitude_dat;
//atk_ms901m_attitude_data_t attitude_dat;
void motor_target_set(float spe1, float spe2)
{
	if(spe1 >= 0)
	{
		motorA_dir = 1;
		motorA.target = spe1;
	}
	else
	{
		motorA_dir = 0;
		motorA.target = -spe1;
	}
	if(spe2 >= 0)
	{
		motorB_dir = 0;
		motorB.target = spe2;
	}
	else
	{
		motorB_dir = 1;
		motorB.target = -spe2;
	}
}

void pid_control() //放在定时器中断里面，对电机进行控制,
{
    if(pid_mode == 1)
    {
        //if(motorA_dir){motorA.now = Left_Count;}else{motorA.now = -Left_Count;}
        //if(motorB_dir){motorB.now = Right_Count;}else{motorB.now = -Right_Count;}
        motorB.now = Right_Count;
        motorA.now = Left_Count;
        Left_Count = 0;
        Right_Count = 0;

        // 2、输入PID控制器进行计算
        pid_cal(&motorA);
        pid_cal(&motorB);
        //motorA.out = Position_PID (motorA.now, motorA.target);
        //motorB.out = Position_PID (motorB.now, motorB.target);
        // 3、输出限幅
        pidout_limit(&motorA);
        pidout_limit(&motorB);
        // 4、PID的输出值 输入给电机
        gpio_set(motorin_AIN1_PORT, motorin_AIN1_PIN, motorA_dir);
        gpio_set(motorin_AIN2_PORT, motorin_AIN2_PIN, !motorA_dir);
        gpio_set(motorin_BIN1_PORT, motorin_BIN1_PIN, motorB_dir);
        gpio_set(motorin_BIN2_PORT, motorin_BIN2_PIN, !motorB_dir);
        DL_Timer_setCaptureCompareValue(motorAB_INST, motorB.out, GPIO_motorAB_C1_IDX);
        DL_Timer_setCaptureCompareValue(motorAB_INST, motorA.out, GPIO_motorAB_C0_IDX);
    }
    
    // 上位机传输数据
    //datavision_send();
}
int Position_PID (int Encoder,int Target)
{ 	
	 float Position_KP=300,Position_KI=0.05,Position_KD=0;
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Target-Encoder;                                  //计算偏差
	 Integral_bias+=Bias;	                                 //求出偏差的积分
	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
	 Last_Bias=Bias;                                       //保存上一次偏差 
	 return Pwm;                                           //增量输出
}

void pid_cal(pid_t *pid)
{
	// 计算当前偏差
	//pid->error[0] = pid->target - pid->now;
    pid->error[0] = Yaw_error_zzk(pid->target, pid->now);

	// 计算输出
	if(pid->pid_mode == DELTA_PID)  // 增量式
	{
		pid->pout = pid->p * (pid->error[0] - pid->error[1]);
		pid->iout = pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
		pid->out += pid->pout + pid->iout + pid->dout;
	}
	else if(pid->pid_mode == POSITION_PID)  // 位置式
	{
		pid->pout = pid->p * pid->error[0];
		pid->iout += pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - pid->error[1]);
		pid->out = pid->pout + pid->iout + pid->dout;
	}

	// 记录前两次偏差
	pid->error[2] = pid->error[1];
	pid->error[1] = pid->error[0];
}

void pid_cal_trace(pid_t *pid)
{
	// 计算当前偏差
	pid->error[0] = pid->target - pid->now;
	// 计算输出
	if(pid->pid_mode == DELTA_PID)  // 增量式
	{
		pid->pout = pid->p * (pid->error[0] - pid->error[1]);
		pid->iout = pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - 2 * pid->error[1] + pid->error[2]);
		pid->out += pid->pout + pid->iout + pid->dout;
	}
	else if(pid->pid_mode == POSITION_PID)  // 位置式
	{
		pid->pout = pid->p * pid->error[0];
		pid->iout += pid->i * pid->error[0];
		pid->dout = pid->d * (pid->error[0] - pid->error[1]);
		pid->out = pid->pout + pid->iout + pid->dout;
	}

	// 记录前两次偏差
	pid->error[2] = pid->error[1];
	pid->error[1] = pid->error[0];
}

void pid_init(pid_t *pid, uint32_t mode, float p, float i, float d)
{
	pid->pid_mode = mode;
	pid->p = p;
	pid->i = i;
	pid->d = d;
    pid->now = 0;

    pid->pout = 0;
    pid->iout = 0;
    pid->dout = 0;
    pid->out = 0;
}

void pidout_limit(pid_t *pid)
{
    if(pid->out>=16000)	
		pid->out=16000;
	if(pid->out<=-16000)	
		pid->out=-16000;
}
//pid_init();
//motor_target_set(xx, xx);

void datavision_send()  // 上位机波形发送函数
{
	// 数据包头
	DL_UART_transmitDataBlocking(UART_0_INST, 0x03);
	DL_UART_transmitDataBlocking(UART_0_INST, 0xfc);

	// 发送数据
	/* DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)motorA.target);  
	DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)motorA.now);
	DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)motorB.target);  
	DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)motorB.now);
    DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)angle.target);  
	DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)angle.now); */
    DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)angle.target);
    DL_UART_transmitDataBlocking(UART_0_INST, (uint8_t)angle.now);
	// 数据包尾
	DL_UART_transmitDataBlocking(UART_0_INST, 0xfc);
	DL_UART_transmitDataBlocking(UART_0_INST, 0x03);
}

float Yaw_error_zzk(float Target, float Now)
 {
    static float error;
    if (Target > 0) 
	{
        if (Now <= 0) 
		{
            if (fabs(Now) < (180 - Target)) 
			{
                error = fabs_zzk(Now) + Target;
            } 
			else 
			{
                error = -(180 - Target) - (180 - fabs_zzk(Now));
            }
        } 
		else 
		{
            if (Now > 0) 
			{
                error = Target - Now;
            }
        }
    } 
	else if (Target < 0)
	 {
        if (Now > 0) 
		{
            if (Now > Target + 180)
			{
                error = (180 - Now) + (180 - fabs_zzk(Target));
            }
			 else if (Now < Target + 180) 
			{
                error = -(fabs_zzk(Target) + Now);
            }
        } 
		else if (Now < 0) 
		{
            error = -(fabs_zzk(Target) - fabs_zzk(Now));
        }
    }
    
    return error;
}
 
float fabs_zzk(float value)
{
    if (value < 0) 
	{
        return -value;
    } 
	else 
	{
        return value;
    }
}