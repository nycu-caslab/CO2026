#include <stdio.h>
#include "../../utils/utils.h"

extern int max_element_asm(int *arr, int size);

int max_element(int *arr, int size){
    // this is the max_element code written in c
    int res = 0;
    for (int i = 0; i < size; i++)
        res = (res > arr[i] ? res : arr[i]);
    return res;
}

int main(){
    int n = readInt();
    int *arr = malloc((size_t)n * sizeof(int));
    readInt1DArray(arr, n);
    int c_res = max_element(arr, n);
    int asm_res = max_element_asm(arr, n);

    if (c_res == asm_res)
        printf("\033[32m[PASS] \033[0m");
    else
        printf("\033[31m[FAILED] \033[0m");
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    
    free(arr);
    return 0;
}