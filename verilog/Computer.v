`timescale 1ns / 1ps

module computer(
	input enable,
	input reset,
	input ext_clk,
	output [7:0] color, // rrr_ggg_bb
	output HSync,
	output VSync,
	output	[7:0] Led, // is zero?
	
	/* KADD */
	input[4:0] sw,
	//input btnd,
	output[3:0] an,
	output[7:0] seg
    );
	 
	wire [14:0] addr;
	wire [15:0] data;
	wire we;
	wire [15:0] data_out;
	wire [14:0] vga_addr;
	wire [15:0] vga_data;
	wire [1:0] pixel_state;
	

  // signals
  wire pos_edge; 
  wire sdb; 		// signal that is debounced
  
  wire dp3, dp2, dp1, dp0;   // dps  
  //wire[3:0] d3n, d2n, d1n, d0n;
  
 
  // bcd outputs
  wire [15:0] bcd_debouncer;
  wire[3:0] d3, d2, d1, d0; 
  
  	wire[23:0] mem_address;
	wire[15:0] mem_data_in, cpu_data_out;
	wire[1:0] sr;
  
	wire debug_move_next;
	wire[3:0] reg_debug_addr;
	wire[15:0] reg_debug_output;
  
   
	ClkBuffer _clkBuffer(ext_clk, clk);
   
  // continuous assignment
 // assign seg = pattern;
  assign dp3 = 1'b1;
  assign dp2 = 1'b1;
  assign dp1 = 1'b1;
  assign dp0 = 1'b1;
  
  assign {d3, d2, d1, d0} = reg_debug_output;  
  
  
  KSevenSegmentMux #(.N(17)) ssm (clk, reset, d3, d2, d1, d0, dp3, dp2, dp1, dp0, an, seg);  
  

	assign debug_move_next = (sw[4]); // _____
	
	assign reg_debug_addr = sw[3:0];
	
	
	NewFSMCore2 mycore(
	clk,
	reset,
	mem_data_in,
	cpu_data_out,
	mem_address,
	we_mem,
	
	debug_move_next, reg_debug_addr, reg_debug_output, sr
	);	// ============================== END ===================
		
	
   //newCore cooCore(clk, data_out, addr, data, we);
	
	wire  [23:0] input_addr = 99;
	wire  [15:0] input_data = 99;
	wire [23:0] output_addr;
	wire [15:0] output_data;
	
	MemController _memController(enable, reset, clk, {we_mem, mem_address[22:0]}, cpu_data_out, mem_data_in, vga_addr, vga_data, pixel_state, input_addr, input_data, output_addr, output_data);
	VgaDisplay _vga_display(enable, reset, clk, color, HSync, VSync, vga_data, vga_addr, pixel_state);

	assign Led[7:6] = sr;
	assign Led[5:0] = {output_addr, output_data[3:0], enable};
	
endmodule





