#include "VMultiplier.h"  // Change this to your generated Verilog module header
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VMultiplier* multiplier = new VMultiplier;  // Change to your module name
    VerilatedVcdC* vcd = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    multiplier->trace(vcd, 5);
    vcd->open("waveform.vcd");
    
    struct TestCase {
        int a, b;
    };
    
    TestCase tests[] = {
        {3, 6},
        {-3, 6},
        {3, -6},
        {-3, -6},
        // add testcase here if needed
    };

    for (int i = 0; i < sizeof(tests) / sizeof(TestCase); i++) {
        multiplier->A = tests[i].a;
        multiplier->B = tests[i].b;
        multiplier->eval();
        vcd->dump(i * 10);
        std::cout << "A: " << tests[i].a
                  << "\tB: " << tests[i].b
                  << "\tMultiplier output: " << (long long)multiplier->P
                  << "\tExpected: " << (long long)tests[i].a * tests[i].b
                  << "\n";
    }

    vcd->close();
    delete multiplier;
    return 0;
}