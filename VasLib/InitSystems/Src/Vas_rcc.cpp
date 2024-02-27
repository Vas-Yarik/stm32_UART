#include <Vas_rcc.h>
#include "stm32f1xx_hal.h"


rcc_system :: rcc_system(short mode)
{
	if (1 == mode)
	{
		rcc.HSE.State = true;
		rcc.HSI.State = false;
	}
}


bool rcc_system :: init(void)
{
	if (rcc.HSE.State && !rcc.HSI.State)
	{
		init_HSE();
	}
	if (!rcc.HSE.State && rcc.HSI.State)
	{
		init_HSI();
	}
	return 0;
}

bool rcc_system :: init_HSE()
{
	RCC->CR |= RCC_CR_HSEON;
	RCC->CFGR |= RCC_CFGR_PLLMULL9;									// PLLMUL 0111 == x9

	if (RCC_CR_PLLRDY == (RCC->CR & RCC_CR_PLLRDY))
	{
		RCC->CR |= RCC_CR_PLLON;
	}
	else
	{
		GPIOC -> ODR &= !GPIO_ODR_ODR13_Msk;						// Устанавливаем 0 (зажигаем светодиод)
	}

	return 0;
}

bool rcc_system :: init_HSI()
{
	//throw ("DEVELOPING");
}
