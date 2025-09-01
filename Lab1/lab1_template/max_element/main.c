#include <stdio.h>

extern int max_element_asm(int *arr, int size);

int max_element(int *arr, int size){
    // this is the max_element code written in c
    int res = 0;
    for (int i = 0; i < size; i++)
        res = (res > arr[i] ? res : arr[i]);
    return res;
}

int main(){
    int arr[] = {2, 1, 6, 7, 1, 8, 2, 0, 3};
    int n = sizeof(arr) / sizeof(int);
    int c_res = max_element(arr, n);
    int asm_res = max_element_asm(arr, n);

    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    return 0;
}