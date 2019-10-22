   @page { margin: 0.79in } p { margin-bottom: 0.1in; line-height: 115% } a:link { so-language: zxx } 

  

Allen McDermott

Assignment 02

  

1.

1.  \-2147483648
    
2.  0x80000000
    
3.  Both are set to 1. The N flag is to indicate if the instruction resulted in a negative number and the V flag is to indicate if there to indicate if the instruction resulted in an overflow. In this case, there was an overflow that resulted in a negative number so both the N and V flag were set to 1.
    

  

2.

1.  It has the value -1 and then goes to 0 after being incremented once.
    
2.  Both are set 0. Since the instruction resulted with a 0 and there was no overflow so neither N or V are set to 1.
    

  

3.

1.  Starts at 2147483647 and is incremented by 1 for each addition.
    
2.  Both are set 0. Since the instruction resulted with neither a negative number or an overflow neither N or V are set to 1.
    

  

4.

1.  Starts at 4294967295 and goes to 0 after being incremented once. After that it is incremented by 1 as expected.
    
2.  Since the result is 0 the N flag is also zero since an unsigned value is never going to be false. The V flag is surprising to me because I thought it would be set to 1 since the the value goes to 0.
    

  

5.

1.  Global, at least for this file.
    
2.  It is not visible for me. If I had to guess I would say that its because there are many variables already "active" and it would be confusing if the debugger listed all of them.
    
3.  Watch can display it as long as you know the variable name.
    
4.  0x20000000
    

  

6.

1.  4
    
2.  p\_int is a pointer that is pointing to the location of counter. When we increment p\_int, we are incrementing the value at that location.
    

  

7.

1.  0x20000000
    
2.  I would guess RAM because the number is being changed so I don't think it would be in ROM.
    
3.  4