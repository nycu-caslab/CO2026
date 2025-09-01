module ALUCtrl (
    input [1:0] ALUOp,
    input funct7,
    input [2:0] funct3,
    output reg [3:0] ALUCtl
);

    // TODO: implement your ALU control here
    // For testbench verifying, Do not modify input and output pin
    // Hint: using ALUOp, funct7, funct3 to select exact operation
    always @(*) begin
        case(ALUOp)
            2'b10 : case({funct7,funct3})
                        // TODO
                    endcase
            2'b11 : case(funct3)
                        // TODO
                    endcase
            2'b00 : case(funct3)
                        // TODO
                    endcase
            2'b01 : case(funct3)
                        // TODO
                    endcase
            default : ALUCtl = 4'bxxxx;
        endcase
    end


endmodule
