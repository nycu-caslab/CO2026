module Control (
    input [6:0] opcode,
    input [2:0] funct3,
    input BrEq, BrLT,
    output reg memRead,
    output reg [1:0] memtoReg,
    output reg [1:0] ALUOp,
    output reg memWrite,
    output reg ALUSrc,
    output reg regWrite,
    output reg [1:0] PCSel
);

    // TODO: implement your Control here
    // Hint: follow the Architecture (figure in spec) to set output signal

    reg [9:0] ctrl_signals;
    assign {PCSel, memRead, memtoReg, ALUOp, memWrite, ALUSrc, regWrite} = ctrl_signals;

    always @(*) begin
        case(opcode)

            7'b0110011: ctrl_signals = 10'b00_0_00_11_0_0_1; //R-type
            7'b0010011: ctrl_signals = 10'b00_0_00_01_0_1_1; // I-type
            7'b1100011:
                case(funct3)
                    
                    // Implement b-type instructions
                    default: ctrl_signals = 10'bxxxxxxxxxx;

                endcase
            default: ctrl_signals = 10'bxxxxxxxxxx;
        
        endcase
    
    end

endmodule

