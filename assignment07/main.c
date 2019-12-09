#include <stdint.h>
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"

#define SYS_CLOCK_HZ 16000000u


void main()
{
   // 1. Enable clock to Peripheral
    RCC->AHB1ENR |= 0x1;
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    GPIOA->MODER |= 0x400; 
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    SysTick->LOAD = SYS_CLOCK_HZ;  
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
    
    while(1)
    {

    }
}
