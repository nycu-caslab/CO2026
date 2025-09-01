# CPU Component Units Lab

## Lab2 Slide
[CO2026_lab2_slide](<https://docs.google.com/presentation/d/1aiGKLDq4CkdNtzkufmjtycfUwkYiru6N/edit?usp=sharing&ouid=112366487093966794500&rtpof=true&sd=true>)

## Intro.

In this lab, you will understand and implement some key components of a processor. You have to implement the following three components in Verilog:

- Arithmetic Logic Unit (ALU)
- ALU Control (ALUCtrl)
- Signed Integer Multiplier

By the end of this lab, you will have a better understanding of how ALU, ALUCtrl and Integer Multiplier work, and how to implement them in Verilog.

## Part 1: ALU Control and ALU Implementation
In this section, you will focus on implement the ALU Control and ALU units. These components are responsible for determining how operations are performed based on control signals from the Control Unit.

**Note**: This lab only requires the implementation of ALUCtrl and ALU. However, to help you better understanding the overall concept, suggestions for writing the Control unit are also provided.

### How to Write Control
- First, understand the ISA and what each field represents (OPcode, funct3, funct7, etc.).
- Choose an instruction to implement.
- Check whether the OPcode is unique among all the instructions you need to implement.
- If it is unique, you can directly use the OPcode to identify the instruction.
- If not, use funct3 to assist in identifying the instruction.
- Once the instruction is identified, it will output unique control signals depending on the instruction (PCSel, ALUOp, regWrite, memWrite, etc.).
- For example, for the `sw` instruction, regWrite should be 0, and memWrite should be 1 (no need to write to the register, but memory needs to be written to).
- ALUOp (for reference only)

| Type   | ALUOp |
| ------ | ----- |
| lw, sw | 00    |
| branch | 01    |
| R-type | 10    |
| I-type | 11    |

### How to Write ALUCtrl
- ALUCtrl will receive ALUOp from the control unit, along with funct3 and funct7.
- These inputs are used to determine which ALUCtrl signal (control signal) to output in order to control the ALU's operation.
- The control signals can be customized as long as the final computation results are correct.
- ALUCtrl (for reference only)

| Type    | ALUCtrl |
| ------- | ------- |
| add     | 0010    |
| sub     | 0110    |
| or      | 0001    |
| and     | 0000    |
| slt     | 0111    |
| xor     | 1001    |
| sll     | 1010    |
| srl     | 1100    |
| sra     | 1011    |

### How to Write ALU
- After receiving ALUCtrl, determine the operation to be performed.
- Execute the operation based on the determination.
- The ALU also needs to output the following flags:
    - `zero`: Indicates whether the result is zero.
    - `overflow`: Indicates whether an overflow occurred during the operation. Note that overflow only occurs in addition and subtraction operations.
- Note: The shift operations (sll, srl, sra) should only use the lower 5 bits of the shift amount.

## Part 2: Integer Multiplier Implementation

In this section, you will implement an integer multiplier in Verilog. The component take two signed 32-bit integers as inputs and produces a signed 64-bit integer as their product. 

We recommend using Booth's algorithm for this implementation, but you may use other methods (e.g. Wallace Tree) if you prefer.

**IMPORTANT**: You **MUST NOT** use built-in multiplication operators in Verilog(e.g., `*`). If you do, you will receive **0 point** for this part. You must implement the multiplication logic manually.

### How to Write Integer Multiplier

- Understand each step of the Booth's algorithm. (e.g. initializing, shifting, adding, etc.)
- Know under which conditions you need to add or subtract the multiplicand.
- Be careful about the difference between sign extension and logical extension. (i.e. `>>>` vs. `>>`)
- If you choose another method, ensure you fully understand the logic of the algorithm and handle the signed multiplication correctly.

## Requirement
1. **ALU and Control Logic**
    - Implement the ALUCtrl and ALU modules in Verilog.
    - Your ALUCtrl must correctly interpret ALUOp, funct3, and funct7 to output the correct ALU control signals.
    - Your ALU must perform operations based on the control signals provided by ALUCtrl and output the correct result.
    - Your ALU must output the `zero` and `overflow` flags.
    - Control signals for operations must be correctly defined and interpreted.
    - required operations: 
        - `add`, `sub`, `or`, `and`, `slt`, `xor`, `sll`, `srl`, `sra`
        - `addi`, `ori`, `andi`, `slti`, `xori`, `slli`, `srli`, `srai`
        - `lw`, `sw`, `jalr`

2. **Integer Multiplier**
    - Implement the integer multiplier in Verilog without using built-in multiplication operators.
    - The multiplier must correctly handle signed multiplication and produce a 64-bit result.
