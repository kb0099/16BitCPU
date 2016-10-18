`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:16:08 10/18/2016
// Design Name:   computer
// Module Name:   X:/16-bit_computer/verilog/vga_memCntrlr_test.v
// Project Name:  Computer_16-bit
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: computer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module vga_memCntrlr_test;

	// Inputs
	reg enable;
	reg reset;
	reg ext_clk;

	// Outputs
	wire [7:0] color;
	wire HSync;
	wire VSync;
	wire on;

	// Instantiate the Unit Under Test (UUT)
	computer uut (
		.enable(enable), 
		.reset(reset), 
		.ext_clk(ext_clk), 
		.color(color), 
		.HSync(HSync), 
		.VSync(VSync), 
		.on(on)
	);
	
	always #0.5 ext_clk = ~ext_clk;

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 0;
		ext_clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		enable = 1;
        
		// Add stimulus here

	end
      
endmodule

