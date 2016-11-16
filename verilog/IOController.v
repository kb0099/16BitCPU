`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:30:24 11/01/2016 
// Design Name: 
// Module Name:    IOController 
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
module IOController(
   input clk,
   input i1,
   input i1sig,
   input io1,
   input i2,
   input i2sig,
   input io2,
   input i3,
   input i3sig,
   input io3,
   output o1,
   output o2,
   output o3,
   output reg mainout,
   output mainout2
    );
    
    reg [1:0] clkcnt = 2'b00;
    
    always@*
    begin
       o1 = io1;
       o2 = io2;
       o3 = io3;
       if (i1sig == 1'b1)
         mainout2 = i1;
       else if (i2sig == 1'b1)
         mainout2 = i2;
       else if (i3sig == 1'b1)
         mainout2 = i3;
    end
    
    always@(posedge clk)
    begin
      if (clkcount == 2'b00)
         mainout <= i1;
      else if (clkcnt == 2'b01)
         mainout <= i2;
      else if (clkcnt == 2'b10)
         mainout <= i3;
         
      clkcnt <= clkcnt + 1'b1;
    end


endmodule
