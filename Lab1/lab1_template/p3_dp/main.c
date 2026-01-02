#include <stdio.h>
#include <string.h>
#include "../../utils/utils.h"

extern int dp_asm(int *arr, int n, int m);

int dp(int *arr, int n, int m){
    // this is the dp code written in c
    arr[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int id = i * m + j;
            if (id == 0)
                continue;
            if (arr[id] == -1)
                continue;
            arr[id] = 0;
            if (i > 0 && arr[id - m] != -1)
                arr[id] += arr[id - m];
            if (j > 0 && arr[id - 1] != -1)
                arr[id] += arr[id - 1];
        }
    }
    return arr[n * m - 1];
}

int main(){
    int n = readInt(), m = readInt();
    int **arr, **arr_asm;

    allocInt2DArray(&arr, n, m);
    allocInt2DArray(&arr_asm, n, m);
    readInt2DArray(&arr_asm, n, m);

    memcpy(arr[0], arr_asm[0], n * m * sizeof(int));
    
    int c_res = dp(arr[0], n, m);
    int asm_res = dp_asm(arr_asm[0], n, m);
    
    if (c_res == asm_res)
        printf("\033[32m[PASS] \033[0m");
    else
        printf("\033[31m[FAILED] \033[0m");
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);

    freeInt2DArray(arr);
    freeInt2DArray(arr_asm);
    
    return 0;
}