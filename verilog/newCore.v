`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:45:24 10/25/2016 
// Design Name: 
// Module Name:    newCore 
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
module newCore(
   input clock,
   input [15:0] datain,
   output reg [14:0] addrout,
   output [15:0] dataout,
   output reg we
    );
    
    parameter [14:0] startAddr = 15'd9216;
    reg [2:0] CI = 3'b000;
    reg readwrite = 1'b0;
    reg [15:0] currentData = 16'd0;
    reg [14:0] dataAddr = 15'd0;
    reg [14:0] instrAddr = startAddr;
    reg [10:0] clockLimit = 26'd0;
    reg [15:0] currentInstruction;
    initial we = 1'b0;
    // State reg
    reg [1:0] state = 2'b00;
    reg [14:0] addrOut;
    parameter READ = 2'b00;
    parameter WRITE = 2'b01;
    parameter ADD = 2'b10;
    parameter JUMP = 2'b11;
    
    //assign addrout = addrOut;
    assign dataout = currentData;
    
    always@*
    begin
      if (readwrite == 1'b1)
         addrout = dataAddr;
      else
         addrout = instrAddr;
    end
    
    always@(posedge clock)
    begin
    if (clockLimit == 10)
    begin
    we <= 1'b0;
    // Set instruction address
    if (state == 2'b00)
      begin
      currentInstruction <= datain;
      if (datain == 16'd0 || datain == 16'd1)
         readwrite <= 1'b1;
      end
    // Read instruction
    else if (state == 2'b01)
      begin
      case(currentInstruction)
         0: begin // READ
            //addrOut = dataAddr;
            //read <= 1'b1;
            $display("READ");
            end
         2: begin // ADD
            currentData <= currentData + 1'b1;
            //dataAddr <= dataAddr + 1'b1;
            $display("ADD");
            end
         1: begin // WRITE
            //addrOut = dataAddr;
            //dataout <= currentData;
            we <= 1;
            $display("WRITE");
            end
         3: begin // JUMP
            dataAddr <= dataAddr + 1'b1;
            $display("JUMP");
            end
      endcase
      end
    // Execute instruction
    else if (state == 2'b10)
      begin
      case(currentInstruction)
         0: begin // READ
            currentData <= datain;
            instrAddr <= instrAddr + 1'b1;
            $display("READ");
            end
         2: begin // ADD
            instrAddr <= instrAddr + 1'b1;
            end
         1: begin // WRITE
            instrAddr <= instrAddr + 1'b1;
            $display("WRITE");
            end
         3: begin // JUMP
            instrAddr <= startAddr;
            $display("JUMP");
            end
      endcase   
      end
    // 2nd instr cycle/reset
    else if (state == 2'b11)
      begin    
      if (dataAddr > 8000)
         dataAddr <= 15'd0;
      readwrite <= 1'b0;
      end
      state <= state + 1'b1;
      end
      clockLimit <= clockLimit + 1'b1;
    end
         


endmodule
