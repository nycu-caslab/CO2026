# extern int xor_trick_asm(int *arr, int size);

.section .text
.global xor_trick_asm

xor_trick_asm:
    li t0, 0 # xor sum 
    li t1, 0 # i = 0

loop:
    lw t2, 0(a0) # get val
    xor t0, t0, t2 # sum = sum ^ a[i]
    addi a0, a0, 4 # add a0
    addi t1, t1, 1 # add index

    blt t1, a1, loop # if i < n, continue the loop

    mv a0, t0
    ret
