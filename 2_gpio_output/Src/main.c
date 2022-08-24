#include "stm32l0xx.h"


#define IOPAEN				(1U<<0) // 0B 0000 0000 0000 0000 0000 0000 0000 0001
#define PIN5				(1U<<5)
#define LED					PIN5

int main(void)
{
	int x;

	/* Enable clock access to GPIOA */
	RCC->IOPENR |= IOPAEN;

	/* Set PA5 as output pin */
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

	while(1)
	{
		/* Experiment 2: toggle led */
		GPIOA->ODR ^= LED;
		for(int i=0; i<10000; i++)
		{
			x++;
		}
	}
}
