#include "stm32f10x.h"
int main()
{

RCC->APB2ENR|=(1<<0|1<<2);//Alternate Function I/O clock enabled and I/O clock enabled
GPIOA->CRL|=(1<<1|1<<3);//Configured as Output-Alternate-Push pull mode

RCC->APB1ENR|=1<<0;//Clock enable APB1 for TIM2 CH1 ie PA0
TIM2->ARR=60000;//TIMx_ARR generating a signal with a frequency Page 368
	
	TIM2->CCMR1|=(1<<6|1<<5);//OCC1M PWM mode 1 is selected ie In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive.
	TIM2->CCMR1&=~(1<<4);
	TIM2->CCMR1&=~(1<<0|1<<1);//CC1 channel is configured as output
	
	TIM2->CCER|=1<<0;//OC1 signal is output on the corresponding output pin
	
TIM2->CCR1=3000;//TIMx_CCRx duty cycle
TIM2->CCMR1|=1<<3;//The user must enable the corresponding preload register by setting the OCxPE bit in the TIMx_CCMRx register,
TIM2->CR1|=(1<<7|1<<0);//The user must enable the auto-reload preload register by setting the ARPE bit in the TIMx_CR1 register	
TIM2->EGR |=(1<<0);//the user has to initialize all the registers by setting the UG bit in the TIMx_EGR register.*/
	while(1)
	{
	}
}
