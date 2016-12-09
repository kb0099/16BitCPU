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
module MemController(
	input 		  enable,
	input 		  reset,
	input 		  clk,
	input  [23:0] core_addr,
	input  [15:0] core_data_in,
	output [15:0] core_data_out,
	input  [14:0] vga_addr,
   output [15:0] vga_data_out,
	input  [15:0] io_data_in,
	output [15:0] output_data
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
	parameter SIZE_TEXT   = 8192;
	parameter SIZE_GLYPH  = 1024;
	parameter SIZE_INSTR  = 10240;
	parameter SIZE_INPUT  = 512;
	parameter SIZE_OUTPUT = 512;
	parameter SIZE_STACK  = 10240;

	// memory area starting address (use size to define)
	parameter ADDR_TEXT   = 0;
	parameter ADDR_GLYPH  = ADDR_TEXT   + SIZE_TEXT;
	parameter ADDR_INSTR  = ADDR_GLYPH  + SIZE_GLYPH;
	parameter ADDR_INPUT  = ADDR_INSTR  + SIZE_INSTR;
	parameter ADDR_OUTPUT = ADDR_INPUT  + SIZE_INPUT;
	parameter ADDR_STACK  = ADDR_OUTPUT + SIZE_OUTPUT;
	
	// wires
	wire 			 weA;
	wire  [14:0] addressA;
	wire  [15:0] dinA;
   // io/memory mux for core_data_out
   wire [15:0] core_data_mem_out;
	reg count = 1'b0;
	
	// stall IO requests by 1 cyle to simulate how memory serves data
	always@(posedge clk) begin
		if(core_addr[14:0] >= ADDR_INPUT && core_addr[14:0] < ADDR_OUTPUT)
			count <= count + 1'b1;
		else
			count <= 1'b0;
	end
	
   assign core_data_out = (count) ? io_data_in : core_data_mem_out;
	
	// muxes to share port A with VGA and INPUT
	assign weA      = 1'b0;
	assign addressA = vga_addr;
	assign dinA	    = 15'd0;
	
	// muxes to grab core data for OUTPUT
	//assign output_addr = (core_addr[14:0] >= ADDR_OUTPUT && core_addr[14:0] < ADDR_STACK) ? core_addr : 24'd0;
	assign output_data = (core_addr[14:0] >= ADDR_OUTPUT && core_addr[14:0] < ADDR_STACK) ? core_data_in : 16'd0;

	//instructionROM _instrROM(clk, 1'b0, instr_addr, 15'd0, instr_out);
	TdpIcBRAM _BRAM(
		.clka(clk), 
		.wea(weA), 
		.addra(addressA),
		.dina(dinA), 
		.douta(vga_data_out),
		.clkb(clk), 
		.web(core_addr[23]),
		.addrb(core_addr[14:0]), 
		.dinb(core_data_in),
		.doutb(core_data_mem_out)
	);
						  
endmodule
