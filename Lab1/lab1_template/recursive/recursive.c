/*
You are given an **sorted** integer array $arr$ and an integer $target$.
You have to find the index(0-base) of $target$ in $arr$ using binary search.
If $target$ does not exist in $arr$, return -1.
*/
#include <stdio.h>
#include "../../utils/utils.h"

extern int binary_search_asm(int arr[], int left, int right, int target);

int binary_search(int arr[], int left, int right, int target){
    // this is the binary_search code written in c
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binary_search(arr, left, mid - 1, target);
    else
        return binary_search(arr, mid + 1, right, target);
}

int main(){
    int n = readInt();
    int target = readInt();
    int *arr = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = readInt();
    
    int c_res = binary_search(arr, 0, n - 1, target);
    int asm_res = binary_search_asm(arr, 0, n - 1, target);
    printf("Result of C code: %d, Result of assembly code: %d\n", c_res, asm_res);
    free(arr);
    return 0;
}