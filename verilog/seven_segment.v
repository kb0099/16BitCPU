`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:04:53 08/25/2016 
// Design Name: 
// Module Name:    seven_segment 
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
/*
	   aaa
	 f     b
    f     b
      ggg
    e     c
    e     c
      ddd
*/
module seven_segment(
	input clk,
   input [4:0] digit0, // high bit (i.e. digit[4]) is to set decimal
	input [4:0] digit1,
	input [4:0] digit2,
	input [4:0] digit3,
	output reg [3:0] seg_on,
	output reg [7:0] display_out // high bit sets decimal
    );
	parameter COUNT_WIDTH = 18;
	
	reg [COUNT_WIDTH-1:0] count = {COUNT_WIDTH{1'b0}};
	reg [4:0] select_digit = 5'd0;
	
	initial seg_on = 4'd0;
	initial display_out = 8'd0;
	
	
	always@(posedge clk) begin // seven segment scanning
		if (count == {COUNT_WIDTH{1'b1}} - 1)
			count <= {COUNT_WIDTH{1'b0}};
		else
			count <= count + 1'b1;

	   case({count[COUNT_WIDTH-1'b1],count[COUNT_WIDTH-2'b10]})
				0: begin seg_on <= 4'b1110;
							select_digit <= digit0;
					end
				1: begin seg_on <= 4'b1101;
							select_digit <= digit1;
					end
				2: begin seg_on <= 4'b1011;
							select_digit <= digit2;
					end
				3: begin seg_on <= 4'b0111;
							select_digit <= digit3;
					end
			endcase
	end

	always@* begin
		if (select_digit[4])
			display_out[7] = 1'b0;
		else
			display_out[7] = 1'b1;
		case(select_digit[3:0])      // abcdefg
			 0: display_out[6:0] = 7'b0000001;
			 1: display_out[6:0] = 7'b1001111;
			 2: display_out[6:0] = 7'b0010010;
			 3: display_out[6:0] = 7'b0000110;
			 4: display_out[6:0] = 7'b1001100;
			 5: display_out[6:0] = 7'b0100100;
			 6: display_out[6:0] = 7'b0100000;
			 7: display_out[6:0] = 7'b0001111;
			 8: display_out[6:0] = 7'b0000000;
			 9: display_out[6:0] = 7'b0000100;
			10: display_out[6:0] = 7'b0000010; // a
			11: display_out[6:0] = 7'b1100000; // b
			12: display_out[6:0] = 7'b1110010; // c
			13: display_out[6:0] = 7'b1000010; // d
			14: display_out[6:0] = 7'b0010000; // e
			15: display_out[6:0] = 7'b0111000; // f
			default: display_out[6:0] = 7'b0000001; // default to display 0
		endcase
	end

endmodule
