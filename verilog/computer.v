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
module computer(
	input enable,
	input reset,
	input ext_clk,
	output [7:0] color, // rrr_ggg_bb
	output HSync,
	output VSync,
	output on // enable LED
    );
	 
	wire [14:0] addr;
	wire [15:0] data;
	wire we;
	wire [15:0] data_out;
	wire [14:0] vga_addr;
	wire [15:0] vga_data;
	wire [13:0] instr_addr;
	wire [15:0] instr_data;
	 
	clkBuffer _clkBuffer(ext_clk, clk);
	
	memController _memController(enable, reset, clk, addr, data, we, data_out, vga_addr, vga_data, instr_addr, instr_data);
	vga_display _vga_display(enable, reset, clk, color, HSync, VSync, vga_data, vga_addr);

	assign on = enable;
	
endmodule
