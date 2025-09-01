# Assembly Language Lab

## Lab1 Slide

[CO2026_lab1_slide](<https://docs.google.com/presentation/d/1tWK-qsUHMEfZ0f9LHjsyXr9xRYoM6SFW/edit?usp=sharing&ouid=112366487093966794500&rtpof=true&sd=true>)

## Intro.

This lab will focus on getting familiar with basic RISC-V assembly instructions.

By the end of this lab, you will have a better grasp of assembly language programming.


## Basic Assembly Functions

Before you start to write this lab, we will quickly introduce some basic instructions in RISC-V and what do they actually do. Please don't be nervous, take a deep breath and we will start to dive into assembly language. 

There are three basic functions you have to implement with assembly code. We have prepared the template of both c code and assembly code of these three functions and you have to filled the absence of assembly code in order to fulfill those three functions. You may check simply check whether your code is correct by the output of c code or using ripes. 

- max_element
- dynamic programming
- fibonacci

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

### Problem 1(max_element):
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

### Problem 2(dp):
Description:
You are given an array $charge$ and a variable $T$.

In each row of the array, the first element represents the length of the timber, and the second element represents the corresponding rewards. For example, $charge = [[1, 2], [2, 5]]$ means:
- if you cut a timber with length 1, you will gain 2 rewards.
- if you cut a timber with length 2, you will gain 5 rewards.

The variable $T$ is the total length of timber you have. Your task is to return the maximum rewards under the given array and total length. 

Example 1:
Input: $charge = [[1, 2], [2, 5]], \ T = 5$
Output: 12
Explanation: 5 = 2 + 2 + 1, maximum rewards = 5 + 5 + 2 = 12

Example 2:
Input: $charge = [[3, 9], [4, 9]], \ T = 12$
Output: 36
Explanation: 12 = 3 + 3 + 3 + 3, maximum rewards = 9 + 9 + 9 + 9 = 36

FYI, this is a classic problem that can be solved using dynamic programming. If you are not fimilier with the problem, [this link](https://www.geeksforgeeks.org/dsa/unbounded-knapsack-repetition-items-allowed/) may help you. 

Constraint of the testcase:
- For every $i, j, \ 1 \leq charge[i][j] \leq 10^3$
- For every $i, \ charge[i].length = 2$
- $1 \leq charge.length \leq 40$
- $1 \leq T \leq 10^3$

### Problem 3(recursive):
Description:
You are given the variable $term$ and you have to return the $term$ of the fibonacci sequence. 

Fibonacci sequence:
$F_n = \begin{cases}
        0 & \text{if } n = 0 \\
        1 & \text{if } n = 1 \\
        F_{n-1} + F_{n-2} & \text{if } n \geq 2
    \end{cases}$

Example 1:
Input: $term = 5$
Output: $5$
Explanation: fibonocci sequence: 0, 1, 1, 2, 3, 5...

Example 2:
Input: $term = 10$
Output: $55$
Explanation: fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...

Constraint of the testcase:
- $0 \leq term \leq 30$

### Registers' list:
![register list](https://i.sstatic.net/2xdbB.png)
You may have to look carfully in this image, since you might have to use the correct register so as to implement the assembly without error. 

### Here are some hints for you:
1. Make sure you completely understand the difference between caller register and callee register.
2. Make sure you know which register is safe to use in your code.
3. Make sure you have totally understanding each register's function. 

## Requirement
1. **Assembly Code Implementation** :
    Implement max_element, dp, and recursive with assembly language. To notice that your result of c and assembly should be the same.

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