module alu(input  logic [31:0] a, b,
           input  logic [4:0]  shamt, // for SLL
           input  logic [3:0]  alucontrol,
           output logic [31:0] result,
           output logic        zero, negdiff);
  
  logic [31:0] condinvb, sum;

  assign condinvb = alucontrol[3] ? ~b : b;
  assign sum = a + condinvb + alucontrol[3];
  
 
  always_comb
    case (alucontrol[2:0])
      3'b000: result = a & b;
      3'b001: result = a | b;
      3'b010: result = sum;
      3'b011: result = sum[31];
      3'b100: result = (condinvb << shamt); // for SLL
      3'b101: result = ~(a | b); // for NOR
      3'b110: result = {a[31:16], b[15:0]}; // for MIX
    endcase

  assign zero = (result == 32'b0);
  assign negdiff = result[31]; // for BLT. Only branch if result of subtraction is negative AND branch==1
endmodule