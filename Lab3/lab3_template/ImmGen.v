module ImmGen (
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0] inst,
    output reg signed [31:0] imm
);
    // ImmGen generate imm value base opcode
    wire [6:0] opcode = inst[6:0];

    always @(*) begin

        case(opcode)
        
            7'b0010011: imm = {{20{inst[31]}}, inst[31:20]}; //I-type except lw
            // Implement other instructions
            default: imm = 32'b0;
        
        endcase
    
    end

endmodule

