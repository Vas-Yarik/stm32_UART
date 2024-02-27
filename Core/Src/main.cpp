#include <Vas_uart.h>
#include "main.h"

int main()
{
	//char* testptr = new (char);
	/*
	//--- Включаем HSE, ждём стабилизации
	SET_BIT(RCC->CR, RCC_CR_HSEON);
	while(READ_BIT(RCC->CR, RCC_CR_HSERDY == RESET)) {}x

	//--- Настраиваем все делители
	MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV2);

	//--- Настраиваем PLL
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV2);
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL, RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL9);
	// Ждём его активации
	SET_BIT(RCC->CR, RCC_CR_PLLON);
	while(READ_BIT(RCC->CR, RCC_CR_PLLRDY) != (RCC_CR_PLLRDY)) {}

	//--- Затактируем от PLL систему
	MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
	//while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}
	*/

	//--- Настройка дебагового пина, для отладки и индикации ошибок
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;								// Тактируем порт C

	GPIOC -> CRH &= !0x00F00000;									// Обнуление регистра ножки
	GPIOC -> CRH |= GPIO_CRH_MODE13_0;								// _ _ 0 1	 	10 мГц
	GPIOC -> CRH |= GPIO_CRH_CNF12_0;								// 0 1 _ _		Открытый сток
	GPIOC -> ODR |= GPIO_ODR_ODR13_Msk;								// Устанавливаем 1 (гасим светодиод)s


	//--- 1. Тактируем нужный порт A (PA2 TX, PA3 RX, USART2), шина APB1
	RCC->APB1ENR |= RCC_APB2ENR_IOPAEN;			// Тактируем порт A
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//--- 1.1 Настраиваем ножки
	// PA2, TX: Alternate function push-pull
	GPIOA->CRL &= !GPIO_CRL_MODE2;				// MODE 00 == (reset val)
	GPIOA->CRL |= GPIO_CRL_MODE2_0;				// MODE 01 == (10 MHz)

	GPIOA->CRL &= !GPIO_CRL_CNF2;				// CNF 00 == (reset val)
	GPIOA->CRL |= GPIO_CRL_CNF2_1;				// CNF 10 == Alternate function output Push-pull

	// PA3, RX: Input floating / Input pull-up
	GPIOA->CRL &= !GPIO_CRL_MODE3;				// MODE 00 == Input mode

	GPIOA->CRL &= !GPIO_CRL_CNF3;				// CNF 00 == (reset cur val)
	GPIOA->CRL |= GPIO_CRL_CNF3_1;				// CNF 10 == Input with pull-up / pull-down



	//--- 2. Включение UART (9600, без чётности, 8 бит, 1 стоп бит (ВСЁ, кроме скорости выставляется по умолчанию, в проекте необходимо предусмотреть установку этих битов!)
	USART2->CR1 |= USART_CR1_UE;			// Включение UART производится без сброса, так как это не обязательно

	//--- 2.1 Настройка скорости последовательного порта
	unsigned long mantissa = 468 << 4U; USART_BRR_DIV_Mantissa;
	unsigned long fraction = 75;
	USART2->BRR &= 0x0;						// Reset regisster
	USART2->BRR |= mantissa | fraction; 	// 9600 бод

	//--- 2.2 Разрешаем работу приёмника и передатчика
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;

	//--- 3. Реализация функции передачи

	GPIOC -> ODR &= !GPIO_ODR_ODR13_Msk;						// Устанавливаем 0 (зажигаем светодиод)
	while(1)
	{
		while(0 == (USART_SR_TXE & USART2->SR))
		{
			// Примитивная реализация ожидания освобождения регистра передачи, заменить на ОС или  проверку условия
		}
		USART2->DR = 0x21;
	}



}
