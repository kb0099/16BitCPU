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
	input [8:0] line_counter,
	input [1:0] pixel_state,
	output reg [7:0] color,
	input [15:0] pg_data,
	output reg [14:0] pg_addr
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
	
	// memory area sizes
	parameter SIZE_TEXT   = 14'd_8192;
	parameter SIZE_GLYPH  = 14'd_1024;
	// memory area starting address (use size to define)
	parameter ADDR_TEXT   = 14'd0;
	parameter ADDR_GLYPH   = ADDR_TEXT + SIZE_TEXT;

   reg foreground;
	
	reg [15:0] pixel_select = 16'd0;
	 
	// sequential logic
	always@(posedge clk) begin
		if (reset || !enable)
			color <= 8'b00000000; // black
		else if (pixel_state == WAIT)
			foreground <= pixel_select[0];
		else if (pixel_state == DRAW) begin
			if (foreground)
				color <= 8'b11111111;	
			else
				color <= 8'b00000000;
		end
	end
	
	// combinational logic
	always@* begin
	
		case(pixel_state)
			TEXT_FETCH: begin // get char addr
				pg_addr = ADDR_TEXT + { line_counter[8:3], pixel_counter[9:3] };
				pixel_select = 1'b0;
			end
			GLYPH_FETCH: begin // get glyph addr
				pg_addr = ADDR_GLYPH + ((pg_data[7:0] << 2'd2) + line_counter[2:1]);
				pixel_select = 1'b0;
			end
			WAIT: begin
				pg_addr = ADDR_GLYPH + ((pg_data[7:0] << 2'd2) + line_counter[2:1]);
				if (line_counter[0] == 1'b0)
					pixel_select = pg_data >> ( 4'd8 + pixel_counter[2:0] );
				else
					pixel_select = pg_data >> ( pixel_counter[2:0] );
			end
			default: begin
				pg_addr = 15'd0;
				pixel_select = 1'b0;
			end
		endcase
			
	end

endmodule