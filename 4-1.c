/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdio.h>

long sum(long from, long to) {
    // Declare and initialize result var – *do not modify*.
    long result = 0;
    // Ensure that argument *from* is in %rdi, 
    // argument *to* is in %rsi, *result* is in %rax 
    // *do not modify*.
    __asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from )); 
    __asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to )); 
    __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result )); 
    
    // Your x86-64 code goes below - comment each instruction...
    //doSum:
    //result += from;
    //++from;
    //if (from <= to)
    //    goto doSum;
    //return result;
    
    __asm__(
        ".L1:"
        "addq %rdi, %rax;" // # this sets result+=from
        "addq $1, %rdi;" // ++from increment
        "cmpq %rsi, %rdi;" // # compare from:to
        "jle .L1;" // if from <= to, goto doSum
        
    );
    
    // Ensure that *result* is in %rax for return - *do not modify*.
    __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result )); 
    return result;
}


int main()
{
    printf("sum(1, 6): %ld\n", sum(1, 6));
    printf("sum(3, 5): %ld\n", sum(3, 5));
    printf("sum(5, 3): %ld\n", sum(5, 3));

    return 0;
}
