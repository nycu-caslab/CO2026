/*
Given four integers a, b, c, d, you have to return the result of F(a, b, c, d), where
F(a, b, c, d) = 
(a xor b) + (c << d) if a < b
(a and b) - (c or d) if a >= b
*/
#include <stdio.h>
#include "../../utils/utils.h"

extern int operators_asm(int a, int b, int c, int d);

int operators(int a, int b, int c, int d){
    // this is the operators code written in c;
    if (a < b)
        return (a ^ b) + (c << d);
    else
        return (a & b) - (c | d);
}

int main(){
    int a = readInt(), b = readInt();
    int c = readInt(), d = readInt();
    int c_res = operators(a, b, c, d);
    int asm_res = operators_asm(a, b, c, d);

    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    return 0;
}