#include "EXTI.h"

void EXTIConfigure(void)
{
	/* GPIOA_0 EXTI Line 0 Falling */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRL &=~ (3UL << 0); 					// Input mode
	GPIOA->CRL &=~ (3UL << 2);					// Clear
	GPIOA->CRL |= (2UL << 2);					// Input pull up/down
	GPIOA->ODR |= (1UL << 0); 					// PA0 Input PullUp

	/* AFIO Configure */
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	AFIO->EXTICR[0] &=~ (15UL << 0);			// PA[x] Pin selected as the source input for EXTI0
	EXTI->IMR |= (1UL << 0);					// Interrupt request from Line 0 is not masked
	EXTI->RTSR &=~ (1UL << 0);					// Rising trigger disabled of Line 0
	EXTI->FTSR |= (1UL << 0);					// Falling trigger enabled of Line 0

	__NVIC_SetPriority(EXTI0_IRQn, 0);			// Set priority of EXTI_IRQn is 0
	__NVIC_EnableIRQ(EXTI0_IRQn);				// Enable EXTI0
}
