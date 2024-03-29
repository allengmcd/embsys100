/*******************************************************************************
File name       : aqrAsm.s
Description     : Assembly language function for square
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : sqrAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : int sqrAsm(val)
                : Where val is the value to calculate it's square
Parameters      : R0: Address of val
Return value    : R0
*******************************************************************************/  
  
swapCharsAsm:
        PUSH {R4} // save the input argument and return address
	MOVS R2, R0     // Move value in R0 to R2
	LDRB R3, [R2]   // Put value in address of R2 into R3
	LDRB R0, [R1]   // Put value in address of R1 into R0
	STRB R0, [R2]   // Store value in address of R2 into R0
	STRB R3, [R1]   // Store value in address of R1 into R3
	LDRB R0, [R2]   // Put value in address of R2 into R0
	LDRB R4, [R1]   // Put value in address of R1 into R4
	CMP R0, R4      // Check if R0 and R4 are equal         
	BNE.N neql      // Jump to neql if not equal
	MOVS R0, #0     // Set reuturn value to 0
	B.N ret         // Jump to ret
neql:                   // Label neql, its supposed to stand for not equal        
	MOVS R0, #1     // Set return 
ret:                    // Label for the return statement
	POP {R4}        // Restore R4
	BX LR           // return (with function result in R0)

    END
