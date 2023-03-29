# x86-64-programming
Practice implementing code in x86-64

Mindy Tran Homework 4 for Computer Organization, Winter 2022

My files do this:
1. 4.1.c Implements a sum function in x86-64
2. 4.2.c Has a factorial function. 
I compiled the fact() function to x86-64 using https://godbolt.org/ with x86-64 gcc 8.3 and 
the -Wall -Og -masm=att arguments. I annotate each line of the x86-64 code in terms of x from the original C code. I also indicate all
instructions in the compiled x86-64 code that modify the stack pointer and state the size of the 
stack frame in bytes (i.e., the amount of data that is pushed onto the call stack each time fact() 
is called).
3. 4.3.c Implements the function my_increment
    using pointer arithmetic and dereferencing as demonstrated by 
    the optimized assembly.
