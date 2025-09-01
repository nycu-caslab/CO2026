module ALU (
    input [3:0] ALUctl,
    input signed [31:0] A,B,
    output reg signed [31:0] ALUOut,
    output zero,
    output overflow
);
    // ALU has two operand, it execute different operator based on ALUctl wire
    // You have to output two flag: zero, overflow

    // TODO: implement your ALU here
    // Hint: you can use operator to implement

    always @(*) begin
        case(ALUctl)
            // TODO
        endcase
    end
endmodule

