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