/*
 * delay.c
 *
 *  Created on: 20 ãðóä. 2017 ð.
 *      Author: Andriy
 */

#include "AA_delay.h"
#include "stm32f7xx.h"

// Ôóíêö³ÿ âìèêàííÿ òàéìåðó äëÿ ïîòðåá delay
void AA_delayInit(void)
{
#ifdef TIMER1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
#endif

#ifdef TIMER2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
#endif

#ifdef TIMER3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
#endif

#ifdef TIMER4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
#endif
}

// Ôóíêö³ÿ âèìèêàííÿ òàéìåðó ÿê íåìàº ïîòðåáè â delay
void AA_delayDeInit(void)
{
#ifdef TIMER1
	RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN;
#endif

#ifdef TIMER2
	RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
#endif

#ifdef TIMER3
	RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN;
#endif

#ifdef TIMER4
	RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN;
#endif
}

//Ôóíêö³ÿ ôîðìóâàííÿ çàòðèìêè â ì³ë³ñåêóíäàõ
void delayMs(volatile uint32_t delay)
{
	CURRENT_TIMER->PSC = CURRENT_FREQ/1000-1; //Âñòàíîâëþºìî ïîäð³áíþâà÷
	CURRENT_TIMER->ARR = delay; //âñòàíîâëþºìî çíà÷åííÿ ïåðåïîâíþâàííÿ òàéìåðó, à òàêîæ ³ çíà÷åííÿ ïðè ÿêîìó ãåíåðóåòüñÿ ïîä³ÿ îíîâëåííÿ
	CURRENT_TIMER->EGR |= TIM_EGR_UG; //Ãåíåðèðóåìî Ïîä³þ îíîâëåííÿ äëÿ çàïèñó äàíèõ â ðåã³ñòðè PSC ³ ARR
	CURRENT_TIMER->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM; //Çàïóñêàåìî òàéìåð çàïèñîì áèòó CEN ³ âñòàíîâëþºìî ðåæèì Îäíîãî ïðîõîäó âñòàíîâëåííÿì á³òó OPM
	while ((CURRENT_TIMER->CR1) & (TIM_CR1_CEN!=0)); //Âèêîíóºìî öèêë ïîêè ðàõóº òàéìåð äî íóëÿ
}

//Ôóíêö³ÿ ôîðìóâàííÿ çàòðèìêè â ì³êðîñåêóíäàõ
void delayUs(volatile uint32_t delay)
{
    CURRENT_TIMER->PSC = 99;                        // Prescaler: 200MHz / 200 = 1MHz (1μs per tick)
	CURRENT_TIMER->ARR = delay;                       // مقدار تأخیر بر حسب میکروثانیه
	CURRENT_TIMER->EGR |= TIM_EGR_UG;                 //
	CURRENT_TIMER->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM;    // فعال کردن تایمر
	while ((CURRENT_TIMER->CR1) & (TIM_CR1_CEN!=0));  // پاک کردن فلگ وقفه
}

// if CPU Clock == 200 MHz
// 1 NOP == 5 ns
void delay_1us_Assembly(void) 
{
    __ASM volatile (
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
        "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
    );
}

void delay_us_Assembly(volatile uint32_t us)
{
    while (us--) 
			{
				__ASM volatile (
            NOP_200  // 200 دستور NOP معادل 1 میکروثانیه
            //"NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t" // جبران تأخیر حلقه
        );
			}
}	
