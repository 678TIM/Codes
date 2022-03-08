////////////
`timescale 1ns / 1ps
module datapath(input  logic        clk, reset,
                input  logic        memtoreg, pcsrc,
                input  logic		alusrca, // handle DC's for LUI and LI
                input  logic [1:0]  alusrcb, // cuz LUI and LI
                input  logic 		regdst,
                input  logic        regwrite, jump,
                input  logic [3:0]  alucontrol,
                output logic        zero, negdiff, // cuz BLT
                output logic [31:0] pc,
                input  logic [31:0] instr,
                output logic [31:0] aluout, writedata,
                input  logic [31:0] readdata);

  logic [4:0]  writereg;
  logic [31:0] pcnext, pcnextbr, pcplus4, pcbranch;
  logic [31:0] signimm, signimmsh, ui, zeroextimm; // ui is upper immediate; zeroextimm is for li's use
  logic [31:0] srca, srca_y, srcb;
  logic [31:0] result;

  // next PC logic
  flopr #(32) pcreg(clk, reset, pcnext, pc);
  adder #(32) pcadd1(pc, 32'b100, 1'b0, pcplus4); //So we adjust this to use the more complex adder; wmt-modification
  sl2         immsh(signimm, signimmsh);
  adder #(32) pcadd2(pcplus4, signimmsh, 1'b0, pcbranch); //See comment above
  mux2 #(32)  pcbrmux(pcplus4, pcbranch, pcsrc, pcnextbr);
  mux2 #(32)  pcmux(pcnextbr, {pcplus4[31:28], 
                    instr[25:0], 2'b00}, jump, pcnext);

  // register file logic
  regfile     rf(clk, regwrite, instr[25:21], instr[20:16], 
                 writereg, result, srca, writedata);
  mux2 #(5)   wrmux(instr[20:16], instr[15:11],
                    regdst, writereg);
  mux2 #(32)  resmux(aluout, readdata, memtoreg, result);
  signext     se(instr[15:0], signimm);
  sl16		  lui_immsh(instr[15:0], ui);
  zeroext     li_zeroext(instr[15:0], zeroextimm);

  // ALU logic
  mux2 #(32)  srcamux(srca, 32'b0, alusrca, srca_y);
  mux4 #(32)  srcbmux(writedata, signimm, ui, zeroextimm, alusrcb, srcb);
  alu         alu(srca_y, srcb, instr[10:6], alucontrol, aluout, zero, negdiff); // accomodate SLL and BLT
endmodule