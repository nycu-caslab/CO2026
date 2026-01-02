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
    readInt1DArray(arr, n);
    int c_res = xor_trick(arr, n);
    int asm_res = xor_trick_asm(arr, n);
    if (c_res == asm_res)
        printf("\033[32m[PASS] \033[0m");
    else
        printf("\033[31m[FAILED] \033[0m");
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    free(arr);
    return 0;
}