`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:29:07 10/15/2016 
// Design Name: 
// Module Name:    memController 
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
module memController(
	input enable,
	input reset,
	input clk,
	input [14:0] addr,
	input [15:0] data_in,
	input we, // write-enable, write data_in to addr
	output [15:0] data_out,
	input [14:0] vga_addr,
   output [15:0] vga_data_out,
	input [13:0] instr_addr,
	output [15:0] instr_out
    );
	 
	// -------------------------------------------------
	// Memory Allocation Table
	// -------------------------------------------------
	// Mem Area Name					Starting Addr	Size
	// -------------------------------------------------
	// Instruction Memory 
	// Glyph Memory					0x2000			256x4
	// Text Memory (VGA Screen)	0x0				128X64
	// -------------------------------------------------
	
	// memory area sizes
	parameter SIZE_TEXT   = 14'd_8192;
	parameter SIZE_GLYPH  = 14'd_1024;
	parameter SIZE_INSTR  = 14'd_10240;
	// memory area starting address (use size to define)
	parameter ADDR_TEXT   = 14'd0;
	parameter ADDR_GLYPH   = ADDR_TEXT + SIZE_TEXT;
	
	instructionROM _instrROM(clk, 1'b0, instr_addr, 15'd0, instr_out);
	dataRAM _dataRAM(clk, we   , addr    , data_in, data_out,
						  clk, 1'b0 , vga_addr,   16'd0, vga_data_out);
						  
endmodule
