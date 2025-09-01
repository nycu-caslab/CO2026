module SingleCycleCPU (
    input clk,
    input start,
    output signed [31:0] r [0:31]
);

// When input start is zero, cpu should reset
// When input start is high, cpu start running

// The rst signal is active low, which means the module will reset if the rst signal is zero.
// And you should follow this design.

// TODO: connect wire to realize SingleCycleCPU
// The following provides simple template,
// you can modify it as you wish except I/O pin and register module


PC m_PC(
    .clk(),
    .rst(),
    .pc_i(),
    .pc_o()
);

Adder m_Adder_1(
    .a(),
    .b(),
    .sum()
);


InstructionMemory m_InstMem(
    .readAddr(),
    .inst()
);

Control m_Control(
    .opcode(),
    .funct3(),
    .BrEq(),
    .BrLT(),
    .memRead(),
    .memtoReg(),
    .ALUOp(),
    .memWrite(),
    .ALUSrc(),
    .regWrite(),
    .PCSel()
);

// For Student:
// Do not change the Register instance name!
// Or you will fail validation.

Register m_Register(
    .clk(),
    .rst(),
    .regWrite(),
    .readReg1(),
    .readReg2(),
    .writeReg(),
    .writeData(),
    .readData1(),
    .readData2()
);

// ======= for validation =======
// == Dont change this section ==
assign r = m_Register.regs;
// ======= for vaildation =======

BranchComp m_BranchComp(
    .A(),
    .B(),
    .BrEq(),
    .BrLT()
);

ImmGen m_ImmGen(
    .inst(),
    .imm()
);


ShiftLeftOne m_ShiftLeftOne(
    .i(),
    .o()
);

Adder m_Adder_2(
    .a(),
    .b(),
    .sum()
);

Mux3to1 #(.size(32)) m_Mux_PC(
    .sel(),
    .s0(),
    .s1(),
    .s2(),
    .out()
);


Mux2to1 #(.size(32)) m_Mux_ALU(
    .sel(),
    .s0(),
    .s1(),
    .out()
);

ALUCtrl m_ALUCtrl(
    .ALUOp(),
    .funct7(),
    .funct3(),
    .ALUCtl()
);

ALU m_ALU(
    .ALUctl(),
    .A(),
    .B(),
    .ALUOut(),
    .zero()
);


DataMemory m_DataMemory(
    .rst(),
    .clk(),
    .memWrite(),
    .memRead(),
    .address(),
    .writeData(),
    .readData()
);


Mux3to1 #(.size(32)) m_Mux_WriteData(
    .sel(),
    .s0(),
    .s1(),
    .s2(),
    .out()
);

endmodule
