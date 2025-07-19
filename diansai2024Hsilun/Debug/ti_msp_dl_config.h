/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for motorAB */
#define motorAB_INST                                                       TIMG0
#define motorAB_INST_IRQHandler                                 TIMG0_IRQHandler
#define motorAB_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define motorAB_INST_CLK_FREQ                                           32000000
/* GPIO defines for channel 0 */
#define GPIO_motorAB_C0_PORT                                               GPIOA
#define GPIO_motorAB_C0_PIN                                       DL_GPIO_PIN_12
#define GPIO_motorAB_C0_IOMUX                                    (IOMUX_PINCM34)
#define GPIO_motorAB_C0_IOMUX_FUNC                   IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_motorAB_C0_IDX                                  DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_motorAB_C1_PORT                                               GPIOA
#define GPIO_motorAB_C1_PIN                                       DL_GPIO_PIN_13
#define GPIO_motorAB_C1_IOMUX                                    (IOMUX_PINCM35)
#define GPIO_motorAB_C1_IOMUX_FUNC                   IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_motorAB_C1_IDX                                  DL_TIMER_CC_1_INDEX



/* Defines for TIM_EncoderA */
#define TIM_EncoderA_INST                                                (TIMA1)
#define TIM_EncoderA_INST_IRQHandler                            TIMA1_IRQHandler
#define TIM_EncoderA_INST_INT_IRQN                              (TIMA1_INT_IRQn)
#define TIM_EncoderA_INST_LOAD_VALUE                                    (12499U)
/* Defines for IMU_RECEIVE_DATA */
#define IMU_RECEIVE_DATA_INST                                            (TIMA0)
#define IMU_RECEIVE_DATA_INST_IRQHandler                        TIMA0_IRQHandler
#define IMU_RECEIVE_DATA_INST_INT_IRQN                          (TIMA0_INT_IRQn)
#define IMU_RECEIVE_DATA_INST_LOAD_VALUE                                (24999U)




/* Defines for OLED */
#define OLED_INST                                                           I2C0
#define OLED_INST_IRQHandler                                     I2C0_IRQHandler
#define OLED_INST_INT_IRQN                                         I2C0_INT_IRQn
#define OLED_BUS_SPEED_HZ                                                 400000
#define GPIO_OLED_SDA_PORT                                                 GPIOA
#define GPIO_OLED_SDA_PIN                                         DL_GPIO_PIN_28
#define GPIO_OLED_IOMUX_SDA                                       (IOMUX_PINCM3)
#define GPIO_OLED_IOMUX_SDA_FUNC                        IOMUX_PINCM3_PF_I2C0_SDA
#define GPIO_OLED_SCL_PORT                                                 GPIOA
#define GPIO_OLED_SCL_PIN                                         DL_GPIO_PIN_31
#define GPIO_OLED_IOMUX_SCL                                       (IOMUX_PINCM6)
#define GPIO_OLED_IOMUX_SCL_FUNC                        IOMUX_PINCM6_PF_I2C0_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART1
#define UART_0_INST_IRQHandler                                  UART1_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_17
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM40)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM39)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM40_PF_UART1_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM39_PF_UART1_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)
/* Defines for IMU */
#define IMU_INST                                                           UART0
#define IMU_INST_IRQHandler                                     UART0_IRQHandler
#define IMU_INST_INT_IRQN                                         UART0_INT_IRQn
#define GPIO_IMU_RX_PORT                                                   GPIOA
#define GPIO_IMU_TX_PORT                                                   GPIOA
#define GPIO_IMU_RX_PIN                                           DL_GPIO_PIN_11
#define GPIO_IMU_TX_PIN                                           DL_GPIO_PIN_10
#define GPIO_IMU_IOMUX_RX                                        (IOMUX_PINCM22)
#define GPIO_IMU_IOMUX_TX                                        (IOMUX_PINCM21)
#define GPIO_IMU_IOMUX_RX_FUNC                         IOMUX_PINCM22_PF_UART0_RX
#define GPIO_IMU_IOMUX_TX_FUNC                         IOMUX_PINCM21_PF_UART0_TX
#define IMU_BAUD_RATE                                                   (115200)
#define IMU_IBRD_32_MHZ_115200_BAUD                                         (17)
#define IMU_FBRD_32_MHZ_115200_BAUD                                         (23)





