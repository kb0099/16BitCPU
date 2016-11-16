`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:56:36 11/08/2016
// Design Name:   Computer
// Module Name:   X:/16-bit_computer_new/computer/MemControllerTest.v
// Project Name:  computer
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Computer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MemControllerTest;

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
	Computer uut (
		.enable(enable), 
		.reset(reset), 
		.ext_clk(ext_clk), 
		.color(color), 
		.HSync(HSync), 
		.VSync(VSync), 
		.on(on)
	);
	
	always #5 ext_clk = ~ext_clk;

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 0;
		ext_clk = 0;

		// Wait 100 ns for global reset to finish
		#10;
		
		enable = 1;
        
		// Add stimulus here

	end
      
endmodule

