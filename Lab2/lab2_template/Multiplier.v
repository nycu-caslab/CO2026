module Multiplier(
    input signed [31:0] A, B,
    output signed [63:0] P
);

    // TODO: implement Multiplier here
    // Note: Do NOT use built-in operator * here.

    reg signed [64:0] acc;
    assign P = ; // assign answer

    always @(*) begin
        // TODO
        
        acc = ; // init acc
        for (int i = 0; i < 32; i += 1) begin
            case () // booth algo operation
                2'b10: ;
                2'b01: ;
                default: ;
            endcase
            acc = ; // update acc
        end

    end

endmodule
