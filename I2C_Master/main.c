#include "stm32f10x.h"

void i2c_init(void)
{
		RCC->APB2ENR|=(1<<0|1<<3);//Enable clock for IO and AFIO
	GPIOB->CRL|=(1<<24|1<<27|26);//Configured as Alternate function Open drain configuration
	GPIOB->CRL|=(1<<28|1<<31|30);
	GPIOB->CRL&=~(1<<29|25);
	//APB1 Enable for I2C
RCC->APB1ENR|=(1<<21);
	
 //Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
I2C1->CR2=0b001000;//8Mhz selected FREQ
	
	//• Configure the clock control registers
I2C1->CCR|=1<<15;//Selected Standard Mode
I2C1->CCR|=(1<<5|1<<3);//Selected 100kHz
	
	//• Configure the rise time register
I2C1->TRISE|=(1<<3|1<<0);//TRISE register 
	
	//• Program the I2C_CR1 register to enable the peripheral
I2C1->CR1|=(1<<0);//Peripheral Enable
}


void i2c_slave_address(unsigned char address)
{
		//• Set the START bit in the I2C_CR1 register to generate a Start condition
I2C1->CR1|=(1<<8);
	//Wait
	while(((I2C1->SR1)&(1<<0))==0)
	{}
	//Slave adress
	I2C1->DR=address;
	//Wait
	while(((I2C1->SR1)&(1<<1))==0)
	{}
	while(((I2C1->SR2)&(1<<2))==0)
	{}
	//Wait
	while(((I2C1->SR1)&(1<<7))==0)
	{}
}


void i2c_transmit(unsigned char data)
{
		//Data
	I2C1->DR=data;
	while(((I2C1->SR1)&(1<<7))==0)
	{}
}


void i2c_stop(void)
{
	//Stop
 while(((I2C1->SR1)&(1<<2))==0)
	I2C1->CR1|=(1<<8);
	
}
void i2c_transmit_string(char *p)
{
	uint32_t i=0;
	while(*(p+i)!='\0')
	{
		i2c_transmit(*(p+i));
		i++;
	}
}
int main()
{

	i2c_init();
	i2c_slave_address(0x00);
	i2c_transmit_string("HiRuthrapathy");
	i2c_stop();

		while(1)
	{	
	
	}
}
