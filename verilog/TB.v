`timescale 1ns / 1ps

module TB;

	// Inputs
	reg enable;
	reg reset;
	reg ext_clk;
	reg [4:0] sw;
	reg btnd;

	// Outputs
	wire [7:0] color;
	wire HSync;
	wire VSync;
	wire on;
	wire [3:0] an;
	wire [7:0] seg;

	// Instantiate the Unit Under Test (UUT)
	computer uut (
		.enable(enable), 
		.reset(reset), 
		.ext_clk(ext_clk), 
		.color(color), 
		.HSync(HSync), 
		.VSync(VSync),
		.sw(sw), 
		.btnd(btnd), 
		.an(an), 
		.seg(seg)
	);

	initial begin
		// Initialize Inputs
		enable = 0;
		reset = 1;
		ext_clk = 0;
		sw = 0;
		btnd = 0;	

		// Wait 10 ns for global reset to finish
		#10;
        
		// Add stimulus here

	end
	
	always #1 ext_clk = ~ext_clk;
      
endmodule

