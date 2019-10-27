#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)RCC_BASE + 0x30))

#define GPIOA_BASE (*((unsigned int*)0x40020000))
#define GPIOA_MODER (*((unsigned int*)GPIOA_BASE + 0x00))
#define GPIOA_ODR (*((unsigned int*)GPIOA_BASE + 0x14))

  int counter = 0;
int main()
{
//    int* p = &counter;
//    (*p)++;
//    (*p)++;
//    (*p)++;
//    (*p)++;
//    (*p)++;
//    (*p)++;
//  
//    p = (int*)0x20000002;
//    (*p) = 0xDEADBEEF;
  
    // Enable clock to Peripheral
    //RCC_AHB1ENR = 0x01;
    
    // Set GPIO5 to Output
    //GPIOA_MODER = 0xA8000400;
    
    
    
    unsigned int a = 0x5A5A5A5A;
    unsigned int b = 0xDEADBEEF;
    unsigned int c;
    
    c = a | b;
    c  = a & b;
    c = a ^ b;
    c = ~b;
    
    c = a >> 1;
    c = b << 3;
    
    
    
    volatile int counter = 0;
    
    while(1)
    {
        counter = 0;
        while(counter < 1000000)
        {
            counter++;
        }
        
        GPIOA_ODR = 0xA8000020; // On
      
        counter = 0;
        while(counter < 1000000)
        {
            counter++;
        }
        
        GPIOA_ODR = 0xA8000000; // On
    }
    
    return 0;
}
 
// RCC Base Address: 0x40023800
// 0x4002 3800 enable clock


//RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
// Address offset: 0x30
// Weite: 0x1

//Address offset: 0x00
//Write: 0x400


// GPIOA Base Address: 0x40020000
// Address offset: 0x14
// Write: 0x20