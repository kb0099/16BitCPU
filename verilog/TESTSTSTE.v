`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:10:07 10/20/2016
// Design Name:   computer
// Module Name:   C:/Users/Tim/Desktop/3710 next level/16-bit_computer/verilog/TESTSTSTE.v
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

module TESTSTSTE;

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
   
   always #2 ext_clk = ~ext_clk;

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 0;
		ext_clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
      enable = 1;
      

	end
      
endmodule

