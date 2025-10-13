/*
Given an array arr, you have to return the result after every element xor with each other. 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
extern int xor_trick_asm(int *arr, int size);

int xor_trick(int *arr, int size){
    int ret = 0;
    for(int i = 0; i < size; i++)
        ret ^= arr[i];
    return ret;
}

int main(){
    int n = readInt();
    int *arr = malloc(sizeof(n) * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = readInt();
    int c_res = xor_trick(arr, n);
    int asm_res = xor_trick_asm(arr, n);

    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    free(arr);
    return 0;
}