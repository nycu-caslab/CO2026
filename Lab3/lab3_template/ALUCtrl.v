module ALUCtrl (
    input [1:0] ALUOp,
    input funct7,
    input [2:0] funct3,
    output reg [3:0] ALUCtl
);

    // TODO: implement your ALU control here
    // For testbench verifying, Do not modify input and output pin
    // Hint: using ALUOp, funct7, funct3 to select exact operation

    
    // Example for addi instruction:
    // ALUOp = 2'b01, funct3 = 3'b000,
    always @(*) begin
        case(ALUOp)
            2'b11: // R-type instructions

                case({funct3, funct7})

                    {3'b000, 1'b0}: ALUCtl = 4'b0010; //You can design your ALU control signals
                    // Implement other R-type instructions
                    default: ALUCtl = 4'bxxxx;

                endcase

            2'b01: // I-type instructions

                case(funct3)

                    3'b000: ALUCtl = 4'b0010; 
                    // Implement other I-type instructions
                    default: ALUCtl = 4'bxxxx;

                endcase

            // Todo: implement other ALUOp cases
        endcase
    end


endmodule

