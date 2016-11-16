`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:16:35 09/01/2016 
// Design Name: 
// Module Name:    timer 
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
module timer(
	input enable,
	input reset,
	input ext_clk,
	output [3:0] seg_on, // seg3 seg2 seg1 seg0
	output [7:0] display_out, // abcdefg(p)
	output enable_led
   );
	
	wire [4:0] digit0, digit1, digit2, digit3;
	
	IBUFG ibufg(.I(ext_clk), .O(int_clk));
	BUFG bufg(.I(int_clk), .O(clk));
	
	debounce db(clk, reset, reset_db);
	
	count bcd(enable, reset_db, clk, digit0, digit1, digit2, digit3);
	
	seven_segment segment(clk, digit0, digit1, digit2, digit3, seg_on, display_out);
	
	assign enable_led = enable;


endmodule
