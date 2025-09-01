module Mux3to1 #(
    parameter size = 32
)
(
    input [1:0] sel,
    input signed [size-1:0] s0,
    input signed [size-1:0] s1,
    input signed [size-1:0] s2,
    output reg signed [size-1:0] out
);
    // TODO: implement your 3to1 multiplexer here

endmodule
