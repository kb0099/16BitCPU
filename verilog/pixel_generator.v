`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:01:23 09/05/2016 
// Design Name: 
// Module Name:    pixel_generator 
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
module pixel_generator(
	input enable,
	input reset,
	input clk,
	input [9:0] pixel_counter,
	input [9:0] line_counter,
	input [1:0] pixel_state,
	output reg [7:0] color,
	input [15:0] data,
	output [14:0] addr
    );
	 
	parameter SUB_PIXEL_WIDTH = 2; // 2 bits for 25MHz clock (count up to 4)
	parameter PIXELS = 800; // for a visible resolution width of 640 pixels
	parameter PIXEL_WIDTH = 10; // bit width pixel_counter
	parameter LINES = 525; // for a visible resolution width of 480 pixels
	parameter LINE_WIDTH = 10; // bit width of line_counter
	
	parameter TEXT_FETCH = 0;
	parameter GLYPH_FETCH = 1;
	parameter WAIT = 2;
	parameter DRAW = 3;

	wire foreground;
	
	reg [15:0] pixel_select = 16'd0;
	 
	// sequential logic
	always@(posedge clk) begin
		if (reset || !enable)
			color <= 8'b00000000; // blac	
		else if (pixel_state == DRAW && foreground)
			color <= 8'b11111111;
		else
			color <= 8'b00000000;			
	end
	
	// combinational logic
	always@* begin
	
		case(pixel_state)
			TEXT_FETCH: begin // get char addr
				addr = { line_counter[8:3], pixel_counter[9:3] };
			end
			GLYPH_FETCH: begin // get glyph addr
				addr = (data[7:0] << 2'd2) + line_counter[2:1];
			end
			DRAW: begin
				if (line_counter[0] == 1'b0)
					pixel_select = data >> ( 4'd8 + pixel_counter[2:0] );
				else
					pixel_select = data >> ( pixel_counter[2:0] );
			end
		endcase
			
	end
	
	assign foreground = pixel_select[0];

endmodule
