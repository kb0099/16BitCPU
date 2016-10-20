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
   output [15:0] vga_data_out
    );
	 
	// -------------------------------------------------
	// Memory Allocation Table
	// -------------------------------------------------
	// Mem Area Name					Starting Addr	Size
	// -------------------------------------------------
	// Stack
	// Instruction Memory 
	// I/O: Output
	// I/O: Input
	// Glyph Memory					0x2000			256x4
	// Text Memory (VGA Screen)	0x0				128X64
	// -------------------------------------------------
	
	// memory area sizes
	parameter SIZE_TEXT   = 14'd_8192;
	parameter SIZE_GLYPH  = 14'd_1024;
	parameter SIZE_INPUT  = 14'd_128;
	parameter SIZE_OUTPUT = SIZE_INPUT;
	parameter SIZE_INSTR  = 14'd_10240;
	parameter SIZE_STACK  = SIZE_INSTR;
	// memory area starting address (use size to define)
	parameter ADDR_TEXT   = 14'd0;
	parameter ADDR_GLYPH   = ADDR_TEXT + SIZE_TEXT;
	parameter ADDR_INPUT  = ADDR_GLYPH + SIZE_GLYPH;
	parameter ADDR_OUTPUT = ADDR_INPUT + SIZE_INPUT;
	parameter ADDR_INSTR  = ADDR_OUTPUT + SIZE_OUTPUT;
	parameter ADDR_STACK  = ADDR_INSTR + SIZE_INSTR;

	ram32Kb _ram32Kb(clk, we   , addr    , data_in, data_out,
						  clk, 1'b0 , vga_addr,   16'd0, vga_data_out);
						  
endmodule
