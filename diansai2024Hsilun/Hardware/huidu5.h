#ifndef _HUIDU5_H_
#define _HUIDU5_H_
#include "headfile.h"

void Get_Light_TTL(void);
void Get_Light_TTL_trace(void);

extern uint8_t L4, L3, L2, L1, R1, R2, R3, R4;
extern uint8_t Line_flag ;//=1表示有线，=0表示没线

#endif
