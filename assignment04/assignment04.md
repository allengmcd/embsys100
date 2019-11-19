Assignment 4 
Allen McDermott

1.
	a. See main.c
	
	b. There seem to be three instructions that are called every time, the MOVS, LDR.N and STR instructions. For the LED ON and OFF Instructions, the order is different than the clock and enable port sections but all of them seem to call those three instructions.
	
	c. For turning the LED on these instructions were called, LDR, BICS.W, STR. For turning the LED off these instructions were called, LDR.N, LDR, ORRS.W, STR.

2. 
	a. For the function I made, there are 5 parameters and each one is an int. For parameters 1-4 the diassembled code simply calls the MOVS instruction and puts each parameter in on of the registers (R0-R3). For parameter 5 it does something a little different, it will put the 5th parameter in R0 and then call STR to move it into memory. 
	
	b. It seems the only code that is generated is the code that puts the values in the registers and memory. The only instructions are MOVS for putting the values into the registers and STR to put parameter 5 into memory. In order to get to the function the BL instruction is called.
	
	c. To get the parameters in the called function is a little more interesting. registers R0-R3 already have the parameters but the disassembly needs to use more registers so it calls PUSH for registers R4-R7 and then puts R0 into R4. To get parameter 5 it calls LDR to get parameter 5 from memory. Once the function is done using registers R4-R7 the POP instruction is called and the function will branch back to the calling function.
	
	d. I do find it interesting that it only calls PUSH and POP for registers R4-R7. If I had to guess I would say that it is just making sure that any values stored in there could be retrieved when the function is finished but I'm curious why it doesn't do that for registers R0-R3 as well. I also feel like it would of been easier to just store each parameter in registers R0-R4 instead of taking parameter 5 and storing it in memory. I guess this is were turning on the optimization comes in to figure out if any instructions or registers aren't being used in an efficient way.

