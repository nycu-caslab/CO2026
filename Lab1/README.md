# Assembly Language Lab

## Lab1 Slide

[CO2026_lab1_slide](<https://docs.google.com/presentation/d/1tWK-qsUHMEfZ0f9LHjsyXr9xRYoM6SFW/edit?usp=sharing&ouid=112366487093966794500&rtpof=true&sd=true>)

## Intro.

This lab will focus on getting familiar with basic RISC-V assembly instructions.

By the end of this lab, you will have a better grasp of assembly language programming.


## Basic Assembly Functions

Before you start to write this lab, we will quickly introduce some basic instructions in RISC-V and what do they actually do. Please don't be nervous, take a deep breath and we will start to dive into assembly language. 

There are four basic functions you have to implement with assembly code. We have prepared the template of both c code and assembly code of these four functions and you have to filled the absence of assembly code in order to fulfill those four functions. You may check simply check whether your code is correct by the output of c code or using ripes. 

- operators practice
- max element
- dynamic programming
- binary search in recursion

### Brief Tutorial of assembly language

In this part, we will quickly go through some common instructions and introduce them to you. 

**add**
```
add rd, rs1, rs2
```
This instruction will add the value that stored inside register rs1 and register rs2 together and store it into register rd.

**sub**
```
sub rd, rs1, rs2
```
This instruction will subtract the value that stored inside register rs1 and register rs2 then store it into register rd.

**addi**
```
addi rd, rs1, imm1
```
This instruction will add the value of register rs1 and immediate imm1 together then store the result into register rd. 

**mv**
```
mv rd, rs1
```
In fact, mv(move) is the pseudo-instruction, and it is equal to addi rd, rs1, 0. So this instruction is actually just move or better to say copy from rs1 to rd.

**li**
```
li rd, imm1
```
Same as above, li is also a pseudo-instruction; however, it's hard to explain, so we will skip it. This instruction will copy the immediate imm1 to register rd.

**lw**
```
lw rd, rs1, imm1
# Assume we store the array a[0] address in reg. a1
lw a0, 0(a1)    # this instruction will load a[0] to reg. a0
lw a0, 4(a1)    # this instruction will load a[1] to reg. a0
```
lw instruction will load the value of address "rs1 + imm1" to rd. In execution, you should be careful of the memory maintainence. If you miscalculate the address, it may lead to a horrible error. 

**sw**
```
sw rs2, rs1, imm1
# Assume we store the array a[0] address in reg. a1
sw a0, 0(a1)
# this instruction will store the value of reg. a0 into a[0]
sw a0, 4(a1)
# this instruction will store the value of reg. a0 into a[1]
```
sw instruction will store the value of reg. rs2 into address "rs1 + imm1". 

**beq**
```
beq rs1, rs2, imm1
# Example code
entry:
    addi a3, x0, 0
    addi a4, x0, 0
    beq a3, a4, entry
# since the value of a3 and a4 reg. are both, beq will branch to entry, so it will form an infinite loop
```
beq will compare the value of reg. rs1 and reg. rs2, if the value equals to each other, then branch to the address "PC + imm1". 

**bge**
```
bge rs1, rs2, imm1
# Example code
entry:
    li a3, 4
    li a5, 7
    bge a3, a5, entry
# since the value of reg. a3 is smaller than a5, so it will not branch to entry
```
bge will compare the value of reg. rs1 and reg. rs2, if the value of reg. rs1 is larger or equal to that of reg. rs2, then branch to the address "PC + imm1". 

**blt**
```
blt rs1, rs2, imm1
# Example code
entry:
    li a2, 3
    li a4, 4
    blt a2, a4, entry
# since the value of reg. a2 is less than reg. a4, so it will form an infinite loop
```
blt will compare the value of reg. rs1 and reg. rs2, if the value of reg. rs1 is less than that of reg. rs2, then branch to the address "PC + imm1". 

**j**
```
# Example code
entry:
    li a0, 1
    j second_process    # this line will jump to second_process
    addi a0, a0, 1
second_process:
    ...
# because the line "addi ..." will not be executed, so the value of reg. a0 is 1 not 2
```
j is also a pseudo-instruction. j is a kind of unconditional branch instruction, so when j is executed, it will directly jump to the destination.

**jal**
```
jal rd, imm
```
jal is jump and link. In the cpu, jal will have two step to execute. First step, rd = pc + 4. Second, pc = pc + imm. This instruction is really important when you are implementing 
things with function call.

**slli**
```
slli rd, rs1, imm1
# Example code
addi a1, x0, 1  # a1 -> 1
slli a2, a1, 2  # a2 -> 100(binary) -> 4(decimal)
# In this instruction, slli will move the value in reg. rs1 imm1 bits left, then store the value into reg. rd
```

### Problem 0(xor trick):

> Note: This is a sample problem. The answer is already provided in the template code. You don't have to implement it or submit it.

Description:
Given an array $arr$, you have to return the result after every element xor with each other. 

Example 1:
Input: $arr = [1, 2, 3]$
Output: 0
Explanation: 1(01) xor 2(10) => 3(11), 3(11) xor 3(11) => 0(00)

Example 2:
Input: $arr = [1, 3, 7]$
Output: 5
Explanation: 1(001) xor 3(011) => 2(010), 2(010) xor 7(111) => 5(101)

Constraints of the testcase:
- $1 \leq arr.length \leq 200$
- For every $i$, $\ 1 \leq arr[i] \leq 10^9$


### Problem 1(operators practice):
Description:
Given four integers $a, b, c, d$, you have to return the result of $F(a, b, c, d)$, where
$$
F(a, b, c, d) = 
\begin{cases}
(a \oplus b) + (c << d) &a < b \\
(a \ \& \ b) - (c \ | \ d) & a \ge b \\
\end{cases}
$$
where $\oplus$ is the bitwise xor operator, $<<$ is the left shift operator, $\&$ is the bitwise and operator, and $|$ is the bitwise or operator.

Example 1:
Input: $a = 7, b = 9, c = 4, d = 3$
Output: $46$
Explanation: $a < b$, so $F(7, 9, 4, 3) = (7 \oplus 9) + (4 << 3) = 14 + 32 = 46$

Example 1:
Input: $a = 7, b = 5, c = 4, d = 3$
Output: $-2$
Explanation: $a >= b$, so $F(7, 5, 4, 3) = (7 \ \& \ 5) - (4 \ | \ 3) = 5 - 7 = -2$

Constraints of the testcase:
- $0 \leq a, b, c \leq 10^5$
- $0 \leq d \leq 10$

### Problem 2(max element):
Description:
Given an array $arr$, you have to return maximum value of the array.  

Example 1:
Input: $arr = [2, 1, 5, 7]$
Output: $7$

Example 2:
Input: $arr = [1, 1]$
Output: $1$


Constraints of the testcase:
- $1 \leq arr.length \leq 200$
- For every $i$, $\ 0 \leq arr[i] \leq 10^9$

### Problem 3(dp):
Description:
You are given an $n * m$ 2D integer array $arr$ stands for a map. Your task is to find how many different paths exist from the top-left corner $(0, 0)$ to the bottom-right corner $(n-1, m-1)$. You can only move either down or right at any point in time.

If $arr[i][j] == -1$, it means that the cell is blocked and you cannot pass through that cell. 
If $arr[i][j] == 0$, you can pass through that cell.

Example 1:
Input: $arr = [[0, 0, 0, 0], [0, -1, 0, 0], [0, 0, 0, 0]]$
Output: 4

Example 2:
Input: $arr = [[0, -1], [-1, 0]]$
Output: 0
Explanation: There is no path from $(0, 0)$ to $(1, 1)$.
 

Constraint of the testcase:
- $1 \leq n, m \leq 15$
- For every $i, j, \ arr[i][j] = 0 or arr[i][j] = -1$

### Problem 4(binary search in recursion):
Description:
You are given an **sorted** integer array $arr$ and an integer $target$. You have to find the index(0-base) of $target$ in $arr$ using binary search. If $target$ does not exist in $arr$, return -1.

Example 1:
Input: $arr = [1, 4, 5, 7, 9, 10, 13]$, $target = 9$
Output: $4$
Explanation: The index of 9 in arr is 4.

Example 2:
Input: $arr = [1, 4, 5, 7, 9, 10, 13]$, $target = 14$
Output: $-1$
Explanation: 14 does not exist in arr, so return -1.

Constraint of the testcase:
- $1 \leq arr.length \leq 1000$
- For every $i$, $\ -10^5 \leq arr[i], target \leq 10^5$
- $arr$ is sorted in ascending order.
- All the integers in $arr$ are unique.

### Registers' list:
![register list](https://i.sstatic.net/2xdbB.png)
You may have to look carfully in this image, since you might have to use the correct register so as to implement the assembly without error. 

### Here are some hints for you:
1. Make sure you completely understand the difference between caller register and callee register.
2. Make sure you know which register is safe to use in your code.
3. Make sure you have totally understanding each register's function. 

## Requirement
1. **Assembly Code Implementation** :
    Implement operators, max element, dp, and recursive with assembly language. To notice that your result of c and assembly should be the same.

## Submission

Please submit your source code as a ZIP file to E3. The name of the ZIP file should be `lab1_<student_id>.zip`, and the structure should be as follows:
```
lab1_<student_id>.zip
└── lab1_<student_id>
    ├── max_element
    │   ├── main.c
    │   ├── main.s
    │   └── makefile
    ├── dp
    │   ├── dp.c
    │   ├── dp.s
    │   └── makefile
    └── recursive
        ├── recursive.c
        ├── recursive.s
        └── makefile

```


## Reference:
[Stackoverflow](https://stackoverflow.com/questions/74094483/why-temporary-registers-and-saved-registers-in-risc-v-are-not-numbered-sequentia)