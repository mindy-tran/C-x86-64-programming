#include <stdio.h>


long fact(long x) {
    if (x <= 1) {
        return 1;
    }
    return x * fact(x - 1);
    
    // minimum size (in bytes) of stack frames for fact() = 16
    // byte size for long x = 8
    // the stack frame must have: the return address, local storage, temporary storage
    
}

int main(){
    printf("fact(2): %ld\n", fact(2));
    printf("fact(3): %ld\n", fact(3));
    printf("fact(6): %ld\n", fact(6));

    return 0;
}
