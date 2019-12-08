#include <stdint.h>
#include "stm32f401xe.h"
#include "system_stm32f4xx.h"
//#include "delay.h"

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 1000000

volatile int counter=0;

extern void delay(unsigned int delays);
extern void control_user_led(uint8_t state, uint32_t duration);

void Problem1()
{
    // 1. Enable clock to Peripheral
    RCC->AHB1ENR |= 0x1;
  
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    GPIOA->MODER |= 0x400; 
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
        counter=0;

        delay(DELAY_DURATION);
        GPIOA->ODR |=  (*((unsigned int*)(0x40020014)));
        GPIOA->ODR |= (unsigned int)(1<<5);
            
        delay(DELAY_DURATION);
        GPIOA->ODR &= ~(unsigned int)(1<<5);
    }
}

void tempDelay(unsigned int delays)
{
    while (counter < delays)
    {
      counter++;
    }
    
}

void Problem2()
{
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC->AHB1ENR |= 0x1;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    GPIOA->MODER |= 0x400; 

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
        control_user_led(LED_ON, DELAY_DURATION);
        control_user_led(LED_OFF, DELAY_DURATION);
    }
}

void main(void)
{
   Problem2();
}