/* Port definition for Pin Group Buzzer */
#define Buzzer_PORT                                                      (GPIOB)

/* Defines for PIN_0: GPIOB.17 with pinCMx 43 on package pin 14 */
#define Buzzer_PIN_0_PIN                                        (DL_GPIO_PIN_17)
#define Buzzer_PIN_0_IOMUX                                       (IOMUX_PINCM43)
/* Port definition for Pin Group LED_zzk */
#define LED_zzk_PORT                                                     (GPIOB)

/* Defines for PIN_1: GPIOB.15 with pinCMx 32 on package pin 3 */
#define LED_zzk_PIN_1_PIN                                       (DL_GPIO_PIN_15)
#define LED_zzk_PIN_1_IOMUX                                      (IOMUX_PINCM32)
/* Port definition for Pin Group LEDS */
#define LEDS_PORT                                                        (GPIOB)

/* Defines for LED2_BLUE: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LEDS_LED2_BLUE_PIN                                      (DL_GPIO_PIN_22)
#define LEDS_LED2_BLUE_IOMUX                                     (IOMUX_PINCM50)
/* Defines for LED2_RED: GPIOB.26 with pinCMx 57 on package pin 28 */
#define LEDS_LED2_RED_PIN                                       (DL_GPIO_PIN_26)
#define LEDS_LED2_RED_IOMUX                                      (IOMUX_PINCM57)
/* Defines for LED2_GREEN: GPIOB.27 with pinCMx 58 on package pin 29 */
#define LEDS_LED2_GREEN_PIN                                     (DL_GPIO_PIN_27)
#define LEDS_LED2_GREEN_IOMUX                                    (IOMUX_PINCM58)
/* Defines for AIN1: GPIOA.8 with pinCMx 19 on package pin 54 */
#define motorin_AIN1_PORT                                                (GPIOA)
#define motorin_AIN1_PIN                                         (DL_GPIO_PIN_8)
#define motorin_AIN1_IOMUX                                       (IOMUX_PINCM19)
/* Defines for AIN2: GPIOA.27 with pinCMx 60 on package pin 31 */
#define motorin_AIN2_PORT                                                (GPIOA)
#define motorin_AIN2_PIN                                        (DL_GPIO_PIN_27)
#define motorin_AIN2_IOMUX                                       (IOMUX_PINCM60)
/* Defines for BIN1: GPIOB.0 with pinCMx 12 on package pin 47 */
#define motorin_BIN1_PORT                                                (GPIOB)
#define motorin_BIN1_PIN                                         (DL_GPIO_PIN_0)
#define motorin_BIN1_IOMUX                                       (IOMUX_PINCM12)
/* Defines for BIN2: GPIOB.6 with pinCMx 23 on package pin 58 */
#define motorin_BIN2_PORT                                                (GPIOB)
#define motorin_BIN2_PIN                                         (DL_GPIO_PIN_6)
#define motorin_BIN2_IOMUX                                       (IOMUX_PINCM23)
/* Defines for STBY: GPIOB.18 with pinCMx 44 on package pin 15 */
#define motorin_STBY_PORT                                                (GPIOB)
#define motorin_STBY_PIN                                        (DL_GPIO_PIN_18)
#define motorin_STBY_IOMUX                                       (IOMUX_PINCM44)
/* Port definition for Pin Group encoder */
#define encoder_PORT                                                     (GPIOB)

