#include "SYS.h"

volatile uint32_t Tick;
void systemClockConfig(void)
{
	RCC->CR |= RCC_CR_HSION; 									// Internal clock
	while(!(RCC->CR & RCC_CR_HSIRDY));							// Wait HSIRDY flag is set

	RCC->APB1ENR |= RCC_APB1ENR_PWREN;							// Power interface enable

	FLASH->ACR |= FLASH_ACR_PRFTBE;								// Enable flash memory
	FLASH->ACR |= FLASH_ACR_LATENCY_1;							// Latency = 010 -> 48MHz <= SYSCLK <= 72MHz
	while(!(FLASH->ACR &FLASH_ACR_PRFTBS));						// Wait PRFTBS flag is set

	RCC->CFGR |= RCC_CFGR_PLLMULL16;							// Bo PLL nhan 16
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;							// He so chia cua AHP la 1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;							// He so chia cua APB1 la 2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;							// he so chia cua APB2 la 1

	RCC->CFGR &=~ RCC_CFGR_PLLSRC;								// HSI clock selected as PLL input clock
	RCC->CR |= RCC_CR_PLLON;									// PLL enable
	while(!(RCC->CR&RCC_CR_PLLRDY));							// Wait PLLRDY flag is set
	RCC->CFGR |= RCC_CFGR_SW_PLL;								// PLLCLK clock selected as SYSCLK input clock
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL)); 					// Wait SWS_PLL flag is set

	SystemInit();												// Thiet lap he thong
	SystemCoreClockUpdate();									// Update cac gia tri tren vao he thong

	/* System Tick la bo dem xuong, moi khi den 0 thi se co ngat systemtick xay ra */
	/* Sau khi thiet lap cac gia tri tren, SystemCoreClock duoc thiet lap */
	/* Chia 1000 de thiet lap moi xung nhip la 1 ms */
	SysTick_Config(SystemCoreClock/1000UL);

}

// Ham xu ly ngat cua systemtick
void SysTick_Handler(void)
{
	Tick++;
}

// Ham lay gia tri tick
uint32_t getTick(void)
{
	return Tick;
}
void Delay_Tick_ms(uint32_t ms)
{
	uint32_t now = getTick(); 							// Lay gia tri bat dau dem
	while((getTick() - now) < ms);						// Lay gia tri hien tai tru di gia tri bat dau den khi bang ms
}
