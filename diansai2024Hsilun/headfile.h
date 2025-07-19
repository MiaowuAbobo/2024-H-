#include "ti_msp_dl_config.h"
#include "stdio.h"

#include "oled.h"
#include "delay.h"
#include "isr.h"
#include "motor.h"
#include "gpio_zzk.h"
#include "huidu5.h"
#include "atk_ms901m.h"


#include "control.h"
#include "pid.h"

//LED控制宏定义
#define LED_RED_ON      DL_GPIO_setPins(LEDS_PORT, LEDS_LED2_RED_PIN);
#define LED_RED_OFF     DL_GPIO_clearPins(LEDS_PORT, LEDS_LED2_RED_PIN);
#define LED_GREEN_ON    DL_GPIO_setPins(LEDS_PORT, LEDS_LED2_GREEN_PIN);
#define LED_GREEN_OFF   DL_GPIO_clearPins(LEDS_PORT, LEDS_LED2_GREEN_PIN);
#define LED_BLUE_ON     DL_GPIO_setPins(LEDS_PORT, LEDS_LED2_BLUE_PIN);
#define LED_BLUE_OFF    DL_GPIO_clearPins(LEDS_PORT, LEDS_LED2_BLUE_PIN);
#define LED_zzk_ON      DL_GPIO_setPins(LED_zzk_PORT, LED_zzk_PIN_1_PIN);
#define LED_zzk_OFF      DL_GPIO_clearPins(LED_zzk_PORT, LED_zzk_PIN_1_PIN);

//BUZZER控制宏定义
#define BUZZER_ON       DL_GPIO_setPins(Buzzer_PORT, Buzzer_PIN_0_PIN);
#define BUZZER_OFF      DL_GPIO_clearPins(Buzzer_PORT, Buzzer_PIN_0_PIN);