/* Defines for AE1: GPIOB.16 with pinCMx 33 on package pin 4 */
// pins affected by this interrupt request:["AE1"]
#define encoder_INT_IRQN                                        (GPIOB_INT_IRQn)
#define encoder_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define encoder_AE1_IIDX                                    (DL_GPIO_IIDX_DIO16)
#define encoder_AE1_PIN                                         (DL_GPIO_PIN_16)
#define encoder_AE1_IOMUX                                        (IOMUX_PINCM33)
/* Defines for AE2: GPIOB.20 with pinCMx 48 on package pin 19 */
#define encoder_AE2_PIN                                         (DL_GPIO_PIN_20)
#define encoder_AE2_IOMUX                                        (IOMUX_PINCM48)
/* Defines for BE1: GPIOB.2 with pinCMx 15 on package pin 50 */
#define encoder_BE1_PIN                                          (DL_GPIO_PIN_2)
#define encoder_BE1_IOMUX                                        (IOMUX_PINCM15)
/* Defines for BE2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define encoder_BE2_PIN                                         (DL_GPIO_PIN_12)
#define encoder_BE2_IOMUX                                        (IOMUX_PINCM29)
/* Defines for L4: GPIOB.7 with pinCMx 24 on package pin 59 */
#define huidu8_L4_PORT                                                   (GPIOB)
#define huidu8_L4_PIN                                            (DL_GPIO_PIN_7)
#define huidu8_L4_IOMUX                                          (IOMUX_PINCM24)
/* Defines for L3: GPIOB.8 with pinCMx 25 on package pin 60 */
#define huidu8_L3_PORT                                                   (GPIOB)
#define huidu8_L3_PIN                                            (DL_GPIO_PIN_8)
#define huidu8_L3_IOMUX                                          (IOMUX_PINCM25)
/* Defines for L2: GPIOA.22 with pinCMx 47 on package pin 18 */
#define huidu8_L2_PORT                                                   (GPIOA)
#define huidu8_L2_PIN                                           (DL_GPIO_PIN_22)
#define huidu8_L2_IOMUX                                          (IOMUX_PINCM47)
/* Defines for L1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define huidu8_L1_PORT                                                   (GPIOB)
#define huidu8_L1_PIN                                            (DL_GPIO_PIN_4)
#define huidu8_L1_IOMUX                                          (IOMUX_PINCM17)
/* Defines for R1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define huidu8_R1_PORT                                                   (GPIOB)
#define huidu8_R1_PIN                                           (DL_GPIO_PIN_19)
#define huidu8_R1_IOMUX                                          (IOMUX_PINCM45)
/* Defines for R2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define huidu8_R2_PORT                                                   (GPIOB)
#define huidu8_R2_PIN                                           (DL_GPIO_PIN_24)
#define huidu8_R2_IOMUX                                          (IOMUX_PINCM52)
/* Defines for R3: GPIOA.26 with pinCMx 59 on package pin 30 */
#define huidu8_R3_PORT                                                   (GPIOA)
#define huidu8_R3_PIN                                           (DL_GPIO_PIN_26)
#define huidu8_R3_IOMUX                                          (IOMUX_PINCM59)
/* Defines for R4: GPIOA.25 with pinCMx 55 on package pin 26 */
#define huidu8_R4_PORT                                                   (GPIOA)
#define huidu8_R4_PIN                                           (DL_GPIO_PIN_25)
#define huidu8_R4_IOMUX                                          (IOMUX_PINCM55)
/* Port definition for Pin Group KEYS */
#define KEYS_PORT                                                        (GPIOB)

/* Defines for KEY1: GPIOB.3 with pinCMx 16 on package pin 51 */
#define KEYS_KEY1_PIN                                            (DL_GPIO_PIN_3)
#define KEYS_KEY1_IOMUX                                          (IOMUX_PINCM16)
/* Defines for KEY2: GPIOB.9 with pinCMx 26 on package pin 61 */
#define KEYS_KEY2_PIN                                            (DL_GPIO_PIN_9)
#define KEYS_KEY2_IOMUX                                          (IOMUX_PINCM26)
/* Defines for KEY3: GPIOB.1 with pinCMx 13 on package pin 48 */
#define KEYS_KEY3_PIN                                            (DL_GPIO_PIN_1)
#define KEYS_KEY3_IOMUX                                          (IOMUX_PINCM13)
/* Defines for KEY4: GPIOB.13 with pinCMx 30 on package pin 1 */
#define KEYS_KEY4_PIN                                           (DL_GPIO_PIN_13)
#define KEYS_KEY4_IOMUX                                          (IOMUX_PINCM30)
/* Defines for KEY5: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEYS_KEY5_PIN                                           (DL_GPIO_PIN_21)
#define KEYS_KEY5_IOMUX                                          (IOMUX_PINCM49)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_motorAB_init(void);
void SYSCFG_DL_TIM_EncoderA_init(void);
void SYSCFG_DL_IMU_RECEIVE_DATA_init(void);
void SYSCFG_DL_OLED_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_IMU_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
