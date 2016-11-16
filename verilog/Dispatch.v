`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:24:24 10/25/2016 
// Design Name: 
// Module Name:    Dispatch 
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
module Dispatch(
   input clk,
   input vga_in,
   input [14:0] vga_addr,
   input io_in,
   input [14:0] io_addr,
   output vga_out,
   output io_out,
   output addr_out
    );
    
    reg get_state = 1'b1;
    reg vga_resolved = 1'b0;
    reg io_resolved = 1'b0;
    reg [14:0] vga_addr_int = 15'd0;
    reg [14:0] io_addr_int = 15'd0;
    reg clk_gate = 1'b0;
    reg [1:0] select = 2'b00;
    
    always@(posedge clk)
    begin
    // Grab data requests from vga and io
    clk_gate <= clk_gate + 1'b1;
    select <= select + 1'b1;
    if (clk_gate == 1'b1)
      begin
      // IO handling
      if (select[1] == 1'b0)
         begin
         addr_out <= io_addr;
         io_out <= 1'b1;
         vga_out <= 1'b0;
         end
      // VGA handling
      else if (select[1] == 1'b1)
         begin
         addr_out <= vga_addr;
         io_out <= 1'b0;
         vga_out <= 1'b1;
         end
      end
    end
      
     



endmodule
