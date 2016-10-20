`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:10:39 10/15/2016 
// Design Name: 
// Module Name:    clkBuffer 
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
module clkBuffer(
	input ext_clk,
	output clk
    );
	 
	IBUFG ibufg(.I(ext_clk), .O(int_clk)); // map ext_clk to internal distributed clock bus
	BUFG bufg(.I(int_clk), .O(clk));

endmodule
