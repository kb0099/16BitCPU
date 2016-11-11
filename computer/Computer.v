`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:28:52 10/15/2016 
// Design Name: 
// Module Name:    computer 
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
module Computer(
	input enable,
	input reset,
	input ext_clk,
	output [7:0] color, // rrr_ggg_bb
	output HSync,
	output VSync,
	output on // enable LED
    );
	 
	wire [23:0] addr;
	wire [15:0] data;
	wire we;
	wire [15:0] data_out;
	wire [14:0] vga_addr;
	wire [15:0] vga_data;
	wire [1:0] pixel_state;
	 
	ClkBuffer _ClkBuffer(ext_clk, clk);
   
   NewCore CooCore(clk, data_out, addr, data);
	
	MemController _MemController(enable, reset, clk, addr, data, data_out, vga_addr, vga_data, pixel_state);
	VgaDisplay _VgaDisplay(enable, reset, clk, color, HSync, VSync, vga_data, vga_addr, pixel_state);

	assign on = enable;
	
endmodule
