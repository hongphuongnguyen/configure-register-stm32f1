#ifndef SYSTEMCONFIGURE_H_
#define SYSTEMCONFIGURE_H_

#include <stdio.h>
#include <stm32f1xx.h>

void systemClockConfig(void);
void SysTick_Handler(void);
uint32_t getTick(void);
void Delay_Tick_ms(uint32_t ms);


#endif /* SYSTEMCONFIGURE_H_ */
