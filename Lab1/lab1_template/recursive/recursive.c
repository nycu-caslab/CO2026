#include <stdio.h>

extern int fibo_asm(int term);

int fibo(int term){
    // this is the fibonacci code written in c
    // fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
    
    if(term == 0)
        return 0;
    else if(term == 1)
        return 1;
    else
        return fibo(term - 1) + fibo(term - 2);
}

int main(){
    int e = 5;
    
    int c_res = fibo(e);
    int asm_res = fibo_asm(e);
    
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);

    return 0;
}