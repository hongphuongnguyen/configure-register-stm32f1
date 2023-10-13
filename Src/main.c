#include <stdint.h>
#include <stm32f1xx.h>
#include "GPIOConfigure.h"
#include "SYS.h"
#include "EXTI.h"

int main(void)
{
	systemClockConfig();
	GPIOConfig();
	EXTIConfigure();

	GPIOC->BSRR |= (1<<13);
    while(1)
    {
    	/*
    	GPIOC->BSRR |= (1<<13);
    	Delay_Tick_ms(1000);
    	GPIOC->BSRR |= (1<<29);
    	Delay_Tick_ms(1000);
		*/

    	/*
    	         * Button *
    	if(GPIOC->IDR & (1<<14) != 0)
    		GPIOC->BSRR |= (1<<13);
    	else
    		GPIOC->BSRR |= (1<<29);
    	*/
    }
}
void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & (1<<0))
	{
		/* Neu co ngat Line 0 xay ra va chua duoc xu ly */
		GPIOC->BSRR |= (1<<29);
		EXTI->PR |= (1<<0); // Sau khi hoan thanh cv thi phai xoa co PR tuong ung
	}
}
