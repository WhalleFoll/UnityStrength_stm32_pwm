#ifndef _LED_H_
#define _LED_H_
#include "sys.h"

void led_init(void);
#define Led_Red    PBout(5)//��ɫLED
#define Led_Green  PEout(5)//��ɫLED
#define Beep       PBout(8)//������
#endif
