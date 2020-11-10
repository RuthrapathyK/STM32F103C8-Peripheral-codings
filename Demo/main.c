#include "stm32f10x.h"

int main()
{
	RCC->APB2ENR |=(1<<3);  //Enable Clock APB2 ffor GPIOB
	//GPIOB->CRH &=~((1<<23)|(1<<22)|(1<<20));  //Configure GPIO as Push-Pull
	GPIOB->CRL |=(1<<25);
	GPIOB->CRL&=~(1<<24|1<<26|1<<27);
	//GPIOC->ODR |=0x00;

	while(1)
	{	
	
GPIOB->ODR ^=(1<<6);		 	 //Turn ON and OFF of the LED PB6
	}
}
