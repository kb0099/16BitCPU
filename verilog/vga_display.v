`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:54:06 09/06/2016 
// Design Name: 
// Module Name:    vga_display 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module vga_display(
	input enable,
	input reset,
	input ext_clk,
	input [6:0] sw, // for output selection
	output [7:0] color, // rrr_ggg_bb
	output HSync,
	output VSync,
	output on // enable LED
    );
	 
	wire [9:0] pixel_counter, line_counter;
	wire [7:0] color_internal;
	wire [1:0] pixel_state;
	 
	IBUFG ibufg(.I(ext_clk), .O(int_clk)); // map ext_clk to internal distributed clock bus
	BUFG bufg(.I(int_clk), .O(clk));
	
	vga_counter _vga_counter(enable, reset, clk, pixel_counter, line_counter, pixel_state);
	pixel_generator _pixel_generator(enable, reset, clk, sw, pixel_counter, line_counter, pixel_state, color_internal);
	vga_output _vga_output(enable, reset, clk, color_internal, pixel_counter, line_counter, color, HSync, VSync);

	assign on = enable;
endmodule