# Lab3: Single Cycle CPU

## Introduction

In Lab3, you are tasked with implementing a Single Cycle CPU based on the RISC-V ISA. Upon completing this lab, you should have a deeper understanding of CPU architecture and the RISC-V instruction set.

Don't panic! This lab is not as difficult as it might seem. To successfully implement the RISC-V CPU, we encourage you to study the functionality of each component and understand how they cooperate. We will also introduce a useful RISC-V simulator, Ripes, which demonstrates the CPU workflow step by step.

## Lab Overview Slides
[Lab3: Single Cycle CPU](https://docs.google.com/presentation/d/1DWdZc4BhhCBx0HShtQsLfXIH1er6WZBTcIolRwz9fSI/edit?usp=sharing)

## Lab Source Code

The TAs have prepared a template for you. You can follow the template or modify it as needed. However, there are certain elements you should not change:

- Registers
- Instruction Memory
- Data Memory
- CPU I/O interface and register instance names

In the provided source code, we include a simple instruction file, `TEST_INSTRUCTIONS.txt`, containing machine code generated from `TEST_INSTRUCTIONS.asm`.

> [!IMPORTANT]
> The `rst` signal is active low, which means the module will reset when the `rst` signal is set to zero. You should follow this design in your implementation.

## Ripes

[Ripes](https://ripes.me/) is a visual computer architecture simulator and assembly code editor designed for the RISC-V instruction set architecture.

![ripes1](images/ripes1.png)

As shown in the picture above, you can write your own assembly code, clock the processor, and verify the register values.

You can copy the generated machine code into `TEST_INSTRUCTIONS.txt` in the following format to run your code on your CPU design. Each line in the file should contain 8 bits. A single 4-byte instruction is represented by 4 lines, and the file should end with a new empty line.

```asm
addi t2 zero 20
jalr ra (t2)0
addi t0 zero 1
addi t0 t0 1
addi t0 t0 1
addi t1 zero 100
```

```
00000001
01000000
00000011
10010011
00000000
00000011
10000000
11100111
00000000
00010000
00000010
10010011
00000000
00010010
10000010
10010011
00000000
00010010
10000010
10010011
00000110
01000000
00000011
00010011
```

> [!IMPORTANT]
> Ensure that you change the settings in Ripes to match the constraints of the register values specified for this lab.
![lab3-ripes3](images/ripes2.png)

## Single Cycle CPU

### Architecture

You can follow the architecture diagram to implement a single-cycle CPU.

![lab3-artitecture](images/artitecture.jpg)

### Instruction

Implement the following instructions. The RV32I ISA layout is provided below.

- add  
  ![add](images/add.png)
- addi  
  ![addi](images/addi.png)
- sub  
  ![sub](images/sub.png)
- and  
  ![and](images/and.png)
- andi  
  ![andi](images/andi.png)
- or  
  ![or](images/or.png)
- ori  
  ![ori](images/ori.png)
- slt  
  ![slt](images/slt.png)
- slti  
  ![slti](images/slti.png)
- lw  
  ![lw](images/lw.png)
- sw  
  ![sw](images/sw.png)
- beq  
  ![beq](images/beq.png)
- bne
  ![bne](images/bne.png)
- blt
  ![blt](images/blt.png)
- bge
  ![bge](images/bge.png)
- jal  
   `jal` stores `pc+4` in `regs[rd]`, executes `pc = pc + imm << 1`
  ![jal](images/jal.png)
- jalr  
  `jalr` stores `pc+4` in `regs[rd]`, exectues `pc = regs[rs1] + imm`
  ![jalr](images/jalr.png)
- auipc  
  ![auipc](images/auipc.png)

> [!IMPORTANT]
> All operations are signed. You must follow this ISA table to implement your instructions:
![lab3-2](images/ISAtable.png)

## Requirements

Implement your RISC-V single-cycle CPU. Your CPU should support the following RISC-V ISA instructions:

- Arithmetic and Logical Operations: `add`, `addi`, `sub`, `and`, `andi`, `or`, `ori`, `slt`, `slti`
- Memory Operations: `lw`, `sw`
- Branch Operations: `beq`, `bne`, `blt`, `bge`
- Jump Operations: `jal`, `jalr`
- U type Operation: `luipc`

TAs have prepared a Verilator testbench and some `TEST_INSTRUCTION.txt` files to grade your design. The correctness will be verified by comparing the register values.

> [!WARNING]
> Do not modify the register, instruction memory, or CPU I/O interface; otherwise, you will receive 0 points.

## Scoring Criteria
- Basic Test: 20%
- Hidden Test: 40%
- Fibonacci Test: 40%

## Submission

Please submit your source code as a ZIP file to E3. The name of the ZIP file should be `lab2_<student_id>.zip`, and the structure should be as follows:

```
lab3_<student_id>.zip
├── lab3_<student_id>
│   ├── ALU.v
│   ├── ALUCtrl.v
│   ├── Adder.v
│   ├── BranchComp.v
│   ├── Control.v
│   ├── DataMemory.v
│   ├── ImmGen.v
│   ├── InstructionMemory.v
│   ├── Mux2to1.v
│   ├── Mux3to1.v
│   ├── PC.v
│   ├── Register.v
│   ├── ShiftLeftOne.v
│   ├── SingleCycleCPU.v
│   ├── ...(other source code files)
```

To compress your file, run the following commands:

```bash
sudo apt-get install zip
zip -rq lab3_<student_id>.zip lab3_<student_id>
```

After creating the zip file, you can verify its contents and folder structure by running:

```bash
chmod +x validate_zip.sh
./validate_zip.sh lab3_<student_id>.zip
```

If the file format is correct, you should see the following message in the terminal:

```
Validation successful: All required files are present.
```

> [!WARNING]
> The deadline for submission is 4/10 at 23:59. Submissions in an incorrect format will result in a 10-point deduction.

## Hints

- Read the textbook first to understand each submodule's functionality.
- Use waveform debugging to simplify the debugging process.
- Try generating your own RISC-V machine code using Ripes. You can write simple assembly code to verify if your implementation works as expected.

## Reference

- Computer Organization and Design RISC-V Edition, CH4
- [Ripes](https://github.com/mortbopet/Ripes)
- [RISC-V Instruction Set Specifications](https://msyksphinz-self.github.io/riscv-isadoc/html/rvi.html)
