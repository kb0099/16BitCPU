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
	
	 
	// sequential logic
	always@(posedge clk) begin
		if (reset || !enable)
			color <= 8'b00000000; // black
			
		else if (pixel_state == SET_FOREGROUND) begin
			// set color based on the appropriate glyph bit
			if (line_counter[0] == 1'b0)
				// replication oper. {3{m}} = {m, m, m}
				color <= {8 {pg_data[ 4'd8 + pixel_counter[2:0] ]}};  
			else
				color <= {8 {pg_data[ pixel_counter[2:0] ]}};
		end
	end
							
	
	// combinational logic
	always@(*) begin
	
		// assume default, overidden properly later
		pg_addr = 15'dx;
		
		case(pixel_state)
			TEXT_FETCH: // get char addr
				pg_addr = ADDR_TEXT + { line_counter[8:3], pixel_counter[9:3] };
			GLYPH_FETCH: // get glyph addr
				pg_addr = ADDR_GLYPH + ((pg_data[7:0] << 2'd2) + line_counter[2:1]);
		endcase
			
	end

endmodule
