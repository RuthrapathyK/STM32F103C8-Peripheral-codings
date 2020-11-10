#include "stm32f10x.h"

void __enable_irq(void);
//void NVIC_EnableIRQ(IRQn_t IRQn);
unsigned volatile int a=0;
int main()
{
	
	//Clock enable for AFIO
	RCC->APB2ENR|=1<<0;
	//Clock enable for GPIO B
	RCC->APB2ENR|=1<<3;
	
	//Clock Enable for PC13
	RCC->APB2ENR|=1<<4;
	//Configure PC13 as Output
	GPIOC->CRH|=1<<21;
	GPIOC->CRH &=~(1<<23|1<<22|1<<20);
	//Configure GPIOB13 as Input with pull down
	GPIOB->CRH|=1<<23;
	GPIOB->CRH&=~(1<<22|1<<21|1<<20);
	GPIOB->IDR&=~(1<<13);
	
	//Configuration Register for Interrupt 
	AFIO->EXTICR[3]=1<<4;
	AFIO->EXTICR[3]&=~(1<<5|1<<6|1<<7);
	
	//Configure Interrupt Mask Register
	EXTI->IMR|=1<<13;
	
	//Select Rising Edge
	EXTI->RTSR|=1<<13;
	
	//Disable Falling Edge
	EXTI->FTSR&=~(1<<13);

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();
	
while(1)
	{
		
	}
}
void EXTI15_10_IRQHandler()
{
	EXTI->PR|=1<<13;
	a++;
	GPIOC->ODR^=1<<13;
}
