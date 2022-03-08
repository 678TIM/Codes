module sl16(input logic [15:0] a,
            output logic [31:0] y,);
  
  // shift left by 16
  assign y = a << 16;
endmodule