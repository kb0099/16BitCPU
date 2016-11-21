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
module PixelGenerator(
	input 			   enable,
	input 			   reset,
	input 			   clk,
	input 	  [ 9:0] pixel_counter,
	input 	  [ 8:0] line_counter,
	input 	  [ 1:0] pixel_state,
	output reg [ 7:0] color,
	input 	  [15:0] pg_data,
	output reg [14:0] pg_addr
    );
	
	parameter TEXT_FETCH = 0;
	parameter GLYPH_FETCH = 1;
	parameter SET_FOREGROUND = 2;
	parameter DRAW = 3;
	
	// memory area sizes
	parameter SIZE_TEXT   = 14'd_8192;
	parameter SIZE_GLYPH  = 14'd_1024;
	// memory area starting address (use size to define)
	parameter ADDR_TEXT   = 14'd0;
	parameter ADDR_GLYPH   = ADDR_TEXT + SIZE_TEXT;
	
	reg 	  	  blink = 1'b0;
	reg  [2:0] bg	  = 4'd0;
	reg  [3:0] fg    = 4'd0;
	
	wire [7:0] fg_color;		  
	wire [7:0] bg_color;
	
	// sequential logic
	always@(posedge clk) begin
		if (reset || !enable)
			color <= 8'b00000000; // black
		
		else if (pixel_state == GLYPH_FETCH) begin
			blink <= pg_data[15];
			bg    <= pg_data[14:12];
			fg    <= pg_data[11:8];
		end
		
		else if (pixel_state == SET_FOREGROUND) begin
			// set color based on the appropriate glyph bit
			if (line_counter[0] == 1'b0) begin
				// replication oper. {3{m}} = {m, m, m}
				if (pg_data[ 4'd8 + pixel_counter[2:0] ]) // foreground
					color <= fg_color;
				else
					color <= bg_color;
			end
			
			else begin
				if (pg_data[ pixel_counter[2:0] ])
					color <= fg_color;
				else
					color <= bg_color;
			end
		end
	end
							
	
	// combinational logic
	always@(*) begin
	
		// assume default, overidden properly later
		pg_addr = 15'd0;
		
		case(pixel_state)
			TEXT_FETCH: // get char addr
				pg_addr = ADDR_TEXT + { line_counter[8:3], pixel_counter[9:3] };
			GLYPH_FETCH: // get glyph addr
				pg_addr = ADDR_GLYPH + ((pg_data[7:0] << 2'd2) + line_counter[2:1]);
		endcase
			
	end
	
	assign bg_color = { {3{bg[2]}}, {3{bg[1]}}, {2{bg[0]}} };
	assign fg_color = { fg[3], {2{fg[2]}}, fg[3], {2{fg[1]}}, fg[3], fg[0] };

endmodule
