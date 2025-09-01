#include "VALU.h"  // Change this to your generated Verilog module header
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VALU* alu = new VALU;  // Change to your module name
    VerilatedVcdC* vcd = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    alu->trace(vcd, 5);
    vcd->open("waveform.vcd");
    
    struct TestCase {
        int alu_ctl;
        int a;
        int b;
        int expected_out;
        int expected_zero;
        int expected_overflow;
    };
    
    TestCase tests[] = {
        {0b0010, 5, 3, 8, 0, 0},    // ADD  (5 + 3 = 8)
        {0b0000, 6, 3, 2, 0, 0},    // AND  (6 & 3 = 2)
        {0b0001, 4, 1, 5, 0, 0},    // OR   (4 | 1 = 5)
        {0b0111, 5, 3, 0, 1, 0},    // SLT  (5 < 3 ? 1 : 0)
        {0b1001, 6, 3, 5, 0, 0},    // XOR  (6 ^ 3 = 5)
        {0b1011, (int)0xFFFFFFFB, 1, (int)0xFFFFFFFD, 0, 0}, // SRA
        {0b1100, (int)0xFFFFFFFB, 1, (int)0x7FFFFFFD, 0, 0}, // SRL
        {0b0010, (int)0x7FFFFFFF, 1, (int)0x80000000, 0, 1}, // ADD (2147483647 + 1, overflow)
        // add testcase here if needed
    };

    for (int i = 0; i < sizeof(tests) / sizeof(TestCase); i++) {
        alu->ALUctl = tests[i].alu_ctl;
        alu->A = tests[i].a;
        alu->B = tests[i].b;
        alu->eval();
        vcd->dump(i * 10);
        std::cout << "ALUctl: " << tests[i].alu_ctl
                  << "\tA: " << tests[i].a
                  << "\tB: " << tests[i].b
                  << "\tALUOut: " << (int)alu->ALUOut
                  << "\tExpected: " << tests[i].expected_out
                  << "\tZero: " << (int)alu->zero
                  << "\tExpected Zero: " << tests[i].expected_zero
                  << "\tOverflow: " << (int)alu->overflow
                  << "\tExpected Overflow: " << tests[i].expected_overflow
                  << std::endl;
    }

    vcd->close();
    delete alu;
    return 0;
}