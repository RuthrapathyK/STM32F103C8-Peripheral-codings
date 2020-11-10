#include "stm32f10x.h"

int main()
{
	//Clock Enable for PB13 and PC13
	RCC->APB2ENR|=(1<<3|1<<4);
	//Configure PB13 as Input with pull down
	GPIOB->CRH|=1<<23;
	GPIOB->CRH&=~(1<<22|1<<21|1<<20);
	GPIOB->IDR&=~(1<<13);
	//Configure PC13 as Output
	GPIOC->CRH|=1<<21;
	GPIOC->CRH&=~(1<<20|1<<23|1<<23);
	//Variable declaration
	uint16_t pressed=0;
	while(1)
	{
		if(((GPIOB->IDR)&(1<<13))!=0)
			GPIOC->ODR |=1<<13;
		else
			GPIOC->ODR &=~(1<<13);
	}
}

