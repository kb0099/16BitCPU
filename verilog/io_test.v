`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:01:18 12/08/2016
// Design Name:   computer
// Module Name:   X:/16bitcomp_final/verilog/io_test.v
// Project Name:  computer
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

module io_test;

	// Inputs
	reg enable;
	reg reset;
	reg ext_clk;
	reg button_up;
	reg button_left;
	reg button_right;
	reg button_center;
	reg button_down;
	reg [5:0] switches;

	// Outputs
	wire [7:0] color;
	wire HSync;
	wire VSync;
	wire [7:0] led_out;
	wire [3:0] an;
	wire [7:0] seg;

	// Bidirs
	wire sensor_data;

	// Instantiate the Unit Under Test (UUT)
	computer uut (
		.enable(enable), 
		.reset(reset), 
		.ext_clk(ext_clk), 
		.sensor_data(sensor_data), 
		.button_up(button_up), 
		.button_left(button_left), 
		.button_right(button_right), 
		.button_center(button_center), 
		.button_down(button_down), 
		.switches(switches), 
		.color(color), 
		.HSync(HSync), 
		.VSync(VSync), 
		.led_out(led_out), 
		.an(an), 
		.seg(seg)
	);
	
	defparam uut._buttons._db_up.WIDTH = 1;
	defparam uut._buttons._db_left.WIDTH = 1;
	defparam uut._buttons._db_center.WIDTH = 1;
	defparam uut._buttons._db_right.WIDTH = 1;
	defparam uut._buttons._db_down.WIDTH = 1;
	
	always #1 ext_clk = ~ext_clk;

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 1;
		ext_clk = 0;
		button_up = 0;
		button_left = 0;
		button_right = 0;
		button_center = 0;
		button_down = 0;
		switches = 0;

		// Wait 100 ns for global reset to finish
		#10;
		
		enable = 1;
		reset = 0;
		
		#10;
		
		button_up = 1;
        
		// Add stimulus here

	end
      
endmodule

