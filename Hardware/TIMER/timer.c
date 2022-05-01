#include "timer.h"

void Timer4_Init(u16 Period)//��������������Ƶ��
{
	GPIO_InitTypeDef GPIO_Init_Structure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInit_Structure;
	TIM_OCInitTypeDef TIM_OCInit_Structure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//�򿪶�Timer4ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//��GPIOBʱ��
	
	GPIO_Init_Structure.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init_Structure.GPIO_Mode = GPIO_Mode_AF_PP;//�ֲ�8.1.11�����������
	GPIO_Init_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Init_Structure);
	
	TIM_TimeBaseInit_Structure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInit_Structure.TIM_Period = Period;//����
	TIM_TimeBaseInit_Structure.TIM_Prescaler = 7199;//��Ƶ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInit_Structure);
	
	TIM_OCInit_Structure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInit_Structure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInit_Structure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInit_Structure.TIM_Pulse = Period;//ռ�ձ�
	TIM_OC3Init(TIM4, &TIM_OCInit_Structure);
	
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM4, ENABLE);
}












