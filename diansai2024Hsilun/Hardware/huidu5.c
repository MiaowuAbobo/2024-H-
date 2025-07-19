#include "headfile.h"
//黑色输出高电平
uint8_t L4 = 0, L3 = 0, L2 = 0, L1 = 0, R1 = 0, R2 = 0, R3 = 0, R4 = 0; 
uint8_t Line_flag = 0;

void Get_Light_TTL(void)
{
    if(DL_GPIO_readPins(huidu8_L4_PORT, huidu8_L4_PIN)) {L4 = 1;} else {L4 = 0;}
    if(DL_GPIO_readPins(huidu8_L3_PORT, huidu8_L3_PIN)) {L3 = 1;} else {L3 = 0;}
    if(DL_GPIO_readPins(huidu8_L2_PORT, huidu8_L2_PIN)) {L2 = 1;} else {L2 = 0;}
    if(DL_GPIO_readPins(huidu8_L1_PORT, huidu8_L1_PIN)) {L1 = 1;} else {L1 = 0;}
    if(DL_GPIO_readPins(huidu8_R1_PORT, huidu8_R1_PIN)) {R1 = 1;} else {R1 = 0;}
    if(DL_GPIO_readPins(huidu8_R2_PORT, huidu8_R2_PIN)) {R2 = 1;} else {R2 = 0;}
    if(DL_GPIO_readPins(huidu8_R3_PORT, huidu8_R3_PIN)) {R3 = 1;} else {R3 = 0;}
    if(DL_GPIO_readPins(huidu8_R4_PORT, huidu8_R4_PIN)) {R4 = 1;} else {R4 = 0;}
    if(L4==0 || L3==0 || L2==0 || L1==0 || R1==0 || R2==0 || R3==0 || R4==0)
    {
        Line_flag = 1;
    }
}

void Get_Light_TTL_trace(void)
{
    if(DL_GPIO_readPins(huidu8_L4_PORT, huidu8_L4_PIN)) {L4 = 0;} else {L4 = 1;}
    if(DL_GPIO_readPins(huidu8_L3_PORT, huidu8_L3_PIN)) {L3 = 0;} else {L3 = 1;}
    if(DL_GPIO_readPins(huidu8_L2_PORT, huidu8_L2_PIN)) {L2 = 0;} else {L2 = 1;}
    if(DL_GPIO_readPins(huidu8_L1_PORT, huidu8_L1_PIN)) {L1 = 0;} else {L1 = 1;}
    if(DL_GPIO_readPins(huidu8_R1_PORT, huidu8_R1_PIN)) {R1 = 0;} else {R1 = 1;}
    if(DL_GPIO_readPins(huidu8_R2_PORT, huidu8_R2_PIN)) {R2 = 0;} else {R2 = 1;}
    if(DL_GPIO_readPins(huidu8_R3_PORT, huidu8_R3_PIN)) {R3 = 0;} else {R3 = 1;}
    if(DL_GPIO_readPins(huidu8_R4_PORT, huidu8_R4_PIN)) {R4 = 0;} else {R4 = 1;}
    if(L4==1 || L3==1 || L2==1 || L1==1 || R1==1 || R2==1 || R3==1 || R4==1)
    {
        Line_flag = 1;
    }
}


