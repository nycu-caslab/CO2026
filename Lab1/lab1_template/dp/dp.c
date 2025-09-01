#include <stdio.h>

#define T 37
#define N 6

extern void dp_asm(int n, int *charge, int t, int *dp_array);

void dp(int n, int *charge, int t, int *dp_array){
    // this is the dp code written in c 
    
    for(int i = 1; i <= t; i++){
        for(int j = 0; j < n; j++){
            if(i - *(charge + (j * 2)) < 0)
                continue;
            
            if(dp_array[i] < dp_array[i - *(charge + (j * 2))] + *(charge + (j * 2) + 1))
                dp_array[i] = dp_array[i - *(charge + (j * 2))] + *(charge + (j * 2) + 1);
        }    
    }
}

int main(){
    int charge[N][2] = { {3, 4}, {1, 1}, {5, 7}, {2, 2}, {7, 10}, {10, 15} };
    
    int dp_arr[T + 1] = {0};
    
    int dp_arr_asm[T + 1] = {0};
    
    dp(N, &charge[0][0], T, dp_arr);
    
    dp_asm(N, &charge[0][0], T, dp_arr_asm);
    
    printf("Result of C code: %d, Result of assembly code: %d\n", dp_arr[T], dp_arr_asm[T]);
    
    return 0;
}