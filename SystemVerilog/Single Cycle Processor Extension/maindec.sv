`timescale 1ns / 1ps
module maindec(input  logic [5:0] op,
               output logic       memtoreg, memwrite,
               output logic       branch, blt, // blt for BLT's use
               output logic		  alusrca,
               output logic	[1:0] alusrcb, // 2 bits cuz 4 choices na
               output logic       regdst, regwrite,
               output logic       jump,
               output logic [1:0] aluop);

  logic [11:0] controls;

  assign {regwrite, regdst, alusrca, alusrcb, branch, blt, memwrite,
          memtoreg, jump, aluop} = controls;
  // alusrca = 0 -> value in rs goes through; alusrca = 1 -> 0 goes through

  always_comb
    case(op)
      6'b000000: controls <= 12'b110000000010; // RTYPE
      6'b100011: controls <= 12'b100010001000; // LW
      6'b101011: controls <= 12'b000010010000; // SW
      6'b000100: controls <= 12'b000001000001; // BEQ
      6'b001000: controls <= 12'b100010000000; // ADDI
      6'b000010: controls <= 12'b000000000100; // J
      6'b001111: controls <= 12'b101100000000; // LUI
      6'b010001: controls <= 12'b101110000000; // LI
      6'b011111: controls <= 12'b000000100001; // BLT
      default:   controls <= 12'bxxxxxxxxxxxx; // illegal op
    endcase
endmodule