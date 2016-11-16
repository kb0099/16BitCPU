`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:06:41 09/05/2016 
// Design Name: 
// Module Name:    debounce 
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
module debounce(
	input clk,
	input btn_noisy,
	output reg btn_clean
    );
	 
	parameter WIDTH = 20;
	reg [WIDTH-1:0] counter = {WIDTH{1'b0}};
	
	always@(posedge clk) begin
		if (btn_noisy)
			if (counter == {WIDTH{1'b1}})
				btn_clean <= 1'b1;
			else begin
				counter <= counter + 1'b1;
				btn_clean <= btn_clean;
			end
		else
			if (counter == {WIDTH{1'b0}})
				btn_clean <= 1'b0;
			else begin
				counter <= counter - 1'b1;
				btn_clean <= btn_clean;
			end
	end

endmodule
