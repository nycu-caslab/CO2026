/*
You are given an n * m 2D integer array $arr$ stands for a map.
Your task is to find how many different paths exist from the top-left corner $(0, 0)$ to the bottom-right corner $(n-1, m-1)$.
You can only move either down or right at any point in time.
*/

#include <stdio.h>
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
    int *data = malloc((size_t)n * m * sizeof(int));
    int *data_asm = malloc((size_t)n * m * sizeof(int));
    int **arr = malloc((size_t)n * sizeof(int *));
    int **arr_asm = malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++){
        arr[i] = data + i * m;
        arr_asm[i] = data_asm + i * m;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            arr[i][j] = arr_asm[i][j] = readInt();
    }
    
    int c_res = dp(&arr[0][0], n, m);
    int asm_res = dp_asm(&arr_asm[0][0], n, m);
    
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    
    return 0;
}