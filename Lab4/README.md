# Lab4 Advance Pipeline CPU
[Spec PPT](https://docs.google.com/presentation/d/1Pk7S0x0lF10fD7-0hi8xSIZB2FVyUODaAu657ZxFmDg/edit?usp=sharing)
## Introduction
In Lab3, we finished the simple single-cycle CPU. We need to make the CPU more efficient, so in Lab4, we will implement the **pipeline cpu**.

Step1: Implement the pipeline register in each pipeline stage

Step2: Consider three significant issues that stay unsolved. They are branches, load-use, and write-use hazards. You are requested to implement hazard detection and forwarding units.

## Lab Source Code
We have provided the code for step 1. It should be able to handle all the instructions without jump, branch, data hazard and control hazard; however, we recommend that you should implement the register module by yourself.

We also privide template for forwarding unit and harazard detection unit

# Pipeline Cycle CPU (with hazard & forwarding)

## Reference Architecture
As long as it works successfully, it is not necessary to implement it according to the architecture diagram.
![image](https://github.com/nycu-caslab/CO2025/blob/main/Lab4/CO_Lab4_architecture.png)


## Hazard Dectection Unit
The hazard detection unit is responsible for inserting a nop when load-use data hazard happens (as the following snippet)
```assembly
ld x1 0(sp);
; insert nop here 
add x1 x1 x2;
```
Also, flush the pipeline register after branch instruction once the branch is taken.
- If you follow the architecture provided above
    - You must determine if the branch will take or not in the ID stage.


## Forwarding Unit
The forwarding unit deals with write-use data hazards; your design should handle the following case.
```assembly
add x1, x1, x2
add x1, x1, x3
add x1, x1, x4
```

## Instruction
Your CPU should be able to support the following RISC-V ISA.
- add, addi, sub, and, andi, or, ori
- slt, slti, sra, srl, auipc
- lw, sw, beq
- jal, jalr, bne, blt, bge

## Requirement
Add pipeline registers to transform your single cycle CPU to a pipelined
CPU

Implement hazard detection and forwarding units, then integrate them into your CPU. You are recommended to write the assembly yourself to test your design's correctness.

TAs have prepared hidden test cases to grade your design. We will verify correctness by comparing register values. Your design should also be able to satisfy previous (lab3) requirements.

## Submission
Please submit your source code as a zip file to **E3**.

The name of the zip file should be <student_id>.zip, and the structure of the file should be as the following:

```
<stduent_id>.zip
    |- <student_id>/
        |- ...(your source codes)
```

## Hint
- Be mindful of data hazards that may occur with branch instructions.
- Read the textbook first and understand each submodule's functionality.
- Debugging with waveform makes your life easier.
- Try to generate your risc-v machine code with Ripe; you can write a simple assembly to verify if your code runs as expected.


## Reference
- Computer Organization and Design RISC-V Edition, CH4
- [Ripes](https://github.com/mortbopet/Ripes)
- [RISC-V Reader](http://riscvbook.com/)
- [riscv-isa-pages](https://msyksphinz-self.github.io/riscv-isadoc/html/rvi.html)
