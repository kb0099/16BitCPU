`timescale 1ns / 1ps

module computer(
	input enable,
	input reset,
	input ext_clk,
   // sensor i/o
   inout sensor_data,
   //buttons
   input button_up,
   input button_left,
   input button_right,
   input button_center,
   input button_down,
   //switches
   input  [5:0] switches,
	output [7:0] color, // rrr_ggg_bb
	output HSync,
	output VSync,
	output [7:0] led_out, // is zero?s
	
	/* KADD */
	//input[4:0] sw,
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
  

	assign debug_move_next = enable; // _____
	
	assign reg_debug_addr = 4'b1111;	
	
	
		
	
   //newCore cooCore(clk, data_out, addr, data, we);
	
	wire [23:0] input_addr = 99;
	wire [15:0] input_data = 99;
	wire [23:0] output_addr;
	wire [15:0] output_data;
   // IO
   wire sensor_ready;
   wire [15:0] sensor_out;
   wire [15:0] buttons_out;
   wire [15:0] io_dataout;
   //wire [5:0] switches;
   wire [15:0] io_data_in;
	// removed input/output_address fields
	
	NewFSMCore2 mycore(
		.clk(clk),
		.reset(reset),
		.mem_data_in(mem_data_in),
		.cpu_data_out(cpu_data_out),
		.mem_address(mem_address),
		.we_mem(we_mem),
		// debug
		.debug_move_next(debug_move_next), 
		.reg_debug_addr(reg_debug_addr), 
		.reg_debug_output(reg_debug_output), 
		.sr(sr)
	);
	
	MemController _memController(
		.enable(enable), 
		.reset(reset), 
		.clk(clk), 
		.core_addr({we_mem, mem_address[22:0]}), 
		.core_data_in(cpu_data_out), 
		.core_data_out(mem_data_in), 
		.vga_addr(vga_addr), 
		.vga_data_out(vga_data), 
		.io_data_in(io_dataout), 
		.output_data(output_data)
	);
	
	VgaDisplay _vga_display(
		enable, 
		reset, 
		clk, 
		color,
		HSync,
		VSync,
		vga_data,
		vga_addr
	);
   // IOTD
   IOController _ioController(
		clk, 
		mem_address, 
		sensor_ready, 
		sensor_out, 
		buttons_out, 
		output_data, 
		io_dataout, 
		led_out
	);
   SensorDriver _sensor(
		clk, 
		sensor_data, 
		sensor_out, 
		sensor_ready
	);
   buttonTown _buttons(
		clk, 
		button_up, 
		button_left, 
		button_center, 
		button_right, 
		button_down, 
		switches, 
		buttons_out
	);

	//assign Led[7:6] = sr;
	//assign Led[5:0] = {output_addr, output_data[3:0], enable};
	
endmodule





