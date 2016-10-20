`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:52:56 08/25/2016 
// Design Name: 
// Module Name:    count 
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
module count(
    input enable,
    input reset,
	 input clk,
	 output reg [4:0] digit0,
	 output reg [4:0] digit1,
	 output reg [4:0] digit2,
	 output reg [4:0] digit3
    );
	 
	 initial digit0 = 5'd0;
	 initial digit1 = 5'b10000;
	 initial digit2 = 5'd0;
	 initial digit3 = 5'b10000;
	 parameter DIGIT_MAX = 9; // CAN'T GO HIGHER THAN 15
	 parameter COUNT_MAX = 10_000_000; // 10Hz
	 reg [23:0] count = 24'd0;
	
	always@(posedge clk) begin // binary coded hex
		if (reset) begin
			digit0 <= 5'd0;
			digit1 <= 5'b10000;
			digit2 <= 5'd0;
			digit3 <= 5'b10000;
		end
		else if (enable) begin
			if (count == COUNT_MAX - 1) begin
				count <= 24'd0;
				if (digit0[3:0] == DIGIT_MAX) begin
					digit0 <= 5'd0;
					if (digit1[3:0] == DIGIT_MAX) begin
						digit1 <= 5'b10000;
						if (digit2[3:0] == 5) begin
							digit2 <= 5'd0;
							if (digit3[3:0] == DIGIT_MAX)
								digit3 <= 5'b10000;
							else
								digit3 <= digit3 + 1'b1;
						end
						else
							digit2 <= digit2 + 1'b1;
					end
					else
						digit1 <= digit1 + 1'b1;
				end
				else
					digit0 <= digit0 + 1'b1;
			end
			else
				count <= count + 1'b1;
		end
	end

endmodule
