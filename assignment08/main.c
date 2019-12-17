#include <stdint.h>
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

#define SYSTICK_TICKS 15000
#define SYS_CLOCK_HZ 16000000
#define MIN_BRIGHTNESS 0
#define MAX_BRIGHTNESS 1000

uint32_t LED_Brightness;
volatile uint32_t msTicks = 0;

void delay(uint32_t delayAmount)
{
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;     
    SysTick->VAL = 0;                            
    msTicks = delayAmount;           
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;     
    
    while (msTicks != 0);
}

void SysTick_Handler()
{
    if (msTicks > 0)
        --msTicks;
}

void main()
{
    SysTick_Config(SYSTICK_TICKS);
  
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN;      
    GPIOA->MODER  |= GPIO_MODER_MODE5_1;       
    GPIOA->AFR[0] |= GPIO_AFRL_AFSEL5_0;       
    
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;                     
    TIM2->CCMR1  |= (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1);  
    TIM2->CCMR1  |= TIM_CCMR1_OC1PE;            
    TIM2->CR1    |= TIM_CR1_ARPE;               
    TIM2->CCER   |= TIM_CCER_CC1E;              
    TIM2->PSC = 0x7U;                           
    TIM2->ARR = 0xFFFU;                         
    TIM2->EGR |= TIM_EGR_UG;                    
    TIM2->CR1 |= TIM_CR1_CEN;                   
      
    LED_Brightness = 0;
    TIM2->CCR1 = LED_Brightness;
    
    while(1)
    {
        while(LED_Brightness < MAX_BRIGHTNESS)
        {
            delay(1);
            LED_Brightness += 1;
            TIM2->CCR1 = LED_Brightness;
        }
        
        while(LED_Brightness > MIN_BRIGHTNESS)
        {
            delay(1);            
            LED_Brightness -= 1;
            TIM2->CCR1 = LED_Brightness;
        }
    }
}
