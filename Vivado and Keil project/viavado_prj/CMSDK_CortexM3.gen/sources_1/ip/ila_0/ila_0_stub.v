// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
// Date        : Wed Feb 22 11:09:11 2023
// Host        : LAPTOP-3N54D6K6 running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top ila_0 -prefix
//               ila_0_ ila_0_stub.v
// Design      : ila_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "ila,Vivado 2022.2" *)
module ila_0(clk, probe0, probe1, probe2, probe3)
/* synthesis syn_black_box black_box_pad_pin="clk,probe0[15:0],probe1[0:0],probe2[31:0],probe3[31:0]" */;
  input clk;
  input [15:0]probe0;
  input [0:0]probe1;
  input [31:0]probe2;
  input [31:0]probe3;
endmodule