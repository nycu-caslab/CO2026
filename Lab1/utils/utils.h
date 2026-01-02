#include <stdio.h>
#include <stdlib.h>

static inline int isDigit(int c){
    return '0' <= c && c <= '9';
}

static inline int readInt(){
    int ret = 0, neg = 0, c;
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n' || c == '\t'));
    if (c == EOF)
        exit(0);
    if (c == '-')
        neg = 1, c = getchar();
    if (c == EOF || !isDigit(c)){
        printf("Unexpect token: %c\n", c);
        exit(-1);
    }
    do{
        ret = ret * 10 + (c - '0');
    }while ((c = getchar()) != EOF && isDigit(c));
    if (neg)
        ret = -ret;
    return ret;
}

static inline void readInt1DArray(int* arr, size_t size) {
    for (int i = 0; i < size; i++)
        arr[i] = readInt();
}

static inline void allocInt2DArray(int*** out_arr, size_t n, size_t m) {
    int *data = (int*)malloc(n * m * sizeof(int));
    int **arr = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        arr[i] = data + i * m;

    *out_arr = arr;
}

static inline void readInt2DArray(int*** out_arr, size_t n, size_t m) {
    int **arr = *out_arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            arr[i][j] = readInt();
    }
}

static inline void freeInt2DArray(int **arr) {
    free(arr[0]);
    free(arr);
}