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
module VgaDisplay(
	input  		  enable,
	input  		  reset,
	input  		  clk,
	output [ 7:0] color, // rrr_ggg_bb
	output 		  HSync,
	output 		  VSync,
	input  [15:0] vgad_data,
	output [14:0] vgad_addr
    );
	 
	wire [9:0] pixel_counter;
	wire [8:0] line_counter;
	wire [7:0] color_internal;
	wire [1:0] pixel_state;
	
	VgaCounter _VgaCounter(
		enable, 
		reset, 
		clk, 
		pixel_counter, 
		line_counter, 
		pixel_state
	);
	
   PixelGenerator _PixelGenerator(
		enable, 
		reset, 
		clk, 
		pixel_counter, 
		line_counter, 
		pixel_state, 
		color_internal, 
		vgad_data, 
		vgad_addr
	);
	
	VgaOutput _VgaOutput(
		enable, 
		reset, 
		color_internal, 
		pixel_counter, 
		line_counter, 
		color, 
		HSync,
		VSync
	);

endmodule
