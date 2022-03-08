`timescale 1ns / 1ps
module mips(input  logic        clk, reset,
            output logic [31:0] pc,
            input  logic [31:0] instr,
            output logic        memwrite,
            output logic [31:0] aluout, writedata,
            input  logic [31:0] readdata);

  logic       memtoreg, regdst;
  logic		  alusrca;	// for LUI and LI (handling Don't Cares)
  logic [1:0] alusrcb;	// for LUI and LI
  logic		  regwrite, jump, pcsrc, zero, negdiff;
  logic [3:0] alucontrol;
  
  // add negdiff as ports to controller and datapath
  controller c(instr[31:26], instr[5:0], zero,
               negdiff, memtoreg, memwrite, pcsrc,
               alusrca, alusrcb, regdst, regwrite, jump,
               alucontrol);
  datapath dp(clk, reset, memtoreg, pcsrc, alusrca,
              alusrcb, regdst, regwrite, jump,
              alucontrol,
              zero, negdiff, pc, instr,
              aluout, writedata, readdata);
endmodule