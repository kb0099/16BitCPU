`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:48:38 11/10/2016
// Design Name:   MemController
// Module Name:   X:/16-bit_computer_new/computer/MemControllerIOTest.v
// Project Name:  computer
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MemController
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MemControllerIOTest;

	// Inputs
	reg enable;
	reg reset;
	reg clk;
	reg [23:0] core_addr;
	reg [15:0] core_data_in;
	reg [14:0] vga_addr;
	reg [1:0] pixel_state;
	reg [23:0] input_addr;
	reg [15:0] input_data;

	// Outputs
	wire [15:0] core_data_out;
	wire [15:0] vga_data_out;
	wire [23:0] output_addr;
	wire [15:0] output_data;

	// Instantiate the Unit Under Test (UUT)
	MemController uut (
		.enable(enable), 
		.reset(reset), 
		.clk(clk), 
		.core_addr(core_addr), 
		.core_data_in(core_data_in), 
		.core_data_out(core_data_out), 
		.vga_addr(vga_addr), 
		.vga_data_out(vga_data_out), 
		.pixel_state(pixel_state), 
		.input_addr(input_addr), 
		.input_data(input_data), 
		.output_addr(output_addr), 
		.output_data(output_data)
	);
	
	always #5 clk = ~clk;
	always #5 pixel_state = pixel_state + 1;
	always #5 input_data = input_data + 1;
	always #5 vga_addr = vga_addr + 1;
	always #5 core_data_in = core_data_in + 1;

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 0;
		clk = 0;
		core_addr = 0;
		core_data_in = 0;
		vga_addr = 0;
		pixel_state = 0;
		input_addr = 0;
		input_data = 0;

		// Wait 100 ns for global reset to finish
		#10;
		
		enable = 1;
		
		#50;
		
		// PORT A tests (VGA & input)
		input_addr = {1'b1, 23'd19456};
		
		// PORT B tests (core)
		core_addr = {24'd10};
		#50;
		core_addr = {1'b1, 23'd19968};
        
		// Add stimulus here

	end
      
endmodule

