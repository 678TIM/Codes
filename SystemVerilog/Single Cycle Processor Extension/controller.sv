`timescale 1ns / 1ps
module controller(input  logic [5:0] op, funct,
                  input  logic       zero, negdiff, // negdiff for BLT
                  output logic       memtoreg, memwrite,
                  output logic       pcsrc, 
                  output logic		 alusrca,
                  output logic [1:0] alusrcb, // cuz LUI and LI
                  output logic       regdst, regwrite,
                  output logic       jump,
                  output logic [3:0] alucontrol);

  logic [1:0] aluop;
  logic       branch, blt;

  maindec md(op, memtoreg, memwrite, branch, blt,
             alusrca, alusrcb, regdst, regwrite, jump, aluop);
  aludec  ad(funct, aluop, alucontrol);

  assign pcsrc = (branch & zero) | (blt & negdiff); // accomodate BLT
endmodule