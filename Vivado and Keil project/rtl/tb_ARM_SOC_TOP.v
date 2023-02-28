`timescale 1ns / 1ns

module tb_ARM_SOC_TOP;

  // ARM_SOC_TOP Parameters
  parameter PERIOD = 10;
  parameter SimPresent = 1;

  // ARM_SOC_TOP Inputs
  reg         clk50M = 0;
  reg         reset_n = 0;
  reg         SWCLK = 0;
  reg         RXD = 0;

  // ARM_SOC_TOP Outputs
  wire        TXD;

  // ARM_SOC_TOP Bidirs
  wire        SWDIO;
  wire [15:0] EXP;

  always #10 clk50M = ~clk50M;

  initial begin
    #(PERIOD * 2) reset_n = 1;
  end

  ARM_SOC_TOP #(
      .SimPresent(SimPresent)
  ) u_ARM_SOC_TOP (
      .clk50M (clk50M),
      .reset_n(reset_n),
      .SWDIO  (SWDIO),
      .SWCLK  (SWCLK),
      .TXD    (TXD),
      .RXD    (RXD),
      .EXP    (EXP)
  );

  initial begin

  end

endmodule
