`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:01:40 09/05/2016 
// Design Name: 
// Module Name:    vga_output 
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
module VgaOutput(
	input 			  enable,
	input 			  reset,
	input 	  [7:0] color_in, // from pixel_generator
	input 	  [9:0] pixel_counter, // from vga_counter
	input 	  [8:0] line_counter, // from vga_counter
	output reg [7:0] color, // rrr_ggg_bb
	output reg 		  HSync,
	output reg 		  VSync
    );
	 
	initial color = 8'b00000000; // initally set to black
	initial HSync = 1'b1; // HSync is active low
	initial VSync = 1'b1; // VSync is active low

	parameter H_ACTIVE = 640; // visible resolution width
	parameter H_FRONT = H_ACTIVE + 16;
	parameter H_SYNC = H_FRONT + 96;
	parameter H_BACK = H_SYNC + 48;
	
	parameter V_ACTIVE = 480; // visible resolution height
	parameter V_FRONT = V_ACTIVE + 10;
	parameter V_SYNC = V_FRONT + 2;
	parameter V_BACK = V_SYNC + 33;
	
	// combinational logic
	always@(*) begin
		if (reset || !enable) begin
			color = 8'b00000000;
			HSync = 1'b1;
			VSync = 1'b1;
		end
		else begin
			if (pixel_counter >= H_FRONT && pixel_counter < H_SYNC)
				HSync = 1'b0; // send HSync pulse at end of line
			else
				HSync = 1'b1; // otherwise don't send HSync pulse
				
			if (line_counter >= V_FRONT && line_counter < V_SYNC)
				VSync = 1'b0; // send VSynce at the bottom of the screen
			else
				VSync = 1'b1; // otherwise don't send VSync
			
			// start drawing at index 0 of pixel_counter and line_counter
			if (pixel_counter >= 0 && pixel_counter < H_ACTIVE && 
				 line_counter  >= 0 && line_counter  < V_ACTIVE)
				color = color_in; // set color to color coming out of pixel_generator
			else
				color = 8'b00000000; // drive color to ground when not in active region
		end
	end
 
endmodule
