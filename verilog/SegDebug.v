`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:36:28 11/09/2016 
// Design Name: 
// Module Name:    SegDebug 
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
module SegDebug(
    input [15:0] data_in,
	 input clock,
    output reg [6:0] segOut,
	 output reg [3:0] segSelect
    );
    reg [7:0] limiter;
    reg [3:0] seg;
    reg [3:0] digSelect;
    reg [2:0] CS, NS;
    localparam dig1 = 0, dig2 = 1, dig3 = 2, dig4 = 3, buf1 = 4, buf2 = 5, buf3 = 6, buf4 = 7;
    initial CS = dig1;
    initial NS = dig1;
	 initial seg = 4'b0111;
    initial limiter = 8'd0;
    // Next-State Updating
	 always@(posedge clock)
	 begin
    limiter = limiter + 1'b1;
      if (seg[3] == 1'b0)
      begin
         digSelect = data_in[15:12];
         segSelect <= seg;
         if (limiter == 255)
         begin
            seg <= 4'b1011;
            limiter = 8'b0000_0000;
         end
      end
      else if (seg[2] == 1'b0)
      begin
         digSelect = data_in[11:8];
         segSelect <= seg;
         if (limiter == 255)
         begin
            seg <= 4'b1101;
            limiter = 8'b0000_0000;
         end
      end
      else if (seg[1] == 1'b0)
      begin
         digSelect = data_in[7:4];
         segSelect <= seg;
         if (limiter == 255)
         begin
            seg <= 4'b1110;
            limiter = 8'b0000_0000;
         end
      end
      else if (seg[0] == 1'b0)
      begin
         digSelect = data_in[3:0];
         segSelect <= seg;
         if (limiter == 255)
         begin
            seg <= 4'b0111;
            limiter = 8'b0000_0000;
         end
      end
      
      case (digSelect)
         0: segOut <= 7'b0000001;
         1: segOut <= 7'b1001111;
         2: segOut <= 7'b0010010;
         3: segOut <= 7'b0000110;
         4: segOut <= 7'b1001100;
         5: segOut <= 7'b0100100;
         6: segOut <= 7'b0100000;
         7: segOut <= 7'b0001111;
         8: segOut <= 7'b0000000;
         9: segOut <= 7'b0000100;
         10: segOut <= 7'b0001000;
         11: segOut <= 7'b1100000;
         12: segOut <= 7'b0110001;
         13: segOut <= 7'b1000010;
         14: segOut <= 7'b0110000;
         15: segOut <= 7'b0111000;
      endcase
    end
	
	 




endmodule
