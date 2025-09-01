# extern void dp_asm(int n, int *charge, int t, int *dp_array);

.section .text
.global dp_asm

dp_asm:
    # TODO: You have to implement dynamic programming with assembly code (fill the dp_array)
    # HINT: You might need to use "slli(shift left)" to implement multiplication
    # HINT: You might need to be careful of calculating the memory address you store in your register
