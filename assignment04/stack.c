#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointers to stack elements for adding and retrieving
int* dataPtr;

// Initialize internals of the stack
void stack_init(void)
{
    dataPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = '\0';
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (dataPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full
        return -1;
    }

    if (dataPtr == 0)
    {
        dataPtr = &StackStore[0];
    }
    else
    {
        dataPtr++;
    }
    
    *dataPtr = data;
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (dataPtr == 0)
    {
        // stack is empty
        return -1;
    }

    *data = *dataPtr;
    dataPtr--;
    
    return 0;
}
