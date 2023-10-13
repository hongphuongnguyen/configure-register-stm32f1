#include "GPIOConfigure.h"

void GPIOConfig(void)
{
	/* GPIOC_13 */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH |= (3UL << 20);					// Output mode, max speed 50MHz
	GPIOC->CRH &= ~(3UL << 22);					// General purpose push-pull

	/* Button chan GPIOC_14 */
	GPIOC->CRH &=~ (3UL << 24); 				// Input mode
	GPIOC->CRH |= (2UL << 26);					// Input pull up/down
	GPIOC->ODR |= (1 << 14);					// GPIOC-14 is pull-up

}

