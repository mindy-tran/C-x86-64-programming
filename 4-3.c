#include <stdio.h>

#define N 5
#define M 4
typedef long array_t[N][M];

// Annotate each line of the x86-64code in terms of N, M, a, i, j, and n from the original C code. 
/*.L2:
     addq %rdx, (%rax) -> a[i][j] += n;
     addq $1, %rdx     -> ++n;
     addq $32, %rax    -> ++i
     cmpq %rcx, %rdx   -> i < N
     jne .L2           -> if i<N not zero, then move onto the code with a[i][j] += n and ++n
*/

void print(array_t a) {
	int i, j;
	for (i = 0; i < N; ++i) {
	 	for (j= 0; j < M; ++j) {
	  		printf("%ld\t", a[i][j]);
		}
		printf("\n");
	}
}


void my_increment(array_t a) {
    /* A new C version of increment that implements these optimizations 
    using pointer arithmetic and dereferencing as demonstrated by 
    the optimized assembly. */

    long i=0, j=0;
    int n=0;
    
    
    // printing input
    printf("Input:\n");
    print(a);
    
    //increment the elements with pointer artithmetic
    for (j = 0; j < M; ++j) {

        // pointer to array
        long *ap = &a[0][j]; 

        for (i = 0; i < N; ++i) {
            *ap += n; //increment
            ap += M; // move onto the next row

            ++n; //increment the loop at the end, syntax
        }
    }
    

    
    // printing the output
    printf("\nOutput:\n");
    print(a);
}

     
     


int main(){
    long array_t[N][M] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, 
                            {13, 14, 15, 16}, {17,18, 19, 20}};
    
    my_increment(array_t);
    
}
