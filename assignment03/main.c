#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define UNIT 250000

#define MESSAGE "ALLEN GENE MCDERMOTT" // All letters must be capital
#define MESSAGE_LENGTH 20 // Length of the message

void Break(int length) // This is the busy wait function
{
    int counter = 0;
    while(counter < UNIT*length)
    {
        counter++;
    }

    return;
}

void Dot() 
{
    GPIOA_ODR = 0x20; // On
    Break(1); // on for 1 unit
    GPIOA_ODR = 0x00; // Off
    Break(1);
    
    return;
}

void Dash() 
{
    GPIOA_ODR = 0x20; // On
    Break(3); // on for 3 units
    GPIOA_ODR = 0x00; // Off  
    Break(1);
    
    return;
}

void charValue(char input)
{
    switch(input)
    {
      case 'A': 
        Dot();
        Dash();
        break;
      case 'B': 
        Dash();
        Dot();
        Dot();
        Dot();
        break;
      case 'C': 
        Dash();
        Dot();
        Dash();
        Dot();
        break;
      case 'D': 
        Dash();
        Dot();
        Dot();
        
        break;
      case 'E': 
        Dot();
        
        break;
      case 'F': 
        Dot();
        Dot();
        Dash();
        Dot();
        
        break;
      case 'G': 
        Dash();
        Dash();
        Dot();
        
        break;
      case 'H': 
        Dot();
        Dot();
        Dot();
        Dot();
        
        break;
      case 'I': 
        Dot();
        Dot();
        
        break;
      case 'J': 
        Dot();
        Dash();
        Dash();
        Dash();
        
        break;
      case 'K':
        Dash();
        Dot();
        Dash();
        
        break;
      case 'L': 
        Dot();
        Dash();
        Dot();
        Dot();
        
        break;
      case 'M': 
        Dash();
        Dash();
        
        break;
      case 'N': 
        Dash();
        Dot();
        
        break;
      case 'O': 
        Dash();
        Dash();
        Dash();
        break;
      case 'P': 
        Dot();
        Dash();
        Dash();
        Dot();
        
        break;
      case 'Q': 
        Dash();
        Dash();
        Dot();
        Dash();
        
        break;
      case 'R': 
        Dot();
        Dash();
        Dot();
        
        break;
      case 'S': 
        Dot();
        Dot();
        Dot();
        break;
      case 'T': 
        Dash();
        
        break;
      case 'U': 
        Dot();
        Dot();
        Dash();
        
        break;
      case 'V': 
        Dot();
        Dot();
        Dot();
        Dash();
        
        break;
      case 'W': 
        Dot();
        Dash();
        Dash();
        
        break;
      case 'X': 
        Dash();
        Dot();
        Dot();
        Dash();
        
        break;
      case 'Y': 
        Dash();
        Dot();
        Dash();
        Dash();
        
        break;
      case 'Z': 
        Dash();
        Dash();
        Dot();
        Dot();
        
        break;
      case '0': 
        Dash();
        Dash();
        Dash();
        Dash();
        Dash();
        
        break;
      case '1': 
        Dot();
        Dash();
        Dash();
        Dash();
        Dash();
        
        break;
      case '2': 
        Dot();
        Dot();
        Dash();
        Dash();
        Dash();
        
        break;
      case '3': 
        Dot();
        Dot();
        Dot();
        Dash();
        Dash();
        
        break;
      case '4': 
        Dot();
        Dot();
        Dot();
        Dot();
        Dash();
        
        break;
      case '5': 
        Dot();
        Dot();
        Dot();
        Dot();
        Dot();
        
        break;
      case '6': 
        Dash();
        Dot();
        Dot();
        Dot();
        Dot();
        
        break;
      case '7': 
        Dash();
        Dash();
        Dot();
        Dot();
        Dot();
        
        break;
      case '8': 
        Dash();
        Dash();
        Dash();
        Dot();
        Dot();
        
        break;
      case '9': 
        Dash();
        Dash();
        Dash();
        Dash();
        Dot();
        
        break;
      default:
    }
}


int main()
{
    RCC_AHB1ENR = 0x01;
    GPIOA_MODER = 0xA8000400;
    int counter = 0;
  
    int length = MESSAGE_LENGTH; // set message length
    char name[MESSAGE_LENGTH] = MESSAGE; // set message
    
    while(1)
    {
        for(int i = 0; i < length; i++) // Loop through the char array
        {
          if(name[i] == ' ') // check if its the end of a word
          {
            Break(6); // wait 7 units between words (each letter automatically waits 1 unit after so only need to break for 6)
          }
          else
          {
            charValue(name[i]); // get the Morse Code value for this char
            Break(2); // wait 3 units between words (each letter automatically waits 1 unit after so only need to break for 2)
          }
        }
        
        Break(12); // Break for 10 units and start over again
    }
    
    return 0;
}