`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:11:49 09/22/2016 
// Design Name: 
// Module Name:    pulseGenerator 
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
module PulseGenerator(
	input enable,
	input reset,
	input clk,
	output reg pulse
    );
	 
	// default to 1 second pulse. Overwrite both params for slower/faster pulse
	parameter BIT_WIDTH = 27;
	parameter COUNT_MAX = 100_000_000;
	
	initial pulse = 1'b0;
	
	reg [BIT_WIDTH-1:0] count = {BIT_WIDTH{1'b0}};
	
	always@(posedge clk) begin
	
		if (reset || !enable) begin
		
			count <= {BIT_WIDTH{1'b0}};
			pulse <= 1'b0;
			
		end
		
		else begin
			
			count <= count + 1'b1;
			
			if (count == COUNT_MAX) begin
			
				count <= {BIT_WIDTH{1'b0}};
				pulse <= 1'b1;
				
			end
			
			else
			
				pulse <= 1'b0;
			
		end
		
	end

endmodule
