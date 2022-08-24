// Where is the LED connected?

// Port: A
// Pin:  5

#define PERIPH_BASE			0x40000000UL
#define IOPERIPH_OFFSET		0x10000000UL
#define IOPERIPH_BASE		(PERIPH_BASE + IOPERIPH_OFFSET)
#define GPIOA_OFFSET		0x000UL
#define GPIOA_BASE			(IOPERIPH_BASE + GPIOA_OFFSET)

#define AHBPERIPH_OFFSET	0x00020000UL
#define AHBPERIPH_BASE		(PERIPH_BASE + AHBPERIPH_OFFSET)
#define RCC_OFFSET			0x00001000UL
#define RCC_BASE			(AHBPERIPH_BASE + RCC_OFFSET)

#define IOPENR_OFFSET		0x2C
#define RCC_IOPENR			(*(volatile unsigned int *)(RCC_BASE + IOPENR_OFFSET))


#define MODER_OFFSET		0x00
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODER_OFFSET))


#define ODR_OFFSET			0x14
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))

#define IOPAEN				(1U<<0) // 0B 0000 0000 0000 0000 0000 0000 0000 0001
#define PIN5				(1U<<5)
#define LED					PIN5


/**
 *
 */
int main(void)
{
	int x;

	/* Enable clock access to GPIOA */
	RCC_IOPENR |= IOPAEN;

	/* Set PA5 as output pin */
	GPIOA_MODE_R |= (1U<<10);
	GPIOA_MODE_R &=~(1U<<11);

	while(1)
	{
		/* Set PA5 as high */
//		GPIOA_OD_R |= LED;

		/* Experiment 2: toggle led */
		GPIOA_OD_R ^= LED;
		for(int i=0; i<10000; i++)
		{
			x++;
		}
	}
}



