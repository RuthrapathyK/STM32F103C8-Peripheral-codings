#include "stm32f10x.h"
void delay(int a)
{
	int i,j,k;
	for(i=0;i<=a;i++)
	{
		for (j=0;j<=1000;j++)
		{
			k=i*j;
			k=i*j;
			k=i*j;
			k=0;
		}
	}
}

int main()
{
	RCC->APB2ENR|=(1<<14|1<<2|1<<0);//Clock for USART and GPIO and Alternte Functions
	
	GPIOA->CRH|=(1<<4|1<<5);//MODE config for Mximum 50Mhz speed
	GPIOA->CRH|=(1<<7|1<<6);//Alternate fuction Open Drain
	//GPIOA->CRH&=~(1<<6);
//Enable USART
	 USART1->CR1=1<<13;
	
//Baud Rate set
	
	USART1->BRR=0x1D4C;//for 72 Mhz calculations are made
	
//Transmit Enable
USART1->CR1|=1<<3;
	

	while(1)
	{
	while(!(USART1->SR&(1<<7)))
	;
	USART1->DR='b';
	delay(100);
	}
}
