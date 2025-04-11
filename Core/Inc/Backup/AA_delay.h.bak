
#ifndef AA_DELAY_H_
#define AA_DELAY_H_

#include <stdint.h>


#define TIMER1
//#define TIMER2
//#define TIMER3
//#define TIMER4

#ifdef TIMER1
#define CURRENT_TIMER               ((TIM_TypeDef *) TIM1)
#endif

#ifdef TIMER2
#define CURRENT_TIMER               ((TIM_TypeDef *) TIM2)
#endif

#ifdef TIMER3
#define CURRENT_TIMER               ((TIM_TypeDef *) TIM3)
#endif

#ifdef TIMER4
#define CURRENT_TIMER               ((TIM_TypeDef *) TIM4)
#endif

#define CURRENT_FREQ				SystemCoreClock

#define NOP_10 "NOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\tNOP\n\t"
#define NOP_50 NOP_10 NOP_10 NOP_10 NOP_10 NOP_10
#define NOP_100 NOP_50 NOP_50
#define NOP_200 NOP_100 NOP_100

void AA_delayInit(void);
void AA_delayDeInit(void);
void delayMs(volatile uint32_t delay);
void delayUs(volatile uint32_t delay);
void delay_1us_Assembly(void);
void delay_us_Assembly(volatile uint32_t us);

#endif /* AA_DELAY_H_ */
