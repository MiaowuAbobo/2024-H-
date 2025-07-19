/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gTIM_EncoderABackup;
DL_TimerA_backupConfig gIMU_RECEIVE_DATABackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_motorAB_init();
    SYSCFG_DL_TIM_EncoderA_init();
    SYSCFG_DL_IMU_RECEIVE_DATA_init();
    SYSCFG_DL_OLED_init();
    SYSCFG_DL_UART_0_init();
    SYSCFG_DL_IMU_init();
    /* Ensure backup structures have no valid state */

	gTIM_EncoderABackup.backupRdy 	= false;
	gIMU_RECEIVE_DATABackup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(TIM_EncoderA_INST, &gTIM_EncoderABackup);
	retStatus &= DL_TimerA_saveConfiguration(IMU_RECEIVE_DATA_INST, &gIMU_RECEIVE_DATABackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(TIM_EncoderA_INST, &gTIM_EncoderABackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(IMU_RECEIVE_DATA_INST, &gIMU_RECEIVE_DATABackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerG_reset(motorAB_INST);
    DL_TimerA_reset(TIM_EncoderA_INST);
    DL_TimerA_reset(IMU_RECEIVE_DATA_INST);
    DL_I2C_reset(OLED_INST);
    DL_UART_Main_reset(UART_0_INST);
    DL_UART_Main_reset(IMU_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerG_enablePower(motorAB_INST);
    DL_TimerA_enablePower(TIM_EncoderA_INST);
    DL_TimerA_enablePower(IMU_RECEIVE_DATA_INST);
    DL_I2C_enablePower(OLED_INST);
    DL_UART_Main_enablePower(UART_0_INST);
    DL_UART_Main_enablePower(IMU_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_motorAB_C0_IOMUX,GPIO_motorAB_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_motorAB_C0_PORT, GPIO_motorAB_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_motorAB_C1_IOMUX,GPIO_motorAB_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_motorAB_C1_PORT, GPIO_motorAB_C1_PIN);

    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_OLED_IOMUX_SDA,
        GPIO_OLED_IOMUX_SDA_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralInputFunctionFeatures(GPIO_OLED_IOMUX_SCL,
        GPIO_OLED_IOMUX_SCL_FUNC, DL_GPIO_INVERSION_DISABLE,
        DL_GPIO_RESISTOR_NONE, DL_GPIO_HYSTERESIS_DISABLE,
        DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_enableHiZ(GPIO_OLED_IOMUX_SDA);
    DL_GPIO_enableHiZ(GPIO_OLED_IOMUX_SCL);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_IMU_IOMUX_TX, GPIO_IMU_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_IMU_IOMUX_RX, GPIO_IMU_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutput(Buzzer_PIN_0_IOMUX);

    DL_GPIO_initDigitalOutput(LED_zzk_PIN_1_IOMUX);

    DL_GPIO_initDigitalOutput(LEDS_LED2_BLUE_IOMUX);

    DL_GPIO_initDigitalOutput(LEDS_LED2_RED_IOMUX);

    DL_GPIO_initDigitalOutput(LEDS_LED2_GREEN_IOMUX);

    DL_GPIO_initDigitalOutput(motorin_AIN1_IOMUX);

    DL_GPIO_initDigitalOutput(motorin_AIN2_IOMUX);

    DL_GPIO_initDigitalOutput(motorin_BIN1_IOMUX);

    DL_GPIO_initDigitalOutput(motorin_BIN2_IOMUX);

    DL_GPIO_initDigitalOutput(motorin_STBY_IOMUX);

    DL_GPIO_initDigitalInputFeatures(encoder_AE1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInput(encoder_AE2_IOMUX);

    DL_GPIO_initDigitalInputFeatures(encoder_BE1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInput(encoder_BE2_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_L4_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_L3_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_L2_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_L1_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_R1_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_R2_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_R3_IOMUX);

    DL_GPIO_initDigitalInput(huidu8_R4_IOMUX);

    DL_GPIO_initDigitalInputFeatures(KEYS_KEY1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEYS_KEY2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEYS_KEY3_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEYS_KEY4_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEYS_KEY5_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_clearPins(GPIOA, motorin_AIN1_PIN |
		motorin_AIN2_PIN);
    DL_GPIO_enableOutput(GPIOA, motorin_AIN1_PIN |
		motorin_AIN2_PIN);
    DL_GPIO_clearPins(GPIOB, Buzzer_PIN_0_PIN |
		LED_zzk_PIN_1_PIN |
		LEDS_LED2_BLUE_PIN |
		LEDS_LED2_RED_PIN |
		LEDS_LED2_GREEN_PIN |
		motorin_BIN1_PIN |
		motorin_BIN2_PIN |
		motorin_STBY_PIN);
    DL_GPIO_enableOutput(GPIOB, Buzzer_PIN_0_PIN |
		LED_zzk_PIN_1_PIN |
		LEDS_LED2_BLUE_PIN |
		LEDS_LED2_RED_PIN |
		LEDS_LED2_GREEN_PIN |
		motorin_BIN1_PIN |
		motorin_BIN2_PIN |
		motorin_STBY_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_2_EDGE_RISE);
    DL_GPIO_setUpperPinsPolarity(GPIOB, DL_GPIO_PIN_16_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOB, encoder_AE1_PIN);
    DL_GPIO_enableInterrupt(GPIOB, encoder_AE1_PIN);

}


SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
    /* Set default configuration */
    DL_SYSCTL_disableHFXT();
    DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_1);
    DL_SYSCTL_setMCLKDivider(DL_SYSCTL_MCLK_DIVIDER_DISABLE);
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOB_INT_IRQn, 0);

}


/*
 * Timer clock configuration to be sourced by  / 1 (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   32000000 Hz = 32000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gmotorABClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gmotorABConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN_UP,
    .period = 32000,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_motorAB_init(void) {

    DL_TimerG_setClockConfig(
        motorAB_INST, (DL_TimerG_ClockConfig *) &gmotorABClockConfig);

    DL_TimerG_initPWMMode(
        motorAB_INST, (DL_TimerG_PWMConfig *) &gmotorABConfig);

    DL_TimerG_setCaptureCompareOutCtl(motorAB_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(motorAB_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(motorAB_INST, 0, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(motorAB_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(motorAB_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(motorAB_INST, 0, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(motorAB_INST);


    
    DL_TimerG_setCCPDirection(motorAB_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   125000 Hz = 32000000 Hz / (1 * (255 + 1))
 */
static const DL_TimerA_ClockConfig gTIM_EncoderAClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIM_EncoderA_INST_LOAD_VALUE = (100ms * 125000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIM_EncoderATimerConfig = {
    .period     = TIM_EncoderA_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIM_EncoderA_init(void) {

    DL_TimerA_setClockConfig(TIM_EncoderA_INST,
        (DL_TimerA_ClockConfig *) &gTIM_EncoderAClockConfig);

    DL_TimerA_initTimerMode(TIM_EncoderA_INST,
        (DL_TimerA_TimerConfig *) &gTIM_EncoderATimerConfig);
    DL_TimerA_enableInterrupt(TIM_EncoderA_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
    DL_TimerA_enableClock(TIM_EncoderA_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (32000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   250000 Hz = 32000000 Hz / (1 * (127 + 1))
 */
static const DL_TimerA_ClockConfig gIMU_RECEIVE_DATAClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 127U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * IMU_RECEIVE_DATA_INST_LOAD_VALUE = (100ms * 250000 Hz) - 1
 */
static const DL_TimerA_TimerConfig gIMU_RECEIVE_DATATimerConfig = {
    .period     = IMU_RECEIVE_DATA_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_IMU_RECEIVE_DATA_init(void) {

    DL_TimerA_setClockConfig(IMU_RECEIVE_DATA_INST,
        (DL_TimerA_ClockConfig *) &gIMU_RECEIVE_DATAClockConfig);

    DL_TimerA_initTimerMode(IMU_RECEIVE_DATA_INST,
        (DL_TimerA_TimerConfig *) &gIMU_RECEIVE_DATATimerConfig);
    DL_TimerA_enableInterrupt(IMU_RECEIVE_DATA_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(IMU_RECEIVE_DATA_INST_INT_IRQN, 0);
    DL_TimerA_enableClock(IMU_RECEIVE_DATA_INST);





}


static const DL_I2C_ClockConfig gOLEDClockConfig = {
    .clockSel = DL_I2C_CLOCK_BUSCLK,
    .divideRatio = DL_I2C_CLOCK_DIVIDE_1,
};

SYSCONFIG_WEAK void SYSCFG_DL_OLED_init(void) {

    DL_I2C_setClockConfig(OLED_INST,
        (DL_I2C_ClockConfig *) &gOLEDClockConfig);
    DL_I2C_setAnalogGlitchFilterPulseWidth(OLED_INST,
        DL_I2C_ANALOG_GLITCH_FILTER_WIDTH_50NS);
    DL_I2C_enableAnalogGlitchFilter(OLED_INST);

    /* Configure Controller Mode */
    DL_I2C_resetControllerTransfer(OLED_INST);
    /* Set frequency to 400000 Hz*/
    DL_I2C_setTimerPeriod(OLED_INST, 7);
    DL_I2C_setControllerTXFIFOThreshold(OLED_INST, DL_I2C_TX_FIFO_LEVEL_EMPTY);
    DL_I2C_setControllerRXFIFOThreshold(OLED_INST, DL_I2C_RX_FIFO_LEVEL_BYTES_1);
    DL_I2C_enableControllerClockStretching(OLED_INST);


    /* Enable module */
    DL_I2C_enableController(OLED_INST);


}


static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void)
{
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115211.52
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_32_MHZ_115200_BAUD, UART_0_FBRD_32_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_0_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(UART_0_INST);
}

static const DL_UART_Main_ClockConfig gIMUClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gIMUConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_IMU_init(void)
{
    DL_UART_Main_setClockConfig(IMU_INST, (DL_UART_Main_ClockConfig *) &gIMUClockConfig);

    DL_UART_Main_init(IMU_INST, (DL_UART_Main_Config *) &gIMUConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115211.52
     */
    DL_UART_Main_setOversampling(IMU_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(IMU_INST, IMU_IBRD_32_MHZ_115200_BAUD, IMU_FBRD_32_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(IMU_INST,
                                 DL_UART_MAIN_INTERRUPT_OVERRUN_ERROR |
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(IMU_INST_INT_IRQN, 0);


    DL_UART_Main_enable(IMU_INST);
}

