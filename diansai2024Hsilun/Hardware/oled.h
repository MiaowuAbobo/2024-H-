#ifndef __OLED_I2C_H
#define	__OLED_I2C_H

#define OLED_ADDRESS	0x3c //脥篓鹿媒碌梅脮没0R碌莽脳猫,脝脕驴脡脪脭0x78潞脥0x7A脕陆赂枚碌脴脰路 -- 脛卢脠脧0x78

void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);

#endif

