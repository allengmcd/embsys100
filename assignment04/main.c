#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

volatile int counter=0;

int SumFive(int one, int two, int three, int four, int five)
{
    int test = one + two;
    int cool = three + four;
    int meal = five;
    
    return test + cool + meal;
}

int CallSumFive()
{
  int returnVal = SumFive(1,2,3,4,5);
  return returnVal;
}

void main(void)
{
    CallSumFive();
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;
    
    *(unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4)) = 0x1;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    //GPIOA_MODER |= 0x400;
    
    
    *(unsigned int*)((0x42000000) + (0x20000 * 32) + (10 * 4)) = 0x01;


    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR |= GPIOA;
    
    *(unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4)) = 0x01;
        
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR &= ~GPIOA;
    *(unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4)) = 0x00;

    }
}