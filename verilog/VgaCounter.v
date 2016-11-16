`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:00:59 09/05/2016 
// Design Name: 
// Module Name:    vga_counter 
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
module VgaCounter(
	input 			  enable,
	input 			  reset,
	input 			  clk,
	output reg [9:0] pixel_counter,
	output reg [8:0] line_counter,
	output reg [1:0] sub_pixel_counter
    );
	 
	parameter SUB_PIXEL_WIDTH = 2; // 2 bits for 25MHz clock (count up to 4)
	parameter PIXELS = 800; // for a visible resolution width of 640 pixels
	parameter PIXEL_WIDTH = 10; // bit width pixel_counter
	parameter LINES = 525; // for a visible resolution width of 480 pixels
	parameter LINE_WIDTH = 9; // bit width of line_counter
	
	parameter PIXEL_COUNTER_START = {PIXEL_WIDTH{1'b0}};
	parameter LINE_COUNTER_START = {LINE_WIDTH{1'b0}};
	
	initial pixel_counter = PIXEL_COUNTER_START;
	initial line_counter = LINE_COUNTER_START;
	initial sub_pixel_counter = {SUB_PIXEL_WIDTH{1'b0}};
	
	always@(posedge clk) begin
		if (reset || !enable) begin // reset counters
			sub_pixel_counter <= {SUB_PIXEL_WIDTH{1'b0}};
			pixel_counter <= PIXEL_COUNTER_START;
			line_counter <= LINE_COUNTER_START;
		end
		else begin
		
			sub_pixel_counter <= sub_pixel_counter + 1'b1;
			
			if (sub_pixel_counter == {SUB_PIXEL_WIDTH{1'b1}}) begin // "clock divider" - every 4 clock ticks
			
				if (pixel_counter == PIXELS - 1'b1) begin // if pixel_counter is at the end of the line
					pixel_counter <= {PIXEL_WIDTH{1'b0}}; // reset pixel_counter
					line_counter <= line_counter + 1'b1; // move down one line
				end
				else
					pixel_counter <= pixel_counter + 1'b1; // else draw next pixel
				if (line_counter == LINES - 1'b1) // if line_counter has reached the bottom of the screen
					line_counter <= {LINE_WIDTH{1'b0}}; // reset back to the top of the screen
					
			end // if end
		end // else end
	end // always end

endmodule
