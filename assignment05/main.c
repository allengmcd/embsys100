
	
extern int sqrAsm(int val);
extern int divAsm(int val);
extern int swapCharsAsm(char* val1, char* val2);


int PrintString()
{
  return 0;
}

int myCstr()
{
  return 0;
}

int swapChars(char* val1, char* val2)
{
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    
    if(*val1 == *val2)
    {
      return 0;
    }
    
    return 1;
}


int swap_pointer(int** xPtr, int** yPtr)
{
  int* temp = *xPtr;
  *xPtr = *yPtr;
  *yPtr = temp;
  
  return 0;
}

int main()
{
  int x = 0;
  int y = 1;
  
  int* xPtr = &x;
  int* yPtr = &y;
  
  swap_pointer(&xPtr, &yPtr);
  //int test = sqrAsm(2);
  
  int test = divAsm(8);
  
  char a = 'a';
  char b = 'b';
  
  int outputTest = swapCharsAsm(&a, &b);
  
  return 0;
}
